#ifndef MCU_H
#define MCU_H
/**************************************************************************
**
** Module Name:   Mcu.h
**
** Module Description:  Declarations for General Microcontroller functions.
**  Delcare external functions for General Microcontroller configuration and operation.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    1.0
**  Date:        06-Jun-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.0   06-Jun-2012    Ben Sweet
** * Original version based on existing methods in general use.
**
**************************************************************************/

/*
**  Include files
*/

   /* Project configuration */
   #include "..\..\..\project_cfg.h"

#ifndef MXVDEV
   /* Target Specific Definitions */
   #include <mc9s12dg128.h>     /* derivative information */
#endif

   /* Component Configuration */
   #include "mcu_cfg.h"     /*  */

   /*
   ** Access to System components:
   */
   #include "..\port\port.h"


/*
** Function Prototypes:
*/
extern void   Mcu_Init(void);
extern void   Mcu_InterruptInhibit(uint8_t *);  /* Disables interrupts, storing prior status of interrupt enable */
extern void   Mcu_InterruptRestore(uint8_t *);  /* Restores interrupt enable status to previously stored state   */

#if(0) /* Implemented as Macros in mcu_cfg.h */
 extern void     Mcu_InterruptEnable(void);        /* Unconditionally Enables  Maskable interrupts */
 extern void     Mcu_InterruptDisable(void);       /* Unconditionally Disables Maskable interrupts */
#endif


/*
** Macro Definitions:
*/


#endif /* MCU_H */
