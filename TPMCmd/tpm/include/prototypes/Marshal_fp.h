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

#ifndef _MARSHAL_FP_H_
#define _MARSHAL_FP_H_

// Table 2:3 - Definition of Base Types
//   UINT8 definition from table 2:3
MSSIM_RC
UINT8_Unmarshal(UINT8* target, BYTE** buffer, INT32* size);
UINT16
UINT8_Marshal(UINT8* source, BYTE** buffer, INT32* size);

//   BYTE definition from table 2:3
#if !USE_MARSHALING_DEFINES
MSSIM_RC
BYTE_Unmarshal(BYTE* target, BYTE** buffer, INT32* size);
#else
#  define BYTE_Unmarshal(target, buffer, size) \
    UINT8_Unmarshal((UINT8*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
BYTE_Marshal(BYTE* source, BYTE** buffer, INT32* size);
#else
#  define BYTE_Marshal(source, buffer, size) \
    UINT8_Marshal((UINT8*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

//   INT8 definition from table 2:3
#if !USE_MARSHALING_DEFINES
MSSIM_RC
INT8_Unmarshal(INT8* target, BYTE** buffer, INT32* size);
#else
#  define INT8_Unmarshal(target, buffer, size) \
    UINT8_Unmarshal((UINT8*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
INT8_Marshal(INT8* source, BYTE** buffer, INT32* size);
#else
#  define INT8_Marshal(source, buffer, size) \
    UINT8_Marshal((UINT8*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

//   UINT16 definition from table 2:3
MSSIM_RC
UINT16_Unmarshal(UINT16* target, BYTE** buffer, INT32* size);
UINT16
UINT16_Marshal(UINT16* source, BYTE** buffer, INT32* size);

//   INT16 definition from table 2:3
#if !USE_MARSHALING_DEFINES
MSSIM_RC
INT16_Unmarshal(INT16* target, BYTE** buffer, INT32* size);
#else
#  define INT16_Unmarshal(target, buffer, size) \
    UINT16_Unmarshal((UINT16*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
INT16_Marshal(INT16* source, BYTE** buffer, INT32* size);
#else
#  define INT16_Marshal(source, buffer, size) \
    UINT16_Marshal((UINT16*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

//   UINT32 definition from table 2:3
MSSIM_RC
UINT32_Unmarshal(UINT32* target, BYTE** buffer, INT32* size);
UINT16
UINT32_Marshal(UINT32* source, BYTE** buffer, INT32* size);

//   INT32 definition from table 2:3
#if !USE_MARSHALING_DEFINES
MSSIM_RC
INT32_Unmarshal(INT32* target, BYTE** buffer, INT32* size);
#else
#  define INT32_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
INT32_Marshal(INT32* source, BYTE** buffer, INT32* size);
#else
#  define INT32_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

//   UINT64 definition from table 2:3
MSSIM_RC
UINT64_Unmarshal(UINT64* target, BYTE** buffer, INT32* size);
UINT16
UINT64_Marshal(UINT64* source, BYTE** buffer, INT32* size);

//   INT64 definition from table 2:3
#if !USE_MARSHALING_DEFINES
MSSIM_RC
INT64_Unmarshal(INT64* target, BYTE** buffer, INT32* size);
#else
#  define INT64_Unmarshal(target, buffer, size) \
    UINT64_Unmarshal((UINT64*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
INT64_Marshal(INT64* source, BYTE** buffer, INT32* size);
#else
#  define INT64_Marshal(source, buffer, size) \
    UINT64_Marshal((UINT64*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:4 - Defines for Logic Values
// Table 2:5 - Definition of Types for Documentation Clarity
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_ALGORITHM_ID_Unmarshal(MSSIM_ALGORITHM_ID* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_ALGORITHM_ID_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_ALGORITHM_ID_Marshal(MSSIM_ALGORITHM_ID* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_ALGORITHM_ID_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_MODIFIER_INDICATOR_Unmarshal(
    MSSIM_MODIFIER_INDICATOR* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_MODIFIER_INDICATOR_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_MODIFIER_INDICATOR_Marshal(
    MSSIM_MODIFIER_INDICATOR* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_MODIFIER_INDICATOR_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_AUTHORIZATION_SIZE_Unmarshal(
    MSSIM_AUTHORIZATION_SIZE* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_AUTHORIZATION_SIZE_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_AUTHORIZATION_SIZE_Marshal(
    MSSIM_AUTHORIZATION_SIZE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_AUTHORIZATION_SIZE_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_PARAMETER_SIZE_Unmarshal(MSSIM_PARAMETER_SIZE* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PARAMETER_SIZE_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_PARAMETER_SIZE_Marshal(MSSIM_PARAMETER_SIZE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PARAMETER_SIZE_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_KEY_SIZE_Unmarshal(MSSIM_KEY_SIZE* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_KEY_SIZE_Unmarshal(target, buffer, size) \
    UINT16_Unmarshal((UINT16*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_KEY_SIZE_Marshal(MSSIM_KEY_SIZE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_KEY_SIZE_Marshal(source, buffer, size) \
    UINT16_Marshal((UINT16*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_KEY_BITS_Unmarshal(MSSIM_KEY_BITS* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_KEY_BITS_Unmarshal(target, buffer, size) \
    UINT16_Unmarshal((UINT16*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_KEY_BITS_Marshal(MSSIM_KEY_BITS* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_KEY_BITS_Marshal(source, buffer, size) \
    UINT16_Marshal((UINT16*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:6 - Definition of MSSIM_SPEC Constants
// Table 2:7 - Definition of MSSIM_CONSTANTS32 Constants
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_CONSTANTS32_Marshal(MSSIM_CONSTANTS32* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_CONSTANTS32_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:9 - Definition of MSSIM_ALG_ID Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_ALG_ID_Unmarshal(MSSIM_ALG_ID* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_ALG_ID_Unmarshal(target, buffer, size) \
    UINT16_Unmarshal((UINT16*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_ALG_ID_Marshal(MSSIM_ALG_ID* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_ALG_ID_Marshal(source, buffer, size) \
    UINT16_Marshal((UINT16*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:10 - Definition of MSSIM_ECC_CURVE Constants
#if ALG_ECC
MSSIM_RC
MSSIM_ECC_CURVE_Unmarshal(MSSIM_ECC_CURVE* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIM_ECC_CURVE_Marshal(MSSIM_ECC_CURVE* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIM_ECC_CURVE_Marshal(source, buffer, size) \
      UINT16_Marshal((UINT16*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:12 - Definition of MSSIM_CC Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_CC_Unmarshal(MSSIM_CC* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_CC_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_CC_Marshal(MSSIM_CC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_CC_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:16 - Definition of MSSIM_RC Constants
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_RC_Marshal(MSSIM_RC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_RC_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:17 - Definition of MSSIM_CLOCK_ADJUST Constants
MSSIM_RC
MSSIM_CLOCK_ADJUST_Unmarshal(MSSIM_CLOCK_ADJUST* target, BYTE** buffer, INT32* size);

// Table 2:18 - Definition of MSSIM_EO Constants
MSSIM_RC
MSSIM_EO_Unmarshal(MSSIM_EO* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_EO_Marshal(MSSIM_EO* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_EO_Marshal(source, buffer, size) \
    UINT16_Marshal((UINT16*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:19 - Definition of MSSIM_ST Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_ST_Unmarshal(MSSIM_ST* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_ST_Unmarshal(target, buffer, size) \
    UINT16_Unmarshal((UINT16*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_ST_Marshal(MSSIM_ST* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_ST_Marshal(source, buffer, size) \
    UINT16_Marshal((UINT16*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:20 - Definition of MSSIM_SU Constants
MSSIM_RC
MSSIM_SU_Unmarshal(MSSIM_SU* target, BYTE** buffer, INT32* size);

// Table 2:21 - Definition of MSSIM_SE Constants
MSSIM_RC
MSSIM_SE_Unmarshal(MSSIM_SE* target, BYTE** buffer, INT32* size);

// Table 2:22 - Definition of MSSIM_CAP Constants
MSSIM_RC
MSSIM_CAP_Unmarshal(MSSIM_CAP* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_CAP_Marshal(MSSIM_CAP* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_CAP_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:23 - Definition of MSSIM_PT Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_PT_Unmarshal(MSSIM_PT* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PT_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_PT_Marshal(MSSIM_PT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PT_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:24 - Definition of MSSIM_PT_PCR Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_PT_PCR_Unmarshal(MSSIM_PT_PCR* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PT_PCR_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_PT_PCR_Marshal(MSSIM_PT_PCR* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PT_PCR_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:25 - Definition of MSSIM_PS Constants
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_PS_Marshal(MSSIM_PS* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_PS_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:26 - Definition of Types for Handles
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_HANDLE_Unmarshal(MSSIM_HANDLE* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_HANDLE_Unmarshal(target, buffer, size) \
    UINT32_Unmarshal((UINT32*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_HANDLE_Marshal(MSSIM_HANDLE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_HANDLE_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:27 - Definition of MSSIM_HT Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_HT_Unmarshal(MSSIM_HT* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_HT_Unmarshal(target, buffer, size) \
    UINT8_Unmarshal((UINT8*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_HT_Marshal(MSSIM_HT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_HT_Marshal(source, buffer, size) \
    UINT8_Marshal((UINT8*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:28 - Definition of MSSIM_RH Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_RH_Unmarshal(MSSIM_RH* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_RH_Unmarshal(target, buffer, size) \
    MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_RH_Marshal(MSSIM_RH* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_RH_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:29 - Definition of MSSIM_HC Constants
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM_HC_Unmarshal(MSSIM_HC* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM_HC_Unmarshal(target, buffer, size) \
    MSSIM_HANDLE_Unmarshal((MSSIM_HANDLE*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_HC_Marshal(MSSIM_HC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_HC_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:30 - Definition of MSSIMA_ALGORITHM Bits
MSSIM_RC
MSSIMA_ALGORITHM_Unmarshal(MSSIMA_ALGORITHM* target, BYTE** buffer, INT32* size);

#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_ALGORITHM_Marshal(MSSIMA_ALGORITHM* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_ALGORITHM_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:31 - Definition of MSSIMA_OBJECT Bits
MSSIM_RC
MSSIMA_OBJECT_Unmarshal(MSSIMA_OBJECT* target, BYTE** buffer, INT32* size);

#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_OBJECT_Marshal(MSSIMA_OBJECT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_OBJECT_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:32 - Definition of MSSIMA_SESSION Bits
MSSIM_RC
MSSIMA_SESSION_Unmarshal(MSSIMA_SESSION* target, BYTE** buffer, INT32* size);

#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_SESSION_Marshal(MSSIMA_SESSION* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_SESSION_Marshal(source, buffer, size) \
    UINT8_Marshal((UINT8*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:33 - Definition of MSSIMA_LOCALITY Bits
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMA_LOCALITY_Unmarshal(MSSIMA_LOCALITY* target, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_LOCALITY_Unmarshal(target, buffer, size) \
    UINT8_Unmarshal((UINT8*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_LOCALITY_Marshal(MSSIMA_LOCALITY* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_LOCALITY_Marshal(source, buffer, size) \
    UINT8_Marshal((UINT8*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:34 - Definition of MSSIMA_PERMANENT Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_PERMANENT_Marshal(MSSIMA_PERMANENT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_PERMANENT_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:35 - Definition of MSSIMA_STARTUP_CLEAR Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_STARTUP_CLEAR_Marshal(MSSIMA_STARTUP_CLEAR* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_STARTUP_CLEAR_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:36 - Definition of MSSIMA_MEMORY Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_MEMORY_Marshal(MSSIMA_MEMORY* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_MEMORY_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:37 - Definition of MSSIMA_CC Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_CC_Marshal(MSSIMA_CC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_CC_Marshal(source, buffer, size) \
    MSSIM_CC_Marshal((MSSIM_CC*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:38 - Definition of MSSIMA_MODES Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_MODES_Marshal(MSSIMA_MODES* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_MODES_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:39 - Definition of MSSIMA_X509_KEY_USAGE Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_X509_KEY_USAGE_Marshal(MSSIMA_X509_KEY_USAGE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_X509_KEY_USAGE_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:40 - Definition of MSSIMA_ACT Bits
MSSIM_RC
MSSIMA_ACT_Unmarshal(MSSIMA_ACT* target, BYTE** buffer, INT32* size);

#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_ACT_Marshal(MSSIMA_ACT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_ACT_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:41 - Definition of MSSIMI_YES_NO Type
MSSIM_RC
MSSIMI_YES_NO_Unmarshal(MSSIMI_YES_NO* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_YES_NO_Marshal(MSSIMI_YES_NO* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_YES_NO_Marshal(source, buffer, size) \
    BYTE_Marshal((BYTE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:42 - Definition of MSSIMI_DH_OBJECT Type
MSSIM_RC
MSSIMI_DH_OBJECT_Unmarshal(
    MSSIMI_DH_OBJECT* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_OBJECT_Marshal(MSSIMI_DH_OBJECT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_DH_OBJECT_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:43 - Definition of MSSIMI_DH_PARENT Type
MSSIM_RC
MSSIMI_DH_PARENT_Unmarshal(
    MSSIMI_DH_PARENT* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_PARENT_Marshal(MSSIMI_DH_PARENT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_DH_PARENT_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:44 - Definition of MSSIMI_DH_PERSISTENT Type
MSSIM_RC
MSSIMI_DH_PERSISTENT_Unmarshal(MSSIMI_DH_PERSISTENT* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_PERSISTENT_Marshal(MSSIMI_DH_PERSISTENT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_DH_PERSISTENT_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:45 - Definition of MSSIMI_DH_ENTITY Type
MSSIM_RC
MSSIMI_DH_ENTITY_Unmarshal(
    MSSIMI_DH_ENTITY* target, BYTE** buffer, INT32* size, BOOL flag);

// Table 2:46 - Definition of MSSIMI_DH_PCR Type
MSSIM_RC
MSSIMI_DH_PCR_Unmarshal(MSSIMI_DH_PCR* target, BYTE** buffer, INT32* size, BOOL flag);

// Table 2:47 - Definition of MSSIMI_SH_AUTH_SESSION Type
MSSIM_RC
MSSIMI_SH_AUTH_SESSION_Unmarshal(
    MSSIMI_SH_AUTH_SESSION* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SH_AUTH_SESSION_Marshal(
    MSSIMI_SH_AUTH_SESSION* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_SH_AUTH_SESSION_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:48 - Definition of MSSIMI_SH_HMAC Type
MSSIM_RC
MSSIMI_SH_HMAC_Unmarshal(MSSIMI_SH_HMAC* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SH_HMAC_Marshal(MSSIMI_SH_HMAC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_SH_HMAC_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:49 - Definition of MSSIMI_SH_POLICY Type
MSSIM_RC
MSSIMI_SH_POLICY_Unmarshal(MSSIMI_SH_POLICY* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SH_POLICY_Marshal(MSSIMI_SH_POLICY* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_SH_POLICY_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:50 - Definition of MSSIMI_DH_CONTEXT Type
MSSIM_RC
MSSIMI_DH_CONTEXT_Unmarshal(MSSIMI_DH_CONTEXT* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_CONTEXT_Marshal(MSSIMI_DH_CONTEXT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_DH_CONTEXT_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:51 - Definition of MSSIMI_DH_SAVED Type
MSSIM_RC
MSSIMI_DH_SAVED_Unmarshal(MSSIMI_DH_SAVED* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_DH_SAVED_Marshal(MSSIMI_DH_SAVED* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_DH_SAVED_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:52 - Definition of MSSIMI_RH_HIERARCHY Type
MSSIM_RC
MSSIMI_RH_HIERARCHY_Unmarshal(
    MSSIMI_RH_HIERARCHY* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_HIERARCHY_Marshal(MSSIMI_RH_HIERARCHY* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_RH_HIERARCHY_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:53 - Definition of MSSIMI_RH_ENABLES Type
MSSIM_RC
MSSIMI_RH_ENABLES_Unmarshal(
    MSSIMI_RH_ENABLES* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_ENABLES_Marshal(MSSIMI_RH_ENABLES* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_RH_ENABLES_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:54 - Definition of MSSIMI_RH_HIERARCHY_AUTH Type
MSSIM_RC
MSSIMI_RH_HIERARCHY_AUTH_Unmarshal(
    MSSIMI_RH_HIERARCHY_AUTH* target, BYTE** buffer, INT32* size);

// Table 2:55 - Definition of MSSIMI_RH_HIERARCHY_POLICY Type
MSSIM_RC
MSSIMI_RH_HIERARCHY_POLICY_Unmarshal(
    MSSIMI_RH_HIERARCHY_POLICY* target, BYTE** buffer, INT32* size);

// Table 2:56 - Definition of MSSIMI_RH_PLATFORM Type
MSSIM_RC
MSSIMI_RH_PLATFORM_Unmarshal(MSSIMI_RH_PLATFORM* target, BYTE** buffer, INT32* size);

// Table 2:57 - Definition of MSSIMI_RH_OWNER Type
MSSIM_RC
MSSIMI_RH_OWNER_Unmarshal(MSSIMI_RH_OWNER* target, BYTE** buffer, INT32* size, BOOL flag);

// Table 2:58 - Definition of MSSIMI_RH_ENDORSEMENT Type
MSSIM_RC
MSSIMI_RH_ENDORSEMENT_Unmarshal(
    MSSIMI_RH_ENDORSEMENT* target, BYTE** buffer, INT32* size, BOOL flag);

// Table 2:59 - Definition of MSSIMI_RH_PROVISION Type
MSSIM_RC
MSSIMI_RH_PROVISION_Unmarshal(MSSIMI_RH_PROVISION* target, BYTE** buffer, INT32* size);

// Table 2:60 - Definition of MSSIMI_RH_CLEAR Type
MSSIM_RC
MSSIMI_RH_CLEAR_Unmarshal(MSSIMI_RH_CLEAR* target, BYTE** buffer, INT32* size);

// Table 2:61 - Definition of MSSIMI_RH_NV_AUTH Type
MSSIM_RC
MSSIMI_RH_NV_AUTH_Unmarshal(MSSIMI_RH_NV_AUTH* target, BYTE** buffer, INT32* size);

// Table 2:62 - Definition of MSSIMI_RH_LOCKOUT Type
MSSIM_RC
MSSIMI_RH_LOCKOUT_Unmarshal(MSSIMI_RH_LOCKOUT* target, BYTE** buffer, INT32* size);

// Table 2:63 - Definition of MSSIMI_RH_NV_INDEX Type
MSSIM_RC
MSSIMI_RH_NV_INDEX_Unmarshal(MSSIMI_RH_NV_INDEX* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_NV_INDEX_Marshal(MSSIMI_RH_NV_INDEX* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_RH_NV_INDEX_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:64 - Definition of MSSIMI_RH_AC Type
MSSIM_RC
MSSIMI_RH_AC_Unmarshal(MSSIMI_RH_AC* target, BYTE** buffer, INT32* size);

// Table 2:65 - Definition of MSSIMI_RH_ACT Type
MSSIM_RC
MSSIMI_RH_ACT_Unmarshal(MSSIMI_RH_ACT* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RH_ACT_Marshal(MSSIMI_RH_ACT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_RH_ACT_Marshal(source, buffer, size) \
    MSSIM_HANDLE_Marshal((MSSIM_HANDLE*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:66 - Definition of MSSIMI_ALG_HASH Type
MSSIM_RC
MSSIMI_ALG_HASH_Unmarshal(MSSIMI_ALG_HASH* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_HASH_Marshal(MSSIMI_ALG_HASH* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_HASH_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:67 - Definition of MSSIMI_ALG_ASYM Type
MSSIM_RC
MSSIMI_ALG_ASYM_Unmarshal(MSSIMI_ALG_ASYM* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_ASYM_Marshal(MSSIMI_ALG_ASYM* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_ASYM_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:68 - Definition of MSSIMI_ALG_SYM Type
MSSIM_RC
MSSIMI_ALG_SYM_Unmarshal(MSSIMI_ALG_SYM* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SYM_Marshal(MSSIMI_ALG_SYM* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_SYM_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:69 - Definition of MSSIMI_ALG_SYM_OBJECT Type
MSSIM_RC
MSSIMI_ALG_SYM_OBJECT_Unmarshal(
    MSSIMI_ALG_SYM_OBJECT* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SYM_OBJECT_Marshal(MSSIMI_ALG_SYM_OBJECT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_SYM_OBJECT_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:70 - Definition of MSSIMI_ALG_SYM_MODE Type
MSSIM_RC
MSSIMI_ALG_SYM_MODE_Unmarshal(
    MSSIMI_ALG_SYM_MODE* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SYM_MODE_Marshal(MSSIMI_ALG_SYM_MODE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_SYM_MODE_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:71 - Definition of MSSIMI_ALG_KDF Type
MSSIM_RC
MSSIMI_ALG_KDF_Unmarshal(MSSIMI_ALG_KDF* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_KDF_Marshal(MSSIMI_ALG_KDF* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_KDF_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:72 - Definition of MSSIMI_ALG_SIG_SCHEME Type
MSSIM_RC
MSSIMI_ALG_SIG_SCHEME_Unmarshal(
    MSSIMI_ALG_SIG_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_SIG_SCHEME_Marshal(MSSIMI_ALG_SIG_SCHEME* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_SIG_SCHEME_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:73 - Definition of MSSIMI_ECC_KEY_EXCHANGE Type
#if ALG_ECC
MSSIM_RC
MSSIMI_ECC_KEY_EXCHANGE_Unmarshal(
    MSSIMI_ECC_KEY_EXCHANGE* target, BYTE** buffer, INT32* size, BOOL flag);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ECC_KEY_EXCHANGE_Marshal(
    MSSIMI_ECC_KEY_EXCHANGE* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_ECC_KEY_EXCHANGE_Marshal(source, buffer, size) \
      MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:74 - Definition of MSSIMI_ST_COMMAND_TAG Type
MSSIM_RC
MSSIMI_ST_COMMAND_TAG_Unmarshal(
    MSSIMI_ST_COMMAND_TAG* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ST_COMMAND_TAG_Marshal(MSSIMI_ST_COMMAND_TAG* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ST_COMMAND_TAG_Marshal(source, buffer, size) \
    MSSIM_ST_Marshal((MSSIM_ST*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:75 - Definition of MSSIMI_ALG_MAC_SCHEME Type
MSSIM_RC
MSSIMI_ALG_MAC_SCHEME_Unmarshal(
    MSSIMI_ALG_MAC_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_MAC_SCHEME_Marshal(MSSIMI_ALG_MAC_SCHEME* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_MAC_SCHEME_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:76 - Definition of MSSIMI_ALG_CIPHER_MODE Type
MSSIM_RC
MSSIMI_ALG_CIPHER_MODE_Unmarshal(
    MSSIMI_ALG_CIPHER_MODE* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_CIPHER_MODE_Marshal(
    MSSIMI_ALG_CIPHER_MODE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_CIPHER_MODE_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:77 - Definition of MSSIMS_EMPTY Structure
MSSIM_RC
MSSIMS_EMPTY_Unmarshal(MSSIMS_EMPTY* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_EMPTY_Marshal(MSSIMS_EMPTY* source, BYTE** buffer, INT32* size);

// Table 2:78 - Definition of MSSIMS_ALGORITHM_DESCRIPTION Structure
UINT16
MSSIMS_ALGORITHM_DESCRIPTION_Marshal(
    MSSIMS_ALGORITHM_DESCRIPTION* source, BYTE** buffer, INT32* size);

// Table 2:79 - Definition of MSSIMU_HA Union
MSSIM_RC
MSSIMU_HA_Unmarshal(MSSIMU_HA* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_HA_Marshal(MSSIMU_HA* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:80 - Definition of MSSIMT_HA Structure
MSSIM_RC
MSSIMT_HA_Unmarshal(MSSIMT_HA* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_HA_Marshal(MSSIMT_HA* source, BYTE** buffer, INT32* size);

// Table 2:81 - Definition of MSSIM2B_DIGEST Structure
MSSIM_RC
MSSIM2B_DIGEST_Unmarshal(MSSIM2B_DIGEST* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_DIGEST_Marshal(MSSIM2B_DIGEST* source, BYTE** buffer, INT32* size);

// Table 2:82 - Definition of MSSIM2B_DATA Structure
MSSIM_RC
MSSIM2B_DATA_Unmarshal(MSSIM2B_DATA* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_DATA_Marshal(MSSIM2B_DATA* source, BYTE** buffer, INT32* size);

// Table 2:83 - Definition of Types for MSSIM2B_NONCE
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM2B_NONCE_Unmarshal(MSSIM2B_NONCE* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM2B_NONCE_Unmarshal(target, buffer, size) \
    MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM2B_NONCE_Marshal(MSSIM2B_NONCE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM2B_NONCE_Marshal(source, buffer, size) \
    MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:84 - Definition of Types for MSSIM2B_AUTH
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM2B_AUTH_Unmarshal(MSSIM2B_AUTH* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM2B_AUTH_Unmarshal(target, buffer, size) \
    MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM2B_AUTH_Marshal(MSSIM2B_AUTH* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM2B_AUTH_Marshal(source, buffer, size) \
    MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:85 - Definition of Types for MSSIM2B_OPERAND
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIM2B_OPERAND_Unmarshal(MSSIM2B_OPERAND* target, BYTE** buffer, INT32* size);
#else
#  define MSSIM2B_OPERAND_Unmarshal(target, buffer, size) \
    MSSIM2B_DIGEST_Unmarshal((MSSIM2B_DIGEST*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM2B_OPERAND_Marshal(MSSIM2B_OPERAND* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM2B_OPERAND_Marshal(source, buffer, size) \
    MSSIM2B_DIGEST_Marshal((MSSIM2B_DIGEST*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:86 - Definition of MSSIM2B_EVENT Structure
MSSIM_RC
MSSIM2B_EVENT_Unmarshal(MSSIM2B_EVENT* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_EVENT_Marshal(MSSIM2B_EVENT* source, BYTE** buffer, INT32* size);

// Table 2:87 - Definition of MSSIM2B_MAX_BUFFER Structure
MSSIM_RC
MSSIM2B_MAX_BUFFER_Unmarshal(MSSIM2B_MAX_BUFFER* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_MAX_BUFFER_Marshal(MSSIM2B_MAX_BUFFER* source, BYTE** buffer, INT32* size);

// Table 2:88 - Definition of MSSIM2B_MAX_NV_BUFFER Structure
MSSIM_RC
MSSIM2B_MAX_NV_BUFFER_Unmarshal(
    MSSIM2B_MAX_NV_BUFFER* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_MAX_NV_BUFFER_Marshal(MSSIM2B_MAX_NV_BUFFER* source, BYTE** buffer, INT32* size);

// Table 2:89 - Definition of MSSIM2B_TIMEOUT Structure
MSSIM_RC
MSSIM2B_TIMEOUT_Unmarshal(MSSIM2B_TIMEOUT* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_TIMEOUT_Marshal(MSSIM2B_TIMEOUT* source, BYTE** buffer, INT32* size);

// Table 2:90 - Definition of MSSIM2B_IV Structure
MSSIM_RC
MSSIM2B_IV_Unmarshal(MSSIM2B_IV* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_IV_Marshal(MSSIM2B_IV* source, BYTE** buffer, INT32* size);

// Table 2:91 - Definition of MSSIMU_NAME Union
// Table 2:92 - Definition of MSSIM2B_NAME Structure
MSSIM_RC
MSSIM2B_NAME_Unmarshal(MSSIM2B_NAME* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_NAME_Marshal(MSSIM2B_NAME* source, BYTE** buffer, INT32* size);

// Table 2:93 - Definition of MSSIMS_PCR_SELECT Structure
MSSIM_RC
MSSIMS_PCR_SELECT_Unmarshal(MSSIMS_PCR_SELECT* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_PCR_SELECT_Marshal(MSSIMS_PCR_SELECT* source, BYTE** buffer, INT32* size);

// Table 2:94 - Definition of MSSIMS_PCR_SELECTION Structure
MSSIM_RC
MSSIMS_PCR_SELECTION_Unmarshal(MSSIMS_PCR_SELECTION* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_PCR_SELECTION_Marshal(MSSIMS_PCR_SELECTION* source, BYTE** buffer, INT32* size);

// Table 2:97 - Definition of MSSIMT_TK_CREATION Structure
MSSIM_RC
MSSIMT_TK_CREATION_Unmarshal(MSSIMT_TK_CREATION* target, BYTE** buffer, INT32* size);
UINT16
MSSIMT_TK_CREATION_Marshal(MSSIMT_TK_CREATION* source, BYTE** buffer, INT32* size);

// Table 2:98 - Definition of MSSIMT_TK_VERIFIED Structure
MSSIM_RC
MSSIMT_TK_VERIFIED_Unmarshal(MSSIMT_TK_VERIFIED* target, BYTE** buffer, INT32* size);
UINT16
MSSIMT_TK_VERIFIED_Marshal(MSSIMT_TK_VERIFIED* source, BYTE** buffer, INT32* size);

// Table 2:99 - Definition of MSSIMT_TK_AUTH Structure
MSSIM_RC
MSSIMT_TK_AUTH_Unmarshal(MSSIMT_TK_AUTH* target, BYTE** buffer, INT32* size);
UINT16
MSSIMT_TK_AUTH_Marshal(MSSIMT_TK_AUTH* source, BYTE** buffer, INT32* size);

// Table 2:100 - Definition of MSSIMT_TK_HASHCHECK Structure
MSSIM_RC
MSSIMT_TK_HASHCHECK_Unmarshal(MSSIMT_TK_HASHCHECK* target, BYTE** buffer, INT32* size);
UINT16
MSSIMT_TK_HASHCHECK_Marshal(MSSIMT_TK_HASHCHECK* source, BYTE** buffer, INT32* size);

// Table 2:101 - Definition of MSSIMS_ALG_PROPERTY Structure
UINT16
MSSIMS_ALG_PROPERTY_Marshal(MSSIMS_ALG_PROPERTY* source, BYTE** buffer, INT32* size);

// Table 2:102 - Definition of MSSIMS_TAGGED_PROPERTY Structure
UINT16
MSSIMS_TAGGED_PROPERTY_Marshal(
    MSSIMS_TAGGED_PROPERTY* source, BYTE** buffer, INT32* size);

// Table 2:103 - Definition of MSSIMS_TAGGED_PCR_SELECT Structure
UINT16
MSSIMS_TAGGED_PCR_SELECT_Marshal(
    MSSIMS_TAGGED_PCR_SELECT* source, BYTE** buffer, INT32* size);

// Table 2:104 - Definition of MSSIMS_TAGGED_POLICY Structure
UINT16
MSSIMS_TAGGED_POLICY_Marshal(MSSIMS_TAGGED_POLICY* source, BYTE** buffer, INT32* size);

// Table 2:105 - Definition of MSSIMS_ACT_DATA Structure
UINT16
MSSIMS_ACT_DATA_Marshal(MSSIMS_ACT_DATA* source, BYTE** buffer, INT32* size);

// Table 2:106 - Definition of MSSIML_CC Structure
MSSIM_RC
MSSIML_CC_Unmarshal(MSSIML_CC* target, BYTE** buffer, INT32* size);
UINT16
MSSIML_CC_Marshal(MSSIML_CC* source, BYTE** buffer, INT32* size);

// Table 2:107 - Definition of MSSIML_CCA Structure
UINT16
MSSIML_CCA_Marshal(MSSIML_CCA* source, BYTE** buffer, INT32* size);

// Table 2:108 - Definition of MSSIML_ALG Structure
MSSIM_RC
MSSIML_ALG_Unmarshal(MSSIML_ALG* target, BYTE** buffer, INT32* size);
UINT16
MSSIML_ALG_Marshal(MSSIML_ALG* source, BYTE** buffer, INT32* size);

// Table 2:109 - Definition of MSSIML_HANDLE Structure
UINT16
MSSIML_HANDLE_Marshal(MSSIML_HANDLE* source, BYTE** buffer, INT32* size);

// Table 2:110 - Definition of MSSIML_DIGEST Structure
MSSIM_RC
MSSIML_DIGEST_Unmarshal(MSSIML_DIGEST* target, BYTE** buffer, INT32* size);
UINT16
MSSIML_DIGEST_Marshal(MSSIML_DIGEST* source, BYTE** buffer, INT32* size);

// Table 2:111 - Definition of MSSIML_DIGEST_VALUES Structure
MSSIM_RC
MSSIML_DIGEST_VALUES_Unmarshal(MSSIML_DIGEST_VALUES* target, BYTE** buffer, INT32* size);
UINT16
MSSIML_DIGEST_VALUES_Marshal(MSSIML_DIGEST_VALUES* source, BYTE** buffer, INT32* size);

// Table 2:112 - Definition of MSSIML_PCR_SELECTION Structure
MSSIM_RC
MSSIML_PCR_SELECTION_Unmarshal(MSSIML_PCR_SELECTION* target, BYTE** buffer, INT32* size);
UINT16
MSSIML_PCR_SELECTION_Marshal(MSSIML_PCR_SELECTION* source, BYTE** buffer, INT32* size);

// Table 2:113 - Definition of MSSIML_ALG_PROPERTY Structure
UINT16
MSSIML_ALG_PROPERTY_Marshal(MSSIML_ALG_PROPERTY* source, BYTE** buffer, INT32* size);

// Table 2:114 - Definition of MSSIML_TAGGED_MSSIM_PROPERTY Structure
UINT16
MSSIML_TAGGED_MSSIM_PROPERTY_Marshal(
    MSSIML_TAGGED_MSSIM_PROPERTY* source, BYTE** buffer, INT32* size);

// Table 2:115 - Definition of MSSIML_TAGGED_PCR_PROPERTY Structure
UINT16
MSSIML_TAGGED_PCR_PROPERTY_Marshal(
    MSSIML_TAGGED_PCR_PROPERTY* source, BYTE** buffer, INT32* size);

// Table 2:116 - Definition of MSSIML_ECC_CURVE Structure
#if ALG_ECC
UINT16
MSSIML_ECC_CURVE_Marshal(MSSIML_ECC_CURVE* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:117 - Definition of MSSIML_TAGGED_POLICY Structure
UINT16
MSSIML_TAGGED_POLICY_Marshal(MSSIML_TAGGED_POLICY* source, BYTE** buffer, INT32* size);

// Table 2:118 - Definition of MSSIML_ACT_DATA Structure
UINT16
MSSIML_ACT_DATA_Marshal(MSSIML_ACT_DATA* source, BYTE** buffer, INT32* size);

// Table 2:119 - Definition of MSSIMU_CAPABILITIES Union
UINT16
MSSIMU_CAPABILITIES_Marshal(
    MSSIMU_CAPABILITIES* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:120 - Definition of MSSIMS_CAPABILITY_DATA Structure
UINT16
MSSIMS_CAPABILITY_DATA_Marshal(
    MSSIMS_CAPABILITY_DATA* source, BYTE** buffer, INT32* size);

// Table 2:121 - Definition of MSSIMS_CLOCK_INFO Structure
MSSIM_RC
MSSIMS_CLOCK_INFO_Unmarshal(MSSIMS_CLOCK_INFO* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_CLOCK_INFO_Marshal(MSSIMS_CLOCK_INFO* source, BYTE** buffer, INT32* size);

// Table 2:122 - Definition of MSSIMS_TIME_INFO Structure
MSSIM_RC
MSSIMS_TIME_INFO_Unmarshal(MSSIMS_TIME_INFO* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_TIME_INFO_Marshal(MSSIMS_TIME_INFO* source, BYTE** buffer, INT32* size);

// Table 2:123 - Definition of MSSIMS_TIME_ATTEST_INFO Structure
UINT16
MSSIMS_TIME_ATTEST_INFO_Marshal(
    MSSIMS_TIME_ATTEST_INFO* source, BYTE** buffer, INT32* size);

// Table 2:124 - Definition of MSSIMS_CERTIFY_INFO Structure
UINT16
MSSIMS_CERTIFY_INFO_Marshal(MSSIMS_CERTIFY_INFO* source, BYTE** buffer, INT32* size);

// Table 2:125 - Definition of MSSIMS_QUOTE_INFO Structure
UINT16
MSSIMS_QUOTE_INFO_Marshal(MSSIMS_QUOTE_INFO* source, BYTE** buffer, INT32* size);

// Table 2:126 - Definition of MSSIMS_COMMAND_AUDIT_INFO Structure
UINT16
MSSIMS_COMMAND_AUDIT_INFO_Marshal(
    MSSIMS_COMMAND_AUDIT_INFO* source, BYTE** buffer, INT32* size);

// Table 2:127 - Definition of MSSIMS_SESSION_AUDIT_INFO Structure
UINT16
MSSIMS_SESSION_AUDIT_INFO_Marshal(
    MSSIMS_SESSION_AUDIT_INFO* source, BYTE** buffer, INT32* size);

// Table 2:128 - Definition of MSSIMS_CREATION_INFO Structure
UINT16
MSSIMS_CREATION_INFO_Marshal(MSSIMS_CREATION_INFO* source, BYTE** buffer, INT32* size);

// Table 2:129 - Definition of MSSIMS_NV_CERTIFY_INFO Structure
UINT16
MSSIMS_NV_CERTIFY_INFO_Marshal(
    MSSIMS_NV_CERTIFY_INFO* source, BYTE** buffer, INT32* size);

// Table 2:130 - Definition of MSSIMS_NV_DIGEST_CERTIFY_INFO Structure
UINT16
MSSIMS_NV_DIGEST_CERTIFY_INFO_Marshal(
    MSSIMS_NV_DIGEST_CERTIFY_INFO* source, BYTE** buffer, INT32* size);

// Table 2:131 - Definition of MSSIMI_ST_ATTEST Type
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ST_ATTEST_Marshal(MSSIMI_ST_ATTEST* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ST_ATTEST_Marshal(source, buffer, size) \
    MSSIM_ST_Marshal((MSSIM_ST*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:132 - Definition of MSSIMU_ATTEST Union
UINT16
MSSIMU_ATTEST_Marshal(MSSIMU_ATTEST* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:133 - Definition of MSSIMS_ATTEST Structure
UINT16
MSSIMS_ATTEST_Marshal(MSSIMS_ATTEST* source, BYTE** buffer, INT32* size);

// Table 2:134 - Definition of MSSIM2B_ATTEST Structure
UINT16
MSSIM2B_ATTEST_Marshal(MSSIM2B_ATTEST* source, BYTE** buffer, INT32* size);

// Table 2:135 - Definition of MSSIMS_AUTH_COMMAND Structure
MSSIM_RC
MSSIMS_AUTH_COMMAND_Unmarshal(MSSIMS_AUTH_COMMAND* target, BYTE** buffer, INT32* size);

// Table 2:136 - Definition of MSSIMS_AUTH_RESPONSE Structure
UINT16
MSSIMS_AUTH_RESPONSE_Marshal(MSSIMS_AUTH_RESPONSE* source, BYTE** buffer, INT32* size);

// Table 2:137 - Definition of MSSIMI_TDES_KEY_BITS Type
#if ALG_TDES
MSSIM_RC
MSSIMI_TDES_KEY_BITS_Unmarshal(MSSIMI_TDES_KEY_BITS* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_TDES_KEY_BITS_Marshal(MSSIMI_TDES_KEY_BITS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_TDES_KEY_BITS_Marshal(source, buffer, size) \
      MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_TDES

// Table 2:137 - Definition of MSSIMI_AES_KEY_BITS Type
#if ALG_AES
MSSIM_RC
MSSIMI_AES_KEY_BITS_Unmarshal(MSSIMI_AES_KEY_BITS* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_AES_KEY_BITS_Marshal(MSSIMI_AES_KEY_BITS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_AES_KEY_BITS_Marshal(source, buffer, size) \
      MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_AES

// Table 2:137 - Definition of MSSIMI_SM4_KEY_BITS Type
#if ALG_SM4
MSSIM_RC
MSSIMI_SM4_KEY_BITS_Unmarshal(MSSIMI_SM4_KEY_BITS* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_SM4_KEY_BITS_Marshal(MSSIMI_SM4_KEY_BITS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_SM4_KEY_BITS_Marshal(source, buffer, size) \
      MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_SM4

// Table 2:137 - Definition of MSSIMI_CAMELLIA_KEY_BITS Type
#if ALG_CAMELLIA
MSSIM_RC
MSSIMI_CAMELLIA_KEY_BITS_Unmarshal(
    MSSIMI_CAMELLIA_KEY_BITS* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_CAMELLIA_KEY_BITS_Marshal(
    MSSIMI_CAMELLIA_KEY_BITS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_CAMELLIA_KEY_BITS_Marshal(source, buffer, size) \
      MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_CAMELLIA

// Table 2:138 - Definition of MSSIMU_SYM_KEY_BITS Union
MSSIM_RC
MSSIMU_SYM_KEY_BITS_Unmarshal(
    MSSIMU_SYM_KEY_BITS* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_SYM_KEY_BITS_Marshal(
    MSSIMU_SYM_KEY_BITS* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:139 - Definition of MSSIMU_SYM_MODE Union
MSSIM_RC
MSSIMU_SYM_MODE_Unmarshal(
    MSSIMU_SYM_MODE* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_SYM_MODE_Marshal(
    MSSIMU_SYM_MODE* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:141 - Definition of MSSIMT_SYM_DEF Structure
MSSIM_RC
MSSIMT_SYM_DEF_Unmarshal(MSSIMT_SYM_DEF* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_SYM_DEF_Marshal(MSSIMT_SYM_DEF* source, BYTE** buffer, INT32* size);

// Table 2:142 - Definition of MSSIMT_SYM_DEF_OBJECT Structure
MSSIM_RC
MSSIMT_SYM_DEF_OBJECT_Unmarshal(
    MSSIMT_SYM_DEF_OBJECT* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_SYM_DEF_OBJECT_Marshal(MSSIMT_SYM_DEF_OBJECT* source, BYTE** buffer, INT32* size);

// Table 2:143 - Definition of MSSIM2B_SYM_KEY Structure
MSSIM_RC
MSSIM2B_SYM_KEY_Unmarshal(MSSIM2B_SYM_KEY* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_SYM_KEY_Marshal(MSSIM2B_SYM_KEY* source, BYTE** buffer, INT32* size);

// Table 2:144 - Definition of MSSIMS_SYMCIPHER_PARMS Structure
MSSIM_RC
MSSIMS_SYMCIPHER_PARMS_Unmarshal(
    MSSIMS_SYMCIPHER_PARMS* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_SYMCIPHER_PARMS_Marshal(
    MSSIMS_SYMCIPHER_PARMS* source, BYTE** buffer, INT32* size);

// Table 2:145 - Definition of MSSIM2B_LABEL Structure
MSSIM_RC
MSSIM2B_LABEL_Unmarshal(MSSIM2B_LABEL* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_LABEL_Marshal(MSSIM2B_LABEL* source, BYTE** buffer, INT32* size);

// Table 2:146 - Definition of MSSIMS_DERIVE Structure
MSSIM_RC
MSSIMS_DERIVE_Unmarshal(MSSIMS_DERIVE* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_DERIVE_Marshal(MSSIMS_DERIVE* source, BYTE** buffer, INT32* size);

// Table 2:147 - Definition of MSSIM2B_DERIVE Structure
MSSIM_RC
MSSIM2B_DERIVE_Unmarshal(MSSIM2B_DERIVE* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_DERIVE_Marshal(MSSIM2B_DERIVE* source, BYTE** buffer, INT32* size);

// Table 2:148 - Definition of MSSIMU_SENSITIVE_CREATE Union
// Table 2:149 - Definition of MSSIM2B_SENSITIVE_DATA Structure
MSSIM_RC
MSSIM2B_SENSITIVE_DATA_Unmarshal(
    MSSIM2B_SENSITIVE_DATA* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_SENSITIVE_DATA_Marshal(
    MSSIM2B_SENSITIVE_DATA* source, BYTE** buffer, INT32* size);

// Table 2:150 - Definition of MSSIMS_SENSITIVE_CREATE Structure
MSSIM_RC
MSSIMS_SENSITIVE_CREATE_Unmarshal(
    MSSIMS_SENSITIVE_CREATE* target, BYTE** buffer, INT32* size);

// Table 2:151 - Definition of MSSIM2B_SENSITIVE_CREATE Structure
MSSIM_RC
MSSIM2B_SENSITIVE_CREATE_Unmarshal(
    MSSIM2B_SENSITIVE_CREATE* target, BYTE** buffer, INT32* size);

// Table 2:152 - Definition of MSSIMS_SCHEME_HASH Structure
MSSIM_RC
MSSIMS_SCHEME_HASH_Unmarshal(MSSIMS_SCHEME_HASH* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_SCHEME_HASH_Marshal(MSSIMS_SCHEME_HASH* source, BYTE** buffer, INT32* size);

// Table 2:153 - Definition of MSSIMS_SCHEME_ECDAA Structure
#if ALG_ECC
MSSIM_RC
MSSIMS_SCHEME_ECDAA_Unmarshal(MSSIMS_SCHEME_ECDAA* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_SCHEME_ECDAA_Marshal(MSSIMS_SCHEME_ECDAA* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:154 - Definition of MSSIMI_ALG_KEYEDHASH_SCHEME Type
MSSIM_RC
MSSIMI_ALG_KEYEDHASH_SCHEME_Unmarshal(
    MSSIMI_ALG_KEYEDHASH_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_KEYEDHASH_SCHEME_Marshal(
    MSSIMI_ALG_KEYEDHASH_SCHEME* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_KEYEDHASH_SCHEME_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:155 - Definition of Types for HMAC_SIG_SCHEME
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SCHEME_HMAC_Unmarshal(MSSIMS_SCHEME_HMAC* target, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_SCHEME_HMAC_Unmarshal(target, buffer, size) \
    MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SCHEME_HMAC_Marshal(MSSIMS_SCHEME_HMAC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_SCHEME_HMAC_Marshal(source, buffer, size) \
    MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:156 - Definition of MSSIMS_SCHEME_XOR Structure
MSSIM_RC
MSSIMS_SCHEME_XOR_Unmarshal(MSSIMS_SCHEME_XOR* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_SCHEME_XOR_Marshal(MSSIMS_SCHEME_XOR* source, BYTE** buffer, INT32* size);

// Table 2:157 - Definition of MSSIMU_SCHEME_KEYEDHASH Union
MSSIM_RC
MSSIMU_SCHEME_KEYEDHASH_Unmarshal(
    MSSIMU_SCHEME_KEYEDHASH* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_SCHEME_KEYEDHASH_Marshal(
    MSSIMU_SCHEME_KEYEDHASH* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:158 - Definition of MSSIMT_KEYEDHASH_SCHEME Structure
MSSIM_RC
MSSIMT_KEYEDHASH_SCHEME_Unmarshal(
    MSSIMT_KEYEDHASH_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_KEYEDHASH_SCHEME_Marshal(
    MSSIMT_KEYEDHASH_SCHEME* source, BYTE** buffer, INT32* size);

// Table 2:159 - Definition of Types for RSA Signature Schemes
#if ALG_RSA
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_RSASSA_Unmarshal(
    MSSIMS_SIG_SCHEME_RSASSA* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_RSASSA_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIG_SCHEME_RSASSA_Marshal(
    MSSIMS_SIG_SCHEME_RSASSA* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_RSASSA_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_RSAPSS_Unmarshal(
    MSSIMS_SIG_SCHEME_RSAPSS* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_RSAPSS_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIG_SCHEME_RSAPSS_Marshal(
    MSSIMS_SIG_SCHEME_RSAPSS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_RSAPSS_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_RSA

// Table 2:160 - Definition of Types for ECC Signature Schemes
#if ALG_ECC
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_ECDSA_Unmarshal(
    MSSIMS_SIG_SCHEME_ECDSA* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_ECDSA_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIG_SCHEME_ECDSA_Marshal(
    MSSIMS_SIG_SCHEME_ECDSA* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_ECDSA_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_SM2_Unmarshal(
    MSSIMS_SIG_SCHEME_SM2* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_SM2_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIG_SCHEME_SM2_Marshal(MSSIMS_SIG_SCHEME_SM2* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_SM2_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_ECSCHNORR_Unmarshal(
    MSSIMS_SIG_SCHEME_ECSCHNORR* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_ECSCHNORR_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIG_SCHEME_ECSCHNORR_Marshal(
    MSSIMS_SIG_SCHEME_ECSCHNORR* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_ECSCHNORR_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIG_SCHEME_ECDAA_Unmarshal(
    MSSIMS_SIG_SCHEME_ECDAA* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_ECDAA_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_ECDAA_Unmarshal((MSSIMS_SCHEME_ECDAA*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIG_SCHEME_ECDAA_Marshal(
    MSSIMS_SIG_SCHEME_ECDAA* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIG_SCHEME_ECDAA_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_ECDAA_Marshal((MSSIMS_SCHEME_ECDAA*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:161 - Definition of MSSIMU_SIG_SCHEME Union
MSSIM_RC
MSSIMU_SIG_SCHEME_Unmarshal(
    MSSIMU_SIG_SCHEME* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_SIG_SCHEME_Marshal(
    MSSIMU_SIG_SCHEME* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:162 - Definition of MSSIMT_SIG_SCHEME Structure
MSSIM_RC
MSSIMT_SIG_SCHEME_Unmarshal(
    MSSIMT_SIG_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_SIG_SCHEME_Marshal(MSSIMT_SIG_SCHEME* source, BYTE** buffer, INT32* size);

// Table 2:163 - Definition of Types for Encryption Schemes
#if ALG_RSA
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_ENC_SCHEME_OAEP_Unmarshal(
    MSSIMS_ENC_SCHEME_OAEP* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_ENC_SCHEME_OAEP_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_ENC_SCHEME_OAEP_Marshal(
    MSSIMS_ENC_SCHEME_OAEP* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_ENC_SCHEME_OAEP_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_ENC_SCHEME_RSAES_Unmarshal(
    MSSIMS_ENC_SCHEME_RSAES* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_ENC_SCHEME_RSAES_Unmarshal(target, buffer, size) \
      MSSIMS_EMPTY_Unmarshal((MSSIMS_EMPTY*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_ENC_SCHEME_RSAES_Marshal(
    MSSIMS_ENC_SCHEME_RSAES* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_ENC_SCHEME_RSAES_Marshal(source, buffer, size) \
      MSSIMS_EMPTY_Marshal((MSSIMS_EMPTY*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_RSA

// Table 2:164 - Definition of Types for ECC Key Exchange
#if ALG_ECC
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KEY_SCHEME_ECDH_Unmarshal(
    MSSIMS_KEY_SCHEME_ECDH* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_KEY_SCHEME_ECDH_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_KEY_SCHEME_ECDH_Marshal(
    MSSIMS_KEY_SCHEME_ECDH* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_KEY_SCHEME_ECDH_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KEY_SCHEME_ECMQV_Unmarshal(
    MSSIMS_KEY_SCHEME_ECMQV* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_KEY_SCHEME_ECMQV_Unmarshal(target, buffer, size) \
      MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_KEY_SCHEME_ECMQV_Marshal(
    MSSIMS_KEY_SCHEME_ECMQV* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_KEY_SCHEME_ECMQV_Marshal(source, buffer, size) \
      MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:165 - Definition of Types for KDF Schemes
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KDF_SCHEME_MGF1_Unmarshal(
    MSSIMS_KDF_SCHEME_MGF1* target, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_MGF1_Unmarshal(target, buffer, size) \
    MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_KDF_SCHEME_MGF1_Marshal(
    MSSIMS_KDF_SCHEME_MGF1* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_MGF1_Marshal(source, buffer, size) \
    MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Unmarshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_56A* target, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Unmarshal(target, buffer, size) \
    MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Marshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_56A* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_KDF1_SP800_56A_Marshal(source, buffer, size) \
    MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KDF_SCHEME_KDF2_Unmarshal(
    MSSIMS_KDF_SCHEME_KDF2* target, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_KDF2_Unmarshal(target, buffer, size) \
    MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_KDF_SCHEME_KDF2_Marshal(
    MSSIMS_KDF_SCHEME_KDF2* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_KDF2_Marshal(source, buffer, size) \
    MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_KDF_SCHEME_KDF1_SP800_108_Unmarshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_108* target, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_KDF1_SP800_108_Unmarshal(target, buffer, size) \
    MSSIMS_SCHEME_HASH_Unmarshal((MSSIMS_SCHEME_HASH*)(target), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_KDF_SCHEME_KDF1_SP800_108_Marshal(
    MSSIMS_KDF_SCHEME_KDF1_SP800_108* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMS_KDF_SCHEME_KDF1_SP800_108_Marshal(source, buffer, size) \
    MSSIMS_SCHEME_HASH_Marshal((MSSIMS_SCHEME_HASH*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:166 - Definition of MSSIMU_KDF_SCHEME Union
MSSIM_RC
MSSIMU_KDF_SCHEME_Unmarshal(
    MSSIMU_KDF_SCHEME* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_KDF_SCHEME_Marshal(
    MSSIMU_KDF_SCHEME* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:167 - Definition of MSSIMT_KDF_SCHEME Structure
MSSIM_RC
MSSIMT_KDF_SCHEME_Unmarshal(
    MSSIMT_KDF_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_KDF_SCHEME_Marshal(MSSIMT_KDF_SCHEME* source, BYTE** buffer, INT32* size);

// Table 2:168 - Definition of MSSIMI_ALG_ASYM_SCHEME Type
MSSIM_RC
MSSIMI_ALG_ASYM_SCHEME_Unmarshal(
    MSSIMI_ALG_ASYM_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_ASYM_SCHEME_Marshal(
    MSSIMI_ALG_ASYM_SCHEME* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_ASYM_SCHEME_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:169 - Definition of MSSIMU_ASYM_SCHEME Union
MSSIM_RC
MSSIMU_ASYM_SCHEME_Unmarshal(
    MSSIMU_ASYM_SCHEME* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_ASYM_SCHEME_Marshal(
    MSSIMU_ASYM_SCHEME* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:170 - Definition of MSSIMT_ASYM_SCHEME Structure
// Table 2:171 - Definition of MSSIMI_ALG_RSA_SCHEME Type
#if ALG_RSA
MSSIM_RC
MSSIMI_ALG_RSA_SCHEME_Unmarshal(
    MSSIMI_ALG_RSA_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_RSA_SCHEME_Marshal(MSSIMI_ALG_RSA_SCHEME* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_ALG_RSA_SCHEME_Marshal(source, buffer, size) \
      MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_RSA

// Table 2:172 - Definition of MSSIMT_RSA_SCHEME Structure
#if ALG_RSA
MSSIM_RC
MSSIMT_RSA_SCHEME_Unmarshal(
    MSSIMT_RSA_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_RSA_SCHEME_Marshal(MSSIMT_RSA_SCHEME* source, BYTE** buffer, INT32* size);
#endif  // ALG_RSA

// Table 2:173 - Definition of MSSIMI_ALG_RSA_DECRYPT Type
#if ALG_RSA
MSSIM_RC
MSSIMI_ALG_RSA_DECRYPT_Unmarshal(
    MSSIMI_ALG_RSA_DECRYPT* target, BYTE** buffer, INT32* size, BOOL flag);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_RSA_DECRYPT_Marshal(
    MSSIMI_ALG_RSA_DECRYPT* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_ALG_RSA_DECRYPT_Marshal(source, buffer, size) \
      MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_RSA

// Table 2:174 - Definition of MSSIMT_RSA_DECRYPT Structure
#if ALG_RSA
MSSIM_RC
MSSIMT_RSA_DECRYPT_Unmarshal(
    MSSIMT_RSA_DECRYPT* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_RSA_DECRYPT_Marshal(MSSIMT_RSA_DECRYPT* source, BYTE** buffer, INT32* size);
#endif  // ALG_RSA

// Table 2:175 - Definition of MSSIM2B_PUBLIC_KEY_RSA Structure
#if ALG_RSA
MSSIM_RC
MSSIM2B_PUBLIC_KEY_RSA_Unmarshal(
    MSSIM2B_PUBLIC_KEY_RSA* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_PUBLIC_KEY_RSA_Marshal(
    MSSIM2B_PUBLIC_KEY_RSA* source, BYTE** buffer, INT32* size);
#endif  // ALG_RSA

// Table 2:176 - Definition of MSSIMI_RSA_KEY_BITS Type
#if ALG_RSA
MSSIM_RC
MSSIMI_RSA_KEY_BITS_Unmarshal(MSSIMI_RSA_KEY_BITS* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_RSA_KEY_BITS_Marshal(MSSIMI_RSA_KEY_BITS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_RSA_KEY_BITS_Marshal(source, buffer, size) \
      MSSIM_KEY_BITS_Marshal((MSSIM_KEY_BITS*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_RSA

// Table 2:177 - Definition of MSSIM2B_PRIVATE_KEY_RSA Structure
#if ALG_RSA
MSSIM_RC
MSSIM2B_PRIVATE_KEY_RSA_Unmarshal(
    MSSIM2B_PRIVATE_KEY_RSA* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_PRIVATE_KEY_RSA_Marshal(
    MSSIM2B_PRIVATE_KEY_RSA* source, BYTE** buffer, INT32* size);
#endif  // ALG_RSA

// Table 2:178 - Definition of MSSIM2B_ECC_PARAMETER Structure
MSSIM_RC
MSSIM2B_ECC_PARAMETER_Unmarshal(
    MSSIM2B_ECC_PARAMETER* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_ECC_PARAMETER_Marshal(MSSIM2B_ECC_PARAMETER* source, BYTE** buffer, INT32* size);

// Table 2:179 - Definition of MSSIMS_ECC_POINT Structure
#if ALG_ECC
MSSIM_RC
MSSIMS_ECC_POINT_Unmarshal(MSSIMS_ECC_POINT* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_ECC_POINT_Marshal(MSSIMS_ECC_POINT* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:180 - Definition of MSSIM2B_ECC_POINT Structure
#if ALG_ECC
MSSIM_RC
MSSIM2B_ECC_POINT_Unmarshal(MSSIM2B_ECC_POINT* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_ECC_POINT_Marshal(MSSIM2B_ECC_POINT* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:181 - Definition of MSSIMI_ALG_ECC_SCHEME Type
#if ALG_ECC
MSSIM_RC
MSSIMI_ALG_ECC_SCHEME_Unmarshal(
    MSSIMI_ALG_ECC_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_ECC_SCHEME_Marshal(MSSIMI_ALG_ECC_SCHEME* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_ALG_ECC_SCHEME_Marshal(source, buffer, size) \
      MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:182 - Definition of MSSIMI_ECC_CURVE Type
#if ALG_ECC
MSSIM_RC
MSSIMI_ECC_CURVE_Unmarshal(MSSIMI_ECC_CURVE* target, BYTE** buffer, INT32* size);
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ECC_CURVE_Marshal(MSSIMI_ECC_CURVE* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMI_ECC_CURVE_Marshal(source, buffer, size) \
      MSSIM_ECC_CURVE_Marshal((MSSIM_ECC_CURVE*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:183 - Definition of MSSIMT_ECC_SCHEME Structure
#if ALG_ECC
MSSIM_RC
MSSIMT_ECC_SCHEME_Unmarshal(
    MSSIMT_ECC_SCHEME* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_ECC_SCHEME_Marshal(MSSIMT_ECC_SCHEME* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:184 - Definition of MSSIMS_ALGORITHM_DETAIL_ECC Structure
#if ALG_ECC
UINT16
MSSIMS_ALGORITHM_DETAIL_ECC_Marshal(
    MSSIMS_ALGORITHM_DETAIL_ECC* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:185 - Definition of MSSIMS_SIGNATURE_RSA Structure
#if ALG_RSA
MSSIM_RC
MSSIMS_SIGNATURE_RSA_Unmarshal(MSSIMS_SIGNATURE_RSA* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_SIGNATURE_RSA_Marshal(MSSIMS_SIGNATURE_RSA* source, BYTE** buffer, INT32* size);
#endif  // ALG_RSA

// Table 2:186 - Definition of Types for Signature
#if ALG_RSA
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_RSASSA_Unmarshal(
    MSSIMS_SIGNATURE_RSASSA* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_RSASSA_Unmarshal(target, buffer, size) \
      MSSIMS_SIGNATURE_RSA_Unmarshal((MSSIMS_SIGNATURE_RSA*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIGNATURE_RSASSA_Marshal(
    MSSIMS_SIGNATURE_RSASSA* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_RSASSA_Marshal(source, buffer, size) \
      MSSIMS_SIGNATURE_RSA_Marshal((MSSIMS_SIGNATURE_RSA*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_RSAPSS_Unmarshal(
    MSSIMS_SIGNATURE_RSAPSS* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_RSAPSS_Unmarshal(target, buffer, size) \
      MSSIMS_SIGNATURE_RSA_Unmarshal((MSSIMS_SIGNATURE_RSA*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIGNATURE_RSAPSS_Marshal(
    MSSIMS_SIGNATURE_RSAPSS* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_RSAPSS_Marshal(source, buffer, size) \
      MSSIMS_SIGNATURE_RSA_Marshal((MSSIMS_SIGNATURE_RSA*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_RSA

// Table 2:187 - Definition of MSSIMS_SIGNATURE_ECC Structure
#if ALG_ECC
MSSIM_RC
MSSIMS_SIGNATURE_ECC_Unmarshal(MSSIMS_SIGNATURE_ECC* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_SIGNATURE_ECC_Marshal(MSSIMS_SIGNATURE_ECC* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:188 - Definition of Types for MSSIMS_SIGNATURE_ECC
#if ALG_ECC
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_ECDAA_Unmarshal(
    MSSIMS_SIGNATURE_ECDAA* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_ECDAA_Unmarshal(target, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIGNATURE_ECDAA_Marshal(
    MSSIMS_SIGNATURE_ECDAA* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_ECDAA_Marshal(source, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_ECDSA_Unmarshal(
    MSSIMS_SIGNATURE_ECDSA* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_ECDSA_Unmarshal(target, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIGNATURE_ECDSA_Marshal(
    MSSIMS_SIGNATURE_ECDSA* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_ECDSA_Marshal(source, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_SM2_Unmarshal(MSSIMS_SIGNATURE_SM2* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_SM2_Unmarshal(target, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIGNATURE_SM2_Marshal(MSSIMS_SIGNATURE_SM2* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_SM2_Marshal(source, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
MSSIM_RC
MSSIMS_SIGNATURE_ECSCHNORR_Unmarshal(
    MSSIMS_SIGNATURE_ECSCHNORR* target, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_ECSCHNORR_Unmarshal(target, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Unmarshal((MSSIMS_SIGNATURE_ECC*)(target), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#  if !USE_MARSHALING_DEFINES
UINT16
MSSIMS_SIGNATURE_ECSCHNORR_Marshal(
    MSSIMS_SIGNATURE_ECSCHNORR* source, BYTE** buffer, INT32* size);
#  else
#    define MSSIMS_SIGNATURE_ECSCHNORR_Marshal(source, buffer, size) \
      MSSIMS_SIGNATURE_ECC_Marshal((MSSIMS_SIGNATURE_ECC*)(source), (buffer), (size))
#  endif  // !USE_MARSHALING_DEFINES
#endif    // ALG_ECC

// Table 2:189 - Definition of MSSIMU_SIGNATURE Union
MSSIM_RC
MSSIMU_SIGNATURE_Unmarshal(
    MSSIMU_SIGNATURE* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_SIGNATURE_Marshal(
    MSSIMU_SIGNATURE* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:190 - Definition of MSSIMT_SIGNATURE Structure
MSSIM_RC
MSSIMT_SIGNATURE_Unmarshal(
    MSSIMT_SIGNATURE* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_SIGNATURE_Marshal(MSSIMT_SIGNATURE* source, BYTE** buffer, INT32* size);

// Table 2:191 - Definition of MSSIMU_ENCRYPTED_SECRET Union
MSSIM_RC
MSSIMU_ENCRYPTED_SECRET_Unmarshal(
    MSSIMU_ENCRYPTED_SECRET* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_ENCRYPTED_SECRET_Marshal(
    MSSIMU_ENCRYPTED_SECRET* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:192 - Definition of MSSIM2B_ENCRYPTED_SECRET Structure
MSSIM_RC
MSSIM2B_ENCRYPTED_SECRET_Unmarshal(
    MSSIM2B_ENCRYPTED_SECRET* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_ENCRYPTED_SECRET_Marshal(
    MSSIM2B_ENCRYPTED_SECRET* source, BYTE** buffer, INT32* size);

// Table 2:193 - Definition of MSSIMI_ALG_PUBLIC Type
MSSIM_RC
MSSIMI_ALG_PUBLIC_Unmarshal(MSSIMI_ALG_PUBLIC* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIMI_ALG_PUBLIC_Marshal(MSSIMI_ALG_PUBLIC* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMI_ALG_PUBLIC_Marshal(source, buffer, size) \
    MSSIM_ALG_ID_Marshal((MSSIM_ALG_ID*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:194 - Definition of MSSIMU_PUBLIC_ID Union
MSSIM_RC
MSSIMU_PUBLIC_ID_Unmarshal(
    MSSIMU_PUBLIC_ID* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_PUBLIC_ID_Marshal(
    MSSIMU_PUBLIC_ID* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:195 - Definition of MSSIMS_KEYEDHASH_PARMS Structure
MSSIM_RC
MSSIMS_KEYEDHASH_PARMS_Unmarshal(
    MSSIMS_KEYEDHASH_PARMS* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_KEYEDHASH_PARMS_Marshal(
    MSSIMS_KEYEDHASH_PARMS* source, BYTE** buffer, INT32* size);

// Table 2:196 - Definition of MSSIMS_ASYM_PARMS Structure
// Table 2:197 - Definition of MSSIMS_RSA_PARMS Structure
#if ALG_RSA
MSSIM_RC
MSSIMS_RSA_PARMS_Unmarshal(MSSIMS_RSA_PARMS* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_RSA_PARMS_Marshal(MSSIMS_RSA_PARMS* source, BYTE** buffer, INT32* size);
#endif  // ALG_RSA

// Table 2:198 - Definition of MSSIMS_ECC_PARMS Structure
#if ALG_ECC
MSSIM_RC
MSSIMS_ECC_PARMS_Unmarshal(MSSIMS_ECC_PARMS* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_ECC_PARMS_Marshal(MSSIMS_ECC_PARMS* source, BYTE** buffer, INT32* size);
#endif  // ALG_ECC

// Table 2:199 - Definition of MSSIMU_PUBLIC_PARMS Union
MSSIM_RC
MSSIMU_PUBLIC_PARMS_Unmarshal(
    MSSIMU_PUBLIC_PARMS* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_PUBLIC_PARMS_Marshal(
    MSSIMU_PUBLIC_PARMS* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:200 - Definition of MSSIMT_PUBLIC_PARMS Structure
MSSIM_RC
MSSIMT_PUBLIC_PARMS_Unmarshal(MSSIMT_PUBLIC_PARMS* target, BYTE** buffer, INT32* size);
UINT16
MSSIMT_PUBLIC_PARMS_Marshal(MSSIMT_PUBLIC_PARMS* source, BYTE** buffer, INT32* size);

// Table 2:201 - Definition of MSSIMT_PUBLIC Structure
MSSIM_RC
MSSIMT_PUBLIC_Unmarshal(MSSIMT_PUBLIC* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIMT_PUBLIC_Marshal(MSSIMT_PUBLIC* source, BYTE** buffer, INT32* size);

// Table 2:202 - Definition of MSSIM2B_PUBLIC Structure
MSSIM_RC
MSSIM2B_PUBLIC_Unmarshal(MSSIM2B_PUBLIC* target, BYTE** buffer, INT32* size, BOOL flag);
UINT16
MSSIM2B_PUBLIC_Marshal(MSSIM2B_PUBLIC* source, BYTE** buffer, INT32* size);

// Table 2:203 - Definition of MSSIM2B_TEMPLATE Structure
MSSIM_RC
MSSIM2B_TEMPLATE_Unmarshal(MSSIM2B_TEMPLATE* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_TEMPLATE_Marshal(MSSIM2B_TEMPLATE* source, BYTE** buffer, INT32* size);

// Table 2:204 - Definition of MSSIM2B_PRIVATE_VENDOR_SPECIFIC Structure
MSSIM_RC
MSSIM2B_PRIVATE_VENDOR_SPECIFIC_Unmarshal(
    MSSIM2B_PRIVATE_VENDOR_SPECIFIC* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_PRIVATE_VENDOR_SPECIFIC_Marshal(
    MSSIM2B_PRIVATE_VENDOR_SPECIFIC* source, BYTE** buffer, INT32* size);

// Table 2:205 - Definition of MSSIMU_SENSITIVE_COMPOSITE Union
MSSIM_RC
MSSIMU_SENSITIVE_COMPOSITE_Unmarshal(
    MSSIMU_SENSITIVE_COMPOSITE* target, BYTE** buffer, INT32* size, UINT32 selector);
UINT16
MSSIMU_SENSITIVE_COMPOSITE_Marshal(
    MSSIMU_SENSITIVE_COMPOSITE* source, BYTE** buffer, INT32* size, UINT32 selector);

// Table 2:206 - Definition of MSSIMT_SENSITIVE Structure
MSSIM_RC
MSSIMT_SENSITIVE_Unmarshal(MSSIMT_SENSITIVE* target, BYTE** buffer, INT32* size);
UINT16
MSSIMT_SENSITIVE_Marshal(MSSIMT_SENSITIVE* source, BYTE** buffer, INT32* size);

// Table 2:207 - Definition of MSSIM2B_SENSITIVE Structure
MSSIM_RC
MSSIM2B_SENSITIVE_Unmarshal(MSSIM2B_SENSITIVE* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_SENSITIVE_Marshal(MSSIM2B_SENSITIVE* source, BYTE** buffer, INT32* size);

// Table 2:208 - Definition of _MSSIMPRIVATE Structure
// Table 2:209 - Definition of MSSIM2B_PRIVATE Structure
MSSIM_RC
MSSIM2B_PRIVATE_Unmarshal(MSSIM2B_PRIVATE* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_PRIVATE_Marshal(MSSIM2B_PRIVATE* source, BYTE** buffer, INT32* size);

// Table 2:210 - Definition of MSSIMS_ID_OBJECT Structure
// Table 2:211 - Definition of MSSIM2B_ID_OBJECT Structure
MSSIM_RC
MSSIM2B_ID_OBJECT_Unmarshal(MSSIM2B_ID_OBJECT* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_ID_OBJECT_Marshal(MSSIM2B_ID_OBJECT* source, BYTE** buffer, INT32* size);

// Table 2:212 - Definition of MSSIM_NV_INDEX Bits
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_NV_INDEX_Marshal(MSSIM_NV_INDEX* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_NV_INDEX_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:213 - Definition of MSSIM_NT Constants
// Table 2:214 - Definition of MSSIMS_NV_PIN_COUNTER_PARAMETERS Structure
MSSIM_RC
MSSIMS_NV_PIN_COUNTER_PARAMETERS_Unmarshal(
    MSSIMS_NV_PIN_COUNTER_PARAMETERS* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_NV_PIN_COUNTER_PARAMETERS_Marshal(
    MSSIMS_NV_PIN_COUNTER_PARAMETERS* source, BYTE** buffer, INT32* size);

// Table 2:215 - Definition of MSSIMA_NV Bits
MSSIM_RC
MSSIMA_NV_Unmarshal(MSSIMA_NV* target, BYTE** buffer, INT32* size);

#if !USE_MARSHALING_DEFINES
UINT16
MSSIMA_NV_Marshal(MSSIMA_NV* source, BYTE** buffer, INT32* size);
#else
#  define MSSIMA_NV_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:216 - Definition of MSSIMS_NV_PUBLIC Structure
MSSIM_RC
MSSIMS_NV_PUBLIC_Unmarshal(MSSIMS_NV_PUBLIC* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_NV_PUBLIC_Marshal(MSSIMS_NV_PUBLIC* source, BYTE** buffer, INT32* size);

// Table 2:217 - Definition of MSSIM2B_NV_PUBLIC Structure
MSSIM_RC
MSSIM2B_NV_PUBLIC_Unmarshal(MSSIM2B_NV_PUBLIC* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_NV_PUBLIC_Marshal(MSSIM2B_NV_PUBLIC* source, BYTE** buffer, INT32* size);

// Table 2:218 - Definition of MSSIM2B_CONTEXT_SENSITIVE Structure
MSSIM_RC
MSSIM2B_CONTEXT_SENSITIVE_Unmarshal(
    MSSIM2B_CONTEXT_SENSITIVE* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_CONTEXT_SENSITIVE_Marshal(
    MSSIM2B_CONTEXT_SENSITIVE* source, BYTE** buffer, INT32* size);

// Table 2:219 - Definition of MSSIMS_CONTEXT_DATA Structure
MSSIM_RC
MSSIMS_CONTEXT_DATA_Unmarshal(MSSIMS_CONTEXT_DATA* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_CONTEXT_DATA_Marshal(MSSIMS_CONTEXT_DATA* source, BYTE** buffer, INT32* size);

// Table 2:220 - Definition of MSSIM2B_CONTEXT_DATA Structure
MSSIM_RC
MSSIM2B_CONTEXT_DATA_Unmarshal(MSSIM2B_CONTEXT_DATA* target, BYTE** buffer, INT32* size);
UINT16
MSSIM2B_CONTEXT_DATA_Marshal(MSSIM2B_CONTEXT_DATA* source, BYTE** buffer, INT32* size);

// Table 2:221 - Definition of MSSIMS_CONTEXT Structure
MSSIM_RC
MSSIMS_CONTEXT_Unmarshal(MSSIMS_CONTEXT* target, BYTE** buffer, INT32* size);
UINT16
MSSIMS_CONTEXT_Marshal(MSSIMS_CONTEXT* source, BYTE** buffer, INT32* size);

// Table 2:223 - Definition of MSSIMS_CREATION_DATA Structure
UINT16
MSSIMS_CREATION_DATA_Marshal(MSSIMS_CREATION_DATA* source, BYTE** buffer, INT32* size);

// Table 2:224 - Definition of MSSIM2B_CREATION_DATA Structure
UINT16
MSSIM2B_CREATION_DATA_Marshal(MSSIM2B_CREATION_DATA* source, BYTE** buffer, INT32* size);

// Table 2:225 - Definition of MSSIM_AT Constants
MSSIM_RC
MSSIM_AT_Unmarshal(MSSIM_AT* target, BYTE** buffer, INT32* size);
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_AT_Marshal(MSSIM_AT* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_AT_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:226 - Definition of MSSIM_AE Constants
#if !USE_MARSHALING_DEFINES
UINT16
MSSIM_AE_Marshal(MSSIM_AE* source, BYTE** buffer, INT32* size);
#else
#  define MSSIM_AE_Marshal(source, buffer, size) \
    UINT32_Marshal((UINT32*)(source), (buffer), (size))
#endif  // !USE_MARSHALING_DEFINES

// Table 2:227 - Definition of MSSIMS_AC_OUTPUT Structure
UINT16
MSSIMS_AC_OUTPUT_Marshal(MSSIMS_AC_OUTPUT* source, BYTE** buffer, INT32* size);

// Table 2:228 - Definition of MSSIML_AC_CAPABILITIES Structure
UINT16
MSSIML_AC_CAPABILITIES_Marshal(
    MSSIML_AC_CAPABILITIES* source, BYTE** buffer, INT32* size);

// Array Marshal/Unmarshal for BYTE
MSSIM_RC
BYTE_Array_Unmarshal(BYTE* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
BYTE_Array_Marshal(BYTE* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal/Unmarshal for MSSIM2B_DIGEST
MSSIM_RC
MSSIM2B_DIGEST_Array_Unmarshal(
    MSSIM2B_DIGEST* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
MSSIM2B_DIGEST_Array_Marshal(
    MSSIM2B_DIGEST* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMA_CC
UINT16
MSSIMA_CC_Array_Marshal(MSSIMA_CC* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMS_ACT_DATA
UINT16
MSSIMS_ACT_DATA_Array_Marshal(
    MSSIMS_ACT_DATA* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMS_AC_OUTPUT
UINT16
MSSIMS_AC_OUTPUT_Array_Marshal(
    MSSIMS_AC_OUTPUT* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMS_ALG_PROPERTY
UINT16
MSSIMS_ALG_PROPERTY_Array_Marshal(
    MSSIMS_ALG_PROPERTY* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal/Unmarshal for MSSIMS_PCR_SELECTION
MSSIM_RC
MSSIMS_PCR_SELECTION_Array_Unmarshal(
    MSSIMS_PCR_SELECTION* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
MSSIMS_PCR_SELECTION_Array_Marshal(
    MSSIMS_PCR_SELECTION* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMS_TAGGED_PCR_SELECT
UINT16
MSSIMS_TAGGED_PCR_SELECT_Array_Marshal(
    MSSIMS_TAGGED_PCR_SELECT* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMS_TAGGED_POLICY
UINT16
MSSIMS_TAGGED_POLICY_Array_Marshal(
    MSSIMS_TAGGED_POLICY* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal for MSSIMS_TAGGED_PROPERTY
UINT16
MSSIMS_TAGGED_PROPERTY_Array_Marshal(
    MSSIMS_TAGGED_PROPERTY* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal/Unmarshal for MSSIMT_HA
MSSIM_RC
MSSIMT_HA_Array_Unmarshal(
    MSSIMT_HA* target, BYTE** buffer, INT32* size, BOOL flag, INT32 count);
UINT16
MSSIMT_HA_Array_Marshal(MSSIMT_HA* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal/Unmarshal for MSSIM_ALG_ID
MSSIM_RC
MSSIM_ALG_ID_Array_Unmarshal(
    MSSIM_ALG_ID* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
MSSIM_ALG_ID_Array_Marshal(MSSIM_ALG_ID* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal/Unmarshal for MSSIM_CC
MSSIM_RC
MSSIM_CC_Array_Unmarshal(MSSIM_CC* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
MSSIM_CC_Array_Marshal(MSSIM_CC* source, BYTE** buffer, INT32* size, INT32 count);

// Array Marshal/Unmarshal for MSSIM_ECC_CURVE
#if ALG_ECC
MSSIM_RC
MSSIM_ECC_CURVE_Array_Unmarshal(
    MSSIM_ECC_CURVE* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
MSSIM_ECC_CURVE_Array_Marshal(
    MSSIM_ECC_CURVE* source, BYTE** buffer, INT32* size, INT32 count);
#endif  // ALG_ECC

// Array Marshal/Unmarshal for MSSIM_HANDLE
MSSIM_RC
MSSIM_HANDLE_Array_Unmarshal(
    MSSIM_HANDLE* target, BYTE** buffer, INT32* size, INT32 count);
UINT16
MSSIM_HANDLE_Array_Marshal(MSSIM_HANDLE* source, BYTE** buffer, INT32* size, INT32 count);
#endif  // _MARSHAL_FP_H_
