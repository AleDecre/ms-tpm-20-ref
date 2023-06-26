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
 *  Created by NewMarshal; Version 1.4 Apr 7, 2019
 *  Date: Mar  6, 2020  Time: 01:50:10PM
 */

#ifndef _TABLE_MARSHAL_DEFINES_H_
#define _TABLE_MARSHAL_DEFINES_H_

#define NULL_SHIFT 15
#define NULL_FLAG  (1 << NULL_SHIFT)

// The range macro processes a min, max value and produces a values that is used in
// the computation to see if something is within a range. The max value is (max-min).
// This lets the check for something ('val') within a range become:
//   if((val - min) <= max) // passes if in range
//   if((val - min) > max) // passes if not in range
// This works because all values are converted to UINT32 values before the compare.
// For (val - min), all values greater than or equal to val will become positive
// values with a value equal to 'min' being zero. This means that in an unsigned
// compare against 'max,' any value that is outside the range will appear to be a
// number greater than max. The benefit of this operation is that this will work even
// if the input value is a signed number as long as the input is sign extended.

#define RANGE(_min_, _max_, _base_) (UINT32) _min_, (UINT32)((_base_)(_max_ - _min_))

// This macro is like the offsetof macro but, instead of computing the offset of
// a structure element, it computes the stride between elements that are in a
// structure array. This is used instead of sizeof() because the sizeof() operator on
// a structure can return an implementation dependent value.
#define STRIDE(s) ((UINT16)(size_t) & (((s*)0)[1]))

#define MARSHAL_REF(TYPE) ((UINT16)(offsetof(MARSHAL_DATA, TYPE)))

// This macro creates the entry in the array lookup table
#define ARRAY_MARSHAL_ENTRY(TYPE)                             \
  {                                                           \
    (marshalIndex_t) TYPE##_MARSHAL_REF, (UINT16)STRIDE(TYPE) \
  }

// Defines for array lookup
#define UINT8_ARRAY_MARSHAL_INDEX                  0   // 0x00
#define MSSIM_CC_ARRAY_MARSHAL_INDEX                 1   // 0x01
#define MSSIMA_CC_ARRAY_MARSHAL_INDEX                2   // 0x02
#define MSSIM_ALG_ID_ARRAY_MARSHAL_INDEX             3   // 0x03
#define MSSIM_HANDLE_ARRAY_MARSHAL_INDEX             4   // 0x04
#define MSSIM2B_DIGEST_ARRAY_MARSHAL_INDEX           5   // 0x05
#define MSSIMT_HA_ARRAY_MARSHAL_INDEX                6   // 0x06
#define MSSIMS_PCR_SELECTION_ARRAY_MARSHAL_INDEX     7   // 0x07
#define MSSIMS_ALG_PROPERTY_ARRAY_MARSHAL_INDEX      8   // 0x08
#define MSSIMS_TAGGED_PROPERTY_ARRAY_MARSHAL_INDEX   9   // 0x09
#define MSSIMS_TAGGED_PCR_SELECT_ARRAY_MARSHAL_INDEX 10  // 0x0A
#define MSSIM_ECC_CURVE_ARRAY_MARSHAL_INDEX          11  // 0x0B
#define MSSIMS_TAGGED_POLICY_ARRAY_MARSHAL_INDEX     12  // 0x0C
#define MSSIMS_ACT_DATA_ARRAY_MARSHAL_INDEX          13  // 0x0D
#define MSSIMS_AC_OUTPUT_ARRAY_MARSHAL_INDEX         14  // 0x0E

