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
/*(Auto-generated)
 *  Created by TpmStructures; Version 4.4 Mar 26, 2019
 *  Date: Mar 28, 2019  Time: 08:25:17PM
 */

#if CC_PolicyAuthorize  // Command must be enabled

#  ifndef _Policy_Authorize_FP_H_
#    define _Policy_Authorize_FP_H_

// Input structure definition
typedef struct
{
    MSSIMI_SH_POLICY   policySession;
    MSSIM2B_DIGEST     approvedPolicy;
    MSSIM2B_NONCE      policyRef;
    MSSIM2B_NAME       keySign;
    MSSIMT_TK_VERIFIED checkTicket;
} PolicyAuthorize_In;

// Response code modifiers
#    define RC_PolicyAuthorize_policySession  (MSSIM_RC_H + MSSIM_RC_1)
#    define RC_PolicyAuthorize_approvedPolicy (MSSIM_RC_P + MSSIM_RC_1)
#    define RC_PolicyAuthorize_policyRef      (MSSIM_RC_P + MSSIM_RC_2)
#    define RC_PolicyAuthorize_keySign        (MSSIM_RC_P + MSSIM_RC_3)
#    define RC_PolicyAuthorize_checkTicket    (MSSIM_RC_P + MSSIM_RC_4)

// Function prototype
MSSIM_RC
MSSIM2_PolicyAuthorize(PolicyAuthorize_In* in);

#  endif  // _Policy_Authorize_FP_H_
#endif    // CC_PolicyAuthorize
