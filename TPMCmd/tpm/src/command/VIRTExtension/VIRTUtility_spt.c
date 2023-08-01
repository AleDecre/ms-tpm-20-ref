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
//** Includes
#define TESTMIO
#include "Tpm.h"
#include "VIRTUtility_spt.h"
#include "NvDynamic_fp.h"
#include "Marshal.h"

void Init_Tcti_Esys_Context()
{
    TSS2_RC rc;
    size_t  context_size;

    //Define allocation for the mssim TCTI
    /* 
        TSS2_RC Tss2_Tcti_Tabrmd_Init (TSS2_TCTI_CONTEXT *tcti_context, size_t *size, const char *conf)
        minimum size of the context => pass NULL to conf
        *tcti_context => desired connection properties for the TCTI
    */
    rc = Tss2_Tcti_Mssim_Init(0, &context_size, NULL);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout, "Failed to get allocation size for mssim TCTI \n");
        exit(EXIT_FAILURE);
    }

    s_params.tcti_context = (TSS2_TCTI_CONTEXT*)calloc(1, context_size);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout, "Allocation for TCTI context failed: %d0 \n", rc);
        exit(EXIT_FAILURE);
    }

    rc = Tss2_Tcti_Mssim_Init(
        s_params.tcti_context, &context_size, "host=localhost,port=2321");
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(
            stdout, "Failed to initialize tabrmd TCTI context: 0x%" PRIx32 "0\n", rc);
        free(s_params.tcti_context);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Initialization of the TCTI context successfull\n");

    TSS2_ABI_VERSION abi_version = TSS2_ABI_VERSION_CURRENT;

    //Initialization of the ESYS context
    /*
        TSS2_RC Esys_Initialize( ESYS_CONTEXT **esysContext, TSS2_TCTI_CONTEXT *tcti, TSS2_ABI_VERSION *abiVersion);
        esysContext => reference to a pointer to the opaque ESYS_CONTEXT blob. It must be not NULL
        tcti => pointer to the TCTI context
        abiVersion => pointer to the ABI version that the application requests
    */
    rc = Esys_Initialize(&s_params.esys_context, s_params.tcti_context, &abi_version);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(
            stderr, "Failed to initialize the ESYS context: 0x%" PRIx32 "0 \n", rc);
        free(s_params.tcti_context);
        s_params.tcti_context = NULL;
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Initialization of the ESYS context successfull\n");

    rc = Esys_Startup(s_params.esys_context, TPM2_SU_CLEAR);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stderr, "Failed to Startup TPM: 0x%" PRIx32 "0 \n", rc);
        Finalize_Tcti_Esys_Context();
        exit(EXIT_FAILURE);
    }
}

void Finalize_Tcti_Esys_Context()
{
    Tss2_Tcti_Finalize(s_params.tcti_context);

    fprintf(stdout, "\nFinalization of the TCTI context\n");

    Esys_Finalize(&s_params.esys_context);

    free(s_params.tcti_context);
    s_params.tcti_context = NULL;

    fprintf(stdout, "Finalization of the Esys context\n\n");
}

void LoadSWK(char *swkPath)
{
    TSS2_RC rc;
    
    FILE *swkFile;
    swkFile = fopen(swkPath, "rb");
    if(swkFile == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(swkFile, 0, SEEK_END);
    long fsize = ftell(swkFile);
    fseek(swkFile, 0, SEEK_SET);
    
    char buffer[fsize];
    memset(buffer,0,fsize);

    fread(buffer, fsize, 1, swkFile);

    TPM2B_AUTH authValueSWK = {
        .size = 5,
        .buffer = {1,2,3,4,5}
    };

    size_t nextData = 0;

    Tss2_MU_TPMS_CONTEXT_Unmarshal((uint8_t *)buffer,  fsize, &nextData,  &s_SWK.eSWK.context);
    printf("\n-------------Esys_ContextLoad------------\n");
    rc = Esys_ContextLoad(s_params.esys_context, &s_SWK.eSWK.context, &s_SWK.eSWK.handle);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during context loading\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Context loading successfull\n");
    }
    Esys_TR_SetAuth(s_params.esys_context,s_SWK.eSWK.handle,&authValueSWK);

    Tss2_MU_TPMS_CONTEXT_Unmarshal((uint8_t *)buffer,  fsize, &nextData,  &s_SWK.sSWK.context);
    printf("\n-------------Esys_ContextLoad------------\n");
    rc = Esys_ContextLoad(s_params.esys_context, &s_SWK.sSWK.context, &s_SWK.sSWK.handle);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during context loading\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Context loading successfull\n");
    }
    Esys_TR_SetAuth(s_params.esys_context,s_SWK.sSWK.handle,&authValueSWK);

    Tss2_MU_TPMS_CONTEXT_Unmarshal((uint8_t *)buffer,  fsize, &nextData,  &s_SWK.pSWK.context);
    printf("\n-------------Esys_ContextLoad------------\n");
    rc = Esys_ContextLoad(s_params.esys_context, &s_SWK.pSWK.context, &s_SWK.pSWK.handle);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during context loading\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Context loading successfull\n");
    }
    Esys_TR_SetAuth(s_params.esys_context,s_SWK.pSWK.handle,&authValueSWK);
}