// Defines for referencing a type by offset
#define UINT8_MARSHAL_REF                  ((UINT16)(offsetof(MarshalData_st, UINT8_DATA)))
#define BYTE_MARSHAL_REF                   UINT8_MARSHAL_REF
#define MSSIM_HT_MARSHAL_REF                 UINT8_MARSHAL_REF
#define MSSIMA_LOCALITY_MARSHAL_REF          UINT8_MARSHAL_REF
#define UINT16_MARSHAL_REF                 ((UINT16)(offsetof(MarshalData_st, UINT16_DATA)))
#define MSSIM_KEY_SIZE_MARSHAL_REF           UINT16_MARSHAL_REF
#define MSSIM_KEY_BITS_MARSHAL_REF           UINT16_MARSHAL_REF
#define MSSIM_ALG_ID_MARSHAL_REF             UINT16_MARSHAL_REF
#define MSSIM_ST_MARSHAL_REF                 UINT16_MARSHAL_REF
#define UINT32_MARSHAL_REF                 ((UINT16)(offsetof(MarshalData_st, UINT32_DATA)))
#define MSSIM_ALGORITHM_ID_MARSHAL_REF       UINT32_MARSHAL_REF
#define MSSIM_MODIFIER_INDICATOR_MARSHAL_REF UINT32_MARSHAL_REF
#define MSSIM_AUTHORIZATION_SIZE_MARSHAL_REF UINT32_MARSHAL_REF
#define MSSIM_PARAMETER_SIZE_MARSHAL_REF     UINT32_MARSHAL_REF
#define MSSIM_SPEC_MARSHAL_REF               UINT32_MARSHAL_REF
#define MSSIM_CONSTANTS32_MARSHAL_REF        UINT32_MARSHAL_REF
#define MSSIM_CC_MARSHAL_REF                 UINT32_MARSHAL_REF
#define MSSIM_RC_MARSHAL_REF                 UINT32_MARSHAL_REF
#define MSSIM_PT_MARSHAL_REF                 UINT32_MARSHAL_REF
#define MSSIM_PT_PCR_MARSHAL_REF             UINT32_MARSHAL_REF
#define MSSIM_PS_MARSHAL_REF                 UINT32_MARSHAL_REF
#define MSSIM_HANDLE_MARSHAL_REF             UINT32_MARSHAL_REF
#define MSSIM_RH_MARSHAL_REF                 UINT32_MARSHAL_REF
#define MSSIM_HC_MARSHAL_REF                 UINT32_MARSHAL_REF
#define MSSIMA_PERMANENT_MARSHAL_REF         UINT32_MARSHAL_REF
#define MSSIMA_STARTUP_CLEAR_MARSHAL_REF     UINT32_MARSHAL_REF
#define MSSIMA_MEMORY_MARSHAL_REF            UINT32_MARSHAL_REF
#define MSSIMA_CC_MARSHAL_REF                UINT32_MARSHAL_REF
#define MSSIMA_MODES_MARSHAL_REF             UINT32_MARSHAL_REF
#define MSSIMA_X509_KEY_USAGE_MARSHAL_REF    UINT32_MARSHAL_REF
#define MSSIM_NV_INDEX_MARSHAL_REF           UINT32_MARSHAL_REF
#define MSSIM_AE_MARSHAL_REF                 UINT32_MARSHAL_REF
#define UINT64_MARSHAL_REF                 ((UINT16)(offsetof(MarshalData_st, UINT64_DATA)))
#define INT8_MARSHAL_REF                   ((UINT16)(offsetof(MarshalData_st, INT8_DATA)))
#define INT16_MARSHAL_REF                  ((UINT16)(offsetof(MarshalData_st, INT16_DATA)))
#define INT32_MARSHAL_REF                  ((UINT16)(offsetof(MarshalData_st, INT32_DATA)))
#define INT64_MARSHAL_REF                  ((UINT16)(offsetof(MarshalData_st, INT64_DATA)))
#define UINT0_MARSHAL_REF                  ((UINT16)(offsetof(MarshalData_st, UINT0_DATA)))
#define MSSIM_ECC_CURVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM_ECC_CURVE_DATA)))
#define MSSIM_CLOCK_ADJUST_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM_CLOCK_ADJUST_DATA)))
#define MSSIM_EO_MARSHAL_REF  ((UINT16)(offsetof(MarshalData_st, MSSIM_EO_DATA)))
#define MSSIM_SU_MARSHAL_REF  ((UINT16)(offsetof(MarshalData_st, MSSIM_SU_DATA)))
#define MSSIM_SE_MARSHAL_REF  ((UINT16)(offsetof(MarshalData_st, MSSIM_SE_DATA)))
#define MSSIM_CAP_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIM_CAP_DATA)))
#define MSSIMA_ALGORITHM_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMA_ALGORITHM_DATA)))
#define MSSIMA_OBJECT_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMA_OBJECT_DATA)))
#define MSSIMA_SESSION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMA_SESSION_DATA)))
#define MSSIMA_ACT_MARSHAL_REF    ((UINT16)(offsetof(MarshalData_st, MSSIMA_ACT_DATA)))
#define MSSIMI_YES_NO_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMI_YES_NO_DATA)))
#define MSSIMI_DH_OBJECT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_OBJECT_DATA)))
#define MSSIMI_DH_PARENT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_PARENT_DATA)))
#define MSSIMI_DH_PERSISTENT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_PERSISTENT_DATA)))
#define MSSIMI_DH_ENTITY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_ENTITY_DATA)))
#define MSSIMI_DH_PCR_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_PCR_DATA)))
#define MSSIMI_SH_AUTH_SESSION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_SH_AUTH_SESSION_DATA)))
#define MSSIMI_SH_HMAC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_SH_HMAC_DATA)))
#define MSSIMI_SH_POLICY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_SH_POLICY_DATA)))
#define MSSIMI_DH_CONTEXT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_CONTEXT_DATA)))
#define MSSIMI_DH_SAVED_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_DH_SAVED_DATA)))
#define MSSIMI_RH_HIERARCHY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_HIERARCHY_DATA)))
#define MSSIMI_RH_ENABLES_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_ENABLES_DATA)))
#define MSSIMI_RH_HIERARCHY_AUTH_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_HIERARCHY_AUTH_DATA)))
#define MSSIMI_RH_HIERARCHY_POLICY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_HIERARCHY_POLICY_DATA)))
#define MSSIMI_RH_PLATFORM_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_PLATFORM_DATA)))
#define MSSIMI_RH_OWNER_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_OWNER_DATA)))
#define MSSIMI_RH_ENDORSEMENT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_ENDORSEMENT_DATA)))
#define MSSIMI_RH_PROVISION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_PROVISION_DATA)))
#define MSSIMI_RH_CLEAR_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_CLEAR_DATA)))
#define MSSIMI_RH_NV_AUTH_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_NV_AUTH_DATA)))
#define MSSIMI_RH_LOCKOUT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_LOCKOUT_DATA)))
#define MSSIMI_RH_NV_INDEX_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_NV_INDEX_DATA)))
#define MSSIMI_RH_AC_MARSHAL_REF  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_AC_DATA)))
#define MSSIMI_RH_ACT_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMI_RH_ACT_DATA)))
#define MSSIMI_ALG_HASH_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_HASH_DATA)))
#define MSSIMI_ALG_ASYM_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_ASYM_DATA)))
#define MSSIMI_ALG_SYM_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_SYM_DATA)))
#define MSSIMI_ALG_SYM_OBJECT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_SYM_OBJECT_DATA)))
#define MSSIMI_ALG_SYM_MODE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_SYM_MODE_DATA)))
#define MSSIMI_ALG_KDF_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_KDF_DATA)))
#define MSSIMI_ALG_SIG_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_SIG_SCHEME_DATA)))
#define MSSIMI_ECC_KEY_EXCHANGE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ECC_KEY_EXCHANGE_DATA)))
#define MSSIMI_ST_COMMAND_TAG_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ST_COMMAND_TAG_DATA)))
#define MSSIMI_ALG_MAC_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_MAC_SCHEME_DATA)))
#define MSSIMI_ALG_CIPHER_MODE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_CIPHER_MODE_DATA)))
#define MSSIMS_EMPTY_MARSHAL_REF            ((UINT16)(offsetof(MarshalData_st, MSSIMS_EMPTY_DATA)))
#define MSSIMS_ENC_SCHEME_RSAES_MARSHAL_REF MSSIMS_EMPTY_MARSHAL_REF
#define MSSIMS_ALGORITHM_DESCRIPTION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_ALGORITHM_DESCRIPTION_DATA)))
#define MSSIMU_HA_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMU_HA_DATA)))
#define MSSIMT_HA_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMT_HA_DATA)))
#define MSSIM2B_DIGEST_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_DIGEST_DATA)))
#define MSSIM2B_NONCE_MARSHAL_REF   MSSIM2B_DIGEST_MARSHAL_REF
#define MSSIM2B_AUTH_MARSHAL_REF    MSSIM2B_DIGEST_MARSHAL_REF
#define MSSIM2B_OPERAND_MARSHAL_REF MSSIM2B_DIGEST_MARSHAL_REF
#define MSSIM2B_DATA_MARSHAL_REF    ((UINT16)(offsetof(MarshalData_st, MSSIM2B_DATA_DATA)))
#define MSSIM2B_EVENT_MARSHAL_REF   ((UINT16)(offsetof(MarshalData_st, MSSIM2B_EVENT_DATA)))
#define MSSIM2B_MAX_BUFFER_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_MAX_BUFFER_DATA)))
#define MSSIM2B_MAX_NV_BUFFER_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_MAX_NV_BUFFER_DATA)))
#define MSSIM2B_TIMEOUT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_TIMEOUT_DATA)))
#define MSSIM2B_IV_MARSHAL_REF              ((UINT16)(offsetof(MarshalData_st, MSSIM2B_IV_DATA)))
#define NULL_UNION_MARSHAL_REF            ((UINT16)(offsetof(MarshalData_st, NULL_UNION_DATA)))
#define MSSIMU_NAME_MARSHAL_REF             NULL_UNION_MARSHAL_REF
#define MSSIMU_SENSITIVE_CREATE_MARSHAL_REF NULL_UNION_MARSHAL_REF
#define MSSIM2B_NAME_MARSHAL_REF            ((UINT16)(offsetof(MarshalData_st, MSSIM2B_NAME_DATA)))
#define MSSIMS_PCR_SELECT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_PCR_SELECT_DATA)))
#define MSSIMS_PCR_SELECTION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_PCR_SELECTION_DATA)))
#define MSSIMT_TK_CREATION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_TK_CREATION_DATA)))
#define MSSIMT_TK_VERIFIED_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_TK_VERIFIED_DATA)))
#define MSSIMT_TK_AUTH_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_TK_AUTH_DATA)))
#define MSSIMT_TK_HASHCHECK_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_TK_HASHCHECK_DATA)))
#define MSSIMS_ALG_PROPERTY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_ALG_PROPERTY_DATA)))
#define MSSIMS_TAGGED_PROPERTY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_TAGGED_PROPERTY_DATA)))
#define MSSIMS_TAGGED_PCR_SELECT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_TAGGED_PCR_SELECT_DATA)))
#define MSSIMS_TAGGED_POLICY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_TAGGED_POLICY_DATA)))
#define MSSIMS_ACT_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_ACT_DATA_DATA)))
#define MSSIML_CC_MARSHAL_REF     ((UINT16)(offsetof(MarshalData_st, MSSIML_CC_DATA)))
#define MSSIML_CCA_MARSHAL_REF    ((UINT16)(offsetof(MarshalData_st, MSSIML_CCA_DATA)))
#define MSSIML_ALG_MARSHAL_REF    ((UINT16)(offsetof(MarshalData_st, MSSIML_ALG_DATA)))
#define MSSIML_HANDLE_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIML_HANDLE_DATA)))
#define MSSIML_DIGEST_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIML_DIGEST_DATA)))
#define MSSIML_DIGEST_VALUES_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_DIGEST_VALUES_DATA)))
#define MSSIML_PCR_SELECTION_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_PCR_SELECTION_DATA)))
#define MSSIML_ALG_PROPERTY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_ALG_PROPERTY_DATA)))
#define MSSIML_TAGGED_MSSIM_PROPERTY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_TAGGED_MSSIM_PROPERTY_DATA)))
#define MSSIML_TAGGED_PCR_PROPERTY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_TAGGED_PCR_PROPERTY_DATA)))
#define MSSIML_ECC_CURVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_ECC_CURVE_DATA)))
#define MSSIML_TAGGED_POLICY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_TAGGED_POLICY_DATA)))
#define MSSIML_ACT_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_ACT_DATA_DATA)))
#define MSSIMU_CAPABILITIES_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_CAPABILITIES_DATA)))
#define MSSIMS_CAPABILITY_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CAPABILITY_DATA_DATA)))
#define MSSIMS_CLOCK_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CLOCK_INFO_DATA)))
#define MSSIMS_TIME_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_TIME_INFO_DATA)))
#define MSSIMS_TIME_ATTEST_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_TIME_ATTEST_INFO_DATA)))
#define MSSIMS_CERTIFY_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CERTIFY_INFO_DATA)))
#define MSSIMS_QUOTE_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_QUOTE_INFO_DATA)))
#define MSSIMS_COMMAND_AUDIT_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_COMMAND_AUDIT_INFO_DATA)))
#define MSSIMS_SESSION_AUDIT_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SESSION_AUDIT_INFO_DATA)))
#define MSSIMS_CREATION_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CREATION_INFO_DATA)))
#define MSSIMS_NV_CERTIFY_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_NV_CERTIFY_INFO_DATA)))
#define MSSIMS_NV_DIGEST_CERTIFY_INFO_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_NV_DIGEST_CERTIFY_INFO_DATA)))
#define MSSIMI_ST_ATTEST_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ST_ATTEST_DATA)))
#define MSSIMU_ATTEST_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMU_ATTEST_DATA)))
#define MSSIMS_ATTEST_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMS_ATTEST_DATA)))
#define MSSIM2B_ATTEST_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_ATTEST_DATA)))
#define MSSIMS_AUTH_COMMAND_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_AUTH_COMMAND_DATA)))
#define MSSIMS_AUTH_RESPONSE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_AUTH_RESPONSE_DATA)))
#define MSSIMI_TDES_KEY_BITS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_TDES_KEY_BITS_DATA)))
#define MSSIMI_AES_KEY_BITS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_AES_KEY_BITS_DATA)))
#define MSSIMI_SM4_KEY_BITS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_SM4_KEY_BITS_DATA)))
#define MSSIMI_CAMELLIA_KEY_BITS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_CAMELLIA_KEY_BITS_DATA)))
#define MSSIMU_SYM_KEY_BITS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_SYM_KEY_BITS_DATA)))
#define MSSIMU_SYM_MODE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_SYM_MODE_DATA)))
#define MSSIMT_SYM_DEF_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_SYM_DEF_DATA)))
#define MSSIMT_SYM_DEF_OBJECT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_SYM_DEF_OBJECT_DATA)))
#define MSSIM2B_SYM_KEY_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_SYM_KEY_DATA)))
#define MSSIMS_SYMCIPHER_PARMS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SYMCIPHER_PARMS_DATA)))
#define MSSIM2B_LABEL_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIM2B_LABEL_DATA)))
#define MSSIMS_DERIVE_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMS_DERIVE_DATA)))
#define MSSIM2B_DERIVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_DERIVE_DATA)))
#define MSSIM2B_SENSITIVE_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_SENSITIVE_DATA_DATA)))
#define MSSIMS_SENSITIVE_CREATE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SENSITIVE_CREATE_DATA)))
#define MSSIM2B_SENSITIVE_CREATE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_SENSITIVE_CREATE_DATA)))
#define MSSIMS_SCHEME_HASH_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SCHEME_HASH_DATA)))
#define MSSIMS_SCHEME_HMAC_MARSHAL_REF               MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_SIG_SCHEME_RSASSA_MARSHAL_REF         MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_SIG_SCHEME_RSAPSS_MARSHAL_REF         MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_SIG_SCHEME_ECDSA_MARSHAL_REF          MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_SIG_SCHEME_SM2_MARSHAL_REF            MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_SIG_SCHEME_ECSCHNORR_MARSHAL_REF      MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_ENC_SCHEME_OAEP_MARSHAL_REF           MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_KEY_SCHEME_ECDH_MARSHAL_REF           MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_KEY_SCHEME_ECMQV_MARSHAL_REF          MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_KDF_SCHEME_MGF1_MARSHAL_REF           MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_KDF_SCHEME_KDF1_SP800_56A_MARSHAL_REF MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_KDF_SCHEME_KDF2_MARSHAL_REF           MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_KDF_SCHEME_KDF1_SP800_108_MARSHAL_REF MSSIMS_SCHEME_HASH_MARSHAL_REF
#define MSSIMS_SCHEME_ECDAA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SCHEME_ECDAA_DATA)))
#define MSSIMS_SIG_SCHEME_ECDAA_MARSHAL_REF MSSIMS_SCHEME_ECDAA_MARSHAL_REF
#define MSSIMI_ALG_KEYEDHASH_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_KEYEDHASH_SCHEME_DATA)))
#define MSSIMS_SCHEME_XOR_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SCHEME_XOR_DATA)))
#define MSSIMU_SCHEME_KEYEDHASH_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_SCHEME_KEYEDHASH_DATA)))
#define MSSIMT_KEYEDHASH_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_KEYEDHASH_SCHEME_DATA)))
#define MSSIMU_SIG_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_SIG_SCHEME_DATA)))
#define MSSIMT_SIG_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_SIG_SCHEME_DATA)))
#define MSSIMU_KDF_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_KDF_SCHEME_DATA)))
#define MSSIMT_KDF_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_KDF_SCHEME_DATA)))
#define MSSIMI_ALG_ASYM_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_ASYM_SCHEME_DATA)))
#define MSSIMU_ASYM_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_ASYM_SCHEME_DATA)))
#define MSSIMI_ALG_RSA_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_RSA_SCHEME_DATA)))
#define MSSIMT_RSA_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_RSA_SCHEME_DATA)))
#define MSSIMI_ALG_RSA_DECRYPT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_RSA_DECRYPT_DATA)))
#define MSSIMT_RSA_DECRYPT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_RSA_DECRYPT_DATA)))
#define MSSIM2B_PUBLIC_KEY_RSA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_PUBLIC_KEY_RSA_DATA)))
#define MSSIMI_RSA_KEY_BITS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_RSA_KEY_BITS_DATA)))
#define MSSIM2B_PRIVATE_KEY_RSA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_PRIVATE_KEY_RSA_DATA)))
#define MSSIM2B_ECC_PARAMETER_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_ECC_PARAMETER_DATA)))
#define MSSIMS_ECC_POINT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_ECC_POINT_DATA)))
#define MSSIM2B_ECC_POINT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_ECC_POINT_DATA)))
#define MSSIMI_ALG_ECC_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_ECC_SCHEME_DATA)))
#define MSSIMI_ECC_CURVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ECC_CURVE_DATA)))
#define MSSIMT_ECC_SCHEME_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_ECC_SCHEME_DATA)))
#define MSSIMS_ALGORITHM_DETAIL_ECC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_ALGORITHM_DETAIL_ECC_DATA)))
#define MSSIMS_SIGNATURE_RSA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SIGNATURE_RSA_DATA)))
#define MSSIMS_SIGNATURE_RSASSA_MARSHAL_REF MSSIMS_SIGNATURE_RSA_MARSHAL_REF
#define MSSIMS_SIGNATURE_RSAPSS_MARSHAL_REF MSSIMS_SIGNATURE_RSA_MARSHAL_REF
#define MSSIMS_SIGNATURE_ECC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_SIGNATURE_ECC_DATA)))
#define MSSIMS_SIGNATURE_ECDAA_MARSHAL_REF     MSSIMS_SIGNATURE_ECC_MARSHAL_REF
#define MSSIMS_SIGNATURE_ECDSA_MARSHAL_REF     MSSIMS_SIGNATURE_ECC_MARSHAL_REF
#define MSSIMS_SIGNATURE_SM2_MARSHAL_REF       MSSIMS_SIGNATURE_ECC_MARSHAL_REF
#define MSSIMS_SIGNATURE_ECSCHNORR_MARSHAL_REF MSSIMS_SIGNATURE_ECC_MARSHAL_REF
#define MSSIMU_SIGNATURE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_SIGNATURE_DATA)))
#define MSSIMT_SIGNATURE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_SIGNATURE_DATA)))
#define MSSIMU_ENCRYPTED_SECRET_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_ENCRYPTED_SECRET_DATA)))
#define MSSIM2B_ENCRYPTED_SECRET_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_ENCRYPTED_SECRET_DATA)))
#define MSSIMI_ALG_PUBLIC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMI_ALG_PUBLIC_DATA)))
#define MSSIMU_PUBLIC_ID_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_PUBLIC_ID_DATA)))
#define MSSIMS_KEYEDHASH_PARMS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_KEYEDHASH_PARMS_DATA)))
#define MSSIMS_RSA_PARMS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_RSA_PARMS_DATA)))
#define MSSIMS_ECC_PARMS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_ECC_PARMS_DATA)))
#define MSSIMU_PUBLIC_PARMS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_PUBLIC_PARMS_DATA)))
#define MSSIMT_PUBLIC_PARMS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_PUBLIC_PARMS_DATA)))
#define MSSIMT_PUBLIC_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMT_PUBLIC_DATA)))
#define MSSIM2B_PUBLIC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_PUBLIC_DATA)))
#define MSSIM2B_TEMPLATE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_TEMPLATE_DATA)))
#define MSSIM2B_PRIVATE_VENDOR_SPECIFIC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_PRIVATE_VENDOR_SPECIFIC_DATA)))
#define MSSIMU_SENSITIVE_COMPOSITE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMU_SENSITIVE_COMPOSITE_DATA)))
#define MSSIMT_SENSITIVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMT_SENSITIVE_DATA)))
#define MSSIM2B_SENSITIVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_SENSITIVE_DATA)))
#define MSSIM2B_PRIVATE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_PRIVATE_DATA)))
#define MSSIM2B_ID_OBJECT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_ID_OBJECT_DATA)))
#define MSSIMS_NV_PIN_COUNTER_PARAMETERS_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_NV_PIN_COUNTER_PARAMETERS_DATA)))
#define MSSIMA_NV_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIMA_NV_DATA)))
#define MSSIMS_NV_PUBLIC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_NV_PUBLIC_DATA)))
#define MSSIM2B_NV_PUBLIC_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_NV_PUBLIC_DATA)))
#define MSSIM2B_CONTEXT_SENSITIVE_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_CONTEXT_SENSITIVE_DATA)))
#define MSSIMS_CONTEXT_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CONTEXT_DATA_DATA)))
#define MSSIM2B_CONTEXT_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_CONTEXT_DATA_DATA)))
#define MSSIMS_CONTEXT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CONTEXT_DATA)))
#define MSSIMS_CREATION_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_CREATION_DATA_DATA)))
#define MSSIM2B_CREATION_DATA_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIM2B_CREATION_DATA_DATA)))
#define MSSIM_AT_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, MSSIM_AT_DATA)))
#define MSSIMS_AC_OUTPUT_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIMS_AC_OUTPUT_DATA)))
#define MSSIML_AC_CAPABILITIES_MARSHAL_REF \
  ((UINT16)(offsetof(MarshalData_st, MSSIML_AC_CAPABILITIES_DATA)))
