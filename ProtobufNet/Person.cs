using ProtoBuf;
using System;
using System.Collections.Generic;
using System.Text;

namespace ProtobufNet
{
    [ProtoContract]
    class Person
    {
        [ProtoMember(1)]
        public string Name { get; set; }
        [ProtoMember(2)]
        public int Id { get; set; }
        [ProtoMember(3)]
        public string Email { get; set; }
        [ProtoMember(4)]
        public PhoneNumber[] Phones { get; set; }
    }

    enum PhoneType
    {
        MOBILE,
        HOME,
        WORK,
    }

    [ProtoContract]
    struct PhoneNumber
    {
        [ProtoMember(1)]
        public string Number { get; set; }
        [ProtoMember(2)]
        public PhoneType Type { get; set; }
    }
}
