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
 *  Created by TpmMarshal; Version 4.1 Dec 10, 2018
 *  Date: Mar  6, 2020  Time: 01:50:10PM
 */

#include "Tpm.h"
#if !TABLE_DRIVEN_MARSHAL
#  include "Marshal_fp.h"

// Table 2:3 - Definition of Base Types
//   UINT8 definition from table 2:3
MSSIM_RC
UINT8_Unmarshal(UINT8* target, BYTE** buffer, INT32* size)
{
    if((*size -= 1) < 0)
        return MSSIM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT8(*buffer);
    *buffer += 1;
    return MSSIM_RC_SUCCESS;
}
UINT16
UINT8_Marshal(UINT8* source, BYTE** buffer, INT32* size)
{
    if(buffer != 0)
    {
        if((size == 0) || ((*size -= 1) >= 0))
        {
            UINT8_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 1;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (1);
}

//   BYTE definition from table 2:3
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
BYTE_Unmarshal(BYTE* target, BYTE** buffer, INT32* size)
{
    return UINT8_Unmarshal((UINT8*)target, buffer, size);
}
UINT16
BYTE_Marshal(BYTE* source, BYTE** buffer, INT32* size)
{
    return UINT8_Marshal((UINT8*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

//   INT8 definition from table 2:3
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
INT8_Unmarshal(INT8* target, BYTE** buffer, INT32* size)
{
    return UINT8_Unmarshal((UINT8*)target, buffer, size);
}
UINT16
INT8_Marshal(INT8* source, BYTE** buffer, INT32* size)
{
    return UINT8_Marshal((UINT8*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

//   UINT16 definition from table 2:3
MSSIM_RC
UINT16_Unmarshal(UINT16* target, BYTE** buffer, INT32* size)
{
    if((*size -= 2) < 0)
        return MSSIM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT16(*buffer);
    *buffer += 2;
    return MSSIM_RC_SUCCESS;
}
UINT16
UINT16_Marshal(UINT16* source, BYTE** buffer, INT32* size)
{
    if(buffer != 0)
    {
        if((size == 0) || ((*size -= 2) >= 0))
        {
            UINT16_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 2;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (2);
}

//   INT16 definition from table 2:3
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
INT16_Unmarshal(INT16* target, BYTE** buffer, INT32* size)
{
    return UINT16_Unmarshal((UINT16*)target, buffer, size);
}
UINT16
INT16_Marshal(INT16* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

//   UINT32 definition from table 2:3
MSSIM_RC
UINT32_Unmarshal(UINT32* target, BYTE** buffer, INT32* size)
{
    if((*size -= 4) < 0)
        return MSSIM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT32(*buffer);
    *buffer += 4;
    return MSSIM_RC_SUCCESS;
}
UINT16
UINT32_Marshal(UINT32* source, BYTE** buffer, INT32* size)
{
    if(buffer != 0)
    {
        if((size == 0) || ((*size -= 4) >= 0))
        {
            UINT32_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 4;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (4);
}

//   INT32 definition from table 2:3
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
INT32_Unmarshal(INT32* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
INT32_Marshal(INT32* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

//   UINT64 definition from table 2:3
MSSIM_RC
UINT64_Unmarshal(UINT64* target, BYTE** buffer, INT32* size)
{
    if((*size -= 8) < 0)
        return MSSIM_RC_INSUFFICIENT;
    *target = BYTE_ARRAY_TO_UINT64(*buffer);
    *buffer += 8;
    return MSSIM_RC_SUCCESS;
}
UINT16
UINT64_Marshal(UINT64* source, BYTE** buffer, INT32* size)
{
    if(buffer != 0)
    {
        if((size == 0) || ((*size -= 8) >= 0))
        {
            UINT64_TO_BYTE_ARRAY(*source, *buffer);
            *buffer += 8;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    return (8);
}

//   INT64 definition from table 2:3
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
INT64_Unmarshal(INT64* target, BYTE** buffer, INT32* size)
{
    return UINT64_Unmarshal((UINT64*)target, buffer, size);
}
UINT16
INT64_Marshal(INT64* source, BYTE** buffer, INT32* size)
{
    return UINT64_Marshal((UINT64*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:4 - Defines for Logic Values
// Table 2:5 - Definition of Types for Documentation Clarity
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_ALGORITHM_ID_Unmarshal(MSSIM_ALGORITHM_ID* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_ALGORITHM_ID_Marshal(MSSIM_ALGORITHM_ID* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
MSSIM_RC
MSSIM_MODIFIER_INDICATOR_Unmarshal(
    MSSIM_MODIFIER_INDICATOR* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_MODIFIER_INDICATOR_Marshal(
    MSSIM_MODIFIER_INDICATOR* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
MSSIM_RC
MSSIM_AUTHORIZATION_SIZE_Unmarshal(
    MSSIM_AUTHORIZATION_SIZE* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_AUTHORIZATION_SIZE_Marshal(
    MSSIM_AUTHORIZATION_SIZE* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
MSSIM_RC
MSSIM_PARAMETER_SIZE_Unmarshal(MSSIM_PARAMETER_SIZE* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_PARAMETER_SIZE_Marshal(MSSIM_PARAMETER_SIZE* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
MSSIM_RC
MSSIM_KEY_SIZE_Unmarshal(MSSIM_KEY_SIZE* target, BYTE** buffer, INT32* size)
{
    return UINT16_Unmarshal((UINT16*)target, buffer, size);
}
UINT16
MSSIM_KEY_SIZE_Marshal(MSSIM_KEY_SIZE* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
MSSIM_RC
MSSIM_KEY_BITS_Unmarshal(MSSIM_KEY_BITS* target, BYTE** buffer, INT32* size)
{
    return UINT16_Unmarshal((UINT16*)target, buffer, size);
}
UINT16
MSSIM_KEY_BITS_Marshal(MSSIM_KEY_BITS* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:6 - Definition of MSSIM_SPEC Constants
// Table 2:7 - Definition of MSSIM_CONSTANTS32 Constants
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_CONSTANTS32_Marshal(MSSIM_CONSTANTS32* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:9 - Definition of MSSIM_ALG_ID Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_ALG_ID_Unmarshal(MSSIM_ALG_ID* target, BYTE** buffer, INT32* size)
{
    return UINT16_Unmarshal((UINT16*)target, buffer, size);
}
UINT16
MSSIM_ALG_ID_Marshal(MSSIM_ALG_ID* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:10 - Definition of MSSIM_ECC_CURVE Constants
#  if ALG_ECC
MSSIM_RC
MSSIM_ECC_CURVE_Unmarshal(MSSIM_ECC_CURVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_ECC_NIST_P192:
            case MSSIM_ECC_NIST_P224:
            case MSSIM_ECC_NIST_P256:
            case MSSIM_ECC_NIST_P384:
            case MSSIM_ECC_NIST_P521:
            case MSSIM_ECC_BN_P256:
            case MSSIM_ECC_BN_P638:
            case MSSIM_ECC_SM2_P256:
                break;
            default:
                result = MSSIM_RC_CURVE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIM_ECC_CURVE_Marshal(MSSIM_ECC_CURVE* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:12 - Definition of MSSIM_CC Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_CC_Unmarshal(MSSIM_CC* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_CC_Marshal(MSSIM_CC* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:16 - Definition of MSSIM_RC Constants
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_RC_Marshal(MSSIM_RC* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:17 - Definition of MSSIM_CLOCK_ADJUST Constants
MSSIM_RC
MSSIM_CLOCK_ADJUST_Unmarshal(MSSIM_CLOCK_ADJUST* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = INT8_Unmarshal((INT8*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_CLOCK_COARSE_SLOWER:
            case MSSIM_CLOCK_MEDIUM_SLOWER:
            case MSSIM_CLOCK_FINE_SLOWER:
            case MSSIM_CLOCK_NO_CHANGE:
            case MSSIM_CLOCK_FINE_FASTER:
            case MSSIM_CLOCK_MEDIUM_FASTER:
            case MSSIM_CLOCK_COARSE_FASTER:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:18 - Definition of MSSIM_EO Constants
MSSIM_RC
MSSIM_EO_Unmarshal(MSSIM_EO* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_EO_EQ:
            case MSSIM_EO_NEQ:
            case MSSIM_EO_SIGNED_GT:
            case MSSIM_EO_UNSIGNED_GT:
            case MSSIM_EO_SIGNED_LT:
            case MSSIM_EO_UNSIGNED_LT:
            case MSSIM_EO_SIGNED_GE:
            case MSSIM_EO_UNSIGNED_GE:
            case MSSIM_EO_SIGNED_LE:
            case MSSIM_EO_UNSIGNED_LE:
            case MSSIM_EO_BITSET:
            case MSSIM_EO_BITCLEAR:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_EO_Marshal(MSSIM_EO* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:19 - Definition of MSSIM_ST Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_ST_Unmarshal(MSSIM_ST* target, BYTE** buffer, INT32* size)
{
    return UINT16_Unmarshal((UINT16*)target, buffer, size);
}
UINT16
MSSIM_ST_Marshal(MSSIM_ST* source, BYTE** buffer, INT32* size)
{
    return UINT16_Marshal((UINT16*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:20 - Definition of MSSIM_SU Constants
MSSIM_RC
MSSIM_SU_Unmarshal(MSSIM_SU* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_SU_CLEAR:
            case MSSIM_SU_STATE:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:21 - Definition of MSSIM_SE Constants
MSSIM_RC
MSSIM_SE_Unmarshal(MSSIM_SE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT8_Unmarshal((UINT8*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_SE_HMAC:
            case MSSIM_SE_POLICY:
            case MSSIM_SE_TRIAL:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:22 - Definition of MSSIM_CAP Constants
MSSIM_RC
MSSIM_CAP_Unmarshal(MSSIM_CAP* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_CAP_ALGS:
            case MSSIM_CAP_HANDLES:
            case MSSIM_CAP_COMMANDS:
            case MSSIM_CAP_PP_COMMANDS:
            case MSSIM_CAP_AUDIT_COMMANDS:
            case MSSIM_CAP_PCRS:
            case MSSIM_CAP_MSSIM_PROPERTIES:
            case MSSIM_CAP_PCR_PROPERTIES:
            case MSSIM_CAP_ECC_CURVES:
            case MSSIM_CAP_AUTH_POLICIES:
            case MSSIM_CAP_ACT:
            case MSSIM_CAP_VENDOR_PROPERTY:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_CAP_Marshal(MSSIM_CAP* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:23 - Definition of MSSIM_PT Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_PT_Unmarshal(MSSIM_PT* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_PT_Marshal(MSSIM_PT* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:24 - Definition of MSSIM_PT_PCR Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_PT_PCR_Unmarshal(MSSIM_PT_PCR* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_PT_PCR_Marshal(MSSIM_PT_PCR* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:25 - Definition of MSSIM_PS Constants
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_PS_Marshal(MSSIM_PS* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:26 - Definition of Types for Handles
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_HANDLE_Unmarshal(MSSIM_HANDLE* target, BYTE** buffer, INT32* size)
{
    return UINT32_Unmarshal((UINT32*)target, buffer, size);
}
UINT16
MSSIM_HANDLE_Marshal(MSSIM_HANDLE* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:27 - Definition of MSSIM_HT Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_HT_Unmarshal(MSSIM_HT* target, BYTE** buffer, INT32* size)
{
    return UINT8_Unmarshal((UINT8*)target, buffer, size);
}
UINT16
MSSIM_HT_Marshal(MSSIM_HT* source, BYTE** buffer, INT32* size)
{
    return UINT8_Marshal((UINT8*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:28 - Definition of MSSIM_RH Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_RH_Unmarshal(MSSIM_RH* target, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
}
UINT16
MSSIM_RH_Marshal(MSSIM_RH* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:29 - Definition of MSSIM_HC Constants
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_HC_Unmarshal(MSSIM_HC* target, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
}
UINT16
MSSIM_HC_Marshal(MSSIM_HC* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:30 - Definition of MSSIMA_ALGORITHM Bits
MSSIM_RC
MSSIMA_ALGORITHM_Unmarshal(MSSIMA_ALGORITHM* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*((UINT32*)target) & (UINT32)0xfffff8f0)
            result = MSSIM_RC_RESERVED_BITS;
    }
    return result;
}

#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_ALGORITHM_Marshal(MSSIMA_ALGORITHM* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:31 - Definition of MSSIMA_OBJECT Bits
MSSIM_RC
MSSIMA_OBJECT_Unmarshal(MSSIMA_OBJECT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*((UINT32*)target) & (UINT32)0xfff0f309)
            result = MSSIM_RC_RESERVED_BITS;
    }
    return result;
}

#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_OBJECT_Marshal(MSSIMA_OBJECT* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:32 - Definition of MSSIMA_SESSION Bits
MSSIM_RC
MSSIMA_SESSION_Unmarshal(MSSIMA_SESSION* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT8_Unmarshal((UINT8*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*((UINT8*)target) & (UINT8)0x18)
            result = MSSIM_RC_RESERVED_BITS;
    }
    return result;
}

#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_SESSION_Marshal(MSSIMA_SESSION* source, BYTE** buffer, INT32* size)
{
    return UINT8_Marshal((UINT8*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:33 - Definition of MSSIMA_LOCALITY Bits
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMA_LOCALITY_Unmarshal(MSSIMA_LOCALITY* target, BYTE** buffer, INT32* size)
{
    return UINT8_Unmarshal((UINT8*)target, buffer, size);
}
UINT16
MSSIMA_LOCALITY_Marshal(MSSIMA_LOCALITY* source, BYTE** buffer, INT32* size)
{
    return UINT8_Marshal((UINT8*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:34 - Definition of MSSIMA_PERMANENT Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_PERMANENT_Marshal(MSSIMA_PERMANENT* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:35 - Definition of MSSIMA_STARTUP_CLEAR Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_STARTUP_CLEAR_Marshal(MSSIMA_STARTUP_CLEAR* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:36 - Definition of MSSIMA_MEMORY Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_MEMORY_Marshal(MSSIMA_MEMORY* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:37 - Definition of MSSIMA_CC Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_CC_Marshal(MSSIMA_CC* source, BYTE** buffer, INT32* size)
{
    return MSSIM_CC_Marshal((MSSIM_CC*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:38 - Definition of MSSIMA_MODES Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_MODES_Marshal(MSSIMA_MODES* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:39 - Definition of MSSIMA_X509_KEY_USAGE Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_X509_KEY_USAGE_Marshal(MSSIMA_X509_KEY_USAGE* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:40 - Definition of MSSIMA_ACT Bits
MSSIM_RC
MSSIMA_ACT_Unmarshal(MSSIMA_ACT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*((UINT32*)target) & (UINT32)0xfffffffc)
            result = MSSIM_RC_RESERVED_BITS;
    }
    return result;
}

#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_ACT_Marshal(MSSIMA_ACT* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:41 - Definition of MSSIMI_YES_NO Type
MSSIM_RC
MSSIMI_YES_NO_Unmarshal(MSSIMI_YES_NO* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = BYTE_Unmarshal((BYTE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case NO:
            case YES:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_YES_NO_Marshal(MSSIMI_YES_NO* source, BYTE** buffer, INT32* size)
{
    return BYTE_Marshal((BYTE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:42 - Definition of MSSIMI_DH_OBJECT Type
MSSIM_RC
MSSIMI_DH_OBJECT_Unmarshal(
    MSSIMI_DH_OBJECT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*target == MSSIM_RH_NULL)
        {
            if(!flag)
                result = MSSIM_RC_VALUE;
        }
        else if(((*target < TRANSIENT_FIRST) || (*target > TRANSIENT_LAST))
                && ((*target < PERSISTENT_FIRST) || (*target > PERSISTENT_LAST)))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_OBJECT_Marshal(MSSIMI_DH_OBJECT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:43 - Definition of MSSIMI_DH_PARENT Type
MSSIM_RC
MSSIMI_DH_PARENT_Unmarshal(
    MSSIMI_DH_PARENT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_ENDORSEMENT:
                break;
            case MSSIM_RH_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                if(((*target < TRANSIENT_FIRST) || (*target > TRANSIENT_LAST))
                   && ((*target < PERSISTENT_FIRST) || (*target > PERSISTENT_LAST)))
                    result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_PARENT_Marshal(MSSIMI_DH_PARENT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:44 - Definition of MSSIMI_DH_PERSISTENT Type
MSSIM_RC
MSSIMI_DH_PERSISTENT_Unmarshal(MSSIMI_DH_PERSISTENT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((*target < PERSISTENT_FIRST) || (*target > PERSISTENT_LAST))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_PERSISTENT_Marshal(MSSIMI_DH_PERSISTENT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:45 - Definition of MSSIMI_DH_ENTITY Type
MSSIM_RC
MSSIMI_DH_ENTITY_Unmarshal(
    MSSIMI_DH_ENTITY* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_ENDORSEMENT:
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_LOCKOUT:
                break;
            case MSSIM_RH_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                if(((*target < TRANSIENT_FIRST) || (*target > TRANSIENT_LAST))
                   && ((*target < PERSISTENT_FIRST) || (*target > PERSISTENT_LAST))
                   && ((*target < NV_INDEX_FIRST) || (*target > NV_INDEX_LAST))
                   && (*target > PCR_LAST)
                   && ((*target < MSSIM_RH_AUTH_00) || (*target > MSSIM_RH_AUTH_FF)))
                    result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:46 - Definition of MSSIMI_DH_PCR Type
MSSIM_RC
MSSIMI_DH_PCR_Unmarshal(MSSIMI_DH_PCR* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*target == MSSIM_RH_NULL)
        {
            if(!flag)
                result = MSSIM_RC_VALUE;
        }
        else if(*target > PCR_LAST)
            result = MSSIM_RC_VALUE;
    }
    return result;
}

// Table 2:47 - Definition of MSSIMI_SH_AUTH_SESSION Type
MSSIM_RC
MSSIMI_SH_AUTH_SESSION_Unmarshal(
    MSSIMI_SH_AUTH_SESSION* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*target == MSSIM_RS_PW)
        {
            if(!flag)
                result = MSSIM_RC_VALUE;
        }
        else if(
            ((*target < HMAC_SESSION_FIRST) || (*target > HMAC_SESSION_LAST))
            && ((*target < POLICY_SESSION_FIRST) || (*target > POLICY_SESSION_LAST)))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SH_AUTH_SESSION_Marshal(MSSIMI_SH_AUTH_SESSION* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:48 - Definition of MSSIMI_SH_HMAC Type
MSSIM_RC
MSSIMI_SH_HMAC_Unmarshal(MSSIMI_SH_HMAC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((*target < HMAC_SESSION_FIRST) || (*target > HMAC_SESSION_LAST))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SH_HMAC_Marshal(MSSIMI_SH_HMAC* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:49 - Definition of MSSIMI_SH_POLICY Type
MSSIM_RC
MSSIMI_SH_POLICY_Unmarshal(MSSIMI_SH_POLICY* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((*target < POLICY_SESSION_FIRST) || (*target > POLICY_SESSION_LAST))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SH_POLICY_Marshal(MSSIMI_SH_POLICY* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:50 - Definition of MSSIMI_DH_CONTEXT Type
MSSIM_RC
MSSIMI_DH_CONTEXT_Unmarshal(MSSIMI_DH_CONTEXT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(((*target < HMAC_SESSION_FIRST) || (*target > HMAC_SESSION_LAST))
           && ((*target < POLICY_SESSION_FIRST) || (*target > POLICY_SESSION_LAST))
           && ((*target < TRANSIENT_FIRST) || (*target > TRANSIENT_LAST)))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_CONTEXT_Marshal(MSSIMI_DH_CONTEXT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:51 - Definition of MSSIMI_DH_SAVED Type
MSSIM_RC
MSSIMI_DH_SAVED_Unmarshal(MSSIMI_DH_SAVED* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case 0x80000000:
            case 0x80000001:
            case 0x80000002:
                break;
            default:
                if(((*target < HMAC_SESSION_FIRST) || (*target > HMAC_SESSION_LAST))
                   && ((*target < POLICY_SESSION_FIRST)
                       || (*target > POLICY_SESSION_LAST)))
                    result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_SAVED_Marshal(MSSIMI_DH_SAVED* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:52 - Definition of MSSIMI_RH_HIERARCHY Type
MSSIM_RC
MSSIMI_RH_HIERARCHY_Unmarshal(
    MSSIMI_RH_HIERARCHY* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_ENDORSEMENT:
                break;
            case MSSIM_RH_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_HIERARCHY_Marshal(MSSIMI_RH_HIERARCHY* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:53 - Definition of MSSIMI_RH_ENABLES Type
MSSIM_RC
MSSIMI_RH_ENABLES_Unmarshal(
    MSSIMI_RH_ENABLES* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_ENDORSEMENT:
            case MSSIM_RH_PLATFORM_NV:
                break;
            case MSSIM_RH_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_ENABLES_Marshal(MSSIMI_RH_ENABLES* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:54 - Definition of MSSIMI_RH_HIERARCHY_AUTH Type
MSSIM_RC
MSSIMI_RH_HIERARCHY_AUTH_Unmarshal(
    MSSIMI_RH_HIERARCHY_AUTH* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_ENDORSEMENT:
            case MSSIM_RH_LOCKOUT:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:55 - Definition of MSSIMI_RH_HIERARCHY_POLICY Type
MSSIM_RC
MSSIMI_RH_HIERARCHY_POLICY_Unmarshal(
    MSSIMI_RH_HIERARCHY_POLICY* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_ENDORSEMENT:
            case MSSIM_RH_LOCKOUT:
                break;
            default:
                if((*target < MSSIM_RH_ACT_0) || (*target > MSSIM_RH_ACT_F))
                    result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:56 - Definition of MSSIMI_RH_PLATFORM Type
MSSIM_RC
MSSIMI_RH_PLATFORM_Unmarshal(MSSIMI_RH_PLATFORM* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_PLATFORM:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:57 - Definition of MSSIMI_RH_OWNER Type
MSSIM_RC
MSSIMI_RH_OWNER_Unmarshal(MSSIMI_RH_OWNER* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
                break;
            case MSSIM_RH_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:58 - Definition of MSSIMI_RH_ENDORSEMENT Type
MSSIM_RC
MSSIMI_RH_ENDORSEMENT_Unmarshal(
    MSSIMI_RH_ENDORSEMENT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_ENDORSEMENT:
                break;
            case MSSIM_RH_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:59 - Definition of MSSIMI_RH_PROVISION Type
MSSIM_RC
MSSIMI_RH_PROVISION_Unmarshal(MSSIMI_RH_PROVISION* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_OWNER:
            case MSSIM_RH_PLATFORM:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:60 - Definition of MSSIMI_RH_CLEAR Type
MSSIM_RC
MSSIMI_RH_CLEAR_Unmarshal(MSSIMI_RH_CLEAR* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_LOCKOUT:
            case MSSIM_RH_PLATFORM:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:61 - Definition of MSSIMI_RH_NV_AUTH Type
MSSIM_RC
MSSIMI_RH_NV_AUTH_Unmarshal(MSSIMI_RH_NV_AUTH* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_PLATFORM:
            case MSSIM_RH_OWNER:
                break;
            default:
                if((*target < NV_INDEX_FIRST) || (*target > NV_INDEX_LAST))
                    result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:62 - Definition of MSSIMI_RH_LOCKOUT Type
MSSIM_RC
MSSIMI_RH_LOCKOUT_Unmarshal(MSSIMI_RH_LOCKOUT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_RH_LOCKOUT:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}

// Table 2:63 - Definition of MSSIMI_RH_NV_INDEX Type
MSSIM_RC
MSSIMI_RH_NV_INDEX_Unmarshal(MSSIMI_RH_NV_INDEX* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((*target < NV_INDEX_FIRST) || (*target > NV_INDEX_LAST))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_NV_INDEX_Marshal(MSSIMI_RH_NV_INDEX* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:64 - Definition of MSSIMI_RH_AC Type
MSSIM_RC
MSSIMI_RH_AC_Unmarshal(MSSIMI_RH_AC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((*target < AC_FIRST) || (*target > AC_LAST))
            result = MSSIM_RC_VALUE;
    }
    return result;
}

// Table 2:65 - Definition of MSSIMI_RH_ACT Type
MSSIM_RC
MSSIMI_RH_ACT_Unmarshal(MSSIMI_RH_ACT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((*target < MSSIM_RH_ACT_0) || (*target > MSSIM_RH_ACT_F))
            result = MSSIM_RC_VALUE;
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_ACT_Marshal(MSSIMI_RH_ACT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:66 - Definition of MSSIMI_ALG_HASH Type
MSSIM_RC
MSSIMI_ALG_HASH_Unmarshal(MSSIMI_ALG_HASH* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_SHA1
            case MSSIM_ALG_SHA1:
#  endif  // ALG_SHA1
#  if ALG_SHA256
            case MSSIM_ALG_SHA256:
#  endif  // ALG_SHA256
#  if ALG_SHA384
            case MSSIM_ALG_SHA384:
#  endif  // ALG_SHA384
#  if ALG_SHA512
            case MSSIM_ALG_SHA512:
#  endif  // ALG_SHA512
#  if ALG_SM3_256
            case MSSIM_ALG_SM3_256:
#  endif  // ALG_SM3_256
#  if ALG_SHA3_256
            case MSSIM_ALG_SHA3_256:
#  endif  // ALG_SHA3_256
#  if ALG_SHA3_384
            case MSSIM_ALG_SHA3_384:
#  endif  // ALG_SHA3_384
#  if ALG_SHA3_512
            case MSSIM_ALG_SHA3_512:
#  endif  // ALG_SHA3_512
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_HASH;
                break;
            default:
                result = MSSIM_RC_HASH;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_HASH_Marshal(MSSIMI_ALG_HASH* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:67 - Definition of MSSIMI_ALG_ASYM Type
MSSIM_RC
MSSIMI_ALG_ASYM_Unmarshal(MSSIMI_ALG_ASYM* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_RSA
            case MSSIM_ALG_RSA:
#  endif  // ALG_RSA
#  if ALG_ECC
            case MSSIM_ALG_ECC:
#  endif  // ALG_ECC
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_ASYMMETRIC;
                break;
            default:
                result = MSSIM_RC_ASYMMETRIC;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_ASYM_Marshal(MSSIMI_ALG_ASYM* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:68 - Definition of MSSIMI_ALG_SYM Type
MSSIM_RC
MSSIMI_ALG_SYM_Unmarshal(MSSIMI_ALG_SYM* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_TDES
            case MSSIM_ALG_TDES:
#  endif  // ALG_TDES
#  if ALG_AES
            case MSSIM_ALG_AES:
#  endif  // ALG_AES
#  if ALG_SM4
            case MSSIM_ALG_SM4:
#  endif  // ALG_SM4
#  if ALG_CAMELLIA
            case MSSIM_ALG_CAMELLIA:
#  endif  // ALG_CAMELLIA
#  if ALG_XOR
            case MSSIM_ALG_XOR:
#  endif  // ALG_XOR
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_SYMMETRIC;
                break;
            default:
                result = MSSIM_RC_SYMMETRIC;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SYM_Marshal(MSSIMI_ALG_SYM* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:69 - Definition of MSSIMI_ALG_SYM_OBJECT Type
MSSIM_RC
MSSIMI_ALG_SYM_OBJECT_Unmarshal(
    MSSIMI_ALG_SYM_OBJECT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_TDES
            case MSSIM_ALG_TDES:
#  endif  // ALG_TDES
#  if ALG_AES
            case MSSIM_ALG_AES:
#  endif  // ALG_AES
#  if ALG_SM4
            case MSSIM_ALG_SM4:
#  endif  // ALG_SM4
#  if ALG_CAMELLIA
            case MSSIM_ALG_CAMELLIA:
#  endif  // ALG_CAMELLIA
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_SYMMETRIC;
                break;
            default:
                result = MSSIM_RC_SYMMETRIC;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SYM_OBJECT_Marshal(MSSIMI_ALG_SYM_OBJECT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:70 - Definition of MSSIMI_ALG_SYM_MODE Type
MSSIM_RC
MSSIMI_ALG_SYM_MODE_Unmarshal(
    MSSIMI_ALG_SYM_MODE* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_CTR
            case MSSIM_ALG_CTR:
#  endif  // ALG_CTR
#  if ALG_OFB
            case MSSIM_ALG_OFB:
#  endif  // ALG_OFB
#  if ALG_CBC
            case MSSIM_ALG_CBC:
#  endif  // ALG_CBC
#  if ALG_CFB
            case MSSIM_ALG_CFB:
#  endif  // ALG_CFB
#  if ALG_ECB
            case MSSIM_ALG_ECB:
#  endif  // ALG_ECB
#  if ALG_CMAC
            case MSSIM_ALG_CMAC:
#  endif  // ALG_CMAC
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_MODE;
                break;
            default:
                result = MSSIM_RC_MODE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SYM_MODE_Marshal(MSSIMI_ALG_SYM_MODE* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:71 - Definition of MSSIMI_ALG_KDF Type
MSSIM_RC
MSSIMI_ALG_KDF_Unmarshal(MSSIMI_ALG_KDF* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_MGF1
            case MSSIM_ALG_MGF1:
#  endif  // ALG_MGF1
#  if ALG_KDF1_SP800_56A
            case MSSIM_ALG_KDF1_SP800_56A:
#  endif  // ALG_KDF1_SP800_56A
#  if ALG_KDF2
            case MSSIM_ALG_KDF2:
#  endif  // ALG_KDF2
#  if ALG_KDF1_SP800_108
            case MSSIM_ALG_KDF1_SP800_108:
#  endif  // ALG_KDF1_SP800_108
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_KDF;
                break;
            default:
                result = MSSIM_RC_KDF;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_KDF_Marshal(MSSIMI_ALG_KDF* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:72 - Definition of MSSIMI_ALG_SIG_SCHEME Type
MSSIM_RC
MSSIMI_ALG_SIG_SCHEME_Unmarshal(
    MSSIMI_ALG_SIG_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_ECDAA
            case MSSIM_ALG_ECDAA:
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
            case MSSIM_ALG_RSASSA:
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
            case MSSIM_ALG_RSAPSS:
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
            case MSSIM_ALG_ECDSA:
#  endif  // ALG_ECDSA
#  if ALG_SM2
            case MSSIM_ALG_SM2:
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
            case MSSIM_ALG_ECSCHNORR:
#  endif  // ALG_ECSCHNORR
#  if ALG_HMAC
            case MSSIM_ALG_HMAC:
#  endif  // ALG_HMAC
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_SCHEME;
                break;
            default:
                result = MSSIM_RC_SCHEME;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SIG_SCHEME_Marshal(MSSIMI_ALG_SIG_SCHEME* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:73 - Definition of MSSIMI_ECC_KEY_EXCHANGE Type
#  if ALG_ECC
MSSIM_RC
MSSIMI_ECC_KEY_EXCHANGE_Unmarshal(
    MSSIMI_ECC_KEY_EXCHANGE* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if ALG_ECDH
            case MSSIM_ALG_ECDH:
#    endif  // ALG_ECDH
#    if ALG_ECMQV
            case MSSIM_ALG_ECMQV:
#    endif  // ALG_ECMQV
#    if ALG_SM2
            case MSSIM_ALG_SM2:
#    endif  // ALG_SM2
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_SCHEME;
                break;
            default:
                result = MSSIM_RC_SCHEME;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ECC_KEY_EXCHANGE_Marshal(
    MSSIMI_ECC_KEY_EXCHANGE* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:74 - Definition of MSSIMI_ST_COMMAND_TAG Type
MSSIM_RC
MSSIMI_ST_COMMAND_TAG_Unmarshal(MSSIMI_ST_COMMAND_TAG* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ST_Unmarshal((MSSIM_ST*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_ST_NO_SESSIONS:
            case MSSIM_ST_SESSIONS:
                break;
            default:
                result = MSSIM_RC_BAD_TAG;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ST_COMMAND_TAG_Marshal(MSSIMI_ST_COMMAND_TAG* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ST_Marshal((MSSIM_ST*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:75 - Definition of MSSIMI_ALG_MAC_SCHEME Type
MSSIM_RC
MSSIMI_ALG_MAC_SCHEME_Unmarshal(
    MSSIMI_ALG_MAC_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_CMAC
            case MSSIM_ALG_CMAC:
#  endif  // ALG_CMAC
#  if ALG_SHA1
            case MSSIM_ALG_SHA1:
#  endif  // ALG_SHA1
#  if ALG_SHA256
            case MSSIM_ALG_SHA256:
#  endif  // ALG_SHA256
#  if ALG_SHA384
            case MSSIM_ALG_SHA384:
#  endif  // ALG_SHA384
#  if ALG_SHA512
            case MSSIM_ALG_SHA512:
#  endif  // ALG_SHA512
#  if ALG_SM3_256
            case MSSIM_ALG_SM3_256:
#  endif  // ALG_SM3_256
#  if ALG_SHA3_256
            case MSSIM_ALG_SHA3_256:
#  endif  // ALG_SHA3_256
#  if ALG_SHA3_384
            case MSSIM_ALG_SHA3_384:
#  endif  // ALG_SHA3_384
#  if ALG_SHA3_512
            case MSSIM_ALG_SHA3_512:
#  endif  // ALG_SHA3_512
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_SYMMETRIC;
                break;
            default:
                result = MSSIM_RC_SYMMETRIC;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_MAC_SCHEME_Marshal(MSSIMI_ALG_MAC_SCHEME* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:76 - Definition of MSSIMI_ALG_CIPHER_MODE Type
MSSIM_RC
MSSIMI_ALG_CIPHER_MODE_Unmarshal(
    MSSIMI_ALG_CIPHER_MODE* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_CTR
            case MSSIM_ALG_CTR:
#  endif  // ALG_CTR
#  if ALG_OFB
            case MSSIM_ALG_OFB:
#  endif  // ALG_OFB
#  if ALG_CBC
            case MSSIM_ALG_CBC:
#  endif  // ALG_CBC
#  if ALG_CFB
            case MSSIM_ALG_CFB:
#  endif  // ALG_CFB
#  if ALG_ECB
            case MSSIM_ALG_ECB:
#  endif  // ALG_ECB
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_MODE;
                break;
            default:
                result = MSSIM_RC_MODE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_CIPHER_MODE_Marshal(MSSIMI_ALG_CIPHER_MODE* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:77 - Definition of MSSIMS_EMPTY Structure
MSSIM_RC
MSSIMS_EMPTY_Unmarshal(MSSIMS_EMPTY* target, BYTE** buffer, INT32* size)
{
    // to prevent the compiler from complaining
    NOT_REFERENCED(target);
    NOT_REFERENCED(buffer);
    NOT_REFERENCED(size);
    return MSSIM_RC_SUCCESS;
}
UINT16
MSSIMS_EMPTY_Marshal(MSSIMS_EMPTY* source, BYTE** buffer, INT32* size)
{
    // to prevent the compiler from complaining
    NOT_REFERENCED(source);
    NOT_REFERENCED(buffer);
    NOT_REFERENCED(size);
    return 0;
}

// Table 2:78 - Definition of MSSIMS_ALGORITHM_DESCRIPTION Structure
UINT16
MSSIMS_ALGORITHM_DESCRIPTION_Marshal(
    MSSIMS_ALGORITHM_DESCRIPTION* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)&(source->alg), buffer, size));
    result = (UINT16)(result
                      + MSSIMA_ALGORITHM_Marshal(
                          (MSSIMA_ALGORITHM*)&(source->attributes), buffer, size));
    return result;
}

// Table 2:79 - Definition of MSSIMU_HA Union
MSSIM_RC
MSSIMU_HA_Unmarshal(MSSIMU_HA* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_SHA1
        case MSSIM_ALG_SHA1:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha1), buffer, size, (INT32)SHA1_DIGEST_SIZE);
#  endif  // ALG_SHA1
#  if ALG_SHA256
        case MSSIM_ALG_SHA256:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha256), buffer, size, (INT32)SHA256_DIGEST_SIZE);
#  endif  // ALG_SHA256
#  if ALG_SHA384
        case MSSIM_ALG_SHA384:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha384), buffer, size, (INT32)SHA384_DIGEST_SIZE);
#  endif  // ALG_SHA384
#  if ALG_SHA512
        case MSSIM_ALG_SHA512:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha512), buffer, size, (INT32)SHA512_DIGEST_SIZE);
#  endif  // ALG_SHA512
#  if ALG_SM3_256
        case MSSIM_ALG_SM3_256:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sm3_256), buffer, size, (INT32)SM3_256_DIGEST_SIZE);
#  endif  // ALG_SM3_256
#  if ALG_SHA3_256
        case MSSIM_ALG_SHA3_256:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha3_256), buffer, size, (INT32)SHA3_256_DIGEST_SIZE);
#  endif  // ALG_SHA3_256
#  if ALG_SHA3_384
        case MSSIM_ALG_SHA3_384:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha3_384), buffer, size, (INT32)SHA3_384_DIGEST_SIZE);
#  endif  // ALG_SHA3_384
#  if ALG_SHA3_512
        case MSSIM_ALG_SHA3_512:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->sha3_512), buffer, size, (INT32)SHA3_512_DIGEST_SIZE);
#  endif  // ALG_SHA3_512
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_HA_Marshal(MSSIMU_HA* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_SHA1
        case MSSIM_ALG_SHA1:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha1), buffer, size, (INT32)SHA1_DIGEST_SIZE);
#  endif  // ALG_SHA1
#  if ALG_SHA256
        case MSSIM_ALG_SHA256:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha256), buffer, size, (INT32)SHA256_DIGEST_SIZE);
#  endif  // ALG_SHA256
#  if ALG_SHA384
        case MSSIM_ALG_SHA384:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha384), buffer, size, (INT32)SHA384_DIGEST_SIZE);
#  endif  // ALG_SHA384
#  if ALG_SHA512
        case MSSIM_ALG_SHA512:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha512), buffer, size, (INT32)SHA512_DIGEST_SIZE);
#  endif  // ALG_SHA512
#  if ALG_SM3_256
        case MSSIM_ALG_SM3_256:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sm3_256), buffer, size, (INT32)SM3_256_DIGEST_SIZE);
#  endif  // ALG_SM3_256
#  if ALG_SHA3_256
        case MSSIM_ALG_SHA3_256:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha3_256), buffer, size, (INT32)SHA3_256_DIGEST_SIZE);
#  endif  // ALG_SHA3_256
#  if ALG_SHA3_384
        case MSSIM_ALG_SHA3_384:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha3_384), buffer, size, (INT32)SHA3_384_DIGEST_SIZE);
#  endif  // ALG_SHA3_384
#  if ALG_SHA3_512
        case MSSIM_ALG_SHA3_512:
            return BYTE_Array_Marshal(
                (BYTE*)(source->sha3_512), buffer, size, (INT32)SHA3_512_DIGEST_SIZE);
#  endif  // ALG_SHA3_512
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:80 - Definition of MSSIMT_HA Structure
MSSIM_RC
MSSIMT_HA_Unmarshal(MSSIMT_HA* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_HASH_Unmarshal(
        (MSSIMI_ALG_HASH*)&(target->hashAlg), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_HA_Unmarshal(
            (MSSIMU_HA*)&(target->digest), buffer, size, (UINT32)target->hashAlg);
    return result;
}
UINT16
MSSIMT_HA_Marshal(MSSIMT_HA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->hashAlg), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_HA_Marshal((MSSIMU_HA*)&(source->digest),
                                        buffer,
                                        size,
                                        (UINT32)source->hashAlg));
    return result;
}

// Table 2:81 - Definition of MSSIM2B_DIGEST Structure
MSSIM_RC
MSSIM2B_DIGEST_Unmarshal(MSSIM2B_DIGEST* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMU_HA))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_DIGEST_Marshal(MSSIM2B_DIGEST* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:82 - Definition of MSSIM2B_DATA Structure
MSSIM_RC
MSSIM2B_DATA_Unmarshal(MSSIM2B_DATA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMT_HA))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_DATA_Marshal(MSSIM2B_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:83 - Definition of Types for MSSIM2B_NONCE
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM2B_NONCE_Unmarshal(MSSIM2B_NONCE* target, BYTE** buffer, INT32* size)
{
    return MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)target, buffer, size);
}
UINT16
MSSIM2B_NONCE_Marshal(MSSIM2B_NONCE* source, BYTE** buffer, INT32* size)
{
    return MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:84 - Definition of Types for MSSIM2B_AUTH
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM2B_AUTH_Unmarshal(MSSIM2B_AUTH* target, BYTE** buffer, INT32* size)
{
    return MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)target, buffer, size);
}
UINT16
MSSIM2B_AUTH_Marshal(MSSIM2B_AUTH* source, BYTE** buffer, INT32* size)
{
    return MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:85 - Definition of Types for MSSIM2B_OPERAND
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM2B_OPERAND_Unmarshal(MSSIM2B_OPERAND* target, BYTE** buffer, INT32* size)
{
    return MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)target, buffer, size);
}
UINT16
MSSIM2B_OPERAND_Marshal(MSSIM2B_OPERAND* source, BYTE** buffer, INT32* size)
{
    return MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:86 - Definition of MSSIM2B_EVENT Structure
MSSIM_RC
MSSIM2B_EVENT_Unmarshal(MSSIM2B_EVENT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > 1024)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_EVENT_Marshal(MSSIM2B_EVENT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:87 - Definition of MSSIM2B_MAX_BUFFER Structure
MSSIM_RC
MSSIM2B_MAX_BUFFER_Unmarshal(MSSIM2B_MAX_BUFFER* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_DIGEST_BUFFER)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_MAX_BUFFER_Marshal(MSSIM2B_MAX_BUFFER* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:88 - Definition of MSSIM2B_MAX_NV_BUFFER Structure
MSSIM_RC
MSSIM2B_MAX_NV_BUFFER_Unmarshal(MSSIM2B_MAX_NV_BUFFER* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_NV_BUFFER_SIZE)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_MAX_NV_BUFFER_Marshal(MSSIM2B_MAX_NV_BUFFER* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:89 - Definition of MSSIM2B_TIMEOUT Structure
MSSIM_RC
MSSIM2B_TIMEOUT_Unmarshal(MSSIM2B_TIMEOUT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(UINT64))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_TIMEOUT_Marshal(MSSIM2B_TIMEOUT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:90 - Definition of MSSIM2B_IV Structure
MSSIM_RC
MSSIM2B_IV_Unmarshal(MSSIM2B_IV* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_SYM_BLOCK_SIZE)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_IV_Marshal(MSSIM2B_IV* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:91 - Definition of MSSIMU_NAME Union
// Table 2:92 - Definition of MSSIM2B_NAME Structure
MSSIM_RC
MSSIM2B_NAME_Unmarshal(MSSIM2B_NAME* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMU_NAME))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.name), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_NAME_Marshal(MSSIM2B_NAME* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result =
        (UINT16)(result
                 + BYTE_Array_Marshal(
                     (BYTE*)(source->t.name), buffer, size, (INT32)(source->t.size)));
    return result;
}

// Table 2:93 - Definition of MSSIMS_PCR_SELECT Structure
MSSIM_RC
MSSIMS_PCR_SELECT_Unmarshal(MSSIMS_PCR_SELECT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT8_Unmarshal((UINT8*)&(target->sizeofSelect), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->sizeofSelect < PCR_SELECT_MIN))
        result = MSSIM_RC_VALUE;
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->sizeofSelect) > PCR_SELECT_MAX)
            result = MSSIM_RC_VALUE;
        else
            result = BYTE_Array_Unmarshal((BYTE*)(target->pcrSelect),
                                          buffer,
                                          size,
                                          (INT32)(target->sizeofSelect));
    }
    return result;
}
UINT16
MSSIMS_PCR_SELECT_Marshal(MSSIMS_PCR_SELECT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + UINT8_Marshal((UINT8*)&(source->sizeofSelect), buffer, size));
    result        = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->pcrSelect),
                                           buffer,
                                           size,
                                           (INT32)(source->sizeofSelect)));
    return result;
}

// Table 2:94 - Definition of MSSIMS_PCR_SELECTION Structure
MSSIM_RC
MSSIMS_PCR_SELECTION_Unmarshal(MSSIMS_PCR_SELECTION* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_HASH_Unmarshal((MSSIMI_ALG_HASH*)&(target->hash), buffer, size, 0);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT8_Unmarshal((UINT8*)&(target->sizeofSelect), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->sizeofSelect < PCR_SELECT_MIN))
        result = MSSIM_RC_VALUE;
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->sizeofSelect) > PCR_SELECT_MAX)
            result = MSSIM_RC_VALUE;
        else
            result = BYTE_Array_Unmarshal((BYTE*)(target->pcrSelect),
                                          buffer,
                                          size,
                                          (INT32)(target->sizeofSelect));
    }
    return result;
}
UINT16
MSSIMS_PCR_SELECTION_Marshal(MSSIMS_PCR_SELECTION* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->hash), buffer, size));
    result        = (UINT16)(result
                      + UINT8_Marshal((UINT8*)&(source->sizeofSelect), buffer, size));
    result        = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->pcrSelect),
                                           buffer,
                                           size,
                                           (INT32)(source->sizeofSelect)));
    return result;
}

// Table 2:97 - Definition of MSSIMT_TK_CREATION Structure
MSSIM_RC
MSSIMT_TK_CREATION_Unmarshal(MSSIMT_TK_CREATION* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ST_Unmarshal((MSSIM_ST*)&(target->tag), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->tag != MSSIM_ST_CREATION))
        result = MSSIM_RC_TAG;
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_RH_HIERARCHY_Unmarshal(
            (MSSIMI_RH_HIERARCHY*)&(target->hierarchy), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)&(target->digest), buffer, size);
    return result;
}
UINT16
MSSIMT_TK_CREATION_Marshal(MSSIMT_TK_CREATION* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result = (UINT16)(result + MSSIM_ST_Marshal((MSSIM_ST*)&(source->tag), buffer, size));
    result = (UINT16)(result
                      + MSSIMI_RH_HIERARCHY_Marshal(
                          (MSSIMI_RH_HIERARCHY*)&(source->hierarchy), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->digest), buffer, size));
    return result;
}

// Table 2:98 - Definition of MSSIMT_TK_VERIFIED Structure
MSSIM_RC
MSSIMT_TK_VERIFIED_Unmarshal(MSSIMT_TK_VERIFIED* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ST_Unmarshal((MSSIM_ST*)&(target->tag), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->tag != MSSIM_ST_VERIFIED))
        result = MSSIM_RC_TAG;
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_RH_HIERARCHY_Unmarshal(
            (MSSIMI_RH_HIERARCHY*)&(target->hierarchy), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)&(target->digest), buffer, size);
    return result;
}
UINT16
MSSIMT_TK_VERIFIED_Marshal(MSSIMT_TK_VERIFIED* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result = (UINT16)(result + MSSIM_ST_Marshal((MSSIM_ST*)&(source->tag), buffer, size));
    result = (UINT16)(result
                      + MSSIMI_RH_HIERARCHY_Marshal(
                          (MSSIMI_RH_HIERARCHY*)&(source->hierarchy), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->digest), buffer, size));
    return result;
}

// Table 2:99 - Definition of MSSIMT_TK_AUTH Structure
MSSIM_RC
MSSIMT_TK_AUTH_Unmarshal(MSSIMT_TK_AUTH* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ST_Unmarshal((MSSIM_ST*)&(target->tag), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->tag != MSSIM_ST_AUTH_SIGNED)
       && (target->tag != MSSIM_ST_AUTH_SECRET))
        result = MSSIM_RC_TAG;
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_RH_HIERARCHY_Unmarshal(
            (MSSIMI_RH_HIERARCHY*)&(target->hierarchy), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)&(target->digest), buffer, size);
    return result;
}
UINT16
MSSIMT_TK_AUTH_Marshal(MSSIMT_TK_AUTH* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result = (UINT16)(result + MSSIM_ST_Marshal((MSSIM_ST*)&(source->tag), buffer, size));
    result = (UINT16)(result
                      + MSSIMI_RH_HIERARCHY_Marshal(
                          (MSSIMI_RH_HIERARCHY*)&(source->hierarchy), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->digest), buffer, size));
    return result;
}

// Table 2:100 - Definition of MSSIMT_TK_HASHCHECK Structure
MSSIM_RC
MSSIMT_TK_HASHCHECK_Unmarshal(MSSIMT_TK_HASHCHECK* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ST_Unmarshal((MSSIM_ST*)&(target->tag), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->tag != MSSIM_ST_HASHCHECK))
        result = MSSIM_RC_TAG;
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_RH_HIERARCHY_Unmarshal(
            (MSSIMI_RH_HIERARCHY*)&(target->hierarchy), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)&(target->digest), buffer, size);
    return result;
}
UINT16
MSSIMT_TK_HASHCHECK_Marshal(MSSIMT_TK_HASHCHECK* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result = (UINT16)(result + MSSIM_ST_Marshal((MSSIM_ST*)&(source->tag), buffer, size));
    result = (UINT16)(result
                      + MSSIMI_RH_HIERARCHY_Marshal(
                          (MSSIMI_RH_HIERARCHY*)&(source->hierarchy), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->digest), buffer, size));
    return result;
}

// Table 2:101 - Definition of MSSIMS_ALG_PROPERTY Structure
UINT16
MSSIMS_ALG_PROPERTY_Marshal(MSSIMS_ALG_PROPERTY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)&(source->alg), buffer, size));
    result = (UINT16)(result
                      + MSSIMA_ALGORITHM_Marshal(
                          (MSSIMA_ALGORITHM*)&(source->algProperties), buffer, size));
    return result;
}

// Table 2:102 - Definition of MSSIMS_TAGGED_PROPERTY Structure
UINT16
MSSIMS_TAGGED_PROPERTY_Marshal(MSSIMS_TAGGED_PROPERTY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + MSSIM_PT_Marshal((MSSIM_PT*)&(source->property), buffer, size));
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->value), buffer, size));
    return result;
}

// Table 2:103 - Definition of MSSIMS_TAGGED_PCR_SELECT Structure
UINT16
MSSIMS_TAGGED_PCR_SELECT_Marshal(
    MSSIMS_TAGGED_PCR_SELECT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM_PT_PCR_Marshal((MSSIM_PT_PCR*)&(source->tag), buffer, size));
    result = (UINT16)(result
                      + UINT8_Marshal((UINT8*)&(source->sizeofSelect), buffer, size));
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->pcrSelect),
                                           buffer,
                                           size,
                                           (INT32)(source->sizeofSelect)));
    return result;
}

// Table 2:104 - Definition of MSSIMS_TAGGED_POLICY Structure
UINT16
MSSIMS_TAGGED_POLICY_Marshal(MSSIMS_TAGGED_POLICY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)&(source->handle), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMT_HA_Marshal((MSSIMT_HA*)&(source->policyHash), buffer, size));
    return result;
}

// Table 2:105 - Definition of MSSIMS_ACT_DATA Structure
UINT16
MSSIMS_ACT_DATA_Marshal(MSSIMS_ACT_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)&(source->handle), buffer, size));
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->timeout), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMA_ACT_Marshal((MSSIMA_ACT*)&(source->attributes), buffer, size));
    return result;
}

// Table 2:106 - Definition of MSSIML_CC Structure
MSSIM_RC
MSSIML_CC_Unmarshal(MSSIML_CC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)&(target->count), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->count) > MAX_CAP_CC)
            result = MSSIM_RC_SIZE;
        else
            result = MSSIM_CC_Array_Unmarshal((MSSIM_CC*)(target->commandCodes),
                                            buffer,
                                            size,
                                            (INT32)(target->count));
    }
    return result;
}
UINT16
MSSIML_CC_Marshal(MSSIML_CC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIM_CC_Array_Marshal((MSSIM_CC*)(source->commandCodes),
                                             buffer,
                                             size,
                                             (INT32)(source->count)));
    return result;
}

// Table 2:107 - Definition of MSSIML_CCA Structure
UINT16
MSSIML_CCA_Marshal(MSSIML_CCA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMA_CC_Array_Marshal((MSSIMA_CC*)(source->commandAttributes),
                                              buffer,
                                              size,
                                              (INT32)(source->count)));
    return result;
}

// Table 2:108 - Definition of MSSIML_ALG Structure
MSSIM_RC
MSSIML_ALG_Unmarshal(MSSIML_ALG* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)&(target->count), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->count) > MAX_ALG_LIST_SIZE)
            result = MSSIM_RC_SIZE;
        else
            result = MSSIM_ALG_ID_Array_Unmarshal((MSSIM_ALG_ID*)(target->algorithms),
                                                buffer,
                                                size,
                                                (INT32)(target->count));
    }
    return result;
}
UINT16
MSSIML_ALG_Marshal(MSSIML_ALG* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIM_ALG_ID_Array_Marshal((MSSIM_ALG_ID*)(source->algorithms),
                                                 buffer,
                                                 size,
                                                 (INT32)(source->count)));
    return result;
}

// Table 2:109 - Definition of MSSIML_HANDLE Structure
UINT16
MSSIML_HANDLE_Marshal(MSSIML_HANDLE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIM_HANDLE_Array_Marshal((MSSIM_HANDLE*)(source->handle),
                                                 buffer,
                                                 size,
                                                 (INT32)(source->count)));
    return result;
}

// Table 2:110 - Definition of MSSIML_DIGEST Structure
MSSIM_RC
MSSIML_DIGEST_Unmarshal(MSSIML_DIGEST* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)&(target->count), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->count < 2))
        result = MSSIM_RC_SIZE;
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->count) > 8)
            result = MSSIM_RC_SIZE;
        else
            result = MSSIM2B_DIGEST_Array_Unmarshal((MSSIM2B_DIGEST*)(target->digests),
                                                  buffer,
                                                  size,
                                                  (INT32)(target->count));
    }
    return result;
}
UINT16
MSSIML_DIGEST_Marshal(MSSIML_DIGEST* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Array_Marshal((MSSIM2B_DIGEST*)(source->digests),
                                                   buffer,
                                                   size,
                                                   (INT32)(source->count)));
    return result;
}

// Table 2:111 - Definition of MSSIML_DIGEST_VALUES Structure
MSSIM_RC
MSSIML_DIGEST_VALUES_Unmarshal(MSSIML_DIGEST_VALUES* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)&(target->count), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->count) > HASH_COUNT)
            result = MSSIM_RC_SIZE;
        else
            result = MSSIMT_HA_Array_Unmarshal(
                (MSSIMT_HA*)(target->digests), buffer, size, 0, (INT32)(target->count));
    }
    return result;
}
UINT16
MSSIML_DIGEST_VALUES_Marshal(MSSIML_DIGEST_VALUES* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMT_HA_Array_Marshal((MSSIMT_HA*)(source->digests),
                                              buffer,
                                              size,
                                              (INT32)(source->count)));
    return result;
}

// Table 2:112 - Definition of MSSIML_PCR_SELECTION Structure
MSSIM_RC
MSSIML_PCR_SELECTION_Unmarshal(MSSIML_PCR_SELECTION* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)&(target->count), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->count) > HASH_COUNT)
            result = MSSIM_RC_SIZE;
        else
            result = MSSIMS_PCR_SELECTION_Array_Unmarshal(
                (MSSIMS_PCR_SELECTION*)(target->pcrSelections),
                buffer,
                size,
                (INT32)(target->count));
    }
    return result;
}
UINT16
MSSIML_PCR_SELECTION_Marshal(MSSIML_PCR_SELECTION* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_PCR_SELECTION_Array_Marshal(
                          (MSSIMS_PCR_SELECTION*)(source->pcrSelections),
                          buffer,
                          size,
                          (INT32)(source->count)));
    return result;
}

// Table 2:113 - Definition of MSSIML_ALG_PROPERTY Structure
UINT16
MSSIML_ALG_PROPERTY_Marshal(MSSIML_ALG_PROPERTY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_ALG_PROPERTY_Array_Marshal(
                          (MSSIMS_ALG_PROPERTY*)(source->algProperties),
                          buffer,
                          size,
                          (INT32)(source->count)));
    return result;
}

// Table 2:114 - Definition of MSSIML_TAGGED_MSSIM_PROPERTY Structure
UINT16
MSSIML_TAGGED_MSSIM_PROPERTY_Marshal(
    MSSIML_TAGGED_MSSIM_PROPERTY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_TAGGED_PROPERTY_Array_Marshal(
                          (MSSIMS_TAGGED_PROPERTY*)(source->tpmProperty),
                          buffer,
                          size,
                          (INT32)(source->count)));
    return result;
}

// Table 2:115 - Definition of MSSIML_TAGGED_PCR_PROPERTY Structure
UINT16
MSSIML_TAGGED_PCR_PROPERTY_Marshal(
    MSSIML_TAGGED_PCR_PROPERTY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_TAGGED_PCR_SELECT_Array_Marshal(
                          (MSSIMS_TAGGED_PCR_SELECT*)(source->pcrProperty),
                          buffer,
                          size,
                          (INT32)(source->count)));
    return result;
}

// Table 2:116 - Definition of MSSIML_ECC_CURVE Structure
#  if ALG_ECC
UINT16
MSSIML_ECC_CURVE_Marshal(MSSIML_ECC_CURVE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result =
        (UINT16)(result
                 + MSSIM_ECC_CURVE_Array_Marshal((MSSIM_ECC_CURVE*)(source->eccCurves),
                                               buffer,
                                               size,
                                               (INT32)(source->count)));
    return result;
}
#  endif  // ALG_ECC

// Table 2:117 - Definition of MSSIML_TAGGED_POLICY Structure
UINT16
MSSIML_TAGGED_POLICY_Marshal(MSSIML_TAGGED_POLICY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_TAGGED_POLICY_Array_Marshal(
                          (MSSIMS_TAGGED_POLICY*)(source->policies),
                          buffer,
                          size,
                          (INT32)(source->count)));
    return result;
}

// Table 2:118 - Definition of MSSIML_ACT_DATA Structure
UINT16
MSSIML_ACT_DATA_Marshal(MSSIML_ACT_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_ACT_DATA_Array_Marshal((MSSIMS_ACT_DATA*)(source->actData),
                                                    buffer,
                                                    size,
                                                    (INT32)(source->count)));
    return result;
}

// Table 2:119 - Definition of MSSIMU_CAPABILITIES Union
UINT16
MSSIMU_CAPABILITIES_Marshal(
    MSSIMU_CAPABILITIES* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
        case MSSIM_CAP_ALGS:
            return MSSIML_ALG_PROPERTY_Marshal(
                (MSSIML_ALG_PROPERTY*)&(source->algorithms), buffer, size);
        case MSSIM_CAP_HANDLES:
            return MSSIML_HANDLE_Marshal(
                (MSSIML_HANDLE*)&(source->handles), buffer, size);
        case MSSIM_CAP_COMMANDS:
            return MSSIML_CCA_Marshal((MSSIML_CCA*)&(source->command), buffer, size);
        case MSSIM_CAP_PP_COMMANDS:
            return MSSIML_CC_Marshal((MSSIML_CC*)&(source->ppCommands), buffer, size);
        case MSSIM_CAP_AUDIT_COMMANDS:
            return MSSIML_CC_Marshal((MSSIML_CC*)&(source->auditCommands), buffer, size);
        case MSSIM_CAP_PCRS:
            return MSSIML_PCR_SELECTION_Marshal(
                (MSSIML_PCR_SELECTION*)&(source->assignedPCR), buffer, size);
        case MSSIM_CAP_MSSIM_PROPERTIES:
            return MSSIML_TAGGED_MSSIM_PROPERTY_Marshal(
                (MSSIML_TAGGED_MSSIM_PROPERTY*)&(source->tpmProperties), buffer, size);
        case MSSIM_CAP_PCR_PROPERTIES:
            return MSSIML_TAGGED_PCR_PROPERTY_Marshal(
                (MSSIML_TAGGED_PCR_PROPERTY*)&(source->pcrProperties), buffer, size);
#  if ALG_ECC
        case MSSIM_CAP_ECC_CURVES:
            return MSSIML_ECC_CURVE_Marshal(
                (MSSIML_ECC_CURVE*)&(source->eccCurves), buffer, size);
#  endif  // ALG_ECC
        case MSSIM_CAP_AUTH_POLICIES:
            return MSSIML_TAGGED_POLICY_Marshal(
                (MSSIML_TAGGED_POLICY*)&(source->authPolicies), buffer, size);
        case MSSIM_CAP_ACT:
            return MSSIML_ACT_DATA_Marshal(
                (MSSIML_ACT_DATA*)&(source->actData), buffer, size);
    }
    return 0;
}

// Table 2:120 - Definition of MSSIMS_CAPABILITY_DATA Structure
UINT16
MSSIMS_CAPABILITY_DATA_Marshal(MSSIMS_CAPABILITY_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM_CAP_Marshal((MSSIM_CAP*)&(source->capability), buffer, size));
    result = (UINT16)(result
                      + MSSIMU_CAPABILITIES_Marshal((MSSIMU_CAPABILITIES*)&(source->data),
                                                  buffer,
                                                  size,
                                                  (UINT32)source->capability));
    return result;
}

// Table 2:121 - Definition of MSSIMS_CLOCK_INFO Structure
MSSIM_RC
MSSIMS_CLOCK_INFO_Unmarshal(MSSIMS_CLOCK_INFO* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT64_Unmarshal((UINT64*)&(target->clock), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT32_Unmarshal((UINT32*)&(target->resetCount), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT32_Unmarshal((UINT32*)&(target->restartCount), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_YES_NO_Unmarshal((MSSIMI_YES_NO*)&(target->safe), buffer, size);
    return result;
}
UINT16
MSSIMS_CLOCK_INFO_Marshal(MSSIMS_CLOCK_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT64_Marshal((UINT64*)&(source->clock), buffer, size));
    result = (UINT16)(result
                      + UINT32_Marshal((UINT32*)&(source->resetCount), buffer, size));
    result =
        (UINT16)(result
                 + UINT32_Marshal((UINT32*)&(source->restartCount), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMI_YES_NO_Marshal((MSSIMI_YES_NO*)&(source->safe), buffer, size));
    return result;
}

// Table 2:122 - Definition of MSSIMS_TIME_INFO Structure
MSSIM_RC
MSSIMS_TIME_INFO_Unmarshal(MSSIMS_TIME_INFO* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT64_Unmarshal((UINT64*)&(target->time), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMS_CLOCK_INFO_Unmarshal(
            (MSSIMS_CLOCK_INFO*)&(target->clockInfo), buffer, size);
    return result;
}
UINT16
MSSIMS_TIME_INFO_Marshal(MSSIMS_TIME_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT64_Marshal((UINT64*)&(source->time), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_CLOCK_INFO_Marshal(
                          (MSSIMS_CLOCK_INFO*)&(source->clockInfo), buffer, size));
    return result;
}

// Table 2:123 - Definition of MSSIMS_TIME_ATTEST_INFO Structure
UINT16
MSSIMS_TIME_ATTEST_INFO_Marshal(
    MSSIMS_TIME_ATTEST_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMS_TIME_INFO_Marshal(
                          (MSSIMS_TIME_INFO*)&(source->time), buffer, size));
    result =
        (UINT16)(result
                 + UINT64_Marshal((UINT64*)&(source->firmwareVersion), buffer, size));
    return result;
}

// Table 2:124 - Definition of MSSIMS_CERTIFY_INFO Structure
UINT16
MSSIMS_CERTIFY_INFO_Marshal(MSSIMS_CERTIFY_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM2B_NAME_Marshal((MSSIM2B_NAME*)&(source->name), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->qualifiedName), buffer, size));
    return result;
}

// Table 2:125 - Definition of MSSIMS_QUOTE_INFO Structure
UINT16
MSSIMS_QUOTE_INFO_Marshal(MSSIMS_QUOTE_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIML_PCR_SELECTION_Marshal(
                          (MSSIML_PCR_SELECTION*)&(source->pcrSelect), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->pcrDigest), buffer, size));
    return result;
}

// Table 2:126 - Definition of MSSIMS_COMMAND_AUDIT_INFO Structure
UINT16
MSSIMS_COMMAND_AUDIT_INFO_Marshal(
    MSSIMS_COMMAND_AUDIT_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + UINT64_Marshal((UINT64*)&(source->auditCounter), buffer, size));
    result = (UINT16)(result
                      + MSSIM_ALG_ID_Marshal(
                          (MSSIM_ALG_ID*)&(source->digestAlg), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->auditDigest), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->commandDigest), buffer, size));
    return result;
}

// Table 2:127 - Definition of MSSIMS_SESSION_AUDIT_INFO Structure
UINT16
MSSIMS_SESSION_AUDIT_INFO_Marshal(
    MSSIMS_SESSION_AUDIT_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_YES_NO_Marshal(
                          (MSSIMI_YES_NO*)&(source->exclusiveSession), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->sessionDigest), buffer, size));
    return result;
}

// Table 2:128 - Definition of MSSIMS_CREATION_INFO Structure
UINT16
MSSIMS_CREATION_INFO_Marshal(MSSIMS_CREATION_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->objectName), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->creationHash), buffer, size));
    return result;
}

// Table 2:129 - Definition of MSSIMS_NV_CERTIFY_INFO Structure
UINT16
MSSIMS_NV_CERTIFY_INFO_Marshal(MSSIMS_NV_CERTIFY_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->indexName), buffer, size));
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->offset), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_MAX_NV_BUFFER_Marshal(
                          (MSSIM2B_MAX_NV_BUFFER*)&(source->nvContents), buffer, size));
    return result;
}

