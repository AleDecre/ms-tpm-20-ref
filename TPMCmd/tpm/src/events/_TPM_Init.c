/* Microsoft Reference Implementation for MSSIM 2.0
 *
 *  The copyright in this software is being made available under the BSD License,
 *  included below. This software may be subject to other third party and
 *  contributor rights, including patent rights, and no such rights are granted
 *  under this license.
 *
 *  Copyright (c) Microsoft Corporation
 *
 *  All rights reserved.
 *
 *  BSD License
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  Redistributions of source code must retain the above copyright notice, this list
 *  of conditions and the following disclaimer.
 *
 *  Redistributions in binary form must reproduce the above copyright notice, this
 *  list of conditions and the following disclaimer in the documentation and/or
 *  other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ""AS IS""
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "Tpm.h"
#include "_TPM_Init_fp.h"
#include <stdio.h>
#include "tss2/tss2_tcti_mssim.h"
#include "tss2/tss2-tcti-tabrmd.h"
#include "tss2/tss2_esys.h"

// This function is used to process a _MSSIM_Init indication.
LIB_EXPORT void _MSSIM_Init(bool binding)
{

    g_powerWasLost = g_powerWasLost | _plat__WasPowerLost();

#if SIMULATION && DEBUG
    // If power was lost and this was a simulation, put canary in RAM used by NV
    // so that uninitialized memory can be detected more easily
    if(g_powerWasLost)
    {
        memset(&gc, 0xbb, sizeof(gc));
        memset(&gr, 0xbb, sizeof(gr));
        memset(&gp, 0xbb, sizeof(gp));
        memset(&go, 0xbb, sizeof(go));
    }
#endif

#if SIMULATION
    // Clear the flag that forces failure on self-test
    g_forceFailureMode = FALSE;
#endif

    // Disable the tick processing
    _plat__ACT_EnableTicks(FALSE);

    // Set initialization state
    MSSIMInit();

    // Set g_DRTMHandle as unassigned
    g_DRTMHandle = MSSIM_RH_UNASSIGNED;

    // No H-CRTM, yet.
    g_DrtmPreStartup = FALSE;

    // Initialize the NvEnvironment.
    g_nvOk = NvPowerOn();

    // Initialize cryptographic functions
    g_inFailureMode = (g_nvOk == FALSE) || (CryptInit() == FALSE);
    if(!g_inFailureMode)
    {
        // Load the persistent data
        NvReadPersistent();

        // Load the orderly data (clock and DRBG state).
        // If this is not done here, things break
        NvRead(&go, NV_ORDERLY_DATA, sizeof(go));

        // Start clock. Need to do this after NV has been restored.
        TimePowerOn();
    }

    if(binding){

        TSS2_RC rc;
        size_t context_size;

        TSS2_ABI_VERSION abi_version = TSS2_ABI_VERSION_CURRENT;
        ESYS_CONTEXT *esys_context = 0;

        rc = Tss2_Tcti_Mssim_Init(0, &context_size, NULL);
        
        TSS2_TCTI_CONTEXT *tcti_context = (TSS2_TCTI_CONTEXT *) calloc(1,context_size);

        rc = Tss2_Tcti_Mssim_Init(tcti_context,&context_size, NULL);

        if(rc != MSSIM_RC_SUCCESS)
        {
            fprintf(stderr,"Failed to initialize the TCTI context: 0x%" PRIx32 "0 \n", rc);
            free(tcti_context);
            exit(EXIT_FAILURE);
        }
        
        fprintf(stdout,"Initialization of the TCTI context successfull \n");

        rc = Esys_Initialize(&esys_context,tcti_context,&abi_version);
        if (rc != TSS2_RC_SUCCESS)
        {
            fprintf(stderr,"Failed to initialize the ESYS context: 0x%" PRIx32 "0 \n", rc);
            free(tcti_context);
            exit(EXIT_FAILURE);
        }

        fprintf(stdout,"Initialization of the ESYS context successfull \n");

        rc = Esys_Startup(esys_context, TPM2_SU_CLEAR);
        if (rc != TSS2_RC_SUCCESS)
        {
            fprintf(stderr,"Failed to Startup TPM: 0x%" PRIx32 "0 \n", rc);
            free(tcti_context);
            exit(EXIT_FAILURE);
        }
        ESYS_TR swkHandle = ESYS_TR_NONE;
        
        // Approximation : no session or HMAC authorization defined
        TPM2B_AUTH authValuePK = {
            .size = 5,
            .buffer = {1,2,3,4,5}
        };

        TPM2B_SENSITIVE_CREATE inSensitivePK = {
            .size = 0,
            .sensitive = {
                .userAuth = authValuePK,
                .data = {
                    .size = 0,
                    .buffer = {0}
                },
            },
        };

        TPM2B_PUBLIC inPublic = {
            .size = 0,
            .publicArea = {
                .type = TPM2_ALG_RSA,
                .nameAlg = TPM2_ALG_SHA256,
                .objectAttributes = (
                    TPMA_OBJECT_USERWITHAUTH | 
                    TPMA_OBJECT_RESTRICTED |
                    TPMA_OBJECT_DECRYPT |
                    TPMA_OBJECT_FIXEDTPM |
                    TPMA_OBJECT_FIXEDPARENT |
                    TPMA_OBJECT_SENSITIVEDATAORIGIN 
                ),
                .authPolicy = {
                    .size = 0,
                    .buffer = {},
                },
                .parameters = {
                    .rsaDetail = {
                        .symmetric = {
                            .algorithm = TPM2_ALG_AES,
                            .keyBits = {
                                .aes = 128
                            },
                            .mode = {
                                .aes = TPM2_ALG_CFB,
                            },
                        },
                        .scheme = {
                            .scheme = TPM2_ALG_NULL,
                        /*    .details = {
                                .rsapss = {
                                    .hashAlg = TPM2_ALG_SHA256
                                }
                            }*/
                        },
                        .keyBits = 2048,
                        .exponent = 0,
                    },
                },
                .unique = {
                    .rsa = {
                        .size = 0,
                        .buffer = {},
                    },
                },
            },
        };

        TPM2B_DATA outInfo = {.size = 0, .buffer = {}};
        TPML_PCR_SELECTION pcrSelection = {.count = 0};
        TPM2B_AUTH authValue = {.size = 0, .buffer = {}};

        rc = Esys_TR_SetAuth(esys_context,ESYS_TR_RH_ENDORSEMENT,&authValue);

        TPM2B_PUBLIC *outPublic;
        TPM2B_CREATION_DATA *creationData;
        TPM2B_DIGEST *creationHash;
        TPMT_TK_CREATION *creationTicket;

        printf("\n\nPrima eSWK--> %d\n", s_SWK.eSWK);
        printf("Prima sSWK--> %d\n", s_SWK.sSWK);
        printf("Prima pSWK--> %d\n", s_SWK.pSWK);

        printf("\n-------------Esys_CreatePrimary------------\n");
        rc = Esys_CreatePrimary(
            esys_context,           // [in] esysContext
            ESYS_TR_RH_ENDORSEMENT,              // [in] primaryHandle : hierarchy
            ESYS_TR_PASSWORD,       // [in] Session handle for authorization of primaryHandle
            ESYS_TR_NONE,           // Session handle 2
            ESYS_TR_NONE,           // Session handle 3
            &inSensitivePK,         // [in] inSensitive => sensitive data
            &inPublic,              // [in] public Template
            &outInfo,               // [in] data that will be included in the creation data this object to provide permanent
            &pcrSelection,          // [in] PCR that will be used in the creation process
            &swkHandle,             // [in] object handle
            &outPublic,             // [out] Public portion of the created object 
            &creationData,          // [out] contains the creation data
            &creationHash,          // [out] Digest of creation data
            &creationTicket         // [out] ticket used to validate the creation of the object
        );

        s_SWK.eSWK = swkHandle;

        rc = Esys_TR_SetAuth(esys_context,ESYS_TR_RH_OWNER,&authValue);

        printf("\n-------------Esys_CreatePrimary------------\n");
        rc = Esys_CreatePrimary(
            esys_context,           // [in] esysContext
            ESYS_TR_RH_OWNER,              // [in] primaryHandle : hierarchy
            ESYS_TR_PASSWORD,       // [in] Session handle for authorization of primaryHandle
            ESYS_TR_NONE,           // Session handle 2
            ESYS_TR_NONE,           // Session handle 3
            &inSensitivePK,         // [in] inSensitive => sensitive data
            &inPublic,              // [in] public Template
            &outInfo,               // [in] data that will be included in the creation data this object to provide permanent
            &pcrSelection,          // [in] PCR that will be used in the creation process
            &swkHandle,             // [in] object handle
            &outPublic,             // [out] Public portion of the created object 
            &creationData,          // [out] contains the creation data
            &creationHash,          // [out] Digest of creation data
            &creationTicket         // [out] ticket used to validate the creation of the object
        );

        s_SWK.sSWK = swkHandle;

        rc = Esys_TR_SetAuth(esys_context,ESYS_TR_RH_PLATFORM,&authValue);

        printf("\n-------------Esys_CreatePrimary------------\n");
        rc = Esys_CreatePrimary(
            esys_context,           // [in] esysContext
            ESYS_TR_RH_PLATFORM,              // [in] primaryHandle : hierarchy
            ESYS_TR_PASSWORD,       // [in] Session handle for authorization of primaryHandle
            ESYS_TR_NONE,           // Session handle 2
            ESYS_TR_NONE,           // Session handle 3
            &inSensitivePK,         // [in] inSensitive => sensitive data
            &inPublic,              // [in] public Template
            &outInfo,               // [in] data that will be included in the creation data this object to provide permanent
            &pcrSelection,          // [in] PCR that will be used in the creation process
            &swkHandle,             // [in] object handle
            &outPublic,             // [out] Public portion of the created object 
            &creationData,          // [out] contains the creation data
            &creationHash,          // [out] Digest of creation data
            &creationTicket         // [out] ticket used to validate the creation of the object
        );

        s_SWK.pSWK = swkHandle;

        printf("\n\nDopo eSWK--> %d", s_SWK.eSWK);
        printf("\nDopo sSWK--> %d", s_SWK.sSWK);
        printf("\nDopo pSWK--> %d\n", s_SWK.pSWK);

    
        Tss2_Tcti_Finalize(tcti_context);
        Esys_Finalize(&esys_context);
        free(tcti_context);

    }

    return;
}