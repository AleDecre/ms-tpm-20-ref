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

#ifndef _TABLE_MARSHAL_TYPES_H_
#define _TABLE_MARSHAL_TYPES_H_

typedef UINT16 marshalIndex_t;

//*** Structure Entries
// A structure contains a list of elements to unmarshal. Each of the entries is a
// UINT16. The structure descriptor is:

// The 'values' array contains indicators for the things to marshal. The 'elements'
// parameter indicates how many different entities are unmarshaled. This number
// nominally corresponds to the number of rows in the Part 2 table that describes
// the structure (the number of rows minus the title row and any error code rows).

// A schematic of a simple structure entry is shown here but the values are not
// actually in a structure. As shown, the third value is the offset in the structure
// where the value is placed when unmarshaled, or fetched from when marshaling. This
// is sufficient when the element type indicated by 'index' is always a simple type
// and never a union or array.This is just shown for illustrative purposes.
typedef struct simpleStructureEntry_t
{
    UINT16 qualifiers;     // indicates the type of entry (array, union
                           // etc.)
    marshalIndex_t index;  // the index into the appropriate array of
                           //  the descriptor of this type
    UINT16 offset;         // where this comes from or is placed
} simpleStructureEntry_t;

typedef const struct UintMarshal_mst
{
    UINT8 marshalType;  // UINT_MTYPE
    UINT8 modifiers;    // size and signed indicator.
} UintMarshal_mst;

typedef struct UnionMarshal_mst
{
    UINT8  countOfselectors;
    UINT8  modifiers;  // NULL_SELECTOR
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[1];
    //    UINT16          marshalingTypes[1]; // This is not part of the prototypical
    //    entry. It is here to show where the
    //    marshaling types will be in a union
} UnionMarshal_mst;

typedef struct NullUnionMarshal_mst
{
    UINT8 count;
} NullUnionMarshal_mst;

typedef struct MarshalHeader_mst
{
    UINT8 marshalType;  // VALUES_MTYPE
    UINT8 modifiers;
    UINT8 errorCode;
} MarshalHeader_mst;

typedef const struct ArrayMarshal_mst  // used in a structure
{
    marshalIndex_t type;
    UINT16         stride;
} ArrayMarshal_mst;

typedef const struct StructMarshal_mst
{
    UINT8  marshalType;  // STRUCTURE_MTYPE
    UINT8  elements;
    UINT16 values[1];  // three times elements
} StructMarshal_mst;

typedef const struct ValuesMarshal_mst
{
    UINT8  marshalType;  // VALUES_MTYPE
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[1];
} ValuesMarshal_mst;

typedef const struct TableMarshal_mst
{
    UINT8  marshalType;  // TABLE_MTYPE
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  singles;
    UINT32 values[1];
} TableMarshal_mst;

typedef const struct MinMaxMarshal_mst
{
    UINT8  marshalType;  // MIN_MAX_MTYPE
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MinMaxMarshal_mst;

typedef const struct Tpm2bMarshal_mst
{
    UINT8  unmarshalType;  // MSSIM2B_MTYPE
    UINT16 sizeIndex;      // reference to type for this size value
} Tpm2bMarshal_mst;

typedef const struct Tpm2bsMarshal_mst
{
    UINT8  unmarshalType;  // MSSIM2BS_MTYPE
    UINT8  modifiers;      // size= and offset (2 - 7)
    UINT16 sizeIndex;      // index of the size value;
    UINT16 dataIndex;      // the structure
} Tpm2bsMarshal_mst;

typedef const struct ListMarshal_mst
{
    UINT8  unmarshalType;  // LIST_MTYPE (for MSSIML)
    UINT8  modifiers;      // size offset 2-7
    UINT16 sizeIndex;      // reference to the minmax structure that
                           //      unmarshals the size parameter
    UINT16 arrayRef;       // reference to an array definition (type
                           //  and stride)
} ListMarshal_mst;

typedef const struct AttributesMarshal_mst
{
    UINT8  unmarashalType;  // ATTRIBUTE_MTYPE
    UINT8  modifiers;       // size (ONE_BYTES, TWO_BYTES, or FOUR_BYTES
    UINT32 attributeMask;   // the values that must be zero.
} AttributesMarshal_mst;

typedef const struct CompositeMarshal_mst
{
    UINT8          unmashalType;  // COMPOSITE_MTYPE
    UINT8          modifiers;     // number of entries and size
    marshalIndex_t types[1];      // array of unmarshaling types
} CompositeMarshal_mst;

typedef const struct MSSIM_ECC_CURVE_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIM_ECC_CURVE_mst;

typedef const struct MSSIM_CLOCK_ADJUST_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIM_CLOCK_ADJUST_mst;

typedef const struct MSSIM_EO_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIM_EO_mst;

typedef const struct MSSIM_SU_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIM_SU_mst;

typedef const struct MSSIM_SE_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[3];
} MSSIM_SE_mst;

typedef const struct MSSIM_CAP_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[3];
} MSSIM_CAP_mst;

typedef const struct MSSIMI_YES_NO_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIMI_YES_NO_mst;

typedef const struct MSSIMI_DH_OBJECT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[5];
} MSSIMI_DH_OBJECT_mst;

