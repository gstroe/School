#ifndef TIMER_CFG_H
#define TIMER_CFG_H
/**************************************************************************
**
** Module Name:  Timer_cfg.h.
**
** Module Description:  Configuration constants for Timer service.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.0
**  Date:        October 02, 2010
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.0    02-Oct-2010  B. Sweet
**  Original implementation.
**************************************************************************/

/*
** Type Definitions:
*/
#include "..\..\Types.h"

/* Project Configuration: */
#include "..\..\project_cfg.h"   /* Contains definition of DEBUG conditional compile switch */


/*
** Component Configuration:
*/

/*
** Maximum value of timer
*/

/* Consider having 8-bit, 16-bit, and 32-bit timers... */
#define TIMER_MAX_VALUE  (UINT16_MAX)       /* 16-bit timer */

/*
** Constants for configuration:  
*/
#define TimerState_IDLE         (0u)
#define TimerState_RUNNING      (1u)
#define TimerState_EXPIRED      (2u)


/*
** Add an entry for each Timer channel.
**
** Additional Channels may be added, and the channel names may be redefined, 
**  but MAX_TIMER_CHANNEL _MUST_ ALWAYS be the LAST entry in the table, 
**  and must NOT be renamed.
*/
/* Consider having 8-bit, 16-bit, and 32-bit timers... */
enum tTimerList
{
   TIMER_CHANNEL_0 = 0u,
   TIMER_CHANNEL_1,
   TIMER_CHANNEL_2,

   /* Note: THIS MUST ALWAYS BE THE LAST ENTRY */
   MAX_TIMER_CHANNELS
};

/*
** Timer Channel Aliases:
*/
#define TASK_TIMER_01ms	    (TIMER_CHANNEL_0)
#define TASK_TIMER_05ms     (TIMER_CHANNEL_1)
#define TASK_TIMER_10ms	    (TIMER_CHANNEL_2)

/* Timer Channel Durations: */
    #define TASK_TIMER_DURATION_01ms  (1u)     /* Task Rate:  1 ms:  1 iteration  of 1 ms RTI ISR */
    #define TASK_TIMER_DURATION_05ms  (5u)     /* Task Rate:  5 ms:  5 iterations of 1 ms RTI ISR */
    #define TASK_TIMER_DURATION_10ms (10u)     /* Task Rate: 10 ms: 10 iterations of 1 ms RTI ISR */

/*
** Timer Channel Structure
*/
/* Consider having 8-bit, 16-bit, and 32-bit timers... */
typedef struct TimerChannelStruct
{
   uint8_t  timerState;         /* Current State of Timer Channel: IDLE, RUNNING, EXPIRED   */
   uint16_t timerSetValue;      /* Value for desired timer elapsed counts                   */
   uint16_t timerStartCounter;  /* Storage for "snapshot" of Timer Channel's initial counter value */
} tTimerChannel;

#endif /* TIMER_CFG_H */
