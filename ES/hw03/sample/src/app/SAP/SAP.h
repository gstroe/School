#ifndef SAP_H
#define SAP_H
/*
** SAP.h
**
** Module Description:
**  Simple Application (SAP) to demonstrate basic abstraction.
**
**
***************************************************************************
**
** Author:          Benjamin D. Sweet
** Revision:        1.1
** Creation Date:   15-January-2012
** Edit Date:       20-January-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.1    20-Jan-2012   B.Sweet
** * Remove "extern" of Set_ accessor.
**
** Revision: 1.0    15-Jan-2012   B.Sweet
** * Original version.
** 
**************************************************************************/

/* Standard Type Definitions */
#include "..\..\Types.h"

/* Component Configuration: */
#include "SAP_cfg.h"


/*
** External Function Declaration:
*/
/* Methods: */
extern void     SAP_Init(void);
extern void     SAP_Task(void);

/* Accessors: */
extern uint8_t  Get_ApplicationOutput1(void);
extern uint8_t  Get_ApplicationOutput2(void);

#endif /* SAP_H */
