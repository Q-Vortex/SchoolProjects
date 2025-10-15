using System.Globalization;

namespace laborator2;

class Program
{

    static void Program1()
    {
        Console.Write("Write an sentence: ");
        string input = Console.ReadLine();
        Stack<string> smallsizewords = new Stack<string>();
        Stack<string> bigsizewords = new Stack<string>();

        if (input == null) return;

        string[] words = input.Split(' ');

        foreach (string word in words)
        {
            if (word.Length >= 6)
            {
                bigsizewords.Push(word);
            }
            else
            {
                smallsizewords.Push(word);
            }
        }

        Console.WriteLine("Words with lenght up to 6:");
        foreach (string word in smallsizewords)
        {
            Console.WriteLine(word);
        }

        Console.WriteLine("Words with lenght over 6:");
        foreach (string word in bigsizewords)
        {
            Console.WriteLine(word);
        }
    }

    static void Program2()
    {
        Console.Write("Write an sentence: ");
        string input = Console.ReadLine().ToLower();
        Stack<string> samecharswords = new Stack<string>();
        Stack<string> diferensecharwords = new Stack<string>();

        if (input == null) return;

        string[] words = input.Split(' ');

        foreach (string word in words)
        {
            int lastcharidx = word.Length - 1;

            if (word[0] == word[lastcharidx])
            {
                samecharswords.Push(word);
            }
            else if (word[0] != word[lastcharidx])
            {
                diferensecharwords.Push(word);
            }
        }

        Console.WriteLine("Words with same letters:");
        foreach (string word in samecharswords)
        {
            Console.WriteLine(word);
        }

        Console.WriteLine("Words without same letters:");
        foreach (string word in diferensecharwords)
        {
            Console.WriteLine(word);
        }
    }

    static void Program3()
    {
        Console.Write("Get array size: ");
        int n = int.Parse(Console.ReadLine());
        int[] nums = new int[n];
        
        for (int i = 0; i < nums.Length; ++i)
        {
            try
            {
                Console.Write("Num: ");
                nums[i] = int.Parse(Console.ReadLine());
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                i--;
            }
            
        }

        Stack<int> evennums = new Stack<int>();
        Stack<int> oddnums = new Stack<int>();

        foreach (int num in nums)
        {
            if (num % 2 == 0)
            {
                evennums.Push(num);
            }
            else if (num % 2 != 0)
            {
                oddnums.Push(num);
            }
        }

        Console.WriteLine("Even nums:");
        foreach (int num in evennums)
        {
            Console.WriteLine(num);
        }

        Console.WriteLine("Odd nums:");
        foreach (int num in oddnums)
        {
            Console.WriteLine(num);
        }
    }
    static void Main(string[] args)
    {
        Program3();
    }
}
