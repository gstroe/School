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
**  Revision:    1.5
**  Date:        06/12/2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.5    06/12/2012   B. Sweet
** * Typecast result of Dio_ReadPort( DIO_OUT_PORT_MotorControl ) to sint8_t
**   for proper value display.
**
** Revision: 1.4    05/26/2012   B. Sweet
** * KeySim component moved to .\drv\drv_KeySim to become a virtual driver.
** * Replaced scanf() (derecated function) with scanf_s().
**
** Revision: 1.3    04/21/2012   Benjamin Sweet
** * Add display of System Task Timer states and values.
**
** Revision: 1.2    09/15/2011   Alex Campbell
** * Improve User Iterface.
**
** Revision: 1.1    09/28/2010   Benjamin Sweet
** * Improve "flow" of Input/Output sequence:
**   + Don't clear the screen between displaying current values and selecting inputs.
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
#include <ctype.h>
#include "KeySim.h"
#include "KeySim_cfg.h"

#include ".\dio\dio.h"                  /* KeySim DIO Driver                    */
   /*
   ** NON-standard Accessors - NOT to be Externed in Dio.h:
   ** This is necessary to allow KeySim to "Set" the Input Channels and Ports.
   */
   extern void Dio_SetChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
   extern void Dio_SetPort( Dio_PortType PortId, Dio_PortLevelType Level );

#include "..\..\svc\tmr\Timer.h"        /* Access to TMR Get_ accessors         */
#include "..\..\svc\io_mgr\io_mgr.h"    /* Access to I/O signal Get_ accessors  */
#include "..\..\app\sap\sap.h"          /* Access to SAP Get_ accessors         */


/*
** Global variable declarations
*/


/*
** Local variable declarations
*/

    /*
    ** Digital Input & Output (DIO) Ports:
    **  General Purpose Input/Output (GPIO)
    */
    volatile uint8_t      GPIO_Port_00_Data;    /* General Purpose Input/Output Port: 0x00 - Data Register              */
    volatile uint8_t      GPIO_Port_00_Dir;     /* General Purpose Input/Output Port: 0x00 - Data Direction Register    */

    volatile uint8_t      GPIO_Port_01_Data;    /* General Purpose Input/Output Port: 0x01 - Data Register              */
    volatile uint8_t      GPIO_Port_01_Dir;     /* General Purpose Input/Output Port: 0x01 - Data Direction Register    */

    volatile uint8_t      GPIO_Port_02_Data;    /* General Purpose Input/Output Port: 0x02 - Data Register              */
    volatile uint8_t      GPIO_Port_02_Dir;     /* General Purpose Input/Output Port: 0x02 - Data Direction Register    */

    volatile uint8_t      GPIO_Port_03_Data;    /* General Purpose Input/Output Port: 0x03 - Data Register              */
    volatile uint8_t      GPIO_Port_03_Dir;     /* General Purpose Input/Output Port: 0x03 - Data Direction Register    */

    /*
    ** Analog-to-Digital (ADC) Input Channels:
    */
    volatile uint16_t     ADC_Channel_00;       /* Analog to Digital Conversion Input Channel: 0x00 - Result Register   */
    volatile uint16_t     ADC_Channel_01;       /* Analog to Digital Conversion Input Channel: 0x01 - Result Register   */
    volatile uint16_t     ADC_Channel_02;       /* Analog to Digital Conversion Input Channel: 0x02 - Result Register   */
    volatile uint16_t     ADC_Channel_03;       /* Analog to Digital Conversion Input Channel: 0x03 - Result Register   */
    volatile uint16_t     ADC_Channel_04;       /* Analog to Digital Conversion Input Channel: 0x04 - Result Register   */
    volatile uint16_t     ADC_Channel_05;       /* Analog to Digital Conversion Input Channel: 0x05 - Result Register   */
    volatile uint16_t     ADC_Channel_06;       /* Analog to Digital Conversion Input Channel: 0x06 - Result Register   */
    volatile uint16_t     ADC_Channel_07;       /* Analog to Digital Conversion Input Channel: 0x07 - Result Register   */


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
    char       userInputString[10] = {0};       /* */
    uint8_t    userInputSignalSelection = 0u;   /* */
    sint16_t   userInputValue           = 0;    /* */
    uint8_t    userInputBoolean         = 0u;   /* */
    uint8_t    continueSignalSelection  = 1u;   /* Default continueSlection option to TRUE */


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
#if(0)  // Examples...
        printf(" 2 - AnotherInput\n");
        printf(" 3 - YetAnotherIn\n");
#endif

        printf("\n\n");     /* a few blank lines    */
#if(1) /* DevC++ does not presently recognize scanf_s() and _countof() */
        scanf("%s", userInputString);               /* Read User Signal Selection as a string   */
#else
        scanf_s("%s", userInputString, _countof(userInputString));  /* Read User Signal Selection as a string   */
#endif
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
#if(1) /* DevC++ does not presently recognize scanf_s() and _countof() */
                     scanf("%hd", &userInputValue);                         /* Read User Signal Value input from the keyboard   */
