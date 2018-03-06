using System;
using System.IO;
using System.Text;
using Google.Protobuf;
using Google.Protobuf.Examples.AddressBook; // protoc.exeにより自動生成されたクラスの名前空間
using static Google.Protobuf.Examples.AddressBook.Person.Types; // C# 6 の書き方で、クラス内クラスを省略形式で記述することができるようになる（protobufとは関係なし）

namespace ProtobufCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            // AddressBook.csで定義されているPresonクラスを実体化する
            Person person = new Person
            {
                Id = 1234,
                Name = "Yamada Tarou",
                Email = "yamada@sample.com",
                Phones = { new PhoneNumber { Number = "555-4321", Type = PhoneType.Home },
                    new PhoneNumber { Number = "222-1111", Type = PhoneType.Work } }
            };

            // 文字列にシリアライズ
            var data = Serialize(person);

            // シリアライズした文字列を読み込んでデシリアライズする
            Person someone = Deserialize<Person>(data);

            // 動作確認
            Console.WriteLine($"Id:{someone.Id}, Name:{someone.Name}, Email:{someone.Email}, " +
                $"Phones[0](Number:{someone.Phones[0].Number}, Type:{someone.Phones[0].Type}), " +
                $"Phones[1](Number:{someone.Phones[1].Number}, Type:{someone.Phones[1].Type})");

            Console.ReadKey();
        }

        static string Serialize<T>(T obj) where T : IMessage<T>
        {
            using (var stream = new MemoryStream())
            {
                obj.WriteTo(stream);
                return Encoding.UTF8.GetString(stream.ToArray());
            }
        }

        static T Deserialize<T>(string data) where T : IMessage<T>, new()
        {
            var parser = new MessageParser<T>(() => new T());
            return parser.ParseFrom(new MemoryStream(Encoding.UTF8.GetBytes(data)));
        }
    }
}
