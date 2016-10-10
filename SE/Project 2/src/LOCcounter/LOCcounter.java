package LOCcounter;


import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

///////////////////////////////////////////////////////////////////////////
//
// Module Name:   LOCcounter.java
//
// Module Description:
// This program is designed to count the number of lines of code in a file
//   and display them onto the screen. If the file does not exist it will just
//   end the execution of the program without error.
// This is an edit from the original program that has just the basic
//   components and is platform independent.
// This program will now also count the number of ,lines in each function.
//
///////////////////////////////////////////////////////////////////////////
//
// Author:          Nathan McCollister, Benjamin Sweet, Gary Givental, Gabriel Stroe
// Revision:        2.1
// Creation Date:   28-May-2014
// Edit Date:       26-Sep-2016
//
///////////////////////////////////////////////////////////////////////////
//
// Revision History:
//
// Revision: 2.3    26-Sep-2016   Gabriel Stroe
//   -- added in the functionality to filter through comments in the countFuncLOC function.
//
// Revision: 2.2    26-Sep-2016   Gabriel Stroe
//   -- Fixed an issues where the counting function did not count the first line of code per function
//
// Revision: 2.1    25-Sep-2016   Gabriel Stroe
//   -- Fixed an issues where the counting of the entire file would cause the functions not to read as it was at the end of the file.
//
// Revision: 2.0    25-Sep-2016   Gabriel Stroe
//   -- redesigned the countLOC function to accept a buffered reader as an input so  countFuncLOC could pass it for it to count.
//   -- added countFuncLOC to count the number of lines in a specific function. It separate the function test and then passes it to countLOC
//
// Revision: 1.3    03-Sep-2016   G. Givental
//   -- added the handling for comment inside a comment block as found by Prof. Swee
//
//
// Revision: 1.2    14-Feb-2016   G. Givental
//   -- fixed the class name to be "LOCcounter" so that it matches the name of the file itself
//   -- fixed File checking
//   -- modified countLOC to take a "File" object as a parameter
//
//
// Revision: 1.1    06-Feb-2016   B. Sweet
// * Revised where and how iTotalLOC is incremented to provide more obvious
//   "state" behavior.
// * Resolved error in which a line containing only '*' would be counted as LOC.
//
// Revision: 1.0    28-May-2014   Nathan McCollister
// * Original version.
//
///////////////////////////////////////////////////////////////////////////

public class LOCcounter {

    public static void main(String[] args) {
        // The list for all of the functions
        List<FunctionData> FunctionList = new ArrayList<FunctionData>();

        // read the user provided file name for where to count LOC
        String sFileName;
        Scanner in = new Scanner(System.in);
        System.out.print("Please enter the file name:   ");
        sFileName = in.nextLine();
        in.close();

        // now that we have the filename, verify that this is a valid file
        File file = new File(sFileName);

        if (!file.exists()) {
            System.out.format("File %s does not exist.", sFileName);
            return;
        }

        // now that we know we have a file that exists,
        // call our countLOC method, passing in the File as the arg
        // and let it run
        // we might still get an exception reading a "bad" file
        // so make sure to catch it here
        try {
            int fileLOC = countFuncLOC(file, FunctionList);
            System.out.format("filename:  %s\n LOC:  %d\n\n", sFileName, fileLOC);

            // print the function lines of code
            for(int i = 0; i < FunctionList.size(); i++) {
                System.out.format("Function Name:  %s\n LOC:  %d\n\n", FunctionList.get(i).functionName, FunctionList.get(i).functionLOC);
            }
        }
        catch (IOException e) {
            System.out.format("Error reading file %s: %s", sFileName, e.getMessage());
        }
    }


