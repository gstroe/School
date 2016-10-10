/*************************************************************************
 * Copyright (C) 2006 by Freescale Semiconductor Inc. All rights reserved*
 *************************************************************************
 *                                                                       *
 *   Freescale reserves the right to make changes without further notice *
 *   to any product herein to improve reliability, function or design.   *
 *   Freescale does not assume any liability arising out of the          *
 *   application or use of any product, circuit, or software described   *
 *   herein; neither does it convey any license under its patent rights  *
 *   nor the rights of others.                                           *
 *                                                                       *
 *   Freescale products are not designed, intended, or authorized for    *
 *   use as components in systems intended for surgical implant into     *
 *   the body, or other applications intended to support life, or for    *
 *   any other application in which the failure of the Motorola product  *
 *   could create a situation where personal injury or death may occur.  *
 *                                                                       *
 *   Should Buyer purchase or use Freescale products for any such        *
 *   unintended or unauthorized application, Buyer shall indemnify and   *
 *   hold Freescale and its officers, employees, subsidiaries,           *
 *   affiliates, and distributors harmless against all claims costs,     *
 *   damages, and expenses, and reasonable attorney fees arising out     *
 *   of, directly or indirectly, any claim of personal injury or death   *
 *   associated with such unintended or unauthorized use, even if such   *
 *   claim alleges that Freescale was negligent regarding the design     *
 *   or manufacture of the part.                                         *
 *                                                                       *
 *   Freescale and the Freescale logo* are registered trademarks of      *
 *   Freescale Inc.                                                      *
 *                                                                       *
 *************************************************************************/

/*************************************************************************
 *                                                                       *
 *                  Freescale S12UB Stand Alone                          *
 *                 Target Circuitry Test Software                        *
 *                                                                       *
 *************************************************************************/
 
/*************************************************************************
*                                               
* FILE NAME: projectdefines.h                                        
*                                                                           
* PURPOSE: header file for project level defines and external reference to 
*          IC registers. Each C source file has a companion .h file to 
*          declare functions. Sharing is allowed because extern is implied
*          with function prototypes. 
*                                                                           
*                                                                           
*                                                                           
* AUTHOR: BB       
*                                                                                                                                                
**************************************************************************/

#ifndef PROJECTDEFINES_H        /*prevent duplicated includes*/
#define PROJECTDEFINES_H

/*************************************************************************
* Global Includes															                           * 
**************************************************************************/

#include <hidef.h>				    //Includes Code Warrior definitions	

#define Dx128_L40K

/*************************************************************************
* ROUTINE: MCU Peripherals
*
* DESCRIPTION:  Includes MCU_Maskset peripheral file from project 
*				        definitions library.        
*                                                                           
* NOTE: Modify by selecting which maskset to include into your main 
*		    application by uncommenting the appropriate define at the top
*		    of projectglobals.h (MCU_Maskset Selection)                                           
*                                                            
**************************************************************************/

#ifdef Dx128_L40K
#include "per_Dx128_L40K.h"	
#define Flash_Sector_Size 0x200	
#endif /*Dx128_L40K*/

/*************************************************************************
* Macro Definitions	and project level defines                        	   *
**************************************************************************/

#define int_enable()  {asm andcc   #0xEF;}	  //interrupts enabled
#define int_disable() {asm orcc    #0x10;}	  //interrupts disabled
#define wait()        {asm wait;}			        //enter wait mode
#define stop_enable() {asm andcc   #0x7F;}	  //stop mode enabled
#define stop()        {asm stop;}			        //enter stop mode
#define nop()         {asm nop;}			        //enter NOP asm instruction
#define bgnd()        {asm bgnd; asm nop;}	  //enter BGND asm instruction

#define xirq_disabled() {asm orcc    #0x40;}	//XIRQ interrupt disabled


#define ON 1								    //ON 
#define OFF 0								    //OFF
#define TRUE 1								  //TRUE
#define FALSE 0								  //FALSE	
#define PASS 0u								  //PASS	
#define FAIL 1u								  //FAIL 	
#define SET 1u								  //SET	
#define CLEAR 0u							  //CLEAR	


#endif /*PROJECTDEFINES_H*/
