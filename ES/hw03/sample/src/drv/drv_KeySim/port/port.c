/**************************************************************************
**
** Module Name:   Port.c
**
** Module Description:  General I/O Port functions.
**  Define functions for Overall I/O Port configuration.
**
** Port_Init():
**  Configures overall Input/Output ports for desired operation.
**
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    2.0
**  Date:        05-May-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 2.0   05-May-2012    Ben Sweet
** * Moved Digital I/O Port component operations to Dio.c.
**
** Revision: 1.1    6-June-2008   Ben Sweet
**  Added Port Accessor macros (defined in Port_cfg.h):
**   GetPortX, SetPortX, SetMaskPortX, ClearMaskPortX, SetBitPortX, ClearBitPortX, TestBitPortX.
**
**   Re: "An architecture for designing reusable embedded systems software, Part 2", Dinu Madau
**        http://embedded.com/design/opensource/207403738?pgno=2
**
** Revision: 1.0    4-June-2008   Ben Sweet
**  Original version based on existing methods in general use.
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
   #include "Port.h"        /* Function Prototypes & Definitions for configuration constants */
   #include "..\dio\dio.h"  /* Access to Dio_Init()  */


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
** Function Name:   Port_Init()
**
** Function Description:
**  - Configures Overall System Input/Output ports for desired operation.
**
**    NOTE: The constant values are defined in Port_cfg.h.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Port_Init();
**
***************************************************************************
** System Interface:
** -  Dio_Init() - General Purpose Digital Input/Output ports
**
**************************************************************************/
void Port_Init(void)
{
    /*
    ** Configures Overall System Input/Output ports for desired operation:
    */
    Dio_Init();  /* Configure General Purpose Digital Input/Output ports */

}

