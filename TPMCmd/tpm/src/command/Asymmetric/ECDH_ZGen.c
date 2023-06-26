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
#include "ECDH_ZGen_fp.h"

#if CC_ECDH_ZGen  // Conditional expansion of this file

/*(See part 3 specification)
// This command uses the MSSIM to recover the Z value from a public point
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES               key referenced by 'keyA' is restricted or
//                                      not a decrypt key
//      MSSIM_RC_KEY                      key referenced by 'keyA' is not an ECC key
//      MSSIM_RC_NO_RESULT                multiplying 'inPoint' resulted in a
//                                      point at infinity
//      MSSIM_RC_SCHEME                   the scheme of the key referenced by 'keyA'
//                                      is not MSSIM_ALG_NULL, MSSIM_ALG_ECDH,
MSSIM_RC
MSSIM2_ECDH_ZGen(ECDH_ZGen_In*  in,  // IN: input parameter list
               ECDH_ZGen_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC  result;
    OBJECT* eccKey;

    // Input Validation
    eccKey = HandleToObject(in->keyHandle);

    // Selected key must be a non-restricted, decrypt ECC key
    if(eccKey->publicArea.type != MSSIM_ALG_ECC)
        return MSSIM_RCS_KEY + RC_ECDH_ZGen_keyHandle;
    // Selected key needs to be unrestricted with the 'decrypt' attribute
    if(IS_ATTRIBUTE(eccKey->publicArea.objectAttributes, MSSIMA_OBJECT, restricted)
       || !IS_ATTRIBUTE(eccKey->publicArea.objectAttributes, MSSIMA_OBJECT, decrypt))
        return MSSIM_RCS_ATTRIBUTES + RC_ECDH_ZGen_keyHandle;
    // Make sure the scheme allows this use
    if(eccKey->publicArea.parameters.eccDetail.scheme.scheme != MSSIM_ALG_ECDH
       && eccKey->publicArea.parameters.eccDetail.scheme.scheme != MSSIM_ALG_NULL)
        return MSSIM_RCS_SCHEME + RC_ECDH_ZGen_keyHandle;
    // Command Output
    // Compute Z. MSSIM_RC_ECC_POINT or MSSIM_RC_NO_RESULT may be returned here.
    result = CryptEccPointMultiply(&out->outPoint.point,
                                   eccKey->publicArea.parameters.eccDetail.curveID,
                                   &in->inPoint.point,
                                   &eccKey->sensitive.sensitive.ecc,
                                   NULL,
                                   NULL);
    if(result != MSSIM_RC_SUCCESS)
        return RcSafeAddToResult(result, RC_ECDH_ZGen_inPoint);
    return result;
}

#endif  // CC_ECDH_ZGen