void CreateLoadPrimarySeed(ESYS_TR hierarchy)
{

    SWKEntry* SWK = NULL;
    VPSEntry* VPS = NULL;
    MSSIMI_RH_HIERARCHY *VPSHandle = NULL;
    switch(hierarchy)
    {
        case ESYS_TR_RH_ENDORSEMENT:
            SWK = &s_SWK.eSWK;
            VPS = &s_VPS.vEPS;
            VPSHandle = &s_HandleMap.vEPSHandle;
            break;
        case ESYS_TR_RH_OWNER:
            SWK = &s_SWK.sSWK;
            VPS = &s_VPS.vSPS;
            VPSHandle = &s_HandleMap.vSPSHandle;
            break;
        case ESYS_TR_RH_PLATFORM:
            SWK = &s_SWK.pSWK;
            VPS = &s_VPS.vPPS;
            VPSHandle = &s_HandleMap.vPPSHandle;
            break;
        default:
            break;
    }

    TSS2_RC rc;

    ESYS_TR session = ESYS_TR_NONE;
    ESYS_TR swkHandleAuthSession = SWK->handle;
    TPMT_SYM_DEF symmetric = {.algorithm = TPM2_ALG_AES,
                              .keyBits = {.aes = 128},
                              .mode = {.aes = TPM2_ALG_CFB}};
    TPMA_SESSION sessionAttributes;
    sessionAttributes = (TPMA_SESSION_DECRYPT |
                         TPMA_SESSION_ENCRYPT |
                         TPMA_SESSION_CONTINUESESSION);
    TPM2_SE sessionType = TPM2_SE_HMAC;
    TPMI_ALG_HASH authHash = TPM2_ALG_SHA256;

    rc = Esys_StartAuthSession(
        s_params.esys_context,
        swkHandleAuthSession,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        NULL,
        sessionType,
        &symmetric,
        authHash,
        &session
    );

    rc = Esys_TRSess_SetAttributes(
        s_params.esys_context,
        session,
        sessionAttributes,
        0xff
    );

    TPM2B_AUTH authVPS = {
        .size = 5,
        .buffer = {1,2,3,4,5}
    };

    TPM2B_SENSITIVE_CREATE inSensitiveVPS = {
        .size = 0,
        .sensitive = {
            .userAuth = authVPS,
            .data = {
                .size=128,
                .buffer = {}
            }
        }
    };

    TPM2B_PUBLIC inPublicVPS = {
        .size = 0,
        .publicArea = {
            .type = TPM2_ALG_KEYEDHASH,
            .nameAlg = TPM2_ALG_SHA256,
            .objectAttributes = (
                TPMA_OBJECT_RESTRICTED |
                TPMA_OBJECT_FIXEDTPM |
                TPMA_OBJECT_FIXEDPARENT
            ),
            .authPolicy = {
                .size = 0,
                .buffer = {},
            },
            .parameters = {
                .keyedHashDetail = {
                    .scheme = {
                        .scheme = TPM2_ALG_NULL,
                    }
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

    TPM2B_DATA outInfoVPS = {.size = 0, .buffer = {}};
    TPML_PCR_SELECTION creationPCRdk = { .count = 0,};

    TPM2B_PUBLIC *outPublicVPS;
    TPM2B_PRIVATE *outPrivateVPS;
    TPM2B_CREATION_DATA *creationDataVPS;
    TPM2B_DIGEST *creationHashVPS;
    TPMT_TK_CREATION *creationTicketVPS;

    printf("\n-------------Esys_VIRT_CreateSeed------------\n");
    rc = Esys_VIRT_CreateSeed(
        s_params.esys_context,
        SWK->handle,
        session,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        48,
        &inSensitiveVPS,
        &inPublicVPS,
        &outInfoVPS,
        &creationPCRdk,
        &outPrivateVPS,
        &outPublicVPS,
        &creationDataVPS,
        &creationHashVPS,
        &creationTicketVPS
    );
    
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during the creation of the VPS\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Creation of VPS successfull\n");
    }

    VPS->vpsPrivate = *outPrivateVPS;
    VPS->vpsPublic = *outPublicVPS;

    ESYS_TR vpsHandle = ESYS_TR_NONE;

    printf("\n-------------Esys_VIRT_LoadSeed------------\n");
    rc = Esys_VIRT_LoadSeed(
        s_params.esys_context,
        SWK->handle,
        session,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        outPrivateVPS,
        outPublicVPS,
        &vpsHandle
    );
    
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during loading VPS\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Loading VPS successfull\n");
    }

    rc = Esys_TR_SetAuth(s_params.esys_context,vpsHandle,NULL);
    
    *VPSHandle = (MSSIMI_RH_HIERARCHY)vpsHandle;

    printf("\n-------------Esys_FlushContext------------\n");
    rc = Esys_FlushContext(
        s_params.esys_context,
        session
    );
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during context flushing\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Context flushing successfull\n");
    }

}

void CreateVSPK(char *vspkTemplatePath)
{

    TSS2_RC rc;

    ESYS_TR vspkHandle = ESYS_TR_NONE;
    
    TPM2B_AUTH authValuevPPS = {
        .size = 5,
        .buffer = {1,2,3,4,5}
    };

    TPM2B_SENSITIVE_CREATE inSensitivevPPS = {
        .size = 0,
        .sensitive = {
            .userAuth = authValuevPPS,
            .data = {
                .size = 0,
                .buffer = {0}
            },
        },
    };

    FILE *vspkTemplateFile;
    vspkTemplateFile = fopen(vspkTemplatePath, "rb");
    if(vspkTemplateFile == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(vspkTemplateFile, 0, SEEK_END);
    long fsize = ftell(vspkTemplateFile);
    fseek(vspkTemplateFile, 0, SEEK_SET);
    
    char buffer[fsize];
    memset(buffer,0,fsize);

    fread(buffer, fsize, 1, vspkTemplateFile);

    TPM2B_TEMPLATE inPublicTemplateVSPK;
    
    rc = Tss2_MU_TPM2B_TEMPLATE_Unmarshal((uint8_t *)buffer,  fsize, 0,  &inPublicTemplateVSPK);
    if (rc){
    printf("TEST");
        exit(EXIT_FAILURE);}

    TPM2B_PUBLIC  inPublicVSPK;

    rc = Tss2_MU_TPMT_PUBLIC_Unmarshal(inPublicTemplateVSPK.buffer, sizeof(inPublicTemplateVSPK.buffer), 0, &inPublicVSPK.publicArea);
    if (rc){
    printf("TEST222");
        exit(EXIT_FAILURE);}
    inPublicVSPK.size = inPublicTemplateVSPK.size;
    

    TPM2B_DATA outInfoVSPK = {.size = 0, .buffer = {}};
    TPML_PCR_SELECTION pcrSelectionVSPK = {.count = 0};

    TPM2B_PUBLIC *outPublicVSPK;
    TPM2B_CREATION_DATA *creationDataVSPK;
    TPM2B_DIGEST *creationHashVSPK;
    TPMT_TK_CREATION *creationTicketVSPK;

    printf("\n-------------Esys_VIRT_CreatePrimary------------\n");
    rc = Esys_VIRT_CreatePrimary(
        s_params.esys_context,          // [in] esysContext
        s_HandleMap.vPPSHandle,         // [in] primaryHandle : hierarchy
        ESYS_TR_PASSWORD,               // [in] Session handle for authorization of primaryHandle
        ESYS_TR_NONE,                   // Session handle 2
        ESYS_TR_NONE,                   // Session handle 3
        &inSensitivevPPS,               // [in] inSensitive => sensitive data
        &inPublicVSPK,                  // [in] public Template
        &outInfoVSPK,                   // [in] data that will be included in the creation data this object to provide permanent
        &pcrSelectionVSPK,              // [in] PCR that will be used in the creation process
        &vspkHandle,                    // [in] object handle
        &outPublicVSPK,                 // [out] Public portion of the created object 
        &creationDataVSPK,              // [out] contains the creation data
        &creationHashVSPK,              // [out] Digest of creation data
        &creationTicketVSPK             // [out] ticket used to validate the creation of the object
    );

    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during the creation of the VSPK\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Creation of the VSPK successfull\n");
    }
        
    s_HandleMap.pVSPKHandle = vspkHandle;

}

void StoreRestoreState(){
    TSS2_RC rc;

// STORE STATE PARAMETERS
    // TPM2B_PUBLIC *outPublic = NULL;
    // TPM2B_CREATION_DATA *creationData = NULL;
    // TPM2B_DIGEST *creationHash = NULL;
    // TPMT_TK_CREATION *creationTicket = NULL;
    TPM2B_MAX_BUFFER *outData = NULL;
    TPM2B_IV *ivOut = NULL;

// RESTORE STATE PARAMETERS
    // TPM2B_PUBLIC *outPublic2 = NULL;
    // TPM2B_PRIVATE *outPrivate2 = NULL;
    // TPM2B_CREATION_DATA *creationData2 = NULL;
    // TPM2B_DIGEST *creationHash2 = NULL;
    // TPMT_TK_CREATION *creationTicket2 = NULL;
    TPM2B_MAX_BUFFER *outData2 = NULL;
    TPM2B_IV *ivOut2 = NULL;

    TPMI_ALG_CIPHER_MODE mode = TPM2_ALG_NULL;

    UINT32 maxCmdSize = 1024;
    BYTE cmdBuffer[maxCmdSize];
    size_t nextData = 0;

    rc = Tss2_MU_TPM2B_PRIVATE_Marshal(&s_VPS.vEPS.vpsPrivate, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_TPM2B_PUBLIC_Marshal(&s_VPS.vEPS.vpsPublic, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_TPM2B_PRIVATE_Marshal(&s_VPS.vSPS.vpsPrivate, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_TPM2B_PUBLIC_Marshal(&s_VPS.vSPS.vpsPublic, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_TPM2B_PRIVATE_Marshal(&s_VPS.vPPS.vpsPrivate, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_TPM2B_PUBLIC_Marshal(&s_VPS.vPPS.vpsPublic, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_UINT32_Marshal(s_SWK.eSWK.handle, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);
    
    rc = Tss2_MU_UINT32_Marshal(s_SWK.sSWK.handle, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_UINT32_Marshal(s_SWK.pSWK.handle, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_UINT32_Marshal(s_HandleMap.vEPSHandle, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);
    
    rc = Tss2_MU_UINT32_Marshal(s_HandleMap.vSPSHandle, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_UINT32_Marshal(s_HandleMap.vPPSHandle, cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    rc = Tss2_MU_UINT32_Marshal(sizeof(PERSISTENT_DATA), cmdBuffer,
                                maxCmdSize,
                                &nextData);
    if (rc)
        exit(EXIT_FAILURE);

    NvRead(cmdBuffer+nextData, NV_PERSISTENT_DATA, sizeof(PERSISTENT_DATA));
    nextData += sizeof(PERSISTENT_DATA);

    TPM2B_IV ivIn = {
        .size = 16,
        .buffer = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16}
    };

    TPM2B_MAX_BUFFER inData = {
        .size = (UINT16)1024,
        .buffer = {}
    };

    memcpy(inData.buffer, cmdBuffer, 1024);

    printf("\nMarshalled data in cmdBuffer copied in inData:\n");

    for (size_t i = 0; i < inData.size; i++)
    {
        printf("%d ", inData.buffer[i]);
    }
    printf("\n");

    printf("\n-------------Esys_VIRT_StoreState------------\n");
    rc = Esys_VIRT_StoreState(
        s_params.esys_context,
        s_HandleMap.pVSPKHandle,
        ESYS_TR_PASSWORD,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        &inData,
        mode,
        &ivIn,
        &outData,
        &ivOut);

    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during state storing\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"State storing successfull\n");
    }

    printf("Encrypted inData (outData):\n");

    for (size_t i = 0; i < outData->size; i++)
    {
        printf("%d ", outData->buffer[i]);
    }
    
    printf("\n");

    printf("\n-------------Esys_VIRT_RestoreState------------\n");
    rc = Esys_VIRT_RestoreState(
        s_params.esys_context,
        s_HandleMap.pVSPKHandle,
        ESYS_TR_PASSWORD,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        outData,
        mode,
        &ivIn,
        &outData2,
        &ivOut2);

    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during state restoring\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"State restoring successfull\n");
    }

    printf("Decrypted outData (outData2):\n");

    for (size_t i = 0; i < outData2->size; i++)
    {
        printf("%d ", outData2->buffer[i]);
    }

    printf("\n");

    if (outData2->size != inData.size ||
        memcmp(&outData2->buffer, &inData.buffer[0], outData2->size) != 0) {
        printf("Error: decrypted text not equal to origin");
        exit(EXIT_FAILURE);
    }
   
}
