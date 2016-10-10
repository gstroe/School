#ifndef TASK_H
#define TASK_H
/**************************************************************************
**
** Module Name:   Task.h
**
** Module Description:  Declarations for System Periodic Task functions.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    1.0
**  Date:        04-Mar-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.0    04-Mar-2012   Benjamin Sweet
** * Original version.
**  
**************************************************************************/

#include "..\Types.h"   /* Type Definitions */
#include "Task_cfg.h"   /* Periodic Task configurable definitions */


/*
** Function Prototypes
*/
extern void Task_Init(void);   /* Initialize the System Periodic Task timers */
extern void System_Task(void); /* Manage System Periodic Tasks               */

#endif /* TASK_H */