#define Type00_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type00_DATA)))
#define Type01_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type01_DATA)))
#define Type02_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type02_DATA)))
#define Type03_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type03_DATA)))
#define Type04_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type04_DATA)))
#define Type05_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type05_DATA)))
#define Type06_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type06_DATA)))
#define Type07_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type07_DATA)))
#define Type08_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type08_DATA)))
#define Type09_MARSHAL_REF Type08_MARSHAL_REF
#define Type14_MARSHAL_REF Type08_MARSHAL_REF
#define Type10_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type10_DATA)))
#define Type11_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type11_DATA)))
#define Type12_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type12_DATA)))
#define Type13_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type13_DATA)))
#define Type15_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type15_DATA)))
#define Type16_MARSHAL_REF Type15_MARSHAL_REF
#define Type17_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type17_DATA)))
#define Type18_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type18_DATA)))
#define Type19_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type19_DATA)))
#define Type20_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type20_DATA)))
#define Type21_MARSHAL_REF Type20_MARSHAL_REF
#define Type22_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type22_DATA)))
#define Type23_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type23_DATA)))
#define Type24_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type24_DATA)))
#define Type25_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type25_DATA)))
#define Type26_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type26_DATA)))
#define Type27_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type27_DATA)))
#define Type28_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type28_DATA)))
#define Type29_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type29_DATA)))
#define Type30_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type30_DATA)))
#define Type31_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type31_DATA)))
#define Type32_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type32_DATA)))
#define Type33_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type33_DATA)))
#define Type34_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type34_DATA)))
#define Type35_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type35_DATA)))
#define Type36_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type36_DATA)))
#define Type37_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type37_DATA)))
#define Type38_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type38_DATA)))
#define Type39_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type39_DATA)))
#define Type40_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type40_DATA)))
#define Type41_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type41_DATA)))
#define Type42_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type42_DATA)))
#define Type43_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type43_DATA)))
#define Type44_MARSHAL_REF ((UINT16)(offsetof(MarshalData_st, Type44_DATA)))

