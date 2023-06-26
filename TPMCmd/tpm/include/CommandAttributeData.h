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
 *  Date: Sep  7, 2019  Time: 04:51:22PM
 */

// This file should only be included by CommandCodeAttibutes.c
#ifdef _COMMAND_CODE_ATTRIBUTES_

#  include "CommandAttributes.h"

#  if COMPRESSED_LISTS
#    define PAD_LIST 0
#  else
#    define PAD_LIST 1
#  endif

// This is the command code attribute array for GetCapability.
// Both this array and s_commandAttributes provides command code attributes,
// but tuned for different purpose
const MSSIMA_CC s_ccAttr[] = {
#  if(PAD_LIST || CC_NV_UndefineSpaceSpecial)
    MSSIMA_CC_INITIALIZER(0x011F, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_EvictControl)
    MSSIMA_CC_INITIALIZER(0x0120, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_HierarchyControl)
    MSSIMA_CC_INITIALIZER(0x0121, 0, 1, 1, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_UndefineSpace)
    MSSIMA_CC_INITIALIZER(0x0122, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST)
    MSSIMA_CC_INITIALIZER(0x0123, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ChangeEPS)
    MSSIMA_CC_INITIALIZER(0x0124, 0, 1, 1, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ChangePPS)
    MSSIMA_CC_INITIALIZER(0x0125, 0, 1, 1, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Clear)
    MSSIMA_CC_INITIALIZER(0x0126, 0, 1, 1, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ClearControl)
    MSSIMA_CC_INITIALIZER(0x0127, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ClockSet)
    MSSIMA_CC_INITIALIZER(0x0128, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_HierarchyChangeAuth)
    MSSIMA_CC_INITIALIZER(0x0129, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_DefineSpace)
    MSSIMA_CC_INITIALIZER(0x012A, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_Allocate)
    MSSIMA_CC_INITIALIZER(0x012B, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_SetAuthPolicy)
    MSSIMA_CC_INITIALIZER(0x012C, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PP_Commands)
    MSSIMA_CC_INITIALIZER(0x012D, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_SetPrimaryPolicy)
    MSSIMA_CC_INITIALIZER(0x012E, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_FieldUpgradeStart)
    MSSIMA_CC_INITIALIZER(0x012F, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ClockRateAdjust)
    MSSIMA_CC_INITIALIZER(0x0130, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_CreatePrimary)
    MSSIMA_CC_INITIALIZER(0x0131, 0, 0, 0, 0, 1, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_GlobalWriteLock)
    MSSIMA_CC_INITIALIZER(0x0132, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_GetCommandAuditDigest)
    MSSIMA_CC_INITIALIZER(0x0133, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_Increment)
    MSSIMA_CC_INITIALIZER(0x0134, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_SetBits)
    MSSIMA_CC_INITIALIZER(0x0135, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_Extend)
    MSSIMA_CC_INITIALIZER(0x0136, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_Write)
    MSSIMA_CC_INITIALIZER(0x0137, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_WriteLock)
    MSSIMA_CC_INITIALIZER(0x0138, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_DictionaryAttackLockReset)
    MSSIMA_CC_INITIALIZER(0x0139, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_DictionaryAttackParameters)
    MSSIMA_CC_INITIALIZER(0x013A, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_ChangeAuth)
    MSSIMA_CC_INITIALIZER(0x013B, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_Event)
    MSSIMA_CC_INITIALIZER(0x013C, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_Reset)
    MSSIMA_CC_INITIALIZER(0x013D, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_SequenceComplete)
    MSSIMA_CC_INITIALIZER(0x013E, 0, 0, 0, 1, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_SetAlgorithmSet)
    MSSIMA_CC_INITIALIZER(0x013F, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_SetCommandCodeAuditStatus)
    MSSIMA_CC_INITIALIZER(0x0140, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_FieldUpgradeData)
    MSSIMA_CC_INITIALIZER(0x0141, 0, 1, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_IncrementalSelfTest)
    MSSIMA_CC_INITIALIZER(0x0142, 0, 1, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_SelfTest)
    MSSIMA_CC_INITIALIZER(0x0143, 0, 1, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Startup)
    MSSIMA_CC_INITIALIZER(0x0144, 0, 1, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Shutdown)
    MSSIMA_CC_INITIALIZER(0x0145, 0, 1, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_StirRandom)
    MSSIMA_CC_INITIALIZER(0x0146, 0, 1, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ActivateCredential)
    MSSIMA_CC_INITIALIZER(0x0147, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Certify)
    MSSIMA_CC_INITIALIZER(0x0148, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyNV)
    MSSIMA_CC_INITIALIZER(0x0149, 0, 0, 0, 0, 3, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_CertifyCreation)
    MSSIMA_CC_INITIALIZER(0x014A, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Duplicate)
    MSSIMA_CC_INITIALIZER(0x014B, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_GetTime)
    MSSIMA_CC_INITIALIZER(0x014C, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_GetSessionAuditDigest)
    MSSIMA_CC_INITIALIZER(0x014D, 0, 0, 0, 0, 3, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_Read)
    MSSIMA_CC_INITIALIZER(0x014E, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_ReadLock)
    MSSIMA_CC_INITIALIZER(0x014F, 0, 1, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ObjectChangeAuth)
    MSSIMA_CC_INITIALIZER(0x0150, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicySecret)
    MSSIMA_CC_INITIALIZER(0x0151, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Rewrap)
    MSSIMA_CC_INITIALIZER(0x0152, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Create)
    MSSIMA_CC_INITIALIZER(0x0153, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ECDH_ZGen)
    MSSIMA_CC_INITIALIZER(0x0154, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || (CC_HMAC || CC_MAC))
    MSSIMA_CC_INITIALIZER(0x0155, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Import)
    MSSIMA_CC_INITIALIZER(0x0156, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Load)
    MSSIMA_CC_INITIALIZER(0x0157, 0, 0, 0, 0, 1, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_Quote)
    MSSIMA_CC_INITIALIZER(0x0158, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_RSA_Decrypt)
    MSSIMA_CC_INITIALIZER(0x0159, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST)
    MSSIMA_CC_INITIALIZER(0x015A, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || (CC_HMAC_Start || CC_MAC_Start))
    MSSIMA_CC_INITIALIZER(0x015B, 0, 0, 0, 0, 1, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_SequenceUpdate)
    MSSIMA_CC_INITIALIZER(0x015C, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Sign)
    MSSIMA_CC_INITIALIZER(0x015D, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Unseal)
    MSSIMA_CC_INITIALIZER(0x015E, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST)
    MSSIMA_CC_INITIALIZER(0x015F, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicySigned)
    MSSIMA_CC_INITIALIZER(0x0160, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ContextLoad)
    MSSIMA_CC_INITIALIZER(0x0161, 0, 0, 0, 0, 0, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_ContextSave)
    MSSIMA_CC_INITIALIZER(0x0162, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ECDH_KeyGen)
    MSSIMA_CC_INITIALIZER(0x0163, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_EncryptDecrypt)
    MSSIMA_CC_INITIALIZER(0x0164, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_FlushContext)
    MSSIMA_CC_INITIALIZER(0x0165, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST)
    MSSIMA_CC_INITIALIZER(0x0166, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_LoadExternal)
    MSSIMA_CC_INITIALIZER(0x0167, 0, 0, 0, 0, 0, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_MakeCredential)
    MSSIMA_CC_INITIALIZER(0x0168, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_ReadPublic)
    MSSIMA_CC_INITIALIZER(0x0169, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyAuthorize)
    MSSIMA_CC_INITIALIZER(0x016A, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyAuthValue)
    MSSIMA_CC_INITIALIZER(0x016B, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyCommandCode)
    MSSIMA_CC_INITIALIZER(0x016C, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyCounterTimer)
    MSSIMA_CC_INITIALIZER(0x016D, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyCpHash)
    MSSIMA_CC_INITIALIZER(0x016E, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyLocality)
    MSSIMA_CC_INITIALIZER(0x016F, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyNameHash)
    MSSIMA_CC_INITIALIZER(0x0170, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyOR)
    MSSIMA_CC_INITIALIZER(0x0171, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyTicket)
    MSSIMA_CC_INITIALIZER(0x0172, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ReadPublic)
    MSSIMA_CC_INITIALIZER(0x0173, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_RSA_Encrypt)
    MSSIMA_CC_INITIALIZER(0x0174, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST)
    MSSIMA_CC_INITIALIZER(0x0175, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_StartAuthSession)
    MSSIMA_CC_INITIALIZER(0x0176, 0, 0, 0, 0, 2, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_VerifySignature)
    MSSIMA_CC_INITIALIZER(0x0177, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ECC_Parameters)
    MSSIMA_CC_INITIALIZER(0x0178, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_FirmwareRead)
    MSSIMA_CC_INITIALIZER(0x0179, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_GetCapability)
    MSSIMA_CC_INITIALIZER(0x017A, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_GetRandom)
    MSSIMA_CC_INITIALIZER(0x017B, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_GetTestResult)
    MSSIMA_CC_INITIALIZER(0x017C, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Hash)
    MSSIMA_CC_INITIALIZER(0x017D, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_Read)
    MSSIMA_CC_INITIALIZER(0x017E, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyPCR)
    MSSIMA_CC_INITIALIZER(0x017F, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyRestart)
    MSSIMA_CC_INITIALIZER(0x0180, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ReadClock)
    MSSIMA_CC_INITIALIZER(0x0181, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_Extend)
    MSSIMA_CC_INITIALIZER(0x0182, 0, 1, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PCR_SetAuthValue)
    MSSIMA_CC_INITIALIZER(0x0183, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_NV_Certify)
    MSSIMA_CC_INITIALIZER(0x0184, 0, 0, 0, 0, 3, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_EventSequenceComplete)
    MSSIMA_CC_INITIALIZER(0x0185, 0, 1, 0, 1, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_HashSequenceStart)
    MSSIMA_CC_INITIALIZER(0x0186, 0, 0, 0, 0, 0, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyPhysicalPresence)
    MSSIMA_CC_INITIALIZER(0x0187, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyDuplicationSelect)
    MSSIMA_CC_INITIALIZER(0x0188, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyGetDigest)
    MSSIMA_CC_INITIALIZER(0x0189, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_TestParms)
    MSSIMA_CC_INITIALIZER(0x018A, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Commit)
    MSSIMA_CC_INITIALIZER(0x018B, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyPassword)
    MSSIMA_CC_INITIALIZER(0x018C, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ZGen_2Phase)
    MSSIMA_CC_INITIALIZER(0x018D, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_EC_Ephemeral)
    MSSIMA_CC_INITIALIZER(0x018E, 0, 0, 0, 0, 0, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyNvWritten)
    MSSIMA_CC_INITIALIZER(0x018F, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyTemplate)
    MSSIMA_CC_INITIALIZER(0x0190, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_CreateLoaded)
    MSSIMA_CC_INITIALIZER(0x0191, 0, 0, 0, 0, 1, 1, 0, 0),
#  endif
#  if(PAD_LIST || CC_PolicyAuthorizeNV)
    MSSIMA_CC_INITIALIZER(0x0192, 0, 0, 0, 0, 3, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_EncryptDecrypt2)
    MSSIMA_CC_INITIALIZER(0x0193, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_AC_GetCapability)
    MSSIMA_CC_INITIALIZER(0x0194, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_AC_Send)
    MSSIMA_CC_INITIALIZER(0x0195, 0, 0, 0, 0, 3, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Policy_AC_SendSelect)
    MSSIMA_CC_INITIALIZER(0x0196, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_CertifyX509)
    MSSIMA_CC_INITIALIZER(0x0197, 0, 0, 0, 0, 2, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ACT_SetTimeout)
    MSSIMA_CC_INITIALIZER(0x0198, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ECC_Encrypt)
    MSSIMA_CC_INITIALIZER(0x0199, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_ECC_Decrypt)
    MSSIMA_CC_INITIALIZER(0x019A, 0, 0, 0, 0, 1, 0, 0, 0),
#  endif
#  if(PAD_LIST || CC_Vendor_TCG_Test)
    MSSIMA_CC_INITIALIZER(0x0000, 0, 0, 0, 0, 0, 0, 1, 0),
#  endif
#  if(PAD_LIST || CC_VIRT_CreateSeed)
    MSSIMA_CC_INITIALIZER(0x0001, 0, 0, 0, 0, 1, 0, 1, 0),
#  endif
    MSSIMA_ZERO_INITIALIZER()};

