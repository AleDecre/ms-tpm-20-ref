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
//** Description
// This file contains the functions that are used for accessing the
// MSSIM_CAP_MSSIM_PROPERTY values.

//** Includes

#include "Tpm.h"

//** Functions

//*** MSSIMPropertyIsDefined()
// This function accepts a property selection and, if so, sets 'value'
// to the value of the property.
//
// All the fixed values are vendor dependent or determined by a
// platform-specific specification. The values in the table below
// are examples and should be changed by the vendor.
//  Return Type: BOOL
//      TRUE(1)         referenced property exists and 'value' set
//      FALSE(0)        referenced property does not exist
static BOOL MSSIMPropertyIsDefined(MSSIM_PT  property,  // IN: property
                                 UINT32* value      // OUT: property value
)
{
    switch(property)
    {
        case MSSIM_PT_FAMILY_INDICATOR:
            // from the title page of the specification
            // For this specification, the value is "2.0".
            *value = MSSIM_SPEC_FAMILY;
            break;
        case MSSIM_PT_LEVEL:
            // from the title page of the specification
            *value = MSSIM_SPEC_LEVEL;
            break;
        case MSSIM_PT_REVISION:
            // from the title page of the specification
            *value = MSSIM_SPEC_VERSION;
            break;
        case MSSIM_PT_DAY_OF_YEAR:
            // computed from the date value on the title page of the specification
            *value = MSSIM_SPEC_DAY_OF_YEAR;
            break;
        case MSSIM_PT_YEAR:
            // from the title page of the specification
            *value = MSSIM_SPEC_YEAR;
            break;
        case MSSIM_PT_MANUFACTURER:
            // vendor ID unique to each MSSIM manufacturer
            *value = BYTE_ARRAY_TO_UINT32(MANUFACTURER);
            break;
        case MSSIM_PT_VENDOR_STRING_1:
            // first four characters of the vendor ID string
            *value = BYTE_ARRAY_TO_UINT32(VENDOR_STRING_1);
            break;
        case MSSIM_PT_VENDOR_STRING_2:
            // second four characters of the vendor ID string
#ifdef VENDOR_STRING_2
            *value = BYTE_ARRAY_TO_UINT32(VENDOR_STRING_2);
#else
            *value = 0;
#endif
            break;
        case MSSIM_PT_VENDOR_STRING_3:
            // third four characters of the vendor ID string
#ifdef VENDOR_STRING_3
            *value = BYTE_ARRAY_TO_UINT32(VENDOR_STRING_3);
#else
            *value = 0;
#endif
            break;
        case MSSIM_PT_VENDOR_STRING_4:
            // fourth four characters of the vendor ID string
#ifdef VENDOR_STRING_4
            *value = BYTE_ARRAY_TO_UINT32(VENDOR_STRING_4);
#else
            *value = 0;
#endif
            break;
        case MSSIM_PT_VENDOR_MSSIM_TYPE:
            // vendor-defined value indicating the MSSIM model
            *value = 1;
            break;
        case MSSIM_PT_FIRMWARE_VERSION_1:
            // more significant 32-bits of a vendor-specific value
            *value = gp.firmwareV1;
            break;
        case MSSIM_PT_FIRMWARE_VERSION_2:
            // less significant 32-bits of a vendor-specific value
            *value = gp.firmwareV2;
            break;
        case MSSIM_PT_INPUT_BUFFER:
            // maximum size of MSSIM2B_MAX_BUFFER
            *value = MAX_DIGEST_BUFFER;
            break;
        case MSSIM_PT_HR_TRANSIENT_MIN:
            // minimum number of transient objects that can be held in MSSIM
            // RAM
            *value = MAX_LOADED_OBJECTS;
            break;
        case MSSIM_PT_HR_PERSISTENT_MIN:
            // minimum number of persistent objects that can be held in
            // MSSIM NV memory
            // In this implementation, there is no minimum number of
            // persistent objects.
            *value = MIN_EVICT_OBJECTS;
            break;
        case MSSIM_PT_HR_LOADED_MIN:
            // minimum number of authorization sessions that can be held in
            // MSSIM RAM
            *value = MAX_LOADED_SESSIONS;
            break;
        case MSSIM_PT_ACTIVE_SESSIONS_MAX:
            // number of authorization sessions that may be active at a time
            *value = MAX_ACTIVE_SESSIONS;
            break;
        case MSSIM_PT_PCR_COUNT:
            // number of PCR implemented
            *value = IMPLEMENTATION_PCR;
            break;
        case MSSIM_PT_PCR_SELECT_MIN:
            // minimum number of bytes in a MSSIMS_PCR_SELECT.sizeOfSelect
            *value = PCR_SELECT_MIN;
            break;
        case MSSIM_PT_CONTEXT_GAP_MAX:
            // maximum allowed difference (unsigned) between the contextID
            // values of two saved session contexts
            *value = ((UINT32)1 << (sizeof(CONTEXT_SLOT) * 8)) - 1;
            break;
        case MSSIM_PT_NV_COUNTERS_MAX:
            // maximum number of NV indexes that are allowed to have the
            // MSSIMA_NV_COUNTER attribute SET
            // In this implementation, there is no limitation on the number
            // of counters, except for the size of the NV Index memory.
            *value = 0;
            break;
        case MSSIM_PT_NV_INDEX_MAX:
            // maximum size of an NV index data area
            *value = MAX_NV_INDEX_SIZE;
            break;
        case MSSIM_PT_MEMORY:
            // a MSSIMA_MEMORY indicating the memory management method for the MSSIM
            {
                union
                {
                    MSSIMA_MEMORY att;
                    UINT32      u32;
                } attributes = {MSSIMA_ZERO_INITIALIZER()};
                SET_ATTRIBUTE(attributes.att, MSSIMA_MEMORY, sharedNV);
                SET_ATTRIBUTE(attributes.att, MSSIMA_MEMORY, objectCopiedToRam);

                // Note: For a LSb0 machine, the bits in a bit field are in the correct
                // order even if the machine is MSB0. For a MSb0 machine, a MSSIMA will
                // be an integer manipulated by masking (USE_BIT_FIELD_STRUCTURES will
                // be NO) so the bits are manipulate correctly.
                *value = attributes.u32;
                break;
            }
        case MSSIM_PT_CLOCK_UPDATE:
            // interval, in seconds, between updates to the copy of
            // MSSIMS_TIME_INFO .clock in NV
            *value = (1 << NV_CLOCK_UPDATE_INTERVAL);
            break;
        case MSSIM_PT_CONTEXT_HASH:
            // algorithm used for the integrity hash on saved contexts and
            // for digesting the fuData of MSSIM2_FirmwareRead()
            *value = CONTEXT_INTEGRITY_HASH_ALG;
            break;
        case MSSIM_PT_CONTEXT_SYM:
            // algorithm used for encryption of saved contexts
            *value = CONTEXT_ENCRYPT_ALG;
            break;
        case MSSIM_PT_CONTEXT_SYM_SIZE:
            // size of the key used for encryption of saved contexts
            *value = CONTEXT_ENCRYPT_KEY_BITS;
            break;
        case MSSIM_PT_ORDERLY_COUNT:
            // maximum difference between the volatile and non-volatile
            // versions of MSSIMA_NV_COUNTER that have MSSIMA_NV_ORDERLY SET
            *value = MAX_ORDERLY_COUNT;
            break;
        case MSSIM_PT_MAX_COMMAND_SIZE:
            // maximum value for 'commandSize'
            *value = MAX_COMMAND_SIZE;
            break;
        case MSSIM_PT_MAX_RESPONSE_SIZE:
            // maximum value for 'responseSize'
            *value = MAX_RESPONSE_SIZE;
            break;
        case MSSIM_PT_MAX_DIGEST:
            // maximum size of a digest that can be produced by the MSSIM
            *value = sizeof(MSSIMU_HA);
            break;
        case MSSIM_PT_MAX_OBJECT_CONTEXT:
// Header has 'sequence', 'handle' and 'hierarchy'
#define SIZE_OF_CONTEXT_HEADER \
  sizeof(UINT64) + sizeof(MSSIMI_DH_CONTEXT) + sizeof(MSSIMI_RH_HIERARCHY)
#define SIZE_OF_CONTEXT_INTEGRITY (sizeof(UINT16) + CONTEXT_INTEGRITY_HASH_SIZE)
#define SIZE_OF_FINGERPRINT       sizeof(UINT64)
#define SIZE_OF_CONTEXT_BLOB_OVERHEAD \
  (sizeof(UINT16) + SIZE_OF_CONTEXT_INTEGRITY + SIZE_OF_FINGERPRINT)
#define SIZE_OF_CONTEXT_OVERHEAD \
  (SIZE_OF_CONTEXT_HEADER + SIZE_OF_CONTEXT_BLOB_OVERHEAD)
#if 0
            // maximum size of a MSSIMS_CONTEXT that will be returned by
            // MSSIM2_ContextSave for object context
            *value = 0;
            // adding sequence, saved handle and hierarchy
            *value += sizeof(UINT64) + sizeof(MSSIMI_DH_CONTEXT) +
                sizeof(MSSIMI_RH_HIERARCHY);
            // add size field in MSSIM2B_CONTEXT
            *value += sizeof(UINT16);
            // add integrity hash size
            *value += sizeof(UINT16) +
                CryptHashGetDigestSize(CONTEXT_INTEGRITY_HASH_ALG);
            // Add fingerprint size, which is the same as sequence size
            *value += sizeof(UINT64);
            // Add OBJECT structure size
            *value += sizeof(OBJECT);
#else
            // the maximum size of a MSSIMS_CONTEXT that will be returned by
            // MSSIM2_ContextSave for object context
            *value = SIZE_OF_CONTEXT_OVERHEAD + sizeof(OBJECT);
#endif
            break;
        case MSSIM_PT_MAX_SESSION_CONTEXT:
#if 0

            // the maximum size of a MSSIMS_CONTEXT that will be returned by
            // MSSIM2_ContextSave for object context
            *value = 0;
            // adding sequence, saved handle and hierarchy
            *value += sizeof(UINT64) + sizeof(MSSIMI_DH_CONTEXT) +
                sizeof(MSSIMI_RH_HIERARCHY);
            // Add size field in MSSIM2B_CONTEXT
            *value += sizeof(UINT16);
// Add integrity hash size
            *value += sizeof(UINT16) +
                CryptHashGetDigestSize(CONTEXT_INTEGRITY_HASH_ALG);
      // Add fingerprint size, which is the same as sequence size
            *value += sizeof(UINT64);
            // Add SESSION structure size
            *value += sizeof(SESSION);
#else
            // the maximum size of a MSSIMS_CONTEXT that will be returned by
            // MSSIM2_ContextSave for object context
            *value = SIZE_OF_CONTEXT_OVERHEAD + sizeof(SESSION);
#endif
            break;
        case MSSIM_PT_PS_FAMILY_INDICATOR:
            // platform specific values for the MSSIM_PT_PS parameters from
            // the relevant platform-specific specification
            // In this reference implementation, all of these values are 0.
            *value = PLATFORM_FAMILY;
            break;
        case MSSIM_PT_PS_LEVEL:
            // level of the platform-specific specification
            *value = PLATFORM_LEVEL;
            break;
        case MSSIM_PT_PS_REVISION:
            // specification Revision times 100 for the platform-specific
            // specification
            *value = PLATFORM_VERSION;
            break;
        case MSSIM_PT_PS_DAY_OF_YEAR:
            // platform-specific specification day of year using TCG calendar
            *value = PLATFORM_DAY_OF_YEAR;
            break;
        case MSSIM_PT_PS_YEAR:
            // platform-specific specification year using the CE
            *value = PLATFORM_YEAR;
            break;
        case MSSIM_PT_SPLIT_MAX:
            // number of split signing operations supported by the MSSIM
            *value = 0;
#if ALG_ECC
            *value = sizeof(gr.commitArray) * 8;
#endif
            break;
        case MSSIM_PT_TOTAL_COMMANDS:
            // total number of commands implemented in the MSSIM
            // Since the reference implementation does not have any
            // vendor-defined commands, this will be the same as the
            // number of library commands.
            {
#if COMPRESSED_LISTS
                (*value) = COMMAND_COUNT;
#else
                COMMAND_INDEX commandIndex;
                *value = 0;

                // scan all implemented commands
                for(commandIndex = GetClosestCommandIndex(0);
                    commandIndex != UNIMPLEMENTED_COMMAND_INDEX;
                    commandIndex = GetNextCommandIndex(commandIndex))
                {
                    (*value)++;  // count of all implemented
                }
#endif
                break;
            }
        case MSSIM_PT_LIBRARY_COMMANDS:
            // number of commands from the MSSIM library that are implemented
            {
#if COMPRESSED_LISTS
                *value = LIBRARY_COMMAND_ARRAY_SIZE;
#else
                COMMAND_INDEX commandIndex;
                *value = 0;

                // scan all implemented commands
                for(commandIndex = GetClosestCommandIndex(0);
                    commandIndex < LIBRARY_COMMAND_ARRAY_SIZE;
                    commandIndex = GetNextCommandIndex(commandIndex))
                {
                    (*value)++;
                }
#endif
                break;
            }
        case MSSIM_PT_VENDOR_COMMANDS:
            // number of vendor commands that are implemented
            *value = VENDOR_COMMAND_ARRAY_SIZE;
            break;
        case MSSIM_PT_NV_BUFFER_MAX:
            // Maximum data size in an NV write command
            *value = MAX_NV_BUFFER_SIZE;
            break;
        case MSSIM_PT_MODES:
#if FIPS_COMPLIANT
            *value = 1;
#else
            *value = 0;
#endif
            break;
        case MSSIM_PT_MAX_CAP_BUFFER:
            *value = MAX_CAP_BUFFER;
            break;

        // Start of variable commands
        case MSSIM_PT_PERMANENT:
            // MSSIMA_PERMANENT
            {
                union
                {
                    MSSIMA_PERMANENT attr;
                    UINT32         u32;
                } flags = {MSSIMA_ZERO_INITIALIZER()};
                if(gp.ownerAuth.t.size != 0)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_PERMANENT, ownerAuthSet);
                if(gp.endorsementAuth.t.size != 0)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_PERMANENT, endorsementAuthSet);
                if(gp.lockoutAuth.t.size != 0)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_PERMANENT, lockoutAuthSet);
                if(gp.disableClear)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_PERMANENT, disableClear);
                if(gp.failedTries >= gp.maxTries)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_PERMANENT, inLockout);
                // In this implementation, EPS is always generated by MSSIM
                SET_ATTRIBUTE(flags.attr, MSSIMA_PERMANENT, tpmGeneratedEPS);

                // Note: For a LSb0 machine, the bits in a bit field are in the correct
                // order even if the machine is MSB0. For a MSb0 machine, a MSSIMA will
                // be an integer manipulated by masking (USE_BIT_FIELD_STRUCTURES will
                // be NO) so the bits are manipulate correctly.
                *value = flags.u32;
                break;
            }
        case MSSIM_PT_STARTUP_CLEAR:
            // MSSIMA_STARTUP_CLEAR
            {
                union
                {
                    MSSIMA_STARTUP_CLEAR attr;
                    UINT32             u32;
                } flags = {MSSIMA_ZERO_INITIALIZER()};
                //
                if(g_phEnable)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_STARTUP_CLEAR, phEnable);
                if(gc.shEnable)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_STARTUP_CLEAR, shEnable);
                if(gc.ehEnable)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_STARTUP_CLEAR, ehEnable);
                if(gc.phEnableNV)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_STARTUP_CLEAR, phEnableNV);
                if(g_prevOrderlyState != SU_NONE_VALUE)
                    SET_ATTRIBUTE(flags.attr, MSSIMA_STARTUP_CLEAR, orderly);

                // Note: For a LSb0 machine, the bits in a bit field are in the correct
                // order even if the machine is MSB0. For a MSb0 machine, a MSSIMA will
                // be an integer manipulated by masking (USE_BIT_FIELD_STRUCTURES will
                // be NO) so the bits are manipulate correctly.
                *value = flags.u32;
                break;
            }
        case MSSIM_PT_HR_NV_INDEX:
            // number of NV indexes currently defined
            *value = NvCapGetIndexNumber();
            break;
        case MSSIM_PT_HR_LOADED:
            // number of authorization sessions currently loaded into MSSIM
            // RAM
            *value = SessionCapGetLoadedNumber();
            break;
        case MSSIM_PT_HR_LOADED_AVAIL:
            // number of additional authorization sessions, of any type,
            // that could be loaded into MSSIM RAM
            *value = SessionCapGetLoadedAvail();
            break;
        case MSSIM_PT_HR_ACTIVE:
            // number of active authorization sessions currently being
            // tracked by the MSSIM
            *value = SessionCapGetActiveNumber();
            break;
        case MSSIM_PT_HR_ACTIVE_AVAIL:
            // number of additional authorization sessions, of any type,
            // that could be created
            *value = SessionCapGetActiveAvail();
            break;
        case MSSIM_PT_HR_TRANSIENT_AVAIL:
            // estimate of the number of additional transient objects that
            // could be loaded into MSSIM RAM
            *value = ObjectCapGetTransientAvail();
            break;
        case MSSIM_PT_HR_PERSISTENT:
            // number of persistent objects currently loaded into MSSIM
            // NV memory
            *value = NvCapGetPersistentNumber();
            break;
        case MSSIM_PT_HR_PERSISTENT_AVAIL:
            // number of additional persistent objects that could be loaded
            // into NV memory
            *value = NvCapGetPersistentAvail();
            break;
        case MSSIM_PT_NV_COUNTERS:
            // number of defined NV indexes that have NV MSSIMA_NV_COUNTER
            // attribute SET
            *value = NvCapGetCounterNumber();
            break;
        case MSSIM_PT_NV_COUNTERS_AVAIL:
            // number of additional NV indexes that can be defined with their
            // MSSIMA_NV_COUNTER attribute SET
            *value = NvCapGetCounterAvail();
            break;
        case MSSIM_PT_ALGORITHM_SET:
            // region code for the MSSIM
            *value = gp.algorithmSet;
            break;
        case MSSIM_PT_LOADED_CURVES:
