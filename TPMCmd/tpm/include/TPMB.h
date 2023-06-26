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
//
// This file contains extra MSSIM2B structures
//

#ifndef _MSSIMB_H
#define _MSSIMB_H

// MSSIM2B Types
typedef struct
{
    UINT16 size;
    BYTE   buffer[1];
} MSSIM2B, *P2B;
typedef const MSSIM2B* PC2B;

// This macro helps avoid having to type in the structure in order to create
// a new MSSIM2B type that is used in a function.
#define MSSIM2B_TYPE(name, bytes) \
  typedef union                 \
  {                             \
    struct                      \
    {                           \
      UINT16 size;              \
      BYTE   buffer[(bytes)];   \
    } t;                        \
    MSSIM2B b;                    \
  } MSSIM2B_##name

// This macro defines a MSSIM2B with a constant character value. This macro
// sets the size of the string to the size minus the terminating zero byte.
// This lets the user of the label add their terminating 0. This method
// is chosen so that existing code that provides a label will continue
// to work correctly.

// Macro to instance and initialize a MSSIM2B value
#define MSSIM2B_INIT(TYPE, name) MSSIM2B_##TYPE name = {sizeof(name.t.buffer), {0}}

#define MSSIM2B_BYTE_VALUE(bytes) MSSIM2B_TYPE(bytes##_BYTE_VALUE, bytes)

#endif
