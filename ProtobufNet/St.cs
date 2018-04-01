using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using ProtoBuf;

namespace ProtobufNet
{
    [ProtoContract]
    class St
    {
        [ProtoMember(1)]
        public int A { get; set; }
        [ProtoMember(2)]
        public string B { get; set; }
        [ProtoMember(3)]
        public T Child { get; set; }
        [ProtoMember(4)]
        public int C { get; set; }
        [ProtoMember(5)]
        public bool D { get; set; }
        [ProtoMember(6)]
        public Dictionary<string, int> Dict { get; set; }
        [ProtoMember(7)]
        public byte[] ArrayOfBytes { get; set; }
    }

    [ProtoContract]
    class T
    {
        [ProtoMember(1)]
        public int X { get; set; }
        [ProtoMember(2)]
        public int Y { get; set; }
        [ProtoMember(3)]
        public int Z { get; set; }
    }
}
