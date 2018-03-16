using Google.Protobuf;
using System;
using System.IO;
using System.Text;
using test;

namespace ProtobufCsharp2
{
    class Program
    {
        static readonly string FileName = @"C:\13041\00-repo\git\github\ProtobufSample\ProtobufSample2\serialize_data.dat";

        static void Main(string[] args)
        {
            // デシリアライズ
            st st = Deserialize<st>(ReadFile(FileName));

            Console.WriteLine("Read Success !!");
            Console.WriteLine($"A:{st.A}, B:{st.B}, C:{st.C}, D:{st.D}, Child.X:{st.Child.X}, Child.Y:{st.Child.Y}");
            foreach (var item in st.Dict)
            {
                Console.WriteLine($"key:{item.Key}, value:{item.Value}");
            }
            Console.ReadLine();
        }

        static byte[] ReadFile(string filename)
        {
            using (var fs = new System.IO.FileStream(
                filename,
                System.IO.FileMode.Open,
                System.IO.FileAccess.Read))
            {
                var bs = new byte[fs.Length];

                fs.Read(bs, 0, bs.Length);

                return bs;
            }
        }

        static T Deserialize<T>(byte[] data) where T : IMessage<T>, new()
        {
            var parser = new MessageParser<T>(() => new T());
            return parser.ParseFrom(new MemoryStream(data));
        }
    }
}
