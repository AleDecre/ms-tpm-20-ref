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
 *  Date: Mar  6, 2020  Time: 01:50:09PM
 */

#ifndef _MSSIM_TYPES_H_
#define _MSSIM_TYPES_H_

#include "tss2/tss2_tpm2_types.h"
/* Definition of Types for Handles */
typedef UINT32 MSSIM2_HANDLE;

// Table 1:2 - Definition of MSSIM_ALG_ID Constants
typedef UINT16 MSSIM_ALG_ID;
#define TYPE_OF_MSSIM_ALG_ID       UINT16
#define ALG_ERROR_VALUE          0x0000
#define MSSIM_ALG_ERROR            (MSSIM_ALG_ID)(ALG_ERROR_VALUE)
#define ALG_RSA_VALUE            0x0001
#define MSSIM_ALG_RSA              (MSSIM_ALG_ID)(ALG_RSA_VALUE)
#define ALG_TDES_VALUE           0x0003
#define MSSIM_ALG_TDES             (MSSIM_ALG_ID)(ALG_TDES_VALUE)
#define ALG_SHA_VALUE            0x0004
#define MSSIM_ALG_SHA              (MSSIM_ALG_ID)(ALG_SHA_VALUE)
#define ALG_SHA1_VALUE           0x0004
#define MSSIM_ALG_SHA1             (MSSIM_ALG_ID)(ALG_SHA1_VALUE)
#define ALG_HMAC_VALUE           0x0005
#define MSSIM_ALG_HMAC             (MSSIM_ALG_ID)(ALG_HMAC_VALUE)
#define ALG_AES_VALUE            0x0006
#define MSSIM_ALG_AES              (MSSIM_ALG_ID)(ALG_AES_VALUE)
#define ALG_MGF1_VALUE           0x0007
#define MSSIM_ALG_MGF1             (MSSIM_ALG_ID)(ALG_MGF1_VALUE)
#define ALG_KEYEDHASH_VALUE      0x0008
#define MSSIM_ALG_KEYEDHASH        (MSSIM_ALG_ID)(ALG_KEYEDHASH_VALUE)
#define ALG_XOR_VALUE            0x000A
#define MSSIM_ALG_XOR              (MSSIM_ALG_ID)(ALG_XOR_VALUE)
#define ALG_SHA256_VALUE         0x000B
#define MSSIM_ALG_SHA256           (MSSIM_ALG_ID)(ALG_SHA256_VALUE)
#define ALG_SHA384_VALUE         0x000C
#define MSSIM_ALG_SHA384           (MSSIM_ALG_ID)(ALG_SHA384_VALUE)
#define ALG_SHA512_VALUE         0x000D
#define MSSIM_ALG_SHA512           (MSSIM_ALG_ID)(ALG_SHA512_VALUE)
#define ALG_NULL_VALUE           0x0010
#define MSSIM_ALG_NULL             (MSSIM_ALG_ID)(ALG_NULL_VALUE)
#define ALG_SM3_256_VALUE        0x0012
#define MSSIM_ALG_SM3_256          (MSSIM_ALG_ID)(ALG_SM3_256_VALUE)
#define ALG_SM4_VALUE            0x0013
#define MSSIM_ALG_SM4              (MSSIM_ALG_ID)(ALG_SM4_VALUE)
#define ALG_RSASSA_VALUE         0x0014
#define MSSIM_ALG_RSASSA           (MSSIM_ALG_ID)(ALG_RSASSA_VALUE)
#define ALG_RSAES_VALUE          0x0015
#define MSSIM_ALG_RSAES            (MSSIM_ALG_ID)(ALG_RSAES_VALUE)
#define ALG_RSAPSS_VALUE         0x0016
#define MSSIM_ALG_RSAPSS           (MSSIM_ALG_ID)(ALG_RSAPSS_VALUE)
#define ALG_OAEP_VALUE           0x0017
#define MSSIM_ALG_OAEP             (MSSIM_ALG_ID)(ALG_OAEP_VALUE)
#define ALG_ECDSA_VALUE          0x0018
#define MSSIM_ALG_ECDSA            (MSSIM_ALG_ID)(ALG_ECDSA_VALUE)
#define ALG_ECDH_VALUE           0x0019
#define MSSIM_ALG_ECDH             (MSSIM_ALG_ID)(ALG_ECDH_VALUE)
#define ALG_ECDAA_VALUE          0x001A
#define MSSIM_ALG_ECDAA            (MSSIM_ALG_ID)(ALG_ECDAA_VALUE)
#define ALG_SM2_VALUE            0x001B
#define MSSIM_ALG_SM2              (MSSIM_ALG_ID)(ALG_SM2_VALUE)
#define ALG_ECSCHNORR_VALUE      0x001C
#define MSSIM_ALG_ECSCHNORR        (MSSIM_ALG_ID)(ALG_ECSCHNORR_VALUE)
#define ALG_ECMQV_VALUE          0x001D
#define MSSIM_ALG_ECMQV            (MSSIM_ALG_ID)(ALG_ECMQV_VALUE)
#define ALG_KDF1_SP800_56A_VALUE 0x0020
#define MSSIM_ALG_KDF1_SP800_56A   (MSSIM_ALG_ID)(ALG_KDF1_SP800_56A_VALUE)
#define ALG_KDF2_VALUE           0x0021
#define MSSIM_ALG_KDF2             (MSSIM_ALG_ID)(ALG_KDF2_VALUE)
#define ALG_KDF1_SP800_108_VALUE 0x0022
#define MSSIM_ALG_KDF1_SP800_108   (MSSIM_ALG_ID)(ALG_KDF1_SP800_108_VALUE)
#define ALG_ECC_VALUE            0x0023
#define MSSIM_ALG_ECC              (MSSIM_ALG_ID)(ALG_ECC_VALUE)
#define ALG_SYMCIPHER_VALUE      0x0025
#define MSSIM_ALG_SYMCIPHER        (MSSIM_ALG_ID)(ALG_SYMCIPHER_VALUE)
#define ALG_CAMELLIA_VALUE       0x0026
#define MSSIM_ALG_CAMELLIA         (MSSIM_ALG_ID)(ALG_CAMELLIA_VALUE)
#define ALG_SHA3_256_VALUE       0x0027
#define MSSIM_ALG_SHA3_256         (MSSIM_ALG_ID)(ALG_SHA3_256_VALUE)
#define ALG_SHA3_384_VALUE       0x0028
#define MSSIM_ALG_SHA3_384         (MSSIM_ALG_ID)(ALG_SHA3_384_VALUE)
#define ALG_SHA3_512_VALUE       0x0029
#define MSSIM_ALG_SHA3_512         (MSSIM_ALG_ID)(ALG_SHA3_512_VALUE)
#define ALG_CMAC_VALUE           0x003F
#define MSSIM_ALG_CMAC             (MSSIM_ALG_ID)(ALG_CMAC_VALUE)
#define ALG_CTR_VALUE            0x0040
#define MSSIM_ALG_CTR              (MSSIM_ALG_ID)(ALG_CTR_VALUE)
#define ALG_OFB_VALUE            0x0041
#define MSSIM_ALG_OFB              (MSSIM_ALG_ID)(ALG_OFB_VALUE)
#define ALG_CBC_VALUE            0x0042
#define MSSIM_ALG_CBC              (MSSIM_ALG_ID)(ALG_CBC_VALUE)
#define ALG_CFB_VALUE            0x0043
#define MSSIM_ALG_CFB              (MSSIM_ALG_ID)(ALG_CFB_VALUE)
#define ALG_ECB_VALUE            0x0044
#define MSSIM_ALG_ECB              (MSSIM_ALG_ID)(ALG_ECB_VALUE)
// Values derived from Table 1:2
#define ALG_FIRST_VALUE 0x0001
#define MSSIM_ALG_FIRST   (MSSIM_ALG_ID)(ALG_FIRST_VALUE)
#define ALG_LAST_VALUE  0x0044
#define MSSIM_ALG_LAST    (MSSIM_ALG_ID)(ALG_LAST_VALUE)

// Table 1:4 - Definition of MSSIM_ECC_CURVE Constants
typedef UINT16 MSSIM_ECC_CURVE;
#define TYPE_OF_MSSIM_ECC_CURVE UINT16
#define MSSIM_ECC_NONE          (MSSIM_ECC_CURVE)(0x0000)
#define MSSIM_ECC_NIST_P192     (MSSIM_ECC_CURVE)(0x0001)
#define MSSIM_ECC_NIST_P224     (MSSIM_ECC_CURVE)(0x0002)
#define MSSIM_ECC_NIST_P256     (MSSIM_ECC_CURVE)(0x0003)
#define MSSIM_ECC_NIST_P384     (MSSIM_ECC_CURVE)(0x0004)
#define MSSIM_ECC_NIST_P521     (MSSIM_ECC_CURVE)(0x0005)
#define MSSIM_ECC_BN_P256       (MSSIM_ECC_CURVE)(0x0010)
#define MSSIM_ECC_BN_P638       (MSSIM_ECC_CURVE)(0x0011)
#define MSSIM_ECC_SM2_P256      (MSSIM_ECC_CURVE)(0x0020)

// Table 2:12 - Definition of MSSIM_CC Constants
typedef UINT32 MSSIM_CC;
#define TYPE_OF_MSSIM_CC                    UINT32
#define MSSIM_CC_NV_UndefineSpaceSpecial    (MSSIM_CC)(0x0000011F)
#define MSSIM_CC_EvictControl               (MSSIM_CC)(0x00000120)
#define MSSIM_CC_HierarchyControl           (MSSIM_CC)(0x00000121)
#define MSSIM_CC_NV_UndefineSpace           (MSSIM_CC)(0x00000122)
#define MSSIM_CC_ChangeEPS                  (MSSIM_CC)(0x00000124)
#define MSSIM_CC_ChangePPS                  (MSSIM_CC)(0x00000125)
#define MSSIM_CC_Clear                      (MSSIM_CC)(0x00000126)
#define MSSIM_CC_ClearControl               (MSSIM_CC)(0x00000127)
#define MSSIM_CC_ClockSet                   (MSSIM_CC)(0x00000128)
#define MSSIM_CC_HierarchyChangeAuth        (MSSIM_CC)(0x00000129)
#define MSSIM_CC_NV_DefineSpace             (MSSIM_CC)(0x0000012A)
#define MSSIM_CC_PCR_Allocate               (MSSIM_CC)(0x0000012B)
#define MSSIM_CC_PCR_SetAuthPolicy          (MSSIM_CC)(0x0000012C)
#define MSSIM_CC_PP_Commands                (MSSIM_CC)(0x0000012D)
#define MSSIM_CC_SetPrimaryPolicy           (MSSIM_CC)(0x0000012E)
#define MSSIM_CC_FieldUpgradeStart          (MSSIM_CC)(0x0000012F)
#define MSSIM_CC_ClockRateAdjust            (MSSIM_CC)(0x00000130)
#define MSSIM_CC_CreatePrimary              (MSSIM_CC)(0x00000131)
#define MSSIM_CC_NV_GlobalWriteLock         (MSSIM_CC)(0x00000132)
#define MSSIM_CC_GetCommandAuditDigest      (MSSIM_CC)(0x00000133)
#define MSSIM_CC_NV_Increment               (MSSIM_CC)(0x00000134)
#define MSSIM_CC_NV_SetBits                 (MSSIM_CC)(0x00000135)
#define MSSIM_CC_NV_Extend                  (MSSIM_CC)(0x00000136)
#define MSSIM_CC_NV_Write                   (MSSIM_CC)(0x00000137)
#define MSSIM_CC_NV_WriteLock               (MSSIM_CC)(0x00000138)
#define MSSIM_CC_DictionaryAttackLockReset  (MSSIM_CC)(0x00000139)
#define MSSIM_CC_DictionaryAttackParameters (MSSIM_CC)(0x0000013A)
#define MSSIM_CC_NV_ChangeAuth              (MSSIM_CC)(0x0000013B)
#define MSSIM_CC_PCR_Event                  (MSSIM_CC)(0x0000013C)
#define MSSIM_CC_PCR_Reset                  (MSSIM_CC)(0x0000013D)
#define MSSIM_CC_SequenceComplete           (MSSIM_CC)(0x0000013E)
#define MSSIM_CC_SetAlgorithmSet            (MSSIM_CC)(0x0000013F)
#define MSSIM_CC_SetCommandCodeAuditStatus  (MSSIM_CC)(0x00000140)
#define MSSIM_CC_FieldUpgradeData           (MSSIM_CC)(0x00000141)
#define MSSIM_CC_IncrementalSelfTest        (MSSIM_CC)(0x00000142)
#define MSSIM_CC_SelfTest                   (MSSIM_CC)(0x00000143)
#define MSSIM_CC_Startup                    (MSSIM_CC)(0x00000144)
#define MSSIM_CC_Shutdown                   (MSSIM_CC)(0x00000145)
#define MSSIM_CC_StirRandom                 (MSSIM_CC)(0x00000146)
#define MSSIM_CC_ActivateCredential         (MSSIM_CC)(0x00000147)
#define MSSIM_CC_Certify                    (MSSIM_CC)(0x00000148)
#define MSSIM_CC_PolicyNV                   (MSSIM_CC)(0x00000149)
#define MSSIM_CC_CertifyCreation            (MSSIM_CC)(0x0000014A)
#define MSSIM_CC_Duplicate                  (MSSIM_CC)(0x0000014B)
#define MSSIM_CC_GetTime                    (MSSIM_CC)(0x0000014C)
#define MSSIM_CC_GetSessionAuditDigest      (MSSIM_CC)(0x0000014D)
#define MSSIM_CC_NV_Read                    (MSSIM_CC)(0x0000014E)
#define MSSIM_CC_NV_ReadLock                (MSSIM_CC)(0x0000014F)
#define MSSIM_CC_ObjectChangeAuth           (MSSIM_CC)(0x00000150)
#define MSSIM_CC_PolicySecret               (MSSIM_CC)(0x00000151)
#define MSSIM_CC_Rewrap                     (MSSIM_CC)(0x00000152)
#define MSSIM_CC_Create                     (MSSIM_CC)(0x00000153)
#define MSSIM_CC_ECDH_ZGen                  (MSSIM_CC)(0x00000154)
#define MSSIM_CC_HMAC                       (MSSIM_CC)(0x00000155)
#define MSSIM_CC_MAC                        (MSSIM_CC)(0x00000155)
#define MSSIM_CC_Import                     (MSSIM_CC)(0x00000156)
#define MSSIM_CC_Load                       (MSSIM_CC)(0x00000157)
#define MSSIM_CC_Quote                      (MSSIM_CC)(0x00000158)
#define MSSIM_CC_RSA_Decrypt                (MSSIM_CC)(0x00000159)
#define MSSIM_CC_HMAC_Start                 (MSSIM_CC)(0x0000015B)
#define MSSIM_CC_MAC_Start                  (MSSIM_CC)(0x0000015B)
#define MSSIM_CC_SequenceUpdate             (MSSIM_CC)(0x0000015C)
#define MSSIM_CC_Sign                       (MSSIM_CC)(0x0000015D)
#define MSSIM_CC_Unseal                     (MSSIM_CC)(0x0000015E)
#define MSSIM_CC_PolicySigned               (MSSIM_CC)(0x00000160)
#define MSSIM_CC_ContextLoad                (MSSIM_CC)(0x00000161)
#define MSSIM_CC_ContextSave                (MSSIM_CC)(0x00000162)
#define MSSIM_CC_ECDH_KeyGen                (MSSIM_CC)(0x00000163)
#define MSSIM_CC_EncryptDecrypt             (MSSIM_CC)(0x00000164)
#define MSSIM_CC_FlushContext               (MSSIM_CC)(0x00000165)
#define MSSIM_CC_LoadExternal               (MSSIM_CC)(0x00000167)
#define MSSIM_CC_MakeCredential             (MSSIM_CC)(0x00000168)
#define MSSIM_CC_NV_ReadPublic              (MSSIM_CC)(0x00000169)
#define MSSIM_CC_PolicyAuthorize            (MSSIM_CC)(0x0000016A)
#define MSSIM_CC_PolicyAuthValue            (MSSIM_CC)(0x0000016B)
#define MSSIM_CC_PolicyCommandCode          (MSSIM_CC)(0x0000016C)
#define MSSIM_CC_PolicyCounterTimer         (MSSIM_CC)(0x0000016D)
#define MSSIM_CC_PolicyCpHash               (MSSIM_CC)(0x0000016E)
#define MSSIM_CC_PolicyLocality             (MSSIM_CC)(0x0000016F)
#define MSSIM_CC_PolicyNameHash             (MSSIM_CC)(0x00000170)
#define MSSIM_CC_PolicyOR                   (MSSIM_CC)(0x00000171)
#define MSSIM_CC_PolicyTicket               (MSSIM_CC)(0x00000172)
#define MSSIM_CC_ReadPublic                 (MSSIM_CC)(0x00000173)
#define MSSIM_CC_RSA_Encrypt                (MSSIM_CC)(0x00000174)
#define MSSIM_CC_StartAuthSession           (MSSIM_CC)(0x00000176)
#define MSSIM_CC_VerifySignature            (MSSIM_CC)(0x00000177)
#define MSSIM_CC_ECC_Parameters             (MSSIM_CC)(0x00000178)
#define MSSIM_CC_FirmwareRead               (MSSIM_CC)(0x00000179)
#define MSSIM_CC_GetCapability              (MSSIM_CC)(0x0000017A)
#define MSSIM_CC_GetRandom                  (MSSIM_CC)(0x0000017B)
#define MSSIM_CC_GetTestResult              (MSSIM_CC)(0x0000017C)
#define MSSIM_CC_Hash                       (MSSIM_CC)(0x0000017D)
#define MSSIM_CC_PCR_Read                   (MSSIM_CC)(0x0000017E)
#define MSSIM_CC_PolicyPCR                  (MSSIM_CC)(0x0000017F)
#define MSSIM_CC_PolicyRestart              (MSSIM_CC)(0x00000180)
#define MSSIM_CC_ReadClock                  (MSSIM_CC)(0x00000181)
#define MSSIM_CC_PCR_Extend                 (MSSIM_CC)(0x00000182)
#define MSSIM_CC_PCR_SetAuthValue           (MSSIM_CC)(0x00000183)
#define MSSIM_CC_NV_Certify                 (MSSIM_CC)(0x00000184)
#define MSSIM_CC_EventSequenceComplete      (MSSIM_CC)(0x00000185)
#define MSSIM_CC_HashSequenceStart          (MSSIM_CC)(0x00000186)
#define MSSIM_CC_PolicyPhysicalPresence     (MSSIM_CC)(0x00000187)
#define MSSIM_CC_PolicyDuplicationSelect    (MSSIM_CC)(0x00000188)
#define MSSIM_CC_PolicyGetDigest            (MSSIM_CC)(0x00000189)
#define MSSIM_CC_TestParms                  (MSSIM_CC)(0x0000018A)
#define MSSIM_CC_Commit                     (MSSIM_CC)(0x0000018B)
#define MSSIM_CC_PolicyPassword             (MSSIM_CC)(0x0000018C)
#define MSSIM_CC_ZGen_2Phase                (MSSIM_CC)(0x0000018D)
#define MSSIM_CC_EC_Ephemeral               (MSSIM_CC)(0x0000018E)
#define MSSIM_CC_PolicyNvWritten            (MSSIM_CC)(0x0000018F)
#define MSSIM_CC_PolicyTemplate             (MSSIM_CC)(0x00000190)
#define MSSIM_CC_CreateLoaded               (MSSIM_CC)(0x00000191)
#define MSSIM_CC_PolicyAuthorizeNV          (MSSIM_CC)(0x00000192)
#define MSSIM_CC_EncryptDecrypt2            (MSSIM_CC)(0x00000193)
#define MSSIM_CC_AC_GetCapability           (MSSIM_CC)(0x00000194)
#define MSSIM_CC_AC_Send                    (MSSIM_CC)(0x00000195)
#define MSSIM_CC_Policy_AC_SendSelect       (MSSIM_CC)(0x00000196)
#define MSSIM_CC_CertifyX509                (MSSIM_CC)(0x00000197)
#define MSSIM_CC_ACT_SetTimeout             (MSSIM_CC)(0x00000198)
#define MSSIM_CC_ECC_Encrypt                (MSSIM_CC)(0x00000199)
#define MSSIM_CC_ECC_Decrypt                (MSSIM_CC)(0x0000019A)
#define CC_VEND                             0x20000000
#define MSSIM_CC_Vendor_TCG_Test            (MSSIM_CC)(0x20000000)
#define MSSIM_CC_VIRT_CreateSeed            (MSSIM_CC)(0x20000001)
#define MSSIM_CC_VIRT_LoadSeed              (MSSIM_CC)(0x20000002)
#define MSSIM_CC_VIRT_CreatePrimary         (MSSIM_CC)(0x20000003)
#define MSSIM_CC_VIRT_StoreState            (MSSIM_CC)(0x20000004)
#define MSSIM_CC_VIRT_RestoreState          (MSSIM_CC)(0x20000005)

