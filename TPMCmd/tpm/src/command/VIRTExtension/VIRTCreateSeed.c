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
#include "VIRT_CreateSeed_fp.h"
#include "stdio.h"
#include "tss2/tss2_tcti_mssim.h"
#include "tss2/tss2-tcti-tabrmd.h"
#include "tss2/tss2_esys.h"

#if CC_VIRT_CreateSeed  // Conditional expansion of this file

/*(See part 3 specification)
// Create a regular object
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES       'sensitiveDataOrigin' is CLEAR when 'sensitive.data'
//                              is an Empty Buffer, or is SET when 'sensitive.data' is
//                              not empty;
//                              'fixedMSSIM', 'fixedParent', or 'encryptedDuplication'
//                              attributes are inconsistent between themselves or with
//                              those of the parent object;
//                              inconsistent 'restricted', 'decrypt' and 'sign'
//                              attributes;
//                              attempt to inject sensitive data for an asymmetric
//                              key;
//      MSSIM_RC_HASH             non-duplicable storage key and its parent have
//                              different name algorithm
//      MSSIM_RC_KDF              incorrect KDF specified for decrypting keyed hash
//                              object
//      MSSIM_RC_KEY              invalid key size values in an asymmetric key public
//                              area or a provided symmetric key has a value that is
//                              not allowed
//      MSSIM_RC_KEY_SIZE         key size in public area for symmetric key differs from
//                              the size in the sensitive creation area; may also be
//                              returned if the MSSIM does not allow the key size to be
//                              used for a Storage Key
//      MSSIM_RC_OBJECT_MEMORY    a free slot is not available as scratch memory for
//                              object creation
//      MSSIM_RC_RANGE            the exponent value of an RSA key is not supported.
//      MSSIM_RC_SCHEME           inconsistent attributes 'decrypt', 'sign', or
//                              'restricted' and key's scheme ID; or hash algorithm is
//                              inconsistent with the scheme ID for keyed hash object
//      MSSIM_RC_SIZE             size of public authPolicy or sensitive authValue does
//                              not match digest size of the name algorithm
//                              sensitive data size for the keyed hash object is
//                              larger than is allowed for the scheme
//      MSSIM_RC_SYMMETRIC        a storage key with no symmetric algorithm specified;
//                              or non-storage key with symmetric algorithm different
//                              from MSSIM_ALG_NULL
//      MSSIM_RC_TYPE             unknown object type;
//                              'parentHandle' does not reference a restricted
//                              decryption key in the storage hierarchy with both
//                              public and sensitive portion loaded
//      MSSIM_RC_VALUE            exponent is not prime or could not find a prime using
//                              the provided parameters for an RSA key;
//                              unsupported name algorithm for an ECC key
//      MSSIM_RC_OBJECT_MEMORY    there is no free slot for the object
MSSIM_RC MSSIM2_VIRT_CreateSeed(VIRTCreateSeed_In* in, VIRTCreateSeed_Out* out)
{
    MSSIM_RC       result = MSSIM_RC_SUCCESS;
    OBJECT*      parentObject;
    OBJECT*      newObject;
    MSSIMT_PUBLIC* publicArea;


// TEST TCTI CONNECTION



    TSS2_RC rc;
    size_t context_size;

    TSS2_ABI_VERSION abi_version = TSS2_ABI_VERSION_CURRENT;
    ESYS_CONTEXT *esys_context = 0;


    rc = Tss2_Tcti_Tabrmd_Init(0, &context_size, NULL);
    
    TSS2_TCTI_CONTEXT *tcti_context = (TSS2_TCTI_CONTEXT *) calloc(1,context_size);

    fprintf(stdout,"OOOOOOOOOOOOOOOOOOO \n");
    rc = Tss2_Tcti_Tabrmd_Init(tcti_context,&context_size, NULL);
    fprintf(stdout,"KKKKKKKKKKKKKKKKKKK \n");

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


    TPM2B_DIGEST *randomBytes;
    rc = Esys_GetRandom(esys_context, ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                       20, &randomBytes);

    printf("random size: %d\n", randomBytes->size);
    printf("random contents: ");

    for(int i = 0; i < randomBytes->size; i++) {
        printf("%d ", randomBytes->buffer[i]);
    }
    printf("\n");


    free(tcti_context);



// END TEST TCTI CONNECTION

    // Input Validation
    parentObject = HandleToObject(in->parentHandle);
    pAssert(parentObject != NULL);

    printf("TEST1\n\n\n");
    // Does parent have the proper attributes?
    if(!ObjectIsParent(parentObject))
        return MSSIM_RCS_TYPE + RC_VIRT_CreateSeed_parentHandle;

    printf("TEST2\n\n\n");
    // Get a slot for the creation
    newObject = FindEmptyObjectSlot(NULL);
    if(newObject == NULL)
        return MSSIM_RC_OBJECT_MEMORY;
    // If the MSSIM2_TSSB_PUBLIC was passed as a structure, marshal it into is canonical
    // form for processing

    // to save typing.
    publicArea = &newObject->publicArea;

    // Copy the input structure to the allocated structure
    *publicArea = in->inPublic.publicArea;

    // Check attributes in input public area. CreateChecks() checks the things that
    // are unique to creation and then validates the attributes and values that are
    // common to create and load.
    result =
        VIRTCreateChecks(parentObject, publicArea, in->inSensitive.sensitive.data.t.size);
    if(result != MSSIM_RC_SUCCESS){
        return RcSafeAddToResult(result, RC_VIRT_CreateSeed_inPublic);}
    // Clean up the authValue if necessary
    if(!AdjustAuthSize(&in->inSensitive.sensitive.userAuth, publicArea->nameAlg))
        return MSSIM_RCS_SIZE + RC_VIRT_CreateSeed_inSensitive;

    // if the requested bytes exceed the output buffer size, generates the
    // maximum bytes that the output buffer allows

    CryptRandomGenerate(in->inSensitive.sensitive.data.t.size, in->inSensitive.sensitive.data.t.buffer);

    printf("buffer size: %d\n", in->inSensitive.sensitive.data.t.size);
    printf("buffer contents: ");

    for(int i = 0; i < in->inSensitive.sensitive.data.t.size; i++) {
        printf("%d ", in->inSensitive.sensitive.data.t.buffer[i]);
    }
    printf("\n");


    // Command Output
    // Create the object using the default MSSIM random-number generator
    result = CryptCreateObject(newObject, &in->inSensitive.sensitive, NULL);
    if(result != MSSIM_RC_SUCCESS)
        return result;
    // Fill in creation data
    FillInCreationData(in->parentHandle,
                       publicArea->nameAlg,
                       &in->creationPCR,
                       &in->outsideInfo,
                       &out->creationData,
                       &out->creationHash);

    // Compute creation ticket
    TicketComputeCreation(EntityGetHierarchy(in->parentHandle),
                          &newObject->name,
                          &out->creationHash,
                          &out->creationTicket);

    // Prepare output private data from sensitive
    SensitiveToPrivate(&newObject->sensitive,
                       &newObject->name,
                       parentObject,
                       publicArea->nameAlg,
                       &out->outPrivate);

    // Finish by copying the remaining return values
    out->outPublic.publicArea = newObject->publicArea;

    return MSSIM_RC_SUCCESS;
}

#endif  // CC_VIRT_CreateSeed