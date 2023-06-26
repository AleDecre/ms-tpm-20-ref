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
#include "CreateLoaded_fp.h"

#if CC_CreateLoaded  // Conditional expansion of this file

/*(See part 3 of specification)
 * Create and load any type of key, including a temporary key.
 * The input template is a marshaled public area rather than an unmarshaled one as
 * used in Create and CreatePrimary. This is so that the label and context that
 * could be in the template can be processed without changing the formats for the
 * calls to Create and CreatePrimary.
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES       'sensitiveDataOrigin' is CLEAR when 'sensitive.data'
//                              is an Empty Buffer;
//                              'fixedMSSIM', 'fixedParent', or 'encryptedDuplication'
//                              attributes are inconsistent between themselves or with
//                              those of the parent object;
//                              inconsistent 'restricted', 'decrypt' and 'sign'
//                              attributes;
//                              attempt to inject sensitive data for an asymmetric
//                              key;
//                              attempt to create a symmetric cipher key that is not
//                              a decryption key
//      MSSIM_RC_KDF              incorrect KDF specified for decrypting keyed hash
//                              object
//      MSSIM_RC_KEY              the value of a provided symmetric key is not allowed
//      MSSIM_RC_OBJECT_MEMORY    there is no free slot for the object
//      MSSIM_RC_SCHEME           inconsistent attributes 'decrypt', 'sign',
//                              'restricted' and key's scheme ID; or hash algorithm is
//                              inconsistent with the scheme ID for keyed hash object
//      MSSIM_RC_SIZE             size of public authorization policy or sensitive
//                              authorization value does not match digest size of the
//                              name algorithm sensitive data size for the keyed hash
//                              object is larger than is allowed for the scheme
//      MSSIM_RC_SYMMETRIC        a storage key with no symmetric algorithm specified;
//                              or non-storage key with symmetric algorithm different
//                              from MSSIM_ALG_NULL
//      MSSIM_RC_TYPE             cannot create the object of the indicated type
//                              (usually only occurs if trying to derive an RSA key).
MSSIM_RC
MSSIM2_CreateLoaded(CreateLoaded_In*  in,  // IN: input parameter list
                  CreateLoaded_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC       result = MSSIM_RC_SUCCESS;
    OBJECT*      parent = HandleToObject(in->parentHandle);
    OBJECT*      newObject;
    BOOL         derivation;
    MSSIMT_PUBLIC* publicArea;
    RAND_STATE   randState;
    RAND_STATE*  rand = &randState;
    MSSIMS_DERIVE  labelContext;

    // Input Validation

    // How the public area is unmarshaled is determined by the parent, so
    // see if parent is a derivation parent
    derivation = (parent != NULL && parent->attributes.derivation);

    // If the parent is an object, then make sure that it is either a parent or
    // derivation parent
    if(parent != NULL && !parent->attributes.isParent && !derivation)
        return MSSIM_RCS_TYPE + RC_CreateLoaded_parentHandle;

    // Get a spot in which to create the newObject
    newObject = FindEmptyObjectSlot(&out->objectHandle);
    if(newObject == NULL)
        return MSSIM_RC_OBJECT_MEMORY;

    // Do this to save typing
    publicArea = &newObject->publicArea;

    // Unmarshal the template into the object space. MSSIM2_Create() and
    // MSSIM2_CreatePrimary() have the publicArea unmarshaled by CommandDispatcher.
    // This command is different because of an unfortunate property of the
    // unique field of an ECC key. It is a structure rather than a single MSSIM2B. If
    // if had been a MSSIM2B, then the label and context could be within a MSSIM2B and
    // unmarshaled like other public areas. Since it is not, this command needs its
    // on template that is a MSSIM2B that is unmarshaled as a BYTE array with a
    // its own unmarshal function.
    result = UnmarshalToPublic(publicArea, &in->inPublic, derivation, &labelContext);
    if(result != MSSIM_RC_SUCCESS)
        return result + RC_CreateLoaded_inPublic;

    // Validate that the authorization size is appropriate
    if(!AdjustAuthSize(&in->inSensitive.sensitive.userAuth, publicArea->nameAlg))
        return MSSIM_RCS_SIZE + RC_CreateLoaded_inSensitive;

    // Command output
    if(derivation)
    {
        MSSIMT_KEYEDHASH_SCHEME* scheme;
        scheme = &parent->publicArea.parameters.keyedHashDetail.scheme;

        // SP800-108 is the only KDF supported by this implementation and there is
        // no default hash algorithm.
        pAssert(scheme->details.xor.hashAlg != MSSIM_ALG_NULL
                && scheme->details.xor.kdf == MSSIM_ALG_KDF1_SP800_108);
        // Don't derive RSA keys
        if(publicArea->type == MSSIM_ALG_RSA)
            return MSSIM_RCS_TYPE + RC_CreateLoaded_inPublic;
        // sensitiveDataOrigin has to be CLEAR in a derived object. Since this
        // is specific to a derived object, it is checked here.
        if(IS_ATTRIBUTE(
               publicArea->objectAttributes, MSSIMA_OBJECT, sensitiveDataOrigin))
            return MSSIM_RCS_ATTRIBUTES;
        // Check the reset of the attributes
        result = PublicAttributesValidation(parent, publicArea);
        if(result != MSSIM_RC_SUCCESS)
            return RcSafeAddToResult(result, RC_CreateLoaded_inPublic);
        // Process the template and sensitive areas to get the actual 'label' and
        // 'context' values to be used for this derivation.
        result = SetLabelAndContext(&labelContext, &in->inSensitive.sensitive.data);
        if(result != MSSIM_RC_SUCCESS)
            return result;
        // Set up the KDF for object generation
        DRBG_InstantiateSeededKdf((KDF_STATE*)rand,
                                  scheme->details.xor.hashAlg,
                                  scheme->details.xor.kdf,
                                  &parent->sensitive.sensitive.bits.b,
                                  &labelContext.label.b,
                                  &labelContext.context.b,
                                  MSSIM_MAX_DERIVATION_BITS);
        // Clear the sensitive size so that the creation functions will not try
        // to use this value.
        in->inSensitive.sensitive.data.t.size = 0;
    }
    else
    {
        // Check attributes in input public area. CreateChecks() checks the things
        // that are unique to creation and then validates the attributes and values
        // that are common to create and load.
        result =
            CreateChecks(parent, publicArea, in->inSensitive.sensitive.data.t.size);
        if(result != MSSIM_RC_SUCCESS)
            return RcSafeAddToResult(result, RC_CreateLoaded_inPublic);
        // Creating a primary object
        if(parent == NULL)
        {
            MSSIM2B_NAME name;
            newObject->attributes.primary = SET;
            if(in->parentHandle == MSSIM_RH_ENDORSEMENT)
                newObject->attributes.epsHierarchy = SET;
            // If so, use the primary seed and the digest of the template
            // to seed the DRBG
            result = DRBG_InstantiateSeeded(
                (DRBG_STATE*)rand,
                &HierarchyGetPrimarySeed(in->parentHandle)->b,
                PRIMARY_OBJECT_CREATION,
                (MSSIM2B*)PublicMarshalAndComputeName(publicArea, &name),
                &in->inSensitive.sensitive.data.b);
            if(result != MSSIM_RC_SUCCESS)
                return result;
        }
        else
        {
            // This is an ordinary object so use the normal random number generator
            rand = NULL;
        }
    }
    // Internal data update
    // Create the object
    result = CryptCreateObject(newObject, &in->inSensitive.sensitive, rand);
    if(result != MSSIM_RC_SUCCESS)
        return result;
    // if this is not a Primary key and not a derived key, then return the sensitive
    // area
    if(parent != NULL && !derivation)
        // Prepare output private data from sensitive
        SensitiveToPrivate(&newObject->sensitive,
                           &newObject->name,
                           parent,
                           newObject->publicArea.nameAlg,
                           &out->outPrivate);
    else
        out->outPrivate.t.size = 0;
    // Set the remaining return values
    out->outPublic.publicArea = newObject->publicArea;
    out->name                 = newObject->name;
    // Set the remaining attributes for a loaded object
    ObjectSetLoadedAttributes(newObject, in->parentHandle);

    return result;
}

#endif  // CC_CreateLoaded