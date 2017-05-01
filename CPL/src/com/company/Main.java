package com.company;
// library's for lists
import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        // just a list to contain the samples of Strings to run through the gauntlet
        ArrayList<String> StringList = new ArrayList<String>();
        StringList.add("Hello!");
        StringList.add("String");
        StringList.add("ZZZzzz");
        StringList.add("This is a program.");
        StringList.add("The shark is in the water!#@$!");
        StringList.add("is Ok");
        StringList.add("Good Bye!");

        // tests the String lengths
        System.out.println("String Lengths:");
        for (int i = 0; i < StringList.size(); i++)
        {
            System.out.println(StringList.get(i) + " = " + myString.myStrlen(StringList.get(i)));
        }
        System.out.println();

        // tests the String catenate
        System.out.println("String Catenate with Bacon:");
        for (int i = 0; i < StringList.size(); i++)
        {
            String tempText = StringList.get(i);
            System.out.print(tempText + " = ");
            tempText = myString.myStrcat(tempText,"Bacon");
            System.out.println(tempText);
        }
        System.out.println();

        // tests the String cpy
        System.out.println("String copy with Bacon:");
        for (int i = 0; i < StringList.size(); i++)
        {
            String tempText = StringList.get(i);
            System.out.print(tempText + " = ");
            tempText = myString.myStrcpy(tempText,"Bacon"); // prints the String that was copied
            System.out.println(tempText);
        }
        System.out.println();

        // tests the String cpy with n
        System.out.println("String copy with length with Bacon:");
        for  (int i=0; i<StringList.size(); i++)
        {
            String tempText = StringList.get(i);
            System.out.print(tempText + " = ");
            tempText = myString.myStrcpy(tempText,"Bacon",2+i) + "<-\'where the new String ended\'";
            System.out.println(tempText);
        }
        System.out.println();

        // tests the String cmp
        System.out.println("String cmp with String");
        for (int i = 0; i < StringList.size(); i++)
        {
            String tempText = StringList.get(i);
            System.out.println(tempText + " = " + myString.myStrcmp(tempText,"String"));
        }
        System.out.println();

        // tests the strstr with 'is'
        System.out.println("strstr index return with \'is\'");
        for (int i = 0; i < StringList.size(); i++)
        {
            String tempText = StringList.get(i);
            System.out.println(tempText + " = " + myString.myStrstr(tempText,"is"));
        }
        System.out.println();

        // tests the strstr with 'is'
        System.out.println("strstr replace with \'is\' to \'are\'");
        for (int i = 0; i < StringList.size(); i++)
        {
            String tempText = StringList.get(i);
            System.out.println(tempText + " = " + myString.myStrstrReplace(tempText,"is", "are"));
        }
        System.out.println();
    
        // read input to pause program
        Scanner input = new Scanner(System.in);
        String data = input.nextLine();;
    }

    // an abstract class containing these functions. Since string class is final I cannot extend the current string class so an aditional calss is need to perform these
    public static abstract class myString
    {
        // Returns the length of the String
        public static int myStrlen(String text)
        {
            int length = 0;

            //using the foreach function equivalent for java to loop through and count the number of characters
            for(char c : text.toCharArray()) // change to character array for for loop to work
            {
                length++; // increment
            }

            return length; // return the count
        }

        // Returns a String with the added String at the end
        public static String myStrcat(String text, String addedText)
        {
            // In java Strings can just be added together just like literals
            text = text + addedText;

            return text; // returns the new text
        }

        // Trivial with Java since Strings can just be set to equal the value of another String
        public static String myStrcpy(String text, String newText)
        {
            return newText;
        }

        // overloaded method
        // Trivial with Java since Strings can just be set to equal the value of another String
        // Added a parameter that specifies how much of the String to print
        public static String myStrcpy(String text, String newText, int n)
        {
            // initiated the String
            String temp = "";

            for (int i=0; i<n; i++)
            {
                // check to see if String has char or pad zero
                if (i < myStrlen(newText))
                {
                    temp += newText.charAt(i);
                }
                else
                {
                    temp += '\0';
                }
            }

            return temp;
        }

        // Compares the Strings, returns 0 if they are the same
        // returns a negitive number it the values of cmpText is larger
        // returns a positive number if the values of cmpText is smaller
        public static int myStrcmp(String text, String cmpText)
        {
            int val1 = 0; // The value of the text for text
            int val2 = 0; // the value of the text for cmpText
            // sum each String
            for(int i=0; i<myStrlen(text); i++)
            {
                val1 += text.charAt(i);
            }
            for(int i=0; i<myStrlen(cmpText); i++)
            {
                val2 += cmpText.charAt(i);
            }

            return val1-val2; // return the comparison
        }

        // So java does not allow for arthritic with pointers since everything in java is a reference to an object.
        // This means like in c# we will need to simulate and make an equivalent to the pointer for java. So we will use the index of the beginning of the substring
        // Also for a second function the myStrstrReplace replaces the substrings which is one of the most common usage of C++'s strstr()
        public static int myStrstr(String text, String subText)
        {
            boolean check = false; // fro breaknig out if the loop if the subString is found
            for(int i=0; i<myStrlen(text); i++) // count through the list
            {
                if (text.charAt(i) == subText.charAt(0)) // if the first character is found
                {
                    check = true;
                    for (int j = 0; j < myStrlen(subText); j++)
                    {
                        if(text.charAt(i+j) != subText.charAt(j))
                        {
                            check = false;
                            break; // not the subString so break
                        }
                    }
                    if (check) // found it! so break and return index
                    {
                        return i;
                    }

                }
            }

            return -1; // didn't find so return one
        }


        // To round out one of the man uses for strstr this replace function will replace the subString.
        public static String myStrstrReplace(String text, String subText, String replaceText)
        {
            boolean check = false; // fro breaking out if the loop if the subString is found
            for (int i = 0; i < myStrlen(text); i++) // count through the list
            {
                if (text.charAt(i) == subText.charAt(0)) // if the first character is found
                {
                    check = true;
                    int j = 0;
                    for (j = 0; j < myStrlen(subText); j++)
                    {
                        if (text.charAt(i + j) != subText.charAt(j))
                        {
                            check = false;
                            break; // not the subString so break
                        }

                    }

                    if (check) // found it! so break and return index
                    {
                        String str1 = "";
                        for(int k=0; k < i; k++) // get the first part of the old String
                        {
                            str1 += text.charAt(k);
                        }

                        String str2 = "";
                        for(int k = i+j; k < myStrlen(text); k++) // the last half of the String
                        {
                            str2 += text.charAt(k);
                        }

                        return str1 + replaceText + str2; // return the combination
                    }

                }
            }

            return text; // didnt find so return old text
        }
    }

}