//#defines to change calling sequence for code using marshaling
#define UINT8_Unmarshal(target, buffer, size) \
  Unmarshal(UINT8_MARSHAL_REF, (target), (buffer), (size))
#define UINT8_Marshal(source, buffer, size) \
  Marshal(UINT8_MARSHAL_REF, (source), (buffer), (size))
#define BYTE_Unmarshal(target, buffer, size) \
  Unmarshal(UINT8_MARSHAL_REF, (target), (buffer), (size))
#define BYTE_Marshal(source, buffer, size) \
  Marshal(UINT8_MARSHAL_REF, (source), (buffer), (size))
#define INT8_Unmarshal(target, buffer, size) \
  Unmarshal(INT8_MARSHAL_REF, (target), (buffer), (size))
#define INT8_Marshal(source, buffer, size) \
  Marshal(INT8_MARSHAL_REF, (source), (buffer), (size))
#define UINT16_Unmarshal(target, buffer, size) \
  Unmarshal(UINT16_MARSHAL_REF, (target), (buffer), (size))
#define UINT16_Marshal(source, buffer, size) \
  Marshal(UINT16_MARSHAL_REF, (source), (buffer), (size))
#define INT16_Unmarshal(target, buffer, size) \
  Unmarshal(INT16_MARSHAL_REF, (target), (buffer), (size))
#define INT16_Marshal(source, buffer, size) \
  Marshal(INT16_MARSHAL_REF, (source), (buffer), (size))
#define UINT32_Unmarshal(target, buffer, size) \
  Unmarshal(UINT32_MARSHAL_REF, (target), (buffer), (size))
#define UINT32_Marshal(source, buffer, size) \
  Marshal(UINT32_MARSHAL_REF, (source), (buffer), (size))
