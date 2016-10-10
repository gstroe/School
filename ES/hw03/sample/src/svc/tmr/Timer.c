/**************************************************************************
**
** Module Name:  Timer.c.
**
** Module Description:  Timer Service for measuring elapsed time duration.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.3
**  Date:        06-Jun-2012
**
***************************************************************************
**
** Services provided:
**  Timer_Init()            - Initialize the values in all timer channels.
**                          - For Microcontroller targets, initializes RTI.
**
**  Timer_Task()            - Periodic task to increment main timer accumulator.
**
**  Get_TimerMainCount()    - Returns the current value of the mainTimerAccumulator.
**
**  Start_Timer()           - Starts the specified timerChannel.
**  
**  Restart_TimerPeriodicInterval()
**                          - Restarts a periodic Timer interval from the end of 
**                            the previous interval's scheduled expiration time.
**
**  Stop_Timer()            - Stops the specified timerChannel.
**
**  Get_TimerStatus()       - Returns the current state of the specified timerChannel.
**
**  Get_TimerElapsed()      - Returns the current elapsed time for the specified timerChannel.
**
**  Set_TimerDuration()     - Sets the desired timer interval for the specified timerChannel.
**
**  Get_TimerDuration()     - Returns the value of the stored interval for the specifeid timerChannel.
**
**  Get_TimerStoredCount()  - Returns the value of the stored mainTimerAccumulator for the specifeid timerChannel.
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.3    06-Jun-2012  B. Sweet
** * Revise Restart_TimerPeriodicInterval() to start the new interval at the end
**   of the previous interval's scheduled expiration time.
** * Moved calls to RTI_Init() and InterruptEnable() from Timer_Init() to MCU_Init() [Mcu.c] 
**
** Revision: 1.2    05-May-2012  B. Sweet
** * Add RTI initialization to Timer_Init().
**
** Revision: 1.1    22-Apr-2012  B. Sweet
** * Added Get_TimerStoredCount() and Restart_PeriodicTimerInterval().
**
** Revision: 1.0    02-Oct-2010  B. Sweet
** * Original implementation.
**************************************************************************/

/*
**  Include files
*/
#include "..\..\Types.h"                    /* Standard and Custom Data Types   */
#include "..\..\project_cfg.h"              /* Project configuration            */
#include "Timer_cfg.h"                      /* Component Configuration: */

#if defined TARGET_S12UB
  #include "..\..\drv\drv_MC9S12DG128\mcu\mcu.h"
#endif /* TARGET */


/*
** Local variable declarations
*/

/* Consider having 8-bit, 16-bit, and 32-bit timers... */
uint16_t    mainTimerAccumulator    = 0u;   /* This is the main timer accumulator  */

/*
** Array of Timers, one element for each Timer Channel.
** Timer Channel names are defined in Timer_cfg.h.
*/
extern tTimerChannel Timers[MAX_TIMER_CHANNELS];


/*
** Function Prototypes:
*/
void        Timer_Init(void);
void        Timer_Task(void);

/* Consider having 8-bit, 16-bit, and 32-bit timers... */
uint16_t    Get_TimerMainCount(void);
uint8_t     Start_Timer(uint8_t timerChannel);
uint8_t     Restart_TimerPeriodicInterval(uint8_t timerChannel);
uint8_t     Stop_Timer(uint8_t timerChannel);
uint8_t     Get_TimerStatus(uint8_t timerChannel);
uint16_t    Get_TimerElapsed(uint8_t timerChannel);
uint8_t     Set_TimerDuration(uint8_t timerChannel, uint16_t timerDuration);
uint16_t    Get_TimerDuration(uint8_t TimerChannel);
uint16_t    Get_TimerStoredCount(uint8_t TimerChannel);


/*
** Module Code Begins:
*/

/**************************************************************************
**
** Function Name:   Timer_Init
**
** Function Description:
**  - Initialize the values in all timer channels.
**  - Returns:  void
** 
**  Inputs:
**   none
**
**  Output:
**   none
**
**  Usage:
**   Call to this function from should be in the format of
**      Timer_Init();
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
void    Timer_Init(void)
{
    uint8_t     timerChannel;

    mainTimerAccumulator    = 0u;

    for (timerChannel = 0u ; timerChannel < MAX_TIMER_CHANNELS ; ++timerChannel)
    {
        Timers[timerChannel].timerState = TimerState_IDLE;
        Timers[timerChannel].timerSetValue = 0u;
        Timers[timerChannel].timerStartCounter = 0u;
    }

    return;
} /* Timer_Init() */


