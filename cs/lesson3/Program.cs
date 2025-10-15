using System.Net.Quic;
using System.Runtime.CompilerServices;

namespace lesson3;


class Program
{
    static void Program1()
    {
        Queue<int> nums = new Queue<int>();

        int startN = int.Parse(Console.ReadLine());

        for (int i = 0; i < startN; ++i)
        {
            try
            {
                nums.Enqueue(int.Parse(Console.ReadLine()));

            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                i--;
            }
        }

        bool is_PN_num = false;
        foreach (int n in nums)
        {
            if (n < 0 && !is_PN_num)
            {
                continue;
            }
            else
            {
                is_PN_num = true;
            }
            Console.Write(n + " ");
        }
    }

    static void Program2() {
        Queue<char> word = new Queue<char>();

        Stack<char> backword = new Stack<char>();

        string input = Console.ReadLine();

        foreach (char c in input) {
            word.Enqueue(c);
            backword.Push(c);
        }

        bool iseq = true;
        foreach (char c in backword)
        {
            if (c == word.Peek())
            {
                word.Dequeue();
            }
            else
            {
                Console.WriteLine("The word isn't polendrom");
                iseq = false;
                break;
            }
        }

        if (iseq)
        {
            Console.WriteLine("The word is polendrom");
        }
    }

    static void Main(string[] args)
    {


        Program2();
    }
}
