using System;
using System.Collections.Generic;
using System.Text;

namespace ProtobufCsharp2
{
    public partial class MySt
    {
        public int A { get; set; }
        public string B { get; set; }
        public MyT Child { get; set; }
        public int C { get; set; }
        public bool D { get; set; }
        public Dictionary<string, int> Dict { get; set; }
        public byte[] ArrayOfBytes { get; set; }
    }

    public partial class MyT
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Z { get; set; }
    }
}
