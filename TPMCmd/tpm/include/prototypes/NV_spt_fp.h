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
 *  Created by TpmPrototypes; Version 3.0 July 18, 2017
 *  Date: Mar 28, 2019  Time: 08:25:18PM
 */

#ifndef _NV_SPT_FP_H_
#define _NV_SPT_FP_H_

//*** NvReadAccessChecks()
// Common routine for validating a read
// Used by MSSIM2_NV_Read, MSSIM2_NV_ReadLock and MSSIM2_PolicyNV
//  Return Type: MSSIM_RC
//      MSSIM_RC_NV_AUTHORIZATION     autHandle is not allowed to authorize read
//                                  of the index
//      MSSIM_RC_NV_LOCKED            Read locked
//      MSSIM_RC_NV_UNINITIALIZED     Try to read an uninitialized index
//
MSSIM_RC
NvReadAccessChecks(MSSIM_HANDLE authHandle,  // IN: the handle that provided the
                                           //     authorization
                   MSSIM_HANDLE nvHandle,   // IN: the handle of the NV index to be read
                   MSSIMA_NV    attributes  // IN: the attributes of 'nvHandle'
);

//*** NvWriteAccessChecks()
// Common routine for validating a write
// Used by MSSIM2_NV_Write, MSSIM2_NV_Increment, MSSIM2_SetBits, and MSSIM2_NV_WriteLock
//  Return Type: MSSIM_RC
//      MSSIM_RC_NV_AUTHORIZATION     Authorization fails
//      MSSIM_RC_NV_LOCKED            Write locked
//
MSSIM_RC
NvWriteAccessChecks(
    MSSIM_HANDLE authHandle,  // IN: the handle that provided the
                            //     authorization
    MSSIM_HANDLE nvHandle,    // IN: the handle of the NV index to be written
    MSSIMA_NV    attributes   // IN: the attributes of 'nvHandle'
);

//*** NvClearOrderly()
// This function is used to cause gp.orderlyState to be cleared to the
// non-orderly state.
MSSIM_RC
NvClearOrderly(void);

//*** NvIsPinPassIndex()
// Function to check to see if an NV index is a PIN Pass Index
//  Return Type: BOOL
//      TRUE(1)         is pin pass
//      FALSE(0)        is not pin pass
BOOL NvIsPinPassIndex(MSSIM_HANDLE index  // IN: Handle to check
);

#endif  // _NV_SPT_FP_H_
