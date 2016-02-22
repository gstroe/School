using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace ThreadingProgram
{
    class Program
    {
        // Global Definitions
        static string input;
        static int[] numList;
        static double avg;
        static int max, min;
        static Thread avgThread, maxThread, minThread;

        /// <summary>
        /// The main functions of the program.
        /// Currently the parameters do nothing.
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            // Prompt the user to imput a series of numbers represented with a space in between.
            Console.WriteLine("Hello! This program takes in a series of numbers and perform calculations on them.");
            Console.WriteLine("Please Enter a series of int each seperated by a space, any none integer values will not be counted:");

            // read the user input
            input = Console.ReadLine();
            Console.WriteLine("Valid Entries:");

            // parse through data and get total entered
            int index1 = 0, index2 = 0, totalEntered = 0;
            for (int i = 0; i < input.Length; i++)
            {
                int temp = 0; // just for parse function
                if (input[i] == ' ')
                {
                    index2 = i; // mark the entry endpoint
                    if (int.TryParse(input.Substring(index1, index2 - index1), out temp)) // see if it can be parsed into a string
                    {
                        totalEntered++;
                        Console.WriteLine(temp);
                        
                    }
                    index1 = index2 + 1;                    
                }

                if (i == input.Length - 1) // does it one last time to count the last value if its the last number
                {
                    if (int.TryParse(input.Substring(index2, input.Length - index2), out temp)) // see if it can be parsed into a string
                    {
                        totalEntered++;
                        Console.WriteLine(temp);

                    }
                }
            }
            // output the total valid entries
            Console.WriteLine("Total entered: " + totalEntered + "\r\n");

            // error handling for zero inputs
            if (totalEntered == 0)
                totalEntered = 1;

            // Same steps insert the numbers in the table
            numList = new int[totalEntered];
            index1 = 0;
            index2 = 0;
            int j = 0; // for countin the int array
            for (int i = 0; i < input.Length; i++)
            {
                int temp = 0; // just for parse function
                if (input[i] == ' ')
                {
                    index2 = i; // mark the entry endpoint
                    if (int.TryParse(input.Substring(index1, index2 - index1), out temp)) // see if it can be parsed into a string
                    {
                        numList[j] = temp;
                        j++;
                    }
                    index1 = index2 + 1;
                }

                if (i == input.Length - 1) // does it one last time to count the last value if its the last number
                {
                    if (int.TryParse(input.Substring(index2, input.Length - index2), out temp)) // see if it can be parsed into a string
                    {
                        numList[j] = temp;
                        j++;
                    }
                }
            }


            // create the threads for calculateing the results and starts them
            avgThread = new Thread(new ThreadStart(avgThreadFunc));
            maxThread = new Thread(new ThreadStart(maxThreadFunc));
            minThread = new Thread(new ThreadStart(minThreadFunc));
            avgThread.Start();
            maxThread.Start();
            minThread.Start();

            // waits for all the threads to finish and then continues with this main method
            avgThread.Join();
            maxThread.Join(); // ----- comment out to see proof for all threads runing indepentely
            minThread.Join();

            // print the results
            Console.WriteLine("The Average: " + avg);
            Console.WriteLine("The Maximum: " + max);
            Console.WriteLine("The Minimum: " + min);

            // read key to exit program
            Console.WriteLine("\nPress any key to exit.");
            Console.ReadKey();
        }


        /// <summary>
        /// The thread method that gets the average value
        /// </summary>
        static public void avgThreadFunc()
        {
            double temp = 0;
            for (int i = 0; i < numList.Length; i++)
                temp += numList[i];

            avg = temp / numList.Length;
        }

        /// <summary>
        /// The thread method that gets the max value
        /// </summary>
        static public void maxThreadFunc()
        {
//            Thread.Sleep(3000);     // ----- Uncomment to see proof for all threads runing indepentely
            int temp = numList[0];
            for (int i = 1; i < numList.Length; i++)
            {
                if (numList[i] > temp)
                    temp = numList[i];
            }
            max = temp;
        }

        /// <summary>
        /// The thread method that gets the min value
        /// </summary>
        static public void minThreadFunc()
        {
            int temp = numList[0];
            for (int i = 1; i < numList.Length; i++)
            {
                if (numList[i] < temp)
                    temp = numList[i];
            }
            min = temp;
        }
    }
}
