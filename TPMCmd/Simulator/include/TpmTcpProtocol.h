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
//** Introduction

// MSSIM commands are communicated as uint8_t streams on a TCP connection.  The MSSIM
// command protocol is enveloped with the interface protocol described in this
// file. The command is indicated by a uint32 with one of the values below.  Most
// commands take no parameters return no MSSIM errors.  In these cases the MSSIM
// interface protocol acknowledges that command processing is completed by returning
// a uint32=0. The command MSSIM_SIGNAL_HASH_DATA takes a uint32-prepended variable
// length byte array and the interface protocol acknowledges command completion
// with a uint32=0. Most MSSIM commands are enveloped using the MSSIM_SEND_COMMAND
// interface command. The parameters are as indicated below.  The interface layer
// also appends a UIN32=0 to the MSSIM response for regularity.

//** Typedefs and Defines
#ifndef TCP_MSSIM_PROTOCOL_H
#define TCP_MSSIM_PROTOCOL_H

//** MSSIM Commands.
// All commands acknowledge processing by returning a uint32 == 0 except where noted
#define MSSIM_SIGNAL_POWER_ON      1
#define MSSIM_SIGNAL_POWER_OFF     2
#define MSSIM_SIGNAL_PHYS_PRES_ON  3
#define MSSIM_SIGNAL_PHYS_PRES_OFF 4
#define MSSIM_SIGNAL_HASH_START    5
#define MSSIM_SIGNAL_HASH_DATA     6
// {uint32_t BufferSize, uint8_t[BufferSize] Buffer}
#define MSSIM_SIGNAL_HASH_END 7
#define MSSIM_SEND_COMMAND    8
// {uint8_t Locality, uint32_t InBufferSize, uint8_t[InBufferSize] InBuffer} ->
//     {uint32_t OutBufferSize, uint8_t[OutBufferSize] OutBuffer}

#define MSSIM_SIGNAL_CANCEL_ON     9
#define MSSIM_SIGNAL_CANCEL_OFF    10
#define MSSIM_SIGNAL_NV_ON         11
#define MSSIM_SIGNAL_NV_OFF        12
#define MSSIM_SIGNAL_KEY_CACHE_ON  13
#define MSSIM_SIGNAL_KEY_CACHE_OFF 14

#define MSSIM_REMOTE_HANDSHAKE       15
#define MSSIM_SET_ALTERNATIVE_RESULT 16

#define MSSIM_SIGNAL_RESET   17
#define MSSIM_SIGNAL_RESTART 18

#define MSSIM_SESSION_END 20
#define MSSIM_STOP        21

#define MSSIM_GET_COMMAND_RESPONSE_SIZES 25

#define MSSIM_ACT_GET_SIGNALED 26

#define MSSIM_TEST_FAILURE_MODE 30

//** Enumerations and Structures
enum TpmEndPointInfo
{
    tpmPlatformAvailable = 0x01,
    tpmUsesTbs           = 0x02,
    tpmInRawMode         = 0x04,
    tpmSupportsPP        = 0x08
};

#ifdef _MSC_VER
#  pragma warning(push, 3)
#endif

// Existing RPC interface type definitions retained so that the implementation
// can be re-used
typedef struct in_buffer
{
    unsigned long  BufferSize;
    unsigned char* Buffer;
} _IN_BUFFER;

typedef unsigned char* _OUTPUT_BUFFER;

typedef struct out_buffer
{
    uint32_t       BufferSize;
    _OUTPUT_BUFFER Buffer;
} _OUT_BUFFER;

#ifdef _MSC_VER
#  pragma warning(pop)
#endif

#ifndef WIN32
typedef unsigned long DWORD;
typedef void*         LPVOID;
#endif

#endif
