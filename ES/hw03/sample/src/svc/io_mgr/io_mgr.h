#ifndef IO_MGR_H
#define IO_MGR_H
/**************************************************************************
**
** Module Name:   io_mgr.h
**
** Module Description:  Declarations for Input Output Manager functions.
**  Delcare external functions for General Input Output operation.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    3.0
**  Edit Date:   16-Oct-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 3.0   16-Oct-2012   Ben Sweet
** * Customized for Simple Abstraction project:
**   + Prototype for UserInput accessor.
**   + Removed MMC related accessors.
**
** Revision: 2.1   20-Jan-2012    Ben Sweet
** * Removed erroneous "extern" statement.
**
** Revision: 2.0   16-Sep-2010    Ben Sweet
** * Customized for Main Machine Controller (MMC) application.
**
** Revision: 1.0    7-Jun-2008    Ben Sweet
** * Original version based on existing methods in general use.
**  
**************************************************************************/

/* Configuration */
#include "io_mgr_cfg.h"


/*
** Function Prototypes
*/
extern void  IO_Mgr_Init(void);
extern void  IO_Mgr_InputTask(void);
extern void  IO_Mgr_OutputTask(void);

/* Public Signal Accessor methods: */
extern uint8_t Get_UserInput(void);


/*
** Macro Definitions
*/

#endif /* IO_MGR_H */
