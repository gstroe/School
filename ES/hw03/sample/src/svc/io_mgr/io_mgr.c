/**************************************************************************
**
** Module Name:   io_mgr.c
**
** Module Description:  Input/Output Manager
**  Maps Hardware/Microcontroller Specific Port Input and Output functions to generic Input and Output routines
**
** IO_Mgr_Init:
** - Initializes Input and Output states.
**
** IO_Mgr_InputTask():
**  Periodic Input Task invoked by the System.
**
** IO_Mgr_OutputTask():
**  Periodic Output Task invoked by the System.
**
** Application-Specifice Signal Accessors are not listed here.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    3.0
**  Date:        16-Oct-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 3.0   16-Oct-2012   Ben Sweet
** * Customized for Simple Abstraction project:
**   + Added UserInput signal maintenance.
**   + Removed MMC related signals.
**
** Revision: 2.2   26-May-2012   Ben Sweet
** * KeySim component moved to .\drv\drv_KeySim to become a virtual driver.
**
** Revision: 2.1   21-Apr-2012   Ben Sweet
** * Adjust Path for Driver components (TARGET_S12UB).
**
** Revision: 2.0   16-Sep-2010   Ben Sweet
** * Customized for Main Machine Controller (MMC) application.
**
** Revision: 1.0   03-Jun-2008   Ben Sweet
** * Original version.
**  
**************************************************************************/

/*
**  Include files
*/
   /* Project configuration */
   #include "..\..\project_cfg.h"
   /* Type Definitions */
   #include "..\..\Types.h"

   /* Function Prototypes/Declaration */
   #include "io_mgr.h"

   /*
   ** Access to System components:
   */
#if defined(TARGET_PC)
    #include "..\..\drv\drv_KeySim\KeySim.h"   /* Access to Keyboard Simulation */ 
    #include "..\..\drv\drv_KeySim\dio\dio.h"  /* Access to Digital Input/Output driver */

#elif defined(TARGET_S12UB)
    #include "..\..\drv\drv_MC9S12DG128\dio\dio.h"  /* Access to Digital Input/Output driver */

#endif /* TARGET */

   #include "..\..\app\sap\SAP.h"               /* Access to SAP component      */

/*
** Global variable declarations
*/


/*
** Local variable declarations
**
**  Add new signals here to allocate storage in memory.
*/
uint8_t     UserInput1      = UserInput_INIT;   /* Current state of Input Switch */
uint8_t     UserInput2      = UserInput_INIT;   /* Current state of Input Switch */


/*
** Local Function Prototypes/Declaration:
*/
void Set_UserInput1(uint8_t);
uint8_t Get_UserInput1();
void Set_UserInput2(uint8_t);
uint8_t Get_UserInput2();


/*
**  Module code begins
*/

/**************************************************************************
**
** Function Name:   IO_Mgr_Init()
**
** Function Description:
**  - Initializes the Input and Output states
**
** Inputs:
**   (none)
**
** Output:
**   Switch_State
**
** Usage:
**   Call to this function from should be in the format of
**    IO_Mgr_Init();
**
***************************************************************************
** System Interface:
** -  . 
**
**************************************************************************/
void IO_Mgr_Init(void)
{
    /* Input Signals: */
    Set_UserInput1(UserInput_INIT);
    Set_UserInput2(UserInput_INIT);

    /* Output Signals: */

    return;
}  /* End: IO_Mgr_Init() */


/**************************************************************************
**
** Function Name:   IO_Mgr_InputTask()
**
** Function Description:
**  - Periodic Input Task invoked by the System.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    IO_Mgr_InputTask();
**
***************************************************************************
** System Interface:
** - Invoked by System.
**
**************************************************************************/
void IO_Mgr_InputTask(void)
{
    /*
    ** First input
    */
    
    uint8_t    rawInput;       /* Temporary variable for raw inputs        */

    /*
    **  Add update of Input signals here:
    */

    rawInput = (uint8_t)TestBitPortB( DIO_IN_CHANNEL_UserInput1 );
    Set_UserInput1(rawInput);
    
    
    /*
    ** Second input
    **  Add update of Input signals here:
    */

    rawInput = (uint8_t)TestBitPortB( DIO_IN_CHANNEL_UserInput2 );
    Set_UserInput2(rawInput);


    return;
}  /* End: IO_Mgr_InputTask() */


/**************************************************************************
**
** Function Name:   IO_Mgr_OutputTask()
**
** Function Description:
**  - Periodic Output Task invoked by the System.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    IO_Mgr_OutputTask();
**
***************************************************************************
** System Interface:
** - Invoked by System.
**
**************************************************************************/
void IO_Mgr_OutputTask(void)
{
    uint8_t    OutputValue;     /* Temporary variable for outputs        */

    /*
    **  Add update of Output signals here:
    */

    OutputValue = Get_ApplicationOutput1();
    WriteBitPortA(DIO_OUT_CHANNEL_ApplicationOutput1, OutputValue);
    
    OutputValue = Get_ApplicationOutput2();
    WriteBitPortA(DIO_OUT_CHANNEL_ApplicationOutput2, OutputValue);


  #if(0)  /* Test to verity that two bits can be written independently. */
    OutputValue = TestBitPortB(3);
    WriteBitPortA(4, OutputValue);
  #endif

    return;
}  /* End: IO_Mgr_OutputTask() */


/*
**  Definition of Input and Output Accessor methods:
*/

/*
** UserInput:
**  Type: uint8_t
*/
void Set_UserInput1(uint8_t SetValue)
{
   UserInput1 = SetValue;
   return;
}
uint8_t Get_UserInput1(void)
{
   return UserInput1;
}
void Set_UserInput2(uint8_t SetValue)
{
   UserInput2 = SetValue;
   return;
}
uint8_t Get_UserInput2(void)
{
   return UserInput2;
}

