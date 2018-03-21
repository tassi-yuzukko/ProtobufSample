/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: st.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "st.pb-c.h"
void   st__t__init
                     (St__T         *message)
{
  static const St__T init_value = ST__T__INIT;
  *message = init_value;
}
void   st__dict_entry__init
                     (St__DictEntry         *message)
{
  static const St__DictEntry init_value = ST__DICT_ENTRY__INIT;
  *message = init_value;
}
void   st__init
                     (St         *message)
{
  static const St init_value = ST__INIT;
  *message = init_value;
}
size_t st__get_packed_size
                     (const St *message)
{
  assert(message->base.descriptor == &st__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t st__pack
                     (const St *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &st__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t st__pack_to_buffer
                     (const St *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &st__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
St *
       st__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (St *)
     protobuf_c_message_unpack (&st__descriptor,
                                allocator, len, data);
}
void   st__free_unpacked
                     (St *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &st__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor st__t__field_descriptors[3] =
{
  {
    "x",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(St__T, x),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "y",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(St__T, y),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "z",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(St__T, z),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned st__t__field_indices_by_name[] = {
  0,   /* field[0] = x */
  1,   /* field[1] = y */
  2,   /* field[2] = z */
};
static const ProtobufCIntRange st__t__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor st__t__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "st.t",
  "T",
  "St__T",
  "",
  sizeof(St__T),
  3,
  st__t__field_descriptors,
  st__t__field_indices_by_name,
  1,  st__t__number_ranges,
  (ProtobufCMessageInit) st__t__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor st__dict_entry__field_descriptors[2] =
{
  {
    "key",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(St__DictEntry, key),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(St__DictEntry, value),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned st__dict_entry__field_indices_by_name[] = {
  0,   /* field[0] = key */
  1,   /* field[1] = value */
};
static const ProtobufCIntRange st__dict_entry__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor st__dict_entry__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "st.DictEntry",
  "DictEntry",
  "St__DictEntry",
  "",
  sizeof(St__DictEntry),
  2,
  st__dict_entry__field_descriptors,
  st__dict_entry__field_indices_by_name,
  1,  st__dict_entry__number_ranges,
  (ProtobufCMessageInit) st__dict_entry__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor st__field_descriptors[7] =
{
  {
    "a",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(St, a),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "b",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(St, b),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "child",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(St, child),
    &st__t__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "c",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(St, c),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "d",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(St, d),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "dict",
    6,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(St, n_dict),
    offsetof(St, dict),
    &st__dict_entry__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "array_of_bytes",
    7,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(St, array_of_bytes),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned st__field_indices_by_name[] = {
  0,   /* field[0] = a */
  6,   /* field[6] = array_of_bytes */
  1,   /* field[1] = b */
  3,   /* field[3] = c */
  2,   /* field[2] = child */
  4,   /* field[4] = d */
  5,   /* field[5] = dict */
};
static const ProtobufCIntRange st__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 7 }
};
const ProtobufCMessageDescriptor st__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "st",
  "St",
  "St",
  "",
  sizeof(St),
  7,
  st__field_descriptors,
  st__field_indices_by_name,
  1,  st__number_ranges,
  (ProtobufCMessageInit) st__init,
  NULL,NULL,NULL    /* reserved[123] */
};