#if ALG_ECC
            // number of loaded ECC curves
            *value = ECC_CURVE_COUNT;
#else   // ALG_ECC
            *value = 0;
#endif  // ALG_ECC
            break;
        case MSSIM_PT_LOCKOUT_COUNTER:
            // current value of the lockout counter
            *value = gp.failedTries;
            break;
        case MSSIM_PT_MAX_AUTH_FAIL:
            // number of authorization failures before DA lockout is invoked
            *value = gp.maxTries;
            break;
        case MSSIM_PT_LOCKOUT_INTERVAL:
            // number of seconds before the value reported by
            // MSSIM_PT_LOCKOUT_COUNTER is decremented
            *value = gp.recoveryTime;
            break;
        case MSSIM_PT_LOCKOUT_RECOVERY:
            // number of seconds after a lockoutAuth failure before use of
            // lockoutAuth may be attempted again
            *value = gp.lockoutRecovery;
            break;
        case MSSIM_PT_NV_WRITE_RECOVERY:
            // number of milliseconds before the MSSIM will accept another command
            // that will modify NV.
            // This should make a call to the platform code that is doing rate
            // limiting of NV. Rate limiting is not implemented in the reference
            // code so no call is made.
            *value = 0;
            break;
        case MSSIM_PT_AUDIT_COUNTER_0:
            // high-order 32 bits of the command audit counter
            *value = (UINT32)(gp.auditCounter >> 32);
            break;
        case MSSIM_PT_AUDIT_COUNTER_1:
            // low-order 32 bits of the command audit counter
            *value = (UINT32)(gp.auditCounter);
            break;
        default:
            // property is not defined
            return FALSE;
            break;
    }
    return TRUE;
}

