using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace binary_search
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter numbers: ");

            int[] numbers = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

            Console.WriteLine("Enter number to search for: ");
            int number = int.Parse(Console.ReadLine());

            int minI = 0, maxI = numbers.Count(), numberI = -1;
            while (minI <= maxI)
            {   
                int middle = (minI + maxI) / 2;
                if (number == numbers[middle])
                {
                    numberI = middle;
                    break;
                }                
                else if (number > numbers[middle])
                    minI = middle + 1;
                else
                    maxI = middle - 1;
            }

            Console.WriteLine(numberI == -1 ? "Number not found" : "Number found at position " + numberI);
            Console.ReadLine();
        }
    }
}