typedef const struct MSSIMI_DH_PARENT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[8];
} MSSIMI_DH_PARENT_mst;

typedef const struct MSSIMI_DH_PERSISTENT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIMI_DH_PERSISTENT_mst;

typedef const struct MSSIMI_DH_ENTITY_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[15];
} MSSIMI_DH_ENTITY_mst;

typedef const struct MSSIMI_DH_PCR_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[3];
} MSSIMI_DH_PCR_mst;

typedef const struct MSSIMI_SH_AUTH_SESSION_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[5];
} MSSIMI_SH_AUTH_SESSION_mst;

typedef const struct MSSIMI_SH_HMAC_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIMI_SH_HMAC_mst;

typedef const struct MSSIMI_SH_POLICY_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIMI_SH_POLICY_mst;

typedef const struct MSSIMI_DH_CONTEXT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[6];
} MSSIMI_DH_CONTEXT_mst;

typedef const struct MSSIMI_DH_SAVED_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[7];
} MSSIMI_DH_SAVED_mst;

typedef const struct MSSIMI_RH_HIERARCHY_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[4];
} MSSIMI_RH_HIERARCHY_mst;

typedef const struct MSSIMI_RH_ENABLES_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[5];
} MSSIMI_RH_ENABLES_mst;

typedef const struct MSSIMI_RH_HIERARCHY_AUTH_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[4];
} MSSIMI_RH_HIERARCHY_AUTH_mst;

typedef const struct MSSIMI_RH_HIERARCHY_POLICY_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[6];
} MSSIMI_RH_HIERARCHY_POLICY_mst;

typedef const struct MSSIMI_RH_PLATFORM_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} MSSIMI_RH_PLATFORM_mst;

typedef const struct MSSIMI_RH_OWNER_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIMI_RH_OWNER_mst;

typedef const struct MSSIMI_RH_ENDORSEMENT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIMI_RH_ENDORSEMENT_mst;

typedef const struct MSSIMI_RH_PROVISION_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIMI_RH_PROVISION_mst;

typedef const struct MSSIMI_RH_CLEAR_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIMI_RH_CLEAR_mst;

typedef const struct MSSIMI_RH_NV_AUTH_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[4];
} MSSIMI_RH_NV_AUTH_mst;

typedef const struct MSSIMI_RH_LOCKOUT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} MSSIMI_RH_LOCKOUT_mst;

typedef const struct MSSIMI_RH_NV_INDEX_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIMI_RH_NV_INDEX_mst;

typedef const struct MSSIMI_RH_AC_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIMI_RH_AC_mst;

typedef const struct MSSIMI_RH_ACT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} MSSIMI_RH_ACT_mst;

typedef const struct MSSIMI_ALG_HASH_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[5];
} MSSIMI_ALG_HASH_mst;

typedef const struct MSSIMI_ALG_ASYM_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[5];
} MSSIMI_ALG_ASYM_mst;

typedef const struct MSSIMI_ALG_SYM_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[5];
} MSSIMI_ALG_SYM_mst;

typedef const struct MSSIMI_ALG_SYM_OBJECT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[5];
} MSSIMI_ALG_SYM_OBJECT_mst;

typedef const struct MSSIMI_ALG_SYM_MODE_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_SYM_MODE_mst;

typedef const struct MSSIMI_ALG_KDF_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_KDF_mst;

typedef const struct MSSIMI_ALG_SIG_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_SIG_SCHEME_mst;

typedef const struct MSSIMI_ECC_KEY_EXCHANGE_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ECC_KEY_EXCHANGE_mst;

typedef const struct MSSIMI_ST_COMMAND_TAG_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} MSSIMI_ST_COMMAND_TAG_mst;

typedef const struct MSSIMI_ALG_MAC_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[5];
} MSSIMI_ALG_MAC_SCHEME_mst;

typedef const struct MSSIMI_ALG_CIPHER_MODE_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_CIPHER_MODE_mst;

typedef const struct MSSIMS_EMPTY_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[3];
} MSSIMS_EMPTY_mst;

typedef const struct MSSIMS_ALGORITHM_DESCRIPTION_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_ALGORITHM_DESCRIPTION_mst;

typedef struct MSSIMU_HA_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[9];
    UINT16 marshalingTypes[9];
} MSSIMU_HA_mst;

typedef const struct MSSIMT_HA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_HA_mst;

typedef const struct MSSIMS_PCR_SELECT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_PCR_SELECT_mst;

typedef const struct MSSIMS_PCR_SELECTION_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMS_PCR_SELECTION_mst;

typedef const struct MSSIMT_TK_CREATION_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMT_TK_CREATION_mst;

typedef const struct MSSIMT_TK_VERIFIED_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMT_TK_VERIFIED_mst;

typedef const struct MSSIMT_TK_AUTH_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMT_TK_AUTH_mst;

typedef const struct MSSIMT_TK_HASHCHECK_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMT_TK_HASHCHECK_mst;

typedef const struct MSSIMS_ALG_PROPERTY_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_ALG_PROPERTY_mst;

typedef const struct MSSIMS_TAGGED_PROPERTY_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_TAGGED_PROPERTY_mst;