// This is the command code attribute structure.
const COMMAND_ATTRIBUTES s_commandAttributes[] = {
#  if(PAD_LIST || CC_NV_UndefineSpaceSpecial)
    (COMMAND_ATTRIBUTES)(CC_NV_UndefineSpaceSpecial *  // 0x011F
                         (IS_IMPLEMENTED + HANDLE_1_ADMIN + HANDLE_2_USER
                          + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_EvictControl)
    (COMMAND_ATTRIBUTES)(CC_EvictControl*  // 0x0120
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_HierarchyControl)
    (COMMAND_ATTRIBUTES)(CC_HierarchyControl*  // 0x0121
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_NV_UndefineSpace)
    (COMMAND_ATTRIBUTES)(CC_NV_UndefineSpace*  // 0x0122
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST)
    (COMMAND_ATTRIBUTES)(0),  // 0x0123
#  endif
#  if(PAD_LIST || CC_ChangeEPS)
    (COMMAND_ATTRIBUTES)(CC_ChangeEPS*  // 0x0124
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_ChangePPS)
    (COMMAND_ATTRIBUTES)(CC_ChangePPS*  // 0x0125
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_Clear)
    (COMMAND_ATTRIBUTES)(CC_Clear*  // 0x0126
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_ClearControl)
    (COMMAND_ATTRIBUTES)(CC_ClearControl*  // 0x0127
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_ClockSet)
    (COMMAND_ATTRIBUTES)(CC_ClockSet*  // 0x0128
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_HierarchyChangeAuth)
    (COMMAND_ATTRIBUTES)(CC_HierarchyChangeAuth*  // 0x0129
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_NV_DefineSpace)
    (COMMAND_ATTRIBUTES)(CC_NV_DefineSpace*  // 0x012A
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_PCR_Allocate)
    (COMMAND_ATTRIBUTES)(CC_PCR_Allocate*  // 0x012B
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_PCR_SetAuthPolicy)
    (COMMAND_ATTRIBUTES)(CC_PCR_SetAuthPolicy*  // 0x012C
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_PP_Commands)
    (COMMAND_ATTRIBUTES)(CC_PP_Commands*  // 0x012D
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_REQUIRED)),
#  endif
#  if(PAD_LIST || CC_SetPrimaryPolicy)
    (COMMAND_ATTRIBUTES)(CC_SetPrimaryPolicy*  // 0x012E
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_FieldUpgradeStart)
    (COMMAND_ATTRIBUTES)(CC_FieldUpgradeStart*  // 0x012F
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_ADMIN + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_ClockRateAdjust)
    (COMMAND_ATTRIBUTES)(CC_ClockRateAdjust*  // 0x0130
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_CreatePrimary)
    (COMMAND_ATTRIBUTES)(CC_CreatePrimary*  // 0x0131
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + PP_COMMAND
                          + ENCRYPT_2 + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_NV_GlobalWriteLock)
    (COMMAND_ATTRIBUTES)(CC_NV_GlobalWriteLock*  // 0x0132
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_GetCommandAuditDigest)
    (COMMAND_ATTRIBUTES)(CC_GetCommandAuditDigest*  // 0x0133
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_NV_Increment)
    (COMMAND_ATTRIBUTES)(CC_NV_Increment*  // 0x0134
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_NV_SetBits)
    (COMMAND_ATTRIBUTES)(CC_NV_SetBits*  // 0x0135
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_NV_Extend)
    (COMMAND_ATTRIBUTES)(CC_NV_Extend*  // 0x0136
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_NV_Write)
    (COMMAND_ATTRIBUTES)(CC_NV_Write*  // 0x0137
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_NV_WriteLock)
    (COMMAND_ATTRIBUTES)(CC_NV_WriteLock*  // 0x0138
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_DictionaryAttackLockReset)
    (COMMAND_ATTRIBUTES)(CC_DictionaryAttackLockReset*  // 0x0139
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_DictionaryAttackParameters)
    (COMMAND_ATTRIBUTES)(CC_DictionaryAttackParameters*  // 0x013A
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_NV_ChangeAuth)
    (COMMAND_ATTRIBUTES)(CC_NV_ChangeAuth*  // 0x013B
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_ADMIN)),
#  endif
#  if(PAD_LIST || CC_PCR_Event)
    (COMMAND_ATTRIBUTES)(CC_PCR_Event*  // 0x013C
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_PCR_Reset)
    (COMMAND_ATTRIBUTES)(CC_PCR_Reset*  // 0x013D
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_SequenceComplete)
    (COMMAND_ATTRIBUTES)(CC_SequenceComplete*  // 0x013E
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_SetAlgorithmSet)
    (COMMAND_ATTRIBUTES)(CC_SetAlgorithmSet*  // 0x013F
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_SetCommandCodeAuditStatus)
    (COMMAND_ATTRIBUTES)(CC_SetCommandCodeAuditStatus*  // 0x0140
                         (IS_IMPLEMENTED + HANDLE_1_USER + PP_COMMAND)),
