/*
 * q_qube_swingup.h
 *
 * Code generation for model "q_qube_swingup".
 *
 * Model version              : 1.444
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Apr 12 18:24:49 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_q_qube_swingup_h_
#define RTW_HEADER_q_qube_swingup_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef q_qube_swingup_COMMON_INCLUDES_
# define q_qube_swingup_COMMON_INCLUDES_
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
#endif                                 /* q_qube_swingup_COMMON_INCLUDES_ */

#include "q_qube_swingup_types.h"

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
  real_T HILReadEncoderTimebase_o1;    /* '<Root>/HIL Read Encoder Timebase' */
  real_T HILReadEncoderTimebase_o2;    /* '<Root>/HIL Read Encoder Timebase' */
  real_T Pendulumcountstorad;          /* '<S1>/Pendulum:  counts to rad' */
  real_T MathFunction;                 /* '<S1>/Math Function' */
  real_T Bias;                         /* '<S1>/Bias' */
  real_T alpha;                        /* '<Root>/|alpha|' */
  real_T SliderGain;                   /* '<S8>/Slider Gain' */
  real_T cosalpha;                     /* '<S10>/cos(alpha)' */
  real_T Sum1;                         /* '<S10>/Sum1' */
  real_T PendTorqueNm;                 /* '<S10>/Pend Torque (N.m)' */
  real_T alpha_dot;                    /* '<Root>/alpha_dot' */
  real_T alpha_dot2;                   /* '<S10>/alpha_dot^2' */
  real_T PendInertiakgm2;              /* '<S10>/Pend Inertia (kg.m^2)' */
  real_T Energy;                       /* '<S10>/Energy' */
  real_T SliderGain_j;                 /* '<S3>/Slider Gain' */
  real_T mJtoJ;                        /* '<S7>/mJ to J' */
  real_T cosalpha_g;                   /* '<S9>/cos(alpha)' */
  real_T UnaryMinus;                   /* '<S9>/Unary Minus' */
  real_T Armcountstorad;               /* '<S1>/Arm: counts to rad' */
  real_T theta_dot;                    /* '<S6>/theta_dot' */
  real_T alpha_dot_b;                  /* '<S6>/alpha_dot' */
  real_T EnableBalanceControlSwitch;   /* '<Root>/Enable Balance Control Switch' */
  real_T ForveCCW;                     /* '<Root>/For +ve CCW' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T JtomJ;                        /* '<S7>/J to mJ' */
  real_T Gain_b;                       /* '<S5>/Gain' */
  real_T alpha_dotcosalpha;            /* '<S9>/alpha_dot*cos(alpha)' */
  real_T Sign;                         /* '<S9>/Sign' */
  real_T EEr;                          /* '<S9>/E-Er' */
  real_T EErsigna_dotcosa;             /* '<S9>/(E-Er)*sign(a_dot*cos(a))' */
  real_T Product;                      /* '<S9>/Product' */
  real_T Switch2;                      /* '<S11>/Switch2' */
  real_T AccelerationtoTorque;         /* '<S7>/Acceleration to Torque' */
  real_T TorquetoVoltage;              /* '<S7>/Torque to Voltage' */
  real_T Switch;                       /* '<S11>/Switch' */
  real_T Sum[4];                       /* '<Root>/Sum' */
  real_T uKx;                          /* '<Root>/u = -K*x' */
  uint8_T Compare;                     /* '<S2>/Compare' */
  boolean_T LowerRelop1;               /* '<S11>/LowerRelop1' */
  boolean_T UpperRelop;                /* '<S11>/UpperRelop' */
} B_q_qube_swingup_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOMinimums[2];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[2];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<Root>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<Root>/HIL Read Encoder Timebase' */
  void *HILWriteAnalog_PWORK;          /* '<Root>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } MotorVoltageV_PWORK;               /* '<Root>/Motor Voltage (V)' */

  struct {
    void *LoggedData;
  } Pendulumdeg_PWORK;                 /* '<Root>/Pendulum (deg)' */

  struct {
    void *LoggedData;
  } PendulumEnergymJ_PWORK;            /* '<Root>/Pendulum Energy (mJ)' */

  struct {
    void *LoggedData;
  } RotaryArmdeg_PWORK;                /* '<Root>/Rotary Arm (deg)' */

  int32_T HILInitialize_ClockModes;    /* '<Root>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<Root>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[2];/* '<Root>/HIL Read Encoder Timebase' */
} DW_q_qube_swingup_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T alpha_dot_CSTATE;             /* '<Root>/alpha_dot' */
  real_T theta_dot_CSTATE;             /* '<S6>/theta_dot' */
  real_T alpha_dot_CSTATE_b;           /* '<S6>/alpha_dot' */
} X_q_qube_swingup_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T alpha_dot_CSTATE;             /* '<Root>/alpha_dot' */
  real_T theta_dot_CSTATE;             /* '<S6>/theta_dot' */
  real_T alpha_dot_CSTATE_b;           /* '<S6>/alpha_dot' */
} XDot_q_qube_swingup_T;

