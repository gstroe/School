#ifndef PORT_H
#define PORT_H
/**************************************************************************
**
** Module Name:   Port.h
**
** Module Description:  Declarations for General I/O Port functions.
**  Delcare external functions for Overall I/O Port operation.
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
**  Include files
*/

   /* Project configuration */
   #include "..\..\..\project_cfg.h"

   /* Component Configuration */
   #include "port_cfg.h"    /* Port Accessor Macro definitions */

   /*
   ** Access to System components:
   */
   #include "..\dio\dio.h"


/*
** Function Prototypes
*/
extern void Port_Init(void);




/*
** Macro Definitions
*/

#endif /* PORT_H */
