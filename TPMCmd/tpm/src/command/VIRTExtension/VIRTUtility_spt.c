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
#include "Tpm.h"
#include "VIRTUtility_spt.h"
#include "Marshal.h"


void Init_Tcti_Esys_Context()
{
    TSS2_RC rc;
    size_t context_size;

    //Define allocation for the mssim TCTI
    /* 
        TSS2_RC Tss2_Tcti_Tabrmd_Init (TSS2_TCTI_CONTEXT *tcti_context, size_t *size, const char *conf)
        minimum size of the context => pass NULL to conf
        *tcti_context => desired connection properties for the TCTI
    */
    rc = Tss2_Tcti_Mssim_Init(0, &context_size, NULL);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Failed to get allocation size for mssim TCTI \n");
        exit(EXIT_FAILURE);
    }
    
    s_params.tcti_context = (TSS2_TCTI_CONTEXT *) calloc(1,context_size);
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout, "Allocation for TCTI context failed: %d0 \n", rc);
        exit(EXIT_FAILURE);
    }

    rc = Tss2_Tcti_Mssim_Init(s_params.tcti_context,&context_size, "host=localhost,port=2321");
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout, "Failed to initialize tabrmd TCTI context: 0x%" PRIx32 "0\n", rc);
        free(s_params.tcti_context);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout,"Initialization of the TCTI context successfull\n");


    TSS2_ABI_VERSION abi_version = TSS2_ABI_VERSION_CURRENT;

    //Initialization of the ESYS context
    /*
        TSS2_RC Esys_Initialize( ESYS_CONTEXT **esysContext, TSS2_TCTI_CONTEXT *tcti, TSS2_ABI_VERSION *abiVersion);
        esysContext => reference to a pointer to the opaque ESYS_CONTEXT blob. It must be not NULL
        tcti => pointer to the TCTI context
        abiVersion => pointer to the ABI version that the application requests
    */
    rc = Esys_Initialize(&s_params.esys_context,s_params.tcti_context,&abi_version);
    if (rc != TSS2_RC_SUCCESS)
    {
        fprintf(stderr,"Failed to initialize the ESYS context: 0x%" PRIx32 "0 \n", rc);
        free(s_params.tcti_context);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout,"Initialization of the ESYS context successfull\n");


}

void Finalize_Tcti_Esys_Context()
{
    Tss2_Tcti_Finalize(s_params.tcti_context);

    fprintf(stdout,"\nFinalization of the TCTI context\n");

    Esys_Finalize(&s_params.esys_context);

    free(s_params.tcti_context);
    s_params.tcti_context = NULL;
    
    fprintf(stdout,"Finalization of the Esys context\n\n");
}