typedef const struct MSSIMS_TAGGED_PCR_SELECT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMS_TAGGED_PCR_SELECT_mst;

typedef const struct MSSIMS_TAGGED_POLICY_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_TAGGED_POLICY_mst;

typedef const struct MSSIMS_ACT_DATA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMS_ACT_DATA_mst;

typedef struct MSSIMU_CAPABILITIES_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[11];
    UINT16 marshalingTypes[11];
} MSSIMU_CAPABILITIES_mst;

typedef const struct MSSIMS_CAPABILITY_DATA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_CAPABILITY_DATA_mst;

typedef const struct MSSIMS_CLOCK_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMS_CLOCK_INFO_mst;

typedef const struct MSSIMS_TIME_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_TIME_INFO_mst;

typedef const struct MSSIMS_TIME_ATTEST_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_TIME_ATTEST_INFO_mst;

typedef const struct MSSIMS_CERTIFY_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_CERTIFY_INFO_mst;

typedef const struct MSSIMS_QUOTE_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_QUOTE_INFO_mst;

typedef const struct MSSIMS_COMMAND_AUDIT_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMS_COMMAND_AUDIT_INFO_mst;

typedef const struct MSSIMS_SESSION_AUDIT_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_SESSION_AUDIT_INFO_mst;

typedef const struct MSSIMS_CREATION_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_CREATION_INFO_mst;

typedef const struct MSSIMS_NV_CERTIFY_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMS_NV_CERTIFY_INFO_mst;

typedef const struct MSSIMS_NV_DIGEST_CERTIFY_INFO_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_NV_DIGEST_CERTIFY_INFO_mst;

typedef const struct MSSIMI_ST_ATTEST_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  ranges;
    UINT8  singles;
    UINT32 values[3];
} MSSIMI_ST_ATTEST_mst;

typedef struct MSSIMU_ATTEST_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[8];
    UINT16 marshalingTypes[8];
} MSSIMU_ATTEST_mst;

typedef const struct MSSIMS_ATTEST_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[21];
} MSSIMS_ATTEST_mst;

typedef const struct MSSIMS_AUTH_COMMAND_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMS_AUTH_COMMAND_mst;

typedef const struct MSSIMS_AUTH_RESPONSE_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMS_AUTH_RESPONSE_mst;

typedef const struct MSSIMI_TDES_KEY_BITS_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} MSSIMI_TDES_KEY_BITS_mst;

typedef const struct MSSIMI_AES_KEY_BITS_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[3];
} MSSIMI_AES_KEY_BITS_mst;

typedef const struct MSSIMI_SM4_KEY_BITS_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} MSSIMI_SM4_KEY_BITS_mst;

typedef const struct MSSIMI_CAMELLIA_KEY_BITS_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[3];
} MSSIMI_CAMELLIA_KEY_BITS_mst;

typedef struct MSSIMU_SYM_KEY_BITS_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[6];
    UINT16 marshalingTypes[6];
} MSSIMU_SYM_KEY_BITS_mst;

typedef struct MSSIMU_SYM_MODE_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[6];
    UINT16 marshalingTypes[6];
} MSSIMU_SYM_MODE_mst;

typedef const struct MSSIMT_SYM_DEF_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMT_SYM_DEF_mst;

typedef const struct MSSIMT_SYM_DEF_OBJECT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMT_SYM_DEF_OBJECT_mst;

typedef const struct MSSIMS_SYMCIPHER_PARMS_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[3];
} MSSIMS_SYMCIPHER_PARMS_mst;

typedef const struct MSSIMS_DERIVE_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_DERIVE_mst;

typedef const struct MSSIMS_SENSITIVE_CREATE_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_SENSITIVE_CREATE_mst;

typedef const struct MSSIMS_SCHEME_HASH_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[3];
} MSSIMS_SCHEME_HASH_mst;

typedef const struct MSSIMS_SCHEME_ECDAA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_SCHEME_ECDAA_mst;

typedef const struct MSSIMI_ALG_KEYEDHASH_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_KEYEDHASH_SCHEME_mst;

typedef const struct MSSIMS_SCHEME_XOR_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_SCHEME_XOR_mst;

typedef struct MSSIMU_SCHEME_KEYEDHASH_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[3];
    UINT16 marshalingTypes[3];
} MSSIMU_SCHEME_KEYEDHASH_mst;

typedef const struct MSSIMT_KEYEDHASH_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_KEYEDHASH_SCHEME_mst;

typedef struct MSSIMU_SIG_SCHEME_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[8];
    UINT16 marshalingTypes[8];
} MSSIMU_SIG_SCHEME_mst;

typedef const struct MSSIMT_SIG_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_SIG_SCHEME_mst;

typedef struct MSSIMU_KDF_SCHEME_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[5];
    UINT16 marshalingTypes[5];
} MSSIMU_KDF_SCHEME_mst;

typedef const struct MSSIMT_KDF_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_KDF_SCHEME_mst;

typedef const struct MSSIMI_ALG_ASYM_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_ASYM_SCHEME_mst;

