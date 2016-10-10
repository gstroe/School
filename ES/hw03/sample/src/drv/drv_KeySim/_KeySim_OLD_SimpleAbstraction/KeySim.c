/**************************************************************************
**
** Module Name: KeySim.c
**
** Module Description:
**  This file provides Keyboard Input and Screen Output utilities for 
**  keyboard simulation of embedded software.
**
**  Get_KeyboardInput: brief description:
**  - Summary of function.  Return value.
**
**  Set_ScreenOutput: brief description:
**  - Summary of function.  Return value.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.2.1.0
**  Edit Date:   01/15/2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.2.1.0    01/15/2015   B.Sweet
** * Add prototypes for KeySim_Init() and Accessors for UserInput signal.
**
** Revision: 1.2    09/15/2011   Alex Campbell
** * Improve User Iterface.
**
** Revision: 1.1    09/28/2010   Benjamin Sweet
** * Improve "flow" of Input/Output sequence:
**	 + Don't clear the screen between displaying current values and selecting inputs.
**   + Don't clear the screen between selecting inputs in the same iteration ("while" loop.)
**   + Remove "PAUSE" at the end of Set_ScreenOutput().
**   Note: When running the application, "stretch" the bottom of the "console" to fit the displayed information.
**
** * Resolve the run-time error:
**     "Run-Time Check Failure #2 - Stack around the variable 'userInputValue' was corrupted."
**   + userInputValue is a int16_t, but the sscanf() function was using the "%d" conversion
**     specifier, which indicates a 32-bit integer (hence the stack overflow error.)
**   + Replacing "%d" with "%hd" indicates a 16-bit value and resolves the issue.
**
** Revision: 1.0    09/07/2010   Benjamin Sweet
** * Original version.
**  
**************************************************************************/

/*
**  Include files
*/
#include "..\..\project_cfg.h"    /* Project configuration              */
#include "..\..\Types.h"          /* Standard and Custom Data Types     */


#ifdef TARGET_PC

#include <stdio.h>
#include <stdlib.h>
#include "..\..\app\sap\SAP.h"    /* Access to SAP Get_ accessors         */
#include "KeySim.h"


/*
** Local Function Prototypes:
*/
  /* Methods: */
  void      Get_KeyboardInput(void);
  void      Set_ScreenOutput(void);
  void      KeySim_Init(void);

  /* Accessors: */
  void      Set_UserInput(int16_t value);
  int16_t   Get_UserInput(void);


/*
** File-Scope Global Variables:
*/

  /*
  ** Define interface signal variables:
  */
  /* Inputs: */
  
  /* Outputs: */
  int16_t   UserInput   = USER_INPUT_INIT;  /* Current value of User Input */


/*
**  Module code begins
*/

/**************************************************************************
**
** Function Name:   Get_KeyboardInput
**
** Function Description:  :
**  - .
**  - .
**  - Returns .
** 
**  Inputs:
**   none
**
**  Output:
**   none: User input is written through accessor signals.
**
**  Usage:
**   Call to this function from should be in the format of
**      userInput = Get_KeyboardInput()
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/

void Get_KeyboardInput(void)
{  
    /*
    ** Local variables:
    */
	char    userInputString[10] = {0};		    /* */
    uint8_t userInputSignalSelection = 0u;      /* */
    int16_t userInputValue           = 0;       /* */
    uint8_t continueSignalSelection  = 1u;      /* Default continueSlection option to TRUE */


    /*
    ** Module code begins:
    */

    while (continueSignalSelection != FALSE)
    {
        printf("\n\n");     /* a few blank lines    */
        /*
        ** Customize the list of input signals as necessary: 
        */
        printf("Select a number from the following list of Input signals, or \"0\" to exit signal selection:\n");
        printf(" 0 - Exit signal selection and continue running program\n");
        printf(" 1 - UserInput\n");

        printf("\n\n");     /* a few blank lines    */
        scanf("%s", userInputString);				/* Read User Signal Selection as a string   */

        if (isdigit(userInputString[0]) )
        {
			/* Convert input string to integer value: */
			userInputSignalSelection = (uint8_t)atoi(userInputString);

			switch(userInputSignalSelection)
            {
                case 0:
                default:
                     continueSignalSelection = FALSE;    /* Terminate User input signal selection    */
                     break;
                case USER_INPUT:
                     printf("Enter value for UserInput: ");
                     scanf("%hd", &userInputValue);                         /* Read User Signal Value input from the keyboard   */
                     Set_UserInput( (int16_t)userInputValue);               /* Set input signal value                           */
                     break;
            }
        }
        else
        {
            continueSignalSelection = FALSE;    /* Terminate User input signal selection    */
        }   

    } /* End: while (continueSignalSelection != FALSE) */

	return;
} /* Get_KeyboardInput() */


/**************************************************************************
**
** Function Name:   Set_ScreenOutput
**
** Function Description:  :
**  - .
**  - .
**  - Returns .
** 
**  Inputs:
**   size type: input1
**   size type: input2
**
**  Output:
**   size type: return_value
**
**  Usage:
**   Call to this function from should be in the format of
**      return_value = function_name(type input1, type input2)
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/

void Set_ScreenOutput(void)
{
    /*
    ** Local variables:
    */
    int16_t tempValue;

    /*
    ** Module code begins:
    */
    system ("cls");     /* Clear the display */

    /*
    ** Customize the list of Signals and States as necessary: 
    */
    printf("Current values of the system Signals:");
    printf("\n\n");     /* a few blank lines    */

	printf("System INPUT Variables:\n");
    tempValue = Get_UserInput();
    printf("UserInput:                     Decimal: %d ; Hexadecimal: 0x%2.2hX\n", tempValue, tempValue );

	printf("\n\n");     /* a few blank lines    */

	printf("System OUTPUT Variables:\n");
    tempValue = Get_ApplicationOutput();
    printf("ApplicationOuput:              Decimal: %d ; Hexadecimal: 0x%2.2hX\n", tempValue, tempValue );

    printf("\n\n\n");     /* a few blank lines    */

} /* Set_ScreenOutput() */


/*
** KeySim_Init() - Initialize the KeySim component:
*/
void    KeySim_Init(void)
{
    /* Initialize Output Signals: */
    Set_UserInput(USER_INPUT_INIT);
}


/*
** UserInput:
**  Type: int16_t
*/
void Set_UserInput(int16_t SetValue)
{
   UserInput = SetValue;
   return;
}
int16_t Get_UserInput(void)
{
   return UserInput;
}


#endif /* TARGET_PC */
