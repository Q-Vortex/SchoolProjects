using System.ComponentModel.DataAnnotations;
using System.Runtime.CompilerServices;
using System.Security.Principal;
using System.Threading.Tasks.Dataflow;

namespace lesson6;

class Program
{
    static void Program1()
    {
        string sym = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
        HashSet<char> chars = new HashSet<char>();
        string line = Console.ReadLine();

        foreach (char c in line)
        {
            if (!sym.Contains(c))
            {
                chars.Add(c);
            }
        }

        Console.WriteLine("Unic chars: ");
        Console.WriteLine(string.Join(", ", chars));
    }
    
    static void Program2()
    {
        List<double> nums = new List<double>();
        int idx = 1;
        while (true)
        {
            try
            {
                Console.Write("Type " + idx + " num or (e) to exit: ");
                double num = double.Parse(Console.ReadLine());
                nums.Add(num);
                idx++;
            }
            catch
            {
                // Console.WriteLine(e);
                break;
            }
        }

        for (int i = 0; i < nums.Count; ++i)
        {
            if (nums[i] < 0) nums.RemoveAt(i);
        }

        Console.Write("No negative nums: " + string.Join(", ", nums));
    }
    static void Main(string[] args)
    {
        Program2();
    }
}