//*** MSSIMCapGetProperties()
// This function is used to get the MSSIM_PT values. The search of properties will
// start at 'property' and continue until 'propertyList' has as many values as
// will fit, or the last property has been reported, or the list has as many
// values as requested in 'count'.
//  Return Type: MSSIMI_YES_NO
//  YES        more properties are available
//  NO         no more properties to be reported
MSSIMI_YES_NO
MSSIMCapGetProperties(MSSIM_PT property,  // IN: the starting MSSIM property
                    UINT32 count,     // IN: maximum number of returned
                                      //     properties
                    MSSIML_TAGGED_MSSIM_PROPERTY* propertyList  // OUT: property list
)
{
    MSSIMI_YES_NO more = NO;
    UINT32      i;
    UINT32      nextGroup;

    // initialize output property list
    propertyList->count = 0;

    // maximum count of properties we may return is MAX_PCR_PROPERTIES
    if(count > MAX_MSSIM_PROPERTIES)
        count = MAX_MSSIM_PROPERTIES;

    // if property is less than PT_FIXED, start from PT_FIXED
    if(property < PT_FIXED)
        property = PT_FIXED;
    // There is only the fixed and variable groups with the variable group coming
    // last
    if(property >= (PT_VAR + PT_GROUP))
        return more;

    // Don't read past the end of the selected group
    nextGroup = ((property / PT_GROUP) * PT_GROUP) + PT_GROUP;

    // Scan through the MSSIM properties of the requested group.
    for(i = property; i < nextGroup; i++)
    {
        UINT32 value;
        // if we have hit the end of the group, quit
        if(i != property && ((i % PT_GROUP) == 0))
            break;
        if(MSSIMPropertyIsDefined((MSSIM_PT)i, &value))
        {
            if(propertyList->count < count)
            {
                // If the list is not full, add this property
                propertyList->tpmProperty[propertyList->count].property = (MSSIM_PT)i;
                propertyList->tpmProperty[propertyList->count].value    = value;
                propertyList->count++;
            }
            else
            {
                // If the return list is full but there are more properties
                // available, set the indication and exit the loop.
                more = YES;
                break;
            }
        }
    }
    return more;
}