using System.Diagnostics.Contracts;
using System.Numerics;
using System.Security.AccessControl;

namespace laborator4;

class Program
{

    struct Parseto
    {
        public int[] Bin(int n)
        {
            int[] bits = new int[8];
            int i = 0;

            if (n > 127 || n < -128)
            {
                Console.WriteLine("Num is out of range...");
                return bits;
            }

            int mn = Math.Abs(n);

            while (mn != 0)
            {
                bits[i] = mn % 2;
                mn /= 2;
                i++;
            }

            bits[7] = n < 0 ? 1 : 0;

            return bits;
        }

        public int Num(ref int[] bits)
        {
            int num = 0;

            for (int i = 0; i < bits.Length - 1; ++i)
            {
                num += bits[i] * (1 << i);
            }

            if (bits[7] == 1) num = -num;

            return num;
        }
    }
    
    static void changeBit(ref int[] bits)
    { 
        Console.Write("Get idx: ");
        int idx = int.Parse(Console.ReadLine());

        Console.Write("Get bit: ");
        int bit = int.Parse(Console.ReadLine());

        bits[idx] = bit;
    }

    static void getBits(ref int[] bits)
    {
        foreach (int b in bits)
        {
            Console.Write(b);
        }
        Console.WriteLine();
    }

    static void changeNum(ref int num)
    {
        num = int.Parse(Console.ReadLine());
    }

    static void BinToText(string bits)
    {
        string word = "";
        foreach (char c in bits)
        {
            if (c == ' ')
            {
                Console.Write(word + " ");
                continue;
            }
            word += c;
        }
    }

    static void TextToBin()
    {
        string line = Console.ReadLine();
        Parseto parseto;
        string bits = "";
        foreach (char c in line)
        {
            foreach (int bit in parseto.Bin((int)c))
                bits += bit;
            bits += " ";
        }
        Console.WriteLine(bits);

    }

    static void actions(int n, ref int num, ref int[] bits)
    {
        switch (n)
        {
            case 1: changeNum(ref num); break;
            case 2: getBits(ref bits); break;
            case 3: changeBit(ref bits); break;
            case 4: TextToBin(); break;
            default: Console.WriteLine("Invalied action"); break;
        }
    }
    static void Main(string[] args)
    {
        Parseto parseto;
        Console.Write("Get num: ");
        int num = int.Parse(Console.ReadLine());


        int[] bits = parseto.Bin(num);

        Console.WriteLine("Choise action: ");
        Console.WriteLine("1 - Change num.");
        Console.WriteLine("2 - Show bits.");
        Console.WriteLine("3 - Change bit.");
        Console.WriteLine("4 - Transform text in bits.");

        actions(int.Parse(Console.ReadLine()), ref num, ref bits);

        foreach (int b in bits)
        {
            Console.Write(b);
        }
        Console.WriteLine();
    }
}
