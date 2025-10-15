using System;

class Program
{
    static void Main(string[] args)
    { 
        List<int> nums = new List<int>();

        while (true) {
            try {
                Console.Write("Write an num, type (e) for exit: ");
                int num = int.Parse(Console.ReadLine());
                nums.Add(num);
            } catch (Exception) {
              break;
            }
        }
        
        List<int> dzero = new List<int>();
        int maxInum = 0;
        int num = nums[i];

        for (int i = 0; i < nums.Count; ++i) {
            if (num != 0) dzero.Add(num);
            
            if (num % 2 == 0 && maxInum < num)
                maxInum = num;
            
            if (num < 0) dzero[i] = 0 - num;
        }

        Console.Write("d-zero: { ");
        foreach (var num in dzero) {
            Console.Write(num + " ");
        }
        Console.Write("}\n");

        Console.WriteLine("Max num: " + maxInum);
        Console.WriteLine();
        
        Console.Write("Changet List: { ");
        foreach (var num in nums) {
            Console.Write(num + " ");
        }
        Console.Write("}\n");
    }
} 