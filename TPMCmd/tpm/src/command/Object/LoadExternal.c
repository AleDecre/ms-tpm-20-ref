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
#include "LoadExternal_fp.h"

#if CC_LoadExternal  // Conditional expansion of this file

#  include "Object_spt_fp.h"

/*(See part 3 specification)
// to load an object that is not a Protected Object into the public portion
// of an object into the MSSIM. The command allows loading of a public area or
// both a public and sensitive area
*/
//  Return Type: MSSIM_RC
//      MSSIM_RC_ATTRIBUTES       'fixedParent', 'fixedMSSIM', and 'restricted' must
//                              be CLEAR if sensitive portion of an object is loaded
//      MSSIM_RC_BINDING          the 'inPublic' and 'inPrivate' structures are not
//                              cryptographically bound
//      MSSIM_RC_HASH             incorrect hash selection for signing key
//      MSSIM_RC_HIERARCHY        'hierarchy' is turned off, or only NULL hierarchy
//                              is allowed when loading public and private parts
//                              of an object
//      MSSIM_RC_KDF              incorrect KDF selection for decrypting
//                              keyedHash object
//      MSSIM_RC_KEY              the size of the object's 'unique' field is not
//                              consistent with the indicated size in the object's
//                              parameters
//      MSSIM_RC_OBJECT_MEMORY    if there is no free slot for an object
//      MSSIM_RC_ECC_POINT        for a public-only ECC key, the ECC point is not
//                              on the curve
//      MSSIM_RC_SCHEME           the signing scheme is not valid for the key
//      MSSIM_RC_SIZE             'authPolicy' is not zero and is not the size of a
//                              digest produced by the object's 'nameAlg'
//                              MSSIM_RH_NULL hierarchy
//      MSSIM_RC_SYMMETRIC        symmetric algorithm not provided when required
//      MSSIM_RC_TYPE             'inPublic' and 'inPrivate' are not the same type
MSSIM_RC
MSSIM2_LoadExternal(LoadExternal_In*  in,  // IN: input parameter list
                  LoadExternal_Out* out  // OUT: output parameter list
)
{
    MSSIM_RC          result;
    OBJECT*         object;
    MSSIMT_SENSITIVE* sensitive = NULL;

    // Input Validation
    // Don't get invested in loading if there is no place to put it.
    object = FindEmptyObjectSlot(&out->objectHandle);
    if(object == NULL)
        return MSSIM_RC_OBJECT_MEMORY;

    // If the hierarchy to be associated with this object is turned off, the object
    // cannot be loaded.
    if(!HierarchyIsEnabled(in->hierarchy))
        return MSSIM_RCS_HIERARCHY + RC_LoadExternal_hierarchy;

    // For loading an object with both public and sensitive
    if(in->inPrivate.size != 0)
    {
        // An external object with a sensitive area can only be loaded in the
        // NULL hierarchy
        if(in->hierarchy != MSSIM_RH_NULL)
            return MSSIM_RCS_HIERARCHY + RC_LoadExternal_hierarchy;
        // An external object with a sensitive area must have fixedMSSIM == CLEAR
        // fixedParent == CLEAR so that it does not appear to be a key created by
        // this MSSIM.
        if(IS_ATTRIBUTE(
               in->inPublic.publicArea.objectAttributes, MSSIMA_OBJECT, fixedMSSIM)
           || IS_ATTRIBUTE(
               in->inPublic.publicArea.objectAttributes, MSSIMA_OBJECT, fixedParent)
           || IS_ATTRIBUTE(
               in->inPublic.publicArea.objectAttributes, MSSIMA_OBJECT, restricted))
            return MSSIM_RCS_ATTRIBUTES + RC_LoadExternal_inPublic;

        // Have sensitive point to something other than NULL so that object
        // initialization will load the sensitive part too
        sensitive = &in->inPrivate.sensitiveArea;
    }

    // Need the name to initialize the object structure
    PublicMarshalAndComputeName(&in->inPublic.publicArea, &out->name);

    // Load and validate key
    result = ObjectLoad(object,
                        NULL,
                        &in->inPublic.publicArea,
                        sensitive,
                        RC_LoadExternal_inPublic,
                        RC_LoadExternal_inPrivate,
                        &out->name);
    if(result == MSSIM_RC_SUCCESS)
    {
        object->attributes.external = SET;
        // Set the common OBJECT attributes for a loaded object.
        ObjectSetLoadedAttributes(object, in->hierarchy);
    }
    return result;
}

#endif  // CC_LoadExternal