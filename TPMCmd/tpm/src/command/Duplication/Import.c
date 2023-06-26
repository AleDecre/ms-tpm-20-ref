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
#include "Import_fp.h"

#if CC_Import  // Conditional expansion of this file

#  include "Object_spt_fp.h"

/*(See part 3 specification)
// This command allows an asymmetrically encrypted blob, containing a duplicated
// object to be re-encrypted using the group symmetric key associated with the
// parent.
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES       'FixedMSSIM' and 'fixedParent' of 'objectPublic' are not
//                              both CLEAR; or 'inSymSeed' is nonempty and
//                              'parentHandle' does not reference a decryption key; or
//                              'objectPublic' and 'parentHandle' have incompatible
//                              or inconsistent attributes; or
//                              encrytpedDuplication is SET in 'objectPublic' but the
//                              inner or outer wrapper is missing.
//                              Note that if the MSSIM provides parameter values, the
//                              parameter number will indicate 'symmetricKey' (missing
//                              inner wrapper) or 'inSymSeed' (missing outer wrapper)
//      MSSIM_RC_BINDING          'duplicate' and 'objectPublic' are not
//                              cryptographically bound
//      MSSIM_RC_ECC_POINT        'inSymSeed' is nonempty and ECC point in 'inSymSeed'
//                              is not on the curve
//      MSSIM_RC_HASH             'objectPublic' does not have a valid nameAlg
//      MSSIM_RC_INSUFFICIENT     'inSymSeed' is nonempty and failed to retrieve ECC
//                              point from the secret; or unmarshaling sensitive value
//                              from 'duplicate' failed the result of 'inSymSeed'
//                              decryption
//      MSSIM_RC_INTEGRITY        'duplicate' integrity is broken
//      MSSIM_RC_KDF              'objectPublic' representing decrypting keyed hash
//                              object specifies invalid KDF
//      MSSIM_RC_KEY              inconsistent parameters of 'objectPublic'; or
//                              'inSymSeed' is nonempty and 'parentHandle' does not
//                              reference a key of supported type; or
//                              invalid key size in 'objectPublic' representing an
//                              asymmetric key
//      MSSIM_RC_NO_RESULT        'inSymSeed' is nonempty and multiplication resulted in
//                              ECC point at infinity
//      MSSIM_RC_OBJECT_MEMORY    no available object slot
//      MSSIM_RC_SCHEME           inconsistent attributes 'decrypt', 'sign',
//                              'restricted' and key's scheme ID in 'objectPublic';
//                              or hash algorithm is inconsistent with the scheme ID
//                              for keyed hash object
//      MSSIM_RC_SIZE             'authPolicy' size does not match digest size of the
//                              name algorithm in 'objectPublic'; or
//                              'symmetricAlg' and 'encryptionKey' have different
//                              sizes; or
//                              'inSymSeed' is nonempty and it size is not
//                              consistent with the type of 'parentHandle'; or
//                              unmarshaling sensitive value from 'duplicate' failed
//      MSSIM_RC_SYMMETRIC        'objectPublic' is either a storage key with no
//                              symmetric algorithm or a non-storage key with
//                              symmetric algorithm different from MSSIM_ALG_NULL
//      MSSIM_RC_TYPE             unsupported type of 'objectPublic'; or
//                              'parentHandle' is not a storage key; or
//                              only the public portion of 'parentHandle' is loaded;
//                              or 'objectPublic' and 'duplicate' are of different
//                              types
//      MSSIM_RC_VALUE            nonempty 'inSymSeed' and its numeric value is
//                              greater than the modulus of the key referenced by
//                              'parentHandle' or 'inSymSeed' is larger than the
//                              size of the digest produced by the name algorithm of
//                              the symmetric key referenced by 'parentHandle'
MSSIM_RC
MSSIM2_Import(Import_In*  in,  // IN: input parameter list
            Import_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC         result = MSSIM_RC_SUCCESS;
    OBJECT*        parentObject;
    MSSIM2B_DATA     data;  // symmetric key
    MSSIMT_SENSITIVE sensitive;
    MSSIM2B_NAME     name;
    MSSIMA_OBJECT    attributes;
    UINT16         innerKeySize = 0;  // encrypt key size for inner
                                      // wrapper

    // Input Validation
    // to save typing
    attributes = in->objectPublic.publicArea.objectAttributes;
    // FixedMSSIM and fixedParent must be CLEAR
    if(IS_ATTRIBUTE(attributes, MSSIMA_OBJECT, fixedMSSIM)
       || IS_ATTRIBUTE(attributes, MSSIMA_OBJECT, fixedParent))
        return MSSIM_RCS_ATTRIBUTES + RC_Import_objectPublic;

    // Get parent pointer
    parentObject = HandleToObject(in->parentHandle);

    if(!ObjectIsParent(parentObject))
        return MSSIM_RCS_TYPE + RC_Import_parentHandle;

    if(in->symmetricAlg.algorithm != MSSIM_ALG_NULL)
    {
        // Get inner wrap key size
        innerKeySize = in->symmetricAlg.keyBits.sym;
        // Input symmetric key must match the size of algorithm.
        if(in->encryptionKey.t.size != (innerKeySize + 7) / 8)
            return MSSIM_RCS_SIZE + RC_Import_encryptionKey;
    }
    else
    {
        // If input symmetric algorithm is NULL, input symmetric key size must
        // be 0 as well
        if(in->encryptionKey.t.size != 0)
            return MSSIM_RCS_SIZE + RC_Import_encryptionKey;
        // If encryptedDuplication is SET, then the object must have an inner
        // wrapper
        if(IS_ATTRIBUTE(attributes, MSSIMA_OBJECT, encryptedDuplication))
            return MSSIM_RCS_ATTRIBUTES + RC_Import_encryptionKey;
    }
    // See if there is an outer wrapper
    if(in->inSymSeed.t.size != 0)
    {
        // in->inParentHandle is a parent, but in order to decrypt an outer wrapper,
        // it must be able to do key exchange and a symmetric key can't do that.
        if(parentObject->publicArea.type == MSSIM_ALG_SYMCIPHER)
            return MSSIM_RCS_TYPE + RC_Import_parentHandle;

        // Decrypt input secret data via asymmetric decryption. MSSIM_RC_ATTRIBUTES,
        // MSSIM_RC_ECC_POINT, MSSIM_RC_INSUFFICIENT, MSSIM_RC_KEY, MSSIM_RC_NO_RESULT,
        // MSSIM_RC_SIZE, MSSIM_RC_VALUE may be returned at this point
        result = CryptSecretDecrypt(
            parentObject, NULL, DUPLICATE_STRING, &in->inSymSeed, &data);
        pAssert(result != MSSIM_RC_BINDING);
        if(result != MSSIM_RC_SUCCESS)
            return RcSafeAddToResult(result, RC_Import_inSymSeed);
    }
    else
    {
        // If encrytpedDuplication is set, then the object must have an outer
        // wrapper
        if(IS_ATTRIBUTE(attributes, MSSIMA_OBJECT, encryptedDuplication))
            return MSSIM_RCS_ATTRIBUTES + RC_Import_inSymSeed;
        data.t.size = 0;
    }
    // Compute name of object
    PublicMarshalAndComputeName(&(in->objectPublic.publicArea), &name);
    if(name.t.size == 0)
        return MSSIM_RCS_HASH + RC_Import_objectPublic;

    // Retrieve sensitive from private.
    // MSSIM_RC_INSUFFICIENT, MSSIM_RC_INTEGRITY, MSSIM_RC_SIZE may be returned here.
    result = DuplicateToSensitive(&in->duplicate.b,
                                  &name.b,
                                  parentObject,
                                  in->objectPublic.publicArea.nameAlg,
                                  &data.b,
                                  &in->symmetricAlg,
                                  &in->encryptionKey.b,
                                  &sensitive);
    if(result != MSSIM_RC_SUCCESS)
        return RcSafeAddToResult(result, RC_Import_duplicate);

    // If the parent of this object has fixedMSSIM SET, then validate this
    // object as if it were being loaded so that validation can be skipped
    // when it is actually loaded.
    if(IS_ATTRIBUTE(parentObject->publicArea.objectAttributes, MSSIMA_OBJECT, fixedMSSIM))
    {
        result = ObjectLoad(NULL,
                            NULL,
                            &in->objectPublic.publicArea,
                            &sensitive,
                            RC_Import_objectPublic,
                            RC_Import_duplicate,
                            NULL);
    }
    // Command output
    if(result == MSSIM_RC_SUCCESS)
    {
        // Prepare output private data from sensitive
        SensitiveToPrivate(&sensitive,
                           &name,
                           parentObject,
                           in->objectPublic.publicArea.nameAlg,
                           &out->outPrivate);
    }
    return result;
}

#endif  // CC_Import