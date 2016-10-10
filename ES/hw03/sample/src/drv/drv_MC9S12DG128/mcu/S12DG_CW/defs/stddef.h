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
   stddef.h - ANSI-C library: standard definitions
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
 

#ifndef _H_STDDEF_
#define _H_STDDEF_

#ifdef __cplusplus
extern "C" {
#endif

/* size_t: defines the maximum object size type */
#if defined(__SIZE_T_IS_UCHAR__)
  typedef unsigned char  size_t;
#elif defined(__SIZE_T_IS_USHORT__)
  typedef unsigned short size_t;
#elif defined(__SIZE_T_IS_UINT__)
  typedef unsigned int   size_t;
#elif defined(__SIZE_T_IS_ULONG__)
  typedef unsigned long  size_t;
#else
  typedef unsigned int   size_t;
#endif

/* ptrdiff_t: defines the maximum pointer difference type */
#if defined(__PTRDIFF_T_IS_CHAR__)
  typedef signed char   ptrdiff_t;
#elif defined(__PTRDIFF_T_IS_SHORT__)
  typedef signed short  ptrdiff_t;
#elif defined(__PTRDIFF_T_IS_INT__)
  typedef signed int    ptrdiff_t;
#elif defined(__PTRDIFF_T_IS_LONG__)
  typedef signed long   ptrdiff_t;
#else
  typedef signed int    ptrdiff_t;
#endif

/* wchar_t: defines the type of wide character */
#if defined(__WCHAR_T_IS_UCHAR__)
  typedef unsigned char  wchar_t;
#elif defined(__WCHAR_T_IS_USHORT__)
  typedef unsigned short wchar_t;
#elif defined(__WCHAR_T_IS_UINT__)
  typedef unsigned int   wchar_t;
#elif defined(__WCHAR_T_IS_ULONG__)
  typedef unsigned long  wchar_t;
#else
  typedef unsigned char  wchar_t;
#endif


typedef unsigned long clock_t;
typedef unsigned long time_t;

#define offsetof(type, member) ((size_t) &(((type *) 0)->member))
#define NULL                   ((void *) 0)

#ifdef __cplusplus
 }
#endif

#endif

/*****************************************************/
/* end stddef.h */