    /**
     *
     * @param reader Gets the reader from the countFuncLOC (change from file to count the functions as well)
     * @return the total number of lines for that section
     * @throws IOException
     */
    public static int countLOC(BufferedReader reader) throws IOException{
        boolean bContinueThisLine = true;   // a flag to determine if the loop should continue searching the current line.
        boolean bBlockComment = false;      // a flag to determine if the program is currently inside of a block comment.
        boolean bIsLOC = false;             // a flag to indicate that the current line IS a Line of Code.
        int iTotalLOC = 0;                  // count of Total LOC found in the file.


        String sReadLine = reader.readLine();   // Get first line in file

        while (sReadLine != null) {
            bContinueThisLine = true;           // reset to true at the beginning of each new line
            for (int i = 0; (i < sReadLine.length()) && (sReadLine.charAt(i) != '\n') && (bContinueThisLine); i++) // a loop to scan each line character by character
            {
                switch (sReadLine.charAt(i)) {
                    case '/':                     // if it starts with an '/' then check if it is a line comment, block comment, or neither
                        if (!bBlockComment)  // If NOT in a block comment, check for beginning of comment
                        {
                            if (i < sReadLine.length() - 1) {
                                if (sReadLine.charAt(i + 1) == '/')     // This is a C++ line comment
                                {
                                    bContinueThisLine = false;          //   Get the next line
                                }
                                else if (sReadLine.charAt(i + 1) == '*')// This is a C block comment
                                {
                                    bBlockComment = true;
                                    i++;                                // Already evaluated next character so don't evaluate it again
                                }
                                else                                    // '/' that is NOT part of a comment delimiter indicates this IS a Line of Code
                                {
                                    bIsLOC = true;


                                }
                            }
                        }
                        else // In a Block Comment
                        {
                            // Ignore the '/' character.  Logic is looking ONLY for the '*' character.
                        }
                        break;
                    case '*':                     // if currently in a block comment it checks to see if it is closing the comment
                        if (!bBlockComment)                 // '*' that is NOT part of a block comment delimiter indicates a Line of Code
                        {
                            bIsLOC = true;
                        }
                        else if (i < sReadLine.length() - 1) {
                            if (sReadLine.charAt(i + 1) == '/')     // Check for end of Block Comment
                            {
                                bBlockComment = false;              // End of Block Comment
                                i++;                                // Already evaluated next character so don't evaluate it again
                            }
                        }
                        break;
                    default:                      // all other non-whitespace characters indicate a LOC assuming not in a block comment
                        if ((bBlockComment) || (Character.isWhitespace(sReadLine.charAt(i)))) {
                            // Skip to the next character or line
                        }
                        else {
                            bIsLOC = true;
                        }
                        break;
                }
            }   // Scan line character by character

            if (bIsLOC)            // If flag indicates current line is LOC
            {
                ++iTotalLOC;               // Tally LOC
                bIsLOC = false;            // Clear the flag for the next iteration
            }

            sReadLine = reader.readLine(); // Get next line in file
        }  // Loop through each line until finding EOF


        return iTotalLOC;
    }