/**************************************************************************
**
** Function Name:   Timer_Task
**
** Function Description:
**  - Periodic task to increment main timer accumulator.
**  - Returns:  void
** 
**  Inputs:
**   none
**
**  Output:
**   none
**
**  Usage:
**   Call to this function from should be in the format of
**      Timer_Task();
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
void    Timer_Task(void)
{
    ++mainTimerAccumulator;

    return;
} /* Timer_Task() */


/**************************************************************************
**
** Function Name:   Get_TimerMainCount
**
** Function Description:
**  - Returns the current value of the mainTimerAccumulator
** 
**  Inputs:
**   none
**
**  Output:
**   uint16_t:  mainTimerAccumulator
**
**  Usage:
**   Call to this function from should be in the format of
**      mainTimerValue = Get_TimerMainCount();
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint16_t    Get_TimerMainCount(void)
{

    uint16_t currentTimerAccumulatorValue;
  #ifndef TARGET_PC
    uint8_t localInterruptStatusStore;
  #endif /* TARGET */


  #ifndef TARGET_PC
    Mcu_InterruptInhibit(&localInterruptStatusStore);
  #endif /* TARGET */

    currentTimerAccumulatorValue = mainTimerAccumulator;

  #ifndef TARGET_PC
    Mcu_InterruptRestore(&localInterruptStatusStore);
  #endif /* TARGET */


    return currentTimerAccumulatorValue;


} /* Get_TimerMainCount() */


/**************************************************************************
**
** Function Name:   Start_Timer
**
** Function Description: 
**  - Initializes the timerStartCounter of the specified timerChannel to the 
**    present value of mainTimerAccumulator.
**  - Sets the timerState of the specified timerChannel to RUNNING.
**  - Returns:
**    + 0 if the specified timerChannel is out of range
**    + 1 otherwise
** 
**  Inputs:
**   uint8_t:   timerChannel - Timer Channel to be initialized.
**
**  Output:
**   uint8_t:   startResult - Result of Start_Timer attempt.
**
**  Usage:
**   Call to this function from should be in the format of
**      startResult = Start_Timer(timerChannel);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint8_t     Start_Timer(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint8_t startResult;
  #ifndef TARGET_PC
    uint8_t localInterruptStatusStore;
  #endif /* TARGET */

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        startResult = 0u;   /* Start_Timer attempt was NOT successful */
    }
    else
    {
      #ifndef TARGET_PC
        Mcu_InterruptInhibit(&localInterruptStatusStore);
      #endif /* TARGET */

        /* Store a "snapshot" of the present value of mainTimerAccumulator */
        Timers[timerChannel].timerStartCounter = mainTimerAccumulator;

      #ifndef TARGET_PC
        Mcu_InterruptRestore(&localInterruptStatusStore);
      #endif /* TARGET */

        /* Indicate that Timer is Running */
        Timers[timerChannel].timerState = TimerState_RUNNING;

        startResult = 1u;   /* Start_Timer attempt WAS successful */
    }

    return  startResult;
} /* Start_Timer() */



#ifdef DEBUG
   /*
   ** Global Variable for DEBUG:  (Otherwise this is a Local variables.)
   */
   /* Restart_TimerPeriodicInterval(): */
   uint16_t timerReStartCounter = 0u;
#endif /* DEBUG */

/**************************************************************************
**
** Function Name:   Restart_TimerPeriodicInterval()
**
** Function Description: 
**  Restarts a periodic Timer interval from the end of the previous interval's
**   scheduled expiration time
**  - Initializes the timerStartCounter of the specified timerChannel to the 
**    previous interval's timerStartCounter plus the timerSetValue.
**  - If the present interval's duration is already Expired, 
**      the timerState is set to EXPIRED.
**    - Otherwise the timerState is set to RUNNING.
**  - Returns:
**    + 0 if the specified timerChannel is out of range
**    + 1 otherwise
** 
**  Inputs:
**   uint8_t:   timerChannel - Timer Channel to be re-started.
**
**  Output:
**   uint8_t:   restartResult - Result of Restart_PeriodicTimerInterval attempt.
**
**  Usage:
**   Call to this function from should be in the format of
**      restartResult = Restart_TimerPeriodicInterval(timerChannel);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint8_t  Restart_TimerPeriodicInterval(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint8_t  restartResult;

  #ifndef DEBUG   /* Variable defined as Global for DEBUG: */
    uint16_t timerReStartCounter = 0u;
  #endif
  #ifndef TARGET_PC
    uint8_t localInterruptStatusStore;
  #endif /* TARGET */

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        restartResult = 0u;    /* Restart_TimerPeriodicInterval attempt was NOT successful */
    }
    else
    {
        /* Calculate timer Re-Start Counter value from previous interval's scheduled expiration time: */
        timerReStartCounter = Timers[timerChannel].timerStartCounter + Timers[timerChannel].timerSetValue;
        /* Store the new interval Start Counter: */
        Timers[timerChannel].timerStartCounter = timerReStartCounter;

        /* Check for Timer Expiration: */
      #ifndef TARGET_PC
        Mcu_InterruptInhibit(&localInterruptStatusStore);
      #endif /* TARGET */

        if ( (mainTimerAccumulator - Timers[timerChannel].timerStartCounter) >= Timers[timerChannel].timerSetValue ) 
        {   /* Indicate that timer is Expired: */
            Timers[timerChannel].timerState = TimerState_EXPIRED;
        }
        else
        {
            /* Indicate that Timer is Running */
            Timers[timerChannel].timerState = TimerState_RUNNING;
        }

      #ifndef TARGET_PC
        Mcu_InterruptRestore(&localInterruptStatusStore);
      #endif /* TARGET */

        restartResult = 1u;   /* Restart_TimerPeriodicInterval attempt WAS successful */
    }

    return  restartResult;
} /* Restart_TimerPeriodicInterval() */


