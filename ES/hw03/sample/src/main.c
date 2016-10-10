/**************************************************************************
**
** Module Name:   main.c
**
** Module Description:
**   Provides main() function, System_Init() and System_Task() function for project.
**
** main(): Main program loop.
** - Initialization and main menu loop.
** - Perpetually calls the System_Task().
**   Returns (void)
**
** System_Init():
** - Calls the various package- and/or component-level _Init() functions.
**   Returns (void)
**
***************************************************************************
**
** Authors:     Benjamin D. Sweet
** Revision:    1.6
** Creation Date: June  6, 2008
** Edit Date:     May  26, 2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.6    26-May-2012   B. Sweet
** * Move #includes and prototypes to main.h for consistency.
**
** Revision: 1.5    04-May-2012   B. Sweet
** * Add multiple rate System Tasks: 1 ms, 5 ms, 10 ms.
**
** Revision: 1.4    21-Apr-2012   B. Sweet
** * Replace "Dumb" Wait loop with Task Timer.
** * Adjust Path for Driver components (TARGET_S12UB).
**
** Revision: 1.3    26-Sep-2010   B. Sweet
** * For TARGET_PC, before "forever" loop call IO_Mgr_OutputTask() to display
**   initial values for system states, inputs, and outputs.
**
** Revision: 1.2    11-Sep-2010   B. Sweet
** * Add Keyboard Simulation components.
** * Add MMC (Main Machine Controller) application component.
**
** Revision: 1.1    10-Jun-2008   B. Sweet
** * In main(), added varialble "wait" loop after calling System_Task() to 
**   allow for time to pass between Task iterations.
**
** Revision: 1.0     6-Jun-2008   B. Sweet
** * Working baseline.
**
**************************************************************************/

/*
** Include files:
*/
   #include "main.h"

   /*
   ** Access to System components:
   */
   #include "svc\tmr\Timer.h"
   #include "tsk\Task.h"
   #include "svc\io_mgr\io_mgr.h"

  #if defined (TARGET_PC)
   #include ".\drv\drv_KeySim\mcu\mcu.h"        /* Access to (virtual) MCU driver */
  #elif defined(TARGET_S12UB)
   #include ".\drv\drv_MC9S12DG128\mcu\mcu.h"   /* Access to MCU driver */
  #endif /* TARGET */

/*
** Function Prototypes:
*/


/*
** Global Variables:
*/


/*
**  Module code begins:
*/

/*
**
*/
void main(void)
{
   /*
   ** Local Variables:
   */


   /*
   ** Put your own code here:
   */

   /*
   ** Initialization:
   */
   System_Init();


   /*
   ** Forever Loop:
   */
   for( ; ; )
   {

      System_Task(); /* Manage Periodic System Tasks. */

   }

   /* please make sure that you never leave this function */
}


/**************************************************************************
**
** Function Name:   System_Init()
**
** Function Description:
**  - Calls all component _Init functions.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    System_Init();
**
***************************************************************************
** System Interface:
** - Timer_Init()
** - Task_Init()
** - Port_Init()
**
**************************************************************************/
void System_Init(void)
{
    Timer_Init();               /* Initialize the System Timers                       */

    Task_Init();                /* Initialize System Tasks and Periodic Task Timers   */
    IO_Mgr_Init();              /* Initialize the Input/Output Manager                */
    Mcu_Init();                 /* Initialize the Micro-controller                    */

    return;
}  /* End: System_Init() */