#  endif
#  if(PAD_LIST || CC_FieldUpgradeData)
    (COMMAND_ATTRIBUTES)(CC_FieldUpgradeData*  // 0x0141
                         (IS_IMPLEMENTED + DECRYPT_2)),
#  endif
#  if(PAD_LIST || CC_IncrementalSelfTest)
    (COMMAND_ATTRIBUTES)(CC_IncrementalSelfTest*  // 0x0142
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_SelfTest)
    (COMMAND_ATTRIBUTES)(CC_SelfTest*  // 0x0143
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_Startup)
    (COMMAND_ATTRIBUTES)(CC_Startup*  // 0x0144
                         (IS_IMPLEMENTED + NO_SESSIONS)),
#  endif
#  if(PAD_LIST || CC_Shutdown)
    (COMMAND_ATTRIBUTES)(CC_Shutdown*  // 0x0145
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_StirRandom)
    (COMMAND_ATTRIBUTES)(CC_StirRandom*  // 0x0146
                         (IS_IMPLEMENTED + DECRYPT_2)),
#  endif
#  if(PAD_LIST || CC_ActivateCredential)
    (COMMAND_ATTRIBUTES)(CC_ActivateCredential*  // 0x0147
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_ADMIN + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Certify)
    (COMMAND_ATTRIBUTES)(CC_Certify*  // 0x0148
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_ADMIN + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_PolicyNV)
    (COMMAND_ATTRIBUTES)(CC_PolicyNV*  // 0x0149
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_CertifyCreation)
    (COMMAND_ATTRIBUTES)(CC_CertifyCreation*  // 0x014A
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Duplicate)
    (COMMAND_ATTRIBUTES)(CC_Duplicate*  // 0x014B
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_DUP + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_GetTime)
    (COMMAND_ATTRIBUTES)(CC_GetTime*  // 0x014C
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_GetSessionAuditDigest)
    (COMMAND_ATTRIBUTES)(CC_GetSessionAuditDigest*  // 0x014D
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_NV_Read)
    (COMMAND_ATTRIBUTES)(CC_NV_Read*  // 0x014E
                         (IS_IMPLEMENTED + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_NV_ReadLock)
    (COMMAND_ATTRIBUTES)(CC_NV_ReadLock*  // 0x014F
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_ObjectChangeAuth)
    (COMMAND_ATTRIBUTES)(CC_ObjectChangeAuth*  // 0x0150
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_ADMIN + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_PolicySecret)
    (COMMAND_ATTRIBUTES)(CC_PolicySecret*  // 0x0151
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ALLOW_TRIAL
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Rewrap)
    (COMMAND_ATTRIBUTES)(CC_Rewrap*  // 0x0152
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Create)
    (COMMAND_ATTRIBUTES)(CC_Create*  // 0x0153
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_ECDH_ZGen)
    (COMMAND_ATTRIBUTES)(CC_ECDH_ZGen*  // 0x0154
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || (CC_HMAC || CC_MAC))
    (COMMAND_ATTRIBUTES)((CC_HMAC || CC_MAC) *  // 0x0155
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Import)
    (COMMAND_ATTRIBUTES)(CC_Import*  // 0x0156
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Load)
    (COMMAND_ATTRIBUTES)(CC_Load*  // 0x0157
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2
                          + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_Quote)
    (COMMAND_ATTRIBUTES)(CC_Quote*  // 0x0158
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_RSA_Decrypt)
    (COMMAND_ATTRIBUTES)(CC_RSA_Decrypt*  // 0x0159
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST)
    (COMMAND_ATTRIBUTES)(0),  // 0x015A
#  endif
#  if(PAD_LIST || (CC_HMAC_Start || CC_MAC_Start))
    (COMMAND_ATTRIBUTES)((CC_HMAC_Start || CC_MAC_Start) *  // 0x015B
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_SequenceUpdate)
    (COMMAND_ATTRIBUTES)(CC_SequenceUpdate*  // 0x015C
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_Sign)
    (COMMAND_ATTRIBUTES)(CC_Sign*  // 0x015D
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_Unseal)
    (COMMAND_ATTRIBUTES)(CC_Unseal*  // 0x015E
                         (IS_IMPLEMENTED + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST)
    (COMMAND_ATTRIBUTES)(0),  // 0x015F
#  endif
#  if(PAD_LIST || CC_PolicySigned)
    (COMMAND_ATTRIBUTES)(CC_PolicySigned*  // 0x0160
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_ContextLoad)
    (COMMAND_ATTRIBUTES)(CC_ContextLoad*  // 0x0161
                         (IS_IMPLEMENTED + NO_SESSIONS + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_ContextSave)
    (COMMAND_ATTRIBUTES)(CC_ContextSave*  // 0x0162
                         (IS_IMPLEMENTED + NO_SESSIONS)),
#  endif
#  if(PAD_LIST || CC_ECDH_KeyGen)
    (COMMAND_ATTRIBUTES)(CC_ECDH_KeyGen*  // 0x0163
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_EncryptDecrypt)
    (COMMAND_ATTRIBUTES)(CC_EncryptDecrypt*  // 0x0164
                         (IS_IMPLEMENTED + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_FlushContext)
    (COMMAND_ATTRIBUTES)(CC_FlushContext*  // 0x0165
                         (IS_IMPLEMENTED + NO_SESSIONS)),
#  endif
#  if(PAD_LIST)
    (COMMAND_ATTRIBUTES)(0),  // 0x0166
#  endif
#  if(PAD_LIST || CC_LoadExternal)
    (COMMAND_ATTRIBUTES)(CC_LoadExternal*  // 0x0167
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2 + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_MakeCredential)
    (COMMAND_ATTRIBUTES)(CC_MakeCredential*  // 0x0168
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_NV_ReadPublic)
    (COMMAND_ATTRIBUTES)(CC_NV_ReadPublic*  // 0x0169
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_PolicyAuthorize)
    (COMMAND_ATTRIBUTES)(CC_PolicyAuthorize*  // 0x016A
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyAuthValue)
    (COMMAND_ATTRIBUTES)(CC_PolicyAuthValue*  // 0x016B
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyCommandCode)
    (COMMAND_ATTRIBUTES)(CC_PolicyCommandCode*  // 0x016C
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyCounterTimer)
    (COMMAND_ATTRIBUTES)(CC_PolicyCounterTimer*  // 0x016D
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyCpHash)
    (COMMAND_ATTRIBUTES)(CC_PolicyCpHash*  // 0x016E
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyLocality)
    (COMMAND_ATTRIBUTES)(CC_PolicyLocality*  // 0x016F
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyNameHash)
    (COMMAND_ATTRIBUTES)(CC_PolicyNameHash*  // 0x0170
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyOR)
    (COMMAND_ATTRIBUTES)(CC_PolicyOR*  // 0x0171
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyTicket)
    (COMMAND_ATTRIBUTES)(CC_PolicyTicket*  // 0x0172
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_ReadPublic)
    (COMMAND_ATTRIBUTES)(CC_ReadPublic*  // 0x0173
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_RSA_Encrypt)
    (COMMAND_ATTRIBUTES)(CC_RSA_Encrypt*  // 0x0174
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2)),
#  endif
#  if(PAD_LIST)
    (COMMAND_ATTRIBUTES)(0),  // 0x0175
#  endif
#  if(PAD_LIST || CC_StartAuthSession)
    (COMMAND_ATTRIBUTES)(CC_StartAuthSession*  // 0x0176
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2 + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_VerifySignature)
    (COMMAND_ATTRIBUTES)(CC_VerifySignature*  // 0x0177
                         (IS_IMPLEMENTED + DECRYPT_2)),
#  endif
#  if(PAD_LIST || CC_ECC_Parameters)
    (COMMAND_ATTRIBUTES)(CC_ECC_Parameters*  // 0x0178
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_FirmwareRead)
    (COMMAND_ATTRIBUTES)(CC_FirmwareRead*  // 0x0179
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_GetCapability)
    (COMMAND_ATTRIBUTES)(CC_GetCapability*  // 0x017A
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_GetRandom)
    (COMMAND_ATTRIBUTES)(CC_GetRandom*  // 0x017B
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_GetTestResult)
    (COMMAND_ATTRIBUTES)(CC_GetTestResult*  // 0x017C
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Hash)
    (COMMAND_ATTRIBUTES)(CC_Hash*  // 0x017D
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_PCR_Read)
    (COMMAND_ATTRIBUTES)(CC_PCR_Read*  // 0x017E
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_PolicyPCR)
    (COMMAND_ATTRIBUTES)(CC_PolicyPCR*  // 0x017F
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyRestart)
    (COMMAND_ATTRIBUTES)(CC_PolicyRestart*  // 0x0180
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_ReadClock)
    (COMMAND_ATTRIBUTES)(CC_ReadClock*  // 0x0181
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_PCR_Extend)
    (COMMAND_ATTRIBUTES)(CC_PCR_Extend*  // 0x0182
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_PCR_SetAuthValue)
    (COMMAND_ATTRIBUTES)(CC_PCR_SetAuthValue*  // 0x0183
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_NV_Certify)
    (COMMAND_ATTRIBUTES)(CC_NV_Certify*  // 0x0184
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_EventSequenceComplete)
    (COMMAND_ATTRIBUTES)(CC_EventSequenceComplete*  // 0x0185
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER
                          + HANDLE_2_USER)),
#  endif
#  if(PAD_LIST || CC_HashSequenceStart)
    (COMMAND_ATTRIBUTES)(CC_HashSequenceStart*  // 0x0186
                         (IS_IMPLEMENTED + DECRYPT_2 + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_PolicyPhysicalPresence)
    (COMMAND_ATTRIBUTES)(CC_PolicyPhysicalPresence*  // 0x0187
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyDuplicationSelect)
    (COMMAND_ATTRIBUTES)(CC_PolicyDuplicationSelect*  // 0x0188
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyGetDigest)
    (COMMAND_ATTRIBUTES)(CC_PolicyGetDigest*  // 0x0189
                         (IS_IMPLEMENTED + ALLOW_TRIAL + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_TestParms)
    (COMMAND_ATTRIBUTES)(CC_TestParms*  // 0x018A
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_Commit)
    (COMMAND_ATTRIBUTES)(CC_Commit*  // 0x018B
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_PolicyPassword)
    (COMMAND_ATTRIBUTES)(CC_PolicyPassword*  // 0x018C
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_ZGen_2Phase)
    (COMMAND_ATTRIBUTES)(CC_ZGen_2Phase*  // 0x018D
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_EC_Ephemeral)
    (COMMAND_ATTRIBUTES)(CC_EC_Ephemeral*  // 0x018E
                         (IS_IMPLEMENTED + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_PolicyNvWritten)
    (COMMAND_ATTRIBUTES)(CC_PolicyNvWritten*  // 0x018F
                         (IS_IMPLEMENTED + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_PolicyTemplate)
    (COMMAND_ATTRIBUTES)(CC_PolicyTemplate*  // 0x0190
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_CreateLoaded)
    (COMMAND_ATTRIBUTES)(CC_CreateLoaded*  // 0x0191
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + PP_COMMAND
                          + ENCRYPT_2 + R_HANDLE)),
#  endif
#  if(PAD_LIST || CC_PolicyAuthorizeNV)
    (COMMAND_ATTRIBUTES)(CC_PolicyAuthorizeNV*  // 0x0192
                         (IS_IMPLEMENTED + HANDLE_1_USER + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_EncryptDecrypt2)
    (COMMAND_ATTRIBUTES)(CC_EncryptDecrypt2*  // 0x0193
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_AC_GetCapability)
    (COMMAND_ATTRIBUTES)(CC_AC_GetCapability*  // 0x0194
                         (IS_IMPLEMENTED)),
#  endif
#  if(PAD_LIST || CC_AC_Send)
    (COMMAND_ATTRIBUTES)(CC_AC_Send*  // 0x0195
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_DUP + HANDLE_2_USER)),
#  endif
#  if(PAD_LIST || CC_Policy_AC_SendSelect)
    (COMMAND_ATTRIBUTES)(CC_Policy_AC_SendSelect*  // 0x0196
                         (IS_IMPLEMENTED + DECRYPT_2 + ALLOW_TRIAL)),
#  endif
#  if(PAD_LIST || CC_CertifyX509)
    (COMMAND_ATTRIBUTES)(CC_CertifyX509*  // 0x0197
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_ADMIN + HANDLE_2_USER
                          + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_ACT_SetTimeout)
    (COMMAND_ATTRIBUTES)(CC_ACT_SetTimeout*  // 0x0198
                         (IS_IMPLEMENTED + HANDLE_1_USER)),
#  endif
#  if(PAD_LIST || CC_ECC_Encrypt)
    (COMMAND_ATTRIBUTES)(CC_ECC_Encrypt*  // 0x0199
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_ECC_Decrypt)
    (COMMAND_ATTRIBUTES)(CC_ECC_Decrypt*  // 0x019A
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_Vendor_TCG_Test)
    (COMMAND_ATTRIBUTES)(CC_Vendor_TCG_Test*  // 0x0000
                         (IS_IMPLEMENTED + DECRYPT_2 + ENCRYPT_2)),
#  endif
#  if(PAD_LIST || CC_VIRT_CreateSeed)
    (COMMAND_ATTRIBUTES)(CC_VIRT_CreateSeed*  // 0x0001
                         (IS_IMPLEMENTED + DECRYPT_2 + HANDLE_1_USER + ENCRYPT_2)),
#  endif
    0};

#endif  // _COMMAND_CODE_ATTRIBUTES_