/**************************************************************************
**
** Function Name:   Stop_Timer
**
** Function Description: 
**  - Sets the timerState of the specified timerChannel to IDLE.
**  - Sets the timerSetValue of the specified timerChannel to Zero.
**  - Returns:
**    + 0 if the specified timerChannel is out of range
**    + 1 otherwise
** 
**  Inputs:
**   uint8_t:   timerChannel - Timer Channel to be initialized.
**
**  Output:
**   uint8_t:   stopResult - Result of Stop_Timer attempt.
**
**  Usage:
**   Call to this function from should be in the format of
**      stopResult = Stop_Timer(timerChannel);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint8_t     Stop_Timer(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint8_t stopResult;

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        stopResult = 0u;    /* Stop_Timer attempt was NOT successful */
    }
    else
    {
        Timers[timerChannel].timerState = TimerState_IDLE;
        Timers[timerChannel].timerSetValue = 0u;

        stopResult = 1u;   /* Stop_Timer attempt WAS successful */
    }

    return  stopResult;
} /* Stop_Timer() */


/**************************************************************************
**
** Function Name:   Get_TimerStatus
**
** Function Description: 
**  - Returns:
**    + 0xFF if the specified timerChannel is out of range.
**    + IDLE if the specified timerChannel is IDLE.
**    + RUNNING if the specified timerChannel is RUNNING and NOT EXPIRED.
**    + EXPIRED if the specified timerChannel is EXPIRED OR
**              RUNNING AND ( timerSetValue is NOT Zero ) AND ( mainTimerAccumulator is >= timerSetValue )
**              * This condition sets timerState to EXPIRED.
** 
**  Inputs:
**   uint8_t:   timerChannel - Timer Channel to be initialized.
**
**  Output:
**   uint8_t:   timerState - Operational state of the specified timer.
**
**  Usage:
**   Call to this function from should be in the format of
**      timerStatus = Get_TimerStatus(timerChannel);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint8_t     Get_TimerStatus(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint8_t timerStatus;
  #ifndef TARGET_PC
    uint8_t localInterruptStatusStore;
  #endif /* TARGET */


    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        timerStatus = 0xFFu;    /* Get_TimerStatus attempt was NOT successful */
    }
    else
    {
      #ifndef TARGET_PC
        Mcu_InterruptInhibit(&localInterruptStatusStore);
      #endif /* TARGET */

        /* Check for Timer Expiration: */
        if ( ( Timers[timerChannel].timerState == TimerState_RUNNING ) && 
             ( (mainTimerAccumulator - Timers[timerChannel].timerStartCounter) >= Timers[timerChannel].timerSetValue ) 
           )
        {   /* Indicate that timer is Expired: */
            Timers[timerChannel].timerState = TimerState_EXPIRED;
        }

      #ifndef TARGET_PC
        Mcu_InterruptRestore(&localInterruptStatusStore);
      #endif /* TARGET */

        /* Retrieve the current Timer State: */
        timerStatus = Timers[timerChannel].timerState; 
    }

    return  timerStatus;
} /* Get_TimerStatus() */


