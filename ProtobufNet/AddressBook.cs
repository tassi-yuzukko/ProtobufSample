using ProtoBuf;
using System;
using System.Collections.Generic;
using System.Text;

namespace ProtobufNet
{
    [ProtoContract]
    class AddressBook
    {
        [ProtoMember(1)]
        public Person[] People { get; set; }
    }
}
