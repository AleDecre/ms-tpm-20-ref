/* Microsoft Reference Implementation for TPM 2.0
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
 *  list of conditions and the following disclaimer in the documentation and/or other
 *  materials provided with the distribution.
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
// This file contains the function prototypes for the functions that need to be 
// present in the selected match library. For each function listed, there should 
// be a small stub function. That stub provides the interface between the TPM 
// code and the support library. In most cases, the stub function will only need 
// to do a format conversion between the TPM big number and the support library 
// big number. The TPM big number format was chosen to make this relatively 
// simple and fast.

#ifndef SUPPORT_LIBRARY_FUNCTION_PROTOTYPES_H
#define SUPPORT_LIBRARY_FUNCTION_PROTOTYPES_H

LIB_EXPORT int SupportLibInit(void);

// MathLibraryCompatibililtyCheck()
// This function is only used during development to make sure that the library
// that is being referenced is using the same size of data structures as the TPM.
void
MathLibraryCompatibilityCheck(
    void
    );

//** BnModMult()
// Does multiply and divide returning the remainder of the divide.
LIB_EXPORT BOOL
BnModMult(bigNum result, bigConst op1, bigConst op2, bigConst modulus);

//** BnMult()
// Multiplies two numbers
LIB_EXPORT BOOL BnMult(bigNum result, bigConst multiplicand, bigConst multiplier);

//** BnDiv()
// This function divides two bigNum values. The function always returns TRUE.
LIB_EXPORT BOOL BnDiv(bigNum quotient, bigNum remainder,
                      bigConst dividend, bigConst divisor);
//** BnMod()
#define BnMod(a, b)     BnDiv(NULL, (a), (a), (b))

#ifdef TPM_ALG_RSA
//** BnGcd()
// Get the greatest common divisor of two numbers
LIB_EXPORT BOOL BnGcd(bigNum gcd, bigConst number1, bigConst number2);

//**BnModExp()
// Do modular exponentiation using bigNum values.
LIB_EXPORT BOOL BnModExp(bigNum result, bigConst number,
                         bigConst exponent, bigConst modulus);
//** BnModInverse()
// Modular multiplicative inverse
LIB_EXPORT BOOL BnModInverse(bigNum result, bigConst number,
                             bigConst modulus);
#endif // TPM_ALG_RSA

#ifdef TPM_ALG_ECC

//** BnEccModMult()
// This function does a point multiply of the form R = [d]S
// return type: BOOL
//  FALSE       failure in operation; treat as result being point at infinity
LIB_EXPORT BOOL BnEccModMult(bigPoint R, pointConst S, bigConst d, bigCurve E);

//** BnEccModMult2()
// This function does a point multiply of the form R = [d]S + [u]Q
// return type: BOOL
//  FALSE       failure in operation; treat as result being point at infinity
LIB_EXPORT BOOL BnEccModMult2(bigPoint R, pointConst S, bigConst d,
                              pointConst Q, bigConst u, bigCurve E);

//** BnEccAdd()
// This function does a point add R = S + Q
// return type: BOOL
//  FALSE       failure in operation; treat as result being point at infinity
LIB_EXPORT BOOL BnEccAdd(bigPoint R, pointConst S, pointConst Q, bigCurve E);

//** BnCurveInitialize()
// This function is used to initialize the pointers of a bnCurve_t structure. The
// structure is a set of pointers to bigNum values. The curve-dependent values are
// set by a different function.
LIB_EXPORT bigCurve BnCurveInitialize(bigCurve E, TPM_ECC_CURVE curveId);

#endif // TPM_ALG_ECC

#endif 