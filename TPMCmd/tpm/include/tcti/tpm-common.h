/* SPDX-License-Identifier: BSD-2-Clause */
/***********************************************************************
 * Copyright (c) 2015 - 2018 Intel Corporation
 * All rights reserved.
 ***********************************************************************/
#ifndef TCTI_COMMON_H
#define TCTI_COMMON_H

#include <stdbool.h>

#include "tpm_tcti.h"

/* Definition of UINT16 TPM2_ST Constants <INOUT S> */
typedef UINT16 TPM2_ST;
#define TPM2_ST_RSP_COMMAND          ((TPM2_ST) 0x00C4) /* Tag value for a response used when there is an error in the tag. This is also the value returned from a TPM 1.2 when an error occurs. This value is used in this specification because an error in the command tag may prevent determination of the family. When this tag is used in the response the response code will be TPM2_RC_BAD_TAG 0 1E16 which has the same numeric value as the TPM 1.2 response code for TPM_BADTAG. NOTE In a previously published version of this specification TPM2_RC_BAD_TAG was incorrectly assigned a value of 0x030 instead of 30 0x01e. Some implementations my return the old value instead of the new value. */
#define TPM2_ST_NULL                 ((TPM2_ST) 0X8000) /* no structure type specified */
#define TPM2_ST_NO_SESSIONS          ((TPM2_ST) 0x8001) /* tag value for a command response for a command defined in this specification indicating that the command response has no attached sessions and no authorizationSizeparameterSize value is present. If the responseCode from the TPM is not TPM2_RC_SUCCESS then the response tag shall have this value. */
#define TPM2_ST_SESSIONS             ((TPM2_ST) 0x8002) /* tag value for a command response for a command defined in this specification indicating that the command response has one or more attached sessions and the authorizationSizeparameterSize field is present */
#define TPM2_ST_RESERVED1            ((TPM2_ST) 0x8003) /* When used between application software and the TPM resource manager, this tag indicates that the command has no sessions and the handles are using the Name format rather than the 32-bit handle format. NOTE 1 The response to application software will have a tag of TPM2_ST_NO_SESSIONS. Between the TRM and TPM, this tag would occur in a response from a TPM that overlaps the tag parameter of a request with the tag parameter of a response when the response has no associated sessions. NOTE 2 This tag is not used by all TPM or TRM implementations. */
#define TPM2_ST_RESERVED2            ((TPM2_ST) 0x8004) /* When used between application software and the TPM resource manager. This tag indicates that the command has sessions and the handles are using the Name format rather than the 32-bit handle format. NOTE 1 If the command completes successfully the response to application software will have a tag of TPM2_ST_SESSIONS. Between the TRM and TPM would occur in a response from a TPM that overlaps the tag parameter of a request with the tag parameter of a response when the response has authorization sessions. NOTE 2 This tag is not used by all TPM or TRM implementations. */
#define TPM2_ST_ATTEST_NV            ((TPM2_ST) 0x8014) /* tag for an attestation structure */
#define TPM2_ST_ATTEST_COMMAND_AUDIT ((TPM2_ST) 0x8015) /* tag for an attestation structure */
#define TPM2_ST_ATTEST_SESSION_AUDIT ((TPM2_ST) 0x8016) /* tag for an attestation structure */
#define TPM2_ST_ATTEST_CERTIFY       ((TPM2_ST) 0x8017) /* tag for an attestation structure */
#define TPM2_ST_ATTEST_QUOTE         ((TPM2_ST) 0x8018) /* tag for an attestation structure */
#define TPM2_ST_ATTEST_TIME          ((TPM2_ST) 0x8019) /* tag for an attestation structure */
#define TPM2_ST_ATTEST_CREATION      ((TPM2_ST) 0x801A) /* tag for an attestation structure */
#define TPM2_ST_RESERVED3            ((TPM2_ST) 0x801B) /* do not use . NOTE This was previously assigned to TPM2_ST_ATTEST_NV. The tag is changed because the structure has changed */
#define TPM2_ST_CREATION             ((TPM2_ST) 0x8021) /* tag for a ticket type */
#define TPM2_ST_VERIFIED             ((TPM2_ST) 0x8022) /* tag for a ticket type */
#define TPM2_ST_AUTH_SECRET          ((TPM2_ST) 0x8023) /* tag for a ticket type */
#define TPM2_ST_HASHCHECK            ((TPM2_ST) 0x8024) /* tag for a ticket type */
#define TPM2_ST_AUTH_SIGNED          ((TPM2_ST) 0x8025) /* tag for a ticket type */
#define TPM2_ST_FU_MANIFEST          ((TPM2_ST) 0x8029) /* tag for a structure describing a Field Upgrade Policy */

