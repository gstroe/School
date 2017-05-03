/*
 * LAB09.h
 *
 * Code generation for model "LAB09".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Apr 05 18:22:21 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_LAB09_h_
#define RTW_HEADER_LAB09_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef LAB09_COMMON_INCLUDES_
# define LAB09_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* LAB09_COMMON_INCLUDES_ */

#include "LAB09_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T UnaryMinus2;                  /* '<Root>/Unary Minus2' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T UnaryMinus;                   /* '<Root>/Unary Minus' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Gain_c;                       /* '<S4>/Gain' */
  real_T Gain_p;                       /* '<S5>/Gain' */
  boolean_T Compare;                   /* '<S1>/Compare' */
} B_LAB09_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOMinimums[2];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[2];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<Root>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *HILReadEncoder_PWORK;          /* '<Root>/HIL Read Encoder' */
  void *HILWriteAnalog_PWORK;          /* '<Root>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } Pendulum_PWORK;                    /* '<S3>/Pendulum' */

  struct {
    void *LoggedData;
  } Rotor_PWORK;                       /* '<S3>/Rotor' */

  int32_T HILInitialize_ClockModes;    /* '<Root>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<Root>/HIL Initialize' */
  int32_T HILReadEncoder_Buffer[2];    /* '<Root>/HIL Read Encoder' */
} DW_LAB09_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
} X_LAB09_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
} XDot_LAB09_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE;       /* '<Root>/Transfer Fcn2' */
} XDis_LAB09_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_LAB09_T_ {
  real_T HILInitialize_analog_output_max;/* Mask Parameter: HILInitialize_analog_output_max
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_output_min;/* Mask Parameter: HILInitialize_analog_output_min
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_analog_ou;/* Mask Parameter: HILInitialize_initial_analog_ou
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_e;/* Mask Parameter: HILInitialize_set_other_outpu_e
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outp_e1;/* Mask Parameter: HILInitialize_set_other_outp_e1
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_l;/* Mask Parameter: HILInitialize_set_other_outpu_l
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_analog_o;/* Mask Parameter: HILInitialize_watchdog_analog_o
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILInitialize_hardware_clocks;/* Mask Parameter: HILInitialize_hardware_clocks
                                         * Referenced by: '<Root>/HIL Initialize'
                                         */
  int32_T HILInitialize_initial_encoder_c;/* Mask Parameter: HILInitialize_initial_encoder_c
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  uint32_T HILInitialize_analog_output_cha[2];/* Mask Parameter: HILInitialize_analog_output_cha
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILReadEncoder_channels[2]; /* Mask Parameter: HILReadEncoder_channels
                                        * Referenced by: '<Root>/HIL Read Encoder'
                                        */
  uint32_T HILWriteAnalog_channels;    /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
  uint32_T HILInitialize_encoder_channels[2];/* Mask Parameter: HILInitialize_encoder_channels
                                              * Referenced by: '<Root>/HIL Initialize'
                                              */
  uint32_T HILInitialize_quadrature;   /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_d;/* Mask Parameter: HILInitialize_set_analog_inpu_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_j;/* Mask Parameter: HILInitialize_set_analog_outp_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_i;/* Mask Parameter: HILInitialize_set_analog_outp_i
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_k;/* Mask Parameter: HILInitialize_set_analog_outp_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_o;/* Mask Parameter: HILInitialize_set_analog_outp_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_kt;/* Mask Parameter: HILInitialize_set_analog_out_kt
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_p;/* Mask Parameter: HILInitialize_set_analog_outp_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_f;/* Mask Parameter: HILInitialize_set_clock_frequ_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_l;/* Mask Parameter: HILInitialize_set_clock_param_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_i;/* Mask Parameter: HILInitialize_set_digital_out_i
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_f;/* Mask Parameter: HILInitialize_set_digital_out_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_d;/* Mask Parameter: HILInitialize_set_digital_out_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_o;/* Mask Parameter: HILInitialize_set_digital_out_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_h;/* Mask Parameter: HILInitialize_set_digital_out_h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_k;/* Mask Parameter: HILInitialize_set_digital_out_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_m;/* Mask Parameter: HILInitialize_set_encoder_cou_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_d;/* Mask Parameter: HILInitialize_set_encoder_par_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outp_es;/* Mask Parameter: HILInitialize_set_other_outp_es
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_n;/* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_g;/* Mask Parameter: HILInitialize_set_pwm_outputs_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_m;/* Mask Parameter: HILInitialize_set_pwm_outputs_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__c;/* Mask Parameter: HILInitialize_set_pwm_params__c
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T Gain1_Gain;                   /* Expression: -2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2.5
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T ToRads_Gain;                  /* Expression: 2*pi/2048
                                        * Referenced by: '<S3>/To Rads'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -pi
                                        * Referenced by: '<S3>/Bias'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 30
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T ToRads1_Gain;                 /* Expression: -2*pi/2048
                                        * Referenced by: '<S3>/To Rads1'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D;               /* Computed Parameter: TransferFcn2_D
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T Constant_Value;               /* Expression: 30
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -2
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  boolean_T HILReadEncoder_Active;     /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<Root>/HIL Read Encoder'
                                        */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LAB09_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_LAB09_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][2];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_LAB09_T LAB09_P;

/* Block signals (auto storage) */
extern B_LAB09_T LAB09_B;

/* Continuous states (auto storage) */
extern X_LAB09_T LAB09_X;

/* Block states (auto storage) */
extern DW_LAB09_T LAB09_DW;

/* Model entry point functions */
extern void LAB09_initialize(void);
extern void LAB09_step(void);
extern void LAB09_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LAB09_T *const LAB09_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LAB09'
 * '<S1>'   : 'LAB09/Compare To Constant'
 * '<S2>'   : 'LAB09/Degrees to Radians'
 * '<S3>'   : 'LAB09/Subsystem'
 * '<S4>'   : 'LAB09/Subsystem/Radians to Degrees'
 * '<S5>'   : 'LAB09/Subsystem/Radians to Degrees1'
 */
#endif                                 /* RTW_HEADER_LAB09_h_ */