/**************************************************************************
**
** Function Name:   Get_TimerElapsed
**
** Function Description: 
**  - Returns:
**    + 0 if the specified timerChannel is out of range.
**    + 0 if the specified timerChannel is IDLE.
**    + ( mainTimerAccumulator - timerStartCounter ) if the specified
**       timerChannel is RUNNING Or EXPIRED.
** 
**  Inputs:
**   uint8_t:   timerChannel - Timer Channel to be initialized.
**
**  Output:
**   uint16_t:  elapsedTime - Difference between current counter value and
**                            stored counter value.
**
**  Usage:
**   Call to this function from should be in the format of
**      elapsedTime = Get_TimerElapsed(timerChannel);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint16_t    Get_TimerElapsed(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint16_t elapsedTime;
  #ifndef TARGET_PC
    uint8_t localInterruptStatusStore;
  #endif /* TARGET */

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        elapsedTime = 0u;       /* TimerElapsed attempt was NOT successful */
    }
    else if (Timers[timerChannel].timerState == TimerState_IDLE)
    {
        /* Specified timerChannel is not active: */
        elapsedTime = 0u;
    }
    else
    {
      #ifndef TARGET_PC
        Mcu_InterruptInhibit(&localInterruptStatusStore);
      #endif /* TARGET */

        /* Compute elapsed time: */
        elapsedTime = mainTimerAccumulator - Timers[timerChannel].timerStartCounter;

      #ifndef TARGET_PC
        Mcu_InterruptRestore(&localInterruptStatusStore);
      #endif /* TARGET */
    }

    return  elapsedTime;
} /* Get_TimerElapsed() */


/**************************************************************************
**
** Function Name:   Set_TimerDuration
**
** Function Description: 
**  - Sets the timerSetValue of the specified timerChannel to specified TimerDuration.
**  - Returns:
**    + 0 if the specified timerChannel is out of range.
**    + 1 otherwise
** 
**  Inputs:
**   uint8_t:   timerChannel  - Timer Channel to be initialized.
**   uint16_t:  timerDuration - Desired Timer interval to measure.
**
**  Output:
**   uint8_t:   setResult - Result of Set_TimerDuration attempt.
**
**  Usage:
**   Call to this function from should be in the format of
**      setResult = Set_TimerDuration(timerChannel, timerDuration);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint8_t     Set_TimerDuration(uint8_t timerChannel, uint16_t timerDuration)
{
    /*
    ** Local Variables:
    */
    uint8_t     setResult;

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        setResult = 0u;         /* Set_TimerDuration attempt was NOT successful */
    }
    else
    {
        Timers[timerChannel].timerSetValue = timerDuration;
        setResult = 1u;         /* Set_TimerDuration attempt WAS successful */
    }

    return  setResult;
} /* Set_TimerDuration() */


/**************************************************************************
**
** Function Name:   Get_TimerDuration
**
** Function Description: 
**  - Returns:
**    + 0xFFFF if the specified timerChannel is out of range.
**    + Otherwise returns the value of the stored interval for the specifeid timerChannel.
** 
**  Inputs:
**   uint8_t:   timerChannel  - Timer Channel of interest.
**
**  Output:
**   uint16_t:  timerDuration - Stored Timer interval.
**
**  Usage:
**   Call to this function from should be in the format of
**      timerDuration = Get_TimerDuration(timerChannel);
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint16_t    Get_TimerDuration(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint16_t    getResult;

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        getResult = 0xFFFFu;    /* Get_TimerDuration attempt was NOT successful */
    }
    else
    {
        getResult = Timers[timerChannel].timerSetValue;
    }

    return  getResult;
} /* Get_TimerDuration() */


/**************************************************************************
**
** Function Name:   Get_TimerStoredCount
**
** Function Description:
**  - Returns the value of the stored mainTimerAccumulator for the specifeid timerChannel.
** 
**  Inputs:
**   uint8_t:   timerChannel  - Timer Channel of interest.
**
**  Output:
**   uint16_t:  stored mainTimerAccumulator value for specified Timer Channel.
**
**  Usage:
**   Call to this function from should be in the format of
**      storedTimerValue = Get_TimerStoredCount();
**
***************************************************************************
**  System Interface: :
**  -  .
**  -  .
**
**************************************************************************/
uint16_t    Get_TimerStoredCount(uint8_t timerChannel)
{
    /*
    ** Local Variables:
    */
    uint16_t    getResult;

    /*
    ** Module Code Begins:
    */
    /* Verify that specified timerChannel is within range: */
    if (timerChannel >= MAX_TIMER_CHANNELS)
    {
        /* Specified timerChannel is out of range: */
        getResult = 0xFFFFu;    /* Get_TimerStoredCount attempt was NOT successful */
    }
    else
    {
        getResult = Timers[timerChannel].timerStartCounter;
    }

    return  getResult;
} /* Get_TimerStoredCount() */