typedef struct MSSIMU_ASYM_SCHEME_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[11];
    UINT16 marshalingTypes[11];
} MSSIMU_ASYM_SCHEME_mst;

typedef const struct MSSIMI_ALG_RSA_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_RSA_SCHEME_mst;

typedef const struct MSSIMT_RSA_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_RSA_SCHEME_mst;

typedef const struct MSSIMI_ALG_RSA_DECRYPT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_RSA_DECRYPT_mst;

typedef const struct MSSIMT_RSA_DECRYPT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_RSA_DECRYPT_mst;

typedef const struct MSSIMI_RSA_KEY_BITS_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[3];
} MSSIMI_RSA_KEY_BITS_mst;

typedef const struct MSSIMS_ECC_POINT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_ECC_POINT_mst;

typedef const struct MSSIMI_ALG_ECC_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_ECC_SCHEME_mst;

typedef const struct MSSIMI_ECC_CURVE_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[3];
} MSSIMI_ECC_CURVE_mst;

typedef const struct MSSIMT_ECC_SCHEME_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_ECC_SCHEME_mst;

typedef const struct MSSIMS_ALGORITHM_DETAIL_ECC_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[33];
} MSSIMS_ALGORITHM_DETAIL_ECC_mst;

typedef const struct MSSIMS_SIGNATURE_RSA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_SIGNATURE_RSA_mst;

typedef const struct MSSIMS_SIGNATURE_ECC_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[9];
} MSSIMS_SIGNATURE_ECC_mst;

typedef struct MSSIMU_SIGNATURE_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[8];
    UINT16 marshalingTypes[8];
} MSSIMU_SIGNATURE_mst;

typedef const struct MSSIMT_SIGNATURE_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_SIGNATURE_mst;

typedef struct MSSIMU_ENCRYPTED_SECRET_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[4];
    UINT16 marshalingTypes[4];
} MSSIMU_ENCRYPTED_SECRET_mst;

typedef const struct MSSIMI_ALG_PUBLIC_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[4];
} MSSIMI_ALG_PUBLIC_mst;

typedef struct MSSIMU_PUBLIC_ID_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[4];
    UINT16 marshalingTypes[4];
} MSSIMU_PUBLIC_ID_mst;

typedef const struct MSSIMS_KEYEDHASH_PARMS_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[3];
} MSSIMS_KEYEDHASH_PARMS_mst;

typedef const struct MSSIMS_RSA_PARMS_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMS_RSA_PARMS_mst;

typedef const struct MSSIMS_ECC_PARMS_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMS_ECC_PARMS_mst;

typedef struct MSSIMU_PUBLIC_PARMS_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[4];
    UINT16 marshalingTypes[4];
} MSSIMU_PUBLIC_PARMS_mst;

typedef const struct MSSIMT_PUBLIC_PARMS_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMT_PUBLIC_PARMS_mst;

typedef const struct MSSIMT_PUBLIC_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[18];
} MSSIMT_PUBLIC_mst;

typedef struct MSSIMU_SENSITIVE_COMPOSITE_mst
{
    BYTE   countOfselectors;
    BYTE   modifiers;
    UINT16 offsetOfUnmarshalTypes;
    UINT32 selectors[4];
    UINT16 marshalingTypes[4];
} MSSIMU_SENSITIVE_COMPOSITE_mst;

typedef const struct MSSIMT_SENSITIVE_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMT_SENSITIVE_mst;

typedef const struct MSSIMS_NV_PIN_COUNTER_PARAMETERS_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_NV_PIN_COUNTER_PARAMETERS_mst;

typedef const struct MSSIMS_NV_PUBLIC_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[15];
} MSSIMS_NV_PUBLIC_mst;

typedef const struct MSSIMS_CONTEXT_DATA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_CONTEXT_DATA_mst;

typedef const struct MSSIMS_CONTEXT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[12];
} MSSIMS_CONTEXT_mst;

typedef const struct MSSIMS_CREATION_DATA_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[21];
} MSSIMS_CREATION_DATA_mst;

typedef const struct MSSIM_AT_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[4];
} MSSIM_AT_mst;

typedef const struct MSSIMS_AC_OUTPUT_mst
{
    UINT8  marshalType;
    UINT8  elements;
    UINT16 values[6];
} MSSIMS_AC_OUTPUT_mst;

typedef const struct Type02_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type02_mst;

typedef const struct Type03_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type03_mst;

typedef const struct Type04_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type04_mst;

typedef const struct Type06_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type06_mst;

typedef const struct Type08_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type08_mst;

typedef const struct Type10_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} Type10_mst;

typedef const struct Type11_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} Type11_mst;

typedef const struct Type12_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[2];
} Type12_mst;

typedef const struct Type13_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT8  entries;
    UINT32 values[1];
} Type13_mst;

typedef const struct Type15_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type15_mst;

typedef const struct Type17_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type17_mst;

typedef const struct Type18_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type18_mst;

typedef const struct Type19_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type19_mst;

typedef const struct Type20_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type20_mst;

typedef const struct Type22_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type22_mst;

typedef const struct Type23_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type23_mst;

typedef const struct Type24_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type24_mst;

typedef const struct Type25_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type25_mst;

typedef const struct Type26_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type26_mst;

