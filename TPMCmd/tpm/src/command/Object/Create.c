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
#include "Object_spt_fp.h"
#include "Create_fp.h"

#if CC_Create  // Conditional expansion of this file

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
MSSIM_RC
MSSIM2_Create(Create_In*  in,  // IN: input parameter list
            Create_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC       result = MSSIM_RC_SUCCESS;
    OBJECT*      parentObject;
    OBJECT*      newObject;
    MSSIMT_PUBLIC* publicArea;

    if(s_vTPM && in->inPublic.publicArea.objectAttributes & MSSIMA_OBJECT_pMSSIMCreated){
        // printf("\nPTPMCREATED CREATED\n");

        TSS2_RC rc;

        TPM2B_SENSITIVE_CREATE inSensitive = {
            .size = in->inSensitive.size,
            .sensitive = {
                .userAuth = {
                    .size = in->inSensitive.sensitive.userAuth.t.size,
                    .buffer = {*in->inSensitive.sensitive.userAuth.t.buffer},
                },
                .data = {
                    .size = in->inSensitive.sensitive.data.t.size,
                    .buffer = {*in->inSensitive.sensitive.data.t.buffer},
                },
            },
        };
        TPM2B_PUBLIC inPublic = {
            .size = in->inSensitive.size,
            .publicArea = {
                .authPolicy = {
                    .size = in->inPublic.publicArea.authPolicy.t.size,
                    .buffer = {*in->inPublic.publicArea.authPolicy.t.buffer},
                },
                .nameAlg = in->inPublic.publicArea.nameAlg,
                .objectAttributes = in->inPublic.publicArea.objectAttributes,
                .type = in->inPublic.publicArea.type,
            }
        };

        switch(in->inPublic.publicArea.type)
            {
                case MSSIM_ALG_KEYEDHASH:
                    inPublic.publicArea.parameters.keyedHashDetail.scheme.details.exclusiveOr.hashAlg = in->inPublic.publicArea.parameters.keyedHashDetail.scheme.details.xor.hashAlg;
                    inPublic.publicArea.parameters.keyedHashDetail.scheme.details.exclusiveOr.kdf = in->inPublic.publicArea.parameters.keyedHashDetail.scheme.details.xor.kdf;
                    inPublic.publicArea.parameters.keyedHashDetail.scheme.details.hmac.hashAlg = in->inPublic.publicArea.parameters.keyedHashDetail.scheme.details.hmac.hashAlg;
                    inPublic.publicArea.parameters.keyedHashDetail.scheme.details.null.empty[0] = 0;
                    inPublic.publicArea.parameters.keyedHashDetail.scheme.scheme = in->inPublic.publicArea.parameters.keyedHashDetail.scheme.scheme;
                    inPublic.publicArea.unique.keyedHash.size = in->inPublic.publicArea.unique.keyedHash.t.size;
                    memcpy(inPublic.publicArea.unique.keyedHash.buffer, in->inPublic.publicArea.unique.keyedHash.t.buffer, in->inPublic.publicArea.unique.keyedHash.t.size);
                case MSSIM_ALG_SYMCIPHER:
                    inPublic.publicArea.parameters.symDetail.sym.algorithm = in->inPublic.publicArea.parameters.symDetail.sym.algorithm;
                    switch(in->inPublic.publicArea.parameters.symDetail.sym.algorithm)
                    {
                        case MSSIM_ALG_AES:
                            inPublic.publicArea.parameters.symDetail.sym.keyBits.aes = in->inPublic.publicArea.parameters.symDetail.sym.keyBits.aes;
                            inPublic.publicArea.parameters.symDetail.sym.mode.aes = in->inPublic.publicArea.parameters.symDetail.sym.mode.aes;
                        case MSSIM_ALG_CAMELLIA:
                            inPublic.publicArea.parameters.symDetail.sym.keyBits.camellia = in->inPublic.publicArea.parameters.symDetail.sym.keyBits.camellia;
                            inPublic.publicArea.parameters.symDetail.sym.mode.camellia = in->inPublic.publicArea.parameters.symDetail.sym.mode.camellia;
                        case MSSIM_ALG_XOR:
                            inPublic.publicArea.parameters.symDetail.sym.keyBits.exclusiveOr = in->inPublic.publicArea.parameters.symDetail.sym.keyBits.xor;
                        case MSSIM_ALG_SYMCIPHER:
                            inPublic.publicArea.parameters.symDetail.sym.keyBits.sym = in->inPublic.publicArea.parameters.symDetail.sym.keyBits.sym;
                            inPublic.publicArea.parameters.symDetail.sym.mode.sym = in->inPublic.publicArea.parameters.symDetail.sym.mode.sym;
                        default:
                            return -1;
                    }
                case MSSIM_ALG_RSA:
                    inPublic.publicArea.parameters.rsaDetail.exponent = in->inPublic.publicArea.parameters.rsaDetail.exponent;
                    inPublic.publicArea.parameters.rsaDetail.keyBits = in->inPublic.publicArea.parameters.rsaDetail.keyBits;
                    inPublic.publicArea.parameters.rsaDetail.scheme.scheme = in->inPublic.publicArea.parameters.rsaDetail.scheme.scheme;
                    switch(in->inPublic.publicArea.parameters.rsaDetail.scheme.scheme)
                    {
                        case MSSIM_ALG_ECDAA:
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdaa.hashAlg = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdaa.hashAlg;
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdaa.count = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdaa.count;
                        case MSSIM_ALG_ECDH:
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdh.hashAlg = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdh.hashAlg;
                        case MSSIM_ALG_ECDSA:
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdsa.hashAlg = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.ecdsa.hashAlg;
                        case MSSIM_ALG_ECSCHNORR:
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.ecschnorr.hashAlg = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.ecschnorr.hashAlg;
                        case MSSIM_ALG_OAEP:
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.oaep.hashAlg = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.oaep.hashAlg;
                        case MSSIM_ALG_RSASSA:
                            inPublic.publicArea.parameters.rsaDetail.scheme.details.rsassa.hashAlg = in->inPublic.publicArea.parameters.rsaDetail.scheme.details.rsassa.hashAlg;
                        default:
                            return -1;
                    }
                    inPublic.publicArea.parameters.rsaDetail.symmetric.algorithm = in->inPublic.publicArea.parameters.rsaDetail.symmetric.algorithm;
                    switch(in->inPublic.publicArea.parameters.rsaDetail.symmetric.algorithm)
                    {
                        case MSSIM_ALG_AES:
                            inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.aes = in->inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.aes;
                            inPublic.publicArea.parameters.rsaDetail.symmetric.mode.aes = in->inPublic.publicArea.parameters.rsaDetail.symmetric.mode.aes;
                        case MSSIM_ALG_CAMELLIA:
                            inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.camellia = in->inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.camellia;
                            inPublic.publicArea.parameters.rsaDetail.symmetric.mode.camellia = in->inPublic.publicArea.parameters.rsaDetail.symmetric.mode.camellia;
                        case MSSIM_ALG_XOR:
                            inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.exclusiveOr = in->inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.xor;
                        case MSSIM_ALG_SYMCIPHER:
                            inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.sym = in->inPublic.publicArea.parameters.rsaDetail.symmetric.keyBits.sym;
                            inPublic.publicArea.parameters.rsaDetail.symmetric.mode.sym = in->inPublic.publicArea.parameters.rsaDetail.symmetric.mode.sym;
                        default:
                            return -1;
                    }
                case MSSIM_ALG_ECC:
                    inPublic.publicArea.parameters.eccDetail.curveID = in->inPublic.publicArea.parameters.eccDetail.curveID;
                    inPublic.publicArea.parameters.eccDetail.scheme.scheme = in->inPublic.publicArea.parameters.eccDetail.scheme.scheme;
                    switch(in->inPublic.publicArea.parameters.eccDetail.scheme.scheme)
                    {
                        case MSSIM_ALG_ECDAA:
                            inPublic.publicArea.parameters.eccDetail.scheme.details.ecdaa.hashAlg = in->inPublic.publicArea.parameters.eccDetail.scheme.details.ecdaa.hashAlg;
                            inPublic.publicArea.parameters.eccDetail.scheme.details.ecdaa.count = in->inPublic.publicArea.parameters.eccDetail.scheme.details.ecdaa.count;
                        case MSSIM_ALG_ECDH:
                            inPublic.publicArea.parameters.eccDetail.scheme.details.ecdh.hashAlg = in->inPublic.publicArea.parameters.eccDetail.scheme.details.ecdh.hashAlg;
                        case MSSIM_ALG_ECDSA:
                            inPublic.publicArea.parameters.eccDetail.scheme.details.ecdsa.hashAlg = in->inPublic.publicArea.parameters.eccDetail.scheme.details.ecdsa.hashAlg;
                        case MSSIM_ALG_ECSCHNORR:
                            inPublic.publicArea.parameters.eccDetail.scheme.details.ecschnorr.hashAlg = in->inPublic.publicArea.parameters.eccDetail.scheme.details.ecschnorr.hashAlg;
                        case MSSIM_ALG_OAEP:
                            inPublic.publicArea.parameters.eccDetail.scheme.details.oaep.hashAlg = in->inPublic.publicArea.parameters.eccDetail.scheme.details.oaep.hashAlg;
                        case MSSIM_ALG_RSASSA:
                            inPublic.publicArea.parameters.eccDetail.scheme.details.rsassa.hashAlg = in->inPublic.publicArea.parameters.eccDetail.scheme.details.rsassa.hashAlg;
                        default:
                            return -1;
                    }

                    inPublic.publicArea.parameters.eccDetail.kdf.scheme = in->inPublic.publicArea.parameters.eccDetail.kdf.scheme;
                    switch(in->inPublic.publicArea.parameters.eccDetail.symmetric.algorithm)
                    {
                        case MSSIM_ALG_KDF1_SP800_108:
                            inPublic.publicArea.parameters.eccDetail.kdf.details.kdf1_sp800_108.hashAlg = in->inPublic.publicArea.parameters.eccDetail.kdf.details.kdf1_sp800_108.hashAlg;
                        case MSSIM_ALG_KDF1_SP800_56A:
                            inPublic.publicArea.parameters.eccDetail.kdf.details.kdf1_sp800_56a.hashAlg = in->inPublic.publicArea.parameters.eccDetail.kdf.details.kdf1_sp800_56a.hashAlg;
                        case MSSIM_ALG_KDF2:
                            inPublic.publicArea.parameters.eccDetail.kdf.details.kdf2.hashAlg = in->inPublic.publicArea.parameters.eccDetail.kdf.details.kdf2.hashAlg;
                        case MSSIM_ALG_MGF1:
                            inPublic.publicArea.parameters.eccDetail.kdf.details.mgf1.hashAlg = in->inPublic.publicArea.parameters.eccDetail.kdf.details.mgf1.hashAlg;
                        default:
                            return -1;
                    }

                    inPublic.publicArea.parameters.eccDetail.symmetric.algorithm = in->inPublic.publicArea.parameters.eccDetail.symmetric.algorithm;
                    switch(in->inPublic.publicArea.parameters.eccDetail.symmetric.algorithm)
                    {
                        case MSSIM_ALG_AES:
                            inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.aes = in->inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.aes;
                            inPublic.publicArea.parameters.eccDetail.symmetric.mode.aes = in->inPublic.publicArea.parameters.eccDetail.symmetric.mode.aes;
                        case MSSIM_ALG_CAMELLIA:
                            inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.camellia = in->inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.camellia;
                            inPublic.publicArea.parameters.eccDetail.symmetric.mode.camellia = in->inPublic.publicArea.parameters.eccDetail.symmetric.mode.camellia;
                        case MSSIM_ALG_XOR:
                            inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.exclusiveOr = in->inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.xor;
                        case MSSIM_ALG_SYMCIPHER:
                            inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.sym = in->inPublic.publicArea.parameters.eccDetail.symmetric.keyBits.sym;
                            inPublic.publicArea.parameters.eccDetail.symmetric.mode.sym = in->inPublic.publicArea.parameters.eccDetail.symmetric.mode.sym;
                        default:
                            return -1;
                    }
                default:
                    return -1;
            }

        // TPM2B_DATA outInfoSWK = {.size = 0, .buffer = {}};
        // TPML_PCR_SELECTION pcrSelectionSWK = { .count = 0,};
        // TPM2B_PUBLIC *outPublicSWK;
        // TPM2B_PRIVATE *outPrivateSWK;
        // TPM2B_CREATION_DATA *creationDataSWK;
        // TPM2B_DIGEST *creationHashSWK;
        // TPMT_TK_CREATION *creationTicketSWK;

        // printf("\n-------------Esys_Create------------\n");
        rc = Esys_Create(
            s_params.esys_context,
            in->parentHandle,
            ESYS_TR_PASSWORD,
            ESYS_TR_NONE,
            ESYS_TR_NONE,
            &inSensitive,
            &inPublic,
            &in->outsideInfo,
            &in->creationPCR,
            &out->outPrivate,
            &out->outPublic,
            &out->creationData,
            &out->creationHash,
            &out->creationTicket
            );
        if (rc)
            return rc;
    }
    else{
        // Input Validation
        parentObject = HandleToObject(in->parentHandle);
        pAssert(parentObject != NULL);

        // Does parent have the proper attributes?
        if(!ObjectIsParent(parentObject))
            return MSSIM_RCS_TYPE + RC_Create_parentHandle;

        // Get a slot for the creation
        newObject = FindEmptyObjectSlot(NULL);
        if(newObject == NULL)
            return MSSIM_RC_OBJECT_MEMORY;
        // If the MSSIM2B_PUBLIC was passed as a structure, marshal it into is canonical
        // form for processing

        // to save typing.
        publicArea = &newObject->publicArea;

        // Copy the input structure to the allocated structure
        *publicArea = in->inPublic.publicArea;

        // Check attributes in input public area. CreateChecks() checks the things that
        // are unique to creation and then validates the attributes and values that are
        // common to create and load.
        result =
            CreateChecks(parentObject, publicArea, in->inSensitive.sensitive.data.t.size);
        if(result != MSSIM_RC_SUCCESS)
            return RcSafeAddToResult(result, RC_Create_inPublic);
        // Clean up the authValue if necessary
        if(!AdjustAuthSize(&in->inSensitive.sensitive.userAuth, publicArea->nameAlg))
            return MSSIM_RCS_SIZE + RC_Create_inSensitive;

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
    }

    return MSSIM_RC_SUCCESS;
}

#endif  // CC_Create