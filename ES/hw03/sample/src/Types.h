#ifndef _TYPES_H
#define _TYPES_H
/**************************************************************************
**
** Module Name:   Types.h
**
** Module Description:  Type (Re-)Definitions for standard data types.
**
***************************************************************************
**
** Author:      Benjamin D. Sweet
** Revision:    1.7
** Creation Date: 07-Jun-2008
** Edit Date:     31-May-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.7    31-May-2012    B. Sweet
** * Add fixed/exact-width integer data types for signed values:
**   sint8_t , sint16_t , etc. and the associated MIN and MAX definitions.
**
**   The standard signed data types (int8_t, etc.) do not contain an inherent
**   reminder that they represent signed values.  These data types are intended
**   to prevent possible confusion of signed "int" data types as un-signed. 
**
** Revision: 1.6    27-Jan-2011    B. Sweet
** * Remove conditional definitions of TRUE and FALSE.
** * #include <stdtypes.h> for "standard" definition of TRUE and FALSE.
**
** Revision: 1.5    16-Sept-2010   B. Sweet
** * Conditional definitions for TRUE and FALSE.
**
** Revision: 1.4    25-June-2009   B. Sweet
** * Define Unsigned Int MAX values as Unsigned.
**
** Revision: 1.3    24-June-2009   B. Sweet
** * Correct error in "#if !defined" conditional compile switches.
**
** Revision: 1.2    17-June-2009   B. Sweet
** * Added typedefs C-99 Exact-Width Integer data types and #defines for associated limit values.
**   Re: http://en.wikipedia.org/wiki/Stdint.h#Exact-width_integer_types_.28optional.29
**
** Revision: 1.1    20-June-2008   B. Sweet
** * Added typedefs for H_FSM.
**   Re: http://robertolanuza.tripod.com/fsm/fsm.htm
**      "Finite State Machine Editor and C-code generator"
**
** Revision: 1.0     7-June-2008   B. Sweet
** * Original version from MOTTYPES.h.
**   Re-definition of "fixed-width" integer data types based on common practice.
**  
**************************************************************************/

/******************************************************************************
These Typedefs and #defines allow for easier porting to other compilers.
If porting change these defines to the required values for the chosen compiler.
******************************************************************************/

/* ISO C9x  7.18  Integer types <stdint.h>
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  Contributor: Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2000-12-02
 */
/* 7.18.1.1  Exact-width integer types */
#if !defined (_STDINT_H) && !defined (int8_t)       /* prevent duplicated typedefs */
 typedef signed   char        int8_t;
 typedef unsigned char        uint8_t;
 typedef short                int16_t;
 typedef unsigned short       uint16_t;
 typedef signed   long        int32_t;
 typedef unsigned long        uint32_t;
 typedef signed   long long   int64_t;
 typedef unsigned long long   uint64_t;

 /*
 ** NON-Standard Data Types!  These data types are intended to prevent possible
 ** confusion of signed "int" data types as un-signed.
 */
 typedef signed   char        sint8_t;
 typedef short                sint16_t;
 typedef signed   long        sint32_t;
 typedef signed   long long   sint64_t;

#endif /* .NOT. _STDINT_H .AND. .NOT. int8_t */

#if !defined (_STDINT_H) && !defined (INT8_MIN)     /* prevent duplicated defines */
 /* 7.18.2.1  Limits of exact-width integer types */
 #define INT8_MIN   (-128) 
 #define INT16_MIN  (-32768)
 #define INT32_MIN  (-2147483647 - 1)
 #define INT64_MIN  (-9223372036854775807LL - 1)

 #define INT8_MAX   (127)
 #define INT16_MAX  (32767)
 #define INT32_MAX  (2147483647)
 #define INT64_MAX  (9223372036854775807LL)

 #define UINT8_MAX  (0xffU)   /* 255U */
 #define UINT16_MAX (0xffffU) /* 65535U */
 #define UINT32_MAX (0xffffffffU)  /* 4294967295U */
 #define UINT64_MAX (0xffffffffffffffffULL) /* 18446744073709551615ULL */

 /*
 ** NON-Standard Definitions!  These definitions are intended to prevent possible
 ** confusion of signed "int" data types as un-signed.
 */
 #define SINT8_MIN  (-128) 
 #define SINT16_MIN (-32768)
 #define SINT32_MIN (-2147483647 - 1)
 #define SINT64_MIN (-9223372036854775807LL - 1)

 #define SINT8_MAX  (127)
 #define SINT16_MAX (32767)
 #define SINT32_MAX (2147483647)
 #define SINT64_MAX (9223372036854775807LL)