#else
                     scanf_s("%hd", &userInputValue, sizeof(userInputValue));  /* Read User Signal Value input from the keyboard */
#endif
                     userInputBoolean = (uint8_t)( (userInputValue == 0) ? 0u : 1u);
                     Dio_SetChannel( DIO_IN_CHANNEL_UserInput, (Dio_LevelType)userInputBoolean );
                     break;

#if(0)  // Example...
                case ANOTHER_INPUT:
                     printf("Enter value for AnotherInput: ");
#if(1) /* DevC++ does not presently recognize scanf_s() and _countof() */
                     scanf("%hd", &userInputValue);                         /* Read User Signal Value input from the keyboard   */
#else
                     scanf_s("%hd", &userInputValue, sizeof(userInputValue));  /* Read User Signal Value input from the keyboard */
#endif
                     userInputBoolean = (uint8_t)( (userInputValue == 0) ? 0u : 1u);
                     Dio_SetChannel( DIO_IN_CHANNEL_StopCommand, (Dio_LevelType)userInputBoolean );
                     break;
                case YET_ANOTHER_IN:
                    printf("Enter value for YetAnotherIn: ");
#if(1) /* DevC++ does not presently recognize scanf_s() and _countof() */
                    scanf("%hd", &userInputValue);                         /* Read User Signal Value input from the keyboard   */
#else
                    scanf_s("%hd", &userInputValue, sizeof(userInputValue));  /* Read User Signal Value input from the keyboard */
#endif
                     userInputBoolean = (uint8_t)( (userInputValue == 0) ? 0u : 1u);
                     Dio_SetChannel( DIO_IN_CHANNEL_EmergencyStopCommand, (Dio_LevelType)userInputBoolean );
                     break;
#endif  // Example...

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


    /*
    ** Module code begins:
    */
    system ("cls");     /* Clear the display */

    /*
    ** Customize the list of Signals and States as necessary: 
    */
    printf("Current values of the system Signals and States:\n\n");
    printf("System TIMER Variables:\n");
    printf("Main Timer Accumulator value:       %d\n", Get_TimerMainCount() );
    printf("Timer 0 (TASK_TIMER_01ms) State:                 %d\n", Get_TimerStatus(TASK_TIMER_01ms) );
    printf("Timer 0 (TASK_TIMER_01ms) Elapsed Time:          %d\n", Get_TimerElapsed(TASK_TIMER_01ms) );
    printf("Timer 0 (TASK_TIMER_01ms) Stored Interval:       %d\n", Get_TimerDuration(TASK_TIMER_01ms) );
    printf("\n");       /* blank line    */
    printf("Timer 1 (TASK_TIMER_05ms) State:                 %d\n", Get_TimerStatus(TASK_TIMER_05ms) );
    printf("Timer 1 (TASK_TIMER_05ms) Elapsed Time:          %d\n", Get_TimerElapsed(TASK_TIMER_05ms) );
    printf("Timer 1 (TASK_TIMER_05ms) Stored Interval:       %d\n", Get_TimerDuration(TASK_TIMER_05ms) );

    printf("\n\n");     /* a few blank lines    */

    printf("System STATE Variables:\n");
    printf("MMC_Task State:                     %d\n", Get_MMC_Task_State() );
    printf("ON:                                 ");

    switch( (sint8_t)Dio_ReadPort( DIO_OUT_PORT_MotorControl ) )
    {
        case MotorControl_ON:
            printf("Yes\n");
            break;
        default:
            printf("No\n");
            break;
    }

    printf("E-Stopped                           ");
    if( (uint8_t)Dio_ReadChannel( DIO_IN_CHANNEL_EmergencyStopCommand ) == TRUE )
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    printf("\n\n");     /* a few blank lines    */

    printf("System INPUT Variables:\n");
    printf("StartCommand:                       %d\n", (uint8_t)Dio_ReadChannel( DIO_IN_CHANNEL_StartCommand ) );
    printf("StopCommand:                        %d\n", (uint8_t)Dio_ReadChannel( DIO_IN_CHANNEL_StopCommand ) );
    printf("EmergencyStopCommand:               %d\n", (uint8_t)Dio_ReadChannel( DIO_IN_CHANNEL_EmergencyStopCommand ) );

    printf("\n\n");     /* a few blank lines    */

    printf("System OUTPUT Variables:\n");
    /* Modified to more easily show the system state: */
    printf("MotorControl:                       %d\n", (sint8_t)Dio_ReadPort( DIO_OUT_PORT_MotorControl ) );
    printf("Motor is:                           ");
    switch( (sint8_t)Dio_ReadPort( DIO_OUT_PORT_MotorControl ) )
    {
        case MotorControl_OFF:
            printf("OFF\n");
            break;
        case MotorControl_ON:
            printf("ON\n");
            break;
        default:
            printf("Unknown????\n");
            break;
    }

    printf("\n\n\n");     /* a few blank lines    */

} /* Set_ScreenOutput() */


#endif /* TARGET_PC */
