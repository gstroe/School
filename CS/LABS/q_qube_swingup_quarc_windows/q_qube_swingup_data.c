/*
 * q_qube_swingup_data.c
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
#include "q_qube_swingup.h"
#include "q_qube_swingup_private.h"

/* Block parameters (auto storage) */
P_q_qube_swingup_T q_qube_swingup_P = {
  3.3282000000000004E-5,               /* Variable: Jp
                                        * Referenced by: '<S10>/Pend Inertia (kg.m^2)'
                                        */
  0.129,                               /* Variable: Lp
                                        * Referenced by: '<S10>/Pend Torque (N.m)'
                                        */
  0.085,                               /* Variable: Lr
                                        * Referenced by: '<S7>/Acceleration to Torque'
                                        */
  0.024,                               /* Variable: Mp
                                        * Referenced by: '<S10>/Pend Torque (N.m)'
                                        */
  0.095,                               /* Variable: Mr
                                        * Referenced by: '<S7>/Acceleration to Torque'
                                        */
  8.4,                                 /* Variable: Rm
                                        * Referenced by: '<S7>/Torque to Voltage'
                                        */
  9.81,                                /* Variable: g
                                        * Referenced by: '<S10>/Pend Torque (N.m)'
                                        */
  0.042,                               /* Variable: kt
                                        * Referenced by: '<S7>/Torque to Voltage'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.3490658503988659,                  /* Mask Parameter: EnableBalanceControl_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: mu_gain
                                        * Referenced by: '<S8>/Slider Gain'
                                        */
  30.0,                                /* Mask Parameter: Er_gain
                                        * Referenced by: '<S3>/Slider Gain'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_hardware_clocks
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  { 0U, 1U },
  0U,                                  /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  500U,                                /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_pm
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_jg
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_ph
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Expression: [-2 35 -1.5 3]
   * Referenced by: '<Root>/u = -K*x'
   */
  { -2.0, 35.0, -1.5, 3.0 },
  0.0030679615757712823,               /* Expression: 2*pi/512/4
                                        * Referenced by: '<S1>/Pendulum:  counts to rad'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S1>/Bias'
                                        */
  6.0,                                 /* Expression: 6.0
                                        * Referenced by: '<Root>/u_max'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  -50.0,                               /* Computed Parameter: alpha_dot_A
                                        * Referenced by: '<Root>/alpha_dot'
                                        */
  -2500.0,                             /* Computed Parameter: alpha_dot_C
                                        * Referenced by: '<Root>/alpha_dot'
                                        */
  50.0,                                /* Computed Parameter: alpha_dot_D
                                        * Referenced by: '<Root>/alpha_dot'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S7>/mJ to J'
                                        */

  /*  Expression: [0 0 0 0]
   * Referenced by: '<Root>/Setpoint State: Xd'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  -0.0030679615757712823,              /* Expression: -2*pi/512/4
                                        * Referenced by: '<S1>/Arm: counts to rad'
                                        */
  -50.0,                               /* Computed Parameter: theta_dot_A
                                        * Referenced by: '<S6>/theta_dot'
                                        */
  -2500.0,                             /* Computed Parameter: theta_dot_C
                                        * Referenced by: '<S6>/theta_dot'
                                        */
  50.0,                                /* Computed Parameter: theta_dot_D
                                        * Referenced by: '<S6>/theta_dot'
                                        */
  -50.0,                               /* Computed Parameter: alpha_dot_A_o
                                        * Referenced by: '<S6>/alpha_dot'
                                        */
  -2500.0,                             /* Computed Parameter: alpha_dot_C_i
                                        * Referenced by: '<S6>/alpha_dot'
                                        */
  50.0,                                /* Computed Parameter: alpha_dot_D_i
                                        * Referenced by: '<S6>/alpha_dot'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/For +ve CCW'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<S7>/J to mJ'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<Root>/HIL Read Encoder Timebase'
                                        */
  0                                    /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<Root>/HIL Write Analog'
                                        */
};