// Table 2:5 - Definition of Types for Documentation Clarity
typedef UINT32 MSSIM_ALGORITHM_ID;
#define TYPE_OF_MSSIM_ALGORITHM_ID UINT32
typedef UINT32 MSSIM_MODIFIER_INDICATOR;
#define TYPE_OF_MSSIM_MODIFIER_INDICATOR UINT32
typedef UINT32 MSSIM_AUTHORIZATION_SIZE;
#define TYPE_OF_MSSIM_AUTHORIZATION_SIZE UINT32
typedef UINT32 MSSIM_PARAMETER_SIZE;
#define TYPE_OF_MSSIM_PARAMETER_SIZE UINT32
typedef UINT16 MSSIM_KEY_SIZE;
#define TYPE_OF_MSSIM_KEY_SIZE UINT16
typedef UINT16 MSSIM_KEY_BITS;
#define TYPE_OF_MSSIM_KEY_BITS UINT16

// Table 2:6 - Definition of MSSIM_SPEC Constants
typedef UINT32 MSSIM_SPEC;
#define TYPE_OF_MSSIM_SPEC     UINT32
#define SPEC_FAMILY          0x322E3000
#define MSSIM_SPEC_FAMILY      (MSSIM_SPEC)(SPEC_FAMILY)
#define SPEC_LEVEL           00
#define MSSIM_SPEC_LEVEL       (MSSIM_SPEC)(SPEC_LEVEL)
#define SPEC_VERSION         162
#define MSSIM_SPEC_VERSION     (MSSIM_SPEC)(SPEC_VERSION)
#define SPEC_YEAR            2020
#define MSSIM_SPEC_YEAR        (MSSIM_SPEC)(SPEC_YEAR)
#define SPEC_DAY_OF_YEAR     53
#define MSSIM_SPEC_DAY_OF_YEAR (MSSIM_SPEC)(SPEC_DAY_OF_YEAR)

// Table 2:7 - Definition of MSSIM_CONSTANTS32 Constants
typedef UINT32 MSSIM_CONSTANTS32;
#define TYPE_OF_MSSIM_CONSTANTS32 UINT32
#define MSSIM_GENERATED_VALUE     (MSSIM_CONSTANTS32)(0xFF544347)
#define MSSIM_MAX_DERIVATION_BITS (MSSIM_CONSTANTS32)(8192)

// Table 2:16 - Definition of MSSIM_RC Constants
typedef UINT32 MSSIM_RC;
#define TYPE_OF_MSSIM_RC           UINT32
#define MSSIM_RC_SUCCESS           (MSSIM_RC)(0x000)
#define MSSIM_RC_BAD_TAG           (MSSIM_RC)(0x01E)
#define RC_VER1                  (MSSIM_RC)(0x100)
#define MSSIM_RC_INITIALIZE        (MSSIM_RC)(RC_VER1 + 0x000)
#define MSSIM_RC_FAILURE           (MSSIM_RC)(RC_VER1 + 0x001)
#define MSSIM_RC_SEQUENCE          (MSSIM_RC)(RC_VER1 + 0x003)
#define MSSIM_RC_PRIVATE           (MSSIM_RC)(RC_VER1 + 0x00B)
#define MSSIM_RC_HMAC              (MSSIM_RC)(RC_VER1 + 0x019)
#define MSSIM_RC_DISABLED          (MSSIM_RC)(RC_VER1 + 0x020)
#define MSSIM_RC_EXCLUSIVE         (MSSIM_RC)(RC_VER1 + 0x021)
#define MSSIM_RC_AUTH_TYPE         (MSSIM_RC)(RC_VER1 + 0x024)
#define MSSIM_RC_AUTH_MISSING      (MSSIM_RC)(RC_VER1 + 0x025)
#define MSSIM_RC_POLICY            (MSSIM_RC)(RC_VER1 + 0x026)
#define MSSIM_RC_PCR               (MSSIM_RC)(RC_VER1 + 0x027)
#define MSSIM_RC_PCR_CHANGED       (MSSIM_RC)(RC_VER1 + 0x028)
#define MSSIM_RC_UPGRADE           (MSSIM_RC)(RC_VER1 + 0x02D)
#define MSSIM_RC_TOO_MANY_CONTEXTS (MSSIM_RC)(RC_VER1 + 0x02E)
#define MSSIM_RC_AUTH_UNAVAILABLE  (MSSIM_RC)(RC_VER1 + 0x02F)
#define MSSIM_RC_REBOOT            (MSSIM_RC)(RC_VER1 + 0x030)
#define MSSIM_RC_UNBALANCED        (MSSIM_RC)(RC_VER1 + 0x031)
#define MSSIM_RC_COMMAND_SIZE      (MSSIM_RC)(RC_VER1 + 0x042)
#define MSSIM_RC_COMMAND_CODE      (MSSIM_RC)(RC_VER1 + 0x043)
#define MSSIM_RC_AUTHSIZE          (MSSIM_RC)(RC_VER1 + 0x044)
#define MSSIM_RC_AUTH_CONTEXT      (MSSIM_RC)(RC_VER1 + 0x045)
#define MSSIM_RC_NV_RANGE          (MSSIM_RC)(RC_VER1 + 0x046)
#define MSSIM_RC_NV_SIZE           (MSSIM_RC)(RC_VER1 + 0x047)
#define MSSIM_RC_NV_LOCKED         (MSSIM_RC)(RC_VER1 + 0x048)
#define MSSIM_RC_NV_AUTHORIZATION  (MSSIM_RC)(RC_VER1 + 0x049)
#define MSSIM_RC_NV_UNINITIALIZED  (MSSIM_RC)(RC_VER1 + 0x04A)
#define MSSIM_RC_NV_SPACE          (MSSIM_RC)(RC_VER1 + 0x04B)
#define MSSIM_RC_NV_DEFINED        (MSSIM_RC)(RC_VER1 + 0x04C)
#define MSSIM_RC_BAD_CONTEXT       (MSSIM_RC)(RC_VER1 + 0x050)
#define MSSIM_RC_CPHASH            (MSSIM_RC)(RC_VER1 + 0x051)
#define MSSIM_RC_PARENT            (MSSIM_RC)(RC_VER1 + 0x052)
#define MSSIM_RC_NEEDS_TEST        (MSSIM_RC)(RC_VER1 + 0x053)
#define MSSIM_RC_NO_RESULT         (MSSIM_RC)(RC_VER1 + 0x054)
#define MSSIM_RC_SENSITIVE         (MSSIM_RC)(RC_VER1 + 0x055)
#define RC_MAX_FM0               (MSSIM_RC)(RC_VER1 + 0x07F)
#define RC_FMT1                  (MSSIM_RC)(0x080)
#define MSSIM_RC_ASYMMETRIC        (MSSIM_RC)(RC_FMT1 + 0x001)
#define MSSIM_RCS_ASYMMETRIC       (MSSIM_RC)(RC_FMT1 + 0x001)
#define MSSIM_RC_ATTRIBUTES        (MSSIM_RC)(RC_FMT1 + 0x002)
#define MSSIM_RCS_ATTRIBUTES       (MSSIM_RC)(RC_FMT1 + 0x002)
#define MSSIM_RC_HASH              (MSSIM_RC)(RC_FMT1 + 0x003)
#define MSSIM_RCS_HASH             (MSSIM_RC)(RC_FMT1 + 0x003)
#define MSSIM_RC_VALUE             (MSSIM_RC)(RC_FMT1 + 0x004)
#define MSSIM_RCS_VALUE            (MSSIM_RC)(RC_FMT1 + 0x004)
#define MSSIM_RC_HIERARCHY         (MSSIM_RC)(RC_FMT1 + 0x005)
#define MSSIM_RCS_HIERARCHY        (MSSIM_RC)(RC_FMT1 + 0x005)
#define MSSIM_RC_KEY_SIZE          (MSSIM_RC)(RC_FMT1 + 0x007)
#define MSSIM_RCS_KEY_SIZE         (MSSIM_RC)(RC_FMT1 + 0x007)
#define MSSIM_RC_MGF               (MSSIM_RC)(RC_FMT1 + 0x008)
#define MSSIM_RCS_MGF              (MSSIM_RC)(RC_FMT1 + 0x008)
#define MSSIM_RC_MODE              (MSSIM_RC)(RC_FMT1 + 0x009)
#define MSSIM_RCS_MODE             (MSSIM_RC)(RC_FMT1 + 0x009)
#define MSSIM_RC_TYPE              (MSSIM_RC)(RC_FMT1 + 0x00A)
#define MSSIM_RCS_TYPE             (MSSIM_RC)(RC_FMT1 + 0x00A)
#define MSSIM_RC_HANDLE            (MSSIM_RC)(RC_FMT1 + 0x00B)
#define MSSIM_RCS_HANDLE           (MSSIM_RC)(RC_FMT1 + 0x00B)
#define MSSIM_RC_KDF               (MSSIM_RC)(RC_FMT1 + 0x00C)
#define MSSIM_RCS_KDF              (MSSIM_RC)(RC_FMT1 + 0x00C)
#define MSSIM_RC_RANGE             (MSSIM_RC)(RC_FMT1 + 0x00D)
#define MSSIM_RCS_RANGE            (MSSIM_RC)(RC_FMT1 + 0x00D)
#define MSSIM_RC_AUTH_FAIL         (MSSIM_RC)(RC_FMT1 + 0x00E)
#define MSSIM_RCS_AUTH_FAIL        (MSSIM_RC)(RC_FMT1 + 0x00E)
#define MSSIM_RC_NONCE             (MSSIM_RC)(RC_FMT1 + 0x00F)
#define MSSIM_RCS_NONCE            (MSSIM_RC)(RC_FMT1 + 0x00F)
#define MSSIM_RC_PP                (MSSIM_RC)(RC_FMT1 + 0x010)
#define MSSIM_RCS_PP               (MSSIM_RC)(RC_FMT1 + 0x010)
#define MSSIM_RC_SCHEME            (MSSIM_RC)(RC_FMT1 + 0x012)
#define MSSIM_RCS_SCHEME           (MSSIM_RC)(RC_FMT1 + 0x012)
#define MSSIM_RC_SIZE              (MSSIM_RC)(RC_FMT1 + 0x015)
#define MSSIM_RCS_SIZE             (MSSIM_RC)(RC_FMT1 + 0x015)
#define MSSIM_RC_SYMMETRIC         (MSSIM_RC)(RC_FMT1 + 0x016)
#define MSSIM_RCS_SYMMETRIC        (MSSIM_RC)(RC_FMT1 + 0x016)
#define MSSIM_RC_TAG               (MSSIM_RC)(RC_FMT1 + 0x017)
#define MSSIM_RCS_TAG              (MSSIM_RC)(RC_FMT1 + 0x017)
#define MSSIM_RC_SELECTOR          (MSSIM_RC)(RC_FMT1 + 0x018)
#define MSSIM_RCS_SELECTOR         (MSSIM_RC)(RC_FMT1 + 0x018)
#define MSSIM_RC_INSUFFICIENT      (MSSIM_RC)(RC_FMT1 + 0x01A)
#define MSSIM_RCS_INSUFFICIENT     (MSSIM_RC)(RC_FMT1 + 0x01A)
#define MSSIM_RC_SIGNATURE         (MSSIM_RC)(RC_FMT1 + 0x01B)
#define MSSIM_RCS_SIGNATURE        (MSSIM_RC)(RC_FMT1 + 0x01B)
#define MSSIM_RC_KEY               (MSSIM_RC)(RC_FMT1 + 0x01C)
#define MSSIM_RCS_KEY              (MSSIM_RC)(RC_FMT1 + 0x01C)
#define MSSIM_RC_POLICY_FAIL       (MSSIM_RC)(RC_FMT1 + 0x01D)
#define MSSIM_RCS_POLICY_FAIL      (MSSIM_RC)(RC_FMT1 + 0x01D)
#define MSSIM_RC_INTEGRITY         (MSSIM_RC)(RC_FMT1 + 0x01F)
#define MSSIM_RCS_INTEGRITY        (MSSIM_RC)(RC_FMT1 + 0x01F)
#define MSSIM_RC_TICKET            (MSSIM_RC)(RC_FMT1 + 0x020)
#define MSSIM_RCS_TICKET           (MSSIM_RC)(RC_FMT1 + 0x020)
#define MSSIM_RC_RESERVED_BITS     (MSSIM_RC)(RC_FMT1 + 0x021)
#define MSSIM_RCS_RESERVED_BITS    (MSSIM_RC)(RC_FMT1 + 0x021)
#define MSSIM_RC_BAD_AUTH          (MSSIM_RC)(RC_FMT1 + 0x022)
#define MSSIM_RCS_BAD_AUTH         (MSSIM_RC)(RC_FMT1 + 0x022)
#define MSSIM_RC_EXPIRED           (MSSIM_RC)(RC_FMT1 + 0x023)
#define MSSIM_RCS_EXPIRED          (MSSIM_RC)(RC_FMT1 + 0x023)
#define MSSIM_RC_POLICY_CC         (MSSIM_RC)(RC_FMT1 + 0x024)
#define MSSIM_RCS_POLICY_CC        (MSSIM_RC)(RC_FMT1 + 0x024)
#define MSSIM_RC_BINDING           (MSSIM_RC)(RC_FMT1 + 0x025)
#define MSSIM_RCS_BINDING          (MSSIM_RC)(RC_FMT1 + 0x025)
#define MSSIM_RC_CURVE             (MSSIM_RC)(RC_FMT1 + 0x026)
#define MSSIM_RCS_CURVE            (MSSIM_RC)(RC_FMT1 + 0x026)
#define MSSIM_RC_ECC_POINT         (MSSIM_RC)(RC_FMT1 + 0x027)
#define MSSIM_RCS_ECC_POINT        (MSSIM_RC)(RC_FMT1 + 0x027)
#define RC_WARN                  (MSSIM_RC)(0x900)
#define MSSIM_RC_CONTEXT_GAP       (MSSIM_RC)(RC_WARN + 0x001)
#define MSSIM_RC_OBJECT_MEMORY     (MSSIM_RC)(RC_WARN + 0x002)
#define MSSIM_RC_SESSION_MEMORY    (MSSIM_RC)(RC_WARN + 0x003)
#define MSSIM_RC_MEMORY            (MSSIM_RC)(RC_WARN + 0x004)
#define MSSIM_RC_SESSION_HANDLES   (MSSIM_RC)(RC_WARN + 0x005)
#define MSSIM_RC_OBJECT_HANDLES    (MSSIM_RC)(RC_WARN + 0x006)
#define MSSIM_RC_LOCALITY          (MSSIM_RC)(RC_WARN + 0x007)
#define MSSIM_RC_YIELDED           (MSSIM_RC)(RC_WARN + 0x008)
#define MSSIM_RC_CANCELED          (MSSIM_RC)(RC_WARN + 0x009)
#define MSSIM_RC_TESTING           (MSSIM_RC)(RC_WARN + 0x00A)
#define MSSIM_RC_REFERENCE_H0      (MSSIM_RC)(RC_WARN + 0x010)
#define MSSIM_RC_REFERENCE_H1      (MSSIM_RC)(RC_WARN + 0x011)
#define MSSIM_RC_REFERENCE_H2      (MSSIM_RC)(RC_WARN + 0x012)
#define MSSIM_RC_REFERENCE_H3      (MSSIM_RC)(RC_WARN + 0x013)
#define MSSIM_RC_REFERENCE_H4      (MSSIM_RC)(RC_WARN + 0x014)
#define MSSIM_RC_REFERENCE_H5      (MSSIM_RC)(RC_WARN + 0x015)
#define MSSIM_RC_REFERENCE_H6      (MSSIM_RC)(RC_WARN + 0x016)
#define MSSIM_RC_REFERENCE_S0      (MSSIM_RC)(RC_WARN + 0x018)
#define MSSIM_RC_REFERENCE_S1      (MSSIM_RC)(RC_WARN + 0x019)
#define MSSIM_RC_REFERENCE_S2      (MSSIM_RC)(RC_WARN + 0x01A)
#define MSSIM_RC_REFERENCE_S3      (MSSIM_RC)(RC_WARN + 0x01B)
#define MSSIM_RC_REFERENCE_S4      (MSSIM_RC)(RC_WARN + 0x01C)
#define MSSIM_RC_REFERENCE_S5      (MSSIM_RC)(RC_WARN + 0x01D)
#define MSSIM_RC_REFERENCE_S6      (MSSIM_RC)(RC_WARN + 0x01E)
#define MSSIM_RC_NV_RATE           (MSSIM_RC)(RC_WARN + 0x020)
#define MSSIM_RC_LOCKOUT           (MSSIM_RC)(RC_WARN + 0x021)
#define MSSIM_RC_RETRY             (MSSIM_RC)(RC_WARN + 0x022)
#define MSSIM_RC_NV_UNAVAILABLE    (MSSIM_RC)(RC_WARN + 0x023)
#define MSSIM_RC_NOT_USED          (MSSIM_RC)(RC_WARN + 0x7F)
#define MSSIM_RC_H                 (MSSIM_RC)(0x000)
#define MSSIM_RC_P                 (MSSIM_RC)(0x040)
#define MSSIM_RC_S                 (MSSIM_RC)(0x800)
#define MSSIM_RC_1                 (MSSIM_RC)(0x100)
#define MSSIM_RC_2                 (MSSIM_RC)(0x200)
#define MSSIM_RC_3                 (MSSIM_RC)(0x300)
#define MSSIM_RC_4                 (MSSIM_RC)(0x400)
#define MSSIM_RC_5                 (MSSIM_RC)(0x500)
#define MSSIM_RC_6                 (MSSIM_RC)(0x600)
#define MSSIM_RC_7                 (MSSIM_RC)(0x700)
#define MSSIM_RC_8                 (MSSIM_RC)(0x800)
#define MSSIM_RC_9                 (MSSIM_RC)(0x900)
#define MSSIM_RC_A                 (MSSIM_RC)(0xA00)
#define MSSIM_RC_B                 (MSSIM_RC)(0xB00)
#define MSSIM_RC_C                 (MSSIM_RC)(0xC00)
#define MSSIM_RC_D                 (MSSIM_RC)(0xD00)
#define MSSIM_RC_E                 (MSSIM_RC)(0xE00)
#define MSSIM_RC_F                 (MSSIM_RC)(0xF00)
#define MSSIM_RC_N_MASK            (MSSIM_RC)(0xF00)

