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

#if CC_VIRT_StoreState  // Command must be enabled

#  ifndef _VIRT_StoreState_FP_H_
#    define _VIRT_StoreState_FP_H_

// Input structure definition
typedef struct
{
    MSSIMI_DH_OBJECT       keyHandle;
    MSSIM2B_MAX_BUFFER     inData;
    MSSIMI_YES_NO          decrypt;
    MSSIMI_ALG_CIPHER_MODE mode;
    MSSIM2B_IV             ivIn;
} VIRTStoreState_In;

// Output structure definition
typedef struct
{
    MSSIM2B_MAX_BUFFER outData;
    MSSIM2B_IV         ivOut;
} VIRTStoreState_Out;

// Response code modifiers
#    define RC_VIRT_StoreState_keyHandle (MSSIM_RC_H + MSSIM_RC_1)
#    define RC_VIRT_StoreState_inData    (MSSIM_RC_P + MSSIM_RC_1)
#    define RC_VIRT_StoreState_decrypt   (MSSIM_RC_P + MSSIM_RC_2)
#    define RC_VIRT_StoreState_mode      (MSSIM_RC_P + MSSIM_RC_3)
#    define RC_VIRT_StoreState_ivIn      (MSSIM_RC_P + MSSIM_RC_4)

// Function prototype
MSSIM_RC
MSSIM2_VIRT_StoreState(VIRTStoreState_In* in, VIRTStoreState_Out* out);

#  endif  // _VIRT_StoreState_FP_H_
#endif    // CC_VIRT_StoreState