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
#include "MAC_Start_fp.h"

#if CC_MAC_Start  // Conditional expansion of this file

/*(See part 3 specification)
// Initialize a HMAC sequence and create a sequence object
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES       key referenced by 'handle' is not a signing key
//                              or is restricted
//      MSSIM_RC_OBJECT_MEMORY    no space to create an internal object
//      MSSIM_RC_KEY              key referenced by 'handle' is not an HMAC key
//      MSSIM_RC_VALUE            'hashAlg' is not compatible with the hash algorithm
//                              of the scheme of the object referenced by 'handle'
MSSIM_RC
MSSIM2_MAC_Start(MAC_Start_In*  in,  // IN: input parameter list
               MAC_Start_Out* out  // OUT: output parameter list
)
{
    OBJECT*      keyObject;
    MSSIMT_PUBLIC* publicArea;
    MSSIM_RC       result;

    // Input Validation

    // Get HMAC key object and public area pointers
    keyObject  = HandleToObject(in->handle);
    publicArea = &keyObject->publicArea;

    // Make sure that the key can do what is required
    result = CryptSelectMac(publicArea, &in->inScheme);
    // If the key is not able to do a MAC, indicate that the handle selects an
    // object that can't do a MAC
    if(result == MSSIM_RCS_TYPE)
        return MSSIM_RCS_TYPE + RC_MAC_Start_handle;
    // If there is another error type, indicate that the scheme and key are not
    // compatible
    if(result != MSSIM_RC_SUCCESS)
        return RcSafeAddToResult(result, RC_MAC_Start_inScheme);
    // Make sure that the key is not restricted
    if(IS_ATTRIBUTE(publicArea->objectAttributes, MSSIMA_OBJECT, restricted))
        return MSSIM_RCS_ATTRIBUTES + RC_MAC_Start_handle;
    // and that it is a signing key
    if(!IS_ATTRIBUTE(publicArea->objectAttributes, MSSIMA_OBJECT, sign))
        return MSSIM_RCS_KEY + RC_MAC_Start_handle;

    // Internal Data Update
    // Create a HMAC sequence object. A MSSIM_RC_OBJECT_MEMORY error may be
    // returned at this point
    return ObjectCreateHMACSequence(
        in->inScheme, keyObject, &in->auth, &out->sequenceHandle);
}

#endif  // CC_MAC_Start