// Table 2:17 - Definition of MSSIM_CLOCK_ADJUST Constants
typedef INT8 MSSIM_CLOCK_ADJUST;
#define TYPE_OF_MSSIM_CLOCK_ADJUST UINT8
#define MSSIM_CLOCK_COARSE_SLOWER  (MSSIM_CLOCK_ADJUST)(-3)
#define MSSIM_CLOCK_MEDIUM_SLOWER  (MSSIM_CLOCK_ADJUST)(-2)
#define MSSIM_CLOCK_FINE_SLOWER    (MSSIM_CLOCK_ADJUST)(-1)
#define MSSIM_CLOCK_NO_CHANGE      (MSSIM_CLOCK_ADJUST)(0)
#define MSSIM_CLOCK_FINE_FASTER    (MSSIM_CLOCK_ADJUST)(1)
#define MSSIM_CLOCK_MEDIUM_FASTER  (MSSIM_CLOCK_ADJUST)(2)
#define MSSIM_CLOCK_COARSE_FASTER  (MSSIM_CLOCK_ADJUST)(3)

// Table 2:18 - Definition of MSSIM_EO Constants
typedef UINT16 MSSIM_EO;
#define TYPE_OF_MSSIM_EO     UINT16
#define MSSIM_EO_EQ          (MSSIM_EO)(0x0000)
#define MSSIM_EO_NEQ         (MSSIM_EO)(0x0001)
#define MSSIM_EO_SIGNED_GT   (MSSIM_EO)(0x0002)
#define MSSIM_EO_UNSIGNED_GT (MSSIM_EO)(0x0003)
#define MSSIM_EO_SIGNED_LT   (MSSIM_EO)(0x0004)
#define MSSIM_EO_UNSIGNED_LT (MSSIM_EO)(0x0005)
#define MSSIM_EO_SIGNED_GE   (MSSIM_EO)(0x0006)
#define MSSIM_EO_UNSIGNED_GE (MSSIM_EO)(0x0007)
#define MSSIM_EO_SIGNED_LE   (MSSIM_EO)(0x0008)
#define MSSIM_EO_UNSIGNED_LE (MSSIM_EO)(0x0009)
#define MSSIM_EO_BITSET      (MSSIM_EO)(0x000A)
#define MSSIM_EO_BITCLEAR    (MSSIM_EO)(0x000B)

// Table 2:19 - Definition of MSSIM_ST Constants
typedef UINT16 MSSIM_ST;
#define TYPE_OF_MSSIM_ST              UINT16
#define MSSIM_ST_RSP_COMMAND          (MSSIM_ST)(0x00C4)
#define MSSIM_ST_NULL                 (MSSIM_ST)(0x8000)
#define MSSIM_ST_NO_SESSIONS          (MSSIM_ST)(0x8001)
#define MSSIM_ST_SESSIONS             (MSSIM_ST)(0x8002)
#define MSSIM_ST_ATTEST_NV            (MSSIM_ST)(0x8014)
#define MSSIM_ST_ATTEST_COMMAND_AUDIT (MSSIM_ST)(0x8015)
#define MSSIM_ST_ATTEST_SESSION_AUDIT (MSSIM_ST)(0x8016)
#define MSSIM_ST_ATTEST_CERTIFY       (MSSIM_ST)(0x8017)
#define MSSIM_ST_ATTEST_QUOTE         (MSSIM_ST)(0x8018)
#define MSSIM_ST_ATTEST_TIME          (MSSIM_ST)(0x8019)
#define MSSIM_ST_ATTEST_CREATION      (MSSIM_ST)(0x801A)
#define MSSIM_ST_ATTEST_NV_DIGEST     (MSSIM_ST)(0x801C)
#define MSSIM_ST_CREATION             (MSSIM_ST)(0x8021)
#define MSSIM_ST_VERIFIED             (MSSIM_ST)(0x8022)
#define MSSIM_ST_AUTH_SECRET          (MSSIM_ST)(0x8023)
#define MSSIM_ST_HASHCHECK            (MSSIM_ST)(0x8024)
#define MSSIM_ST_AUTH_SIGNED          (MSSIM_ST)(0x8025)
#define MSSIM_ST_FU_MANIFEST          (MSSIM_ST)(0x8029)

// Table 2:20 - Definition of MSSIM_SU Constants
typedef UINT16 MSSIM_SU;
#define TYPE_OF_MSSIM_SU UINT16
#define MSSIM_SU_CLEAR   (MSSIM_SU)(0x0000)
#define MSSIM_SU_STATE   (MSSIM_SU)(0x0001)

// Table 2:21 - Definition of MSSIM_SE Constants
typedef UINT8 MSSIM_SE;
#define TYPE_OF_MSSIM_SE UINT8
#define MSSIM_SE_HMAC    (MSSIM_SE)(0x00)
#define MSSIM_SE_POLICY  (MSSIM_SE)(0x01)
#define MSSIM_SE_TRIAL   (MSSIM_SE)(0x03)

// Table 2:22 - Definition of MSSIM_CAP Constants
typedef UINT32 MSSIM_CAP;
#define TYPE_OF_MSSIM_CAP         UINT32
#define MSSIM_CAP_FIRST           (MSSIM_CAP)(0x00000000)
#define MSSIM_CAP_ALGS            (MSSIM_CAP)(0x00000000)
#define MSSIM_CAP_HANDLES         (MSSIM_CAP)(0x00000001)
#define MSSIM_CAP_COMMANDS        (MSSIM_CAP)(0x00000002)
#define MSSIM_CAP_PP_COMMANDS     (MSSIM_CAP)(0x00000003)
#define MSSIM_CAP_AUDIT_COMMANDS  (MSSIM_CAP)(0x00000004)
#define MSSIM_CAP_PCRS            (MSSIM_CAP)(0x00000005)
#define MSSIM_CAP_MSSIM_PROPERTIES  (MSSIM_CAP)(0x00000006)
#define MSSIM_CAP_PCR_PROPERTIES  (MSSIM_CAP)(0x00000007)
#define MSSIM_CAP_ECC_CURVES      (MSSIM_CAP)(0x00000008)
#define MSSIM_CAP_AUTH_POLICIES   (MSSIM_CAP)(0x00000009)
#define MSSIM_CAP_ACT             (MSSIM_CAP)(0x0000000A)
#define MSSIM_CAP_LAST            (MSSIM_CAP)(0x0000000A)
#define MSSIM_CAP_VENDOR_PROPERTY (MSSIM_CAP)(0x00000100)

// Table 2:23 - Definition of MSSIM_PT Constants
typedef UINT32 MSSIM_PT;
#define TYPE_OF_MSSIM_PT             UINT32
#define MSSIM_PT_NONE                (MSSIM_PT)(0x00000000)
#define PT_GROUP                   (MSSIM_PT)(0x00000100)
#define PT_FIXED                   (MSSIM_PT)(PT_GROUP * 1)
#define MSSIM_PT_FAMILY_INDICATOR    (MSSIM_PT)(PT_FIXED + 0)
#define MSSIM_PT_LEVEL               (MSSIM_PT)(PT_FIXED + 1)
#define MSSIM_PT_REVISION            (MSSIM_PT)(PT_FIXED + 2)
#define MSSIM_PT_DAY_OF_YEAR         (MSSIM_PT)(PT_FIXED + 3)
#define MSSIM_PT_YEAR                (MSSIM_PT)(PT_FIXED + 4)
#define MSSIM_PT_MANUFACTURER        (MSSIM_PT)(PT_FIXED + 5)
#define MSSIM_PT_VENDOR_STRING_1     (MSSIM_PT)(PT_FIXED + 6)
#define MSSIM_PT_VENDOR_STRING_2     (MSSIM_PT)(PT_FIXED + 7)
#define MSSIM_PT_VENDOR_STRING_3     (MSSIM_PT)(PT_FIXED + 8)
#define MSSIM_PT_VENDOR_STRING_4     (MSSIM_PT)(PT_FIXED + 9)
#define MSSIM_PT_VENDOR_MSSIM_TYPE     (MSSIM_PT)(PT_FIXED + 10)
#define MSSIM_PT_FIRMWARE_VERSION_1  (MSSIM_PT)(PT_FIXED + 11)
#define MSSIM_PT_FIRMWARE_VERSION_2  (MSSIM_PT)(PT_FIXED + 12)
#define MSSIM_PT_INPUT_BUFFER        (MSSIM_PT)(PT_FIXED + 13)
#define MSSIM_PT_HR_TRANSIENT_MIN    (MSSIM_PT)(PT_FIXED + 14)
#define MSSIM_PT_HR_PERSISTENT_MIN   (MSSIM_PT)(PT_FIXED + 15)
#define MSSIM_PT_HR_LOADED_MIN       (MSSIM_PT)(PT_FIXED + 16)
#define MSSIM_PT_ACTIVE_SESSIONS_MAX (MSSIM_PT)(PT_FIXED + 17)
#define MSSIM_PT_PCR_COUNT           (MSSIM_PT)(PT_FIXED + 18)
#define MSSIM_PT_PCR_SELECT_MIN      (MSSIM_PT)(PT_FIXED + 19)
#define MSSIM_PT_CONTEXT_GAP_MAX     (MSSIM_PT)(PT_FIXED + 20)
#define MSSIM_PT_NV_COUNTERS_MAX     (MSSIM_PT)(PT_FIXED + 22)
#define MSSIM_PT_NV_INDEX_MAX        (MSSIM_PT)(PT_FIXED + 23)
#define MSSIM_PT_MEMORY              (MSSIM_PT)(PT_FIXED + 24)
#define MSSIM_PT_CLOCK_UPDATE        (MSSIM_PT)(PT_FIXED + 25)
#define MSSIM_PT_CONTEXT_HASH        (MSSIM_PT)(PT_FIXED + 26)
#define MSSIM_PT_CONTEXT_SYM         (MSSIM_PT)(PT_FIXED + 27)
#define MSSIM_PT_CONTEXT_SYM_SIZE    (MSSIM_PT)(PT_FIXED + 28)
#define MSSIM_PT_ORDERLY_COUNT       (MSSIM_PT)(PT_FIXED + 29)
#define MSSIM_PT_MAX_COMMAND_SIZE    (MSSIM_PT)(PT_FIXED + 30)
#define MSSIM_PT_MAX_RESPONSE_SIZE   (MSSIM_PT)(PT_FIXED + 31)
#define MSSIM_PT_MAX_DIGEST          (MSSIM_PT)(PT_FIXED + 32)
#define MSSIM_PT_MAX_OBJECT_CONTEXT  (MSSIM_PT)(PT_FIXED + 33)
#define MSSIM_PT_MAX_SESSION_CONTEXT (MSSIM_PT)(PT_FIXED + 34)
#define MSSIM_PT_PS_FAMILY_INDICATOR (MSSIM_PT)(PT_FIXED + 35)
#define MSSIM_PT_PS_LEVEL            (MSSIM_PT)(PT_FIXED + 36)
#define MSSIM_PT_PS_REVISION         (MSSIM_PT)(PT_FIXED + 37)
#define MSSIM_PT_PS_DAY_OF_YEAR      (MSSIM_PT)(PT_FIXED + 38)
#define MSSIM_PT_PS_YEAR             (MSSIM_PT)(PT_FIXED + 39)
#define MSSIM_PT_SPLIT_MAX           (MSSIM_PT)(PT_FIXED + 40)
#define MSSIM_PT_TOTAL_COMMANDS      (MSSIM_PT)(PT_FIXED + 41)
#define MSSIM_PT_LIBRARY_COMMANDS    (MSSIM_PT)(PT_FIXED + 42)
#define MSSIM_PT_VENDOR_COMMANDS     (MSSIM_PT)(PT_FIXED + 43)
#define MSSIM_PT_NV_BUFFER_MAX       (MSSIM_PT)(PT_FIXED + 44)
#define MSSIM_PT_MODES               (MSSIM_PT)(PT_FIXED + 45)
#define MSSIM_PT_MAX_CAP_BUFFER      (MSSIM_PT)(PT_FIXED + 46)
#define PT_VAR                     (MSSIM_PT)(PT_GROUP * 2)
#define MSSIM_PT_PERMANENT           (MSSIM_PT)(PT_VAR + 0)
#define MSSIM_PT_STARTUP_CLEAR       (MSSIM_PT)(PT_VAR + 1)
#define MSSIM_PT_HR_NV_INDEX         (MSSIM_PT)(PT_VAR + 2)
#define MSSIM_PT_HR_LOADED           (MSSIM_PT)(PT_VAR + 3)
#define MSSIM_PT_HR_LOADED_AVAIL     (MSSIM_PT)(PT_VAR + 4)
#define MSSIM_PT_HR_ACTIVE           (MSSIM_PT)(PT_VAR + 5)
#define MSSIM_PT_HR_ACTIVE_AVAIL     (MSSIM_PT)(PT_VAR + 6)
#define MSSIM_PT_HR_TRANSIENT_AVAIL  (MSSIM_PT)(PT_VAR + 7)
#define MSSIM_PT_HR_PERSISTENT       (MSSIM_PT)(PT_VAR + 8)
#define MSSIM_PT_HR_PERSISTENT_AVAIL (MSSIM_PT)(PT_VAR + 9)
#define MSSIM_PT_NV_COUNTERS         (MSSIM_PT)(PT_VAR + 10)
#define MSSIM_PT_NV_COUNTERS_AVAIL   (MSSIM_PT)(PT_VAR + 11)
#define MSSIM_PT_ALGORITHM_SET       (MSSIM_PT)(PT_VAR + 12)
#define MSSIM_PT_LOADED_CURVES       (MSSIM_PT)(PT_VAR + 13)
#define MSSIM_PT_LOCKOUT_COUNTER     (MSSIM_PT)(PT_VAR + 14)
#define MSSIM_PT_MAX_AUTH_FAIL       (MSSIM_PT)(PT_VAR + 15)
#define MSSIM_PT_LOCKOUT_INTERVAL    (MSSIM_PT)(PT_VAR + 16)
#define MSSIM_PT_LOCKOUT_RECOVERY    (MSSIM_PT)(PT_VAR + 17)
#define MSSIM_PT_NV_WRITE_RECOVERY   (MSSIM_PT)(PT_VAR + 18)
#define MSSIM_PT_AUDIT_COUNTER_0     (MSSIM_PT)(PT_VAR + 19)
#define MSSIM_PT_AUDIT_COUNTER_1     (MSSIM_PT)(PT_VAR + 20)

// Table 2:24 - Definition of MSSIM_PT_PCR Constants
typedef UINT32 MSSIM_PT_PCR;
#define TYPE_OF_MSSIM_PT_PCR      UINT32
#define MSSIM_PT_PCR_FIRST        (MSSIM_PT_PCR)(0x00000000)
#define MSSIM_PT_PCR_SAVE         (MSSIM_PT_PCR)(0x00000000)
#define MSSIM_PT_PCR_EXTEND_L0    (MSSIM_PT_PCR)(0x00000001)
#define MSSIM_PT_PCR_RESET_L0     (MSSIM_PT_PCR)(0x00000002)
#define MSSIM_PT_PCR_EXTEND_L1    (MSSIM_PT_PCR)(0x00000003)
#define MSSIM_PT_PCR_RESET_L1     (MSSIM_PT_PCR)(0x00000004)
#define MSSIM_PT_PCR_EXTEND_L2    (MSSIM_PT_PCR)(0x00000005)
#define MSSIM_PT_PCR_RESET_L2     (MSSIM_PT_PCR)(0x00000006)
#define MSSIM_PT_PCR_EXTEND_L3    (MSSIM_PT_PCR)(0x00000007)
#define MSSIM_PT_PCR_RESET_L3     (MSSIM_PT_PCR)(0x00000008)
#define MSSIM_PT_PCR_EXTEND_L4    (MSSIM_PT_PCR)(0x00000009)
#define MSSIM_PT_PCR_RESET_L4     (MSSIM_PT_PCR)(0x0000000A)
#define MSSIM_PT_PCR_NO_INCREMENT (MSSIM_PT_PCR)(0x00000011)
#define MSSIM_PT_PCR_DRTM_RESET   (MSSIM_PT_PCR)(0x00000012)
#define MSSIM_PT_PCR_POLICY       (MSSIM_PT_PCR)(0x00000013)
#define MSSIM_PT_PCR_AUTH         (MSSIM_PT_PCR)(0x00000014)
#define MSSIM_PT_PCR_LAST         (MSSIM_PT_PCR)(0x00000014)

