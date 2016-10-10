#ifndef RTI_H
#define RTI_H
/**************************************************************************
**
** Module Name:   rti.h
**
** Module Description:  Declarations for Real-Time Interrupt functions.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    1.0
**  Date:        22-Apr-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.0    22-Apr-2012   Benjamin Sweet
** * Original version based on existing methods in general use, and specific
**   work by Justin Michrina and Richard Slindee.
**  
**************************************************************************/


/* Target Specific Definitions */
#ifndef MXVDEV
 #include <mc9s12dg128.h>     /* derivative information */
#endif

#include "Types.h"      /* Type Definitions */
#include "rti_cfg.h"    /* RTI configurable definitions */


/*
** Function Prototypes
*/
extern void RTI_Init(void);    /* Initialize the Real-Time Interrupt clock & Interrupt */
extern void RTI_DeInit(void);  /* Power-Down the Real-Time Interrupt                   */

#pragma CODE_SEG NON_BANKED
extern __interrupt void RTI_Isr(void);

#pragma CODE_SEG DEFAULT

#endif /* RTI_H */
