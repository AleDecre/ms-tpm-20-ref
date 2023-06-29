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
 *  Created by TpmDispatch; Version 4.0 July 8,2017
 *  Date: Feb 28, 2020  Time: 03:04:48PM
 */

#if CC_Startup
case MSSIM_CC_Startup:
    break;
#endif  // CC_Startup
#if CC_Shutdown
case MSSIM_CC_Shutdown:
    break;
#endif  // CC_Shutdown
#if CC_SelfTest
case MSSIM_CC_SelfTest:
    break;
#endif  // CC_SelfTest
#if CC_IncrementalSelfTest
case MSSIM_CC_IncrementalSelfTest:
    break;
#endif  // CC_IncrementalSelfTest
#if CC_GetTestResult
case MSSIM_CC_GetTestResult:
    break;
#endif  // CC_GetTestResult
#if CC_StartAuthSession
case MSSIM_CC_StartAuthSession:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_ENTITY_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_StartAuthSession
#if CC_PolicyRestart
case MSSIM_CC_PolicyRestart:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyRestart
#if CC_Create
case MSSIM_CC_Create:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Create
#if CC_Load
case MSSIM_CC_Load:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Load
#if CC_LoadExternal
case MSSIM_CC_LoadExternal:
    break;
#endif  // CC_LoadExternal
#if CC_ReadPublic
case MSSIM_CC_ReadPublic:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ReadPublic
#if CC_ActivateCredential
case MSSIM_CC_ActivateCredential:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_ActivateCredential
#if CC_MakeCredential
case MSSIM_CC_MakeCredential:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_MakeCredential
#if CC_Unseal
case MSSIM_CC_Unseal:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Unseal
#if CC_ObjectChangeAuth
case MSSIM_CC_ObjectChangeAuth:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_ObjectChangeAuth
#if CC_CreateLoaded
case MSSIM_CC_CreateLoaded:
    *handleCount = 1;
    result       = MSSIMI_DH_PARENT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_CreateLoaded
#if CC_Duplicate
case MSSIM_CC_Duplicate:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_Duplicate
#if CC_Rewrap
case MSSIM_CC_Rewrap:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_Rewrap
#if CC_Import
case MSSIM_CC_Import:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Import
#if CC_RSA_Encrypt
case MSSIM_CC_RSA_Encrypt:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_RSA_Encrypt
#if CC_RSA_Decrypt
case MSSIM_CC_RSA_Decrypt:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_RSA_Decrypt
#if CC_ECDH_KeyGen
case MSSIM_CC_ECDH_KeyGen:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ECDH_KeyGen
#if CC_ECDH_ZGen
case MSSIM_CC_ECDH_ZGen:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ECDH_ZGen
#if CC_ECC_Parameters
case MSSIM_CC_ECC_Parameters:
    break;
#endif  // CC_ECC_Parameters
#if CC_ZGen_2Phase
case MSSIM_CC_ZGen_2Phase:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ZGen_2Phase
#if CC_ECC_Encrypt
case MSSIM_CC_ECC_Encrypt:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ECC_Encrypt
#if CC_ECC_Decrypt
case MSSIM_CC_ECC_Decrypt:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ECC_Decrypt
#if CC_EncryptDecrypt
case MSSIM_CC_EncryptDecrypt:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_EncryptDecrypt
#if CC_EncryptDecrypt2
case MSSIM_CC_EncryptDecrypt2:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_EncryptDecrypt2
#if CC_Hash
case MSSIM_CC_Hash:
    break;
#endif  // CC_Hash
#if CC_HMAC
case MSSIM_CC_HMAC:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_HMAC
#if CC_MAC
case MSSIM_CC_MAC:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_MAC
#if CC_GetRandom
case MSSIM_CC_GetRandom:
    break;
#endif  // CC_GetRandom
#if CC_StirRandom
case MSSIM_CC_StirRandom:
    break;
#endif  // CC_StirRandom
#if CC_HMAC_Start
case MSSIM_CC_HMAC_Start:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_HMAC_Start
#if CC_MAC_Start
case MSSIM_CC_MAC_Start:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_MAC_Start
#if CC_HashSequenceStart
case MSSIM_CC_HashSequenceStart:
    break;