// Table 2:25 - Definition of MSSIM_PS Constants
typedef UINT32 MSSIM_PS;
#define TYPE_OF_MSSIM_PS        UINT32
#define MSSIM_PS_MAIN           (MSSIM_PS)(0x00000000)
#define MSSIM_PS_PC             (MSSIM_PS)(0x00000001)
#define MSSIM_PS_PDA            (MSSIM_PS)(0x00000002)
#define MSSIM_PS_CELL_PHONE     (MSSIM_PS)(0x00000003)
#define MSSIM_PS_SERVER         (MSSIM_PS)(0x00000004)
#define MSSIM_PS_PERIPHERAL     (MSSIM_PS)(0x00000005)
#define MSSIM_PS_TSS            (MSSIM_PS)(0x00000006)
#define MSSIM_PS_STORAGE        (MSSIM_PS)(0x00000007)
#define MSSIM_PS_AUTHENTICATION (MSSIM_PS)(0x00000008)
#define MSSIM_PS_EMBEDDED       (MSSIM_PS)(0x00000009)
#define MSSIM_PS_HARDCOPY       (MSSIM_PS)(0x0000000A)
#define MSSIM_PS_INFRASTRUCTURE (MSSIM_PS)(0x0000000B)
#define MSSIM_PS_VIRTUALIZATION (MSSIM_PS)(0x0000000C)
#define MSSIM_PS_TNC            (MSSIM_PS)(0x0000000D)
#define MSSIM_PS_MULTI_TENANT   (MSSIM_PS)(0x0000000E)
#define MSSIM_PS_TC             (MSSIM_PS)(0x0000000F)

// Table 2:26 - Definition of Types for Handles
typedef UINT32 MSSIM_HANDLE;
#define TYPE_OF_MSSIM_HANDLE UINT32

// Table 2:27 - Definition of MSSIM_HT Constants
typedef UINT8 MSSIM_HT;
#define TYPE_OF_MSSIM_HT        UINT8
#define MSSIM_HT_PCR            (MSSIM_HT)(0x00)
#define MSSIM_HT_NV_INDEX       (MSSIM_HT)(0x01)
#define MSSIM_HT_HMAC_SESSION   (MSSIM_HT)(0x02)
#define MSSIM_HT_LOADED_SESSION (MSSIM_HT)(0x02)
#define MSSIM_HT_POLICY_SESSION (MSSIM_HT)(0x03)
#define MSSIM_HT_SAVED_SESSION  (MSSIM_HT)(0x03)
#define MSSIM_HT_PERMANENT      (MSSIM_HT)(0x40)
#define MSSIM_HT_TRANSIENT      (MSSIM_HT)(0x80)
#define MSSIM_HT_PERSISTENT     (MSSIM_HT)(0x81)
#define MSSIM_HT_AC             (MSSIM_HT)(0x90)

// Table 2:28 - Definition of MSSIM_RH Constants
typedef MSSIM_HANDLE MSSIM_RH;
#define MSSIM_RH_FIRST       (MSSIM_RH)(0x40000000)
#define MSSIM_RH_SRK         (MSSIM_RH)(0x40000000)
#define MSSIM_RH_OWNER       (MSSIM_RH)(0x40000001)
#define MSSIM_RH_REVOKE      (MSSIM_RH)(0x40000002)
#define MSSIM_RH_TRANSPORT   (MSSIM_RH)(0x40000003)
#define MSSIM_RH_OPERATOR    (MSSIM_RH)(0x40000004)
#define MSSIM_RH_ADMIN       (MSSIM_RH)(0x40000005)
#define MSSIM_RH_EK          (MSSIM_RH)(0x40000006)
#define MSSIM_RH_NULL        (MSSIM_RH)(0x40000007)
#define MSSIM_RH_UNASSIGNED  (MSSIM_RH)(0x40000008)
#define MSSIM_RS_PW          (MSSIM_RH)(0x40000009)
#define MSSIM_RH_LOCKOUT     (MSSIM_RH)(0x4000000A)
#define MSSIM_RH_ENDORSEMENT (MSSIM_RH)(0x4000000B)
#define MSSIM_RH_PLATFORM    (MSSIM_RH)(0x4000000C)
#define MSSIM_RH_PLATFORM_NV (MSSIM_RH)(0x4000000D)
#define MSSIM_RH_AUTH_00     (MSSIM_RH)(0x40000010)
#define MSSIM_RH_AUTH_FF     (MSSIM_RH)(0x4000010F)
#define MSSIM_RH_ACT_0       (MSSIM_RH)(0x40000110)
#define MSSIM_RH_ACT_F       (MSSIM_RH)(0x4000011F)
#define MSSIM_RH_LAST        (MSSIM_RH)(0x4000011F)

// Table 2:29 - Definition of MSSIM_HC Constants
typedef MSSIM_HANDLE MSSIM_HC;
#define HR_HANDLE_MASK       (MSSIM_HC)(0x00FFFFFF)
#define HR_RANGE_MASK        (MSSIM_HC)(0xFF000000)
#define HR_SHIFT             (MSSIM_HC)(24)
#define HR_PCR               (MSSIM_HC)((MSSIM_HT_PCR << HR_SHIFT))
#define HR_HMAC_SESSION      (MSSIM_HC)((MSSIM_HT_HMAC_SESSION << HR_SHIFT))
#define HR_POLICY_SESSION    (MSSIM_HC)((MSSIM_HT_POLICY_SESSION << HR_SHIFT))
#define HR_TRANSIENT         (MSSIM_HC)((MSSIM_HT_TRANSIENT << HR_SHIFT))
#define HR_PERSISTENT        (MSSIM_HC)((MSSIM_HT_PERSISTENT << HR_SHIFT))
#define HR_NV_INDEX          (MSSIM_HC)((MSSIM_HT_NV_INDEX << HR_SHIFT))
#define HR_PERMANENT         (MSSIM_HC)((MSSIM_HT_PERMANENT << HR_SHIFT))
#define PCR_FIRST            (MSSIM_HC)((HR_PCR + 0))
#define PCR_LAST             (MSSIM_HC)((PCR_FIRST + IMPLEMENTATION_PCR - 1))
#define HMAC_SESSION_FIRST   (MSSIM_HC)((HR_HMAC_SESSION + 0))
#define HMAC_SESSION_LAST    (MSSIM_HC)((HMAC_SESSION_FIRST + MAX_ACTIVE_SESSIONS - 1))
#define LOADED_SESSION_FIRST (MSSIM_HC)(HMAC_SESSION_FIRST)
#define LOADED_SESSION_LAST  (MSSIM_HC)(HMAC_SESSION_LAST)
#define POLICY_SESSION_FIRST (MSSIM_HC)((HR_POLICY_SESSION + 0))
#define POLICY_SESSION_LAST  (MSSIM_HC)((POLICY_SESSION_FIRST + MAX_ACTIVE_SESSIONS - 1))
#define TRANSIENT_FIRST      (MSSIM_HC)((HR_TRANSIENT + 0))
#define ACTIVE_SESSION_FIRST (MSSIM_HC)(POLICY_SESSION_FIRST)
#define ACTIVE_SESSION_LAST  (MSSIM_HC)(POLICY_SESSION_LAST)
#define TRANSIENT_LAST       (MSSIM_HC)((TRANSIENT_FIRST + MAX_LOADED_OBJECTS - 1))
#define PERSISTENT_FIRST     (MSSIM_HC)((HR_PERSISTENT + 0))
#define PERSISTENT_LAST      (MSSIM_HC)((PERSISTENT_FIRST + 0x00FFFFFF))
#define PLATFORM_PERSISTENT  (MSSIM_HC)((PERSISTENT_FIRST + 0x00800000))
#define NV_INDEX_FIRST       (MSSIM_HC)((HR_NV_INDEX + 0))
#define NV_INDEX_LAST        (MSSIM_HC)((NV_INDEX_FIRST + 0x00FFFFFF))
#define PERMANENT_FIRST      (MSSIM_HC)(MSSIM_RH_FIRST)
#define PERMANENT_LAST       (MSSIM_HC)(MSSIM_RH_LAST)
#define HR_NV_AC             (MSSIM_HC)(((MSSIM_HT_NV_INDEX << HR_SHIFT) + 0xD00000))
#define NV_AC_FIRST          (MSSIM_HC)((HR_NV_AC + 0))
#define NV_AC_LAST           (MSSIM_HC)((HR_NV_AC + 0x0000FFFF))
#define HR_AC                (MSSIM_HC)((MSSIM_HT_AC << HR_SHIFT))
#define AC_FIRST             (MSSIM_HC)((HR_AC + 0))
#define AC_LAST              (MSSIM_HC)((HR_AC + 0x0000FFFF))

#define TYPE_OF_MSSIMA_ALGORITHM      UINT32
#define MSSIMA_ALGORITHM_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_ALGORITHM(a) (*((MSSIMA_ALGORITHM*)&(a)))
#define MSSIMA_ALGORITHM_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_ALGORITHM_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_ALGORITHM(i, a)  \
  {                                         \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);     \
    i        = UINT32_TO_MSSIMA_ALGORITHM(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_ALGORITHM
{  // Table 2:30
    unsigned asymmetric          : 1;
    unsigned symmetric           : 1;
    unsigned hash                : 1;
    unsigned object              : 1;
    unsigned Reserved_bits_at_4  : 4;
    unsigned signing             : 1;
    unsigned encrypting          : 1;
    unsigned method              : 1;
    unsigned Reserved_bits_at_11 : 21;
} MSSIMA_ALGORITHM; /* Bits */
// This is the initializer for a MSSIMA_ALGORITHM structure
#  define MSSIMA_ALGORITHM_INITIALIZER(asymmetric,                                   \
                                     symmetric,                                    \
                                     hash,                                         \
                                     object,                                       \
                                     bits_at_4,                                    \
                                     signing,                                      \
                                     encrypting,                                   \
                                     method,                                       \
                                     bits_at_11)                                   \
    {                                                                              \
      asymmetric, symmetric, hash, object, bits_at_4, signing, encrypting, method, \
          bits_at_11                                                               \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:30 MSSIMA_ALGORITHM using bit masking
typedef UINT32 MSSIMA_ALGORITHM;
#  define TYPE_OF_MSSIMA_ALGORITHM    UINT32
#  define MSSIMA_ALGORITHM_asymmetric ((MSSIMA_ALGORITHM)1 << 0)
#  define MSSIMA_ALGORITHM_symmetric  ((MSSIMA_ALGORITHM)1 << 1)
#  define MSSIMA_ALGORITHM_hash       ((MSSIMA_ALGORITHM)1 << 2)
#  define MSSIMA_ALGORITHM_object     ((MSSIMA_ALGORITHM)1 << 3)
#  define MSSIMA_ALGORITHM_signing    ((MSSIMA_ALGORITHM)1 << 8)
#  define MSSIMA_ALGORITHM_encrypting ((MSSIMA_ALGORITHM)1 << 9)
#  define MSSIMA_ALGORITHM_method     ((MSSIMA_ALGORITHM)1 << 10)
//  This is the initializer for a MSSIMA_ALGORITHM bit array.
#  define MSSIMA_ALGORITHM_INITIALIZER(asymmetric,                          \
                                     symmetric,                           \
                                     hash,                                \
                                     object,                              \
                                     bits_at_4,                           \
                                     signing,                             \
                                     encrypting,                          \
                                     method,                              \
                                     bits_at_11)                          \
    (MSSIMA_ALGORITHM)((asymmetric << 0) + (symmetric << 1) + (hash << 2)   \
                     + (object << 3) + (signing << 8) + (encrypting << 9) \
                     + (method << 10))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_OBJECT      UINT32
#define MSSIMA_OBJECT_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_OBJECT(a) (*((MSSIMA_OBJECT*)&(a)))
#define MSSIMA_OBJECT_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_OBJECT_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_OBJECT(i, a)  \
  {                                      \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);  \
    i        = UINT32_TO_MSSIMA_OBJECT(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_OBJECT
{  // Table 2:31
    unsigned pMSSIMCreate         : 1;
    unsigned fixedMSSIM           : 1;
    unsigned stClear              : 1;
    unsigned Reserved_bit_at_3    : 1;
    unsigned fixedParent          : 1;
    unsigned sensitiveDataOrigin  : 1;
    unsigned userWithAuth         : 1;
    unsigned adminWithPolicy      : 1;
    unsigned Reserved_bits_at_8   : 2;
    unsigned noDA                 : 1;
    unsigned encryptedDuplication : 1;
    unsigned Reserved_bits_at_12  : 4;
    unsigned restricted           : 1;
    unsigned decrypt              : 1;
    unsigned sign                 : 1;
    unsigned x509sign             : 1;
    unsigned Reserved_bits_at_20  : 12;
} MSSIMA_OBJECT; /* Bits */
// This is the initializer for a MSSIMA_OBJECT structure
#  define MSSIMA_OBJECT_INITIALIZER(pMSSIMCreate,                               \
                                  fixedtpm,                                     \
                                  stclear,                                      \
                                  bit_at_3,                                     \
                                  fixedparent,                                  \
                                  sensitivedataorigin,                          \
                                  userwithauth,                                 \
                                  adminwithpolicy,                              \
                                  bits_at_8,                                    \
                                  noda,                                         \
                                  encryptedduplication,                         \
                                  bits_at_12,                                   \
                                  restricted,                                   \
                                  decrypt,                                      \
                                  sign,                                         \
                                  x509sign,                                     \
                                  bits_at_20)                                   \
    {                                                                           \
      pMSSIMCreate, fixedtpm, stclear, bit_at_3, fixedparent, sensitivedataorigin,  \
          userwithauth, adminwithpolicy, bits_at_8, noda, encryptedduplication, \
          bits_at_12, restricted, decrypt, sign, x509sign, bits_at_20           \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:31 MSSIMA_OBJECT using bit masking
typedef UINT32 MSSIMA_OBJECT;
#  define TYPE_OF_MSSIMA_OBJECT              UINT32
#  define MSSIMA_OBJECT_pMSSIMCreated        ((MSSIMA_OBJECT)1 << 0)
#  define MSSIMA_OBJECT_fixedMSSIM           ((MSSIMA_OBJECT)1 << 1)
#  define MSSIMA_OBJECT_stClear              ((MSSIMA_OBJECT)1 << 2)
#  define MSSIMA_OBJECT_fixedParent          ((MSSIMA_OBJECT)1 << 4)
#  define MSSIMA_OBJECT_sensitiveDataOrigin  ((MSSIMA_OBJECT)1 << 5)
#  define MSSIMA_OBJECT_userWithAuth         ((MSSIMA_OBJECT)1 << 6)
#  define MSSIMA_OBJECT_adminWithPolicy      ((MSSIMA_OBJECT)1 << 7)
#  define MSSIMA_OBJECT_noDA                 ((MSSIMA_OBJECT)1 << 10)
#  define MSSIMA_OBJECT_encryptedDuplication ((MSSIMA_OBJECT)1 << 11)
#  define MSSIMA_OBJECT_restricted           ((MSSIMA_OBJECT)1 << 16)
#  define MSSIMA_OBJECT_decrypt              ((MSSIMA_OBJECT)1 << 17)
#  define MSSIMA_OBJECT_sign                 ((MSSIMA_OBJECT)1 << 18)
#  define MSSIMA_OBJECT_x509sign             ((MSSIMA_OBJECT)1 << 19)
//  This is the initializer for a MSSIMA_OBJECT bit array.
#  define MSSIMA_OBJECT_INITIALIZER(pMSSIMCreate,                          \
                                  fixedtpm,                             \
                                  stclear,                              \
                                  bit_at_3,                             \
                                  fixedparent,                          \
                                  sensitivedataorigin,                  \
                                  userwithauth,                         \
                                  adminwithpolicy,                      \
                                  bits_at_8,                            \
                                  noda,                                 \
                                  encryptedduplication,                 \
                                  bits_at_12,                           \
                                  restricted,                           \
                                  decrypt,                              \
                                  sign,                                 \
                                  x509sign,                             \
                                  bits_at_20)                           \
    (MSSIMA_OBJECT)((pMSSIMCreate << 0) + (fixedtpm << 1) + (stclear << 2) + (fixedparent << 4) \
                  + (sensitivedataorigin << 5) + (userwithauth << 6)    \
                  + (adminwithpolicy << 7) + (noda << 10)               \
                  + (encryptedduplication << 11) + (restricted << 16)   \
                  + (decrypt << 17) + (sign << 18) + (x509sign << 19))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_SESSION     UINT8
