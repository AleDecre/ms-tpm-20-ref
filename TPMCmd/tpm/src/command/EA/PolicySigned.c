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
#include "Policy_spt_fp.h"
#include "PolicySigned_fp.h"

#if CC_PolicySigned  // Conditional expansion of this file

/*(See part 3 specification)
// Include an asymmetrically signed authorization to the policy evaluation
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_CPHASH           cpHash was previously set to a different value
//      MSSIM_RC_EXPIRED          'expiration' indicates a time in the past or
//                              'expiration' is non-zero but no nonceMSSIM is present
//      MSSIM_RC_NONCE            'nonceMSSIM' is not the nonce associated with the
//                              'policySession'
//      MSSIM_RC_SCHEME           the signing scheme of 'auth' is not supported by the
//                              MSSIM
//      MSSIM_RC_SIGNATURE        the signature is not genuine
//      MSSIM_RC_SIZE             input cpHash has wrong size
MSSIM_RC
MSSIM2_PolicySigned(PolicySigned_In*  in,  // IN: input parameter list
                  PolicySigned_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC       result = MSSIM_RC_SUCCESS;
    SESSION*     session;
    MSSIM2B_NAME   entityName;
    MSSIM2B_DIGEST authHash;
    HASH_STATE   hashState;
    UINT64       authTimeout = 0;
    // Input Validation
    // Set up local pointers
    session = SessionGet(in->policySession);  // the session structure

    // Only do input validation if this is not a trial policy session
    if(session->attributes.isTrialPolicy == CLEAR)
    {
        authTimeout = ComputeAuthTimeout(session, in->expiration, &in->nonceMSSIM);

        result      = PolicyParameterChecks(session,
                                       authTimeout,
                                       &in->cpHashA,
                                       &in->nonceMSSIM,
                                       RC_PolicySigned_nonceMSSIM,
                                       RC_PolicySigned_cpHashA,
                                       RC_PolicySigned_expiration);
        if(result != MSSIM_RC_SUCCESS)
            return result;
        // Re-compute the digest being signed
        /*(See part 3 specification)
        // The digest is computed as:
        //     aHash := hash ( nonceMSSIM | expiration | cpHashA | policyRef)
        //  where:
        //      hash()      the hash associated with the signed authorization
        //      nonceMSSIM    the nonceMSSIM value from the MSSIM2_StartAuthSession .
        //                  response If the authorization is not limited to this
        //                  session, the size of this value is zero.
        //      expiration  time limit on authorization set by authorizing object.
        //                  This 32-bit value is set to zero if the expiration
        //                  time is not being set.
        //      cpHashA     hash of the command parameters for the command being
        //                  approved using the hash algorithm of the PSAP session.
        //                  Set to NULLauth if the authorization is not limited
        //                  to a specific command.
        //      policyRef   hash of an opaque value determined by the authorizing
        //                  object.  Set to the NULLdigest if no hash is present.
        */
        // Start hash
        authHash.t.size = CryptHashStart(&hashState, CryptGetSignHashAlg(&in->auth));
        // If there is no digest size, then we don't have a verification function
        // for this algorithm (e.g. MSSIM_ALG_ECDAA) so indicate that it is a
        // bad scheme.
        if(authHash.t.size == 0)
            return MSSIM_RCS_SCHEME + RC_PolicySigned_auth;

        //  nonceMSSIM
        CryptDigestUpdate2B(&hashState, &in->nonceMSSIM.b);

        //  expiration
        CryptDigestUpdateInt(&hashState, sizeof(UINT32), in->expiration);

        //  cpHashA
        CryptDigestUpdate2B(&hashState, &in->cpHashA.b);

        //  policyRef
        CryptDigestUpdate2B(&hashState, &in->policyRef.b);

        //  Complete digest
        CryptHashEnd2B(&hashState, &authHash.b);

        // Validate Signature.  A MSSIM_RC_SCHEME, MSSIM_RC_HANDLE or MSSIM_RC_SIGNATURE
        // error may be returned at this point
        result = CryptValidateSignature(in->authObject, &authHash, &in->auth);
        if(result != MSSIM_RC_SUCCESS)
            return RcSafeAddToResult(result, RC_PolicySigned_auth);
    }
    // Internal Data Update
    // Update policy with input policyRef and name of authorization key
    // These values are updated even if the session is a trial session
    PolicyContextUpdate(MSSIM_CC_PolicySigned,
                        EntityGetName(in->authObject, &entityName),
                        &in->policyRef,
                        &in->cpHashA,
                        authTimeout,
                        session);
    // Command Output
    // Create ticket and timeout buffer if in->expiration < 0 and this is not
    // a trial session.
    // NOTE: PolicyParameterChecks() makes sure that nonceMSSIM is present
    // when expiration is non-zero.
    if(in->expiration < 0 && session->attributes.isTrialPolicy == CLEAR)
    {
        BOOL expiresOnReset = (in->nonceMSSIM.t.size == 0);
        // Compute policy ticket
        authTimeout &= ~EXPIRATION_BIT;

        TicketComputeAuth(MSSIM_ST_AUTH_SIGNED,
                          EntityGetHierarchy(in->authObject),
                          authTimeout,
                          expiresOnReset,
                          &in->cpHashA,
                          &in->policyRef,
                          &entityName,
                          &out->policyTicket);
        // Generate timeout buffer.  The format of output timeout buffer is
        // MSSIM-specific.
        // Note: In this implementation, the timeout buffer value is computed after
        // the ticket is produced so, when the ticket is checked, the expiration
        // flag needs to be extracted before the ticket is checked.
        // In the Windows compatible version, the least-significant bit of the
        // timeout value is used as a flag to indicate if the authorization expires
        // on reset. The flag is the MSb.
        out->timeout.t.size = sizeof(authTimeout);
        if(expiresOnReset)
            authTimeout |= EXPIRATION_BIT;
        UINT64_TO_BYTE_ARRAY(authTimeout, out->timeout.t.buffer);
    }
    else
    {
        // Generate a null ticket.
        // timeout buffer is null
        out->timeout.t.size = 0;

        // authorization ticket is null
        out->policyTicket.tag           = MSSIM_ST_AUTH_SIGNED;
        out->policyTicket.hierarchy     = MSSIM_RH_NULL;
        out->policyTicket.digest.t.size = 0;
    }
    return MSSIM_RC_SUCCESS;
}

#endif  // CC_PolicySigned