/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/config/trace/v3/lightstep.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/collections/array_internal.h"
#include "upb/message/internal.h"
#include "upb/mini_table/enum_internal.h"
#include "envoy/config/trace/v3/lightstep.upb.h"
#include "envoy/config/core/v3/base.upb.h"
#include "envoy/annotations/deprecation.upb.h"
#include "udpa/annotations/migrate.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

// Must be last.
#include "upb/port/def.inc"

static const upb_MiniTableSub envoy_config_trace_v3_LightstepConfig_submsgs[1] = {
  {.submsg = &envoy_config_core_v3_DataSource_msg_init},
};

static const upb_MiniTableField envoy_config_trace_v3_LightstepConfig__fields[4] = {
  {1, UPB_SIZE(12, 8), 0, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {2, UPB_SIZE(20, 24), 0, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)},
  {3, UPB_SIZE(4, 40), 0, kUpb_NoSub, 5, kUpb_FieldMode_Array | kUpb_LabelFlags_IsPacked | kUpb_LabelFlags_IsAlternate | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)},
  {4, UPB_SIZE(8, 48), 1, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)},
};

const upb_MiniTable envoy_config_trace_v3_LightstepConfig_msg_init = {
  &envoy_config_trace_v3_LightstepConfig_submsgs[0],
  &envoy_config_trace_v3_LightstepConfig__fields[0],
  UPB_SIZE(32, 56), 4, kUpb_ExtMode_NonExtendable, 4, UPB_FASTTABLE_MASK(56), 0,
  UPB_FASTTABLE_INIT({
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x000800003f00000a, &upb_pss_1bt},
    {0x001800003f000012, &upb_pss_1bt},
    {0x002800003f00001a, &upb_ppv4_1bt},
    {0x0030000001000022, &upb_psm_1bt_maxmaxb},
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
    {0x0000000000000000, &_upb_FastDecoder_DecodeGeneric},
  })
};

static const upb_MiniTable *messages_layout[1] = {
  &envoy_config_trace_v3_LightstepConfig_msg_init,
};

const upb_MiniTableFile envoy_config_trace_v3_lightstep_proto_upb_file_layout = {
  messages_layout,
  NULL,
  NULL,
  1,
  0,
  0,
};

#include "upb/port/undef.inc"