#define MSSIMA_SESSION_TO_UINT8(a) (*((UINT8*)&(a)))
#define UINT8_TO_MSSIMA_SESSION(a) (*((MSSIMA_SESSION*)&(a)))
#define MSSIMA_SESSION_TO_BYTE_ARRAY(i, a) \
  UINT8_TO_BYTE_ARRAY((MSSIMA_SESSION_TO_UINT8(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_SESSION(i, a) \
  {                                      \
    UINT8 x = BYTE_ARRAY_TO_UINT8(a);    \
    i       = UINT8_TO_MSSIMA_SESSION(x);  \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_SESSION
{  // Table 2:32
    unsigned continueSession    : 1;
    unsigned auditExclusive     : 1;
    unsigned auditReset         : 1;
    unsigned Reserved_bits_at_3 : 2;
    unsigned decrypt            : 1;
    unsigned encrypt            : 1;
    unsigned audit              : 1;
} MSSIMA_SESSION; /* Bits */
// This is the initializer for a MSSIMA_SESSION structure
#  define MSSIMA_SESSION_INITIALIZER(continuesession,                             \
                                   auditexclusive,                              \
                                   auditreset,                                  \
                                   bits_at_3,                                   \
                                   decrypt,                                     \
                                   encrypt,                                     \
                                   audit)                                       \
    {                                                                           \
      continuesession, auditexclusive, auditreset, bits_at_3, decrypt, encrypt, \
          audit                                                                 \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:32 MSSIMA_SESSION using bit masking
typedef UINT8 MSSIMA_SESSION;
#  define TYPE_OF_MSSIMA_SESSION         UINT8
#  define MSSIMA_SESSION_continueSession ((MSSIMA_SESSION)1 << 0)
#  define MSSIMA_SESSION_auditExclusive  ((MSSIMA_SESSION)1 << 1)
#  define MSSIMA_SESSION_auditReset      ((MSSIMA_SESSION)1 << 2)
#  define MSSIMA_SESSION_decrypt         ((MSSIMA_SESSION)1 << 5)
#  define MSSIMA_SESSION_encrypt         ((MSSIMA_SESSION)1 << 6)
#  define MSSIMA_SESSION_audit           ((MSSIMA_SESSION)1 << 7)
//  This is the initializer for a MSSIMA_SESSION bit array.
#  define MSSIMA_SESSION_INITIALIZER(continuesession,                      \
                                   auditexclusive,                       \
                                   auditreset,                           \
                                   bits_at_3,                            \
                                   decrypt,                              \
                                   encrypt,                              \
                                   audit)                                \
    (MSSIMA_SESSION)((continuesession << 0) + (auditexclusive << 1)        \
                   + (auditreset << 2) + (decrypt << 5) + (encrypt << 6) \
                   + (audit << 7))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_LOCALITY     UINT8
#define MSSIMA_LOCALITY_TO_UINT8(a) (*((UINT8*)&(a)))
#define UINT8_TO_MSSIMA_LOCALITY(a) (*((MSSIMA_LOCALITY*)&(a)))
#define MSSIMA_LOCALITY_TO_BYTE_ARRAY(i, a) \
  UINT8_TO_BYTE_ARRAY((MSSIMA_LOCALITY_TO_UINT8(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_LOCALITY(i, a) \
  {                                       \
    UINT8 x = BYTE_ARRAY_TO_UINT8(a);     \
    i       = UINT8_TO_MSSIMA_LOCALITY(x);  \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_LOCALITY
{  // Table 2:33
    unsigned MSSIM_LOC_ZERO  : 1;
    unsigned MSSIM_LOC_ONE   : 1;
    unsigned MSSIM_LOC_TWO   : 1;
    unsigned MSSIM_LOC_THREE : 1;
    unsigned MSSIM_LOC_FOUR  : 1;
    unsigned Extended      : 3;
} MSSIMA_LOCALITY; /* Bits */
// This is the initializer for a MSSIMA_LOCALITY structure
#  define MSSIMA_LOCALITY_INITIALIZER(                                                 \
      tpm_loc_zero, tpm_loc_one, tpm_loc_two, tpm_loc_three, tpm_loc_four, extended) \
    {                                                                                \
      tpm_loc_zero, tpm_loc_one, tpm_loc_two, tpm_loc_three, tpm_loc_four, extended  \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:33 MSSIMA_LOCALITY using bit masking
typedef UINT8 MSSIMA_LOCALITY;
#  define TYPE_OF_MSSIMA_LOCALITY        UINT8
#  define MSSIMA_LOCALITY_MSSIM_LOC_ZERO   ((MSSIMA_LOCALITY)1 << 0)
#  define MSSIMA_LOCALITY_MSSIM_LOC_ONE    ((MSSIMA_LOCALITY)1 << 1)
#  define MSSIMA_LOCALITY_MSSIM_LOC_TWO    ((MSSIMA_LOCALITY)1 << 2)
#  define MSSIMA_LOCALITY_MSSIM_LOC_THREE  ((MSSIMA_LOCALITY)1 << 3)
#  define MSSIMA_LOCALITY_MSSIM_LOC_FOUR   ((MSSIMA_LOCALITY)1 << 4)
#  define MSSIMA_LOCALITY_Extended_SHIFT 5
#  define MSSIMA_LOCALITY_Extended       ((MSSIMA_LOCALITY)0x7 << 5)
//  This is the initializer for a MSSIMA_LOCALITY bit array.
#  define MSSIMA_LOCALITY_INITIALIZER(                                                 \
      tpm_loc_zero, tpm_loc_one, tpm_loc_two, tpm_loc_three, tpm_loc_four, extended) \
    (MSSIMA_LOCALITY)((tpm_loc_zero << 0) + (tpm_loc_one << 1) + (tpm_loc_two << 2)    \
                    + (tpm_loc_three << 3) + (tpm_loc_four << 4) + (extended << 5))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_PERMANENT      UINT32
#define MSSIMA_PERMANENT_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_PERMANENT(a) (*((MSSIMA_PERMANENT*)&(a)))
#define MSSIMA_PERMANENT_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_PERMANENT_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_PERMANENT(i, a)  \
  {                                         \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);     \
    i        = UINT32_TO_MSSIMA_PERMANENT(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_PERMANENT
{  // Table 2:34
    unsigned ownerAuthSet        : 1;
    unsigned endorsementAuthSet  : 1;
    unsigned lockoutAuthSet      : 1;
    unsigned Reserved_bits_at_3  : 5;
    unsigned disableClear        : 1;
    unsigned inLockout           : 1;
    unsigned tpmGeneratedEPS     : 1;
    unsigned Reserved_bits_at_11 : 21;
} MSSIMA_PERMANENT; /* Bits */
// This is the initializer for a MSSIMA_PERMANENT structure
#  define MSSIMA_PERMANENT_INITIALIZER(ownerauthset,                               \
                                     endorsementauthset,                         \
                                     lockoutauthset,                             \
                                     bits_at_3,                                  \
                                     disableclear,                               \
                                     inlockout,                                  \
                                     tpmgeneratedeps,                            \
                                     bits_at_11)                                 \
    {                                                                            \
      ownerauthset, endorsementauthset, lockoutauthset, bits_at_3, disableclear, \
          inlockout, tpmgeneratedeps, bits_at_11                                 \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:34 MSSIMA_PERMANENT using bit masking
typedef UINT32 MSSIMA_PERMANENT;
#  define TYPE_OF_MSSIMA_PERMANENT            UINT32
#  define MSSIMA_PERMANENT_ownerAuthSet       ((MSSIMA_PERMANENT)1 << 0)
#  define MSSIMA_PERMANENT_endorsementAuthSet ((MSSIMA_PERMANENT)1 << 1)
#  define MSSIMA_PERMANENT_lockoutAuthSet     ((MSSIMA_PERMANENT)1 << 2)
#  define MSSIMA_PERMANENT_disableClear       ((MSSIMA_PERMANENT)1 << 8)
#  define MSSIMA_PERMANENT_inLockout          ((MSSIMA_PERMANENT)1 << 9)
#  define MSSIMA_PERMANENT_tpmGeneratedEPS    ((MSSIMA_PERMANENT)1 << 10)
//  This is the initializer for a MSSIMA_PERMANENT bit array.
#  define MSSIMA_PERMANENT_INITIALIZER(ownerauthset,                   \
                                     endorsementauthset,             \
                                     lockoutauthset,                 \
                                     bits_at_3,                      \
                                     disableclear,                   \
                                     inlockout,                      \
                                     tpmgeneratedeps,                \
                                     bits_at_11)                     \
    (MSSIMA_PERMANENT)((ownerauthset << 0) + (endorsementauthset << 1) \
                     + (lockoutauthset << 2) + (disableclear << 8)   \
                     + (inlockout << 9) + (tpmgeneratedeps << 10))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_STARTUP_CLEAR      UINT32
#define MSSIMA_STARTUP_CLEAR_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_STARTUP_CLEAR(a) (*((MSSIMA_STARTUP_CLEAR*)&(a)))
#define MSSIMA_STARTUP_CLEAR_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_STARTUP_CLEAR_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_STARTUP_CLEAR(i, a)  \
  {                                             \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);         \
    i        = UINT32_TO_MSSIMA_STARTUP_CLEAR(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_STARTUP_CLEAR
{  // Table 2:35
    unsigned phEnable           : 1;
    unsigned shEnable           : 1;
    unsigned ehEnable           : 1;
    unsigned phEnableNV         : 1;
    unsigned Reserved_bits_at_4 : 27;
    unsigned orderly            : 1;
} MSSIMA_STARTUP_CLEAR; /* Bits */
// This is the initializer for a MSSIMA_STARTUP_CLEAR structure
#  define MSSIMA_STARTUP_CLEAR_INITIALIZER(                           \
      phenable, shenable, ehenable, phenablenv, bits_at_4, orderly) \
    {                                                               \
      phenable, shenable, ehenable, phenablenv, bits_at_4, orderly  \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:35 MSSIMA_STARTUP_CLEAR using bit masking
typedef UINT32 MSSIMA_STARTUP_CLEAR;
#  define TYPE_OF_MSSIMA_STARTUP_CLEAR    UINT32
#  define MSSIMA_STARTUP_CLEAR_phEnable   ((MSSIMA_STARTUP_CLEAR)1 << 0)
#  define MSSIMA_STARTUP_CLEAR_shEnable   ((MSSIMA_STARTUP_CLEAR)1 << 1)
#  define MSSIMA_STARTUP_CLEAR_ehEnable   ((MSSIMA_STARTUP_CLEAR)1 << 2)
#  define MSSIMA_STARTUP_CLEAR_phEnableNV ((MSSIMA_STARTUP_CLEAR)1 << 3)
#  define MSSIMA_STARTUP_CLEAR_orderly    ((MSSIMA_STARTUP_CLEAR)1 << 31)
//  This is the initializer for a MSSIMA_STARTUP_CLEAR bit array.
#  define MSSIMA_STARTUP_CLEAR_INITIALIZER(                                    \
      phenable, shenable, ehenable, phenablenv, bits_at_4, orderly)          \
    (MSSIMA_STARTUP_CLEAR)((phenable << 0) + (shenable << 1) + (ehenable << 2) \
                         + (phenablenv << 3) + (orderly << 31))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_MEMORY      UINT32
#define MSSIMA_MEMORY_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_MEMORY(a) (*((MSSIMA_MEMORY*)&(a)))
#define MSSIMA_MEMORY_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_MEMORY_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_MEMORY(i, a)  \
  {                                      \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);  \
    i        = UINT32_TO_MSSIMA_MEMORY(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_MEMORY
{  // Table 2:36
    unsigned sharedRAM          : 1;
    unsigned sharedNV           : 1;
    unsigned objectCopiedToRam  : 1;
    unsigned Reserved_bits_at_3 : 29;
} MSSIMA_MEMORY; /* Bits */
// This is the initializer for a MSSIMA_MEMORY structure
#  define MSSIMA_MEMORY_INITIALIZER(sharedram, sharednv, objectcopiedtoram, bits_at_3) \
    {                                                                                \
      sharedram, sharednv, objectcopiedtoram, bits_at_3                              \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:36 MSSIMA_MEMORY using bit masking
typedef UINT32 MSSIMA_MEMORY;
#  define TYPE_OF_MSSIMA_MEMORY           UINT32
#  define MSSIMA_MEMORY_sharedRAM         ((MSSIMA_MEMORY)1 << 0)
#  define MSSIMA_MEMORY_sharedNV          ((MSSIMA_MEMORY)1 << 1)
#  define MSSIMA_MEMORY_objectCopiedToRam ((MSSIMA_MEMORY)1 << 2)
//  This is the initializer for a MSSIMA_MEMORY bit array.
#  define MSSIMA_MEMORY_INITIALIZER(sharedram, sharednv, objectcopiedtoram, bits_at_3) \
    (MSSIMA_MEMORY)((sharedram << 0) + (sharednv << 1) + (objectcopiedtoram << 2))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_CC             UINT32
#define MSSIMA_CC_TO_UINT32(a)        (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_CC(a)        (*((MSSIMA_CC*)&(a)))
#define MSSIMA_CC_TO_BYTE_ARRAY(i, a) UINT32_TO_BYTE_ARRAY((MSSIMA_CC_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_CC(i, a)     \
  {                                     \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a); \
    i        = UINT32_TO_MSSIMA_CC(x);    \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_CC
{  // Table 2:37
    unsigned commandIndex        : 16;
    unsigned Reserved_bits_at_16 : 6;
    unsigned nv                  : 1;
    unsigned extensive           : 1;
    unsigned flushed             : 1;
    unsigned cHandles            : 3;
    unsigned rHandle             : 1;
    unsigned V                   : 1;
    unsigned Reserved_bits_at_30 : 2;
} MSSIMA_CC; /* Bits */
// This is the initializer for a MSSIMA_CC structure
#  define MSSIMA_CC_INITIALIZER(commandindex,                                   \
                              bits_at_16,                                     \
                              nv,                                             \
                              extensive,                                      \
                              flushed,                                        \
                              chandles,                                       \
                              rhandle,                                        \
                              v,                                              \
                              bits_at_30)                                     \
    {                                                                         \
      commandindex, bits_at_16, nv, extensive, flushed, chandles, rhandle, v, \
          bits_at_30                                                          \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:37 MSSIMA_CC using bit masking
typedef UINT32 MSSIMA_CC;
#  define TYPE_OF_MSSIMA_CC            UINT32
#  define MSSIMA_CC_commandIndex_SHIFT 0
#  define MSSIMA_CC_commandIndex       ((MSSIMA_CC)0xffff << 0)
#  define MSSIMA_CC_nv                 ((MSSIMA_CC)1 << 22)
#  define MSSIMA_CC_extensive          ((MSSIMA_CC)1 << 23)
#  define MSSIMA_CC_flushed            ((MSSIMA_CC)1 << 24)
#  define MSSIMA_CC_cHandles_SHIFT     25
#  define MSSIMA_CC_cHandles           ((MSSIMA_CC)0x7 << 25)
#  define MSSIMA_CC_rHandle            ((MSSIMA_CC)1 << 28)
#  define MSSIMA_CC_V                  ((MSSIMA_CC)1 << 29)
//  This is the initializer for a MSSIMA_CC bit array.
#  define MSSIMA_CC_INITIALIZER(commandindex,                                          \
                              bits_at_16,                                            \
                              nv,                                                    \
                              extensive,                                             \
                              flushed,                                               \
                              chandles,                                              \
                              rhandle,                                               \
                              v,                                                     \
                              bits_at_30)                                            \
    (MSSIMA_CC)((commandindex << 0) + (nv << 22) + (extensive << 23) + (flushed << 24) \
              + (chandles << 25) + (rhandle << 28) + (v << 29))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_MODES      UINT32
#define MSSIMA_MODES_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_MODES(a) (*((MSSIMA_MODES*)&(a)))
#define MSSIMA_MODES_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_MODES_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_MODES(i, a)  \
  {                                     \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a); \
    i        = UINT32_TO_MSSIMA_MODES(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_MODES
{  // Table 2:38
    unsigned FIPS_140_2         : 1;
    unsigned Reserved_bits_at_1 : 31;
} MSSIMA_MODES; /* Bits */
// This is the initializer for a MSSIMA_MODES structure
#  define MSSIMA_MODES_INITIALIZER(fips_140_2, bits_at_1) \
    {                                                   \
      fips_140_2, bits_at_1                             \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:38 MSSIMA_MODES using bit masking
typedef UINT32 MSSIMA_MODES;
#  define TYPE_OF_MSSIMA_MODES    UINT32
#  define MSSIMA_MODES_FIPS_140_2 ((MSSIMA_MODES)1 << 0)
//  This is the initializer for a MSSIMA_MODES bit array.
#  define MSSIMA_MODES_INITIALIZER(fips_140_2, bits_at_1) \
    (MSSIMA_MODES)((fips_140_2 << 0))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_X509_KEY_USAGE      UINT32
#define MSSIMA_X509_KEY_USAGE_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_X509_KEY_USAGE(a) (*((MSSIMA_X509_KEY_USAGE*)&(a)))
#define MSSIMA_X509_KEY_USAGE_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_X509_KEY_USAGE_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_X509_KEY_USAGE(i, a)  \
  {                                              \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);          \
    i        = UINT32_TO_MSSIMA_X509_KEY_USAGE(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_X509_KEY_USAGE
{  // Table 2:39
    unsigned Reserved_bits_at_0 : 23;
    unsigned decipherOnly       : 1;
    unsigned encipherOnly       : 1;
    unsigned cRLSign            : 1;
    unsigned keyCertSign        : 1;
    unsigned keyAgreement       : 1;
    unsigned dataEncipherment   : 1;
    unsigned keyEncipherment    : 1;
    unsigned nonrepudiation     : 1;
    unsigned digitalSignature   : 1;
} MSSIMA_X509_KEY_USAGE; /* Bits */
// This is the initializer for a MSSIMA_X509_KEY_USAGE structure
#  define MSSIMA_X509_KEY_USAGE_INITIALIZER(bits_at_0,                             \
                                          decipheronly,                          \
                                          encipheronly,                          \
                                          crlsign,                               \
                                          keycertsign,                           \
                                          keyagreement,                          \
                                          dataencipherment,                      \
                                          keyencipherment,                       \
                                          nonrepudiation,                        \
                                          digitalsignature)                      \
    {                                                                            \
      bits_at_0, decipheronly, encipheronly, crlsign, keycertsign, keyagreement, \
          dataencipherment, keyencipherment, nonrepudiation, digitalsignature    \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:39 MSSIMA_X509_KEY_USAGE using bit masking
typedef UINT32 MSSIMA_X509_KEY_USAGE;
#  define TYPE_OF_MSSIMA_X509_KEY_USAGE          UINT32
#  define MSSIMA_X509_KEY_USAGE_decipherOnly     ((MSSIMA_X509_KEY_USAGE)1 << 23)
#  define MSSIMA_X509_KEY_USAGE_encipherOnly     ((MSSIMA_X509_KEY_USAGE)1 << 24)
#  define MSSIMA_X509_KEY_USAGE_cRLSign          ((MSSIMA_X509_KEY_USAGE)1 << 25)
#  define MSSIMA_X509_KEY_USAGE_keyCertSign      ((MSSIMA_X509_KEY_USAGE)1 << 26)
#  define MSSIMA_X509_KEY_USAGE_keyAgreement     ((MSSIMA_X509_KEY_USAGE)1 << 27)
#  define MSSIMA_X509_KEY_USAGE_dataEncipherment ((MSSIMA_X509_KEY_USAGE)1 << 28)
#  define MSSIMA_X509_KEY_USAGE_keyEncipherment  ((MSSIMA_X509_KEY_USAGE)1 << 29)
#  define MSSIMA_X509_KEY_USAGE_nonrepudiation   ((MSSIMA_X509_KEY_USAGE)1 << 30)
#  define MSSIMA_X509_KEY_USAGE_digitalSignature ((MSSIMA_X509_KEY_USAGE)1 << 31)
//  This is the initializer for a MSSIMA_X509_KEY_USAGE bit array.
#  define MSSIMA_X509_KEY_USAGE_INITIALIZER(bits_at_0,                         \
                                          decipheronly,                      \
                                          encipheronly,                      \
                                          crlsign,                           \
                                          keycertsign,                       \
                                          keyagreement,                      \
                                          dataencipherment,                  \
                                          keyencipherment,                   \
                                          nonrepudiation,                    \
                                          digitalsignature)                  \
    (MSSIMA_X509_KEY_USAGE)((decipheronly << 23) + (encipheronly << 24)        \
                          + (crlsign << 25) + (keycertsign << 26)            \
                          + (keyagreement << 27) + (dataencipherment << 28)  \
                          + (keyencipherment << 29) + (nonrepudiation << 30) \
                          + (digitalsignature << 31))
#endif  // USE_BIT_FIELD_STRUCTURES

#define TYPE_OF_MSSIMA_ACT      UINT32
#define MSSIMA_ACT_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_ACT(a) (*((MSSIMA_ACT*)&(a)))
#define MSSIMA_ACT_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIMA_ACT_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_ACT(i, a)    \
  {                                     \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a); \
    i        = UINT32_TO_MSSIMA_ACT(x);   \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_ACT
{  // Table 2:40
    unsigned signaled           : 1;
    unsigned preserveSignaled   : 1;
    unsigned Reserved_bits_at_2 : 30;
} MSSIMA_ACT; /* Bits */
// This is the initializer for a MSSIMA_ACT structure
#  define MSSIMA_ACT_INITIALIZER(signaled, preservesignaled, bits_at_2) \
    {                                                                 \
      signaled, preservesignaled, bits_at_2                           \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:40 MSSIMA_ACT using bit masking
typedef UINT32 MSSIMA_ACT;
#  define TYPE_OF_MSSIMA_ACT          UINT32
#  define MSSIMA_ACT_signaled         ((MSSIMA_ACT)1 << 0)
#  define MSSIMA_ACT_preserveSignaled ((MSSIMA_ACT)1 << 1)
//  This is the initializer for a MSSIMA_ACT bit array.
#  define MSSIMA_ACT_INITIALIZER(signaled, preservesignaled, bits_at_2) \
    (MSSIMA_ACT)((signaled << 0) + (preservesignaled << 1))
#endif  // USE_BIT_FIELD_STRUCTURES

typedef BYTE       MSSIMI_YES_NO;  // Table 2:41  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_OBJECT;  // Table 2:42  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_PARENT;  // Table 2:43  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_PERSISTENT;  // Table 2:44  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_ENTITY;  // Table 2:45  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_PCR;  // Table 2:46  /* Interface */

typedef MSSIM_HANDLE MSSIMI_SH_AUTH_SESSION;  // Table 2:47  /* Interface */

typedef MSSIM_HANDLE MSSIMI_SH_HMAC;  // Table 2:48  /* Interface */

typedef MSSIM_HANDLE MSSIMI_SH_POLICY;  // Table 2:49  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_CONTEXT;  // Table 2:50  /* Interface */

typedef MSSIM_HANDLE MSSIMI_DH_SAVED;  // Table 2:51  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_HIERARCHY;  // Table 2:52  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_ENABLES;  // Table 2:53  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_HIERARCHY_AUTH;  // Table 2:54  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_HIERARCHY_POLICY;

typedef MSSIM_HANDLE MSSIMI_RH_PLATFORM;  // Table 2:56  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_OWNER;  // Table 2:57  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_ENDORSEMENT;  // Table 2:58  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_PROVISION;  // Table 2:59  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_CLEAR;  // Table 2:60  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_NV_AUTH;  // Table 2:61  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_LOCKOUT;  // Table 2:62  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_NV_INDEX;  // Table 2:63  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_AC;  // Table 2:64  /* Interface */

typedef MSSIM_HANDLE MSSIMI_RH_ACT;  // Table 2:65  /* Interface */

typedef MSSIM_HANDLE VSPK_STRUCTURE;  // VIRT Extension

typedef MSSIM_ALG_ID MSSIMI_ALG_HASH;  // Table 2:66  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_ASYM;  // Table 2:67  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_SYM;  // Table 2:68  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_SYM_OBJECT;  // Table 2:69  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_SYM_MODE;  // Table 2:70  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_KDF;  // Table 2:71  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_SIG_SCHEME;  // Table 2:72  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ECC_KEY_EXCHANGE;  // Table 2:73  /* Interface */

typedef MSSIM_ST     MSSIMI_ST_COMMAND_TAG;  // Table 2:74  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_MAC_SCHEME;  // Table 2:75  /* Interface */

typedef MSSIM_ALG_ID MSSIMI_ALG_CIPHER_MODE;  // Table 2:76  /* Interface */

typedef BYTE       MSSIMS_EMPTY;  // Table 2:77

typedef struct
{  // Table 2:78
    MSSIM_ALG_ID     alg;
    MSSIMA_ALGORITHM attributes;
} MSSIMS_ALGORITHM_DESCRIPTION; /* Structure */

typedef union
{  // Table 2:79
#if ALG_SHA1
    BYTE sha1[SHA1_DIGEST_SIZE];
#endif  // ALG_SHA1
#if ALG_SHA256
    BYTE sha256[SHA256_DIGEST_SIZE];
#endif  // ALG_SHA256
#if ALG_SHA384
    BYTE sha384[SHA384_DIGEST_SIZE];
#endif  // ALG_SHA384
#if ALG_SHA512
    BYTE sha512[SHA512_DIGEST_SIZE];
#endif  // ALG_SHA512
#if ALG_SM3_256
    BYTE sm3_256[SM3_256_DIGEST_SIZE];
#endif  // ALG_SM3_256
#if ALG_SHA3_256
    BYTE sha3_256[SHA3_256_DIGEST_SIZE];
#endif  // ALG_SHA3_256
#if ALG_SHA3_384
    BYTE sha3_384[SHA3_384_DIGEST_SIZE];
#endif  // ALG_SHA3_384
#if ALG_SHA3_512
    BYTE sha3_512[SHA3_512_DIGEST_SIZE];
#endif     // ALG_SHA3_512
} MSSIMU_HA; /* Structure */

typedef struct
{  // Table 2:80
    MSSIMI_ALG_HASH hashAlg;
    MSSIMU_HA       digest;
} MSSIMT_HA; /* Structure */

typedef union
{  // Table 2:81
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(MSSIMU_HA)];
    } t;
    MSSIM2B b;
} MSSIM2B_DIGEST; /* Structure */

typedef union
{  // Table 2:82
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(MSSIMT_HA)];
    } t;
    MSSIM2B b;
} MSSIM2B_DATA; /* Structure */

// Table 2:83 - Definition of Types for MSSIM2B_NONCE
typedef MSSIM2B_DIGEST MSSIM2B_NONCE;

// Table 2:84 - Definition of Types for MSSIM2B_AUTH
typedef MSSIM2B_DIGEST MSSIM2B_AUTH;

// Table 2:85 - Definition of Types for MSSIM2B_OPERAND
typedef MSSIM2B_DIGEST MSSIM2B_OPERAND;

typedef union
{  // Table 2:86
    struct
    {
        UINT16 size;
        BYTE   buffer[1024];
    } t;
    MSSIM2B b;
} MSSIM2B_EVENT; /* Structure */

typedef union
{  // Table 2:87
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_DIGEST_BUFFER];
    } t;
    MSSIM2B b;
} MSSIM2B_MAX_BUFFER; /* Structure */

typedef union
{  // Table 2:88
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_NV_BUFFER_SIZE];
    } t;
    MSSIM2B b;
} MSSIM2B_MAX_NV_BUFFER; /* Structure */

typedef union
{  // Table 2:89
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(UINT64)];
    } t;
    MSSIM2B b;
} MSSIM2B_TIMEOUT; /* Structure */

