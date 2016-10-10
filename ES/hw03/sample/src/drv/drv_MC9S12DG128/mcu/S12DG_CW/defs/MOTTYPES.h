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
 
/*****************************************************************************/
/*                                                                           */
/* FILE NAME: MOTTYPES.h                                                     */
/*                                                                           */
/* PURPOSE: Header file for S12 common definitions           	 		           */
/*                                                                           */
/* DESCRIPTION:  common definitions for Star12 core registers block.         */
/* The standard definitions used to describe register datastructures.        */
/* The following conventions are used -                                      */           
/*                                                                           */
/* names starting with 's' followed by a capital letter denote structs       */
/* names starting with 'u' followed by a capital letter denote unions        */
/* names starting with 't' followed by a capital letter denote typedefs      */
/*                                                                           */
/* MCU register definition is done in separate files, describing each        */
/* peripheral register block as a datastructure. Register naming follows as  */ 
/* close as possible the names used in the device specification.             */
/* Registers containing individual flags are defined as a union of the byte  */ 
/* and as a bitfield structure.                                              */
/*                                                                           */
/* Compiler issues (portability) -                                           */
/* ANSI C defines bitfields as 'int', obviously a problem when defining 8 bit*/
/* registers, most compilers have options to modify this.                    */
/* Cosmic compiler doesn't have a switch, but allows bitfields to be defined */ 
/* as chars.                                                                 */
/* ANSI C does not define bitfield ordering (LSB first in used), other       */
/* compilers may require modification to these files or use of a compiler    */
/* switch.                                                                   */
/*                                                                           */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB      LAST EDIT DATE: 26.07.01         */
/*                                                                           */
/*****************************************************************************/

#ifndef MOTTYPES_H        /*prevent duplicated includes*/
#define MOTTYPES_H

/*Warning Disable*/
#pragma MESSAGE DISABLE C1106		//Non-Standard Bitfields

/******************************************************************************
Standard Definitions

These defines allow for easier porting to other compilers. if porting change
these defines to the required values for the chosen compiler.
******************************************************************************/

typedef unsigned char   tU08;   /*unsigned 8 bit definition */
typedef unsigned int    tU16;   /*unsigned 16 bit definition*/
typedef unsigned long   tU32;   /*unsigned 32 bit definition*/
typedef signed char     tS08;   /*signed 8 bit definition */
typedef int      		tS16;   /*signed 16 bit definition*/
typedef long int    	tS32;   /*signed 32 bit definition*/


#ifndef UINT8
#define	UINT8	tU08			/* unsigned 8-bit */	
#define	UINT16	tU16			/* unsigned 16-bit */
#define	UINT32	tU32			/* unsigned 32-bit */
#define	INT8	tS08			/* signed 8-bit */
#define	INT16	tS16			/* signed 16-bit */
#define	INT32	tS32			/* signed 32-bit */
#endif /* UINT8 */

typedef union uREG08    /*8 bit register with byte and bit access*/
  {
  tU08  byte;           /*access whole register e.g. var.byte   = 0xFF;*/
  struct                /*access bit at a time  e.g. var.bit._7 = 1;   */
    {
    tU08 _0 :1;
    tU08 _1 :1;
    tU08 _2 :1;
    tU08 _3 :1;
    tU08 _4 :1;
    tU08 _5 :1;
    tU08 _6 :1;
    tU08 _7 :1;  
    }bit;
  }tREG08;

typedef union uREG16    /*16 bit register with word and byte access*/
  {
  tU16  word;           /*access whole word    */
  struct                /*access byte at a time*/
    {
    tREG08  msb;
    tREG08  lsb;
    }byte;
  }tREG16;

/******************************************************************************
Common Bit masks
******************************************************************************/

#define BIT0    0x01    
#define BIT1    0x02
#define BIT2    0x04
#define BIT3    0x08
#define BIT4    0x10
#define BIT5    0x20
#define BIT6    0x40
#define BIT7    0x80


#endif /*MOTTYPES_H */
