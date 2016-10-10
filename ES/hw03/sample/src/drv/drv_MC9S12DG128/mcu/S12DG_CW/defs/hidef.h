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
 
/*****************************************************
 hidef.h - ANSI-C library: machine dependent stuff
 ----------------------------------------------------
 Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

/*************************************************************************
 * Local project copy.                                                   *
 *                                                                       *
 *                 No modifications from original                        *
 *                                                                       *
 *************************************************************************/

#ifndef _H_HIDEF_
#define _H_HIDEF_

#ifdef __cplusplus
extern "C" {
#endif

/**** Version for MC68HC12 */

#include "default.sgm"

#ifdef  __BANKED__
#define __MEDIUM__
#endif

#include <stdtypes.h>
#include <stddef.h>

#define CLOCKS_PER_SEC 8000000 /* has to be user defined */
#pragma NO_STRING_CONSTR   /* allow '#' in HLI below */
#define HALT               {__asm CLRB; __asm SWI;}
#define HALTX(x)           {/*lint -e522 */ __asm LDAB x; __asm SWI; /*lint +e522 */} 
#define HALT_AND_QUIT      HALTX(#32)
#define EnableInterrupts   {__asm CLI;}
#define DisableInterrupts  {__asm SEI;}

/* COP macros */
#if defined(_HCS12) || defined(HCS12) || defined(__HCS12__)
#define _COPCTL_ADR  (0x34+0x08)
#define _COP_RST_ADR (0x34+0x0B) /* ARMCOP */
#else
#define _COPCTL_ADR  0x16
#define _COP_RST_ADR 0x17
#endif

/* Note COPCTL is write once. */
#define _ENABLE_COP(period)   ((*(volatile unsigned char*)_COPCTL_ADR)= (period)) /* Note: 7 longest posible COP duration. 0 == COP disabled. */
#define _ENABLE_COP_X() _ENABLE_COP(7) /* as long as possible */
#define _DISABLE_COP() _ENABLE_COP(0x00) /* COP is disabled if period is 0 */
#define _FEED_COP()   ((*(volatile unsigned char*)_COP_RST_ADR)= 0x55,(*(volatile unsigned char*)_COP_RST_ADR)= 0xAA)

#if __STDC__ && 0
  /* with strict ANSI, the far/near keywords are not allowed */
  #define far
  #define near
#endif

#ifdef __ELF_OBJECT_FILE_FORMAT__
  #define INIT_SP_FROM_STARTUP_DESC()   __asm LDS _startupData.stackOffset;
#else
  #define INIT_SP_FROM_STARTUP_DESC()   __asm LDS  _startupData.stackOffset:2;
#endif


/*-------------------- tabled functions used with options -ot -oilib=g ----------------*/

/* 1 << char */
extern const unsigned char _PowOfTwo_8[8];
/* 1 << int */
extern const unsigned short _PowOfTwo_16[16];
/* 1L << long */
extern const unsigned long _PowOfTwo_32[32];


/* PIC support for runtime library. Generate all calls PIC, if option is present */

#ifdef __PIC__
#define __PIC_JSR(dest) JSR dest,pcr
#define __PIC_JMP(dest) JMP dest,pcr
#else
#define __PIC_JSR(dest) JSR dest
#define __PIC_JMP(dest) JMP dest
#endif


#ifdef __cplusplus
 }
#endif

#endif
/*****************************************************/
/* end hidef.h */