// Table 2:130 - Definition of MSSIMS_NV_DIGEST_CERTIFY_INFO Structure
UINT16
MSSIMS_NV_DIGEST_CERTIFY_INFO_Marshal(
    MSSIMS_NV_DIGEST_CERTIFY_INFO* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->indexName), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->nvDigest), buffer, size));
    return result;
}

// Table 2:131 - Definition of MSSIMI_ST_ATTEST Type
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ST_ATTEST_Marshal(MSSIMI_ST_ATTEST* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ST_Marshal((MSSIM_ST*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:132 - Definition of MSSIMU_ATTEST Union
UINT16
MSSIMU_ATTEST_Marshal(MSSIMU_ATTEST* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
        case MSSIM_ST_ATTEST_CERTIFY:
            return MSSIMS_CERTIFY_INFO_Marshal(
                (MSSIMS_CERTIFY_INFO*)&(source->certify), buffer, size);
        case MSSIM_ST_ATTEST_CREATION:
            return MSSIMS_CREATION_INFO_Marshal(
                (MSSIMS_CREATION_INFO*)&(source->creation), buffer, size);
        case MSSIM_ST_ATTEST_QUOTE:
            return MSSIMS_QUOTE_INFO_Marshal(
                (MSSIMS_QUOTE_INFO*)&(source->quote), buffer, size);
        case MSSIM_ST_ATTEST_COMMAND_AUDIT:
            return MSSIMS_COMMAND_AUDIT_INFO_Marshal(
                (MSSIMS_COMMAND_AUDIT_INFO*)&(source->commandAudit), buffer, size);
        case MSSIM_ST_ATTEST_SESSION_AUDIT:
            return MSSIMS_SESSION_AUDIT_INFO_Marshal(
                (MSSIMS_SESSION_AUDIT_INFO*)&(source->sessionAudit), buffer, size);
        case MSSIM_ST_ATTEST_TIME:
            return MSSIMS_TIME_ATTEST_INFO_Marshal(
                (MSSIMS_TIME_ATTEST_INFO*)&(source->time), buffer, size);
        case MSSIM_ST_ATTEST_NV:
            return MSSIMS_NV_CERTIFY_INFO_Marshal(
                (MSSIMS_NV_CERTIFY_INFO*)&(source->nv), buffer, size);
        case MSSIM_ST_ATTEST_NV_DIGEST:
            return MSSIMS_NV_DIGEST_CERTIFY_INFO_Marshal(
                (MSSIMS_NV_DIGEST_CERTIFY_INFO*)&(source->nvDigest), buffer, size);
    }
    return 0;
}

// Table 2:133 - Definition of MSSIMS_ATTEST Structure
UINT16
MSSIMS_ATTEST_Marshal(MSSIMS_ATTEST* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM_CONSTANTS32_Marshal(
                          (MSSIM_CONSTANTS32*)&(source->magic), buffer, size));
    result        = (UINT16)(result
                      + MSSIMI_ST_ATTEST_Marshal(
                          (MSSIMI_ST_ATTEST*)&(source->type), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->qualifiedSigner), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DATA_Marshal(
                          (MSSIM2B_DATA*)&(source->extraData), buffer, size));
    result        = (UINT16)(result
                      + MSSIMS_CLOCK_INFO_Marshal(
                          (MSSIMS_CLOCK_INFO*)&(source->clockInfo), buffer, size));
    result =
        (UINT16)(result
                 + UINT64_Marshal((UINT64*)&(source->firmwareVersion), buffer, size));
    result = (UINT16)(result
                      + MSSIMU_ATTEST_Marshal((MSSIMU_ATTEST*)&(source->attested),
                                            buffer,
                                            size,
                                            (UINT32)source->type));
    return result;
}

// Table 2:134 - Definition of MSSIM2B_ATTEST Structure
UINT16
MSSIM2B_ATTEST_Marshal(MSSIM2B_ATTEST* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.attestationData),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:135 - Definition of MSSIMS_AUTH_COMMAND Structure
MSSIM_RC
MSSIMS_AUTH_COMMAND_Unmarshal(MSSIMS_AUTH_COMMAND* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIMI_SH_AUTH_SESSION_Unmarshal(
        (MSSIMI_SH_AUTH_SESSION*)&(target->sessionHandle), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_NONCE_Unmarshal((MSSIM2B_NONCE*)&(target->nonce), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMA_SESSION_Unmarshal(
            (MSSIMA_SESSION*)&(target->sessionAttributes), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_AUTH_Unmarshal((MSSIM2B_AUTH*)&(target->hmac), buffer, size);
    return result;
}

// Table 2:136 - Definition of MSSIMS_AUTH_RESPONSE Structure
UINT16
MSSIMS_AUTH_RESPONSE_Marshal(MSSIMS_AUTH_RESPONSE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM2B_NONCE_Marshal((MSSIM2B_NONCE*)&(source->nonce), buffer, size));
    result = (UINT16)(result
                      + MSSIMA_SESSION_Marshal(
                          (MSSIMA_SESSION*)&(source->sessionAttributes), buffer, size));
    result =
        (UINT16)(result
                 + MSSIM2B_AUTH_Marshal((MSSIM2B_AUTH*)&(source->hmac), buffer, size));
    return result;
}

// Table 2:137 - Definition of MSSIMI_TDES_KEY_BITS Type
#  if ALG_TDES
MSSIM_RC
MSSIMI_TDES_KEY_BITS_Unmarshal(MSSIMI_TDES_KEY_BITS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_KEY_BITS_Unmarshal((MSSIM_KEY_BITS*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if TDES_128
            case 128:
#    endif  // TDES_128
#    if TDES_192
            case 192:
#    endif  // TDES_192
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_TDES_KEY_BITS_Marshal(MSSIMI_TDES_KEY_BITS* source, BYTE** buffer, INT32* size)
{
    return MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_TDES

// Table 2:137 - Definition of MSSIMI_AES_KEY_BITS Type
#  if ALG_AES
MSSIM_RC
MSSIMI_AES_KEY_BITS_Unmarshal(MSSIMI_AES_KEY_BITS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_KEY_BITS_Unmarshal((MSSIM_KEY_BITS*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if AES_128
            case 128:
#    endif  // AES_128
#    if AES_192
            case 192:
#    endif  // AES_192
#    if AES_256
            case 256:
#    endif  // AES_256
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_AES_KEY_BITS_Marshal(MSSIMI_AES_KEY_BITS* source, BYTE** buffer, INT32* size)
{
    return MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_AES

// Table 2:137 - Definition of MSSIMI_SM4_KEY_BITS Type
#  if ALG_SM4
MSSIM_RC
MSSIMI_SM4_KEY_BITS_Unmarshal(MSSIMI_SM4_KEY_BITS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_KEY_BITS_Unmarshal((MSSIM_KEY_BITS*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if SM4_128
            case 128:
#    endif  // SM4_128
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SM4_KEY_BITS_Marshal(MSSIMI_SM4_KEY_BITS* source, BYTE** buffer, INT32* size)
{
    return MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_SM4

// Table 2:137 - Definition of MSSIMI_CAMELLIA_KEY_BITS Type
#  if ALG_CAMELLIA
MSSIM_RC
MSSIMI_CAMELLIA_KEY_BITS_Unmarshal(
    MSSIMI_CAMELLIA_KEY_BITS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_KEY_BITS_Unmarshal((MSSIM_KEY_BITS*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if CAMELLIA_128
            case 128:
#    endif  // CAMELLIA_128
#    if CAMELLIA_192
            case 192:
#    endif  // CAMELLIA_192
#    if CAMELLIA_256
            case 256:
#    endif  // CAMELLIA_256
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_CAMELLIA_KEY_BITS_Marshal(
    MSSIMI_CAMELLIA_KEY_BITS* source, BYTE** buffer, INT32* size)
{
    return MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_CAMELLIA

// Table 2:138 - Definition of MSSIMU_SYM_KEY_BITS Union
MSSIM_RC
MSSIMU_SYM_KEY_BITS_Unmarshal(
    MSSIMU_SYM_KEY_BITS* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_TDES
        case MSSIM_ALG_TDES:
            return MSSIMI_TDES_KEY_BITS_Unmarshal(
                (MSSIMI_TDES_KEY_BITS*)&(target->tdes), buffer, size);
#  endif  // ALG_TDES
#  if ALG_AES
        case MSSIM_ALG_AES:
            return MSSIMI_AES_KEY_BITS_Unmarshal(
                (MSSIMI_AES_KEY_BITS*)&(target->aes), buffer, size);
#  endif  // ALG_AES
#  if ALG_SM4
        case MSSIM_ALG_SM4:
            return MSSIMI_SM4_KEY_BITS_Unmarshal(
                (MSSIMI_SM4_KEY_BITS*)&(target->sm4), buffer, size);
#  endif  // ALG_SM4
#  if ALG_CAMELLIA
        case MSSIM_ALG_CAMELLIA:
            return MSSIMI_CAMELLIA_KEY_BITS_Unmarshal(
                (MSSIMI_CAMELLIA_KEY_BITS*)&(target->camellia), buffer, size);
#  endif  // ALG_CAMELLIA
#  if ALG_XOR
        case MSSIM_ALG_XOR:
            return MSSIMI_ALG_HASH_Unmarshal(
                (MSSIMI_ALG_HASH*)&(target->xor), buffer, size, 0);
#  endif  // ALG_XOR
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_SYM_KEY_BITS_Marshal(
    MSSIMU_SYM_KEY_BITS* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_TDES
        case MSSIM_ALG_TDES:
            return MSSIMI_TDES_KEY_BITS_Marshal(
                (MSSIMI_TDES_KEY_BITS*)&(source->tdes), buffer, size);
#  endif  // ALG_TDES
#  if ALG_AES
        case MSSIM_ALG_AES:
            return MSSIMI_AES_KEY_BITS_Marshal(
                (MSSIMI_AES_KEY_BITS*)&(source->aes), buffer, size);
#  endif  // ALG_AES
#  if ALG_SM4
        case MSSIM_ALG_SM4:
            return MSSIMI_SM4_KEY_BITS_Marshal(
                (MSSIMI_SM4_KEY_BITS*)&(source->sm4), buffer, size);
#  endif  // ALG_SM4
#  if ALG_CAMELLIA
        case MSSIM_ALG_CAMELLIA:
            return MSSIMI_CAMELLIA_KEY_BITS_Marshal(
                (MSSIMI_CAMELLIA_KEY_BITS*)&(source->camellia), buffer, size);
#  endif  // ALG_CAMELLIA
#  if ALG_XOR
        case MSSIM_ALG_XOR:
            return MSSIMI_ALG_HASH_Marshal(
                (MSSIMI_ALG_HASH*)&(source->xor), buffer, size);
#  endif  // ALG_XOR
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:139 - Definition of MSSIMU_SYM_MODE Union
MSSIM_RC
MSSIMU_SYM_MODE_Unmarshal(
    MSSIMU_SYM_MODE* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_TDES
        case MSSIM_ALG_TDES:
            return MSSIMI_ALG_SYM_MODE_Unmarshal(
                (MSSIMI_ALG_SYM_MODE*)&(target->tdes), buffer, size, 1);
#  endif  // ALG_TDES
#  if ALG_AES
        case MSSIM_ALG_AES:
            return MSSIMI_ALG_SYM_MODE_Unmarshal(
                (MSSIMI_ALG_SYM_MODE*)&(target->aes), buffer, size, 1);
#  endif  // ALG_AES
#  if ALG_SM4
        case MSSIM_ALG_SM4:
            return MSSIMI_ALG_SYM_MODE_Unmarshal(
                (MSSIMI_ALG_SYM_MODE*)&(target->sm4), buffer, size, 1);
#  endif  // ALG_SM4
#  if ALG_CAMELLIA
        case MSSIM_ALG_CAMELLIA:
            return MSSIMI_ALG_SYM_MODE_Unmarshal(
                (MSSIMI_ALG_SYM_MODE*)&(target->camellia), buffer, size, 1);
#  endif  // ALG_CAMELLIA
#  if ALG_XOR
        case MSSIM_ALG_XOR:
            return MSSIM_RC_SUCCESS;
#  endif  // ALG_XOR
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_SYM_MODE_Marshal(
    MSSIMU_SYM_MODE* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_TDES
        case MSSIM_ALG_TDES:
            return MSSIMI_ALG_SYM_MODE_Marshal(
                (MSSIMI_ALG_SYM_MODE*)&(source->tdes), buffer, size);
#  endif  // ALG_TDES
#  if ALG_AES
        case MSSIM_ALG_AES:
            return MSSIMI_ALG_SYM_MODE_Marshal(
                (MSSIMI_ALG_SYM_MODE*)&(source->aes), buffer, size);
#  endif  // ALG_AES
#  if ALG_SM4
        case MSSIM_ALG_SM4:
            return MSSIMI_ALG_SYM_MODE_Marshal(
                (MSSIMI_ALG_SYM_MODE*)&(source->sm4), buffer, size);
#  endif  // ALG_SM4
#  if ALG_CAMELLIA
        case MSSIM_ALG_CAMELLIA:
            return MSSIMI_ALG_SYM_MODE_Marshal(
                (MSSIMI_ALG_SYM_MODE*)&(source->camellia), buffer, size);
#  endif  // ALG_CAMELLIA
#  if ALG_XOR
        case MSSIM_ALG_XOR:
            return 0;
#  endif  // ALG_XOR
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:141 - Definition of MSSIMT_SYM_DEF Structure
MSSIM_RC
MSSIMT_SYM_DEF_Unmarshal(MSSIMT_SYM_DEF* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_SYM_Unmarshal(
        (MSSIMI_ALG_SYM*)&(target->algorithm), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SYM_KEY_BITS_Unmarshal((MSSIMU_SYM_KEY_BITS*)&(target->keyBits),
                                             buffer,
                                             size,
                                             (UINT32)target->algorithm);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SYM_MODE_Unmarshal(
            (MSSIMU_SYM_MODE*)&(target->mode), buffer, size, (UINT32)target->algorithm);
    return result;
}
UINT16
MSSIMT_SYM_DEF_Marshal(MSSIMT_SYM_DEF* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_SYM_Marshal(
                          (MSSIMI_ALG_SYM*)&(source->algorithm), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMU_SYM_KEY_BITS_Marshal((MSSIMU_SYM_KEY_BITS*)&(source->keyBits),
                                             buffer,
                                             size,
                                             (UINT32)source->algorithm));
    result = (UINT16)(result
                      + MSSIMU_SYM_MODE_Marshal((MSSIMU_SYM_MODE*)&(source->mode),
                                              buffer,
                                              size,
                                              (UINT32)source->algorithm));
    return result;
}

// Table 2:142 - Definition of MSSIMT_SYM_DEF_OBJECT Structure
MSSIM_RC
MSSIMT_SYM_DEF_OBJECT_Unmarshal(
    MSSIMT_SYM_DEF_OBJECT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_SYM_OBJECT_Unmarshal(
        (MSSIMI_ALG_SYM_OBJECT*)&(target->algorithm), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SYM_KEY_BITS_Unmarshal((MSSIMU_SYM_KEY_BITS*)&(target->keyBits),
                                             buffer,
                                             size,
                                             (UINT32)target->algorithm);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SYM_MODE_Unmarshal(
            (MSSIMU_SYM_MODE*)&(target->mode), buffer, size, (UINT32)target->algorithm);
    return result;
}
UINT16
MSSIMT_SYM_DEF_OBJECT_Marshal(MSSIMT_SYM_DEF_OBJECT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_SYM_OBJECT_Marshal(
                          (MSSIMI_ALG_SYM_OBJECT*)&(source->algorithm), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMU_SYM_KEY_BITS_Marshal((MSSIMU_SYM_KEY_BITS*)&(source->keyBits),
                                             buffer,
                                             size,
                                             (UINT32)source->algorithm));
    result = (UINT16)(result
                      + MSSIMU_SYM_MODE_Marshal((MSSIMU_SYM_MODE*)&(source->mode),
                                              buffer,
                                              size,
                                              (UINT32)source->algorithm));
    return result;
}

// Table 2:143 - Definition of MSSIM2B_SYM_KEY Structure
MSSIM_RC
MSSIM2B_SYM_KEY_Unmarshal(MSSIM2B_SYM_KEY* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_SYM_KEY_BYTES)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_SYM_KEY_Marshal(MSSIM2B_SYM_KEY* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:144 - Definition of MSSIMS_SYMCIPHER_PARMS Structure
MSSIM_RC
MSSIMS_SYMCIPHER_PARMS_Unmarshal(
    MSSIMS_SYMCIPHER_PARMS* target, BYTE** buffer, INT32* size)
{
    return MSSIMT_SYM_DEF_OBJECT_Unmarshal(
        (MSSIMT_SYM_DEF_OBJECT*)&(target->sym), buffer, size, 0);
}
UINT16
MSSIMS_SYMCIPHER_PARMS_Marshal(MSSIMS_SYMCIPHER_PARMS* source, BYTE** buffer, INT32* size)
{
    return MSSIMT_SYM_DEF_OBJECT_Marshal(
        (MSSIMT_SYM_DEF_OBJECT*)&(source->sym), buffer, size);
}

// Table 2:145 - Definition of MSSIM2B_LABEL Structure
MSSIM_RC
MSSIM2B_LABEL_Unmarshal(MSSIM2B_LABEL* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > LABEL_MAX_BUFFER)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_LABEL_Marshal(MSSIM2B_LABEL* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:146 - Definition of MSSIMS_DERIVE Structure
MSSIM_RC
MSSIMS_DERIVE_Unmarshal(MSSIMS_DERIVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM2B_LABEL_Unmarshal((MSSIM2B_LABEL*)&(target->label), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_LABEL_Unmarshal((MSSIM2B_LABEL*)&(target->context), buffer, size);
    return result;
}
UINT16
MSSIMS_DERIVE_Marshal(MSSIMS_DERIVE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIM2B_LABEL_Marshal((MSSIM2B_LABEL*)&(source->label), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_LABEL_Marshal(
                          (MSSIM2B_LABEL*)&(source->context), buffer, size));
    return result;
}

// Table 2:147 - Definition of MSSIM2B_DERIVE Structure
MSSIM_RC
MSSIM2B_DERIVE_Unmarshal(MSSIM2B_DERIVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMS_DERIVE))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_DERIVE_Marshal(MSSIM2B_DERIVE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:148 - Definition of MSSIMU_SENSITIVE_CREATE Union
// Table 2:149 - Definition of MSSIM2B_SENSITIVE_DATA Structure
MSSIM_RC
MSSIM2B_SENSITIVE_DATA_Unmarshal(
    MSSIM2B_SENSITIVE_DATA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMU_SENSITIVE_CREATE))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_SENSITIVE_DATA_Marshal(MSSIM2B_SENSITIVE_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:150 - Definition of MSSIMS_SENSITIVE_CREATE Structure
MSSIM_RC
MSSIMS_SENSITIVE_CREATE_Unmarshal(
    MSSIMS_SENSITIVE_CREATE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM2B_AUTH_Unmarshal((MSSIM2B_AUTH*)&(target->userAuth), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_SENSITIVE_DATA_Unmarshal(
            (MSSIM2B_SENSITIVE_DATA*)&(target->data), buffer, size);
    return result;
}

// Table 2:151 - Definition of MSSIM2B_SENSITIVE_CREATE Structure
MSSIM_RC
MSSIM2B_SENSITIVE_CREATE_Unmarshal(
    MSSIM2B_SENSITIVE_CREATE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->size), buffer, size);  // =a
    if(result == MSSIM_RC_SUCCESS)
    {
        // if size is zero, then the required structure is missing
        if(target->size == 0)
            result = MSSIM_RC_SIZE;
        else
        {
            INT32 startSize = *size;
            result          = MSSIMS_SENSITIVE_CREATE_Unmarshal(
                (MSSIMS_SENSITIVE_CREATE*)&(target->sensitive), buffer, size);  // =b
            if(result == MSSIM_RC_SUCCESS)
            {
                if(target->size != (startSize - *size))
                    result = MSSIM_RC_SIZE;
            }
        }
    }
    return result;
}

// Table 2:152 - Definition of MSSIMS_SCHEME_HASH Structure
MSSIM_RC
MSSIMS_SCHEME_HASH_Unmarshal(MSSIMS_SCHEME_HASH* target, BYTE** buffer, INT32* size)
{
    return MSSIMI_ALG_HASH_Unmarshal(
        (MSSIMI_ALG_HASH*)&(target->hashAlg), buffer, size, 0);
}
UINT16
MSSIMS_SCHEME_HASH_Marshal(MSSIMS_SCHEME_HASH* source, BYTE** buffer, INT32* size)
{
    return MSSIMI_ALG_HASH_Marshal((MSSIMI_ALG_HASH*)&(source->hashAlg), buffer, size);
}

// Table 2:153 - Definition of MSSIMS_SCHEME_ECDAA Structure
#  if ALG_ECC
MSSIM_RC
MSSIMS_SCHEME_ECDAA_Unmarshal(MSSIMS_SCHEME_ECDAA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_HASH_Unmarshal((MSSIMI_ALG_HASH*)&(target->hashAlg), buffer, size, 0);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT16_Unmarshal((UINT16*)&(target->count), buffer, size);
    return result;
}
UINT16
MSSIMS_SCHEME_ECDAA_Marshal(MSSIMS_SCHEME_ECDAA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->hashAlg), buffer, size));
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->count), buffer, size));
    return result;
}
#  endif  // ALG_ECC

// Table 2:154 - Definition of MSSIMI_ALG_KEYEDHASH_SCHEME Type
MSSIM_RC
MSSIMI_ALG_KEYEDHASH_SCHEME_Unmarshal(
    MSSIMI_ALG_KEYEDHASH_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_HMAC
            case MSSIM_ALG_HMAC:
#  endif  // ALG_HMAC
#  if ALG_XOR
            case MSSIM_ALG_XOR:
#  endif  // ALG_XOR
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_KEYEDHASH_SCHEME_Marshal(
    MSSIMI_ALG_KEYEDHASH_SCHEME* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:155 - Definition of Types for HMAC_SIG_SCHEME
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SCHEME_HMAC_Unmarshal(MSSIMS_SCHEME_HMAC* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_SCHEME_HMAC_Marshal(MSSIMS_SCHEME_HMAC* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:156 - Definition of MSSIMS_SCHEME_XOR Structure
MSSIM_RC
MSSIMS_SCHEME_XOR_Unmarshal(MSSIMS_SCHEME_XOR* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_HASH_Unmarshal((MSSIMI_ALG_HASH*)&(target->hashAlg), buffer, size, 0);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIMI_ALG_KDF_Unmarshal((MSSIMI_ALG_KDF*)&(target->kdf), buffer, size, 1);
    return result;
}
UINT16
MSSIMS_SCHEME_XOR_Marshal(MSSIMS_SCHEME_XOR* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->hashAlg), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMI_ALG_KDF_Marshal((MSSIMI_ALG_KDF*)&(source->kdf), buffer, size));
    return result;
}

// Table 2:157 - Definition of MSSIMU_SCHEME_KEYEDHASH Union
MSSIM_RC
MSSIMU_SCHEME_KEYEDHASH_Unmarshal(
    MSSIMU_SCHEME_KEYEDHASH* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_HMAC
        case MSSIM_ALG_HMAC:
            return MSSIMS_SCHEME_HMAC_Unmarshal(
                (MSSIMS_SCHEME_HMAC*)&(target->hmac), buffer, size);
#  endif  // ALG_HMAC
#  if ALG_XOR
        case MSSIM_ALG_XOR:
            return MSSIMS_SCHEME_XOR_Unmarshal(
                (MSSIMS_SCHEME_XOR*)&(target->xor), buffer, size);
#  endif  // ALG_XOR
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_SCHEME_KEYEDHASH_Marshal(
    MSSIMU_SCHEME_KEYEDHASH* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_HMAC
        case MSSIM_ALG_HMAC:
            return MSSIMS_SCHEME_HMAC_Marshal(
                (MSSIMS_SCHEME_HMAC*)&(source->hmac), buffer, size);
#  endif  // ALG_HMAC
#  if ALG_XOR
        case MSSIM_ALG_XOR:
            return MSSIMS_SCHEME_XOR_Marshal(
                (MSSIMS_SCHEME_XOR*)&(source->xor), buffer, size);
#  endif  // ALG_XOR
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:158 - Definition of MSSIMT_KEYEDHASH_SCHEME Structure
MSSIM_RC
MSSIMT_KEYEDHASH_SCHEME_Unmarshal(
    MSSIMT_KEYEDHASH_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_KEYEDHASH_SCHEME_Unmarshal(
        (MSSIMI_ALG_KEYEDHASH_SCHEME*)&(target->scheme), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SCHEME_KEYEDHASH_Unmarshal(
            (MSSIMU_SCHEME_KEYEDHASH*)&(target->details),
            buffer,
            size,
            (UINT32)target->scheme);
    return result;
}
UINT16
MSSIMT_KEYEDHASH_SCHEME_Marshal(
    MSSIMT_KEYEDHASH_SCHEME* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result
                 + MSSIMI_ALG_KEYEDHASH_SCHEME_Marshal(
                     (MSSIMI_ALG_KEYEDHASH_SCHEME*)&(source->scheme), buffer, size));
    result = (UINT16)(result
                      + MSSIMU_SCHEME_KEYEDHASH_Marshal(
                          (MSSIMU_SCHEME_KEYEDHASH*)&(source->details),
                          buffer,
                          size,
                          (UINT32)source->scheme));
    return result;
}

// Table 2:159 - Definition of Types for RSA Signature Schemes
#  if ALG_RSA
#    if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_RSASSA_Unmarshal(
    MSSIMS_SIG_SCHEME_RSASSA* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_SIG_SCHEME_RSASSA_Marshal(
    MSSIMS_SIG_SCHEME_RSASSA* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIG_SCHEME_RSAPSS_Unmarshal(
    MSSIMS_SIG_SCHEME_RSAPSS* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_SIG_SCHEME_RSAPSS_Marshal(
    MSSIMS_SIG_SCHEME_RSAPSS* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_RSA

// Table 2:160 - Definition of Types for ECC Signature Schemes
#  if ALG_ECC
#    if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_ECDSA_Unmarshal(
    MSSIMS_SIG_SCHEME_ECDSA* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_SIG_SCHEME_ECDSA_Marshal(
    MSSIMS_SIG_SCHEME_ECDSA* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIG_SCHEME_SM2_Unmarshal(MSSIMS_SIG_SCHEME_SM2* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_SIG_SCHEME_SM2_Marshal(MSSIMS_SIG_SCHEME_SM2* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIG_SCHEME_ECSCHNORR_Unmarshal(
    MSSIMS_SIG_SCHEME_ECSCHNORR* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_SIG_SCHEME_ECSCHNORR_Marshal(
    MSSIMS_SIG_SCHEME_ECSCHNORR* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIG_SCHEME_ECDAA_Unmarshal(
    MSSIMS_SIG_SCHEME_ECDAA* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_ECDAA_Unmarshal((MSSIMS_SCHEME_ECDAA*)target, buffer, size);
}
UINT16
MSSIMS_SIG_SCHEME_ECDAA_Marshal(
    MSSIMS_SIG_SCHEME_ECDAA* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_ECDAA_Marshal((MSSIMS_SCHEME_ECDAA*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:161 - Definition of MSSIMU_SIG_SCHEME Union
MSSIM_RC
MSSIMU_SIG_SCHEME_Unmarshal(
    MSSIMU_SIG_SCHEME* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECDAA
        case MSSIM_ALG_ECDAA:
            return MSSIMS_SIG_SCHEME_ECDAA_Unmarshal(
                (MSSIMS_SIG_SCHEME_ECDAA*)&(target->ecdaa), buffer, size);
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
        case MSSIM_ALG_RSASSA:
            return MSSIMS_SIG_SCHEME_RSASSA_Unmarshal(
                (MSSIMS_SIG_SCHEME_RSASSA*)&(target->rsassa), buffer, size);
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
        case MSSIM_ALG_RSAPSS:
            return MSSIMS_SIG_SCHEME_RSAPSS_Unmarshal(
                (MSSIMS_SIG_SCHEME_RSAPSS*)&(target->rsapss), buffer, size);
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
        case MSSIM_ALG_ECDSA:
            return MSSIMS_SIG_SCHEME_ECDSA_Unmarshal(
                (MSSIMS_SIG_SCHEME_ECDSA*)&(target->ecdsa), buffer, size);
#  endif  // ALG_ECDSA
#  if ALG_SM2
        case MSSIM_ALG_SM2:
            return MSSIMS_SIG_SCHEME_SM2_Unmarshal(
                (MSSIMS_SIG_SCHEME_SM2*)&(target->sm2), buffer, size);
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
        case MSSIM_ALG_ECSCHNORR:
            return MSSIMS_SIG_SCHEME_ECSCHNORR_Unmarshal(
                (MSSIMS_SIG_SCHEME_ECSCHNORR*)&(target->ecschnorr), buffer, size);
#  endif  // ALG_ECSCHNORR
#  if ALG_HMAC
        case MSSIM_ALG_HMAC:
            return MSSIMS_SCHEME_HMAC_Unmarshal(
                (MSSIMS_SCHEME_HMAC*)&(target->hmac), buffer, size);
#  endif  // ALG_HMAC
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_SIG_SCHEME_Marshal(
    MSSIMU_SIG_SCHEME* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECDAA
        case MSSIM_ALG_ECDAA:
            return MSSIMS_SIG_SCHEME_ECDAA_Marshal(
                (MSSIMS_SIG_SCHEME_ECDAA*)&(source->ecdaa), buffer, size);
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
        case MSSIM_ALG_RSASSA:
            return MSSIMS_SIG_SCHEME_RSASSA_Marshal(
                (MSSIMS_SIG_SCHEME_RSASSA*)&(source->rsassa), buffer, size);
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
        case MSSIM_ALG_RSAPSS:
            return MSSIMS_SIG_SCHEME_RSAPSS_Marshal(
                (MSSIMS_SIG_SCHEME_RSAPSS*)&(source->rsapss), buffer, size);
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
        case MSSIM_ALG_ECDSA:
            return MSSIMS_SIG_SCHEME_ECDSA_Marshal(
                (MSSIMS_SIG_SCHEME_ECDSA*)&(source->ecdsa), buffer, size);
#  endif  // ALG_ECDSA
#  if ALG_SM2
        case MSSIM_ALG_SM2:
            return MSSIMS_SIG_SCHEME_SM2_Marshal(
                (MSSIMS_SIG_SCHEME_SM2*)&(source->sm2), buffer, size);
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
        case MSSIM_ALG_ECSCHNORR:
            return MSSIMS_SIG_SCHEME_ECSCHNORR_Marshal(
                (MSSIMS_SIG_SCHEME_ECSCHNORR*)&(source->ecschnorr), buffer, size);
#  endif  // ALG_ECSCHNORR
#  if ALG_HMAC
        case MSSIM_ALG_HMAC:
            return MSSIMS_SCHEME_HMAC_Marshal(
                (MSSIMS_SCHEME_HMAC*)&(source->hmac), buffer, size);
#  endif  // ALG_HMAC
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:162 - Definition of MSSIMT_SIG_SCHEME Structure
MSSIM_RC
MSSIMT_SIG_SCHEME_Unmarshal(
    MSSIMT_SIG_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_SIG_SCHEME_Unmarshal(
        (MSSIMI_ALG_SIG_SCHEME*)&(target->scheme), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SIG_SCHEME_Unmarshal((MSSIMU_SIG_SCHEME*)&(target->details),
                                           buffer,
                                           size,
                                           (UINT32)target->scheme);
    return result;
}
UINT16
MSSIMT_SIG_SCHEME_Marshal(MSSIMT_SIG_SCHEME* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_SIG_SCHEME_Marshal(
                          (MSSIMI_ALG_SIG_SCHEME*)&(source->scheme), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_SIG_SCHEME_Marshal((MSSIMU_SIG_SCHEME*)&(source->details),
                                                buffer,
                                                size,
                                                (UINT32)source->scheme));
    return result;
}

// Table 2:163 - Definition of Types for Encryption Schemes
#  if ALG_RSA
#    if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_ENC_SCHEME_OAEP_Unmarshal(
    MSSIMS_ENC_SCHEME_OAEP* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_ENC_SCHEME_OAEP_Marshal(MSSIMS_ENC_SCHEME_OAEP* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_ENC_SCHEME_RSAES_Unmarshal(
    MSSIMS_ENC_SCHEME_RSAES* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_EMPTY_Unmarshal((MSSIMS_EMPTY*)target, buffer, size);
}
UINT16
MSSIMS_ENC_SCHEME_RSAES_Marshal(
    MSSIMS_ENC_SCHEME_RSAES* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_EMPTY_Marshal((MSSIMS_EMPTY*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_RSA

// Table 2:164 - Definition of Types for ECC Key Exchange
#  if ALG_ECC
#    if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KEY_SCHEME_ECDH_Unmarshal(
    MSSIMS_KEY_SCHEME_ECDH* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_KEY_SCHEME_ECDH_Marshal(MSSIMS_KEY_SCHEME_ECDH* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_KEY_SCHEME_ECMQV_Unmarshal(
    MSSIMS_KEY_SCHEME_ECMQV* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_KEY_SCHEME_ECMQV_Marshal(
    MSSIMS_KEY_SCHEME_ECMQV* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:165 - Definition of Types for KDF Schemes
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KDF_SCHEME_MGF1_Unmarshal(
    MSSIMS_KDF_SCHEME_MGF1* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_KDF_SCHEME_MGF1_Marshal(MSSIMS_KDF_SCHEME_MGF1* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Unmarshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_56A* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Marshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_56A* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_KDF_SCHEME_KDF2_Unmarshal(
    MSSIMS_KDF_SCHEME_KDF2* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_KDF_SCHEME_KDF2_Marshal(MSSIMS_KDF_SCHEME_KDF2* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
MSSIM_RC
MSSIMS_KDF_SCHEME_KDF1_SP800_108_Unmarshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_108* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)target, buffer, size);
}
UINT16
MSSIMS_KDF_SCHEME_KDF1_SP800_108_Marshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_108* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:166 - Definition of MSSIMU_KDF_SCHEME Union
MSSIM_RC
MSSIMU_KDF_SCHEME_Unmarshal(
    MSSIMU_KDF_SCHEME* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_MGF1
        case MSSIM_ALG_MGF1:
            return MSSIMS_KDF_SCHEME_MGF1_Unmarshal(
                (MSSIMS_KDF_SCHEME_MGF1*)&(target->mgf1), buffer, size);
#  endif  // ALG_MGF1
#  if ALG_KDF1_SP800_56A
        case MSSIM_ALG_KDF1_SP800_56A:
            return MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Unmarshal(
                (MSSIMS_KDF_SCHEME_KDF1_SP800_56A*)&(target->kdf1_sp800_56a),
                buffer,
                size);
#  endif  // ALG_KDF1_SP800_56A
#  if ALG_KDF2
        case MSSIM_ALG_KDF2:
            return MSSIMS_KDF_SCHEME_KDF2_Unmarshal(
                (MSSIMS_KDF_SCHEME_KDF2*)&(target->kdf2), buffer, size);
#  endif  // ALG_KDF2
#  if ALG_KDF1_SP800_108
        case MSSIM_ALG_KDF1_SP800_108:
            return MSSIMS_KDF_SCHEME_KDF1_SP800_108_Unmarshal(
                (MSSIMS_KDF_SCHEME_KDF1_SP800_108*)&(target->kdf1_sp800_108),
                buffer,
                size);
#  endif  // ALG_KDF1_SP800_108
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_KDF_SCHEME_Marshal(
    MSSIMU_KDF_SCHEME* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_MGF1
        case MSSIM_ALG_MGF1:
            return MSSIMS_KDF_SCHEME_MGF1_Marshal(
                (MSSIMS_KDF_SCHEME_MGF1*)&(source->mgf1), buffer, size);
#  endif  // ALG_MGF1
#  if ALG_KDF1_SP800_56A
        case MSSIM_ALG_KDF1_SP800_56A:
            return MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Marshal(
                (MSSIMS_KDF_SCHEME_KDF1_SP800_56A*)&(source->kdf1_sp800_56a),
                buffer,
                size);
#  endif  // ALG_KDF1_SP800_56A
#  if ALG_KDF2
        case MSSIM_ALG_KDF2:
            return MSSIMS_KDF_SCHEME_KDF2_Marshal(
                (MSSIMS_KDF_SCHEME_KDF2*)&(source->kdf2), buffer, size);
#  endif  // ALG_KDF2
#  if ALG_KDF1_SP800_108
        case MSSIM_ALG_KDF1_SP800_108:
            return MSSIMS_KDF_SCHEME_KDF1_SP800_108_Marshal(
                (MSSIMS_KDF_SCHEME_KDF1_SP800_108*)&(source->kdf1_sp800_108),
                buffer,
                size);
#  endif  // ALG_KDF1_SP800_108
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:167 - Definition of MSSIMT_KDF_SCHEME Structure
MSSIM_RC
MSSIMT_KDF_SCHEME_Unmarshal(
    MSSIMT_KDF_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_KDF_Unmarshal((MSSIMI_ALG_KDF*)&(target->scheme), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_KDF_SCHEME_Unmarshal((MSSIMU_KDF_SCHEME*)&(target->details),
                                           buffer,
                                           size,
                                           (UINT32)target->scheme);
    return result;
}
UINT16
MSSIMT_KDF_SCHEME_Marshal(MSSIMT_KDF_SCHEME* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_KDF_Marshal(
                          (MSSIMI_ALG_KDF*)&(source->scheme), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_KDF_SCHEME_Marshal((MSSIMU_KDF_SCHEME*)&(source->details),
                                                buffer,
                                                size,
                                                (UINT32)source->scheme));
    return result;
}

// Table 2:168 - Definition of MSSIMI_ALG_ASYM_SCHEME Type
MSSIM_RC
MSSIMI_ALG_ASYM_SCHEME_Unmarshal(
    MSSIMI_ALG_ASYM_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_ECDH
            case MSSIM_ALG_ECDH:
#  endif  // ALG_ECDH
#  if ALG_ECMQV
            case MSSIM_ALG_ECMQV:
#  endif  // ALG_ECMQV
#  if ALG_ECDAA
            case MSSIM_ALG_ECDAA:
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
            case MSSIM_ALG_RSASSA:
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
            case MSSIM_ALG_RSAPSS:
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
            case MSSIM_ALG_ECDSA:
#  endif  // ALG_ECDSA
#  if ALG_SM2
            case MSSIM_ALG_SM2:
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
            case MSSIM_ALG_ECSCHNORR:
#  endif  // ALG_ECSCHNORR
#  if ALG_RSAES
            case MSSIM_ALG_RSAES:
#  endif  // ALG_RSAES
#  if ALG_OAEP
            case MSSIM_ALG_OAEP:
#  endif  // ALG_OAEP
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_ASYM_SCHEME_Marshal(MSSIMI_ALG_ASYM_SCHEME* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:169 - Definition of MSSIMU_ASYM_SCHEME Union
MSSIM_RC
MSSIMU_ASYM_SCHEME_Unmarshal(
    MSSIMU_ASYM_SCHEME* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECDH
        case MSSIM_ALG_ECDH:
            return MSSIMS_KEY_SCHEME_ECDH_Unmarshal(
                (MSSIMS_KEY_SCHEME_ECDH*)&(target->ecdh), buffer, size);
#  endif  // ALG_ECDH
#  if ALG_ECMQV
        case MSSIM_ALG_ECMQV:
            return MSSIMS_KEY_SCHEME_ECMQV_Unmarshal(
                (MSSIMS_KEY_SCHEME_ECMQV*)&(target->ecmqv), buffer, size);
#  endif  // ALG_ECMQV
#  if ALG_ECDAA
        case MSSIM_ALG_ECDAA:
            return MSSIMS_SIG_SCHEME_ECDAA_Unmarshal(
                (MSSIMS_SIG_SCHEME_ECDAA*)&(target->ecdaa), buffer, size);
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
        case MSSIM_ALG_RSASSA:
            return MSSIMS_SIG_SCHEME_RSASSA_Unmarshal(
                (MSSIMS_SIG_SCHEME_RSASSA*)&(target->rsassa), buffer, size);
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
        case MSSIM_ALG_RSAPSS:
            return MSSIMS_SIG_SCHEME_RSAPSS_Unmarshal(
                (MSSIMS_SIG_SCHEME_RSAPSS*)&(target->rsapss), buffer, size);
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
        case MSSIM_ALG_ECDSA:
            return MSSIMS_SIG_SCHEME_ECDSA_Unmarshal(
                (MSSIMS_SIG_SCHEME_ECDSA*)&(target->ecdsa), buffer, size);
#  endif  // ALG_ECDSA
#  if ALG_SM2
        case MSSIM_ALG_SM2:
            return MSSIMS_SIG_SCHEME_SM2_Unmarshal(
                (MSSIMS_SIG_SCHEME_SM2*)&(target->sm2), buffer, size);
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
        case MSSIM_ALG_ECSCHNORR:
            return MSSIMS_SIG_SCHEME_ECSCHNORR_Unmarshal(
                (MSSIMS_SIG_SCHEME_ECSCHNORR*)&(target->ecschnorr), buffer, size);
#  endif  // ALG_ECSCHNORR
#  if ALG_RSAES
        case MSSIM_ALG_RSAES:
            return MSSIMS_ENC_SCHEME_RSAES_Unmarshal(
                (MSSIMS_ENC_SCHEME_RSAES*)&(target->rsaes), buffer, size);
#  endif  // ALG_RSAES
#  if ALG_OAEP
        case MSSIM_ALG_OAEP:
            return MSSIMS_ENC_SCHEME_OAEP_Unmarshal(
                (MSSIMS_ENC_SCHEME_OAEP*)&(target->oaep), buffer, size);
#  endif  // ALG_OAEP
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_ASYM_SCHEME_Marshal(
    MSSIMU_ASYM_SCHEME* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECDH
        case MSSIM_ALG_ECDH:
            return MSSIMS_KEY_SCHEME_ECDH_Marshal(
                (MSSIMS_KEY_SCHEME_ECDH*)&(source->ecdh), buffer, size);
#  endif  // ALG_ECDH
#  if ALG_ECMQV
        case MSSIM_ALG_ECMQV:
            return MSSIMS_KEY_SCHEME_ECMQV_Marshal(
                (MSSIMS_KEY_SCHEME_ECMQV*)&(source->ecmqv), buffer, size);
#  endif  // ALG_ECMQV
#  if ALG_ECDAA
        case MSSIM_ALG_ECDAA:
            return MSSIMS_SIG_SCHEME_ECDAA_Marshal(
                (MSSIMS_SIG_SCHEME_ECDAA*)&(source->ecdaa), buffer, size);
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
        case MSSIM_ALG_RSASSA:
            return MSSIMS_SIG_SCHEME_RSASSA_Marshal(
                (MSSIMS_SIG_SCHEME_RSASSA*)&(source->rsassa), buffer, size);
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
        case MSSIM_ALG_RSAPSS:
            return MSSIMS_SIG_SCHEME_RSAPSS_Marshal(
                (MSSIMS_SIG_SCHEME_RSAPSS*)&(source->rsapss), buffer, size);
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
        case MSSIM_ALG_ECDSA:
            return MSSIMS_SIG_SCHEME_ECDSA_Marshal(
                (MSSIMS_SIG_SCHEME_ECDSA*)&(source->ecdsa), buffer, size);
#  endif  // ALG_ECDSA
#  if ALG_SM2
        case MSSIM_ALG_SM2:
            return MSSIMS_SIG_SCHEME_SM2_Marshal(
                (MSSIMS_SIG_SCHEME_SM2*)&(source->sm2), buffer, size);
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
        case MSSIM_ALG_ECSCHNORR:
            return MSSIMS_SIG_SCHEME_ECSCHNORR_Marshal(
                (MSSIMS_SIG_SCHEME_ECSCHNORR*)&(source->ecschnorr), buffer, size);
#  endif  // ALG_ECSCHNORR
#  if ALG_RSAES
        case MSSIM_ALG_RSAES:
            return MSSIMS_ENC_SCHEME_RSAES_Marshal(
                (MSSIMS_ENC_SCHEME_RSAES*)&(source->rsaes), buffer, size);
#  endif  // ALG_RSAES
#  if ALG_OAEP
        case MSSIM_ALG_OAEP:
            return MSSIMS_ENC_SCHEME_OAEP_Marshal(
                (MSSIMS_ENC_SCHEME_OAEP*)&(source->oaep), buffer, size);
#  endif  // ALG_OAEP
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:170 - Definition of MSSIMT_ASYM_SCHEME Structure
// Table 2:171 - Definition of MSSIMI_ALG_RSA_SCHEME Type
#  if ALG_RSA
MSSIM_RC
MSSIMI_ALG_RSA_SCHEME_Unmarshal(
    MSSIMI_ALG_RSA_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if ALG_RSAES
            case MSSIM_ALG_RSAES:
#    endif  // ALG_RSAES
#    if ALG_OAEP
            case MSSIM_ALG_OAEP:
#    endif  // ALG_OAEP
#    if ALG_RSASSA
            case MSSIM_ALG_RSASSA:
#    endif  // ALG_RSASSA
#    if ALG_RSAPSS
            case MSSIM_ALG_RSAPSS:
#    endif  // ALG_RSAPSS
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_RSA_SCHEME_Marshal(MSSIMI_ALG_RSA_SCHEME* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_RSA

// Table 2:172 - Definition of MSSIMT_RSA_SCHEME Structure
#  if ALG_RSA
MSSIM_RC
MSSIMT_RSA_SCHEME_Unmarshal(
    MSSIMT_RSA_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_RSA_SCHEME_Unmarshal(
        (MSSIMI_ALG_RSA_SCHEME*)&(target->scheme), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_ASYM_SCHEME_Unmarshal((MSSIMU_ASYM_SCHEME*)&(target->details),
                                            buffer,
                                            size,
                                            (UINT32)target->scheme);
    return result;
}
UINT16
MSSIMT_RSA_SCHEME_Marshal(MSSIMT_RSA_SCHEME* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_RSA_SCHEME_Marshal(
                          (MSSIMI_ALG_RSA_SCHEME*)&(source->scheme), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMU_ASYM_SCHEME_Marshal((MSSIMU_ASYM_SCHEME*)&(source->details),
                                            buffer,
                                            size,
                                            (UINT32)source->scheme));
    return result;
}
#  endif  // ALG_RSA

// Table 2:173 - Definition of MSSIMI_ALG_RSA_DECRYPT Type
#  if ALG_RSA
MSSIM_RC
MSSIMI_ALG_RSA_DECRYPT_Unmarshal(
    MSSIMI_ALG_RSA_DECRYPT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if ALG_RSAES
            case MSSIM_ALG_RSAES:
#    endif  // ALG_RSAES
#    if ALG_OAEP
            case MSSIM_ALG_OAEP:
#    endif  // ALG_OAEP
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_VALUE;
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_RSA_DECRYPT_Marshal(MSSIMI_ALG_RSA_DECRYPT* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_RSA

// Table 2:174 - Definition of MSSIMT_RSA_DECRYPT Structure
#  if ALG_RSA
MSSIM_RC
MSSIMT_RSA_DECRYPT_Unmarshal(
    MSSIMT_RSA_DECRYPT* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_RSA_DECRYPT_Unmarshal(
        (MSSIMI_ALG_RSA_DECRYPT*)&(target->scheme), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_ASYM_SCHEME_Unmarshal((MSSIMU_ASYM_SCHEME*)&(target->details),
                                            buffer,
                                            size,
                                            (UINT32)target->scheme);
    return result;
}
UINT16
MSSIMT_RSA_DECRYPT_Marshal(MSSIMT_RSA_DECRYPT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_RSA_DECRYPT_Marshal(
                          (MSSIMI_ALG_RSA_DECRYPT*)&(source->scheme), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMU_ASYM_SCHEME_Marshal((MSSIMU_ASYM_SCHEME*)&(source->details),
                                            buffer,
                                            size,
                                            (UINT32)source->scheme));
    return result;
}
#  endif  // ALG_RSA

// Table 2:175 - Definition of MSSIM2B_PUBLIC_KEY_RSA Structure
#  if ALG_RSA
MSSIM_RC
MSSIM2B_PUBLIC_KEY_RSA_Unmarshal(
    MSSIM2B_PUBLIC_KEY_RSA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_RSA_KEY_BYTES)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_PUBLIC_KEY_RSA_Marshal(MSSIM2B_PUBLIC_KEY_RSA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}
#  endif  // ALG_RSA

// Table 2:176 - Definition of MSSIMI_RSA_KEY_BITS Type
#  if ALG_RSA
MSSIM_RC
MSSIMI_RSA_KEY_BITS_Unmarshal(MSSIMI_RSA_KEY_BITS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_KEY_BITS_Unmarshal((MSSIM_KEY_BITS*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if RSA_1024
            case 1024:
#    endif  // RSA_1024
#    if RSA_2048
            case 2048:
#    endif  // RSA_2048
#    if RSA_3072
            case 3072:
#    endif  // RSA_3072
#    if RSA_4096
            case 4096:
#    endif  // RSA_4096
#    if RSA_16384
            case 16384:
#    endif  // RSA_16384
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RSA_KEY_BITS_Marshal(MSSIMI_RSA_KEY_BITS* source, BYTE** buffer, INT32* size)
{
    return MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_RSA

// Table 2:177 - Definition of MSSIM2B_PRIVATE_KEY_RSA Structure
#  if ALG_RSA
MSSIM_RC
MSSIM2B_PRIVATE_KEY_RSA_Unmarshal(
    MSSIM2B_PRIVATE_KEY_RSA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > RSA_PRIVATE_SIZE)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_PRIVATE_KEY_RSA_Marshal(
    MSSIM2B_PRIVATE_KEY_RSA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}
#  endif  // ALG_RSA

// Table 2:178 - Definition of MSSIM2B_ECC_PARAMETER Structure
MSSIM_RC
MSSIM2B_ECC_PARAMETER_Unmarshal(MSSIM2B_ECC_PARAMETER* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_ECC_KEY_BYTES)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_ECC_PARAMETER_Marshal(MSSIM2B_ECC_PARAMETER* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:179 - Definition of MSSIMS_ECC_POINT Structure
#  if ALG_ECC
MSSIM_RC
MSSIMS_ECC_POINT_Unmarshal(MSSIMS_ECC_POINT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM2B_ECC_PARAMETER_Unmarshal(
        (MSSIM2B_ECC_PARAMETER*)&(target->x), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_ECC_PARAMETER_Unmarshal(
            (MSSIM2B_ECC_PARAMETER*)&(target->y), buffer, size);
    return result;
}
UINT16
MSSIMS_ECC_POINT_Marshal(MSSIMS_ECC_POINT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->x), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->y), buffer, size));
    return result;
}
#  endif  // ALG_ECC

// Table 2:180 - Definition of MSSIM2B_ECC_POINT Structure
#  if ALG_ECC
MSSIM_RC
MSSIM2B_ECC_POINT_Unmarshal(MSSIM2B_ECC_POINT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->size), buffer, size);  // =a
    if(result == MSSIM_RC_SUCCESS)
    {
        // if size is zero, then the required structure is missing
        if(target->size == 0)
            result = MSSIM_RC_SIZE;
        else
        {
            INT32 startSize = *size;
            result          = MSSIMS_ECC_POINT_Unmarshal(
                (MSSIMS_ECC_POINT*)&(target->point), buffer, size);  // =b
            if(result == MSSIM_RC_SUCCESS)
            {
                if(target->size != (startSize - *size))
                    result = MSSIM_RC_SIZE;
            }
        }
    }
    return result;
}
UINT16
MSSIM2B_ECC_POINT_Marshal(MSSIM2B_ECC_POINT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    // Marshal a dummy value of the 2B size. This makes sure that 'buffer'
    // and 'size' are advanced as necessary (i.e., if they are present)
    result = UINT16_Marshal(&result, buffer, size);
    // Marshal the structure
    result = (UINT16)(result
                      + MSSIMS_ECC_POINT_Marshal(
                          (MSSIMS_ECC_POINT*)&(source->point), buffer, size));
    // if a buffer was provided, go back and fill in the actual size
    if(buffer != NULL)
        UINT16_TO_BYTE_ARRAY((result - 2), (*buffer - result));
    return result;
}
#  endif  // ALG_ECC

// Table 2:181 - Definition of MSSIMI_ALG_ECC_SCHEME Type
#  if ALG_ECC
MSSIM_RC
MSSIMI_ALG_ECC_SCHEME_Unmarshal(
    MSSIMI_ALG_ECC_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if ALG_ECDAA
            case MSSIM_ALG_ECDAA:
#    endif  // ALG_ECDAA
#    if ALG_ECDSA
            case MSSIM_ALG_ECDSA:
#    endif  // ALG_ECDSA
#    if ALG_SM2
            case MSSIM_ALG_SM2:
#    endif  // ALG_SM2
#    if ALG_ECSCHNORR
            case MSSIM_ALG_ECSCHNORR:
#    endif  // ALG_ECSCHNORR
#    if ALG_ECDH
            case MSSIM_ALG_ECDH:
#    endif  // ALG_ECDH
#    if ALG_ECMQV
            case MSSIM_ALG_ECMQV:
#    endif  // ALG_ECMQV
                break;
            case MSSIM_ALG_NULL:
                if(!flag)
                    result = MSSIM_RC_SCHEME;
                break;
            default:
                result = MSSIM_RC_SCHEME;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_ECC_SCHEME_Marshal(MSSIMI_ALG_ECC_SCHEME* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:182 - Definition of MSSIMI_ECC_CURVE Type
#  if ALG_ECC
MSSIM_RC
MSSIMI_ECC_CURVE_Unmarshal(MSSIMI_ECC_CURVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ECC_CURVE_Unmarshal((MSSIM_ECC_CURVE*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#    if ECC_BN_P256
            case MSSIM_ECC_BN_P256:
#    endif  // ECC_BN_P256
#    if ECC_BN_P638
            case MSSIM_ECC_BN_P638:
#    endif  // ECC_BN_P638
#    if ECC_NIST_P192
            case MSSIM_ECC_NIST_P192:
#    endif  // ECC_NIST_P192
#    if ECC_NIST_P224
            case MSSIM_ECC_NIST_P224:
#    endif  // ECC_NIST_P224
#    if ECC_NIST_P256
            case MSSIM_ECC_NIST_P256:
#    endif  // ECC_NIST_P256
#    if ECC_NIST_P384
            case MSSIM_ECC_NIST_P384:
#    endif  // ECC_NIST_P384
#    if ECC_NIST_P521
            case MSSIM_ECC_NIST_P521:
#    endif  // ECC_NIST_P521
#    if ECC_SM2_P256
            case MSSIM_ECC_SM2_P256:
#    endif  // ECC_SM2_P256
                break;
            default:
                result = MSSIM_RC_CURVE;
                break;
        }
    }
    return result;
}
#    if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ECC_CURVE_Marshal(MSSIMI_ECC_CURVE* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ECC_CURVE_Marshal((MSSIM_ECC_CURVE*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:183 - Definition of MSSIMT_ECC_SCHEME Structure
#  if ALG_ECC
MSSIM_RC
MSSIMT_ECC_SCHEME_Unmarshal(
    MSSIMT_ECC_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_ECC_SCHEME_Unmarshal(
        (MSSIMI_ALG_ECC_SCHEME*)&(target->scheme), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_ASYM_SCHEME_Unmarshal((MSSIMU_ASYM_SCHEME*)&(target->details),
                                            buffer,
                                            size,
                                            (UINT32)target->scheme);
    return result;
}
UINT16
MSSIMT_ECC_SCHEME_Marshal(MSSIMT_ECC_SCHEME* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_ECC_SCHEME_Marshal(
                          (MSSIMI_ALG_ECC_SCHEME*)&(source->scheme), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMU_ASYM_SCHEME_Marshal((MSSIMU_ASYM_SCHEME*)&(source->details),
                                            buffer,
                                            size,
                                            (UINT32)source->scheme));
    return result;
}
#  endif  // ALG_ECC

// Table 2:184 - Definition of MSSIMS_ALGORITHM_DETAIL_ECC Structure
#  if ALG_ECC
UINT16
MSSIMS_ALGORITHM_DETAIL_ECC_Marshal(
    MSSIMS_ALGORITHM_DETAIL_ECC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM_ECC_CURVE_Marshal(
                          (MSSIM_ECC_CURVE*)&(source->curveID), buffer, size));
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->keySize), buffer, size));
    result = (UINT16)(result
                      + MSSIMT_KDF_SCHEME_Marshal(
                          (MSSIMT_KDF_SCHEME*)&(source->kdf), buffer, size));
    result = (UINT16)(result
                      + MSSIMT_ECC_SCHEME_Marshal(
                          (MSSIMT_ECC_SCHEME*)&(source->sign), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->p), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->a), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->b), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->gX), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->gY), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->n), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->h), buffer, size));
    return result;
}
#  endif  // ALG_ECC

// Table 2:185 - Definition of MSSIMS_SIGNATURE_RSA Structure
#  if ALG_RSA
MSSIM_RC
MSSIMS_SIGNATURE_RSA_Unmarshal(MSSIMS_SIGNATURE_RSA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_HASH_Unmarshal((MSSIMI_ALG_HASH*)&(target->hash), buffer, size, 0);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_PUBLIC_KEY_RSA_Unmarshal(
            (MSSIM2B_PUBLIC_KEY_RSA*)&(target->sig), buffer, size);
    return result;
}
UINT16
MSSIMS_SIGNATURE_RSA_Marshal(MSSIMS_SIGNATURE_RSA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->hash), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_PUBLIC_KEY_RSA_Marshal(
                          (MSSIM2B_PUBLIC_KEY_RSA*)&(source->sig), buffer, size));
    return result;
}
#  endif  // ALG_RSA

// Table 2:186 - Definition of Types for Signature
#  if ALG_RSA
#    if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_RSASSA_Unmarshal(
    MSSIMS_SIGNATURE_RSASSA* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_RSA_Unmarshal((MSSIMS_SIGNATURE_RSA*)target, buffer, size);
}
UINT16
MSSIMS_SIGNATURE_RSASSA_Marshal(
    MSSIMS_SIGNATURE_RSASSA* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_RSA_Marshal((MSSIMS_SIGNATURE_RSA*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIGNATURE_RSAPSS_Unmarshal(
    MSSIMS_SIGNATURE_RSAPSS* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_RSA_Unmarshal((MSSIMS_SIGNATURE_RSA*)target, buffer, size);
}
UINT16
MSSIMS_SIGNATURE_RSAPSS_Marshal(
    MSSIMS_SIGNATURE_RSAPSS* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_RSA_Marshal((MSSIMS_SIGNATURE_RSA*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_RSA

// Table 2:187 - Definition of MSSIMS_SIGNATURE_ECC Structure
#  if ALG_ECC
MSSIM_RC
MSSIMS_SIGNATURE_ECC_Unmarshal(MSSIMS_SIGNATURE_ECC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_HASH_Unmarshal((MSSIMI_ALG_HASH*)&(target->hash), buffer, size, 0);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_ECC_PARAMETER_Unmarshal(
            (MSSIM2B_ECC_PARAMETER*)&(target->signatureR), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_ECC_PARAMETER_Unmarshal(
            (MSSIM2B_ECC_PARAMETER*)&(target->signatureS), buffer, size);
    return result;
}
UINT16
MSSIMS_SIGNATURE_ECC_Marshal(MSSIMS_SIGNATURE_ECC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->hash), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->signatureR), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_ECC_PARAMETER_Marshal(
                          (MSSIM2B_ECC_PARAMETER*)&(source->signatureS), buffer, size));
    return result;
}
#  endif  // ALG_ECC

// Table 2:188 - Definition of Types for MSSIMS_SIGNATURE_ECC
#  if ALG_ECC
#    if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_ECDAA_Unmarshal(
    MSSIMS_SIGNATURE_ECDAA* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)target, buffer, size);
}
UINT16
MSSIMS_SIGNATURE_ECDAA_Marshal(MSSIMS_SIGNATURE_ECDAA* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIGNATURE_ECDSA_Unmarshal(
    MSSIMS_SIGNATURE_ECDSA* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)target, buffer, size);
}
UINT16
MSSIMS_SIGNATURE_ECDSA_Marshal(MSSIMS_SIGNATURE_ECDSA* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIGNATURE_SM2_Unmarshal(MSSIMS_SIGNATURE_SM2* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)target, buffer, size);
}
UINT16
MSSIMS_SIGNATURE_SM2_Marshal(MSSIMS_SIGNATURE_SM2* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)source, buffer, size);
}
MSSIM_RC
MSSIMS_SIGNATURE_ECSCHNORR_Unmarshal(
    MSSIMS_SIGNATURE_ECSCHNORR* target, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)target, buffer, size);
}
UINT16
MSSIMS_SIGNATURE_ECSCHNORR_Marshal(
    MSSIMS_SIGNATURE_ECSCHNORR* source, BYTE** buffer, INT32* size)
{
    return MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)source, buffer, size);
}
#    endif  // !USE_MARSHALING_DEFINES
#  endif    // ALG_ECC

// Table 2:189 - Definition of MSSIMU_SIGNATURE Union
MSSIM_RC
MSSIMU_SIGNATURE_Unmarshal(
    MSSIMU_SIGNATURE* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECDAA
        case MSSIM_ALG_ECDAA:
            return MSSIMS_SIGNATURE_ECDAA_Unmarshal(
                (MSSIMS_SIGNATURE_ECDAA*)&(target->ecdaa), buffer, size);
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
        case MSSIM_ALG_RSASSA:
            return MSSIMS_SIGNATURE_RSASSA_Unmarshal(
                (MSSIMS_SIGNATURE_RSASSA*)&(target->rsassa), buffer, size);
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
        case MSSIM_ALG_RSAPSS:
            return MSSIMS_SIGNATURE_RSAPSS_Unmarshal(
                (MSSIMS_SIGNATURE_RSAPSS*)&(target->rsapss), buffer, size);
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
        case MSSIM_ALG_ECDSA:
            return MSSIMS_SIGNATURE_ECDSA_Unmarshal(
                (MSSIMS_SIGNATURE_ECDSA*)&(target->ecdsa), buffer, size);
#  endif  // ALG_ECDSA
#  if ALG_SM2
        case MSSIM_ALG_SM2:
            return MSSIMS_SIGNATURE_SM2_Unmarshal(
                (MSSIMS_SIGNATURE_SM2*)&(target->sm2), buffer, size);
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
        case MSSIM_ALG_ECSCHNORR:
            return MSSIMS_SIGNATURE_ECSCHNORR_Unmarshal(
                (MSSIMS_SIGNATURE_ECSCHNORR*)&(target->ecschnorr), buffer, size);
#  endif  // ALG_ECSCHNORR
#  if ALG_HMAC
        case MSSIM_ALG_HMAC:
            return MSSIMT_HA_Unmarshal((MSSIMT_HA*)&(target->hmac), buffer, size, 0);
#  endif  // ALG_HMAC
        case MSSIM_ALG_NULL:
            return MSSIM_RC_SUCCESS;
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_SIGNATURE_Marshal(
    MSSIMU_SIGNATURE* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECDAA
        case MSSIM_ALG_ECDAA:
            return MSSIMS_SIGNATURE_ECDAA_Marshal(
                (MSSIMS_SIGNATURE_ECDAA*)&(source->ecdaa), buffer, size);
#  endif  // ALG_ECDAA
#  if ALG_RSASSA
        case MSSIM_ALG_RSASSA:
            return MSSIMS_SIGNATURE_RSASSA_Marshal(
                (MSSIMS_SIGNATURE_RSASSA*)&(source->rsassa), buffer, size);
#  endif  // ALG_RSASSA
#  if ALG_RSAPSS
        case MSSIM_ALG_RSAPSS:
            return MSSIMS_SIGNATURE_RSAPSS_Marshal(
                (MSSIMS_SIGNATURE_RSAPSS*)&(source->rsapss), buffer, size);
#  endif  // ALG_RSAPSS
#  if ALG_ECDSA
        case MSSIM_ALG_ECDSA:
            return MSSIMS_SIGNATURE_ECDSA_Marshal(
                (MSSIMS_SIGNATURE_ECDSA*)&(source->ecdsa), buffer, size);
#  endif  // ALG_ECDSA
#  if ALG_SM2
        case MSSIM_ALG_SM2:
            return MSSIMS_SIGNATURE_SM2_Marshal(
                (MSSIMS_SIGNATURE_SM2*)&(source->sm2), buffer, size);
#  endif  // ALG_SM2
#  if ALG_ECSCHNORR
        case MSSIM_ALG_ECSCHNORR:
            return MSSIMS_SIGNATURE_ECSCHNORR_Marshal(
                (MSSIMS_SIGNATURE_ECSCHNORR*)&(source->ecschnorr), buffer, size);
#  endif  // ALG_ECSCHNORR
#  if ALG_HMAC
        case MSSIM_ALG_HMAC:
            return MSSIMT_HA_Marshal((MSSIMT_HA*)&(source->hmac), buffer, size);
#  endif  // ALG_HMAC
        case MSSIM_ALG_NULL:
            return 0;
    }
    return 0;
}

// Table 2:190 - Definition of MSSIMT_SIGNATURE Structure
MSSIM_RC
MSSIMT_SIGNATURE_Unmarshal(
    MSSIMT_SIGNATURE* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_SIG_SCHEME_Unmarshal(
        (MSSIMI_ALG_SIG_SCHEME*)&(target->sigAlg), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SIGNATURE_Unmarshal((MSSIMU_SIGNATURE*)&(target->signature),
                                          buffer,
                                          size,
                                          (UINT32)target->sigAlg);
    return result;
}
UINT16
MSSIMT_SIGNATURE_Marshal(MSSIMT_SIGNATURE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_SIG_SCHEME_Marshal(
                          (MSSIMI_ALG_SIG_SCHEME*)&(source->sigAlg), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_SIGNATURE_Marshal((MSSIMU_SIGNATURE*)&(source->signature),
                                               buffer,
                                               size,
                                               (UINT32)source->sigAlg));
    return result;
}

// Table 2:191 - Definition of MSSIMU_ENCRYPTED_SECRET Union
MSSIM_RC
MSSIMU_ENCRYPTED_SECRET_Unmarshal(
    MSSIMU_ENCRYPTED_SECRET* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->ecc), buffer, size, (INT32)sizeof(MSSIMS_ECC_POINT));
#  endif  // ALG_ECC
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return BYTE_Array_Unmarshal(
                (BYTE*)(target->rsa), buffer, size, (INT32)MAX_RSA_KEY_BYTES);
#  endif  // ALG_RSA
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return BYTE_Array_Unmarshal((BYTE*)(target->symmetric),
                                        buffer,
                                        size,
                                        (INT32)sizeof(MSSIM2B_DIGEST));
#  endif  // ALG_SYMCIPHER
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return BYTE_Array_Unmarshal((BYTE*)(target->keyedHash),
                                        buffer,
                                        size,
                                        (INT32)sizeof(MSSIM2B_DIGEST));
#  endif  // ALG_KEYEDHASH
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_ENCRYPTED_SECRET_Marshal(
    MSSIMU_ENCRYPTED_SECRET* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return BYTE_Array_Marshal(
                (BYTE*)(source->ecc), buffer, size, (INT32)sizeof(MSSIMS_ECC_POINT));
#  endif  // ALG_ECC
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return BYTE_Array_Marshal(
                (BYTE*)(source->rsa), buffer, size, (INT32)MAX_RSA_KEY_BYTES);
#  endif  // ALG_RSA
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return BYTE_Array_Marshal((BYTE*)(source->symmetric),
                                      buffer,
                                      size,
                                      (INT32)sizeof(MSSIM2B_DIGEST));
#  endif  // ALG_SYMCIPHER
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return BYTE_Array_Marshal((BYTE*)(source->keyedHash),
                                      buffer,
                                      size,
                                      (INT32)sizeof(MSSIM2B_DIGEST));
#  endif  // ALG_KEYEDHASH
    }
    return 0;
}

// Table 2:192 - Definition of MSSIM2B_ENCRYPTED_SECRET Structure
MSSIM_RC
MSSIM2B_ENCRYPTED_SECRET_Unmarshal(
    MSSIM2B_ENCRYPTED_SECRET* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMU_ENCRYPTED_SECRET))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.secret), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_ENCRYPTED_SECRET_Marshal(
    MSSIM2B_ENCRYPTED_SECRET* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.secret),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:193 - Definition of MSSIMI_ALG_PUBLIC Type
MSSIM_RC
MSSIMI_ALG_PUBLIC_Unmarshal(MSSIMI_ALG_PUBLIC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIM_ALG_ID_Unmarshal((MSSIM_ALG_ID*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
#  if ALG_RSA
            case MSSIM_ALG_RSA:
#  endif  // ALG_RSA
#  if ALG_ECC
            case MSSIM_ALG_ECC:
#  endif  // ALG_ECC
#  if ALG_KEYEDHASH
            case MSSIM_ALG_KEYEDHASH:
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
            case MSSIM_ALG_SYMCIPHER:
#  endif  // ALG_SYMCIPHER
                break;
            default:
                result = MSSIM_RC_TYPE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_PUBLIC_Marshal(MSSIMI_ALG_PUBLIC* source, BYTE** buffer, INT32* size)
{
    return MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:194 - Definition of MSSIMU_PUBLIC_ID Union
MSSIM_RC
MSSIMU_PUBLIC_ID_Unmarshal(
    MSSIMU_PUBLIC_ID* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return MSSIM2B_DIGEST_Unmarshal(
                (MSSIM2B_DIGEST*)&(target->keyedHash), buffer, size);
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return MSSIM2B_DIGEST_Unmarshal(
                (MSSIM2B_DIGEST*)&(target->sym), buffer, size);
#  endif  // ALG_SYMCIPHER
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return MSSIM2B_PUBLIC_KEY_RSA_Unmarshal(
                (MSSIM2B_PUBLIC_KEY_RSA*)&(target->rsa), buffer, size);
#  endif  // ALG_RSA
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return MSSIMS_ECC_POINT_Unmarshal(
                (MSSIMS_ECC_POINT*)&(target->ecc), buffer, size);
#  endif  // ALG_ECC
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_PUBLIC_ID_Marshal(
    MSSIMU_PUBLIC_ID* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return MSSIM2B_DIGEST_Marshal(
                (MSSIM2B_DIGEST*)&(source->keyedHash), buffer, size);
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)&(source->sym), buffer, size);
#  endif  // ALG_SYMCIPHER
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return MSSIM2B_PUBLIC_KEY_RSA_Marshal(
                (MSSIM2B_PUBLIC_KEY_RSA*)&(source->rsa), buffer, size);
#  endif  // ALG_RSA
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return MSSIMS_ECC_POINT_Marshal(
                (MSSIMS_ECC_POINT*)&(source->ecc), buffer, size);
#  endif  // ALG_ECC
    }
    return 0;
}

// Table 2:195 - Definition of MSSIMS_KEYEDHASH_PARMS Structure
MSSIM_RC
MSSIMS_KEYEDHASH_PARMS_Unmarshal(
    MSSIMS_KEYEDHASH_PARMS* target, BYTE** buffer, INT32* size)
{
    return MSSIMT_KEYEDHASH_SCHEME_Unmarshal(
        (MSSIMT_KEYEDHASH_SCHEME*)&(target->scheme), buffer, size, 1);
}
UINT16
MSSIMS_KEYEDHASH_PARMS_Marshal(MSSIMS_KEYEDHASH_PARMS* source, BYTE** buffer, INT32* size)
{
    return MSSIMT_KEYEDHASH_SCHEME_Marshal(
        (MSSIMT_KEYEDHASH_SCHEME*)&(source->scheme), buffer, size);
}

// Table 2:196 - Definition of MSSIMS_ASYM_PARMS Structure
// Table 2:197 - Definition of MSSIMS_RSA_PARMS Structure
#  if ALG_RSA
MSSIM_RC
MSSIMS_RSA_PARMS_Unmarshal(MSSIMS_RSA_PARMS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIMT_SYM_DEF_OBJECT_Unmarshal(
        (MSSIMT_SYM_DEF_OBJECT*)&(target->symmetric), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMT_RSA_SCHEME_Unmarshal(
            (MSSIMT_RSA_SCHEME*)&(target->scheme), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_RSA_KEY_BITS_Unmarshal(
            (MSSIMI_RSA_KEY_BITS*)&(target->keyBits), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT32_Unmarshal((UINT32*)&(target->exponent), buffer, size);
    return result;
}
UINT16
MSSIMS_RSA_PARMS_Marshal(MSSIMS_RSA_PARMS* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMT_SYM_DEF_OBJECT_Marshal(
                          (MSSIMT_SYM_DEF_OBJECT*)&(source->symmetric), buffer, size));
    result        = (UINT16)(result
                      + MSSIMT_RSA_SCHEME_Marshal(
                          (MSSIMT_RSA_SCHEME*)&(source->scheme), buffer, size));
    result        = (UINT16)(result
                      + MSSIMI_RSA_KEY_BITS_Marshal(
                          (MSSIMI_RSA_KEY_BITS*)&(source->keyBits), buffer, size));
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->exponent), buffer, size));
    return result;
}
#  endif  // ALG_RSA

// Table 2:198 - Definition of MSSIMS_ECC_PARMS Structure
#  if ALG_ECC
MSSIM_RC
MSSIMS_ECC_PARMS_Unmarshal(MSSIMS_ECC_PARMS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIMT_SYM_DEF_OBJECT_Unmarshal(
        (MSSIMT_SYM_DEF_OBJECT*)&(target->symmetric), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMT_ECC_SCHEME_Unmarshal(
            (MSSIMT_ECC_SCHEME*)&(target->scheme), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_ECC_CURVE_Unmarshal(
            (MSSIMI_ECC_CURVE*)&(target->curveID), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMT_KDF_SCHEME_Unmarshal(
            (MSSIMT_KDF_SCHEME*)&(target->kdf), buffer, size, 1);
    return result;
}
UINT16
MSSIMS_ECC_PARMS_Marshal(MSSIMS_ECC_PARMS* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMT_SYM_DEF_OBJECT_Marshal(
                          (MSSIMT_SYM_DEF_OBJECT*)&(source->symmetric), buffer, size));
    result        = (UINT16)(result
                      + MSSIMT_ECC_SCHEME_Marshal(
                          (MSSIMT_ECC_SCHEME*)&(source->scheme), buffer, size));
    result        = (UINT16)(result
                      + MSSIMI_ECC_CURVE_Marshal(
                          (MSSIMI_ECC_CURVE*)&(source->curveID), buffer, size));
    result        = (UINT16)(result
                      + MSSIMT_KDF_SCHEME_Marshal(
                          (MSSIMT_KDF_SCHEME*)&(source->kdf), buffer, size));
    return result;
}
#  endif  // ALG_ECC

// Table 2:199 - Definition of MSSIMU_PUBLIC_PARMS Union
MSSIM_RC
MSSIMU_PUBLIC_PARMS_Unmarshal(
    MSSIMU_PUBLIC_PARMS* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return MSSIMS_KEYEDHASH_PARMS_Unmarshal(
                (MSSIMS_KEYEDHASH_PARMS*)&(target->keyedHashDetail), buffer, size);
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return MSSIMS_SYMCIPHER_PARMS_Unmarshal(
                (MSSIMS_SYMCIPHER_PARMS*)&(target->symDetail), buffer, size);
#  endif  // ALG_SYMCIPHER
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return MSSIMS_RSA_PARMS_Unmarshal(
                (MSSIMS_RSA_PARMS*)&(target->rsaDetail), buffer, size);
#  endif  // ALG_RSA
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return MSSIMS_ECC_PARMS_Unmarshal(
                (MSSIMS_ECC_PARMS*)&(target->eccDetail), buffer, size);
#  endif  // ALG_ECC
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_PUBLIC_PARMS_Marshal(
    MSSIMU_PUBLIC_PARMS* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return MSSIMS_KEYEDHASH_PARMS_Marshal(
                (MSSIMS_KEYEDHASH_PARMS*)&(source->keyedHashDetail), buffer, size);
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return MSSIMS_SYMCIPHER_PARMS_Marshal(
                (MSSIMS_SYMCIPHER_PARMS*)&(source->symDetail), buffer, size);
#  endif  // ALG_SYMCIPHER
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return MSSIMS_RSA_PARMS_Marshal(
                (MSSIMS_RSA_PARMS*)&(source->rsaDetail), buffer, size);
#  endif  // ALG_RSA
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return MSSIMS_ECC_PARMS_Marshal(
                (MSSIMS_ECC_PARMS*)&(source->eccDetail), buffer, size);
#  endif  // ALG_ECC
    }
    return 0;
}

// Table 2:200 - Definition of MSSIMT_PUBLIC_PARMS Structure
MSSIM_RC
MSSIMT_PUBLIC_PARMS_Unmarshal(MSSIMT_PUBLIC_PARMS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_PUBLIC_Unmarshal((MSSIMI_ALG_PUBLIC*)&(target->type), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIMU_PUBLIC_PARMS_Unmarshal((MSSIMU_PUBLIC_PARMS*)&(target->parameters),
                                        buffer,
                                        size,
                                        (UINT32)target->type);
    return result;
}
UINT16
MSSIMT_PUBLIC_PARMS_Marshal(MSSIMT_PUBLIC_PARMS* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_PUBLIC_Marshal(
                          (MSSIMI_ALG_PUBLIC*)&(source->type), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_PUBLIC_PARMS_Marshal(
                          (MSSIMU_PUBLIC_PARMS*)&(source->parameters),
                          buffer,
                          size,
                          (UINT32)source->type));
    return result;
}

// Table 2:201 - Definition of MSSIMT_PUBLIC Structure
MSSIM_RC
MSSIMT_PUBLIC_Unmarshal(MSSIMT_PUBLIC* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result =
        MSSIMI_ALG_PUBLIC_Unmarshal((MSSIMI_ALG_PUBLIC*)&(target->type), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_ALG_HASH_Unmarshal(
            (MSSIMI_ALG_HASH*)&(target->nameAlg), buffer, size, flag);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMA_OBJECT_Unmarshal(
            (MSSIMA_OBJECT*)&(target->objectAttributes), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_DIGEST_Unmarshal(
            (MSSIM2B_DIGEST*)&(target->authPolicy), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIMU_PUBLIC_PARMS_Unmarshal((MSSIMU_PUBLIC_PARMS*)&(target->parameters),
                                        buffer,
                                        size,
                                        (UINT32)target->type);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_PUBLIC_ID_Unmarshal(
            (MSSIMU_PUBLIC_ID*)&(target->unique), buffer, size, (UINT32)target->type);
    return result;
}
UINT16
MSSIMT_PUBLIC_Marshal(MSSIMT_PUBLIC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_PUBLIC_Marshal(
                          (MSSIMI_ALG_PUBLIC*)&(source->type), buffer, size));
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->nameAlg), buffer, size));
    result        = (UINT16)(result
                      + MSSIMA_OBJECT_Marshal(
                          (MSSIMA_OBJECT*)&(source->objectAttributes), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->authPolicy), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_PUBLIC_PARMS_Marshal(
                          (MSSIMU_PUBLIC_PARMS*)&(source->parameters),
                          buffer,
                          size,
                          (UINT32)source->type));
    result        = (UINT16)(result
                      + MSSIMU_PUBLIC_ID_Marshal((MSSIMU_PUBLIC_ID*)&(source->unique),
                                               buffer,
                                               size,
                                               (UINT32)source->type));
    return result;
}

// Table 2:202 - Definition of MSSIM2B_PUBLIC Structure
MSSIM_RC
MSSIM2B_PUBLIC_Unmarshal(MSSIM2B_PUBLIC* target, BYTE** buffer, INT32* size, BOOL flag)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->size), buffer, size);  // =a
    if(result == MSSIM_RC_SUCCESS)
    {
        // if size is zero, then the required structure is missing
        if(target->size == 0)
            result = MSSIM_RC_SIZE;
        else
        {
            INT32 startSize = *size;
            result          = MSSIMT_PUBLIC_Unmarshal(
                (MSSIMT_PUBLIC*)&(target->publicArea), buffer, size, flag);  // =b
            if(result == MSSIM_RC_SUCCESS)
            {
                if(target->size != (startSize - *size))
                    result = MSSIM_RC_SIZE;
            }
        }
    }
    return result;
}
UINT16
MSSIM2B_PUBLIC_Marshal(MSSIM2B_PUBLIC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    // Marshal a dummy value of the 2B size. This makes sure that 'buffer'
    // and 'size' are advanced as necessary (i.e., if they are present)
    result = UINT16_Marshal(&result, buffer, size);
    // Marshal the structure
    result = (UINT16)(result
                      + MSSIMT_PUBLIC_Marshal(
                          (MSSIMT_PUBLIC*)&(source->publicArea), buffer, size));
    // if a buffer was provided, go back and fill in the actual size
    if(buffer != NULL)
        UINT16_TO_BYTE_ARRAY((result - 2), (*buffer - result));
    return result;
}

// Table 2:203 - Definition of MSSIM2B_TEMPLATE Structure
MSSIM_RC
MSSIM2B_TEMPLATE_Unmarshal(MSSIM2B_TEMPLATE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMT_PUBLIC))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_TEMPLATE_Marshal(MSSIM2B_TEMPLATE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:204 - Definition of MSSIM2B_PRIVATE_VENDOR_SPECIFIC Structure
MSSIM_RC
MSSIM2B_PRIVATE_VENDOR_SPECIFIC_Unmarshal(
    MSSIM2B_PRIVATE_VENDOR_SPECIFIC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > PRIVATE_VENDOR_SPECIFIC_BYTES)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_PRIVATE_VENDOR_SPECIFIC_Marshal(
    MSSIM2B_PRIVATE_VENDOR_SPECIFIC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:205 - Definition of MSSIMU_SENSITIVE_COMPOSITE Union
MSSIM_RC
MSSIMU_SENSITIVE_COMPOSITE_Unmarshal(
    MSSIMU_SENSITIVE_COMPOSITE* target, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return MSSIM2B_PRIVATE_KEY_RSA_Unmarshal(
                (MSSIM2B_PRIVATE_KEY_RSA*)&(target->rsa), buffer, size);
#  endif  // ALG_RSA
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return MSSIM2B_ECC_PARAMETER_Unmarshal(
                (MSSIM2B_ECC_PARAMETER*)&(target->ecc), buffer, size);
#  endif  // ALG_ECC
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return MSSIM2B_SENSITIVE_DATA_Unmarshal(
                (MSSIM2B_SENSITIVE_DATA*)&(target->bits), buffer, size);
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return MSSIM2B_SYM_KEY_Unmarshal(
                (MSSIM2B_SYM_KEY*)&(target->sym), buffer, size);
#  endif  // ALG_SYMCIPHER
    }
    return MSSIM_RC_SELECTOR;
}
UINT16
MSSIMU_SENSITIVE_COMPOSITE_Marshal(
    MSSIMU_SENSITIVE_COMPOSITE* source, BYTE** buffer, INT32* size, UINT32 selector)
{
    switch(selector)
    {
#  if ALG_RSA
        case MSSIM_ALG_RSA:
            return MSSIM2B_PRIVATE_KEY_RSA_Marshal(
                (MSSIM2B_PRIVATE_KEY_RSA*)&(source->rsa), buffer, size);
#  endif  // ALG_RSA
#  if ALG_ECC
        case MSSIM_ALG_ECC:
            return MSSIM2B_ECC_PARAMETER_Marshal(
                (MSSIM2B_ECC_PARAMETER*)&(source->ecc), buffer, size);
#  endif  // ALG_ECC
#  if ALG_KEYEDHASH
        case MSSIM_ALG_KEYEDHASH:
            return MSSIM2B_SENSITIVE_DATA_Marshal(
                (MSSIM2B_SENSITIVE_DATA*)&(source->bits), buffer, size);
#  endif  // ALG_KEYEDHASH
#  if ALG_SYMCIPHER
        case MSSIM_ALG_SYMCIPHER:
            return MSSIM2B_SYM_KEY_Marshal(
                (MSSIM2B_SYM_KEY*)&(source->sym), buffer, size);
#  endif  // ALG_SYMCIPHER
    }
    return 0;
}

// Table 2:206 - Definition of MSSIMT_SENSITIVE Structure
MSSIM_RC
MSSIMT_SENSITIVE_Unmarshal(MSSIMT_SENSITIVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIMI_ALG_PUBLIC_Unmarshal(
        (MSSIMI_ALG_PUBLIC*)&(target->sensitiveType), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_AUTH_Unmarshal((MSSIM2B_AUTH*)&(target->authValue), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result =
            MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)&(target->seedValue), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMU_SENSITIVE_COMPOSITE_Unmarshal(
            (MSSIMU_SENSITIVE_COMPOSITE*)&(target->sensitive),
            buffer,
            size,
            (UINT32)target->sensitiveType);
    return result;
}
UINT16
MSSIMT_SENSITIVE_Marshal(MSSIMT_SENSITIVE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_ALG_PUBLIC_Marshal(
                          (MSSIMI_ALG_PUBLIC*)&(source->sensitiveType), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_AUTH_Marshal(
                          (MSSIM2B_AUTH*)&(source->authValue), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->seedValue), buffer, size));
    result        = (UINT16)(result
                      + MSSIMU_SENSITIVE_COMPOSITE_Marshal(
                          (MSSIMU_SENSITIVE_COMPOSITE*)&(source->sensitive),
                          buffer,
                          size,
                          (UINT32)source->sensitiveType));
    return result;
}

// Table 2:207 - Definition of MSSIM2B_SENSITIVE Structure
MSSIM_RC
MSSIM2B_SENSITIVE_Unmarshal(MSSIM2B_SENSITIVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->size), buffer, size);  // =a
    // if there was an error or if target->size equal to 0,
    // skip unmarshaling of the structure
    if((result == MSSIM_RC_SUCCESS) && (target->size != 0))
    {
        INT32 startSize = *size;
        result          = MSSIMT_SENSITIVE_Unmarshal(
            (MSSIMT_SENSITIVE*)&(target->sensitiveArea), buffer, size);  // =b
        if(result == MSSIM_RC_SUCCESS)
        {
            if(target->size != (startSize - *size))
                result = MSSIM_RC_SIZE;
        }
    }
    return result;
}
UINT16
MSSIM2B_SENSITIVE_Marshal(MSSIM2B_SENSITIVE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    // Marshal a dummy value of the 2B size. This makes sure that 'buffer'
    // and 'size' are advanced as necessary (i.e., if they are present)
    result = UINT16_Marshal(&result, buffer, size);
    // Marshal the structure
    result = (UINT16)(result
                      + MSSIMT_SENSITIVE_Marshal(
                          (MSSIMT_SENSITIVE*)&(source->sensitiveArea), buffer, size));
    // if a buffer was provided, go back and fill in the actual size
    if(buffer != NULL)
        UINT16_TO_BYTE_ARRAY((result - 2), (*buffer - result));
    return result;
}

// Table 2:208 - Definition of _MSSIMPRIVATE Structure
// Table 2:209 - Definition of MSSIM2B_PRIVATE Structure
MSSIM_RC
MSSIM2B_PRIVATE_Unmarshal(MSSIM2B_PRIVATE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(_MSSIMPRIVATE))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_PRIVATE_Marshal(MSSIM2B_PRIVATE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:210 - Definition of MSSIMS_ID_OBJECT Structure
// Table 2:211 - Definition of MSSIM2B_ID_OBJECT Structure
MSSIM_RC
MSSIM2B_ID_OBJECT_Unmarshal(MSSIM2B_ID_OBJECT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMS_ID_OBJECT))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.credential), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_ID_OBJECT_Marshal(MSSIM2B_ID_OBJECT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.credential),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:212 - Definition of MSSIM_NV_INDEX Bits
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_NV_INDEX_Marshal(MSSIM_NV_INDEX* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:213 - Definition of MSSIM_NT Constants
// Table 2:214 - Definition of MSSIMS_NV_PIN_COUNTER_PARAMETERS Structure
MSSIM_RC
MSSIMS_NV_PIN_COUNTER_PARAMETERS_Unmarshal(
    MSSIMS_NV_PIN_COUNTER_PARAMETERS* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)&(target->pinCount), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT32_Unmarshal((UINT32*)&(target->pinLimit), buffer, size);
    return result;
}
UINT16
MSSIMS_NV_PIN_COUNTER_PARAMETERS_Marshal(
    MSSIMS_NV_PIN_COUNTER_PARAMETERS* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->pinCount), buffer, size));
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->pinLimit), buffer, size));
    return result;
}

// Table 2:215 - Definition of MSSIMA_NV Bits
MSSIM_RC
MSSIMA_NV_Unmarshal(MSSIMA_NV* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if(*((UINT32*)target) & (UINT32)0x01f00300)
            result = MSSIM_RC_RESERVED_BITS;
    }
    return result;
}

#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_NV_Marshal(MSSIMA_NV* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:216 - Definition of MSSIMS_NV_PUBLIC Structure
MSSIM_RC
MSSIMS_NV_PUBLIC_Unmarshal(MSSIMS_NV_PUBLIC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = MSSIMI_RH_NV_INDEX_Unmarshal(
        (MSSIMI_RH_NV_INDEX*)&(target->nvIndex), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_ALG_HASH_Unmarshal(
            (MSSIMI_ALG_HASH*)&(target->nameAlg), buffer, size, 0);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMA_NV_Unmarshal((MSSIMA_NV*)&(target->attributes), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_DIGEST_Unmarshal(
            (MSSIM2B_DIGEST*)&(target->authPolicy), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = UINT16_Unmarshal((UINT16*)&(target->dataSize), buffer, size);
    if((result == MSSIM_RC_SUCCESS) && (target->dataSize > MAX_NV_INDEX_SIZE))
        result = MSSIM_RC_SIZE;
    return result;
}
UINT16
MSSIMS_NV_PUBLIC_Marshal(MSSIMS_NV_PUBLIC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIMI_RH_NV_INDEX_Marshal(
                          (MSSIMI_RH_NV_INDEX*)&(source->nvIndex), buffer, size));
    result        = (UINT16)(result
                      + MSSIMI_ALG_HASH_Marshal(
                          (MSSIMI_ALG_HASH*)&(source->nameAlg), buffer, size));
    result =
        (UINT16)(result
                 + MSSIMA_NV_Marshal((MSSIMA_NV*)&(source->attributes), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->authPolicy), buffer, size));
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->dataSize), buffer, size));
    return result;
}

// Table 2:217 - Definition of MSSIM2B_NV_PUBLIC Structure
MSSIM_RC
MSSIM2B_NV_PUBLIC_Unmarshal(MSSIM2B_NV_PUBLIC* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->size), buffer, size);  // =a
    if(result == MSSIM_RC_SUCCESS)
    {
        // if size is zero, then the required structure is missing
        if(target->size == 0)
            result = MSSIM_RC_SIZE;
        else
        {
            INT32 startSize = *size;
            result          = MSSIMS_NV_PUBLIC_Unmarshal(
                (MSSIMS_NV_PUBLIC*)&(target->nvPublic), buffer, size);  // =b
            if(result == MSSIM_RC_SUCCESS)
            {
                if(target->size != (startSize - *size))
                    result = MSSIM_RC_SIZE;
            }
        }
    }
    return result;
}
UINT16
MSSIM2B_NV_PUBLIC_Marshal(MSSIM2B_NV_PUBLIC* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    // Marshal a dummy value of the 2B size. This makes sure that 'buffer'
    // and 'size' are advanced as necessary (i.e., if they are present)
    result = UINT16_Marshal(&result, buffer, size);
    // Marshal the structure
    result = (UINT16)(result
                      + MSSIMS_NV_PUBLIC_Marshal(
                          (MSSIMS_NV_PUBLIC*)&(source->nvPublic), buffer, size));
    // if a buffer was provided, go back and fill in the actual size
    if(buffer != NULL)
        UINT16_TO_BYTE_ARRAY((result - 2), (*buffer - result));
    return result;
}

// Table 2:218 - Definition of MSSIM2B_CONTEXT_SENSITIVE Structure
MSSIM_RC
MSSIM2B_CONTEXT_SENSITIVE_Unmarshal(
    MSSIM2B_CONTEXT_SENSITIVE* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > MAX_CONTEXT_SIZE)
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_CONTEXT_SENSITIVE_Marshal(
    MSSIM2B_CONTEXT_SENSITIVE* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:219 - Definition of MSSIMS_CONTEXT_DATA Structure
MSSIM_RC
MSSIMS_CONTEXT_DATA_Unmarshal(MSSIMS_CONTEXT_DATA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result =
        MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)&(target->integrity), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_CONTEXT_SENSITIVE_Unmarshal(
            (MSSIM2B_CONTEXT_SENSITIVE*)&(target->encrypted), buffer, size);
    return result;
}
UINT16
MSSIMS_CONTEXT_DATA_Marshal(MSSIMS_CONTEXT_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->integrity), buffer, size));
    result =
        (UINT16)(result
                 + MSSIM2B_CONTEXT_SENSITIVE_Marshal(
                     (MSSIM2B_CONTEXT_SENSITIVE*)&(source->encrypted), buffer, size));
    return result;
}

// Table 2:220 - Definition of MSSIM2B_CONTEXT_DATA Structure
MSSIM_RC
MSSIM2B_CONTEXT_DATA_Unmarshal(MSSIM2B_CONTEXT_DATA* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT16_Unmarshal((UINT16*)&(target->t.size), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        if((target->t.size) > sizeof(MSSIMS_CONTEXT_DATA))
            result = MSSIM_RC_SIZE;
        else
            result = BYTE_Array_Unmarshal(
                (BYTE*)(target->t.buffer), buffer, size, (INT32)(target->t.size));
    }
    return result;
}
UINT16
MSSIM2B_CONTEXT_DATA_Marshal(MSSIM2B_CONTEXT_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT16_Marshal((UINT16*)&(source->t.size), buffer, size));
    // if size equal to 0, the rest of the structure is a zero buffer.  Stop processing
    if(source->t.size == 0)
        return result;
    result = (UINT16)(result
                      + BYTE_Array_Marshal((BYTE*)(source->t.buffer),
                                           buffer,
                                           size,
                                           (INT32)(source->t.size)));
    return result;
}

// Table 2:221 - Definition of MSSIMS_CONTEXT Structure
MSSIM_RC
MSSIMS_CONTEXT_Unmarshal(MSSIMS_CONTEXT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT64_Unmarshal((UINT64*)&(target->sequence), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_DH_SAVED_Unmarshal(
            (MSSIMI_DH_SAVED*)&(target->savedHandle), buffer, size);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIMI_RH_HIERARCHY_Unmarshal(
            (MSSIMI_RH_HIERARCHY*)&(target->hierarchy), buffer, size, 1);
    if(result == MSSIM_RC_SUCCESS)
        result = MSSIM2B_CONTEXT_DATA_Unmarshal(
            (MSSIM2B_CONTEXT_DATA*)&(target->contextBlob), buffer, size);
    return result;
}
UINT16
MSSIMS_CONTEXT_Marshal(MSSIMS_CONTEXT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT64_Marshal((UINT64*)&(source->sequence), buffer, size));
    result = (UINT16)(result
                      + MSSIMI_DH_SAVED_Marshal(
                          (MSSIMI_DH_SAVED*)&(source->savedHandle), buffer, size));
    result = (UINT16)(result
                      + MSSIMI_RH_HIERARCHY_Marshal(
                          (MSSIMI_RH_HIERARCHY*)&(source->hierarchy), buffer, size));
    result = (UINT16)(result
                      + MSSIM2B_CONTEXT_DATA_Marshal(
                          (MSSIM2B_CONTEXT_DATA*)&(source->contextBlob), buffer, size));
    return result;
}

// Table 2:223 - Definition of MSSIMS_CREATION_DATA Structure
UINT16
MSSIMS_CREATION_DATA_Marshal(MSSIMS_CREATION_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result        = (UINT16)(result
                      + MSSIML_PCR_SELECTION_Marshal(
                          (MSSIML_PCR_SELECTION*)&(source->pcrSelect), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DIGEST_Marshal(
                          (MSSIM2B_DIGEST*)&(source->pcrDigest), buffer, size));
    result        = (UINT16)(result
                      + MSSIMA_LOCALITY_Marshal(
                          (MSSIMA_LOCALITY*)&(source->locality), buffer, size));
    result        = (UINT16)(result
                      + MSSIM_ALG_ID_Marshal(
                          (MSSIM_ALG_ID*)&(source->parentNameAlg), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->parentName), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_NAME_Marshal(
                          (MSSIM2B_NAME*)&(source->parentQualifiedName), buffer, size));
    result        = (UINT16)(result
                      + MSSIM2B_DATA_Marshal(
                          (MSSIM2B_DATA*)&(source->outsideInfo), buffer, size));
    return result;
}

// Table 2:224 - Definition of MSSIM2B_CREATION_DATA Structure
UINT16
MSSIM2B_CREATION_DATA_Marshal(MSSIM2B_CREATION_DATA* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    // Marshal a dummy value of the 2B size. This makes sure that 'buffer'
    // and 'size' are advanced as necessary (i.e., if they are present)
    result = UINT16_Marshal(&result, buffer, size);
    // Marshal the structure
    result =
        (UINT16)(result
                 + MSSIMS_CREATION_DATA_Marshal(
                     (MSSIMS_CREATION_DATA*)&(source->creationData), buffer, size));
    // if a buffer was provided, go back and fill in the actual size
    if(buffer != NULL)
        UINT16_TO_BYTE_ARRAY((result - 2), (*buffer - result));
    return result;
}

// Table 2:225 - Definition of MSSIM_AT Constants
MSSIM_RC
MSSIM_AT_Unmarshal(MSSIM_AT* target, BYTE** buffer, INT32* size)
{
    MSSIM_RC result;
    result = UINT32_Unmarshal((UINT32*)target, buffer, size);
    if(result == MSSIM_RC_SUCCESS)
    {
        switch(*target)
        {
            case MSSIM_AT_ANY:
            case MSSIM_AT_ERROR:
            case MSSIM_AT_PV1:
            case MSSIM_AT_VEND:
                break;
            default:
                result = MSSIM_RC_VALUE;
                break;
        }
    }
    return result;
}
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_AT_Marshal(MSSIM_AT* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:226 - Definition of MSSIM_AE Constants
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_AE_Marshal(MSSIM_AE* source, BYTE** buffer, INT32* size)
{
    return UINT32_Marshal((UINT32*)source, buffer, size);
}
#  endif  // !USE_MARSHALING_DEFINES

// Table 2:227 - Definition of MSSIMS_AC_OUTPUT Structure
UINT16
MSSIMS_AC_OUTPUT_Marshal(MSSIMS_AC_OUTPUT* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result = (UINT16)(result + MSSIM_AT_Marshal((MSSIM_AT*)&(source->tag), buffer, size));
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->data), buffer, size));
    return result;
}

// Table 2:228 - Definition of MSSIML_AC_CAPABILITIES Structure
UINT16
MSSIML_AC_CAPABILITIES_Marshal(MSSIML_AC_CAPABILITIES* source, BYTE** buffer, INT32* size)
{
    UINT16 result = 0;
    result =
        (UINT16)(result + UINT32_Marshal((UINT32*)&(source->count), buffer, size));
    result = (UINT16)(result
                      + MSSIMS_AC_OUTPUT_Array_Marshal(
                          (MSSIMS_AC_OUTPUT*)(source->acCapabilities),
                          buffer,
                          size,
                          (INT32)(source->count)));
    return result;
}

// Array Marshal/Unmarshal for BYTE
MSSIM_RC
BYTE_Array_Unmarshal(BYTE* target, BYTE** buffer, INT32* size, INT32 count)
{
    if(*size < count)
        return MSSIM_RC_INSUFFICIENT;
    memcpy(target, *buffer, count);
    *size -= count;
    *buffer += count;
    return MSSIM_RC_SUCCESS;
}
UINT16
BYTE_Array_Marshal(BYTE* source, BYTE** buffer, INT32* size, INT32 count)
{
    if(buffer != 0)
    {
        if((size == 0) || ((*size -= count) >= 0))
        {
            memcpy(*buffer, source, count);
            *buffer += count;
        }
        pAssert(size == 0 || (*size >= 0));
    }
    pAssert(count < INT16_MAX);
    return ((UINT16)count);
}

// Array Marshal/Unmarshal for MSSIM2B_DIGEST
MSSIM_RC
MSSIM2B_DIGEST_Array_Unmarshal(
    MSSIM2B_DIGEST* target, BYTE** buffer, INT32* size, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIM2B_DIGEST_Unmarshal(&target[i], buffer, size);
    }
    return result;
}
UINT16
MSSIM2B_DIGEST_Array_Marshal(
    MSSIM2B_DIGEST* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIM2B_DIGEST_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMA_CC
UINT16
MSSIMA_CC_Array_Marshal(MSSIMA_CC* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIMA_CC_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMS_ACT_DATA
UINT16
MSSIMS_ACT_DATA_Array_Marshal(
    MSSIMS_ACT_DATA* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIMS_ACT_DATA_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMS_AC_OUTPUT
UINT16
MSSIMS_AC_OUTPUT_Array_Marshal(
    MSSIMS_AC_OUTPUT* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIMS_AC_OUTPUT_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMS_ALG_PROPERTY
UINT16
MSSIMS_ALG_PROPERTY_Array_Marshal(
    MSSIMS_ALG_PROPERTY* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result =
            (UINT16)(result + MSSIMS_ALG_PROPERTY_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for MSSIMS_PCR_SELECTION
MSSIM_RC
MSSIMS_PCR_SELECTION_Array_Unmarshal(
    MSSIMS_PCR_SELECTION* target, BYTE** buffer, INT32* size, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIMS_PCR_SELECTION_Unmarshal(&target[i], buffer, size);
    }
    return result;
}
UINT16
MSSIMS_PCR_SELECTION_Array_Marshal(
    MSSIMS_PCR_SELECTION* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result =
            (UINT16)(result + MSSIMS_PCR_SELECTION_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMS_TAGGED_PCR_SELECT
UINT16
MSSIMS_TAGGED_PCR_SELECT_Array_Marshal(
    MSSIMS_TAGGED_PCR_SELECT* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result
                          + MSSIMS_TAGGED_PCR_SELECT_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMS_TAGGED_POLICY
UINT16
MSSIMS_TAGGED_POLICY_Array_Marshal(
    MSSIMS_TAGGED_POLICY* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result =
            (UINT16)(result + MSSIMS_TAGGED_POLICY_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal for MSSIMS_TAGGED_PROPERTY
UINT16
MSSIMS_TAGGED_PROPERTY_Array_Marshal(
    MSSIMS_TAGGED_PROPERTY* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result =
            (UINT16)(result + MSSIMS_TAGGED_PROPERTY_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for MSSIMT_HA
MSSIM_RC
MSSIMT_HA_Array_Unmarshal(
    MSSIMT_HA* target, BYTE** buffer, INT32* size, BOOL flag, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIMT_HA_Unmarshal(&target[i], buffer, size, flag);
    }
    return result;
}
UINT16
MSSIMT_HA_Array_Marshal(MSSIMT_HA* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIMT_HA_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for MSSIM_ALG_ID
MSSIM_RC
MSSIM_ALG_ID_Array_Unmarshal(
    MSSIM_ALG_ID* target, BYTE** buffer, INT32* size, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIM_ALG_ID_Unmarshal(&target[i], buffer, size);
    }
    return result;
}
UINT16
MSSIM_ALG_ID_Array_Marshal(MSSIM_ALG_ID* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIM_ALG_ID_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for MSSIM_CC
MSSIM_RC
MSSIM_CC_Array_Unmarshal(MSSIM_CC* target, BYTE** buffer, INT32* size, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIM_CC_Unmarshal(&target[i], buffer, size);
    }
    return result;
}
UINT16
MSSIM_CC_Array_Marshal(MSSIM_CC* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIM_CC_Marshal(&source[i], buffer, size));
    }
    return result;
}

// Array Marshal/Unmarshal for MSSIM_ECC_CURVE
#  if ALG_ECC
MSSIM_RC
MSSIM_ECC_CURVE_Array_Unmarshal(
    MSSIM_ECC_CURVE* target, BYTE** buffer, INT32* size, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIM_ECC_CURVE_Unmarshal(&target[i], buffer, size);
    }
    return result;
}
UINT16
MSSIM_ECC_CURVE_Array_Marshal(
    MSSIM_ECC_CURVE* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIM_ECC_CURVE_Marshal(&source[i], buffer, size));
    }
    return result;
}
#  endif  // ALG_ECC

// Array Marshal/Unmarshal for MSSIM_HANDLE
MSSIM_RC
MSSIM_HANDLE_Array_Unmarshal(
    MSSIM_HANDLE* target, BYTE** buffer, INT32* size, INT32 count)
{
    MSSIM_RC result;
    INT32  i;
    for(result = MSSIM_RC_SUCCESS, i = 0; ((result == MSSIM_RC_SUCCESS) && (i < count));
        i++)
    {
        result = MSSIM_HANDLE_Unmarshal(&target[i], buffer, size);
    }
    return result;
}
UINT16
MSSIM_HANDLE_Array_Marshal(MSSIM_HANDLE* source, BYTE** buffer, INT32* size, INT32 count)
{
    UINT16 result = 0;
    INT32  i;
    for(i = 0; i < count; i++)
    {
        result = (UINT16)(result + MSSIM_HANDLE_Marshal(&source[i], buffer, size));
    }
    return result;
}

#endif  // !TABLE_DRIVEN_MARSHAL
