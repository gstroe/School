using System;
using System.Collections.Generic;

namespace cStringFunctions
{
    class Program
    {
        static void Main(string[] args)
        {
            // just a list to contain the samples of strings to run through the gauntlet
            List<string> stringList = new List<string>();
            stringList.Add("Hello!");
            stringList.Add("String");
            stringList.Add("ZZZzzz");
            stringList.Add("This is a program.");
            stringList.Add("The shark is in the water!#@$!");
            stringList.Add("is Ok");
            stringList.Add("Good Bye!");


            // tests the string lengths
            Console.WriteLine("String Lengths:");
            for (int i = 0; i < stringList.Count; i++)
            {
                Console.WriteLine(stringList[i] + " = " + stringList[i].myStrlen());
            }
            Console.WriteLine();

            // tests the string catenate
            Console.WriteLine("String Catenate with Bacon:");
            for (int i = 0; i < stringList.Count; i++)
            {
                string tempText = stringList[i];
                Console.Write(tempText + " = ");
                tempText = tempText.myStrcat("Bacon");
                Console.WriteLine(tempText);
            }
            Console.WriteLine();

            // tests the string cpy
            Console.WriteLine("String copy with Bacon:");
            for (int i = 0; i < stringList.Count; i++)
            {
                string tempText = stringList[i];
                Console.Write(tempText + " = ");
                tempText = tempText.myStrcpy("Bacon"); // prints the string that was copied
                Console.WriteLine(tempText);
            }
            Console.WriteLine();

            // tests the string cpy with n
            Console.WriteLine("String copy with length with Bacon:");
            for  (int i=0; i<stringList.Count; i++)
            {
                string tempText = stringList[i];
                Console.Write(tempText + " = ");
                tempText = tempText.myStrcpy("Bacon",2+i) + "<-\'where the new string ended\'";
                Console.WriteLine(tempText);
            }
            Console.WriteLine();

            // tests the string cmp
            Console.WriteLine("String cmp with String");
            for (int i = 0; i < stringList.Count; i++)
            {
                string tempText = stringList[i];
                Console.WriteLine(tempText + " = " + tempText.myStrcmp("String"));
            }
            Console.WriteLine();

            // tests the strstr with 'is'
            Console.WriteLine("strstr index return with \'is\'");
            for (int i = 0; i < stringList.Count; i++)
            {
                string tempText = stringList[i];
                Console.WriteLine(tempText + " = " + tempText.myStrstr("is"));
            }
            Console.WriteLine();

            // tests the strstr with 'is'
            Console.WriteLine("strstr replace with \'is\' to \'are\'");
            for (int i = 0; i < stringList.Count; i++)
            {
                string tempText = stringList[i];
                Console.WriteLine(tempText + " = " + tempText.myStrstrReplace("is", "are"));
            }
            Console.WriteLine();

            Console.ReadKey();
        }
    }

    /// <summary>
    /// extentions class that can be performed on the current string. 
    /// I am using this instead of tradition methods as a part of the program class as it is more inline with the C# programming style
    /// all of my functions will have 'my' infront to distigush between any functions in the standard string library and the ones I created.
    /// </summary>
    public static class StringExtension
    {
        /// <summary>
        /// Returns the length of the string
        /// </summary>
        /// <returns>Length of String</returns>
        public static int myStrlen(this string text)
        {
            int length = 0;
            
            //using the foreach function to loop through and count the number of characters
            foreach (char c in text)
            {
                length++; // increment
            }

            return length; // return the count
        }

        /// <summary>
        /// Returns a string with the added string at the end
        /// </summary>
        /// <param name="text"> This String</param>
        /// <param name="addedText"> String ro be catenated</param>
        /// <returns>Returns the new string</returns>
        public static string myStrcat(this string text, string addedText)
        {
            // In C# strings can just be added together just like literals
            text = text + addedText;

            return text; // returns the new text
        }

