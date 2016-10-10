/**************************************************************************
**
** Module Name:   Mcu.c
**
** Module Description:  General Microcontroller functions.
**  Define functions for General Overall Microcontroller configuration and operation.
**
** Mcu_Init():
** * Configures Overall microprocessor for desired operation.
**
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
** Include Files
*/

   /* Type Definitions */
   #include "..\..\..\Types.h"


/*
** Function Prototypes:
*/
   #include "Mcu.h"             /* Function Prototypes & Definitions for configuration constants */
   #include "..\port\port.h"    /* Access to Port_Init()  */


/*
** Global Variables:
*/


/*
** Local Variables:
*/

/*
**  Module code begins:
*/

/**************************************************************************
**
** Function Name:   Mcu_Init()
**
** Function Description:
**  - Configures Overall microprocessor for desired operation.
**
**    NOTE: The constant values are defined in mcu_cfg.h.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Mcu_Init();
**
***************************************************************************
** System Interface:
** - Port_Init() - Configures Overall System Input/Output ports for desired operation.
**
**************************************************************************/
void Mcu_Init(void)
{
    /*
    ** Configures Microcontroller System for desired operation:
    */
    Port_Init();                /* Configures Overall System Input/Output ports for desired operation */

}