/*
void CreateSWK(ESYS_TR hierarchy){

    TSS2_RC rc;

    TPM2B_AUTH authValueHierarchy = {.size = 0, .buffer = {}};
    rc = Esys_TR_SetAuth(esys_context, hierarchy, &authValueHierarchy); 

    ESYS_TR primaryKeyHandle = ESYS_TR_NONE;

    TPM2B_AUTH authValuePrimaryKey = {
        .size = 5,
        .buffer = {1,2,3,4,5}
    };
    TPM2B_SENSITIVE_CREATE inSensitivePrimaryKey = {
        .size = 0,
        .sensitive = {
            .userAuth = authValuePrimaryKey,
            .data = {
                .size = 0,
                .buffer = {0}
            },
        },
    };
    TPM2B_PUBLIC inPublicPrimaryKey = {
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
                        //   .details = {
                        //     .rsapss = {
                        //         .hashAlg = TPM2_ALG_SHA256
                        //     }
                        // }
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

    TPM2B_DATA outInfoPrimaryKey = {.size = 0, .buffer = {}};
    TPML_PCR_SELECTION pcrSelectionPrimaryKey = {.count = 0};
    TPM2B_PUBLIC *outPublicPrimaryKey;
    TPM2B_CREATION_DATA *creationDataPrimaryKey;
    TPM2B_DIGEST *creationHashPrimaryKey;
    TPMT_TK_CREATION *creationTicketPrimaryKey;

    printf("\n-------------Esys_CreatePrimary------------\n");
    rc = Esys_CreatePrimary(
        esys_context,                       // [in] esysContext
        hierarchy,                          // [in] primaryHandle : hierarchy
        ESYS_TR_PASSWORD,                   // [in] Session handle for authorization of primaryHandle
        ESYS_TR_NONE,                       // Session handle 2
        ESYS_TR_NONE,                       // Session handle 3
        &inSensitivePrimaryKey,             // [in] inSensitive => sensitive data
        &inPublicPrimaryKey,                // [in] public Template
        &outInfoPrimaryKey,                 // [in] data that will be included in the creation data this object to provide permanent
        &pcrSelectionPrimaryKey,            // [in] PCR that will be used in the creation process
        &primaryKeyHandle,                  // [in] object handle
        &outPublicPrimaryKey,               // [out] Public portion of the created object 
        &creationDataPrimaryKey,            // [out] contains the creation data
        &creationHashPrimaryKey,            // [out] Digest of creation data
        &creationTicketPrimaryKey           // [out] ticket used to validate the creation of the object
    );

    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during the creation of the primary key\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Creation of the Key successfull\n");
    }

    rc = Esys_TR_SetAuth(esys_context,primaryKeyHandle,&authValuePrimaryKey);


    Key *SWK;
    switch (hierarchy)
    {
    case ESYS_TR_RH_ENDORSEMENT:
        SWK = &eSWK;
        break;
    case ESYS_TR_RH_OWNER:
        SWK = &sSWK;
        break;
    case ESYS_TR_RH_PLATFORM:
        SWK = &pSWK;
        break;
    default:
        break;
    }

    ESYS_TR swkHandle = ESYS_TR_NONE;

    TPM2B_AUTH authValueSWK = {
        .size = 5,
        .buffer = {1,2,3,4,5}
    };
    TPM2B_SENSITIVE_CREATE inSensitiveSWK = {
        .size = 0,
        .sensitive = {
            .userAuth = authValueSWK,
            .data = {
                 .size = 0,
                 .buffer = {0},
             },
        },
    };
    TPM2B_PUBLIC inPublicSWK = {
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
                    //     .details = {
                    //         .rsapss = {
                    //             .hashAlg = TPM2_ALG_SHA256
                    //         }
                    //     }
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

    TPM2B_DATA outInfoSWK = {.size = 0, .buffer = {}};
    TPML_PCR_SELECTION pcrSelectionSWK = { .count = 0,};
    TPM2B_PUBLIC *outPublicSWK;
    TPM2B_PRIVATE *outPrivateSWK;
    TPM2B_CREATION_DATA *creationDataSWK;
    TPM2B_DIGEST *creationHashSWK;
    TPMT_TK_CREATION *creationTicketSWK;

    printf("\n-------------Esys_Create------------\n");
    rc = Esys_Create(
        esys_context,
        primaryKeyHandle,
        ESYS_TR_PASSWORD,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        &inSensitiveSWK,
        &inPublicSWK,
        &outInfoSWK,
        &pcrSelectionSWK,
        &outPrivateSWK,
        &outPublicSWK,
        &creationDataSWK,
        &creationHashSWK,
        &creationTicketSWK
        );
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during creation of the SWK\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Loading SWK successfull\n");
    }
    printf("\n-------------Esys_Load------------\n");
    rc = Esys_Load(
        esys_context,
        primaryKeyHandle,
        ESYS_TR_PASSWORD,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        outPrivateSWK,
        outPublicSWK,
        &swkHandle
    );
    
    if(rc != TSS2_RC_SUCCESS)
    {
        fprintf(stdout,"Error during loading the SWK\n");
        exit(EXIT_FAILURE);
    } else
    {
        fprintf(stdout,"Loading SWK successfull\n");
    }


    rc = Esys_TR_SetAuth(esys_context,swkHandle,&authValueSWK);
    
    SWK->keyHandle = swkHandle;
    SWK->creationData = creationDataSWK;
    SWK->creationHash = creationHashSWK;
    SWK->creationTicket = creationTicketSWK;
    SWK->outPublic = outPublicSWK;

}

*/