    /**
     * @param file File "pointer" passed in by main()
     * @param functionList a list containing all of the functions
     * @return count of LOCLs in a file
     * @throws IOException
     */
    public static int countFuncLOC(File file, List functionList) throws IOException {
        int iTotalLOC = 0;                  // count of Total LOC found in the file.
        boolean bInFunction = false;        // Flag to show if were inside a flag
        boolean bFuncStarted = false;       // Flag to indicate that the first bracket has been given and when the iFuncBracCount hits zero it is the end of the function.
        boolean bBlockComment = false;      // Flag to see if its a block comment
        int iFuncBracCount = 0;             // count the number of braces to note when its out of the function
        String sFunctionText = "";          // the function Text that gets sent to line count to count the lines of that function
        FunctionData fData;                 // a temp variable for the function data

        // Read the file and convert it to a input stream, throw exception if cant open.
        // This was taken from countLOC.
        FileReader fileReader = null;
        BufferedReader reader = null;
        try {
            fileReader = new FileReader(file);
            reader = new BufferedReader(fileReader);
        }
        catch (Exception e) {
            System.out.println("An error has occurred.  Cannot open file.\n");
            //e.printStackTrace();
            return -1;
        }

        //count the lines of code per function
        String sReadLine = reader.readLine();   // Get first line in file
        while (sReadLine != null) {
            if (bBlockComment) { // if inside a block comment
                if (sReadLine.contains("*/")) { // if at the end of the block set the flag to false and removed the commented portion so it can be continuted to be scanned.
                    bBlockComment = false;
                    sReadLine += " "; // add a space at the end to protect from the end block being at the end of the function
                    sReadLine = sReadLine.substring(sReadLine.indexOf("*/") + 2);
                }
            }

            if (!bBlockComment) {
                if (bInFunction) { // if inside a function
                    // add to the function string
                    sFunctionText += sReadLine + "\n";

                    if (bFuncStarted) { // if already started then look for it to end and close when you hit zero
                        // scan for the end of the function
                        for (int i = 0; i < sReadLine.length(); i++) {
                            switch (sReadLine.charAt(i)) {
                                case '{':
                                    if(i != 0 && i != (sReadLine.length()-1)) { // Break if the brackets are in "" or '' and check if it is the first or last item in the string
                                        if ((sReadLine.charAt(i+1) == '\'' && sReadLine.charAt(i-1) == '\'') || (sReadLine.charAt(i+1) == '\"' && sReadLine.charAt(i-1) == '\"')) {
                                            break;
                                        }
                                    }
                                    iFuncBracCount++;
                                    break;
                                case '}':
                                    if(i != 0 && i != (sReadLine.length()-1)) { // Break if the brackets are in "" or '' and check if it is the first or last item in the string
                                        if ((sReadLine.charAt(i+1) == '\'' && sReadLine.charAt(i-1) == '\'') || (sReadLine.charAt(i+1) == '\"' && sReadLine.charAt(i-1) == '\"')) {
                                            break;
                                        }
                                    }
                                    iFuncBracCount--;
                                    if (iFuncBracCount == 0) {
                                        bInFunction = false;

                                        // convert string to Buffered reader, code based on an example on https://www.mkyong.com/java/how-to-convert-string-to-inputstream-in-java/
                                        InputStream input = new ByteArrayInputStream(sFunctionText.getBytes());
                                        BufferedReader buffer = new BufferedReader(new InputStreamReader(input));

                                        // get the lines of code and store it
                                        fData = (FunctionData) functionList.get(functionList.size() - 1);
                                        fData.functionLOC = countLOC(buffer);
                                        functionList.set(functionList.size() - 1, fData);

                                        // clear the function string
                                        sFunctionText = "";
                                    }
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    else { // else find the first { and add the lines before to the code.
                        if (sReadLine.contains("{")) {
                            bFuncStarted = true;
                            iFuncBracCount ++;
                        }


                    }
                }
                else if (sReadLine.contains("(") && sReadLine.contains(")") && !sReadLine.contains(";")) { // is function if has ( and ) and does not have a ;
                        // check for a comment first
                        int slashIndex = sReadLine.indexOf("//");
                        int blockStartIndex = sReadLine.indexOf("/*");
                        int blockEndIndex = sReadLine.indexOf("*/");
                        int endPareIndex = sReadLine.indexOf(")");

                        if ((slashIndex == -1 && blockStartIndex == -1) || (endPareIndex < slashIndex) || (endPareIndex < blockStartIndex) || ((blockEndIndex != -1 && (blockEndIndex < endPareIndex)))) // so if not inside a comment of any form
                        {
                            bInFunction = true;

                            functionList.add(new FunctionData()); // add a new function to the function list
                            String Name = sReadLine; // Start the line with the name.
                            Name = Name.substring(0, Name.indexOf("(")); // get everything before the (

                            // Loop to get the end of the name in the string
                            while (Name.charAt(Name.length() - 1) == '(' || (Character.isWhitespace(sReadLine.charAt(Name.length() - 1)))) {
                                Name = Name.substring(0, Name.length() - 1);
                            }

                            Name = Name.substring(Name.lastIndexOf(" ")+1); // use the last space to find the function name
                            // add to the function list
                            fData = (FunctionData) functionList.get(functionList.size() - 1);
                            fData.functionName = Name;
                            functionList.set(functionList.size() - 1, fData);

                            // add to the function string
                            sFunctionText += sReadLine + "\n";
                            if (sReadLine.contains("{")) { // if it contains a brace as well then start the count.
                                iFuncBracCount = 1;
                                bFuncStarted = true;

                                // scan for the end of the function
                                String sTemp = sReadLine.substring(sReadLine.indexOf("{") + 1); // start scanning
                                for (int i = 0; i < sTemp.length(); i++) {
                                    if (!bInFunction) {
                                        break;
                                    }
                                    switch (sReadLine.charAt(i)) {
                                        case '{':
                                            if(i != 0 && i != (sReadLine.length()-1)) { // Break if the brackets are in "" or '' and check if it is the first or last item in the string
                                                if ((sReadLine.charAt(i+1) == '\'' && sReadLine.charAt(i-1) == '\'') || (sReadLine.charAt(i+1) == '\"' && sReadLine.charAt(i-1) == '\"')) {
                                                    break;
                                                }
                                            }
                                            iFuncBracCount++;
                                            break;
                                        case '}':
                                            if(i != 0 && i != (sReadLine.length()-1)) { // Break if the brackets are in "" or '' and check if it is the first or last item in the string
                                                if ((sReadLine.charAt(i+1) == '\'' && sReadLine.charAt(i-1) == '\'') || (sReadLine.charAt(i+1) == '\"' && sReadLine.charAt(i-1) == '\"')) {
                                                    break;
                                                }
                                            }
                                            iFuncBracCount--;
                                            if (iFuncBracCount == 0) { // if at the end change the LOC of code value
                                                bInFunction = false;

                                                // convert string to Buffered reader, code based on an example on https://www.mkyong.com/java/how-to-convert-string-to-inputstream-in-java/
                                                InputStream input = new ByteArrayInputStream(sFunctionText.getBytes());
                                                BufferedReader buffer = new BufferedReader(new InputStreamReader(input));

                                                // get the lines of code and store it
                                                fData = (FunctionData) functionList.get(functionList.size() - 1);
                                                fData.functionLOC = countLOC(buffer);
                                                functionList.set(functionList.size() - 1, fData);

                                                // clear the function string
                                                sFunctionText = "";
                                            }
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                        }
                        else { // see if the block comment flag should be set
                            if (blockStartIndex != -1 && blockEndIndex == -1) {
                                bBlockComment = true;
                            }
                        }
                    }
                else if (sReadLine.contains("/*")) { // check for block comment
                    int blockStartIndex = sReadLine.indexOf("/*");
                    int blockEndIndex = sReadLine.indexOf("*/");
                    bBlockComment = true;
                    if (blockStartIndex < blockEndIndex) // if there is an end in the same line end the block comment
                        bBlockComment = false;

                }
            }

            sReadLine = reader.readLine(); // Get a new line
        }

        // be sure to close the buffered reader
        // as well as the file reader
        // This was taken from countLOC.
        reader.close();
        fileReader.close();

        // this needs to be opened again for the total read.
        try {
            fileReader = new FileReader(file);
            reader = new BufferedReader(fileReader);
        }
        catch (Exception e) {
            System.out.println("An error has occurred.  Cannot open file.\n");
            //e.printStackTrace();
            return -1;
        }

        // get the total lines of code and close the file.
        iTotalLOC = countLOC(reader);
        reader.close();
        fileReader.close();

        return iTotalLOC;
    }




}