#define INT32_Unmarshal(target, buffer, size) \
  Unmarshal(INT32_MARSHAL_REF, (target), (buffer), (size))
#define INT32_Marshal(source, buffer, size) \
  Marshal(INT32_MARSHAL_REF, (source), (buffer), (size))
#define UINT64_Unmarshal(target, buffer, size) \
  Unmarshal(UINT64_MARSHAL_REF, (target), (buffer), (size))
#define UINT64_Marshal(source, buffer, size) \
  Marshal(UINT64_MARSHAL_REF, (source), (buffer), (size))
#define INT64_Unmarshal(target, buffer, size) \
  Unmarshal(INT64_MARSHAL_REF, (target), (buffer), (size))
#define INT64_Marshal(source, buffer, size) \
  Marshal(INT64_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_ALGORITHM_ID_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_ALGORITHM_ID_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_ALGORITHM_ID_Marshal(source, buffer, size) \
  Marshal(MSSIM_ALGORITHM_ID_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_MODIFIER_INDICATOR_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_MODIFIER_INDICATOR_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_MODIFIER_INDICATOR_Marshal(source, buffer, size) \
  Marshal(MSSIM_MODIFIER_INDICATOR_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_AUTHORIZATION_SIZE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_AUTHORIZATION_SIZE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_AUTHORIZATION_SIZE_Marshal(source, buffer, size) \
  Marshal(MSSIM_AUTHORIZATION_SIZE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_PARAMETER_SIZE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_PARAMETER_SIZE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_PARAMETER_SIZE_Marshal(source, buffer, size) \
  Marshal(MSSIM_PARAMETER_SIZE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_KEY_SIZE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_KEY_SIZE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_KEY_SIZE_Marshal(source, buffer, size) \
  Marshal(MSSIM_KEY_SIZE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_KEY_BITS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_KEY_BITS_Marshal(source, buffer, size) \
  Marshal(MSSIM_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_CONSTANTS32_Marshal(source, buffer, size) \
  Marshal(MSSIM_CONSTANTS32_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_ALG_ID_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_ALG_ID_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_ALG_ID_Marshal(source, buffer, size) \
  Marshal(MSSIM_ALG_ID_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_ECC_CURVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_ECC_CURVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_ECC_CURVE_Marshal(source, buffer, size) \
  Marshal(MSSIM_ECC_CURVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_CC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_CC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_CC_Marshal(source, buffer, size) \
  Marshal(MSSIM_CC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_RC_Marshal(source, buffer, size) \
  Marshal(MSSIM_RC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_CLOCK_ADJUST_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_CLOCK_ADJUST_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_EO_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_EO_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_EO_Marshal(source, buffer, size) \
  Marshal(MSSIM_EO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_ST_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_ST_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_ST_Marshal(source, buffer, size) \
  Marshal(MSSIM_ST_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_SU_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_SU_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_SE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_SE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_CAP_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_CAP_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_CAP_Marshal(source, buffer, size) \
  Marshal(MSSIM_CAP_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_PT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_PT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_PT_Marshal(source, buffer, size) \
  Marshal(MSSIM_PT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_PT_PCR_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_PT_PCR_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_PT_PCR_Marshal(source, buffer, size) \
  Marshal(MSSIM_PT_PCR_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_PS_Marshal(source, buffer, size) \
  Marshal(MSSIM_PS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_HANDLE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_HANDLE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_HANDLE_Marshal(source, buffer, size) \
  Marshal(MSSIM_HANDLE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_HT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_HT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_HT_Marshal(source, buffer, size) \
  Marshal(MSSIM_HT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_RH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_RH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_RH_Marshal(source, buffer, size) \
  Marshal(MSSIM_RH_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_HC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_HC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_HC_Marshal(source, buffer, size) \
  Marshal(MSSIM_HC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_ALGORITHM_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMA_ALGORITHM_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMA_ALGORITHM_Marshal(source, buffer, size) \
  Marshal(MSSIMA_ALGORITHM_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_OBJECT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMA_OBJECT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMA_OBJECT_Marshal(source, buffer, size) \
  Marshal(MSSIMA_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_SESSION_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMA_SESSION_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMA_SESSION_Marshal(source, buffer, size) \
  Marshal(MSSIMA_SESSION_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_LOCALITY_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMA_LOCALITY_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMA_LOCALITY_Marshal(source, buffer, size) \
  Marshal(MSSIMA_LOCALITY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_PERMANENT_Marshal(source, buffer, size) \
  Marshal(MSSIMA_PERMANENT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_STARTUP_CLEAR_Marshal(source, buffer, size) \
  Marshal(MSSIMA_STARTUP_CLEAR_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_MEMORY_Marshal(source, buffer, size) \
  Marshal(MSSIMA_MEMORY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_CC_Marshal(source, buffer, size) \
  Marshal(MSSIMA_CC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_MODES_Marshal(source, buffer, size) \
  Marshal(MSSIMA_MODES_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_X509_KEY_USAGE_Marshal(source, buffer, size) \
  Marshal(MSSIMA_X509_KEY_USAGE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_ACT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMA_ACT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMA_ACT_Marshal(source, buffer, size) \
  Marshal(MSSIMA_ACT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_YES_NO_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_YES_NO_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_YES_NO_Marshal(source, buffer, size) \
  Marshal(MSSIMI_YES_NO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_DH_OBJECT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_DH_OBJECT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                            \
            (buffer),                                            \
            (size))
#define MSSIMI_DH_OBJECT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_DH_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_DH_PARENT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_DH_PARENT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                            \
            (buffer),                                            \
            (size))
#define MSSIMI_DH_PARENT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_DH_PARENT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_DH_PERSISTENT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_DH_PERSISTENT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_DH_PERSISTENT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_DH_PERSISTENT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_DH_ENTITY_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_DH_ENTITY_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                            \
            (buffer),                                            \
            (size))
#define MSSIMI_DH_PCR_Unmarshal(target, buffer, size, flag) \
  Unmarshal(                                              \
      MSSIMI_DH_PCR_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIMI_SH_AUTH_SESSION_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_SH_AUTH_SESSION_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                  \
            (buffer),                                                  \
            (size))
#define MSSIMI_SH_AUTH_SESSION_Marshal(source, buffer, size) \
  Marshal(MSSIMI_SH_AUTH_SESSION_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_SH_HMAC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_SH_HMAC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_SH_HMAC_Marshal(source, buffer, size) \
  Marshal(MSSIMI_SH_HMAC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_SH_POLICY_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_SH_POLICY_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_SH_POLICY_Marshal(source, buffer, size) \
  Marshal(MSSIMI_SH_POLICY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_DH_CONTEXT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_DH_CONTEXT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_DH_CONTEXT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_DH_CONTEXT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_DH_SAVED_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_DH_SAVED_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_DH_SAVED_Marshal(source, buffer, size) \
  Marshal(MSSIMI_DH_SAVED_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_RH_HIERARCHY_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_RH_HIERARCHY_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                               \
            (buffer),                                               \
            (size))
#define MSSIMI_RH_HIERARCHY_Marshal(source, buffer, size) \
  Marshal(MSSIMI_RH_HIERARCHY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_RH_ENABLES_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_RH_ENABLES_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                             \
            (buffer),                                             \
            (size))
#define MSSIMI_RH_ENABLES_Marshal(source, buffer, size) \
  Marshal(MSSIMI_RH_ENABLES_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_RH_HIERARCHY_AUTH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_HIERARCHY_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_HIERARCHY_POLICY_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_HIERARCHY_POLICY_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_PLATFORM_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_PLATFORM_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_OWNER_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_RH_OWNER_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                           \
            (buffer),                                           \
            (size))
#define MSSIMI_RH_ENDORSEMENT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_RH_ENDORSEMENT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMI_RH_PROVISION_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_PROVISION_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_CLEAR_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_CLEAR_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_NV_AUTH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_NV_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_LOCKOUT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_LOCKOUT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_NV_INDEX_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_NV_INDEX_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_NV_INDEX_Marshal(source, buffer, size) \
  Marshal(MSSIMI_RH_NV_INDEX_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_RH_AC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_AC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_ACT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RH_ACT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RH_ACT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_RH_ACT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_HASH_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_HASH_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                           \
            (buffer),                                           \
            (size))
#define MSSIMI_ALG_HASH_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_HASH_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_ASYM_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_ASYM_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                           \
            (buffer),                                           \
            (size))
#define MSSIMI_ALG_ASYM_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_ASYM_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_SYM_Unmarshal(target, buffer, size, flag) \
  Unmarshal(                                               \
      MSSIMI_ALG_SYM_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIMI_ALG_SYM_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_SYM_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_SYM_OBJECT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_SYM_OBJECT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMI_ALG_SYM_OBJECT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_SYM_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_SYM_MODE_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_SYM_MODE_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                               \
            (buffer),                                               \
            (size))
#define MSSIMI_ALG_SYM_MODE_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_SYM_MODE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_KDF_Unmarshal(target, buffer, size, flag) \
  Unmarshal(                                               \
      MSSIMI_ALG_KDF_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIMI_ALG_KDF_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_KDF_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_SIG_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_SIG_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMI_ALG_SIG_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_SIG_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ECC_KEY_EXCHANGE_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ECC_KEY_EXCHANGE_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                   \
            (buffer),                                                   \
            (size))
#define MSSIMI_ECC_KEY_EXCHANGE_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ECC_KEY_EXCHANGE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ST_COMMAND_TAG_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_ST_COMMAND_TAG_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_ST_COMMAND_TAG_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ST_COMMAND_TAG_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_MAC_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_MAC_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMI_ALG_MAC_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_MAC_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_CIPHER_MODE_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_CIPHER_MODE_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                  \
            (buffer),                                                  \
            (size))
#define MSSIMI_ALG_CIPHER_MODE_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_CIPHER_MODE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_EMPTY_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_EMPTY_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_EMPTY_Marshal(source, buffer, size) \
  Marshal(MSSIMS_EMPTY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ALGORITHM_DESCRIPTION_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ALGORITHM_DESCRIPTION_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_HA_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_HA_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_HA_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_HA_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_HA_Unmarshal(target, buffer, size, flag) \
  Unmarshal(MSSIMT_HA_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIMT_HA_Marshal(source, buffer, size) \
  Marshal(MSSIMT_HA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_DIGEST_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_DIGEST_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_DIGEST_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_DIGEST_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_DATA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_DATA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_NONCE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_NONCE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_NONCE_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_NONCE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_AUTH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_AUTH_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_AUTH_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_OPERAND_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_OPERAND_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_OPERAND_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_OPERAND_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_EVENT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_EVENT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_EVENT_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_EVENT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_MAX_BUFFER_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_MAX_BUFFER_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_MAX_BUFFER_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_MAX_BUFFER_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_MAX_NV_BUFFER_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_MAX_NV_BUFFER_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_MAX_NV_BUFFER_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_MAX_NV_BUFFER_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_TIMEOUT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_TIMEOUT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_TIMEOUT_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_TIMEOUT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_IV_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_IV_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_IV_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_IV_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_NAME_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_NAME_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_NAME_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_NAME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_PCR_SELECT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_PCR_SELECT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_PCR_SELECT_Marshal(source, buffer, size) \
  Marshal(MSSIMS_PCR_SELECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_PCR_SELECTION_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_PCR_SELECTION_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_PCR_SELECTION_Marshal(source, buffer, size) \
  Marshal(MSSIMS_PCR_SELECTION_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_TK_CREATION_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMT_TK_CREATION_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMT_TK_CREATION_Marshal(source, buffer, size) \
  Marshal(MSSIMT_TK_CREATION_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_TK_VERIFIED_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMT_TK_VERIFIED_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMT_TK_VERIFIED_Marshal(source, buffer, size) \
  Marshal(MSSIMT_TK_VERIFIED_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_TK_AUTH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMT_TK_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMT_TK_AUTH_Marshal(source, buffer, size) \
  Marshal(MSSIMT_TK_AUTH_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_TK_HASHCHECK_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMT_TK_HASHCHECK_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMT_TK_HASHCHECK_Marshal(source, buffer, size) \
  Marshal(MSSIMT_TK_HASHCHECK_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ALG_PROPERTY_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ALG_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_TAGGED_PROPERTY_Marshal(source, buffer, size) \
  Marshal(MSSIMS_TAGGED_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_TAGGED_PCR_SELECT_Marshal(source, buffer, size) \
  Marshal(MSSIMS_TAGGED_PCR_SELECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_TAGGED_POLICY_Marshal(source, buffer, size) \
  Marshal(MSSIMS_TAGGED_POLICY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ACT_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ACT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_CC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIML_CC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIML_CC_Marshal(source, buffer, size) \
  Marshal(MSSIML_CC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_CCA_Marshal(source, buffer, size) \
  Marshal(MSSIML_CCA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_ALG_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIML_ALG_MARSHAL_REF, (target), (buffer), (size))
#define MSSIML_ALG_Marshal(source, buffer, size) \
  Marshal(MSSIML_ALG_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_HANDLE_Marshal(source, buffer, size) \
  Marshal(MSSIML_HANDLE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_DIGEST_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIML_DIGEST_MARSHAL_REF, (target), (buffer), (size))
#define MSSIML_DIGEST_Marshal(source, buffer, size) \
  Marshal(MSSIML_DIGEST_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_DIGEST_VALUES_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIML_DIGEST_VALUES_MARSHAL_REF, (target), (buffer), (size))
#define MSSIML_DIGEST_VALUES_Marshal(source, buffer, size) \
  Marshal(MSSIML_DIGEST_VALUES_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_PCR_SELECTION_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIML_PCR_SELECTION_MARSHAL_REF, (target), (buffer), (size))
#define MSSIML_PCR_SELECTION_Marshal(source, buffer, size) \
  Marshal(MSSIML_PCR_SELECTION_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_ALG_PROPERTY_Marshal(source, buffer, size) \
  Marshal(MSSIML_ALG_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_TAGGED_MSSIM_PROPERTY_Marshal(source, buffer, size) \
  Marshal(MSSIML_TAGGED_MSSIM_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_TAGGED_PCR_PROPERTY_Marshal(source, buffer, size) \
  Marshal(MSSIML_TAGGED_PCR_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_ECC_CURVE_Marshal(source, buffer, size) \
  Marshal(MSSIML_ECC_CURVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_TAGGED_POLICY_Marshal(source, buffer, size) \
  Marshal(MSSIML_TAGGED_POLICY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_ACT_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIML_ACT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_CAPABILITIES_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_CAPABILITIES_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMS_CAPABILITY_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CAPABILITY_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_CLOCK_INFO_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_CLOCK_INFO_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_CLOCK_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CLOCK_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_TIME_INFO_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_TIME_INFO_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_TIME_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_TIME_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_TIME_ATTEST_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_TIME_ATTEST_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_CERTIFY_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CERTIFY_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_QUOTE_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_QUOTE_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_COMMAND_AUDIT_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_COMMAND_AUDIT_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SESSION_AUDIT_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SESSION_AUDIT_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_CREATION_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CREATION_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_NV_CERTIFY_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_NV_CERTIFY_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_NV_DIGEST_CERTIFY_INFO_Marshal(source, buffer, size) \
  Marshal(MSSIMS_NV_DIGEST_CERTIFY_INFO_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ST_ATTEST_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ST_ATTEST_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_ATTEST_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_ATTEST_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMS_ATTEST_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ATTEST_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_ATTEST_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_ATTEST_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_AUTH_COMMAND_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_AUTH_COMMAND_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_AUTH_RESPONSE_Marshal(source, buffer, size) \
  Marshal(MSSIMS_AUTH_RESPONSE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_TDES_KEY_BITS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_TDES_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_TDES_KEY_BITS_Marshal(source, buffer, size) \
  Marshal(MSSIMI_TDES_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_AES_KEY_BITS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_AES_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_AES_KEY_BITS_Marshal(source, buffer, size) \
  Marshal(MSSIMI_AES_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_SM4_KEY_BITS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_SM4_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_SM4_KEY_BITS_Marshal(source, buffer, size) \
  Marshal(MSSIMI_SM4_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_CAMELLIA_KEY_BITS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_CAMELLIA_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_CAMELLIA_KEY_BITS_Marshal(source, buffer, size) \
  Marshal(MSSIMI_CAMELLIA_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_SYM_KEY_BITS_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(                                                   \
      MSSIMU_SYM_KEY_BITS_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_SYM_KEY_BITS_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_SYM_KEY_BITS_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMU_SYM_MODE_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_SYM_MODE_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_SYM_MODE_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_SYM_MODE_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_SYM_DEF_Unmarshal(target, buffer, size, flag) \
  Unmarshal(                                               \
      MSSIMT_SYM_DEF_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIMT_SYM_DEF_Marshal(source, buffer, size) \
  Marshal(MSSIMT_SYM_DEF_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_SYM_DEF_OBJECT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_SYM_DEF_OBJECT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMT_SYM_DEF_OBJECT_Marshal(source, buffer, size) \
  Marshal(MSSIMT_SYM_DEF_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_SYM_KEY_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_SYM_KEY_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_SYM_KEY_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_SYM_KEY_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SYMCIPHER_PARMS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SYMCIPHER_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SYMCIPHER_PARMS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SYMCIPHER_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_LABEL_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_LABEL_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_LABEL_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_LABEL_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_DERIVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_DERIVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_DERIVE_Marshal(source, buffer, size) \
  Marshal(MSSIMS_DERIVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_DERIVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_DERIVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_DERIVE_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_DERIVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_SENSITIVE_DATA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_SENSITIVE_DATA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_SENSITIVE_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_SENSITIVE_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SENSITIVE_CREATE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SENSITIVE_CREATE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_SENSITIVE_CREATE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_SENSITIVE_CREATE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SCHEME_HASH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SCHEME_HASH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SCHEME_HASH_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SCHEME_HASH_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SCHEME_ECDAA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SCHEME_ECDAA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SCHEME_ECDAA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SCHEME_ECDAA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_KEYEDHASH_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_KEYEDHASH_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                       \
            (buffer),                                                       \
            (size))
#define MSSIMI_ALG_KEYEDHASH_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_KEYEDHASH_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SCHEME_HMAC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SCHEME_HMAC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SCHEME_HMAC_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SCHEME_HMAC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SCHEME_XOR_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SCHEME_XOR_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SCHEME_XOR_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SCHEME_XOR_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_SCHEME_KEYEDHASH_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(                                                       \
      MSSIMU_SCHEME_KEYEDHASH_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_SCHEME_KEYEDHASH_Marshal(source, buffer, size, selector) \
  MarshalUnion(                                                       \
      MSSIMU_SCHEME_KEYEDHASH_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_KEYEDHASH_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_KEYEDHASH_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                   \
            (buffer),                                                   \
            (size))
#define MSSIMT_KEYEDHASH_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMT_KEYEDHASH_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIG_SCHEME_RSASSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIG_SCHEME_RSASSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIG_SCHEME_RSASSA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIG_SCHEME_RSASSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIG_SCHEME_RSAPSS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIG_SCHEME_RSAPSS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIG_SCHEME_RSAPSS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIG_SCHEME_RSAPSS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIG_SCHEME_ECDSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIG_SCHEME_ECDSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIG_SCHEME_ECDSA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIG_SCHEME_ECDSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIG_SCHEME_SM2_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIG_SCHEME_SM2_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIG_SCHEME_SM2_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIG_SCHEME_SM2_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIG_SCHEME_ECSCHNORR_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIG_SCHEME_ECSCHNORR_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIG_SCHEME_ECSCHNORR_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIG_SCHEME_ECSCHNORR_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIG_SCHEME_ECDAA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIG_SCHEME_ECDAA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIG_SCHEME_ECDAA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIG_SCHEME_ECDAA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_SIG_SCHEME_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_SIG_SCHEME_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_SIG_SCHEME_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_SIG_SCHEME_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_SIG_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_SIG_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                             \
            (buffer),                                             \
            (size))
#define MSSIMT_SIG_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMT_SIG_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ENC_SCHEME_OAEP_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_ENC_SCHEME_OAEP_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_ENC_SCHEME_OAEP_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ENC_SCHEME_OAEP_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ENC_SCHEME_RSAES_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_ENC_SCHEME_RSAES_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_ENC_SCHEME_RSAES_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ENC_SCHEME_RSAES_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_KEY_SCHEME_ECDH_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KEY_SCHEME_ECDH_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KEY_SCHEME_ECDH_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KEY_SCHEME_ECDH_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_KEY_SCHEME_ECMQV_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KEY_SCHEME_ECMQV_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KEY_SCHEME_ECMQV_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KEY_SCHEME_ECMQV_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_KDF_SCHEME_MGF1_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KDF_SCHEME_MGF1_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KDF_SCHEME_MGF1_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KDF_SCHEME_MGF1_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KDF_SCHEME_KDF1_SP800_56A_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KDF_SCHEME_KDF1_SP800_56A_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_KDF_SCHEME_KDF2_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KDF_SCHEME_KDF2_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KDF_SCHEME_KDF2_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KDF_SCHEME_KDF2_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_KDF_SCHEME_KDF1_SP800_108_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KDF_SCHEME_KDF1_SP800_108_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KDF_SCHEME_KDF1_SP800_108_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KDF_SCHEME_KDF1_SP800_108_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_KDF_SCHEME_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_KDF_SCHEME_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_KDF_SCHEME_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_KDF_SCHEME_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_KDF_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_KDF_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                             \
            (buffer),                                             \
            (size))
#define MSSIMT_KDF_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMT_KDF_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_ASYM_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_ASYM_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                  \
            (buffer),                                                  \
            (size))
#define MSSIMI_ALG_ASYM_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_ASYM_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_ASYM_SCHEME_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_ASYM_SCHEME_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_ASYM_SCHEME_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_ASYM_SCHEME_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMI_ALG_RSA_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_RSA_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMI_ALG_RSA_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_RSA_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_RSA_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_RSA_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                             \
            (buffer),                                             \
            (size))
#define MSSIMT_RSA_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMT_RSA_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_RSA_DECRYPT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_RSA_DECRYPT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                  \
            (buffer),                                                  \
            (size))
#define MSSIMI_ALG_RSA_DECRYPT_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_RSA_DECRYPT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_RSA_DECRYPT_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_RSA_DECRYPT_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                              \
            (buffer),                                              \
            (size))
#define MSSIMT_RSA_DECRYPT_Marshal(source, buffer, size) \
  Marshal(MSSIMT_RSA_DECRYPT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_PUBLIC_KEY_RSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_PUBLIC_KEY_RSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_PUBLIC_KEY_RSA_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_PUBLIC_KEY_RSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_RSA_KEY_BITS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_RSA_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_RSA_KEY_BITS_Marshal(source, buffer, size) \
  Marshal(MSSIMI_RSA_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_PRIVATE_KEY_RSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_PRIVATE_KEY_RSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_PRIVATE_KEY_RSA_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_PRIVATE_KEY_RSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_ECC_PARAMETER_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_ECC_PARAMETER_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_ECC_PARAMETER_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_ECC_PARAMETER_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ECC_POINT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_ECC_POINT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_ECC_POINT_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ECC_POINT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_ECC_POINT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_ECC_POINT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_ECC_POINT_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_ECC_POINT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_ECC_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMI_ALG_ECC_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                                 \
            (buffer),                                                 \
            (size))
#define MSSIMI_ALG_ECC_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_ECC_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ECC_CURVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_ECC_CURVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_ECC_CURVE_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ECC_CURVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_ECC_SCHEME_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_ECC_SCHEME_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                             \
            (buffer),                                             \
            (size))
#define MSSIMT_ECC_SCHEME_Marshal(source, buffer, size) \
  Marshal(MSSIMT_ECC_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ALGORITHM_DETAIL_ECC_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ALGORITHM_DETAIL_ECC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_RSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_RSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_RSA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_RSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_RSASSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_RSASSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_RSASSA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_RSASSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_RSAPSS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_RSAPSS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_RSAPSS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_RSAPSS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_ECC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_ECC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_ECC_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_ECC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_ECDAA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_ECDAA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_ECDAA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_ECDAA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_ECDSA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_ECDSA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_ECDSA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_ECDSA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_SM2_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_SM2_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_SM2_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_SM2_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_SIGNATURE_ECSCHNORR_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_SIGNATURE_ECSCHNORR_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_SIGNATURE_ECSCHNORR_Marshal(source, buffer, size) \
  Marshal(MSSIMS_SIGNATURE_ECSCHNORR_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_SIGNATURE_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_SIGNATURE_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_SIGNATURE_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_SIGNATURE_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_SIGNATURE_Unmarshal(target, buffer, size, flag)     \
  Unmarshal(MSSIMT_SIGNATURE_MARSHAL_REF | (flag ? NULL_FLAG : 0), \
            (target),                                            \
            (buffer),                                            \
            (size))
#define MSSIMT_SIGNATURE_Marshal(source, buffer, size) \
  Marshal(MSSIMT_SIGNATURE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_ENCRYPTED_SECRET_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(                                                       \
      MSSIMU_ENCRYPTED_SECRET_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_ENCRYPTED_SECRET_Marshal(source, buffer, size, selector) \
  MarshalUnion(                                                       \
      MSSIMU_ENCRYPTED_SECRET_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIM2B_ENCRYPTED_SECRET_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_ENCRYPTED_SECRET_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_ENCRYPTED_SECRET_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_ENCRYPTED_SECRET_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMI_ALG_PUBLIC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMI_ALG_PUBLIC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMI_ALG_PUBLIC_Marshal(source, buffer, size) \
  Marshal(MSSIMI_ALG_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_PUBLIC_ID_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(MSSIMU_PUBLIC_ID_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_PUBLIC_ID_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_PUBLIC_ID_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMS_KEYEDHASH_PARMS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_KEYEDHASH_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_KEYEDHASH_PARMS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_KEYEDHASH_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_RSA_PARMS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_RSA_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_RSA_PARMS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_RSA_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_ECC_PARMS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_ECC_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_ECC_PARMS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_ECC_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_PUBLIC_PARMS_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(                                                   \
      MSSIMU_PUBLIC_PARMS_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_PUBLIC_PARMS_Marshal(source, buffer, size, selector) \
  MarshalUnion(MSSIMU_PUBLIC_PARMS_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_PUBLIC_PARMS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMT_PUBLIC_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMT_PUBLIC_PARMS_Marshal(source, buffer, size) \
  Marshal(MSSIMT_PUBLIC_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMT_PUBLIC_Unmarshal(target, buffer, size, flag) \
  Unmarshal(                                              \
      MSSIMT_PUBLIC_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIMT_PUBLIC_Marshal(source, buffer, size) \
  Marshal(MSSIMT_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_PUBLIC_Unmarshal(target, buffer, size, flag) \
  Unmarshal(                                               \
      MSSIM2B_PUBLIC_MARSHAL_REF | (flag ? NULL_FLAG : 0), (target), (buffer), (size))
#define MSSIM2B_PUBLIC_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_TEMPLATE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_TEMPLATE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_TEMPLATE_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_TEMPLATE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_PRIVATE_VENDOR_SPECIFIC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_PRIVATE_VENDOR_SPECIFIC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_PRIVATE_VENDOR_SPECIFIC_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_PRIVATE_VENDOR_SPECIFIC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMU_SENSITIVE_COMPOSITE_Unmarshal(target, buffer, size, selector) \
  UnmarshalUnion(                                                          \
      MSSIMU_SENSITIVE_COMPOSITE_MARSHAL_REF, (target), (buffer), (size), (selector))
#define MSSIMU_SENSITIVE_COMPOSITE_Marshal(source, buffer, size, selector) \
  MarshalUnion(                                                          \
      MSSIMU_SENSITIVE_COMPOSITE_MARSHAL_REF, (source), (buffer), (size), (selector))
#define MSSIMT_SENSITIVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMT_SENSITIVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMT_SENSITIVE_Marshal(source, buffer, size) \
  Marshal(MSSIMT_SENSITIVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_SENSITIVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_SENSITIVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_SENSITIVE_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_SENSITIVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_PRIVATE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_PRIVATE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_PRIVATE_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_PRIVATE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_ID_OBJECT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_ID_OBJECT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_ID_OBJECT_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_ID_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_NV_INDEX_Marshal(source, buffer, size) \
  Marshal(MSSIM_NV_INDEX_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_NV_PIN_COUNTER_PARAMETERS_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_NV_PIN_COUNTER_PARAMETERS_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_NV_PIN_COUNTER_PARAMETERS_Marshal(source, buffer, size) \
  Marshal(MSSIMS_NV_PIN_COUNTER_PARAMETERS_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMA_NV_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMA_NV_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMA_NV_Marshal(source, buffer, size) \
  Marshal(MSSIMA_NV_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_NV_PUBLIC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_NV_PUBLIC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_NV_PUBLIC_Marshal(source, buffer, size) \
  Marshal(MSSIMS_NV_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_NV_PUBLIC_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_NV_PUBLIC_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_NV_PUBLIC_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_NV_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_CONTEXT_SENSITIVE_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_CONTEXT_SENSITIVE_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_CONTEXT_SENSITIVE_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_CONTEXT_SENSITIVE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_CONTEXT_DATA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_CONTEXT_DATA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_CONTEXT_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CONTEXT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_CONTEXT_DATA_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM2B_CONTEXT_DATA_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM2B_CONTEXT_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_CONTEXT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_CONTEXT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIMS_CONTEXT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIMS_CONTEXT_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CONTEXT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_CREATION_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIMS_CREATION_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM2B_CREATION_DATA_Marshal(source, buffer, size) \
  Marshal(MSSIM2B_CREATION_DATA_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_AT_Unmarshal(target, buffer, size) \
  Unmarshal(MSSIM_AT_MARSHAL_REF, (target), (buffer), (size))
#define MSSIM_AT_Marshal(source, buffer, size) \
  Marshal(MSSIM_AT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIM_AE_Marshal(source, buffer, size) \
  Marshal(MSSIM_AE_MARSHAL_REF, (source), (buffer), (size))
#define MSSIMS_AC_OUTPUT_Marshal(source, buffer, size) \
  Marshal(MSSIMS_AC_OUTPUT_MARSHAL_REF, (source), (buffer), (size))
#define MSSIML_AC_CAPABILITIES_Marshal(source, buffer, size) \
  Marshal(MSSIML_AC_CAPABILITIES_MARSHAL_REF, (source), (buffer), (size))

#endif  // _TABLE_MARSHAL_DEFINES_H_
