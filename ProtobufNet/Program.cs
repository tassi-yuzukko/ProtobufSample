using ProtoBuf;
using System;

namespace ProtobufNet
{
    class Program
    {
        static void Main(string[] args)
        {
            DeserializeSt(@"C:\Users\kei\Documents\git\ProtobufSample\ProtobufSample2\serialize_data.dat");

            DeserializeAddressBook(@"C:\Users\kei\Documents\git\ProtobufSample\ProtobufCsharp\john.dat");
        }

        static void DeserializeSt(string filename)
        {
            // デシリアライズ
            St st = Serializer.Deserialize<St>(new System.IO.FileStream(
                filename,
                System.IO.FileMode.Open,
                System.IO.FileAccess.Read));

            Console.WriteLine("Read Success !!");
            Console.WriteLine($"A:{st.A}, B:{st.B}, C:{st.C}, D:{st.D}, Child.X:{st.Child.X}, Child.Y:{st.Child.Y}");
            foreach (var item in st.Dict)
            {
                Console.WriteLine($"key:{item.Key}, value:{item.Value}");
            }
            Console.ReadLine();
        }

        static void DeserializeAddressBook(string filename)
        {
            // デシリアライズ
            AddressBook address = Serializer.Deserialize<AddressBook>(new System.IO.FileStream(
                filename,
                System.IO.FileMode.Open,
                System.IO.FileAccess.Read));

            Console.WriteLine("Read Success !!");
            Console.WriteLine($"Id:{address.People[0].Id}, Name:{address.People[0].Name}, Email:{address.People[0].Email}, " +
                $"Phones[0](Number:{address.People[0].Phones[0].Number}, Type:{address.People[0].Phones[0].Type}), " +
                $"Phones[1](Number:{address.People[0].Phones[1].Number}, Type:{address.People[0].Phones[1].Type}),");
            Console.ReadLine();
        }
    }
}
