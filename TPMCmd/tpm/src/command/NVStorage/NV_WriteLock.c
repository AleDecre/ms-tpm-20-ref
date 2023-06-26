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
#include "NV_WriteLock_fp.h"

#if CC_NV_WriteLock  // Conditional expansion of this file

/*(See part 3 specification)
// Set write lock on a NV index
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES               neither MSSIMA_NV_WRITEDEFINE nor
//                                      MSSIMA_NV_WRITE_STCLEAR is SET in Index
//                                      referenced by 'nvIndex'
//      MSSIM_RC_NV_AUTHORIZATION         the authorization was valid but the
//                                      authorizing entity ('authHandle')
//                                      is not allowed to write to the Index
//                                      referenced by 'nvIndex'
//
MSSIM_RC
MSSIM2_NV_WriteLock(NV_WriteLock_In* in  // IN: input parameter list
)
{
    MSSIM_RC    result;
    NV_REF    locator;
    NV_INDEX* nvIndex      = NvGetIndexInfo(in->nvIndex, &locator);
    MSSIMA_NV   nvAttributes = nvIndex->publicArea.attributes;

    // Input Validation:

    // Common access checks, NvWriteAccessCheck() may return MSSIM_RC_NV_AUTHORIZATION
    // or MSSIM_RC_NV_LOCKED
    result = NvWriteAccessChecks(in->authHandle, in->nvIndex, nvAttributes);
    if(result != MSSIM_RC_SUCCESS)
    {
        if(result == MSSIM_RC_NV_AUTHORIZATION)
            return result;
        // If write access failed because the index is already locked, then it is
        // no error.
        return MSSIM_RC_SUCCESS;
    }
    // if neither MSSIMA_NV_WRITEDEFINE nor MSSIMA_NV_WRITE_STCLEAR is set, the index
    // can not be write-locked
    if(!IS_ATTRIBUTE(nvAttributes, MSSIMA_NV, WRITEDEFINE)
       && !IS_ATTRIBUTE(nvAttributes, MSSIMA_NV, WRITE_STCLEAR))
        return MSSIM_RCS_ATTRIBUTES + RC_NV_WriteLock_nvIndex;
    // Internal Data Update
    // Set the WRITELOCK attribute.
    // Note: if MSSIMA_NV_WRITELOCKED were already SET, then the write access check
    // above would have failed and this code isn't executed.
    SET_ATTRIBUTE(nvAttributes, MSSIMA_NV, WRITELOCKED);

    // Write index info back
    return NvWriteIndexAttributes(nvIndex->publicArea.nvIndex, locator, nvAttributes);
}

#endif  // CC_NV_WriteLock