/* State disabled  */
typedef struct {
  boolean_T alpha_dot_CSTATE;          /* '<Root>/alpha_dot' */
  boolean_T theta_dot_CSTATE;          /* '<S6>/theta_dot' */
  boolean_T alpha_dot_CSTATE_b;        /* '<S6>/alpha_dot' */
} XDis_q_qube_swingup_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_q_qube_swingup_T_ {
  real_T Jp;                           /* Variable: Jp
                                        * Referenced by: '<S10>/Pend Inertia (kg.m^2)'
                                        */
  real_T Lp;                           /* Variable: Lp
                                        * Referenced by: '<S10>/Pend Torque (N.m)'
                                        */
  real_T Lr;                           /* Variable: Lr
                                        * Referenced by: '<S7>/Acceleration to Torque'
                                        */
  real_T Mp;                           /* Variable: Mp
                                        * Referenced by: '<S10>/Pend Torque (N.m)'
                                        */
  real_T Mr;                           /* Variable: Mr
                                        * Referenced by: '<S7>/Acceleration to Torque'
                                        */
  real_T Rm;                           /* Variable: Rm
                                        * Referenced by: '<S7>/Torque to Voltage'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S10>/Pend Torque (N.m)'
                                        */
  real_T kt;                           /* Variable: kt
                                        * Referenced by: '<S7>/Torque to Voltage'
                                        */
  real_T HILInitialize_analog_output_max;/* Mask Parameter: HILInitialize_analog_output_max
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_output_min;/* Mask Parameter: HILInitialize_analog_output_min
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T EnableBalanceControl_const;   /* Mask Parameter: EnableBalanceControl_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T mu_gain;                      /* Mask Parameter: mu_gain
                                        * Referenced by: '<S8>/Slider Gain'
                                        */
  real_T Er_gain;                      /* Mask Parameter: Er_gain
                                        * Referenced by: '<S3>/Slider Gain'
                                        */
  real_T HILInitialize_initial_analog_ou;/* Mask Parameter: HILInitialize_initial_analog_ou
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_d;/* Mask Parameter: HILInitialize_set_other_outpu_d
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_a;/* Mask Parameter: HILInitialize_set_other_outpu_a
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_k;/* Mask Parameter: HILInitialize_set_other_outpu_k
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_analog_o;/* Mask Parameter: HILInitialize_watchdog_analog_o
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILReadEncoderTimebase_clock;/* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
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
  uint32_T HILReadEncoderTimebase_channels[2];/* Mask Parameter: HILReadEncoderTimebase_channels
                                               * Referenced by: '<Root>/HIL Read Encoder Timebase'
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
  uint32_T HILReadEncoderTimebase_samples_;/* Mask Parameter: HILReadEncoderTimebase_samples_
                                            * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                            */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_g;/* Mask Parameter: HILInitialize_set_analog_inpu_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_g;/* Mask Parameter: HILInitialize_set_analog_outp_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_o;/* Mask Parameter: HILInitialize_set_analog_outp_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_m;/* Mask Parameter: HILInitialize_set_analog_outp_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_e;/* Mask Parameter: HILInitialize_set_analog_outp_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_d;/* Mask Parameter: HILInitialize_set_analog_outp_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_p;/* Mask Parameter: HILInitialize_set_analog_outp_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_e;/* Mask Parameter: HILInitialize_set_clock_frequ_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_b;/* Mask Parameter: HILInitialize_set_clock_param_b
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_p;/* Mask Parameter: HILInitialize_set_digital_out_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_j;/* Mask Parameter: HILInitialize_set_digital_out_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_pm;/* Mask Parameter: HILInitialize_set_digital_ou_pm
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_jg;/* Mask Parameter: HILInitialize_set_digital_ou_jg
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_ph;/* Mask Parameter: HILInitialize_set_digital_ou_ph
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_l;/* Mask Parameter: HILInitialize_set_digital_out_l
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
  boolean_T HILInitialize_set_encoder_par_b;/* Mask Parameter: HILInitialize_set_encoder_par_b
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outpu_n;/* Mask Parameter: HILInitialize_set_other_outpu_n
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_n;/* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_c;/* Mask Parameter: HILInitialize_set_pwm_outputs_c
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_p;/* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__j;/* Mask Parameter: HILInitialize_set_pwm_params__j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T uKx_Gain[4];                  /* Expression: [-2 35 -1.5 3]
                                        * Referenced by: '<Root>/u = -K*x'
                                        */
  real_T Pendulumcountstorad_Gain;     /* Expression: 2*pi/512/4
                                        * Referenced by: '<S1>/Pendulum:  counts to rad'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -pi
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T u_max_Value;                  /* Expression: 6.0
                                        * Referenced by: '<Root>/u_max'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T alpha_dot_A;                  /* Computed Parameter: alpha_dot_A
                                        * Referenced by: '<Root>/alpha_dot'
                                        */
  real_T alpha_dot_C;                  /* Computed Parameter: alpha_dot_C
                                        * Referenced by: '<Root>/alpha_dot'
                                        */
  real_T alpha_dot_D;                  /* Computed Parameter: alpha_dot_D
                                        * Referenced by: '<Root>/alpha_dot'
                                        */
  real_T mJtoJ_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<S7>/mJ to J'
                                        */
  real_T SetpointStateXd_Value[4];     /* Expression: [0 0 0 0]
                                        * Referenced by: '<Root>/Setpoint State: Xd'
                                        */
  real_T Armcountstorad_Gain;          /* Expression: -2*pi/512/4
                                        * Referenced by: '<S1>/Arm: counts to rad'
                                        */
  real_T theta_dot_A;                  /* Computed Parameter: theta_dot_A
                                        * Referenced by: '<S6>/theta_dot'
                                        */
  real_T theta_dot_C;                  /* Computed Parameter: theta_dot_C
                                        * Referenced by: '<S6>/theta_dot'
                                        */
  real_T theta_dot_D;                  /* Computed Parameter: theta_dot_D
                                        * Referenced by: '<S6>/theta_dot'
                                        */
  real_T alpha_dot_A_o;                /* Computed Parameter: alpha_dot_A_o
                                        * Referenced by: '<S6>/alpha_dot'
                                        */
  real_T alpha_dot_C_i;                /* Computed Parameter: alpha_dot_C_i
                                        * Referenced by: '<S6>/alpha_dot'
                                        */
  real_T alpha_dot_D_i;                /* Computed Parameter: alpha_dot_D_i
                                        * Referenced by: '<S6>/alpha_dot'
                                        */
  real_T ForveCCW_Gain;                /* Expression: -1
                                        * Referenced by: '<Root>/For +ve CCW'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T JtomJ_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S7>/J to mJ'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  boolean_T HILReadEncoderTimebase_Active;/* Computed Parameter: HILReadEncoderTimebase_Active
                                           * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                           */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_q_qube_swingup_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_q_qube_swingup_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][3];
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
extern P_q_qube_swingup_T q_qube_swingup_P;

