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
#include "VIRT_RestoreState_fp.h"
#include "EncryptDecrypt_fp.h"
#include "EncryptDecrypt_spt_fp.h"

#if CC_VIRT_RestoreState  // Conditional expansion of this file

/*(See part 3 specification)
// symmetric encryption or decryption using modified parameter list
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_KEY          is not a symmetric decryption key with both
//                          public and private portions loaded
//      MSSIM_RC_SIZE         'IvIn' size is incompatible with the block cipher mode;
//                          or 'inData' size is not an even multiple of the block
//                          size for CBC or ECB mode
//      MSSIM_RC_VALUE        'keyHandle' is restricted and the argument 'mode' does
//                          not match the key's mode
MSSIM_RC
MSSIM2_VIRT_RestoreState(VIRTRestoreState_In*  in,  // IN: input parameter list
                     VIRTRestoreState_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC result;
    // EncryptDecyrptShared() performs the operations as shown in
    // MSSIM2_EncrypDecrypt
    result = EncryptDecryptShared(in->keyHandle,
                                  in->decrypt,
                                  in->mode,
                                  &in->ivIn,
                                  &in->inData,
                                  (EncryptDecrypt_Out*)out);
    // Handle response code swizzle.
    switch(result)
    {
        case MSSIM_RCS_MODE + RC_EncryptDecrypt_mode:
            result = MSSIM_RCS_MODE + RC_VIRT_RestoreState_mode;
            break;
        case MSSIM_RCS_SIZE + RC_EncryptDecrypt_ivIn:
            result = MSSIM_RCS_SIZE + RC_VIRT_RestoreState_ivIn;
            break;
        case MSSIM_RCS_SIZE + RC_EncryptDecrypt_inData:
            result = MSSIM_RCS_SIZE + RC_VIRT_RestoreState_inData;
            break;
        default:
            break;
    }
    return result;
}

#endif  // CC_VIRT_RestoreState