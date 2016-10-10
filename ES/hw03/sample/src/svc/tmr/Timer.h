#ifndef TIMER_H
#define TIMER_H

#include "Timer_cfg.h"

/*
** Global Declarations:
*/
extern void     Timer_Init(void);
extern void     Timer_Task(void);

/* Consider having 8-bit, 16-bit, and 32-bit timers... */
extern uint16_t Get_TimerMainCount(void);
extern uint8_t  Start_Timer(uint8_t TimerChannel);
extern uint8_t  Restart_TimerPeriodicInterval(uint8_t timerChannel);
extern uint8_t  Stop_Timer(uint8_t TimerChannel);
extern uint8_t  Get_TimerStatus(uint8_t TimerChannel);
extern uint16_t Get_TimerElapsed(uint8_t TimerChannel);
extern uint8_t  Set_TimerDuration(uint8_t TimerChannel, uint16_t TimerDuration);
extern uint16_t Get_TimerDuration(uint8_t TimerChannel);
extern uint16_t Get_TimerStoredCount(uint8_t TimerChannel);


#endif /* TIMER_H */
