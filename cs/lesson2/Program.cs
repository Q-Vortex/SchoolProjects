using System;
using System.Runtime.ExceptionServices;  // Namespace for basic system functions

// Namespace declaration
namespace MyApplication
{
    // Class declaration
    class Program
    {
        // Main method — entry point of the program
        static void Main(string[] args)
        {
            Stack<int> stiva = new Stack<int>();

            int n = int.Parse(Console.ReadLine());

            while (n > 0)
            {
                stiva.Push(n % 2);
                n /= 2;
            }

            foreach (int num in stiva)
            {
                Console.Write(num);
            }
        }
    }
}
