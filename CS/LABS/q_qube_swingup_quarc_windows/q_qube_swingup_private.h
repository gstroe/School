/*
 * q_qube_swingup_private.h
 *
 * Code generation for model "q_qube_swingup".
 *
 * Model version              : 1.444
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Apr 12 18:20:32 2017
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_q_qube_swingup_private_h_
#define RTW_HEADER_q_qube_swingup_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void q_qube_swingup_derivatives(void);

#endif                                 /* RTW_HEADER_q_qube_swingup_private_h_ */
