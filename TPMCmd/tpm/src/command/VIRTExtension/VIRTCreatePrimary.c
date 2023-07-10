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
#include "VIRT_CreatePrimary_fp.h"
#include "stdio.h"

#if CC_VIRT_CreatePrimary  // Conditional expansion of this file

/*(See part 3 specification)
// Creates a primary or temporary object from a primary seed.
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES       sensitiveDataOrigin is CLEAR when sensitive.data is an
//                              Empty Buffer 'fixedMSSIM', 'fixedParent', or
//                              'encryptedDuplication' attributes are inconsistent
//                              between themselves or with those of the parent object;
//                              inconsistent 'restricted', 'decrypt' and 'sign'
//                              attributes
//                              attempt to inject sensitive data for an asymmetric
//                              key;
//      MSSIM_RC_KDF              incorrect KDF specified for decrypting keyed hash
//                              object
//      MSSIM_RC_KEY              a provided symmetric key value is not allowed
//      MSSIM_RC_OBJECT_MEMORY    there is no free slot for the object
//      MSSIM_RC_SCHEME           inconsistent attributes 'decrypt', 'sign',
//                              'restricted' and key's scheme ID; or hash algorithm is
//                              inconsistent with the scheme ID for keyed hash object
//      MSSIM_RC_SIZE             size of public authorization policy or sensitive
//                              authorization value does not match digest size of the
//                              name algorithm; or sensitive data size for the keyed
//                              hash object is larger than is allowed for the scheme
//      MSSIM_RC_SYMMETRIC        a storage key with no symmetric algorithm specified;
//                              or non-storage key with symmetric algorithm different
//                              from MSSIM_ALG_NULL
//      MSSIM_RC_TYPE             unknown object type
MSSIM_RC
MSSIM2_VIRT_CreatePrimary(VIRTCreatePrimary_In*  in,  // IN: input parameter list
                   VIRTCreatePrimary_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC       result = MSSIM_RC_SUCCESS;
    MSSIMT_PUBLIC* publicArea;
    DRBG_STATE   rand;
    OBJECT*      newObject;
    MSSIM2B_NAME   name;

    // Input Validation
    // Will need a place to put the result
    newObject = FindEmptyObjectSlot(&out->objectHandle);
    if(newObject == NULL)
        return MSSIM_RC_OBJECT_MEMORY;
    // Get the address of the public area in the new object
    // (this is just to save typing)
    publicArea  = &newObject->publicArea;

    *publicArea = in->inPublic.publicArea;

    // Check attributes in input public area. CreateChecks() checks the things that
    // are unique to creation and then validates the attributes and values that are
    // common to create and load.
    result = CreateChecks(NULL, publicArea, in->inSensitive.sensitive.data.t.size);
    if(result != MSSIM_RC_SUCCESS)
        return RcSafeAddToResult(result, RC_VIRT_CreatePrimary_inPublic);
    // Validate the sensitive area values
    if(!AdjustAuthSize(&in->inSensitive.sensitive.userAuth, publicArea->nameAlg))
        return MSSIM_RCS_SIZE + RC_VIRT_CreatePrimary_inSensitive;
    // Command output
    // Compute the name using out->name as a scratch area (this is not the value
    // that ultimately will be returned, then instantiate the state that will be
    // used as a random number generator during the object creation.
    // The caller does not know the seed values so the actual name does not have
    // to be over the input, it can be over the unmarshaled structure.
    OBJECT *object = HandleToObject(in->primaryHandle);
    if(object == NULL){
        printf("test1");
        return MSSIM_RCS_HANDLE + RC_VIRT_CreatePrimary_primaryHandle;
    }
        
    result =
        DRBG_InstantiateSeeded(&rand,
                               &(object->sensitive.sensitive.bits.b),
                               PRIMARY_OBJECT_CREATION,
                               (MSSIM2B*)PublicMarshalAndComputeName(publicArea, &name),
                               &in->inSensitive.sensitive.data.b);
    if(result == MSSIM_RC_SUCCESS)
    {
                printf("SIIIIIIIIIIIIIIIIII");
        newObject->attributes.primary = SET;
        if(in->primaryHandle == MSSIM_RH_ENDORSEMENT)
            newObject->attributes.epsHierarchy = SET;

        // Create the primary object.
        result = CryptCreateObject(
            newObject, &in->inSensitive.sensitive, (RAND_STATE*)&rand);
    }
    if(result != MSSIM_RC_SUCCESS){
                printf("NOOOOOOOOOOOOOOOOOOOOOOO"); return result;
    }
       

    // Set the publicArea and name from the computed values
    out->outPublic.publicArea = newObject->publicArea;
    out->name                 = newObject->name;

    // Fill in creation data
    FillInCreationData(in->primaryHandle,
                       publicArea->nameAlg,
                       &in->creationPCR,
                       &in->outsideInfo,
                       &out->creationData,
                       &out->creationHash);

    // Compute creation ticket
    TicketComputeCreation(EntityGetHierarchy(in->primaryHandle),
                          &out->name,
                          &out->creationHash,
                          &out->creationTicket);

    // Set the remaining attributes for a loaded object
    ObjectSetLoadedAttributes(newObject, in->primaryHandle);
    return result;
}

#endif  // CC_VIRT_CreatePrimary