using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace linear_search
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter numbers: ");

            int[] numbers = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

            Console.WriteLine("Enter number to search for: ");
            int number = int.Parse(Console.ReadLine());

            for (int i = 0; i < numbers.Count(); i++)
            {
                if (numbers[i] == number)
                {
                    Console.WriteLine("Number found at position " + i);
                    Environment.Exit(0);
                }
            }

            Console.WriteLine("Number not found");
        }
    }
}