typedef union
{  // Table 2:90
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_SYM_BLOCK_SIZE];
    } t;
    MSSIM2B b;
} MSSIM2B_IV; /* Structure */

typedef union
{  // Table 2:91
    MSSIMT_HA    digest;
    MSSIM_HANDLE handle;
} MSSIMU_NAME; /* Structure */

typedef union
{  // Table 2:92
    struct
    {
        UINT16 size;
        BYTE   name[sizeof(MSSIMU_NAME)];
    } t;
    MSSIM2B b;
} MSSIM2B_NAME; /* Structure */

typedef struct
{  // Table 2:93
    UINT8 sizeofSelect;
    BYTE  pcrSelect[PCR_SELECT_MAX];
} MSSIMS_PCR_SELECT; /* Structure */

typedef struct
{  // Table 2:94
    MSSIMI_ALG_HASH hash;
    UINT8         sizeofSelect;
    BYTE          pcrSelect[PCR_SELECT_MAX];
} MSSIMS_PCR_SELECTION; /* Structure */

typedef struct
{  // Table 2:97
    MSSIM_ST            tag;
    MSSIMI_RH_HIERARCHY hierarchy;
    MSSIM2B_DIGEST      digest;
} MSSIMT_TK_CREATION; /* Structure */

typedef struct
{  // Table 2:98
    MSSIM_ST            tag;
    MSSIMI_RH_HIERARCHY hierarchy;
    MSSIM2B_DIGEST      digest;
} MSSIMT_TK_VERIFIED; /* Structure */

typedef struct
{  // Table 2:99
    MSSIM_ST            tag;
    MSSIMI_RH_HIERARCHY hierarchy;
    MSSIM2B_DIGEST      digest;
} MSSIMT_TK_AUTH; /* Structure */

typedef struct
{  // Table 2:100
    MSSIM_ST            tag;
    MSSIMI_RH_HIERARCHY hierarchy;
    MSSIM2B_DIGEST      digest;
} MSSIMT_TK_HASHCHECK; /* Structure */

typedef struct
{  // Table 2:101
    MSSIM_ALG_ID     alg;
    MSSIMA_ALGORITHM algProperties;
} MSSIMS_ALG_PROPERTY; /* Structure */

typedef struct
{  // Table 2:102
    MSSIM_PT property;
    UINT32 value;
} MSSIMS_TAGGED_PROPERTY; /* Structure */

typedef struct
{  // Table 2:103
    MSSIM_PT_PCR tag;
    UINT8      sizeofSelect;
    BYTE       pcrSelect[PCR_SELECT_MAX];
} MSSIMS_TAGGED_PCR_SELECT; /* Structure */

typedef struct
{  // Table 2:104
    MSSIM_HANDLE handle;
    MSSIMT_HA    policyHash;
} MSSIMS_TAGGED_POLICY; /* Structure */

typedef struct
{  // Table 2:105
    MSSIM_HANDLE handle;
    UINT32     timeout;
    MSSIMA_ACT   attributes;
} MSSIMS_ACT_DATA; /* Structure */

typedef struct
{  // Table 2:106
    UINT32 count;
    MSSIM_CC commandCodes[MAX_CAP_CC];
} MSSIML_CC; /* Structure */

typedef struct
{  // Table 2:107
    UINT32  count;
    MSSIMA_CC commandAttributes[MAX_CAP_CC];
} MSSIML_CCA; /* Structure */

typedef struct
{  // Table 2:108
    UINT32     count;
    MSSIM_ALG_ID algorithms[MAX_ALG_LIST_SIZE];
} MSSIML_ALG; /* Structure */

typedef struct
{  // Table 2:109
    UINT32     count;
    MSSIM_HANDLE handle[MAX_CAP_HANDLES];
} MSSIML_HANDLE; /* Structure */

typedef struct
{  // Table 2:110
    UINT32       count;
    MSSIM2B_DIGEST digests[8];
} MSSIML_DIGEST; /* Structure */

typedef struct
{  // Table 2:111
    UINT32  count;
    MSSIMT_HA digests[HASH_COUNT];
} MSSIML_DIGEST_VALUES; /* Structure */

typedef struct
{  // Table 2:112
    UINT32             count;
    MSSIMS_PCR_SELECTION pcrSelections[HASH_COUNT];
} MSSIML_PCR_SELECTION; /* Structure */

typedef struct
{  // Table 2:113
    UINT32            count;
    MSSIMS_ALG_PROPERTY algProperties[MAX_CAP_ALGS];
} MSSIML_ALG_PROPERTY; /* Structure */

typedef struct
{  // Table 2:114
    UINT32               count;
    MSSIMS_TAGGED_PROPERTY tpmProperty[MAX_MSSIM_PROPERTIES];
} MSSIML_TAGGED_MSSIM_PROPERTY; /* Structure */

typedef struct
{  // Table 2:115
    UINT32                 count;
    MSSIMS_TAGGED_PCR_SELECT pcrProperty[MAX_PCR_PROPERTIES];
} MSSIML_TAGGED_PCR_PROPERTY; /* Structure */

typedef struct
{  // Table 2:116
    UINT32        count;
    MSSIM_ECC_CURVE eccCurves[MAX_ECC_CURVES];
} MSSIML_ECC_CURVE; /* Structure */

typedef struct
{  // Table 2:117
    UINT32             count;
    MSSIMS_TAGGED_POLICY policies[MAX_TAGGED_POLICIES];
} MSSIML_TAGGED_POLICY; /* Structure */

typedef struct
{  // Table 2:118
    UINT32        count;
    MSSIMS_ACT_DATA actData[MAX_ACT_DATA];
} MSSIML_ACT_DATA; /* Structure */

typedef union
{  // Table 2:119
    MSSIML_ALG_PROPERTY        algorithms;
    MSSIML_HANDLE              handles;
    MSSIML_CCA                 command;
    MSSIML_CC                  ppCommands;
    MSSIML_CC                  auditCommands;
    MSSIML_PCR_SELECTION       assignedPCR;
    MSSIML_TAGGED_MSSIM_PROPERTY tpmProperties;
    MSSIML_TAGGED_PCR_PROPERTY pcrProperties;
#if ALG_ECC
    MSSIML_ECC_CURVE eccCurves;
#endif  // ALG_ECC
    MSSIML_TAGGED_POLICY authPolicies;
    MSSIML_ACT_DATA      actData;
} MSSIMU_CAPABILITIES; /* Structure */

typedef struct
{  // Table 2:120
    MSSIM_CAP           capability;
    MSSIMU_CAPABILITIES data;
} MSSIMS_CAPABILITY_DATA; /* Structure */

typedef struct
{  // Table 2:121
    UINT64      clock;
    UINT32      resetCount;
    UINT32      restartCount;
    MSSIMI_YES_NO safe;
} MSSIMS_CLOCK_INFO; /* Structure */

typedef struct
{  // Table 2:122
    UINT64          time;
    MSSIMS_CLOCK_INFO clockInfo;
} MSSIMS_TIME_INFO; /* Structure */

typedef struct
{  // Table 2:123
    MSSIMS_TIME_INFO time;
    UINT64         firmwareVersion;
} MSSIMS_TIME_ATTEST_INFO; /* Structure */

typedef struct
{  // Table 2:124
    MSSIM2B_NAME name;
    MSSIM2B_NAME qualifiedName;
} MSSIMS_CERTIFY_INFO; /* Structure */

typedef struct
{  // Table 2:125
    MSSIML_PCR_SELECTION pcrSelect;
    MSSIM2B_DIGEST       pcrDigest;
} MSSIMS_QUOTE_INFO; /* Structure */

typedef struct
{  // Table 2:126
    UINT64       auditCounter;
    MSSIM_ALG_ID   digestAlg;
    MSSIM2B_DIGEST auditDigest;
    MSSIM2B_DIGEST commandDigest;
} MSSIMS_COMMAND_AUDIT_INFO; /* Structure */

typedef struct
{  // Table 2:127
    MSSIMI_YES_NO  exclusiveSession;
    MSSIM2B_DIGEST sessionDigest;
} MSSIMS_SESSION_AUDIT_INFO; /* Structure */

typedef struct
{  // Table 2:128
    MSSIM2B_NAME   objectName;
    MSSIM2B_DIGEST creationHash;
} MSSIMS_CREATION_INFO; /* Structure */

typedef struct
{  // Table 2:129
    MSSIM2B_NAME          indexName;
    UINT16              offset;
    MSSIM2B_MAX_NV_BUFFER nvContents;
} MSSIMS_NV_CERTIFY_INFO; /* Structure */

typedef struct
{  // Table 2:130
    MSSIM2B_NAME   indexName;
    MSSIM2B_DIGEST nvDigest;
} MSSIMS_NV_DIGEST_CERTIFY_INFO; /* Structure */

typedef MSSIM_ST MSSIMI_ST_ATTEST;  // Table 2:131  /* Interface */

typedef union
{  // Table 2:132
    MSSIMS_CERTIFY_INFO           certify;
    MSSIMS_CREATION_INFO          creation;
    MSSIMS_QUOTE_INFO             quote;
    MSSIMS_COMMAND_AUDIT_INFO     commandAudit;
    MSSIMS_SESSION_AUDIT_INFO     sessionAudit;
    MSSIMS_TIME_ATTEST_INFO       time;
    MSSIMS_NV_CERTIFY_INFO        nv;
    MSSIMS_NV_DIGEST_CERTIFY_INFO nvDigest;
} MSSIMU_ATTEST; /* Structure */

typedef struct
{  // Table 2:133
    MSSIM_CONSTANTS32 magic;
    MSSIMI_ST_ATTEST  type;
    MSSIM2B_NAME      qualifiedSigner;
    MSSIM2B_DATA      extraData;
    MSSIMS_CLOCK_INFO clockInfo;
    UINT64          firmwareVersion;
    MSSIMU_ATTEST     attested;
} MSSIMS_ATTEST; /* Structure */

typedef union
{  // Table 2:134
    struct
    {
        UINT16 size;
        BYTE   attestationData[sizeof(MSSIMS_ATTEST)];
    } t;
    MSSIM2B b;
} MSSIM2B_ATTEST; /* Structure */

typedef struct
{  // Table 2:135
    MSSIMI_SH_AUTH_SESSION sessionHandle;
    MSSIM2B_NONCE          nonce;
    MSSIMA_SESSION         sessionAttributes;
    MSSIM2B_AUTH           hmac;
} MSSIMS_AUTH_COMMAND; /* Structure */

typedef struct
{  // Table 2:136
    MSSIM2B_NONCE  nonce;
    MSSIMA_SESSION sessionAttributes;
    MSSIM2B_AUTH   hmac;
} MSSIMS_AUTH_RESPONSE; /* Structure */

typedef MSSIM_KEY_BITS MSSIMI_TDES_KEY_BITS;  // Table 2:137  /* Interface */

typedef MSSIM_KEY_BITS MSSIMI_AES_KEY_BITS;  // Table 2:137  /* Interface */

typedef MSSIM_KEY_BITS MSSIMI_SM4_KEY_BITS;  // Table 2:137  /* Interface */

typedef MSSIM_KEY_BITS MSSIMI_CAMELLIA_KEY_BITS;  // Table 2:137  /* Interface */

