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
**  Revision:    1.1.1.0
**  Edit Date:   01/15/2012
**
***************************************************************************
**
** Revision History:
** Revision: 1.2.1.0    01/15/2015   B.Sweet
** * Add prototypes for KeySim_Init() and Accessors for UserInput signal.
**
** Revision: 1.1     9/15/2011   Alex Campbell
** * Add signal definitions.
**
** Revision: 1.0     9/ 7/2010   Benjamin Sweet
** * Original version.
**  
**************************************************************************/

/*
**  Include files
*/
#include "..\..\project_cfg.h"    /* Project configuration            */
#include "..\..\Types.h"          /* Standard and Custom Data Types   */

/* Component Configuration: */
#include "KeySim_cfg.h"

/*
** External function declarations:
*/

#ifdef TARGET_PC

/*
** External Function Declaration:
*/

/*
** Local Function Prototypes:
*/
  /* Methods: */
  extern void       Get_KeyboardInput(void);
  extern void       Set_ScreenOutput(void);
  extern void       KeySim_Init(void);

  /* Accessors: */
  extern void       Set_UserInput(int16_t value);
  extern int16_t    Get_UserInput(void);


#endif /* TARGET_PC */

#endif /* KEY_SIM_H */
