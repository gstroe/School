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
* FILE NAME: projectglobals.c                                        
*                                                                           
* PURPOSE: Central place to declare global variables. Global scope is done
*          through projectglobals.h using EXTERN. Each entry in this
*          file has a companion entry in projectglobals.h. 
*                                                                           
*                                                                           
*                                                                           
* AUTHOR: BB       
*                                                                                                                                                
**************************************************************************/

/*************************************************************************
* Global variable declarations                                           *
*								  																											 *
**************************************************************************/

unsigned char rti_blink_off_cnt; 
unsigned char rti_blink_on_cnt;

unsigned char ucCST;      // RTI control state
unsigned char ucTEMP1;    // uc TEMP 1
unsigned char ucFLAG1;    // uc FLAG 1
unsigned char ucFLAG2;    // uc FLAG 2
unsigned char ucSPI_LSB;
unsigned char ucSPI_MSB;