typedef const struct Type27_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type27_mst;

typedef const struct Type29_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type29_mst;

typedef const struct Type30_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type30_mst;

typedef const struct Type33_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type33_mst;

typedef const struct Type34_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type34_mst;

typedef const struct Type35_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type35_mst;

typedef const struct Type38_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type38_mst;

typedef const struct Type41_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type41_mst;

typedef const struct Type42_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type42_mst;

typedef const struct Type44_mst
{
    UINT8  marshalType;
    UINT8  modifiers;
    UINT8  errorCode;
    UINT32 values[2];
} Type44_mst;

// This structure combines all the individual marshaling structures to build
// something that can be referenced by offset rather than full address
typedef const struct MarshalData_st
{
    UintMarshal_mst                    UINT8_DATA;
    UintMarshal_mst                    UINT16_DATA;
    UintMarshal_mst                    UINT32_DATA;
    UintMarshal_mst                    UINT64_DATA;
    UintMarshal_mst                    INT8_DATA;
    UintMarshal_mst                    INT16_DATA;
    UintMarshal_mst                    INT32_DATA;
    UintMarshal_mst                    INT64_DATA;
    UintMarshal_mst                    UINT0_DATA;
    MSSIM_ECC_CURVE_mst                  MSSIM_ECC_CURVE_DATA;
    MSSIM_CLOCK_ADJUST_mst               MSSIM_CLOCK_ADJUST_DATA;
    MSSIM_EO_mst                         MSSIM_EO_DATA;
    MSSIM_SU_mst                         MSSIM_SU_DATA;
    MSSIM_SE_mst                         MSSIM_SE_DATA;
    MSSIM_CAP_mst                        MSSIM_CAP_DATA;
    AttributesMarshal_mst              MSSIMA_ALGORITHM_DATA;
    AttributesMarshal_mst              MSSIMA_OBJECT_DATA;
    AttributesMarshal_mst              MSSIMA_SESSION_DATA;
    AttributesMarshal_mst              MSSIMA_ACT_DATA;
    MSSIMI_YES_NO_mst                    MSSIMI_YES_NO_DATA;
    MSSIMI_DH_OBJECT_mst                 MSSIMI_DH_OBJECT_DATA;
    MSSIMI_DH_PARENT_mst                 MSSIMI_DH_PARENT_DATA;
    MSSIMI_DH_PERSISTENT_mst             MSSIMI_DH_PERSISTENT_DATA;
    MSSIMI_DH_ENTITY_mst                 MSSIMI_DH_ENTITY_DATA;
    MSSIMI_DH_PCR_mst                    MSSIMI_DH_PCR_DATA;
    MSSIMI_SH_AUTH_SESSION_mst           MSSIMI_SH_AUTH_SESSION_DATA;
    MSSIMI_SH_HMAC_mst                   MSSIMI_SH_HMAC_DATA;
    MSSIMI_SH_POLICY_mst                 MSSIMI_SH_POLICY_DATA;
    MSSIMI_DH_CONTEXT_mst                MSSIMI_DH_CONTEXT_DATA;
    MSSIMI_DH_SAVED_mst                  MSSIMI_DH_SAVED_DATA;
    MSSIMI_RH_HIERARCHY_mst              MSSIMI_RH_HIERARCHY_DATA;
    MSSIMI_RH_ENABLES_mst                MSSIMI_RH_ENABLES_DATA;
    MSSIMI_RH_HIERARCHY_AUTH_mst         MSSIMI_RH_HIERARCHY_AUTH_DATA;
    MSSIMI_RH_HIERARCHY_POLICY_mst       MSSIMI_RH_HIERARCHY_POLICY_DATA;
    MSSIMI_RH_PLATFORM_mst               MSSIMI_RH_PLATFORM_DATA;
    MSSIMI_RH_OWNER_mst                  MSSIMI_RH_OWNER_DATA;
    MSSIMI_RH_ENDORSEMENT_mst            MSSIMI_RH_ENDORSEMENT_DATA;
    MSSIMI_RH_PROVISION_mst              MSSIMI_RH_PROVISION_DATA;
    MSSIMI_RH_CLEAR_mst                  MSSIMI_RH_CLEAR_DATA;
    MSSIMI_RH_NV_AUTH_mst                MSSIMI_RH_NV_AUTH_DATA;
    MSSIMI_RH_LOCKOUT_mst                MSSIMI_RH_LOCKOUT_DATA;
    MSSIMI_RH_NV_INDEX_mst               MSSIMI_RH_NV_INDEX_DATA;
    MSSIMI_RH_AC_mst                     MSSIMI_RH_AC_DATA;
    MSSIMI_RH_ACT_mst                    MSSIMI_RH_ACT_DATA;
    MSSIMI_ALG_HASH_mst                  MSSIMI_ALG_HASH_DATA;
    MSSIMI_ALG_ASYM_mst                  MSSIMI_ALG_ASYM_DATA;
    MSSIMI_ALG_SYM_mst                   MSSIMI_ALG_SYM_DATA;
    MSSIMI_ALG_SYM_OBJECT_mst            MSSIMI_ALG_SYM_OBJECT_DATA;
    MSSIMI_ALG_SYM_MODE_mst              MSSIMI_ALG_SYM_MODE_DATA;
    MSSIMI_ALG_KDF_mst                   MSSIMI_ALG_KDF_DATA;
    MSSIMI_ALG_SIG_SCHEME_mst            MSSIMI_ALG_SIG_SCHEME_DATA;
    MSSIMI_ECC_KEY_EXCHANGE_mst          MSSIMI_ECC_KEY_EXCHANGE_DATA;
    MSSIMI_ST_COMMAND_TAG_mst            MSSIMI_ST_COMMAND_TAG_DATA;
    MSSIMI_ALG_MAC_SCHEME_mst            MSSIMI_ALG_MAC_SCHEME_DATA;
    MSSIMI_ALG_CIPHER_MODE_mst           MSSIMI_ALG_CIPHER_MODE_DATA;
    MSSIMS_EMPTY_mst                     MSSIMS_EMPTY_DATA;
    MSSIMS_ALGORITHM_DESCRIPTION_mst     MSSIMS_ALGORITHM_DESCRIPTION_DATA;
    MSSIMU_HA_mst                        MSSIMU_HA_DATA;
    MSSIMT_HA_mst                        MSSIMT_HA_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_DIGEST_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_DATA_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_EVENT_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_MAX_BUFFER_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_MAX_NV_BUFFER_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_TIMEOUT_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_IV_DATA;
    NullUnionMarshal_mst               NULL_UNION_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_NAME_DATA;
    MSSIMS_PCR_SELECT_mst                MSSIMS_PCR_SELECT_DATA;
    MSSIMS_PCR_SELECTION_mst             MSSIMS_PCR_SELECTION_DATA;
    MSSIMT_TK_CREATION_mst               MSSIMT_TK_CREATION_DATA;
    MSSIMT_TK_VERIFIED_mst               MSSIMT_TK_VERIFIED_DATA;
    MSSIMT_TK_AUTH_mst                   MSSIMT_TK_AUTH_DATA;
    MSSIMT_TK_HASHCHECK_mst              MSSIMT_TK_HASHCHECK_DATA;
    MSSIMS_ALG_PROPERTY_mst              MSSIMS_ALG_PROPERTY_DATA;
    MSSIMS_TAGGED_PROPERTY_mst           MSSIMS_TAGGED_PROPERTY_DATA;
    MSSIMS_TAGGED_PCR_SELECT_mst         MSSIMS_TAGGED_PCR_SELECT_DATA;
    MSSIMS_TAGGED_POLICY_mst             MSSIMS_TAGGED_POLICY_DATA;
    MSSIMS_ACT_DATA_mst                  MSSIMS_ACT_DATA_DATA;
    ListMarshal_mst                    MSSIML_CC_DATA;
    ListMarshal_mst                    MSSIML_CCA_DATA;
    ListMarshal_mst                    MSSIML_ALG_DATA;
    ListMarshal_mst                    MSSIML_HANDLE_DATA;
    ListMarshal_mst                    MSSIML_DIGEST_DATA;
    ListMarshal_mst                    MSSIML_DIGEST_VALUES_DATA;
    ListMarshal_mst                    MSSIML_PCR_SELECTION_DATA;
    ListMarshal_mst                    MSSIML_ALG_PROPERTY_DATA;
    ListMarshal_mst                    MSSIML_TAGGED_MSSIM_PROPERTY_DATA;
    ListMarshal_mst                    MSSIML_TAGGED_PCR_PROPERTY_DATA;
    ListMarshal_mst                    MSSIML_ECC_CURVE_DATA;
    ListMarshal_mst                    MSSIML_TAGGED_POLICY_DATA;
    ListMarshal_mst                    MSSIML_ACT_DATA_DATA;
    MSSIMU_CAPABILITIES_mst              MSSIMU_CAPABILITIES_DATA;
    MSSIMS_CAPABILITY_DATA_mst           MSSIMS_CAPABILITY_DATA_DATA;
    MSSIMS_CLOCK_INFO_mst                MSSIMS_CLOCK_INFO_DATA;
    MSSIMS_TIME_INFO_mst                 MSSIMS_TIME_INFO_DATA;
    MSSIMS_TIME_ATTEST_INFO_mst          MSSIMS_TIME_ATTEST_INFO_DATA;
    MSSIMS_CERTIFY_INFO_mst              MSSIMS_CERTIFY_INFO_DATA;
    MSSIMS_QUOTE_INFO_mst                MSSIMS_QUOTE_INFO_DATA;
    MSSIMS_COMMAND_AUDIT_INFO_mst        MSSIMS_COMMAND_AUDIT_INFO_DATA;
    MSSIMS_SESSION_AUDIT_INFO_mst        MSSIMS_SESSION_AUDIT_INFO_DATA;
    MSSIMS_CREATION_INFO_mst             MSSIMS_CREATION_INFO_DATA;
    MSSIMS_NV_CERTIFY_INFO_mst           MSSIMS_NV_CERTIFY_INFO_DATA;
    MSSIMS_NV_DIGEST_CERTIFY_INFO_mst    MSSIMS_NV_DIGEST_CERTIFY_INFO_DATA;
    MSSIMI_ST_ATTEST_mst                 MSSIMI_ST_ATTEST_DATA;
    MSSIMU_ATTEST_mst                    MSSIMU_ATTEST_DATA;
    MSSIMS_ATTEST_mst                    MSSIMS_ATTEST_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_ATTEST_DATA;
    MSSIMS_AUTH_COMMAND_mst              MSSIMS_AUTH_COMMAND_DATA;
    MSSIMS_AUTH_RESPONSE_mst             MSSIMS_AUTH_RESPONSE_DATA;
    MSSIMI_TDES_KEY_BITS_mst             MSSIMI_TDES_KEY_BITS_DATA;
    MSSIMI_AES_KEY_BITS_mst              MSSIMI_AES_KEY_BITS_DATA;
    MSSIMI_SM4_KEY_BITS_mst              MSSIMI_SM4_KEY_BITS_DATA;
    MSSIMI_CAMELLIA_KEY_BITS_mst         MSSIMI_CAMELLIA_KEY_BITS_DATA;
    MSSIMU_SYM_KEY_BITS_mst              MSSIMU_SYM_KEY_BITS_DATA;
    MSSIMU_SYM_MODE_mst                  MSSIMU_SYM_MODE_DATA;
    MSSIMT_SYM_DEF_mst                   MSSIMT_SYM_DEF_DATA;
    MSSIMT_SYM_DEF_OBJECT_mst            MSSIMT_SYM_DEF_OBJECT_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_SYM_KEY_DATA;
    MSSIMS_SYMCIPHER_PARMS_mst           MSSIMS_SYMCIPHER_PARMS_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_LABEL_DATA;
    MSSIMS_DERIVE_mst                    MSSIMS_DERIVE_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_DERIVE_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_SENSITIVE_DATA_DATA;
    MSSIMS_SENSITIVE_CREATE_mst          MSSIMS_SENSITIVE_CREATE_DATA;
    Tpm2bsMarshal_mst                  MSSIM2B_SENSITIVE_CREATE_DATA;
    MSSIMS_SCHEME_HASH_mst               MSSIMS_SCHEME_HASH_DATA;
    MSSIMS_SCHEME_ECDAA_mst              MSSIMS_SCHEME_ECDAA_DATA;
    MSSIMI_ALG_KEYEDHASH_SCHEME_mst      MSSIMI_ALG_KEYEDHASH_SCHEME_DATA;
    MSSIMS_SCHEME_XOR_mst                MSSIMS_SCHEME_XOR_DATA;
    MSSIMU_SCHEME_KEYEDHASH_mst          MSSIMU_SCHEME_KEYEDHASH_DATA;
    MSSIMT_KEYEDHASH_SCHEME_mst          MSSIMT_KEYEDHASH_SCHEME_DATA;
    MSSIMU_SIG_SCHEME_mst                MSSIMU_SIG_SCHEME_DATA;
    MSSIMT_SIG_SCHEME_mst                MSSIMT_SIG_SCHEME_DATA;
    MSSIMU_KDF_SCHEME_mst                MSSIMU_KDF_SCHEME_DATA;
    MSSIMT_KDF_SCHEME_mst                MSSIMT_KDF_SCHEME_DATA;
    MSSIMI_ALG_ASYM_SCHEME_mst           MSSIMI_ALG_ASYM_SCHEME_DATA;
    MSSIMU_ASYM_SCHEME_mst               MSSIMU_ASYM_SCHEME_DATA;
    MSSIMI_ALG_RSA_SCHEME_mst            MSSIMI_ALG_RSA_SCHEME_DATA;
    MSSIMT_RSA_SCHEME_mst                MSSIMT_RSA_SCHEME_DATA;
    MSSIMI_ALG_RSA_DECRYPT_mst           MSSIMI_ALG_RSA_DECRYPT_DATA;
    MSSIMT_RSA_DECRYPT_mst               MSSIMT_RSA_DECRYPT_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_PUBLIC_KEY_RSA_DATA;
    MSSIMI_RSA_KEY_BITS_mst              MSSIMI_RSA_KEY_BITS_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_PRIVATE_KEY_RSA_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_ECC_PARAMETER_DATA;
    MSSIMS_ECC_POINT_mst                 MSSIMS_ECC_POINT_DATA;
    Tpm2bsMarshal_mst                  MSSIM2B_ECC_POINT_DATA;
    MSSIMI_ALG_ECC_SCHEME_mst            MSSIMI_ALG_ECC_SCHEME_DATA;
    MSSIMI_ECC_CURVE_mst                 MSSIMI_ECC_CURVE_DATA;
    MSSIMT_ECC_SCHEME_mst                MSSIMT_ECC_SCHEME_DATA;
    MSSIMS_ALGORITHM_DETAIL_ECC_mst      MSSIMS_ALGORITHM_DETAIL_ECC_DATA;
    MSSIMS_SIGNATURE_RSA_mst             MSSIMS_SIGNATURE_RSA_DATA;
    MSSIMS_SIGNATURE_ECC_mst             MSSIMS_SIGNATURE_ECC_DATA;
    MSSIMU_SIGNATURE_mst                 MSSIMU_SIGNATURE_DATA;
    MSSIMT_SIGNATURE_mst                 MSSIMT_SIGNATURE_DATA;
    MSSIMU_ENCRYPTED_SECRET_mst          MSSIMU_ENCRYPTED_SECRET_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_ENCRYPTED_SECRET_DATA;
    MSSIMI_ALG_PUBLIC_mst                MSSIMI_ALG_PUBLIC_DATA;
    MSSIMU_PUBLIC_ID_mst                 MSSIMU_PUBLIC_ID_DATA;
    MSSIMS_KEYEDHASH_PARMS_mst           MSSIMS_KEYEDHASH_PARMS_DATA;
    MSSIMS_RSA_PARMS_mst                 MSSIMS_RSA_PARMS_DATA;
    MSSIMS_ECC_PARMS_mst                 MSSIMS_ECC_PARMS_DATA;
    MSSIMU_PUBLIC_PARMS_mst              MSSIMU_PUBLIC_PARMS_DATA;
    MSSIMT_PUBLIC_PARMS_mst              MSSIMT_PUBLIC_PARMS_DATA;
    MSSIMT_PUBLIC_mst                    MSSIMT_PUBLIC_DATA;
    Tpm2bsMarshal_mst                  MSSIM2B_PUBLIC_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_TEMPLATE_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_PRIVATE_VENDOR_SPECIFIC_DATA;
    MSSIMU_SENSITIVE_COMPOSITE_mst       MSSIMU_SENSITIVE_COMPOSITE_DATA;
    MSSIMT_SENSITIVE_mst                 MSSIMT_SENSITIVE_DATA;
    Tpm2bsMarshal_mst                  MSSIM2B_SENSITIVE_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_PRIVATE_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_ID_OBJECT_DATA;
    MSSIMS_NV_PIN_COUNTER_PARAMETERS_mst MSSIMS_NV_PIN_COUNTER_PARAMETERS_DATA;
    AttributesMarshal_mst              MSSIMA_NV_DATA;
    MSSIMS_NV_PUBLIC_mst                 MSSIMS_NV_PUBLIC_DATA;
    Tpm2bsMarshal_mst                  MSSIM2B_NV_PUBLIC_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_CONTEXT_SENSITIVE_DATA;
    MSSIMS_CONTEXT_DATA_mst              MSSIMS_CONTEXT_DATA_DATA;
    Tpm2bMarshal_mst                   MSSIM2B_CONTEXT_DATA_DATA;
    MSSIMS_CONTEXT_mst                   MSSIMS_CONTEXT_DATA;
    MSSIMS_CREATION_DATA_mst             MSSIMS_CREATION_DATA_DATA;
    Tpm2bsMarshal_mst                  MSSIM2B_CREATION_DATA_DATA;
    MSSIM_AT_mst                         MSSIM_AT_DATA;
    MSSIMS_AC_OUTPUT_mst                 MSSIMS_AC_OUTPUT_DATA;
    ListMarshal_mst                    MSSIML_AC_CAPABILITIES_DATA;
    MinMaxMarshal_mst                  Type00_DATA;
    MinMaxMarshal_mst                  Type01_DATA;
    Type02_mst                         Type02_DATA;
    Type03_mst                         Type03_DATA;
    Type04_mst                         Type04_DATA;
    MinMaxMarshal_mst                  Type05_DATA;
    Type06_mst                         Type06_DATA;
    MinMaxMarshal_mst                  Type07_DATA;
    Type08_mst                         Type08_DATA;
    Type10_mst                         Type10_DATA;
    Type11_mst                         Type11_DATA;
    Type12_mst                         Type12_DATA;
    Type13_mst                         Type13_DATA;
    Type15_mst                         Type15_DATA;
    Type17_mst                         Type17_DATA;
    Type18_mst                         Type18_DATA;
    Type19_mst                         Type19_DATA;
    Type20_mst                         Type20_DATA;
    Type22_mst                         Type22_DATA;
    Type23_mst                         Type23_DATA;
    Type24_mst                         Type24_DATA;
    Type25_mst                         Type25_DATA;
    Type26_mst                         Type26_DATA;
    Type27_mst                         Type27_DATA;
    MinMaxMarshal_mst                  Type28_DATA;
    Type29_mst                         Type29_DATA;
    Type30_mst                         Type30_DATA;
    MinMaxMarshal_mst                  Type31_DATA;
    MinMaxMarshal_mst                  Type32_DATA;
    Type33_mst                         Type33_DATA;
    Type34_mst                         Type34_DATA;
    Type35_mst                         Type35_DATA;
    MinMaxMarshal_mst                  Type36_DATA;
    MinMaxMarshal_mst                  Type37_DATA;
    Type38_mst                         Type38_DATA;
    MinMaxMarshal_mst                  Type39_DATA;
    MinMaxMarshal_mst                  Type40_DATA;
    Type41_mst                         Type41_DATA;
    Type42_mst                         Type42_DATA;
    MinMaxMarshal_mst                  Type43_DATA;
    Type44_mst                         Type44_DATA;
} MarshalData_st;

#endif  // _TABLE_MARSHAL_TYPES_H_
