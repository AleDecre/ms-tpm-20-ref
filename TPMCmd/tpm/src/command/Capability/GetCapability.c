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
#include "GetCapability_fp.h"

#if CC_GetCapability  // Conditional expansion of this file

/*(See part 3 specification)
// This command returns various information regarding the MSSIM and its current
// state
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_HANDLE       value of 'property' is in an unsupported handle range
//                          for the MSSIM_CAP_HANDLES 'capability' value
//      MSSIM_RC_VALUE        invalid 'capability'; or 'property' is not 0 for the
//                          MSSIM_CAP_PCRS 'capability' value
MSSIM_RC
MSSIM2_GetCapability(GetCapability_In*  in,  // IN: input parameter list
                   GetCapability_Out* out  // OUT: output parameter list
)
{
    MSSIMU_CAPABILITIES* data = &out->capabilityData.data;
    // Command Output

    // Set output capability type the same as input type
    out->capabilityData.capability = in->capability;

    switch(in->capability)
    {
        case MSSIM_CAP_ALGS:
            out->moreData = AlgorithmCapGetImplemented(
                (MSSIM_ALG_ID)in->property, in->propertyCount, &data->algorithms);
            break;
        case MSSIM_CAP_HANDLES:
            switch(HandleGetType((MSSIM_HANDLE)in->property))
            {
                case MSSIM_HT_TRANSIENT:
                    // Get list of handles of loaded transient objects
                    out->moreData = ObjectCapGetLoaded(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
                case MSSIM_HT_PERSISTENT:
                    // Get list of handles of persistent objects
                    out->moreData = NvCapGetPersistent(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
                case MSSIM_HT_NV_INDEX:
                    // Get list of defined NV index
                    out->moreData = NvCapGetIndex(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
                case MSSIM_HT_LOADED_SESSION:
                    // Get list of handles of loaded sessions
                    out->moreData = SessionCapGetLoaded(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
#  ifdef MSSIM_HT_SAVED_SESSION
                case MSSIM_HT_SAVED_SESSION:
#  else
                case MSSIM_HT_ACTIVE_SESSION:
#  endif
                    // Get list of handles of
                    out->moreData = SessionCapGetSaved(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
                case MSSIM_HT_PCR:
                    // Get list of handles of PCR
                    out->moreData = PCRCapGetHandles(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
                case MSSIM_HT_PERMANENT:
                    // Get list of permanent handles
                    out->moreData = PermanentCapGetHandles(
                        (MSSIM_HANDLE)in->property, in->propertyCount, &data->handles);
                    break;
                default:
                    // Unsupported input handle type
                    return MSSIM_RCS_HANDLE + RC_GetCapability_property;
                    break;
            }
            break;
        case MSSIM_CAP_COMMANDS:
            out->moreData = CommandCapGetCCList(
                (MSSIM_CC)in->property, in->propertyCount, &data->command);
            break;
        case MSSIM_CAP_PP_COMMANDS:
            out->moreData = PhysicalPresenceCapGetCCList(
                (MSSIM_CC)in->property, in->propertyCount, &data->ppCommands);
            break;
        case MSSIM_CAP_AUDIT_COMMANDS:
            out->moreData = CommandAuditCapGetCCList(
                (MSSIM_CC)in->property, in->propertyCount, &data->auditCommands);
            break;
        case MSSIM_CAP_PCRS:
            // Input property must be 0
            if(in->property != 0)
                return MSSIM_RCS_VALUE + RC_GetCapability_property;
            out->moreData =
                PCRCapGetAllocation(in->propertyCount, &data->assignedPCR);
            break;
        case MSSIM_CAP_PCR_PROPERTIES:
            out->moreData = PCRCapGetProperties(
                (MSSIM_PT_PCR)in->property, in->propertyCount, &data->pcrProperties);
            break;
        case MSSIM_CAP_MSSIM_PROPERTIES:
            out->moreData = MSSIMCapGetProperties(
                (MSSIM_PT)in->property, in->propertyCount, &data->tpmProperties);
            break;
#  if ALG_ECC
        case MSSIM_CAP_ECC_CURVES:
            out->moreData = CryptCapGetECCCurve(
                (MSSIM_ECC_CURVE)in->property, in->propertyCount, &data->eccCurves);
            break;
#  endif  // ALG_ECC
        case MSSIM_CAP_AUTH_POLICIES:
            if(HandleGetType((MSSIM_HANDLE)in->property) != MSSIM_HT_PERMANENT)
                return MSSIM_RCS_VALUE + RC_GetCapability_property;
            out->moreData = PermanentHandleGetPolicy(
                (MSSIM_HANDLE)in->property, in->propertyCount, &data->authPolicies);
            break;
        case MSSIM_CAP_ACT:
            if(((MSSIM_RH)in->property < MSSIM_RH_ACT_0)
               || ((MSSIM_RH)in->property > MSSIM_RH_ACT_F))
                return MSSIM_RCS_VALUE + RC_GetCapability_property;
            out->moreData = ActGetCapabilityData(
                (MSSIM_HANDLE)in->property, in->propertyCount, &data->actData);
            break;
        case MSSIM_CAP_VENDOR_PROPERTY:
            // vendor property is not implemented
        default:
            // Unsupported MSSIM_CAP value
            return MSSIM_RCS_VALUE + RC_GetCapability_capability;
            break;
    }

    return MSSIM_RC_SUCCESS;
}

#endif  // CC_GetCapability