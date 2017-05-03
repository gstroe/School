/*
 * q_qube_swingup_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&q_qube_swingup_B.HILReadEncoderTimebase_o1), 0, 0, 40 },

  { (char_T *)(&q_qube_swingup_B.Compare), 3, 0, 1 },

  { (char_T *)(&q_qube_swingup_B.LowerRelop1), 8, 0, 2 }
  ,

  { (char_T *)(&q_qube_swingup_DW.HILInitialize_AOMinimums[0]), 0, 0, 8 },

  { (char_T *)(&q_qube_swingup_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&q_qube_swingup_DW.HILReadEncoderTimebase_Task), 15, 0, 1 },

  { (char_T *)(&q_qube_swingup_DW.HILWriteAnalog_PWORK), 11, 0, 5 },

  { (char_T *)(&q_qube_swingup_DW.HILInitialize_ClockModes), 6, 0, 7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&q_qube_swingup_P.Jp), 0, 0, 20 },

  { (char_T *)(&q_qube_swingup_P.HILReadEncoderTimebase_clock), 6, 0, 3 },

  { (char_T *)(&q_qube_swingup_P.HILInitialize_analog_output_cha[0]), 7, 0, 9 },

  { (char_T *)(&q_qube_swingup_P.HILInitialize_active), 8, 0, 33 },

  { (char_T *)(&q_qube_swingup_P.uKx_Gain[0]), 0, 0, 29 },

  { (char_T *)(&q_qube_swingup_P.HILReadEncoderTimebase_Active), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] q_qube_swingup_dt.h */