#endif  // CC_HashSequenceStart
#if CC_SequenceUpdate
case MSSIM_CC_SequenceUpdate:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_SequenceUpdate
#if CC_SequenceComplete
case MSSIM_CC_SequenceComplete:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_SequenceComplete
#if CC_EventSequenceComplete
case MSSIM_CC_EventSequenceComplete:
    *handleCount = 2;
    result       = MSSIMI_DH_PCR_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_EventSequenceComplete
#if CC_Certify
case MSSIM_CC_Certify:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_Certify
#if CC_CertifyCreation
case MSSIM_CC_CertifyCreation:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_CertifyCreation
#if CC_Quote
case MSSIM_CC_Quote:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Quote
#if CC_GetSessionAuditDigest
case MSSIM_CC_GetSessionAuditDigest:
    *handleCount = 3;
    result       = MSSIMI_RH_ENDORSEMENT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    result =
        MSSIMI_SH_HMAC_Unmarshal(&handles[2], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_3;
    break;
#endif  // CC_GetSessionAuditDigest
#if CC_GetCommandAuditDigest
case MSSIM_CC_GetCommandAuditDigest:
    *handleCount = 2;
    result       = MSSIMI_RH_ENDORSEMENT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_GetCommandAuditDigest
#if CC_GetTime
case MSSIM_CC_GetTime:
    *handleCount = 2;
    result       = MSSIMI_RH_ENDORSEMENT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_GetTime
#if CC_CertifyX509
case MSSIM_CC_CertifyX509:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_CertifyX509
#if CC_Commit
case MSSIM_CC_Commit:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Commit
#if CC_EC_Ephemeral
case MSSIM_CC_EC_Ephemeral:
    break;
#endif  // CC_EC_Ephemeral
#if CC_VerifySignature
case MSSIM_CC_VerifySignature:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_VerifySignature
#if CC_Sign
case MSSIM_CC_Sign:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Sign
#if CC_SetCommandCodeAuditStatus
case MSSIM_CC_SetCommandCodeAuditStatus:
    *handleCount = 1;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_SetCommandCodeAuditStatus
#if CC_PCR_Extend
case MSSIM_CC_PCR_Extend:
    *handleCount = 1;
    result       = MSSIMI_DH_PCR_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PCR_Extend
#if CC_PCR_Event
case MSSIM_CC_PCR_Event:
    *handleCount = 1;
    result       = MSSIMI_DH_PCR_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PCR_Event
#if CC_PCR_Read
case MSSIM_CC_PCR_Read:
    break;
#endif  // CC_PCR_Read
#if CC_PCR_Allocate
case MSSIM_CC_PCR_Allocate:
    *handleCount = 1;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PCR_Allocate
#if CC_PCR_SetAuthPolicy
case MSSIM_CC_PCR_SetAuthPolicy:
    *handleCount = 1;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PCR_SetAuthPolicy
#if CC_PCR_SetAuthValue
case MSSIM_CC_PCR_SetAuthValue:
    *handleCount = 1;
    result       = MSSIMI_DH_PCR_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PCR_SetAuthValue
#if CC_PCR_Reset
case MSSIM_CC_PCR_Reset:
    *handleCount = 1;
    result       = MSSIMI_DH_PCR_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PCR_Reset
#if CC_PolicySigned
case MSSIM_CC_PolicySigned:
    *handleCount = 2;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_PolicySigned
#if CC_PolicySecret
case MSSIM_CC_PolicySecret:
    *handleCount = 2;
    result       = MSSIMI_DH_ENTITY_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_PolicySecret
#if CC_PolicyTicket
case MSSIM_CC_PolicyTicket:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyTicket
#if CC_PolicyOR
case MSSIM_CC_PolicyOR:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyOR
#if CC_PolicyPCR
case MSSIM_CC_PolicyPCR:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyPCR
#if CC_PolicyLocality
case MSSIM_CC_PolicyLocality:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyLocality
#if CC_PolicyNV
case MSSIM_CC_PolicyNV:
    *handleCount = 3;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[2], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_3;
    break;
#endif  // CC_PolicyNV
#if CC_PolicyCounterTimer
case MSSIM_CC_PolicyCounterTimer:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyCounterTimer
#if CC_PolicyCommandCode
case MSSIM_CC_PolicyCommandCode:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyCommandCode
#if CC_PolicyPhysicalPresence
case MSSIM_CC_PolicyPhysicalPresence:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyPhysicalPresence
#if CC_PolicyCpHash
case MSSIM_CC_PolicyCpHash:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyCpHash
#if CC_PolicyNameHash
case MSSIM_CC_PolicyNameHash:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyNameHash
#if CC_PolicyDuplicationSelect
case MSSIM_CC_PolicyDuplicationSelect:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyDuplicationSelect
#if CC_PolicyAuthorize
case MSSIM_CC_PolicyAuthorize:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyAuthorize
#if CC_PolicyAuthValue
case MSSIM_CC_PolicyAuthValue:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyAuthValue
#if CC_PolicyPassword
case MSSIM_CC_PolicyPassword:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyPassword
#if CC_PolicyGetDigest
case MSSIM_CC_PolicyGetDigest:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyGetDigest
#if CC_PolicyNvWritten
case MSSIM_CC_PolicyNvWritten:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyNvWritten
#if CC_PolicyTemplate
case MSSIM_CC_PolicyTemplate:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PolicyTemplate
#if CC_PolicyAuthorizeNV
case MSSIM_CC_PolicyAuthorizeNV:
    *handleCount = 3;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[2], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_3;
    break;
#endif  // CC_PolicyAuthorizeNV
#if CC_CreatePrimary
case MSSIM_CC_CreatePrimary:
    *handleCount = 1;
    result       = MSSIMI_RH_HIERARCHY_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_CreatePrimary
#if CC_HierarchyControl
case MSSIM_CC_HierarchyControl:
    *handleCount = 1;
    result       = MSSIMI_RH_HIERARCHY_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_HierarchyControl
#if CC_SetPrimaryPolicy
case MSSIM_CC_SetPrimaryPolicy:
    *handleCount = 1;
    result       = MSSIMI_RH_HIERARCHY_POLICY_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_SetPrimaryPolicy
#if CC_ChangePPS
case MSSIM_CC_ChangePPS:
    *handleCount = 1;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ChangePPS
#if CC_ChangeEPS
case MSSIM_CC_ChangeEPS:
    *handleCount = 1;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ChangeEPS
#if CC_Clear
case MSSIM_CC_Clear:
    *handleCount = 1;
    result =
        MSSIMI_RH_CLEAR_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Clear
#if CC_ClearControl
case MSSIM_CC_ClearControl:
    *handleCount = 1;
    result =
        MSSIMI_RH_CLEAR_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ClearControl
#if CC_HierarchyChangeAuth
case MSSIM_CC_HierarchyChangeAuth:
    *handleCount = 1;
    result       = MSSIMI_RH_HIERARCHY_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_HierarchyChangeAuth
#if CC_DictionaryAttackLockReset
case MSSIM_CC_DictionaryAttackLockReset:
    *handleCount = 1;
    result       = MSSIMI_RH_LOCKOUT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_DictionaryAttackLockReset
#if CC_DictionaryAttackParameters
case MSSIM_CC_DictionaryAttackParameters:
    *handleCount = 1;
    result       = MSSIMI_RH_LOCKOUT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_DictionaryAttackParameters
#if CC_PP_Commands
case MSSIM_CC_PP_Commands:
    *handleCount = 1;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_PP_Commands
#if CC_SetAlgorithmSet
case MSSIM_CC_SetAlgorithmSet:
    *handleCount = 1;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_SetAlgorithmSet
#if CC_FieldUpgradeStart
case MSSIM_CC_FieldUpgradeStart:
    *handleCount = 2;
    result       = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_FieldUpgradeStart
#if CC_FieldUpgradeData
case MSSIM_CC_FieldUpgradeData:
    break;
#endif  // CC_FieldUpgradeData
#if CC_FirmwareRead
case MSSIM_CC_FirmwareRead:
    break;
#endif  // CC_FirmwareRead
#if CC_ContextSave
case MSSIM_CC_ContextSave:
    *handleCount = 1;
    result       = MSSIMI_DH_CONTEXT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ContextSave
#if CC_ContextLoad
case MSSIM_CC_ContextLoad:
    break;
#endif  // CC_ContextLoad
#if CC_FlushContext
case MSSIM_CC_FlushContext:
    break;
#endif  // CC_FlushContext
#if CC_EvictControl
case MSSIM_CC_EvictControl:
    *handleCount = 2;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_EvictControl
#if CC_ReadClock
case MSSIM_CC_ReadClock:
    break;
#endif  // CC_ReadClock
#if CC_ClockSet
case MSSIM_CC_ClockSet:
    *handleCount = 1;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ClockSet
#if CC_ClockRateAdjust
case MSSIM_CC_ClockRateAdjust:
    *handleCount = 1;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ClockRateAdjust
#if CC_GetCapability
case MSSIM_CC_GetCapability:
    break;
#endif  // CC_GetCapability
#if CC_TestParms
case MSSIM_CC_TestParms:
    break;
#endif  // CC_TestParms
#if CC_NV_DefineSpace
case MSSIM_CC_NV_DefineSpace:
    *handleCount = 1;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_NV_DefineSpace
#if CC_NV_UndefineSpace
case MSSIM_CC_NV_UndefineSpace:
    *handleCount = 2;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_UndefineSpace
#if CC_NV_UndefineSpaceSpecial
case MSSIM_CC_NV_UndefineSpaceSpecial:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_PLATFORM_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_UndefineSpaceSpecial
#if CC_NV_ReadPublic
case MSSIM_CC_NV_ReadPublic:
    *handleCount = 1;
    result       = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_NV_ReadPublic
#if CC_NV_Write
case MSSIM_CC_NV_Write:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_Write
#if CC_NV_Increment
case MSSIM_CC_NV_Increment:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_Increment
#if CC_NV_Extend
case MSSIM_CC_NV_Extend:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_Extend
#if CC_NV_SetBits
case MSSIM_CC_NV_SetBits:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_SetBits
#if CC_NV_WriteLock
case MSSIM_CC_NV_WriteLock:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_WriteLock
#if CC_NV_GlobalWriteLock
case MSSIM_CC_NV_GlobalWriteLock:
    *handleCount = 1;
    result       = MSSIMI_RH_PROVISION_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_NV_GlobalWriteLock
#if CC_NV_Read
case MSSIM_CC_NV_Read:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_Read
#if CC_NV_ReadLock
case MSSIM_CC_NV_ReadLock:
    *handleCount = 2;
    result       = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    break;
#endif  // CC_NV_ReadLock
#if CC_NV_ChangeAuth
case MSSIM_CC_NV_ChangeAuth:
    *handleCount = 1;
    result       = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_NV_ChangeAuth
#if CC_NV_Certify
case MSSIM_CC_NV_Certify:
    *handleCount = 3;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, TRUE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        &handles[2], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_3;
    break;
#endif  // CC_NV_Certify
#if CC_AC_GetCapability
case MSSIM_CC_AC_GetCapability:
    *handleCount = 1;
    result =
        MSSIMI_RH_AC_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_AC_GetCapability
#if CC_AC_Send
case MSSIM_CC_AC_Send:
    *handleCount = 3;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    result = MSSIMI_RH_NV_AUTH_Unmarshal(
        &handles[1], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_2;
    result =
        MSSIMI_RH_AC_Unmarshal(&handles[2], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_3;
    break;
#endif  // CC_AC_Send
#if CC_Policy_AC_SendSelect
case MSSIM_CC_Policy_AC_SendSelect:
    *handleCount = 1;
    result =
        MSSIMI_SH_POLICY_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_Policy_AC_SendSelect
#if CC_ACT_SetTimeout
case MSSIM_CC_ACT_SetTimeout:
    *handleCount = 1;
    result =
        MSSIMI_RH_ACT_Unmarshal(&handles[0], handleBufferStart, bufferRemainingSize);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_ACT_SetTimeout
#if CC_Vendor_TCG_Test
case MSSIM_CC_Vendor_TCG_Test:
    break;
#endif  // CC_Vendor_TCG_Test
#if CC_VIRT_CreateSeed
case MSSIM_CC_VIRT_CreateSeed:
    *handleCount = 1;
    result       = MSSIMI_DH_OBJECT_Unmarshal(
        &handles[0], handleBufferStart, bufferRemainingSize, FALSE);
    if(MSSIM_RC_SUCCESS != result)
        return result + MSSIM_RC_H + MSSIM_RC_1;
    break;
#endif  // CC_VIRT_CreateSeed
#if CC_VIRT_LoadSeed
#endif  // CC_VIRT_LoadSeed
#if CC_VIRT_CreatePrimary
#endif  // CC_VIRT_CreatePrimary
#if CC_VIRT_StoreState
#endif  // CC_VIRT_StoreState
#if CC_VIRT_RestoreState
#endif  // CC_VIRT_RestoreState