/* Block signals (auto storage) */
extern B_q_qube_swingup_T q_qube_swingup_B;

/* Continuous states (auto storage) */
extern X_q_qube_swingup_T q_qube_swingup_X;

/* Block states (auto storage) */
extern DW_q_qube_swingup_T q_qube_swingup_DW;

/* Model entry point functions */
extern void q_qube_swingup_initialize(void);
extern void q_qube_swingup_step(void);
extern void q_qube_swingup_terminate(void);

/* Real-time Model object */
extern RT_MODEL_q_qube_swingup_T *const q_qube_swingup_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 */

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
 * '<Root>' : 'q_qube_swingup'
 * '<S1>'   : 'q_qube_swingup/Counts to Angles'
 * '<S2>'   : 'q_qube_swingup/Enable Balance Control'
 * '<S3>'   : 'q_qube_swingup/Er'
 * '<S4>'   : 'q_qube_swingup/Radians to Degrees'
 * '<S5>'   : 'q_qube_swingup/Radians to Degrees1'
 * '<S6>'   : 'q_qube_swingup/State X'
 * '<S7>'   : 'q_qube_swingup/Swing-Up Control'
 * '<S8>'   : 'q_qube_swingup/mu'
 * '<S9>'   : 'q_qube_swingup/Swing-Up Control/Energy-Based Swing-Up Control'
 * '<S10>'  : 'q_qube_swingup/Swing-Up Control/Energy-Based Swing-Up Control/Pendulum Energy'
 * '<S11>'  : 'q_qube_swingup/Swing-Up Control/Energy-Based Swing-Up Control/User Specified Acceleration Limit'
 */
#endif                                 /* RTW_HEADER_q_qube_swingup_h_ */