typedef union
{  // Table 2:138
#if ALG_TDES
    MSSIMI_TDES_KEY_BITS tdes;
#endif  // ALG_TDES
#if ALG_AES
    MSSIMI_AES_KEY_BITS aes;
#endif  // ALG_AES
#if ALG_SM4
    MSSIMI_SM4_KEY_BITS sm4;
#endif  // ALG_SM4
#if ALG_CAMELLIA
    MSSIMI_CAMELLIA_KEY_BITS camellia;
#endif  // ALG_CAMELLIA
    MSSIM_KEY_BITS sym;
#if ALG_XOR
    MSSIMI_ALG_HASH xor ;
#endif               // ALG_XOR
} MSSIMU_SYM_KEY_BITS; /* Structure */

typedef union
{  // Table 2:139
#if ALG_TDES
    MSSIMI_ALG_SYM_MODE tdes;
#endif  // ALG_TDES
#if ALG_AES
    MSSIMI_ALG_SYM_MODE aes;
#endif  // ALG_AES
#if ALG_SM4
    MSSIMI_ALG_SYM_MODE sm4;
#endif  // ALG_SM4
#if ALG_CAMELLIA
    MSSIMI_ALG_SYM_MODE camellia;
#endif  // ALG_CAMELLIA
    MSSIMI_ALG_SYM_MODE sym;
} MSSIMU_SYM_MODE; /* Structure */

typedef struct
{  // Table 2:141
    MSSIMI_ALG_SYM      algorithm;
    MSSIMU_SYM_KEY_BITS keyBits;
    MSSIMU_SYM_MODE     mode;
} MSSIMT_SYM_DEF; /* Structure */

typedef struct
{  // Table 2:142
    MSSIMI_ALG_SYM_OBJECT algorithm;
    MSSIMU_SYM_KEY_BITS   keyBits;
    MSSIMU_SYM_MODE       mode;
} MSSIMT_SYM_DEF_OBJECT; /* Structure */

typedef union
{  // Table 2:143
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_SYM_KEY_BYTES];
    } t;
    MSSIM2B b;
} MSSIM2B_SYM_KEY; /* Structure */

typedef struct
{  // Table 2:144
    MSSIMT_SYM_DEF_OBJECT sym;
} MSSIMS_SYMCIPHER_PARMS; /* Structure */

typedef union
{  // Table 2:145
    struct
    {
        UINT16 size;
        BYTE   buffer[LABEL_MAX_BUFFER];
    } t;
    MSSIM2B b;
} MSSIM2B_LABEL; /* Structure */

typedef struct
{  // Table 2:146
    MSSIM2B_LABEL label;
    MSSIM2B_LABEL context;
} MSSIMS_DERIVE; /* Structure */

typedef union
{  // Table 2:147
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(MSSIMS_DERIVE)];
    } t;
    MSSIM2B b;
} MSSIM2B_DERIVE; /* Structure */

typedef union
{  // Table 2:148
    BYTE        create[MAX_SYM_DATA];
    MSSIMS_DERIVE derive;
} MSSIMU_SENSITIVE_CREATE; /* Structure */

typedef union
{  // Table 2:149
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(MSSIMU_SENSITIVE_CREATE)];
    } t;
    MSSIM2B b;
} MSSIM2B_SENSITIVE_DATA; /* Structure */

typedef struct
{  // Table 2:150
    MSSIM2B_AUTH           userAuth;
    MSSIM2B_SENSITIVE_DATA data;
} MSSIMS_SENSITIVE_CREATE; /* Structure */

typedef struct
{  // Table 2:151
    UINT16                size;
    MSSIMS_SENSITIVE_CREATE sensitive;
} MSSIM2B_SENSITIVE_CREATE; /* Structure */

typedef struct
{  // Table 2:152
    MSSIMI_ALG_HASH hashAlg;
} MSSIMS_SCHEME_HASH; /* Structure */

typedef struct
{  // Table 2:153
    MSSIMI_ALG_HASH hashAlg;
    UINT16        count;
} MSSIMS_SCHEME_ECDAA; /* Structure */

typedef MSSIM_ALG_ID MSSIMI_ALG_KEYEDHASH_SCHEME;

// Table 2:155 - Definition of Types for HMAC_SIG_SCHEME
typedef MSSIMS_SCHEME_HASH MSSIMS_SCHEME_HMAC;

typedef struct
{  // Table 2:156
    MSSIMI_ALG_HASH hashAlg;
    MSSIMI_ALG_KDF  kdf;
} MSSIMS_SCHEME_XOR; /* Structure */

typedef union
{  // Table 2:157
#if ALG_HMAC
    MSSIMS_SCHEME_HMAC hmac;
#endif  // ALG_HMAC
#if ALG_XOR
    MSSIMS_SCHEME_XOR xor ;
#endif                   // ALG_XOR
} MSSIMU_SCHEME_KEYEDHASH; /* Structure */

typedef struct
{  // Table 2:158
    MSSIMI_ALG_KEYEDHASH_SCHEME scheme;
    MSSIMU_SCHEME_KEYEDHASH     details;
} MSSIMT_KEYEDHASH_SCHEME; /* Structure */

// Table 2:159 - Definition of Types for RSA Signature Schemes
typedef MSSIMS_SCHEME_HASH MSSIMS_SIG_SCHEME_RSASSA;
typedef MSSIMS_SCHEME_HASH MSSIMS_SIG_SCHEME_RSAPSS;

// Table 2:160 - Definition of Types for ECC Signature Schemes
typedef MSSIMS_SCHEME_HASH  MSSIMS_SIG_SCHEME_ECDSA;
typedef MSSIMS_SCHEME_HASH  MSSIMS_SIG_SCHEME_SM2;
typedef MSSIMS_SCHEME_HASH  MSSIMS_SIG_SCHEME_ECSCHNORR;
typedef MSSIMS_SCHEME_ECDAA MSSIMS_SIG_SCHEME_ECDAA;

typedef union
{  // Table 2:161
#if ALG_ECC
    MSSIMS_SIG_SCHEME_ECDAA ecdaa;
#endif  // ALG_ECC
#if ALG_RSASSA
    MSSIMS_SIG_SCHEME_RSASSA rsassa;
#endif  // ALG_RSASSA
#if ALG_RSAPSS
    MSSIMS_SIG_SCHEME_RSAPSS rsapss;
#endif  // ALG_RSAPSS
#if ALG_ECDSA
    MSSIMS_SIG_SCHEME_ECDSA ecdsa;
#endif  // ALG_ECDSA
#if ALG_SM2
    MSSIMS_SIG_SCHEME_SM2 sm2;
#endif  // ALG_SM2
#if ALG_ECSCHNORR
    MSSIMS_SIG_SCHEME_ECSCHNORR ecschnorr;
#endif  // ALG_ECSCHNORR
#if ALG_HMAC
    MSSIMS_SCHEME_HMAC hmac;
#endif  // ALG_HMAC
    MSSIMS_SCHEME_HASH any;
} MSSIMU_SIG_SCHEME; /* Structure */

typedef struct
{  // Table 2:162
    MSSIMI_ALG_SIG_SCHEME scheme;
    MSSIMU_SIG_SCHEME     details;
} MSSIMT_SIG_SCHEME; /* Structure */

// Table 2:163 - Definition of Types for Encryption Schemes
typedef MSSIMS_SCHEME_HASH MSSIMS_ENC_SCHEME_OAEP;
typedef MSSIMS_EMPTY       MSSIMS_ENC_SCHEME_RSAES;

// Table 2:164 - Definition of Types for ECC Key Exchange
typedef MSSIMS_SCHEME_HASH MSSIMS_KEY_SCHEME_ECDH;
typedef MSSIMS_SCHEME_HASH MSSIMS_KEY_SCHEME_ECMQV;

// Table 2:165 - Definition of Types for KDF Schemes
typedef MSSIMS_SCHEME_HASH MSSIMS_KDF_SCHEME_MGF1;
typedef MSSIMS_SCHEME_HASH MSSIMS_KDF_SCHEME_KDF1_SP800_56A;
typedef MSSIMS_SCHEME_HASH MSSIMS_KDF_SCHEME_KDF2;
typedef MSSIMS_SCHEME_HASH MSSIMS_KDF_SCHEME_KDF1_SP800_108;

typedef union
{  // Table 2:166
#if ALG_MGF1
    MSSIMS_KDF_SCHEME_MGF1 mgf1;
#endif  // ALG_MGF1
#if ALG_KDF1_SP800_56A
    MSSIMS_KDF_SCHEME_KDF1_SP800_56A kdf1_sp800_56a;
#endif  // ALG_KDF1_SP800_56A
#if ALG_KDF2
    MSSIMS_KDF_SCHEME_KDF2 kdf2;
#endif  // ALG_KDF2
#if ALG_KDF1_SP800_108
    MSSIMS_KDF_SCHEME_KDF1_SP800_108 kdf1_sp800_108;
#endif  // ALG_KDF1_SP800_108
    MSSIMS_SCHEME_HASH anyKdf;
} MSSIMU_KDF_SCHEME; /* Structure */

typedef struct
{  // Table 2:167
    MSSIMI_ALG_KDF    scheme;
    MSSIMU_KDF_SCHEME details;
} MSSIMT_KDF_SCHEME; /* Structure */

typedef MSSIM_ALG_ID MSSIMI_ALG_ASYM_SCHEME;  // Table 2:168  /* Interface */

typedef union
{  // Table 2:169
#if ALG_ECDH
    MSSIMS_KEY_SCHEME_ECDH ecdh;
#endif  // ALG_ECDH
#if ALG_ECMQV
    MSSIMS_KEY_SCHEME_ECMQV ecmqv;
#endif  // ALG_ECMQV
#if ALG_ECC
    MSSIMS_SIG_SCHEME_ECDAA ecdaa;
#endif  // ALG_ECC
#if ALG_RSASSA
    MSSIMS_SIG_SCHEME_RSASSA rsassa;
#endif  // ALG_RSASSA
#if ALG_RSAPSS
    MSSIMS_SIG_SCHEME_RSAPSS rsapss;
#endif  // ALG_RSAPSS
#if ALG_ECDSA
    MSSIMS_SIG_SCHEME_ECDSA ecdsa;
#endif  // ALG_ECDSA
#if ALG_SM2
    MSSIMS_SIG_SCHEME_SM2 sm2;
#endif  // ALG_SM2
#if ALG_ECSCHNORR
    MSSIMS_SIG_SCHEME_ECSCHNORR ecschnorr;
#endif  // ALG_ECSCHNORR
#if ALG_RSAES
    MSSIMS_ENC_SCHEME_RSAES rsaes;
#endif  // ALG_RSAES
#if ALG_OAEP
    MSSIMS_ENC_SCHEME_OAEP oaep;
#endif  // ALG_OAEP
    MSSIMS_SCHEME_HASH anySig;
} MSSIMU_ASYM_SCHEME; /* Structure */

typedef struct
{  // Table 2:170
    MSSIMI_ALG_ASYM_SCHEME scheme;
    MSSIMU_ASYM_SCHEME     details;
} MSSIMT_ASYM_SCHEME; /* Structure */

typedef MSSIM_ALG_ID MSSIMI_ALG_RSA_SCHEME;  // Table 2:171  /* Interface */

typedef struct
{  // Table 2:172
    MSSIMI_ALG_RSA_SCHEME scheme;
    MSSIMU_ASYM_SCHEME    details;
} MSSIMT_RSA_SCHEME; /* Structure */

typedef MSSIM_ALG_ID MSSIMI_ALG_RSA_DECRYPT;  // Table 2:173  /* Interface */

typedef struct
{  // Table 2:174
    MSSIMI_ALG_RSA_DECRYPT scheme;
    MSSIMU_ASYM_SCHEME     details;
} MSSIMT_RSA_DECRYPT; /* Structure */

typedef union
{  // Table 2:175
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_RSA_KEY_BYTES];
    } t;
    MSSIM2B b;
} MSSIM2B_PUBLIC_KEY_RSA; /* Structure */

typedef MSSIM_KEY_BITS MSSIMI_RSA_KEY_BITS;  // Table 2:176  /* Interface */

typedef union
{  // Table 2:177
    struct
    {
        UINT16 size;
        BYTE   buffer[RSA_PRIVATE_SIZE];
    } t;
    MSSIM2B b;
} MSSIM2B_PRIVATE_KEY_RSA; /* Structure */

typedef union
{  // Table 2:178
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_ECC_KEY_BYTES];
    } t;
    MSSIM2B b;
} MSSIM2B_ECC_PARAMETER; /* Structure */

typedef struct
{  // Table 2:179
    MSSIM2B_ECC_PARAMETER x;
    MSSIM2B_ECC_PARAMETER y;
} MSSIMS_ECC_POINT; /* Structure */

typedef struct
{  // Table 2:180
    UINT16         size;
    MSSIMS_ECC_POINT point;
} MSSIM2B_ECC_POINT; /* Structure */

typedef MSSIM_ALG_ID    MSSIMI_ALG_ECC_SCHEME;  // Table 2:181  /* Interface */

typedef MSSIM_ECC_CURVE MSSIMI_ECC_CURVE;  // Table 2:182  /* Interface */

typedef struct
{  // Table 2:183
    MSSIMI_ALG_ECC_SCHEME scheme;
    MSSIMU_ASYM_SCHEME    details;
} MSSIMT_ECC_SCHEME; /* Structure */

typedef struct
{  // Table 2:184
    MSSIM_ECC_CURVE       curveID;
    UINT16              keySize;
    MSSIMT_KDF_SCHEME     kdf;
    MSSIMT_ECC_SCHEME     sign;
    MSSIM2B_ECC_PARAMETER p;
    MSSIM2B_ECC_PARAMETER a;
    MSSIM2B_ECC_PARAMETER b;
    MSSIM2B_ECC_PARAMETER gX;
    MSSIM2B_ECC_PARAMETER gY;
    MSSIM2B_ECC_PARAMETER n;
    MSSIM2B_ECC_PARAMETER h;
} MSSIMS_ALGORITHM_DETAIL_ECC; /* Structure */

typedef struct
{  // Table 2:185
    MSSIMI_ALG_HASH        hash;
    MSSIM2B_PUBLIC_KEY_RSA sig;
} MSSIMS_SIGNATURE_RSA; /* Structure */

// Table 2:186 - Definition of Types for Signature
typedef MSSIMS_SIGNATURE_RSA MSSIMS_SIGNATURE_RSASSA;
typedef MSSIMS_SIGNATURE_RSA MSSIMS_SIGNATURE_RSAPSS;

typedef struct
{  // Table 2:187
    MSSIMI_ALG_HASH       hash;
    MSSIM2B_ECC_PARAMETER signatureR;
    MSSIM2B_ECC_PARAMETER signatureS;
} MSSIMS_SIGNATURE_ECC; /* Structure */

// Table 2:188 - Definition of Types for MSSIMS_SIGNATURE_ECC
typedef MSSIMS_SIGNATURE_ECC MSSIMS_SIGNATURE_ECDAA;
typedef MSSIMS_SIGNATURE_ECC MSSIMS_SIGNATURE_ECDSA;
typedef MSSIMS_SIGNATURE_ECC MSSIMS_SIGNATURE_SM2;
typedef MSSIMS_SIGNATURE_ECC MSSIMS_SIGNATURE_ECSCHNORR;

typedef union
{  // Table 2:189
#if ALG_ECC
    MSSIMS_SIGNATURE_ECDAA ecdaa;
#endif  // ALG_ECC
#if ALG_RSA
    MSSIMS_SIGNATURE_RSASSA rsassa;
#endif  // ALG_RSA
#if ALG_RSA
    MSSIMS_SIGNATURE_RSAPSS rsapss;
#endif  // ALG_RSA
#if ALG_ECC
    MSSIMS_SIGNATURE_ECDSA ecdsa;
#endif  // ALG_ECC
#if ALG_ECC
    MSSIMS_SIGNATURE_SM2 sm2;
#endif  // ALG_ECC
#if ALG_ECC
    MSSIMS_SIGNATURE_ECSCHNORR ecschnorr;
#endif  // ALG_ECC
#if ALG_HMAC
    MSSIMT_HA hmac;
#endif  // ALG_HMAC
    MSSIMS_SCHEME_HASH any;
} MSSIMU_SIGNATURE; /* Structure */

typedef struct
{  // Table 2:190
    MSSIMI_ALG_SIG_SCHEME sigAlg;
    MSSIMU_SIGNATURE      signature;
} MSSIMT_SIGNATURE; /* Structure */

typedef union
{  // Table 2:191
#if ALG_ECC
    BYTE ecc[sizeof(MSSIMS_ECC_POINT)];
#endif  // ALG_ECC
#if ALG_RSA
    BYTE rsa[MAX_RSA_KEY_BYTES];
#endif  // ALG_RSA
#if ALG_SYMCIPHER
    BYTE symmetric[sizeof(MSSIM2B_DIGEST)];
#endif  // ALG_SYMCIPHER
#if ALG_KEYEDHASH
    BYTE keyedHash[sizeof(MSSIM2B_DIGEST)];
#endif                   // ALG_KEYEDHASH
} MSSIMU_ENCRYPTED_SECRET; /* Structure */

typedef union
{  // Table 2:192
    struct
    {
        UINT16 size;
        BYTE   secret[sizeof(MSSIMU_ENCRYPTED_SECRET)];
    } t;
    MSSIM2B b;
} MSSIM2B_ENCRYPTED_SECRET; /* Structure */

typedef MSSIM_ALG_ID MSSIMI_ALG_PUBLIC;  // Table 2:193  /* Interface */

typedef union
{  // Table 2:194
#if ALG_KEYEDHASH
    MSSIM2B_DIGEST keyedHash;
#endif  // ALG_KEYEDHASH
#if ALG_SYMCIPHER
    MSSIM2B_DIGEST sym;
#endif  // ALG_SYMCIPHER
#if ALG_RSA
    MSSIM2B_PUBLIC_KEY_RSA rsa;
#endif  // ALG_RSA
#if ALG_ECC
    MSSIMS_ECC_POINT ecc;
#endif  // ALG_ECC
    MSSIMS_DERIVE derive;
} MSSIMU_PUBLIC_ID; /* Structure */

typedef struct
{  // Table 2:195
    MSSIMT_KEYEDHASH_SCHEME scheme;
} MSSIMS_KEYEDHASH_PARMS; /* Structure */

typedef struct
{  // Table 2:196
    MSSIMT_SYM_DEF_OBJECT symmetric;
    MSSIMT_ASYM_SCHEME    scheme;
} MSSIMS_ASYM_PARMS; /* Structure */

typedef struct
{  // Table 2:197
    MSSIMT_SYM_DEF_OBJECT symmetric;
    MSSIMT_RSA_SCHEME     scheme;
    MSSIMI_RSA_KEY_BITS   keyBits;
    UINT32              exponent;
} MSSIMS_RSA_PARMS; /* Structure */

