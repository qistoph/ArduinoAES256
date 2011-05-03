using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Security.Cryptography;

namespace Aes256Decrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            Aes aes = Aes.Create();
            aes.Key = new byte[] {
                0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
            };
            aes.IV = new byte[] {
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };
            aes.Mode = CipherMode.ECB;
            aes.Padding = PaddingMode.None;
            ICryptoTransform decrypter = aes.CreateDecryptor();

            byte[] buffer = new byte[] {
                0x02, 0x41, 0x17, 0xFD, 0x2E, 0x73, 0x71, 0x45,
                0x58, 0x2C, 0x97, 0x6F, 0x47, 0xBE, 0xDA, 0x20
            };

            buffer = decrypter.TransformFinalBlock(buffer, 0, buffer.Length);
            Console.WriteLine(ASCIIEncoding.ASCII.GetString(buffer));
            Console.ReadLine();
        }
    }
}
