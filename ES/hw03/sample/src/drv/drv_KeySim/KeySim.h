#ifndef KEY_SIM_H
#define KEY_SIM_H
/**************************************************************************
**
** Module Name: KeySim.h
**
** Module Description:
**  This file provides declarations for Keyboard Input and Screen Output 
**   utilities for keyboard simulation of embedded software.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.2
**  Date:        05/26/2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.2    05/26/2012   B. Sweet
** * KeySim component moved to .\drv\drv_KeySim to become a virtual driver.
**
** Revision: 1.1    09/15/2011   Alex Campbell
** * Add signal definitions.
**
** Revision: 1.0    09/07/2010   Benjamin Sweet
** * Original version.
**  
**************************************************************************/

/*
**  Include files
*/
#include "..\..\project_cfg.h"    /* Project configuration            */
#include "..\..\Types.h"          /* Standard and Custom Data Types   */

/*
** External function declarations:
*/

#ifdef TARGET_PC

/**************************************************************************
** Function Name:   Get_KeyboardInput
**************************************************************************/
extern void Get_KeyboardInput(void);

/**************************************************************************
** Function Name:   Set_ScreenOutput
**************************************************************************/
extern void Set_ScreenOutput(void);


#endif /* TARGET_PC */

#endif /* KEY_SIM_H */