#define TCTI_VERSION 0x2

#define TPM_HEADER_SIZE (sizeof (TPM2_ST) + sizeof (UINT32) + sizeof (UINT32))

typedef struct {
    TPM2_ST tag;
    UINT32 size;
    UINT32 code;
} tpm_header_t;
/*
 * The elements in this enumeration represent the possible states that the
 * TCTI can be in. The state machine is as follows:
 * An instantiated TCTI context begins in the TRANSMIT state:
 *   TRANSMIT:
 *     transmit:    success transitions the state machine to RECEIVE
 *                  failure leaves the state unchanged
 *     receive:     produces TSS2_TCTI_RC_BAD_SEQUENCE
 *     finalize:    transitions state machine to FINAL state
 *     cancel:      produces TSS2_TCTI_RC_BAD_SEQUENCE
 *     setLocality: success or failure leaves state unchanged
 *   RECEIVE:
 *     transmit:    produces TSS2_TCTI_RC_BAD_SEQUENCE
 *     receive:     success transitions the state machine to TRANSMIT
 *                  failure with the following RCs leave the state unchanged:
 *                    TRY_AGAIN, INSUFFICIENT_BUFFER, BAD_CONTEXT,
 *                    BAD_REFERENCE, BAD_VALUE, BAD_SEQUENCE
 *                  all other failures transition state machine to
 *                    TRANSMIT (not recoverable)
 *     finalize:    transitions state machine to FINAL state
 *     cancel:      success transitions state machine to TRANSMIT
 *                  failure leaves state unchanged
 *     setLocality: produces TSS2_TCTI_RC_BAD_SEQUENCE
 *   FINAL:
 *     all function calls produce TSS2_TCTI_RC_BAD_SEQUENCE
 */
typedef enum {
    TCTI_STATE_FINAL,
    TCTI_STATE_TRANSMIT,
    TCTI_STATE_RECEIVE,
} tcti_state_t;

typedef struct {
    TSS2_TCTI_CONTEXT_COMMON_V2 v2;
    tcti_state_t state;
    tpm_header_t header;
    uint8_t locality;
    bool partial_read_supported;
    bool partial;
} TSS2_TCTI_COMMON_CONTEXT;

/*
 */
TSS2_TCTI_COMMON_CONTEXT*
tcti_common_context_cast (TSS2_TCTI_CONTEXT *ctx);
/*
 * This function is used to "down cast" the Intel TCTI context to the opaque
 * context type.
 */
TSS2_TCTI_CONTEXT*
tcti_common_down_cast (TSS2_TCTI_COMMON_CONTEXT *ctx);
/*
 * This function performs checks on the common context structure passed to a
 * TCTI 'cancel' function.
 */
TSS2_RC
tcti_common_cancel_checks (
    TSS2_TCTI_COMMON_CONTEXT *tcti_common,
    uint64_t magic);
/*
 * This function performs common checks on the context structure and the
 * buffer passed into TCTI 'transmit' functions.
 */
TSS2_RC
tcti_common_transmit_checks (
    TSS2_TCTI_COMMON_CONTEXT *tcti_common,
    const uint8_t *command_buffer,
    uint64_t magic);
/*
 * This function performs common checks on the context structure, buffer and
 * size parameter passed to the TCTI 'receive' functions.
 */
TSS2_RC
tcti_common_receive_checks (
    TSS2_TCTI_COMMON_CONTEXT *tcti_common,
    size_t *response_size,
    uint64_t magic);
/*
 * This function performs checks on the common context structure passed to a
 * TCTI 'set_locality' function.
 */
TSS2_RC
tcti_common_set_locality_checks (
    TSS2_TCTI_COMMON_CONTEXT *tcti_common,
    uint64_t magic);
/*
 * Just a function with the right prototype that returns the not implemented
 * RC for the TCTI layer.
 */
TSS2_RC
tcti_make_sticky_not_implemented (
    TSS2_TCTI_CONTEXT *tctiContext,
    TPM2_HANDLE *handle,
    uint8_t sticky);
/*
 * Utility to function to parse the first 10 bytes of a buffer and populate
 * the 'header' structure with the results. The provided buffer is assumed to
 * be at least 10 bytes long.
 */
TSS2_RC
header_unmarshal (
    const uint8_t *buf,
    tpm_header_t *header);
/*
 */
TSS2_RC
header_marshal (
    const tpm_header_t *header,
    uint8_t *buf);

#endif
