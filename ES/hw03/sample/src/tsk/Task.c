/**************************************************************************
**
** Module Name:   Task.c
**
** Module Description:  System Periodic Task functions.
**  Define functions for system periodic tasks.
**
**************************************************************
** Task_Init():
** - Initialize the System Periodic Task timers.
**
** System_Task():
** - Manage System Periodic Tasks.
**
** System_Task_01ms():
** - Periodic  1 ms Task called by the System.
**   Returns (void)
**
** System_Task_05ms():
** - Periodic  5 ms Task called by the System.
**   Returns (void)
**
** System_Task_10ms():
** - Periodic 10 ms Task called by the System.
**   Returns (void)
**
***************************************************************************
**
**  Revised by:  Ben Sweet
**  Revision:    2.0
**  Date:        16-Oct-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 2.0    16-Oct-2012   Benjamin Sweet
** * Updated for Simple Abstraction project:
**   + Add Application task: SAP_Task().
**   + Remove MMC_Task().
**
** Revision: 1.1    02-Jun-2012   Benjamin Sweet
** * For TARGET_PC applications, added call to Get_KeyboardInput() before calling IO_Mgr_InputTask(),
**   and call to Set_ScreenOutput() after all periodic tasks have run.
**
** Revision: 1.0    04-May-2012   Benjamin Sweet
** * Original.
**
**************************************************************************/

/*
** Include Files
*/

   /* Configuration */
   #include "Task.h"      /* Includes Typedefs, public function prototypes and Definitions for configuration constants */

   /*
   ** Access to System components:
   */
   #include "..\app\sap\SAP.h"
   #include "..\svc\tmr\Timer.h"
   #include "..\svc\io_mgr\IO_Mgr.h"

#if defined (TARGET_PC)
   #include "..\drv\drv_KeySim\KeySim.h"
 #if defined (DEBUG)
   #include "..\drv\drv_KeySim\dio\dio.h"
 #endif

#elif defined (TARGET_S12UB)
 #if defined (DEBUG)
   #include "..\drv\drv_MC9S12DG128\dio\dio.h"
 #endif
#endif


/*
** Function Prototypes
*/
void Task_Init(void);   /* Initialize the System Periodic Tasks */
void System_Task(void); /* Manage System Periodic Tasks         */

void System_Task_01ms(void);
void System_Task_05ms(void);
void System_Task_10ms(void);

/*
** Local Variables:
*/


/*
**  Module code begins:
*/

/**************************************************************************
**
** Function Name:   Task_Init()
**
** Function Description:
**  - Initialize the System Periodic Task timers.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Task_Init();
**
***************************************************************************
** System Interface:
** -  System_Task_01ms() - 
** -  System_Task_05ms() - 
** -  System_Task_10ms() - 
**
**************************************************************************/
void Task_Init(void)
{
    /*
    ** Initialize System Periodic Tasks and Services:
    */
    /* Applications: */
    SAP_Init();                 /* Initialize Simple Application component */

    /* Services: */
    IO_Mgr_Init();              /* Initialize Input/Output Manager component    */


    /*
    ** Initialize Periodic Task Timers:
    */

    /*  1 ms Task: */
    (void)Set_TimerDuration(TASK_TIMER_01ms, TASK_TIMER_DURATION_01ms);
    (void)Start_Timer(TASK_TIMER_01ms);
    /*  5 ms Task: */
    (void)Set_TimerDuration(TASK_TIMER_05ms, TASK_TIMER_DURATION_05ms);
    (void)Start_Timer(TASK_TIMER_05ms);
    /* 10 ms Task: */
    (void)Set_TimerDuration(TASK_TIMER_10ms, TASK_TIMER_DURATION_10ms);
    (void)Start_Timer(TASK_TIMER_10ms);

  #if defined(TARGET_PC)
    /*
    ** Display initial system status:
    */
    Set_ScreenOutput(); /* Display system status on the screen. */
  #endif /* TARGET_PC */
}


/**************************************************************************
**
** Function Name:   System_Task()
**
** Function Description:
**  - Manages periodic system tasks.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    System_Task();
**
***************************************************************************
** System Interface:
** -  System_Task_01ms() - 
** -  System_Task_05ms() - 
** -  System_Task_10ms() - 
**
**************************************************************************/
void System_Task(void)
{

  #if defined (TARGET_PC)
      Timer_Task();  /* For Non-PC targets, Timer_Task() occurs in RTI ISR. */
  #endif

      /*
      **  1 ms Task:
      */
      if (Get_TimerStatus(TASK_TIMER_01ms) == TimerState_EXPIRED)
      {
       #if defined (DEBUG)
        Dio_WriteChannel(DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_01MS, STD_HIGH);
       #endif
  
        (void)Restart_TimerPeriodicInterval(TASK_TIMER_01ms);
        System_Task_01ms();

       #if defined (DEBUG)
        Dio_WriteChannel(DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_01MS, STD_LOW);
       #endif
     }

      /*
      **  5 ms Task:
      */
      if (Get_TimerStatus(TASK_TIMER_05ms) == TimerState_EXPIRED)
      {
       #if defined (DEBUG)
        Dio_WriteChannel(DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_05MS, STD_HIGH);
       #endif

        (void)Restart_TimerPeriodicInterval(TASK_TIMER_05ms);
        System_Task_05ms();

       #if defined (DEBUG)
        Dio_WriteChannel(DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_05MS, STD_LOW);
       #endif
      }

      /*
      ** 10 ms Task:
      */
      if (Get_TimerStatus(TASK_TIMER_10ms) == TimerState_EXPIRED)
      {
       #if defined (DEBUG)
        Dio_WriteChannel(DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_10MS, STD_HIGH);
       #endif

        (void)Restart_TimerPeriodicInterval(TASK_TIMER_10ms);
        System_Task_10ms();

       #if defined (DEBUG)
        Dio_WriteChannel(DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_10MS, STD_LOW);
       #endif
      }

  /*
  ** Update system status display after all periodic tasks have been run:
  */
  #if defined (TARGET_PC)
    Set_ScreenOutput(); /* Display system status on the screen. */
  #endif /* TARGET_PC */
}


/**************************************************************************
**
** Function Name:   System_Task_01ms()
**
** Function Description:
**  - Periodic  1 ms Task called by the System.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    System_Task_01ms();
**
***************************************************************************
** System Interface:
** - IO_Mgr_InputTask()
**
**************************************************************************/
void System_Task_01ms(void)
{
  #if defined (TARGET_PC)
    Get_KeyboardInput();    /* Update simulated input signals from User Interface. */
  #endif /* TARGET_PC */

    IO_Mgr_InputTask();         /* Update Input Signals     */

    return;
}  /* End: System_Task_01ms() */


/**************************************************************************
**
** Function Name:   System_Task_05ms()
**
** Function Description:
**  - Periodic  5 ms Task called by the System.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    System_Task_05ms();
**
***************************************************************************
** System Interface:
** - MMC_Task()
** - IO_Mgr_OutputTask()
**
**************************************************************************/
void System_Task_05ms(void)
{
    SAP_Task();                 /* Simple Application - periodic task  */

    IO_Mgr_OutputTask();        /* Update Output Signals */

    return;
}  /* End: System_Task_05ms() */


/**************************************************************************
**
** Function Name:   System_Task_10ms()
**
** Function Description:
**  - Periodic 10 ms Task called by the System.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    System_Task_10ms();
**
***************************************************************************
** System Interface:
** - ...()
**
**************************************************************************/
void System_Task_10ms(void)
{

    return;
}  /* End: System_Task_10ms() */
