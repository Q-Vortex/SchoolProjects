namespace laboratory7;

class Program
{

    static void Program1()
    {
        int n;
        n = int.Parse(Console.ReadLine());
        List<int> nums = new List<int>();

        for (int i = 0; i < n; ++i)
        {
            int input = int.Parse(Console.ReadLine());
            nums.Add(input);
        }

        foreach (int num in nums)
        {
            double f = Math.Sqrt(num);
            if (f - (int)f == 0)
            {
                Console.Write(num + " ");
            }
        }
    }

    static void Program2()
    {
        int n;
        n = int.Parse(Console.ReadLine());
        List<string> nums = new List<string>();

        for (int i = 0; i < n; ++i)
        {
            string input = Console.ReadLine();
            nums.Add(input);
        }

        foreach (string num in nums)
        {
            if (num[0] == num[num.Length - 1])
            {
                Console.Write(num + " ");
            }
        }
    }
    
    static void Main(string[] args)
    {
        Program2();
    }
} 