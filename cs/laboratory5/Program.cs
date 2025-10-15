using System.ComponentModel;
using System.Runtime.Versioning;
using System.Security.AccessControl;
using System.Security.Cryptography;

namespace lesson5;


class Program
{
    static HashSet<string> HashSplit(ref string line)
    {
        HashSet<string> words = new HashSet<string>();
        string word = "";

        foreach (char c in line)
        {


            if (c == ' ' && word != "")
            {
                words.Add(word);
                word = "";
                continue;
            }
            word += c;
        }

        if (word != "") words.Add(word);

        return words;
    }

    static void Program1()
    {
        string line = Console.ReadLine();
        HashSet<String> words = HashSplit(ref line);


        foreach (string word in words)
        {
            Console.WriteLine(word);
        }
    }

    static void Program2()
    {
        string line_1 = Console.ReadLine().ToLower();
        string line_2 = Console.ReadLine().ToLower();

        HashSet<string> words_line_1 = HashSplit(ref line_1);
        HashSet<string> words_line_2 = HashSplit(ref line_2);

        var all_words = words_line_1.Union(words_line_2);
        var intersection_words = words_line_1.Intersect(words_line_2);

        Console.WriteLine("All words which are in both sentences: ");
        foreach (string word in all_words)
        {
            Console.Write(word + "; ");
        }
        Console.WriteLine();

        Console.WriteLine("Words which are in both sentences: ");
        foreach (string word in intersection_words)
        {
            Console.Write(word + "; ");
        }
        Console.WriteLine();

        Console.WriteLine("Words from first sentence which aren't in secod sentence: ");
        foreach (string word in words_line_1)
        {
            if (!intersection_words.Contains(word))
                Console.Write(word + "; ");
        }
        Console.WriteLine();

    }
    
    static void Program3()
    {
        string line_1 = Console.ReadLine().ToUpper();
        string line_2 = Console.ReadLine().ToUpper();
        
        HashSet<string> A = HashSplit(ref line_1);
        HashSet<string> B = HashSplit(ref line_2);

        var unification = A.Union(B);
        var intersection = A.Intersect(B);
        var difference = A.Except(intersection);

        foreach (string el in unification)
        {
            Console.Write(el + " ");
        }
        Console.WriteLine();

        foreach (string el in intersection)
        {
            Console.Write(el + " ");
        }
        Console.WriteLine();

        foreach (string el in difference)
        {
            Console.Write(el + " ");
        }
        Console.WriteLine();
    }

    static void Main(string[] args)
    {
        Program3();
    }
}