typedef struct
{  // Table 2:198
    MSSIMT_SYM_DEF_OBJECT symmetric;
    MSSIMT_ECC_SCHEME     scheme;
    MSSIMI_ECC_CURVE      curveID;
    MSSIMT_KDF_SCHEME     kdf;
} MSSIMS_ECC_PARMS; /* Structure */

typedef union
{  // Table 2:199
#if ALG_KEYEDHASH
    MSSIMS_KEYEDHASH_PARMS keyedHashDetail;
#endif  // ALG_KEYEDHASH
#if ALG_SYMCIPHER
    MSSIMS_SYMCIPHER_PARMS symDetail;
#endif  // ALG_SYMCIPHER
#if ALG_RSA
    MSSIMS_RSA_PARMS rsaDetail;
#endif  // ALG_RSA
#if ALG_ECC
    MSSIMS_ECC_PARMS eccDetail;
#endif  // ALG_ECC
    MSSIMS_ASYM_PARMS asymDetail;
} MSSIMU_PUBLIC_PARMS; /* Structure */

typedef struct
{  // Table 2:200
    MSSIMI_ALG_PUBLIC   type;
    MSSIMU_PUBLIC_PARMS parameters;
} MSSIMT_PUBLIC_PARMS; /* Structure */

typedef struct
{  // Table 2:201
    MSSIMI_ALG_PUBLIC   type;
    MSSIMI_ALG_HASH     nameAlg;
    MSSIMA_OBJECT       objectAttributes;
    MSSIM2B_DIGEST      authPolicy;
    MSSIMU_PUBLIC_PARMS parameters;
    MSSIMU_PUBLIC_ID    unique;
} MSSIMT_PUBLIC; /* Structure */

typedef struct
{  // Table 2:202
    UINT16      size;
    MSSIMT_PUBLIC publicArea;
} MSSIM2B_PUBLIC; /* Structure */

typedef union
{  // Table 2:203
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(MSSIMT_PUBLIC)];
    } t;
    MSSIM2B b;
} MSSIM2B_TEMPLATE; /* Structure */

typedef union
{  // Table 2:204
    struct
    {
        UINT16 size;
        BYTE   buffer[PRIVATE_VENDOR_SPECIFIC_BYTES];
    } t;
    MSSIM2B b;
} MSSIM2B_PRIVATE_VENDOR_SPECIFIC; /* Structure */

typedef union
{  // Table 2:205
#if ALG_RSA
    MSSIM2B_PRIVATE_KEY_RSA rsa;
#endif  // ALG_RSA
#if ALG_ECC
    MSSIM2B_ECC_PARAMETER ecc;
#endif  // ALG_ECC
#if ALG_KEYEDHASH
    MSSIM2B_SENSITIVE_DATA bits;
#endif  // ALG_KEYEDHASH
#if ALG_SYMCIPHER
    MSSIM2B_SYM_KEY sym;
#endif  // ALG_SYMCIPHER
    MSSIM2B_PRIVATE_VENDOR_SPECIFIC any;
} MSSIMU_SENSITIVE_COMPOSITE; /* Structure */

typedef struct
{  // Table 2:206
    MSSIMI_ALG_PUBLIC          sensitiveType;
    MSSIM2B_AUTH               authValue;
    MSSIM2B_DIGEST             seedValue;
    MSSIMU_SENSITIVE_COMPOSITE sensitive;
} MSSIMT_SENSITIVE; /* Structure */

typedef struct
{  // Table 2:207
    UINT16         size;
    MSSIMT_SENSITIVE sensitiveArea;
} MSSIM2B_SENSITIVE; /* Structure */

typedef struct
{  // Table 2:208
    MSSIM2B_DIGEST    integrityOuter;
    MSSIM2B_DIGEST    integrityInner;
    MSSIM2B_SENSITIVE sensitive;
} _MSSIMPRIVATE; /* Structure */

typedef union
{  // Table 2:209
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(_MSSIMPRIVATE)];
    } t;
    MSSIM2B b;
} MSSIM2B_PRIVATE; /* Structure */

typedef struct
{  // Table 2:210
    MSSIM2B_DIGEST integrityHMAC;
    MSSIM2B_DIGEST encIdentity;
} MSSIMS_ID_OBJECT; /* Structure */

typedef union
{  // Table 2:211
    struct
    {
        UINT16 size;
        BYTE   credential[sizeof(MSSIMS_ID_OBJECT)];
    } t;
    MSSIM2B b;
} MSSIM2B_ID_OBJECT; /* Structure */

#define TYPE_OF_MSSIM_NV_INDEX      UINT32
#define MSSIM_NV_INDEX_TO_UINT32(a) (*((UINT32*)&(a)))
#define UINT32_TO_MSSIM_NV_INDEX(a) (*((MSSIM_NV_INDEX*)&(a)))
#define MSSIM_NV_INDEX_TO_BYTE_ARRAY(i, a) \
  UINT32_TO_BYTE_ARRAY((MSSIM_NV_INDEX_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIM_NV_INDEX(i, a)  \
  {                                       \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a);   \
    i        = UINT32_TO_MSSIM_NV_INDEX(x); \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIM_NV_INDEX
{  // Table 2:212
    unsigned index : 24;
    unsigned RH_NV : 8;
} MSSIM_NV_INDEX; /* Bits */
// This is the initializer for a MSSIM_NV_INDEX structure
#  define MSSIM_NV_INDEX_INITIALIZER(index, rh_nv) \
    {                                            \
      index, rh_nv                               \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:212 MSSIM_NV_INDEX using bit masking
typedef UINT32 MSSIM_NV_INDEX;
#  define TYPE_OF_MSSIM_NV_INDEX     UINT32
#  define MSSIM_NV_INDEX_index_SHIFT 0
#  define MSSIM_NV_INDEX_index       ((MSSIM_NV_INDEX)0xffffff << 0)
#  define MSSIM_NV_INDEX_RH_NV_SHIFT 24
#  define MSSIM_NV_INDEX_RH_NV       ((MSSIM_NV_INDEX)0xff << 24)
//  This is the initializer for a MSSIM_NV_INDEX bit array.
#  define MSSIM_NV_INDEX_INITIALIZER(index, rh_nv) \
    (MSSIM_NV_INDEX)((index << 0) + (rh_nv << 24))
#endif  // USE_BIT_FIELD_STRUCTURES

// Table 2:213 - Definition of MSSIM_NT Constants
typedef UINT32 MSSIM_NT;
#define TYPE_OF_MSSIM_NT  UINT32
#define MSSIM_NT_ORDINARY (MSSIM_NT)(0x0)
#define MSSIM_NT_COUNTER  (MSSIM_NT)(0x1)
#define MSSIM_NT_BITS     (MSSIM_NT)(0x2)
#define MSSIM_NT_EXTEND   (MSSIM_NT)(0x4)
#define MSSIM_NT_PIN_FAIL (MSSIM_NT)(0x8)
#define MSSIM_NT_PIN_PASS (MSSIM_NT)(0x9)

typedef struct
{  // Table 2:214
    UINT32 pinCount;
    UINT32 pinLimit;
} MSSIMS_NV_PIN_COUNTER_PARAMETERS; /* Structure */

#define TYPE_OF_MSSIMA_NV             UINT32
#define MSSIMA_NV_TO_UINT32(a)        (*((UINT32*)&(a)))
#define UINT32_TO_MSSIMA_NV(a)        (*((MSSIMA_NV*)&(a)))
#define MSSIMA_NV_TO_BYTE_ARRAY(i, a) UINT32_TO_BYTE_ARRAY((MSSIMA_NV_TO_UINT32(i)), (a))
#define BYTE_ARRAY_TO_MSSIMA_NV(i, a)     \
  {                                     \
    UINT32 x = BYTE_ARRAY_TO_UINT32(a); \
    i        = UINT32_TO_MSSIMA_NV(x);    \
  }
#if USE_BIT_FIELD_STRUCTURES
typedef struct MSSIMA_NV
{  // Table 2:215
    unsigned PPWRITE             : 1;
    unsigned OWNERWRITE          : 1;
    unsigned AUTHWRITE           : 1;
    unsigned POLICYWRITE         : 1;
    unsigned MSSIM_NT              : 4;
    unsigned Reserved_bits_at_8  : 2;
    unsigned POLICY_DELETE       : 1;
    unsigned WRITELOCKED         : 1;
    unsigned WRITEALL            : 1;
    unsigned WRITEDEFINE         : 1;
    unsigned WRITE_STCLEAR       : 1;
    unsigned GLOBALLOCK          : 1;
    unsigned PPREAD              : 1;
    unsigned OWNERREAD           : 1;
    unsigned AUTHREAD            : 1;
    unsigned POLICYREAD          : 1;
    unsigned Reserved_bits_at_20 : 5;
    unsigned NO_DA               : 1;
    unsigned ORDERLY             : 1;
    unsigned CLEAR_STCLEAR       : 1;
    unsigned READLOCKED          : 1;
    unsigned WRITTEN             : 1;
    unsigned PLATFORMCREATE      : 1;
    unsigned READ_STCLEAR        : 1;
} MSSIMA_NV; /* Bits */
// This is the initializer for a MSSIMA_NV structure
#  define MSSIMA_NV_INITIALIZER(ppwrite,                                               \
                              ownerwrite,                                            \
                              authwrite,                                             \
                              policywrite,                                           \
                              tpm_nt,                                                \
                              bits_at_8,                                             \
                              policy_delete,                                         \
                              writelocked,                                           \
                              writeall,                                              \
                              writedefine,                                           \
                              write_stclear,                                         \
                              globallock,                                            \
                              ppread,                                                \
                              ownerread,                                             \
                              authread,                                              \
                              policyread,                                            \
                              bits_at_20,                                            \
                              no_da,                                                 \
                              orderly,                                               \
                              clear_stclear,                                         \
                              readlocked,                                            \
                              written,                                               \
                              platformcreate,                                        \
                              read_stclear)                                          \
    {                                                                                \
      ppwrite, ownerwrite, authwrite, policywrite, tpm_nt, bits_at_8, policy_delete, \
          writelocked, writeall, writedefine, write_stclear, globallock, ppread,     \
          ownerread, authread, policyread, bits_at_20, no_da, orderly,               \
          clear_stclear, readlocked, written, platformcreate, read_stclear           \
    }
#else  // USE_BIT_FIELD_STRUCTURES
// This implements Table 2:215 MSSIMA_NV using bit masking
typedef UINT32 MSSIMA_NV;
#  define TYPE_OF_MSSIMA_NV        UINT32
#  define MSSIMA_NV_PPWRITE        ((MSSIMA_NV)1 << 0)
#  define MSSIMA_NV_OWNERWRITE     ((MSSIMA_NV)1 << 1)
#  define MSSIMA_NV_AUTHWRITE      ((MSSIMA_NV)1 << 2)
#  define MSSIMA_NV_POLICYWRITE    ((MSSIMA_NV)1 << 3)
#  define MSSIMA_NV_MSSIM_NT_SHIFT   4
#  define MSSIMA_NV_MSSIM_NT         ((MSSIMA_NV)0xf << 4)
#  define MSSIMA_NV_POLICY_DELETE  ((MSSIMA_NV)1 << 10)
#  define MSSIMA_NV_WRITELOCKED    ((MSSIMA_NV)1 << 11)
#  define MSSIMA_NV_WRITEALL       ((MSSIMA_NV)1 << 12)
#  define MSSIMA_NV_WRITEDEFINE    ((MSSIMA_NV)1 << 13)
#  define MSSIMA_NV_WRITE_STCLEAR  ((MSSIMA_NV)1 << 14)
#  define MSSIMA_NV_GLOBALLOCK     ((MSSIMA_NV)1 << 15)
#  define MSSIMA_NV_PPREAD         ((MSSIMA_NV)1 << 16)
#  define MSSIMA_NV_OWNERREAD      ((MSSIMA_NV)1 << 17)
#  define MSSIMA_NV_AUTHREAD       ((MSSIMA_NV)1 << 18)
#  define MSSIMA_NV_POLICYREAD     ((MSSIMA_NV)1 << 19)
#  define MSSIMA_NV_NO_DA          ((MSSIMA_NV)1 << 25)
#  define MSSIMA_NV_ORDERLY        ((MSSIMA_NV)1 << 26)
#  define MSSIMA_NV_CLEAR_STCLEAR  ((MSSIMA_NV)1 << 27)
#  define MSSIMA_NV_READLOCKED     ((MSSIMA_NV)1 << 28)
#  define MSSIMA_NV_WRITTEN        ((MSSIMA_NV)1 << 29)
#  define MSSIMA_NV_PLATFORMCREATE ((MSSIMA_NV)1 << 30)
#  define MSSIMA_NV_READ_STCLEAR   ((MSSIMA_NV)1 << 31)
//  This is the initializer for a MSSIMA_NV bit array.
#  define MSSIMA_NV_INITIALIZER(ppwrite,                                        \
                              ownerwrite,                                     \
                              authwrite,                                      \
                              policywrite,                                    \
                              tpm_nt,                                         \
                              bits_at_8,                                      \
                              policy_delete,                                  \
                              writelocked,                                    \
                              writeall,                                       \
                              writedefine,                                    \
                              write_stclear,                                  \
                              globallock,                                     \
                              ppread,                                         \
                              ownerread,                                      \
                              authread,                                       \
                              policyread,                                     \
                              bits_at_20,                                     \
                              no_da,                                          \
                              orderly,                                        \
                              clear_stclear,                                  \
                              readlocked,                                     \
                              written,                                        \
                              platformcreate,                                 \
                              read_stclear)                                   \
    (MSSIMA_NV)((ppwrite << 0) + (ownerwrite << 1) + (authwrite << 2)           \
              + (policywrite << 3) + (tpm_nt << 4) + (policy_delete << 10)    \
              + (writelocked << 11) + (writeall << 12) + (writedefine << 13)  \
              + (write_stclear << 14) + (globallock << 15) + (ppread << 16)   \
              + (ownerread << 17) + (authread << 18) + (policyread << 19)     \
              + (no_da << 25) + (orderly << 26) + (clear_stclear << 27)       \
              + (readlocked << 28) + (written << 29) + (platformcreate << 30) \
              + (read_stclear << 31))
#endif  // USE_BIT_FIELD_STRUCTURES

typedef struct
{  // Table 2:216
    MSSIMI_RH_NV_INDEX nvIndex;
    MSSIMI_ALG_HASH    nameAlg;
    MSSIMA_NV          attributes;
    MSSIM2B_DIGEST     authPolicy;
    UINT16           dataSize;
} MSSIMS_NV_PUBLIC; /* Structure */

typedef struct
{  // Table 2:217
    UINT16         size;
    MSSIMS_NV_PUBLIC nvPublic;
} MSSIM2B_NV_PUBLIC; /* Structure */

typedef union
{  // Table 2:218
    struct
    {
        UINT16 size;
        BYTE   buffer[MAX_CONTEXT_SIZE];
    } t;
    MSSIM2B b;
} MSSIM2B_CONTEXT_SENSITIVE; /* Structure */

typedef struct
{  // Table 2:219
    MSSIM2B_DIGEST            integrity;
    MSSIM2B_CONTEXT_SENSITIVE encrypted;
} MSSIMS_CONTEXT_DATA; /* Structure */

typedef union
{  // Table 2:220
    struct
    {
        UINT16 size;
        BYTE   buffer[sizeof(MSSIMS_CONTEXT_DATA)];
    } t;
    MSSIM2B b;
} MSSIM2B_CONTEXT_DATA; /* Structure */

typedef struct
{  // Table 2:221
    UINT64             sequence;
    MSSIMI_DH_SAVED      savedHandle;
    MSSIMI_RH_HIERARCHY  hierarchy;
    MSSIM2B_CONTEXT_DATA contextBlob;
} MSSIMS_CONTEXT; /* Structure */

typedef struct
{  // Table 2:223
    MSSIML_PCR_SELECTION pcrSelect;
    MSSIM2B_DIGEST       pcrDigest;
    MSSIMA_LOCALITY      locality;
    MSSIM_ALG_ID         parentNameAlg;
    MSSIM2B_NAME         parentName;
    MSSIM2B_NAME         parentQualifiedName;
    MSSIM2B_DATA         outsideInfo;
} MSSIMS_CREATION_DATA; /* Structure */

typedef struct
{  // Table 2:224
    UINT16             size;
    MSSIMS_CREATION_DATA creationData;
} MSSIM2B_CREATION_DATA; /* Structure */

// Table 2:225 - Definition of MSSIM_AT Constants
typedef UINT32 MSSIM_AT;
#define TYPE_OF_MSSIM_AT UINT32
#define MSSIM_AT_ANY     (MSSIM_AT)(0x00000000)
#define MSSIM_AT_ERROR   (MSSIM_AT)(0x00000001)
#define MSSIM_AT_PV1     (MSSIM_AT)(0x00000002)
#define MSSIM_AT_VEND    (MSSIM_AT)(0x80000000)

// Table 2:226 - Definition of MSSIM_AE Constants
typedef UINT32 MSSIM_AE;
#define TYPE_OF_MSSIM_AE UINT32
#define MSSIM_AE_NONE    (MSSIM_AE)(0x00000000)

typedef struct
{  // Table 2:227
    MSSIM_AT tag;
    UINT32 data;
} MSSIMS_AC_OUTPUT; /* Structure */

typedef struct
{  // Table 2:228
    UINT32         count;
    MSSIMS_AC_OUTPUT acCapabilities[MAX_AC_CAPABILITIES];
} MSSIML_AC_CAPABILITIES; /* Structure */

typedef struct {
    TPM2B_PRIVATE vpsPrivate;
    TPM2B_PUBLIC vpsPublic;
} VPSEntry;

typedef struct{
    MSSIMI_RH_HIERARCHY handle;
    TPMS_CONTEXT context;
} SWKEntry;

typedef union{
    MSSIM_HANDLE virtual;
    MSSIM_HANDLE physical;
} CREATED_OBJECT_HANDLE;

typedef struct{
    BOOL defined;
    BOOL fullSoftware;
    CREATED_OBJECT_HANDLE handle;
} CREATED_OBJECT;

typedef struct {
    MSSIMI_RH_HIERARCHY vEPSHandle;
    MSSIMI_RH_HIERARCHY vPPSHandle;
    MSSIMI_RH_HIERARCHY vSPSHandle;
    VSPK_STRUCTURE pVSPKHandle;
    CREATED_OBJECT objectHandles[MAX_LOADED_OBJECTS];
} HandleMap;

#endif  // _MSSIM_TYPES_H_
