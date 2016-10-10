/**************************************************************************
**
** Module Name:  Timer_cfg.c.
**
** Module Description:  Configuration for Digital Debounce service.
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
**  Include files
*/

/* Component Configuration: */
#include "Timer_cfg.h"


/*
** Local variable declarations
*/

/*
** Array of Timers, one element for each Timer Channel.
** Timer Channel names are defined in Timer_cfg.h.
*/
tTimerChannel Timers[MAX_TIMER_CHANNELS];
