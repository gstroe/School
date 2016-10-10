#ifndef PROJECT_CFG_H
#define PROJECT_CFG_H
/**************************************************************************
**
** Module Name:   project_cfg.h
**
** Module Description:
**
** Project Configuration:
** * Definition of overal project settings, such as DEBUG
**
** * Mapping of Applicaiton Generic inputs, outputs, and other parameters to
**   target specific resources.
**
***************************************************************************
**
** Author:      Benjamin D. Sweet
** Revision:    1.4
** Creation Date: 06-Jun-2008
** Edit Date:     11-Sep-2015
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.4    11-Sep-2015   B. Sweet
** * Added conditional switch for USE_SIMPLE_HAL.
**   Used to switch between using the AUTOSAR configuration tables in
**    dio_cfg.c or a simplified (more "hard-wired") Hardware Abstraction
**    Layer (HAL).
**
** Revision: 1.3    06-Jun-2012   B. Sweet
** * Moved definition of InterruptEnable() to mcu_cfg.h.
**
** Revision: 1.2    05-May-2012   B. Sweet
** * Added conditional switch for MICROCONTROLLER_SIM.
**
** Revision: 1.1    20-Jun-2008   B. Sweet
** * Added conditional switch for MXVDEV.
**
** Revision: 1.0    06-Jun-2008   B. Sweet
** * Working prototype for S12UB and PC Target environments.
**
**************************************************************************/

/*
** Generic Include files:
*/

/*
** DEBUG option:
**  xDEBUG - For Production (i.e.: NO DEBUG)
**   DEBUG - For Debug
*/
#ifndef MXVDEV  /* DEBUG is defined in the MxVDev project */
  #define DEBUG
#endif

/*
** Define the desired target
**
** Note: The TARGET symbol could be defined in a "Build Script", compiler configuration, or some other means.
**
**       The symbol MXVDEV is defined by the MxVDev Visual Studio project. 
*/

#define TARGET_S12UB
#define xTARGET_PC

/*
** Microcontroller Simulation:
**  For Microcontroller Targets, this switch can be used to customize port register
**  configuration for hardware simulaiton environments (such as HC12 Full Chip Simulation).
*/
#if defined TARGET_S12UB
 #define MICROCONTROLLER_SIM
#endif /* TARGET */

/*
** UPDATE this list as new targets are added
*/
#if (!defined(TARGET_S12UB) && !defined(TARGET_PC))
   #error "A Target must be specified in project_cfg.h."
#endif


/*
** Project-level Definitions and Configurations: 
*/

/*
**  Use Simple HAL - Hardware Abstraction Layer:
**
**  Used to switch between using the AUTOSAR configuration tables in dio_cfg.c
**  or a simplified (more "hard-wired") Hardware Abstraction Layer(HAL).
*/
#define USE_SIMPLE_HAL		/* USE_SIMPLE_HAL to use HAL ;  xUSE_SIMPLE_HAL to use AUTOSAR configuration tables. */


/*
** Target Specifc Configurations:
*/

#ifndef MXVDEV
 #if defined TARGET_S12UB
 /*
 ** Target is S12 University Board:
 */
   /*
   ** Target Specific Include files:
   */
   #include <hidef.h>      /* common defines and macros */
   #include <mc9s12dg128.h>     /* derivative information */
   #pragma LINK_INFO DERIVATIVE "mc9s12dg128b"

 #elif defined TARGET_PC
 /*
 ** Target is PC:
 */
   /*
   ** Target Specific Include files:
   */
// #include "main.h"

   /*
   ** Target-specific mapping to Input and Output Ports & Registers:  
   */
   #define OutputPort   (PortA.byte)
   #define InputPort    (PortB.byte)

   #define PORTA (PortA.byte)
   #define PA0   (PortA.bit.Bit0)
   #define PA1   (PortA.bit.Bit1)
   #define PA2   (PortA.bit.Bit2)
   #define PA3   (PortA.bit.Bit3)
   #define PA4   (PortA.bit.Bit4)
   #define PA5   (PortA.bit.Bit5)
   #define PA6   (PortA.bit.Bit6)
   #define PA7   (PortA.bit.Bit7)

   #define PORTB (PortB.byte)
   #define PB0   (PortB.bit.Bit0)
   #define PB1   (PortB.bit.Bit1)
   #define PB2   (PortB.bit.Bit2)
   #define PB3   (PortB.bit.Bit3)
   #define PB4   (PortB.bit.Bit4)
   #define PB5   (PortB.bit.Bit5)
   #define PB6   (PortB.bit.Bit6)
   #define PB7   (PortB.bit.Bit7)

 #endif /* TARGET */
#endif /* MXVDEV */


#endif /* PROJECT_CFG_H */