        /// <summary>
        /// Trivial with C# since strings can just be set to equal the value of another string
        /// </summary>
        /// <param name="text">This String</param>
        /// <param name="newText"> This is the string that is returned</param>
        /// <returns>The new Text</returns>
        public static string myStrcpy(this string text, string newText)
        {
            return newText;
        }

        /// <summary>
        /// overloaded method
        /// Trivial with C# since strings can just be set to equall the value of another string
        /// Added a parameter that specifies how much of the string to print
        /// </summary>
        /// <param name="text">This String</param>
        /// <param name="newText"> This is the string that is returned</param>
        /// /// <param name="n"> the amount of the second string to return</param>
        /// <returns>The new Text</returns>
        public static string myStrcpy(this string text, string newText, int n)
        {   
            // initiated the string 
            string temp = "";

            for (int i=0; i<n; i++)
            {
                // check to see if string has char or pad zero
                if (i < newText.myStrlen())
                {
                    temp += newText[i];
                }
                else
                {
                    temp += '\0';
                }
            }

            return temp;
        }

        /// <summary>
        /// Compares the Strings, returns 0 if they are the same
        /// returns a negitive number it the values of cmpText is larger
        /// returns a positive number if the values of cmpText is smaller
        /// </summary>
        /// <param name="text"></param>
        /// <param name="cmpText"></param>
        /// <returns>The comparison</returns>
        public static int myStrcmp(this string text, string cmpText)
        {
            int val1 = 0; // The value of the text for text
            int val2 = 0; // the value of the text for cmpText
            // sum each string
            foreach (char c in text)
            {
                val1 += c;
            }
            foreach (char c in cmpText)
            {
                val2 += c;
            }

            return val1-val2; // return the comparison
        }

        /// <summary>
        /// because C# with the garbage collector it is unsafe just return a pointer to the fucntion. THis is considered a bad programming method for C#.
        /// So instead to return some of the same features I will return the index of the substring in  the main string.
        /// Also added my myStrstrReplace which sorta fufilles the role for strstr
        /// note this only retursn the first index of this
        /// </summary>
        /// <param name="text"> This string</param>
        /// <param name="subText">The substring</param>
        /// <returns>Returns the index or -1 if the substring is not found</returns>
        public static int myStrstr(this string text, string subText)
        {
            bool check = false; // fro breaknig out if the loop if the substring is found
            for(int i=0; i<text.myStrlen(); i++) // count through the list
            {
                if (text[i] == subText[0]) // if the first character is found
                {
                    check = true;
                    for (int j = 0; j < subText.myStrlen(); j++)
                    {
                        if(text[i+j] != subText[j])
                        {
                            check = false;
                            break; // not the substring so break
                        }

                    }

                    if (check) // found it! so break and return index
                    {
                        return i;
                    }

                }
            }

            return -1; // didnt find so return one
        }

        /// <summary>
        /// To round out one of the man uses for strstr this replace function will replace the substring.
        /// </summary>
        /// <param name="text"> This string</param>
        /// <param name="subText">The substring</param>
        /// <param name="replaceText">The to replace</param>
        /// <returns>Returns the new string or the old one if the substring is not found</returns>
        public static string myStrstrReplace(this string text, string subText, string replaceText)
        {
            bool check = false; // fro breaknig out if the loop if the substring is found
            for (int i = 0; i < text.myStrlen(); i++) // count through the list
            {
                if (text[i] == subText[0]) // if the first character is found
                {
                    check = true;
                    int j = 0;
                    for (j = 0; j < subText.myStrlen(); j++)
                    {
                        if (text[i + j] != subText[j])
                        {
                            check = false;
                            break; // not the substring so break
                        }

                    }

                    if (check) // found it! so break and return index
                    {
                        string str1 = "";
                        for(int k=0; k < i; k++) // get the first part of the old string
                        {
                            str1 += text[k];
                        }

                        string str2 = "";
                        for(int k = i+j; k < text.myStrlen(); k++) // the last half of the string
                        {
                            str2 += text[k];
                        }

                        return str1 + replaceText + str2; // return the combination
                    }

                }
            }

            return text; // didnt find so return old text
        }
    }
}