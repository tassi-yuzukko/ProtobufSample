using System;
using System.IO;
using System.Text;
using Google.Protobuf;
using Google.Protobuf.Examples.AddressBook; // protoc.exeにより自動生成されたクラスの名前空間
using Google.Protobuf.WellKnownTypes;
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

            AddressBook addressBook = new AddressBook
            {
                People = { person },
                //FinishedAt = Timestamp.FromDateTime(DateTime.SpecifyKind(DateTime.Now, DateTimeKind.Utc)),
                FinishedAt = new Timestamp() { Seconds = 1999999 }
            };

            // 文字列にシリアライズ
            var data = Serialize(addressBook);

            // シリアライズした文字列を読み込んでデシリアライズする
            var address = Deserialize<AddressBook>(data);

            // 動作確認
            Console.WriteLine($"Id:{address.People[0].Id}, Name:{address.People[0].Name}, Email:{address.People[0].Email}, " +
                $"Phones[0](Number:{address.People[0].Phones[0].Number}, Type:{address.People[0].Phones[0].Type}), " +
                $"Phones[1](Number:{address.People[0].Phones[1].Number}, Type:{address.People[0].Phones[1].Type})," +
                $"Timestamp:{address.FinishedAt}");

            Console.ReadKey();
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
