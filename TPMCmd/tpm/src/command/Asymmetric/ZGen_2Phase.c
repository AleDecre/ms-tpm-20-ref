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
#include "ZGen_2Phase_fp.h"

#if CC_ZGen_2Phase  // Conditional expansion of this file

// This command uses the MSSIM to recover one or two Z values in a two phase key
// exchange protocol
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES               key referenced by 'keyA' is restricted or
//                                      not a decrypt key
//      MSSIM_RC_ECC_POINT                'inQsB' or  'inQeB' is not on the curve of
//                                      the key reference by 'keyA'
//      MSSIM_RC_KEY                      key referenced by 'keyA' is not an ECC key
//      MSSIM_RC_SCHEME                   the scheme of the key referenced by 'keyA'
//                                      is not MSSIM_ALG_NULL, MSSIM_ALG_ECDH,
//                                      MSSIM_ALG_ECMQV or MSSIM_ALG_SM2
MSSIM_RC
MSSIM2_ZGen_2Phase(ZGen_2Phase_In*  in,  // IN: input parameter list
                 ZGen_2Phase_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC              result;
    OBJECT*             eccKey;
    MSSIM2B_ECC_PARAMETER r;
    MSSIM_ALG_ID          scheme;

    // Input Validation

    eccKey = HandleToObject(in->keyA);

    // keyA must be an ECC key
    if(eccKey->publicArea.type != MSSIM_ALG_ECC)
        return MSSIM_RCS_KEY + RC_ZGen_2Phase_keyA;

    // keyA must not be restricted and must be a decrypt key
    if(IS_ATTRIBUTE(eccKey->publicArea.objectAttributes, MSSIMA_OBJECT, restricted)
       || !IS_ATTRIBUTE(eccKey->publicArea.objectAttributes, MSSIMA_OBJECT, decrypt))
        return MSSIM_RCS_ATTRIBUTES + RC_ZGen_2Phase_keyA;

    // if the scheme of keyA is MSSIM_ALG_NULL, then use the input scheme; otherwise
    // the input scheme must be the same as the scheme of keyA
    scheme = eccKey->publicArea.parameters.asymDetail.scheme.scheme;
    if(scheme != MSSIM_ALG_NULL)
    {
        if(scheme != in->inScheme)
            return MSSIM_RCS_SCHEME + RC_ZGen_2Phase_inScheme;
    }
    else
        scheme = in->inScheme;
    if(scheme == MSSIM_ALG_NULL)
        return MSSIM_RCS_SCHEME + RC_ZGen_2Phase_inScheme;

    // Input points must be on the curve of keyA
    if(!CryptEccIsPointOnCurve(eccKey->publicArea.parameters.eccDetail.curveID,
                               &in->inQsB.point))
        return MSSIM_RCS_ECC_POINT + RC_ZGen_2Phase_inQsB;

    if(!CryptEccIsPointOnCurve(eccKey->publicArea.parameters.eccDetail.curveID,
                               &in->inQeB.point))
        return MSSIM_RCS_ECC_POINT + RC_ZGen_2Phase_inQeB;

    if(!CryptGenerateR(
           &r, &in->counter, eccKey->publicArea.parameters.eccDetail.curveID, NULL))
        return MSSIM_RCS_VALUE + RC_ZGen_2Phase_counter;

    // Command Output

    result =
        CryptEcc2PhaseKeyExchange(&out->outZ1.point,
                                  &out->outZ2.point,
                                  eccKey->publicArea.parameters.eccDetail.curveID,
                                  scheme,
                                  &eccKey->sensitive.sensitive.ecc,
                                  &r,
                                  &in->inQsB.point,
                                  &in->inQeB.point);
    if(result == MSSIM_RC_SCHEME)
        return MSSIM_RCS_SCHEME + RC_ZGen_2Phase_inScheme;

    if(result == MSSIM_RC_SUCCESS)
        CryptEndCommit(in->counter);

    return result;
}
#endif  // CC_ZGen_2Phase