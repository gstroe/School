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


/*
** Macro Definitions:
*/


#endif /* MCU_H */
