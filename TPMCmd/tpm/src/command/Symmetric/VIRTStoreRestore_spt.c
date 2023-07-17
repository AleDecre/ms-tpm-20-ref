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
#include "Tpm.h"
#include "EncryptDecrypt_fp.h"
#include "VIRTStoreRestore_spt_fp.h"
#include "stdio.h"

#if CC_VIRT_StoreState || CC_VIRT_RestoreState

/*(See part 3 specification)
// symmetric encryption or decryption
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_KEY          is not a symmetric decryption key with both
//                          public and private portions loaded
//      MSSIM_RC_SIZE         'IvIn' size is incompatible with the block cipher mode;
//                          or 'inData' size is not an even multiple of the block
//                          size for CBC or ECB mode
//      MSSIM_RC_VALUE        'keyHandle' is restricted and the argument 'mode' does
//                          not match the key's mode
MSSIM_RC
StoreRestoreShared(MSSIMI_DH_OBJECT      keyHandleIn,
                     MSSIMI_YES_NO         decryptIn,
                     MSSIMI_ALG_SYM_MODE   modeIn,
                     MSSIM2B_IV*           ivIn,
                     MSSIM2B_MAX_BUFFER*   inData,
                     EncryptDecrypt_Out* out)
{
    OBJECT*    symKey;
    UINT16     keySize;
    UINT16     blockSize;
    BYTE*      key;
    MSSIM_ALG_ID alg;
    MSSIM_ALG_ID mode;
    MSSIM_RC     result;
    BOOL       OK = 1;
    // Input Validation
    symKey = HandleToObject(keyHandleIn);
    mode   = symKey->publicArea.parameters.symDetail.sym.mode.sym;

    // The input key should be a symmetric key
    if(symKey->publicArea.type != MSSIM_ALG_SYMCIPHER)
        return MSSIM_RCS_KEY + RC_EncryptDecrypt_keyHandle;
    // The key must be unrestricted and allow the selected operation
    // OK = !IS_ATTRIBUTE(symKey->publicArea.objectAttributes, MSSIMA_OBJECT, restricted);
    if(YES == decryptIn)
        OK = OK
             && IS_ATTRIBUTE(
                 symKey->publicArea.objectAttributes, MSSIMA_OBJECT, decrypt);
    else
        OK = OK
             && IS_ATTRIBUTE(symKey->publicArea.objectAttributes, MSSIMA_OBJECT, sign);
    if(!OK)
        return MSSIM_RCS_ATTRIBUTES + RC_EncryptDecrypt_keyHandle;

    // Make sure that key is an encrypt/decrypt key and not SMAC
    if(!CryptSymModeIsValid(mode, TRUE))
        return MSSIM_RCS_MODE + RC_EncryptDecrypt_keyHandle;

    // If the key mode is not MSSIM_ALG_NULL...
    // or MSSIM_ALG_NULL
    if(mode != MSSIM_ALG_NULL)
    {
        // then the input mode has to be MSSIM_ALG_NULL or the same as the key
        if((modeIn != MSSIM_ALG_NULL) && (modeIn != mode))
            return MSSIM_RCS_MODE + RC_EncryptDecrypt_mode;
    }
    else
    {
        // if the key mode is null, then the input can't be null
        if(modeIn == MSSIM_ALG_NULL)
            return MSSIM_RCS_MODE + RC_EncryptDecrypt_mode;
        mode = modeIn;
    }
    // The input iv for ECB mode should be an Empty Buffer.  All the other modes
    // should have an iv size same as encryption block size
    keySize   = symKey->publicArea.parameters.symDetail.sym.keyBits.sym;
    alg       = symKey->publicArea.parameters.symDetail.sym.algorithm;
    blockSize = CryptGetSymmetricBlockSize(alg, keySize);

    // reverify the algorithm. This is mainly to keep static analysis tools happy
    if(blockSize == 0)
        return MSSIM_RCS_KEY + RC_EncryptDecrypt_keyHandle;

    if(((mode == MSSIM_ALG_ECB) && (ivIn->t.size != 0))
       || ((mode != MSSIM_ALG_ECB) && (ivIn->t.size != blockSize)))
        return MSSIM_RCS_SIZE + RC_EncryptDecrypt_ivIn;

    // The input data size of CBC mode or ECB mode must be an even multiple of
    // the symmetric algorithm's block size
    if(((mode == MSSIM_ALG_CBC) || (mode == MSSIM_ALG_ECB))
       && ((inData->t.size % blockSize) != 0))
        return MSSIM_RCS_SIZE + RC_EncryptDecrypt_inData;

    // Copy IV
    // Note: This is copied here so that the calls to the encrypt/decrypt functions
    // will modify the output buffer, not the input buffer
    out->ivOut = *ivIn;

    // Command Output
    key = symKey->sensitive.sensitive.sym.t.buffer;
    // For symmetric encryption, the cipher data size is the same as plain data
    // size.
    out->outData.t.size = inData->t.size;
    if(decryptIn == YES)
    {
        // Decrypt data to output
        result = CryptSymmetricDecrypt(out->outData.t.buffer,
                                       alg,
                                       keySize,
                                       key,
                                       &(out->ivOut),
                                       mode,
                                       inData->t.size,
                                       inData->t.buffer);
    }
    else
    {
        // Encrypt data to output
        result = CryptSymmetricEncrypt(out->outData.t.buffer,
                                       alg,
                                       keySize,
                                       key,
                                       &(out->ivOut),
                                       mode,
                                       inData->t.size,
                                       inData->t.buffer);
    }
    return result;
}

#endif  // CC_VIRT_StoreState || CC_VIRT_RestoreState