#endif /* .NOT. _STDINT_H .AND. .NOT. INT8_MIN */


#ifndef tU08         /* prevent duplicated defines */
 typedef unsigned char   tU08;   /*unsigned 8 bit definition */
 typedef unsigned int    tU16;   /*unsigned 16 bit definition*/
 typedef unsigned long   tU32;   /*unsigned 32 bit definition*/
 typedef signed char     tS08;   /*signed 8 bit definition */
 typedef int             tS16;   /*signed 16 bit definition*/
 typedef long int        tS32;   /*signed 32 bit definition*/
#endif /* tU08 */

#ifndef uint8        /* prevent duplicated defines */
 #define  uint8    tU08  /* unsigned  8-bit */
 #define  uint16   tU16  /* unsigned 16-bit */
 #define  uint32   tU32  /* unsigned 32-bit */
 #define  int8     tS08  /* signed    8-bit */
 #define  int16    tS16  /* signed   16-bit */
 #define  int32    tS32  /* signed   32-bit */
#endif /* uint8 */

#ifndef UINT8        /* prevent duplicated defines */
 #define  UINT8    tU08  /* unsigned  8-bit */
 #define  UINT16   tU16  /* unsigned 16-bit */
 #define  UINT32   tU32  /* unsigned 32-bit */
 #define  INT8     tS08  /* signed    8-bit */
 #define  INT16    tS16  /* signed   16-bit */
 #define  INT32    tS32  /* signed   32-bit */
#endif /* UINT8 */


#ifndef MOTTYPES_H   /* prevent duplicated defines */
/******************************************************************************
Standard Definitions from MOTTYPES.H
******************************************************************************/

typedef union uREG08    /*8 bit register with byte and bit access*/
{
  tU08  byte;           /*access whole register e.g. var.byte   = 0xFF;*/
  struct                /*access bit at a time  e.g. var.bit._7 = 1;   */
  {
    tU08 Bit0 :1;
    tU08 Bit1 :1;
    tU08 Bit2 :1;
    tU08 Bit3 :1;
    tU08 Bit4 :1;
    tU08 Bit5 :1;
    tU08 Bit6 :1;
    tU08 Bit7 :1;  
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
#if(0)
/* These definitions cause a conflict with bit-structure bit names in mc9s12dg128.h */ 
 #define BIT0    0x01    
 #define BIT1    0x02
 #define BIT2    0x04
 #define BIT3    0x08
 #define BIT4    0x10
 #define BIT5    0x20
 #define BIT6    0x40
 #define BIT7    0x80
#endif
#endif /* MOTTYPES_H */


/*
** H_FSM types:
** Re: http://robertolanuza.tripod.com/fsm/fsm.htm
**     "Finite State Machine Editor and C-code generator"
*/
#ifndef _FSM_TYPES_H_
#define _FSM_TYPES_H_
    typedef unsigned char   T_bit;
    typedef unsigned char   T_u8;
    typedef char            T_char;
    typedef unsigned short  T_u16;
#endif  /* _FSM_TYPES_H_ */

/*
**  TRUE and FALSE:
*/
#if defined(TARGET_S12UB)
 #include <stdtypes.h>  /* Standard Type Definitions */


#elif defined(TARGET_PC)  /* Visual Studio can't find <stdtypes.h>... */
 #ifndef FALSE
   #define FALSE (0u)
 #endif /* FALSE */
 #ifndef TRUE
   #define TRUE  (1u)
 #endif /* TRUE */


#endif /* TARGET */


#endif /* _TYPES_H */
