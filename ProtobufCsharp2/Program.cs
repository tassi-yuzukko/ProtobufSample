using Google.Protobuf;
using System;
using System.IO;
using System.Text;
using test;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;
using System.Collections.Generic;

namespace ProtobufCsharp2
{
    class Program
    {
        static readonly string FileName = @"..\ProtobufSample2\serialize_data.dat";

        static void Main(string[] args)
        {
            var bytes = SerializeObject();
            DeserializeObject(bytes);

            Console.ReadLine();
        }

        static byte[] SerializeObject()
        {
            var dict = new Dictionary<string, int>();
            dict.Add("tashima", 32);
            dict.Add("Sato", 45);
            dict.Add("Ueda", 52);
            dict.Add("Venus", 23);
            dict.Add("Watson", 3);

            var mySt = new MySt
            {
                A = 123456789,
                B = "tashimakeidesu",
                Child = new MyT
                {
                    X = 9999,
                    Y = 8888,
                    Z = 7777,
                },
                C = -123456789,
                D = true,
                Dict = dict,
                ArrayOfBytes = new byte[] { 1, 2, 3, 5, 8, 13, 21, 34, 55 },
            };

            var setting = new JsonSerializerSettings { MissingMemberHandling = MissingMemberHandling.Ignore, NullValueHandling = NullValueHandling.Ignore, Formatting = Formatting.Indented, ContractResolver = new CamelCasePropertyNamesContractResolver() };
            var json = JsonConvert.SerializeObject(mySt, setting);

            JsonParser jsonParser = new JsonParser(JsonParser.Settings.Default);

            var st = jsonParser.Parse<st>(json);
            return Serialize(st);
        }

        static void DeserializeObject(byte[] bytes)
        {
            // デシリアライズ
            st st = Deserialize<st>(bytes);

            JsonFormatter jsonFormatter = new JsonFormatter(JsonFormatter.Settings.Default);
            var json = jsonFormatter.Format(st);

            var setting = new JsonSerializerSettings { MissingMemberHandling = MissingMemberHandling.Ignore, NullValueHandling = NullValueHandling.Ignore, Formatting = Formatting.Indented, ContractResolver = new CamelCasePropertyNamesContractResolver() };
            var mySt = JsonConvert.DeserializeObject<MySt>(json, setting);

            Console.WriteLine("Read Success !!");
            Console.WriteLine($"A:{st.A}, B:{st.B}, C:{st.C}, D:{st.D}, Child.X:{st.Child.X}, Child.Y:{st.Child.Y}");
            foreach (var item in st.Dict)
            {
                Console.WriteLine($"key:{item.Key}, value:{item.Value}");
            }
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

        static byte[] Serialize<T>(T obj) where T : IMessage<T>
        {
            using (var stream = new MemoryStream())
            {
                obj.WriteTo(stream);
                return stream.ToArray();
            }
        }

        static T Deserialize<T>(byte[] data) where T : IMessage<T>, new()
        {
            var parser = new MessageParser<T>(() => new T());
            return parser.ParseFrom(new MemoryStream(data));
        }
    }
}
