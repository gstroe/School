/*****************************************************
 stdtypes.h - ANSI-C library: standard type typedefs
              defines some usefull stuff not in the
              official ANSI library
 ----------------------------------------------------
 Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_STDTYPES_
#define _H_STDTYPES_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__HIWARE__)
  #define __CAN_HANDLE_LONG_LONG__ /* we accept 'long long' types */
#endif

typedef void (*PROC)(void); /* parameterless function pointer (Procedure variable) */

/* define Byte and sByte */
#if defined(__CHAR_IS_8BIT__)
  typedef  unsigned char      Byte;
  typedef    signed char      sByte;
#elif defined(__SHORT_IS_8BIT__)
  typedef  unsigned short     Byte;
  typedef    signed short     sByte;
#elif defined(__INT_IS_8BIT__)
  typedef  unsigned int       Byte;
  typedef    signed int       sByte;
#elif defined(__LONG_IS_8BIT__)
  typedef  unsigned long      Byte;
  typedef    signed long      sByte;
#elif defined(__LONG_LONG_IS_8BIT__)
  typedef  unsigned long long Byte;
  typedef    signed long long sByte;
#else /* default */
  typedef  unsigned char      Byte;
  typedef    signed char      sByte;
#endif

/* define Word and sWord */
#if defined(__CHAR_IS_16BIT__)
  typedef  unsigned char      Word;
  typedef    signed char      sWord;
#elif defined(__SHORT_IS_16BIT__) && !defined(__INT_IS_16BIT__)
  typedef  unsigned short     Word;
  typedef    signed short     sWord;
#elif defined(__INT_IS_16BIT__)
  typedef  unsigned int       Word;
  typedef    signed int       sWord;
#elif defined(__LONG_IS_16BIT__)
  typedef  unsigned long      Word;
  typedef    signed long      sWord;
#elif defined(__LONG_LONG_IS_16BIT__)
  typedef  unsigned long long Word;
  typedef    signed long long sWord;
#else
  typedef  unsigned short     Word;
  typedef    signed short     sWord;
#endif

/* define LWord and sLWord */
#if defined(__CHAR_IS_32BIT__)
  typedef  unsigned char      LWord;
  typedef    signed char      sLWord;
#elif defined(__SHORT_IS_32BIT__)
  typedef  unsigned short     LWord;
  typedef    signed short     sLWord;
#elif defined(__INT_IS_32BIT__)
  typedef  unsigned int       LWord;
  typedef    signed int       sLWord;
#elif defined(__LONG_IS_32BIT__)
  typedef  unsigned long      LWord;
  typedef    signed long      sLWord;
#elif defined(__LONG_LONG_IS_32BIT__)
  typedef  unsigned long long LWord;
  typedef    signed long long sLWord;
#else /* default */
  typedef  unsigned short LWord;
  typedef    signed short sLWord;
#endif

typedef  unsigned char      uchar;
typedef  unsigned int       uint;
typedef  unsigned long      ulong;
#ifdef __CAN_HANDLE_LONG_LONG__
typedef  unsigned long long ullong;
#endif

typedef  signed char        schar;
typedef  signed int         sint;
typedef  signed long        slong;
#ifdef __CAN_HANDLE_LONG_LONG__
typedef  signed long long   sllong;
#endif

/* define the enum_t type */
#if defined(__ENUM_IS_8BIT__)
  #if defined(__ENUM_IS_UNSIGNED__)
    typedef Byte   enum_t;
    #elif defined(__ENUM_IS_SIGNED__)
    typedef sByte  enum_t;
    #else
      #error "illegal sign of enum"
    #endif
#elif defined(__ENUM_IS_16BIT__)
  #if defined(__ENUM_IS_UNSIGNED__)
      typedef Word   enum_t;
    #elif defined(__ENUM_IS_SIGNED__)
      typedef sWord  enum_t;
    #else
      #error "illegal sign of enum"
    #endif
#elif defined(__ENUM_IS_32BIT__)
  #if defined(__ENUM_IS_UNSIGNED__)
      typedef LWord   enum_t;
    #elif defined(__ENUM_IS_SIGNED__)
      typedef sLWord  enum_t;
    #else
      #error "illegal sign of enum"
    #endif
#else /* default */
  typedef sWord  enum_t;
#endif

typedef int Bool;
#define TRUE  1
#define FALSE 0

#ifdef __cplusplus
 }
#endif

#endif
/*****************************************************/
/* end stdtypes.h */
