package LOCCounter;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        // Make sure that the file name is added as an argument.
        if(args.length < 1) {
            System.out.println("Please enter the file name after the name of this program.");
            return;
        }

        File file = new File(args[0]); // load the file
        int value = countLOC(file);  // store the value

        System.out.println(file.toString() + " = " + value + " LOC"); // Print the value with the function

    }

    static int countLOC(File file)    {
        // declarations for the function
        int lineCount = 0;
        boolean blockCom = false;
        String line = "";
        Scanner FileReader;

        // Open a Scanner with the file
        try {
            FileReader = new Scanner(file);

            // logic for counting the lines of code.
            while(FileReader.hasNextLine()) {
                line = FileReader.nextLine();

                while (!line.equals("")) { // loop through chars until it is equal to null.
                    if (lineCount == 24) {
                        int bacon = 3;
                    }
                    if (!blockCom) { // if the block comment flag is not true go through as normal

                        if (Character.isWhitespace(line.charAt(0))) { // if first is white space remove it and move on
                            line = line.substring(1);
                        }
                        else if (line.charAt(0) == '/') {
                            if (line.charAt(1) == '/') // double slash is at the beginning of the lien so its a comment
                                line = "";
                            else if (line.charAt(1) == '*') { // start block comment
                                if (line.contains("*/"))
                                    line = line.substring(line.indexOf("*/")+2);
                                else {
                                    blockCom = true; // activate block comment mode when scanning
                                    line = ""; // move on to the next line
                                }
                            }
                            else { // character is a part of code, increase line and check for the start of a block comment. Also checks if it ends.
                                lineCount++;
                                // check for block comment
                                if (line.contains("/*")) {
                                    if (line.contains("*/"))
                                        ; // no need to activate block comment mode as it ended in the same line
                                    else {
                                        blockCom = true; // activate block comment mode when scanning
                                    }
                                    line = ""; // move on to the next line
                                }
                            }

                        }
                        else { // the starting character is a normal character.
                            lineCount++;
                            if (line.contains("/*")) {
                                if (line.contains("*/"))
                                    ; // no need to activate block comment mode as it ended in the same line
                                else
                                    blockCom = true; // activate block comment mode when scanning
                            }

                            line = ""; // move on to the next line
                        }
                    }
                    else // block comment logic
                    {
                        if (line.contains("*/")) { // if the character "*/" is there cut of and turn off the block comment flag
                            line = line.substring(line.indexOf("*/")+2);
                            blockCom = false;
                        }
                        else
                            line = "";
                    }
                }
            }

            FileReader.close(); // close the file
        }

        catch (FileNotFoundException ex) { // print if the  file was not found
            System.out.println(ex.toString());
        }

        return lineCount; // return the count.
    }

}





// Check if line starts with the // if so discard the line.
// if the first character is not white space of a / then count it as a line of code.
// if first is white character go to the next space until the line ends.
// if there is a /* then mark all the next characters as comment until you get the */