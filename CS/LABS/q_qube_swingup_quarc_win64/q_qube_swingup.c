/*
 * q_qube_swingup.c
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
#include "q_qube_swingup.h"
#include "q_qube_swingup_private.h"
#include "q_qube_swingup_dt.h"

/* Block signals (auto storage) */
B_q_qube_swingup_T q_qube_swingup_B;

/* Continuous states */
X_q_qube_swingup_T q_qube_swingup_X;

/* Block states (auto storage) */
DW_q_qube_swingup_T q_qube_swingup_DW;

/* Real-time model */
RT_MODEL_q_qube_swingup_T q_qube_swingup_M_;
RT_MODEL_q_qube_swingup_T *const q_qube_swingup_M = &q_qube_swingup_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_qube_swingup_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T y_0;
  real_T u;
  boolean_T y_1;
  if (u1 == 0.0) {
    y = u0;
  } else {
    u = u0;
    y_0 = ((!rtIsNaN(u)) && (!rtIsInf(u)));
    u = u1;
    y_1 = ((!rtIsNaN(u)) && (!rtIsInf(u)));
    if (!(y_0 && y_1)) {
      y = (rtNaN);
    } else {
      u = u0 / u1;
      if (u1 <= floor(u1)) {
        y = u0 - floor(u) * u1;
      } else if (fabs(u - rt_roundd_snf(u)) <= DBL_EPSILON * fabs(u)) {
        y = 0.0;
      } else {
        y = (u - floor(u)) * u1;
      }
    }
  }

  return y;
}

/* Model step function */
void q_qube_swingup_step(void)
{
  real_T A;
  real_T B;
  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* set solver stop time */
    if (!(q_qube_swingup_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_qube_swingup_M->solverInfo,
                            ((q_qube_swingup_M->Timing.clockTickH0 + 1) *
        q_qube_swingup_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_qube_swingup_M->solverInfo,
                            ((q_qube_swingup_M->Timing.clockTick0 + 1) *
        q_qube_swingup_M->Timing.stepSize0 +
        q_qube_swingup_M->Timing.clockTickH0 *
        q_qube_swingup_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_qube_swingup_M)) {
    q_qube_swingup_M->Timing.t[0] = rtsiGetT(&q_qube_swingup_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_qube_swingup/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_qube_swingup_DW.HILReadEncoderTimebase_Task, 1,
         &q_qube_swingup_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
      } else {
        q_qube_swingup_B.HILReadEncoderTimebase_o1 =
          q_qube_swingup_DW.HILReadEncoderTimebase_Buffer[0];
        q_qube_swingup_B.HILReadEncoderTimebase_o2 =
          q_qube_swingup_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S1>/Pendulum:  counts to rad' */
    q_qube_swingup_B.Pendulumcountstorad =
      q_qube_swingup_P.Pendulumcountstorad_Gain *
      q_qube_swingup_B.HILReadEncoderTimebase_o2;

    /* Math: '<S1>/Math Function' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    q_qube_swingup_B.MathFunction = rt_modd_snf
      (q_qube_swingup_B.Pendulumcountstorad, q_qube_swingup_P.Constant1_Value);

    /* Bias: '<S1>/Bias' */
    q_qube_swingup_B.Bias = q_qube_swingup_B.MathFunction +
      q_qube_swingup_P.Bias_Bias;

    /* Abs: '<Root>/|alpha|' */
    q_qube_swingup_B.alpha = fabs(q_qube_swingup_B.Bias);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    q_qube_swingup_B.Compare = (uint8_T)(q_qube_swingup_B.alpha <=
      q_qube_swingup_P.EnableBalanceControl_const);

    /* Gain: '<S8>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant'
     */
    q_qube_swingup_B.SliderGain = q_qube_swingup_P.mu_gain *
      q_qube_swingup_P.Constant_Value;

    /* Trigonometry: '<S10>/cos(alpha)' */
    q_qube_swingup_B.cosalpha = cos(q_qube_swingup_B.Pendulumcountstorad);

    /* Sum: '<S10>/Sum1' incorporates:
     *  Constant: '<S10>/Constant'
     */
    q_qube_swingup_B.Sum1 = q_qube_swingup_P.Constant_Value_k -
      q_qube_swingup_B.cosalpha;

    /* Gain: '<S10>/Pend Torque (N.m)' */
    A = q_qube_swingup_P.Mp * q_qube_swingup_P.g * q_qube_swingup_P.Lp;
    A /= 2.0;
    q_qube_swingup_B.PendTorqueNm = A * q_qube_swingup_B.Sum1;
  }

  /* TransferFcn: '<Root>/alpha_dot' */
  q_qube_swingup_B.alpha_dot = 0.0;
  q_qube_swingup_B.alpha_dot += q_qube_swingup_P.alpha_dot_C *
    q_qube_swingup_X.alpha_dot_CSTATE;
  q_qube_swingup_B.alpha_dot += q_qube_swingup_P.alpha_dot_D *
    q_qube_swingup_B.Pendulumcountstorad;

  /* Math: '<S10>/alpha_dot^2' */
  q_qube_swingup_B.alpha_dot2 = q_qube_swingup_B.alpha_dot *
    q_qube_swingup_B.alpha_dot;

  /* Gain: '<S10>/Pend Inertia (kg.m^2)' */
  A = q_qube_swingup_P.Jp;
  A /= 2.0;
  q_qube_swingup_B.PendInertiakgm2 = A * q_qube_swingup_B.alpha_dot2;

  /* Sum: '<S10>/Energy' */
  q_qube_swingup_B.Energy = q_qube_swingup_B.PendTorqueNm +
    q_qube_swingup_B.PendInertiakgm2;
  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* Gain: '<S3>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant'
     */
    q_qube_swingup_B.SliderGain_j = q_qube_swingup_P.Er_gain *
      q_qube_swingup_P.Constant_Value;

    /* Gain: '<S7>/mJ to J' */
    q_qube_swingup_B.mJtoJ = q_qube_swingup_P.mJtoJ_Gain *
      q_qube_swingup_B.SliderGain_j;

    /* Trigonometry: '<S9>/cos(alpha)' */
    q_qube_swingup_B.cosalpha_g = cos(q_qube_swingup_B.Pendulumcountstorad);

    /* UnaryMinus: '<S9>/Unary Minus' incorporates:
     *  Constant: '<Root>/u_max'
     */
    q_qube_swingup_B.UnaryMinus = -q_qube_swingup_P.u_max_Value;

    /* Gain: '<S1>/Arm: counts to rad' */
    q_qube_swingup_B.Armcountstorad = q_qube_swingup_P.Armcountstorad_Gain *
      q_qube_swingup_B.HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S6>/theta_dot' */
  q_qube_swingup_B.theta_dot = 0.0;
  q_qube_swingup_B.theta_dot += q_qube_swingup_P.theta_dot_C *
    q_qube_swingup_X.theta_dot_CSTATE;
  q_qube_swingup_B.theta_dot += q_qube_swingup_P.theta_dot_D *
    q_qube_swingup_B.Armcountstorad;

  /* TransferFcn: '<S6>/alpha_dot' */
  q_qube_swingup_B.alpha_dot_b = 0.0;
  q_qube_swingup_B.alpha_dot_b += q_qube_swingup_P.alpha_dot_C_i *
    q_qube_swingup_X.alpha_dot_CSTATE_b;
  q_qube_swingup_B.alpha_dot_b += q_qube_swingup_P.alpha_dot_D_i *
    q_qube_swingup_B.Bias;

  /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (q_qube_swingup_B.Compare == 0) {
    /* Product: '<S9>/alpha_dot*cos(alpha)' */
    q_qube_swingup_B.alpha_dotcosalpha = q_qube_swingup_B.cosalpha_g *
      q_qube_swingup_B.alpha_dot;

    /* Signum: '<S9>/Sign' */
    A = q_qube_swingup_B.alpha_dotcosalpha;
    if (A < 0.0) {
      q_qube_swingup_B.Sign = -1.0;
    } else if (A > 0.0) {
      q_qube_swingup_B.Sign = 1.0;
    } else if (A == 0.0) {
      q_qube_swingup_B.Sign = 0.0;
    } else {
      q_qube_swingup_B.Sign = A;
    }

    /* End of Signum: '<S9>/Sign' */

    /* Sum: '<S9>/E-Er' */
    q_qube_swingup_B.EEr = q_qube_swingup_B.Energy - q_qube_swingup_B.mJtoJ;

    /* Product: '<S9>/(E-Er)*sign(a_dot*cos(a))' */
    q_qube_swingup_B.EErsigna_dotcosa = q_qube_swingup_B.EEr *
      q_qube_swingup_B.Sign;

    /* Product: '<S9>/Product' */
    q_qube_swingup_B.Product = q_qube_swingup_B.SliderGain *
      q_qube_swingup_B.EErsigna_dotcosa;

    /* RelationalOperator: '<S11>/LowerRelop1' incorporates:
     *  Constant: '<Root>/u_max'
     */
    q_qube_swingup_B.LowerRelop1 = (q_qube_swingup_B.Product >
      q_qube_swingup_P.u_max_Value);

    /* Switch: '<S11>/Switch2' incorporates:
     *  Constant: '<Root>/u_max'
     */
    if (q_qube_swingup_B.LowerRelop1) {
      q_qube_swingup_B.Switch2 = q_qube_swingup_P.u_max_Value;
    } else {
      /* RelationalOperator: '<S11>/UpperRelop' */
      q_qube_swingup_B.UpperRelop = (q_qube_swingup_B.Product <
        q_qube_swingup_B.UnaryMinus);

      /* Switch: '<S11>/Switch' */
      if (q_qube_swingup_B.UpperRelop) {
        q_qube_swingup_B.Switch = q_qube_swingup_B.UnaryMinus;
      } else {
        q_qube_swingup_B.Switch = q_qube_swingup_B.Product;
      }

      /* End of Switch: '<S11>/Switch' */
      q_qube_swingup_B.Switch2 = q_qube_swingup_B.Switch;
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Gain: '<S7>/Acceleration to Torque' */
    A = q_qube_swingup_P.Mr * q_qube_swingup_P.Lr;
    q_qube_swingup_B.AccelerationtoTorque = A * q_qube_swingup_B.Switch2;

    /* Gain: '<S7>/Torque to Voltage' */
    A = q_qube_swingup_P.Rm;
    B = q_qube_swingup_P.kt;
    A /= B;
    q_qube_swingup_B.TorquetoVoltage = A * q_qube_swingup_B.AccelerationtoTorque;
    q_qube_swingup_B.EnableBalanceControlSwitch =
      q_qube_swingup_B.TorquetoVoltage;
  } else {
    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Setpoint State: Xd'
     */
    q_qube_swingup_B.Sum[0] = q_qube_swingup_P.SetpointStateXd_Value[0] -
      q_qube_swingup_B.Armcountstorad;
    q_qube_swingup_B.Sum[1] = q_qube_swingup_P.SetpointStateXd_Value[1] -
      q_qube_swingup_B.Bias;
    q_qube_swingup_B.Sum[2] = q_qube_swingup_P.SetpointStateXd_Value[2] -
      q_qube_swingup_B.theta_dot;
    q_qube_swingup_B.Sum[3] = q_qube_swingup_P.SetpointStateXd_Value[3] -
      q_qube_swingup_B.alpha_dot_b;

    /* Gain: '<Root>/u = -K*x' */
    A = q_qube_swingup_P.uKx_Gain[0] * q_qube_swingup_B.Sum[0];
    A += q_qube_swingup_P.uKx_Gain[1] * q_qube_swingup_B.Sum[1];
    A += q_qube_swingup_P.uKx_Gain[2] * q_qube_swingup_B.Sum[2];
    A += q_qube_swingup_P.uKx_Gain[3] * q_qube_swingup_B.Sum[3];
    q_qube_swingup_B.uKx = A;
    q_qube_swingup_B.EnableBalanceControlSwitch = q_qube_swingup_B.uKx;
  }

  /* End of MultiPortSwitch: '<Root>/Enable Balance Control Switch' */

  /* Gain: '<Root>/For +ve CCW' */
  q_qube_swingup_B.ForveCCW = q_qube_swingup_P.ForveCCW_Gain *
    q_qube_swingup_B.EnableBalanceControlSwitch;
  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: q_qube_swingup/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_qube_swingup_DW.HILInitialize_Card,
        &q_qube_swingup_P.HILWriteAnalog_channels, 1, &q_qube_swingup_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
      }
    }

    /* Gain: '<S4>/Gain' */
    q_qube_swingup_B.Gain = q_qube_swingup_P.Gain_Gain *
      q_qube_swingup_B.Pendulumcountstorad;
  }

  /* Gain: '<S7>/J to mJ' */
  q_qube_swingup_B.JtomJ = q_qube_swingup_P.JtomJ_Gain * q_qube_swingup_B.Energy;
  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* Gain: '<S5>/Gain' */
    q_qube_swingup_B.Gain_b = q_qube_swingup_P.Gain_Gain_a *
      q_qube_swingup_B.Armcountstorad;
  }

  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, q_qube_swingup_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(q_qube_swingup_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((q_qube_swingup_M->Timing.clockTick1+
                            q_qube_swingup_M->Timing.clockTickH1* 4294967296.0))
                          * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(q_qube_swingup_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(q_qube_swingup_M)!=-1) &&
          !((rtmGetTFinal(q_qube_swingup_M)-
             (((q_qube_swingup_M->Timing.clockTick1+
                q_qube_swingup_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((q_qube_swingup_M->Timing.clockTick1+
               q_qube_swingup_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(q_qube_swingup_M, "Simulation finished");
      }

      if (rtmGetStopRequested(q_qube_swingup_M)) {
        rtmSetErrorStatus(q_qube_swingup_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&q_qube_swingup_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_qube_swingup_M->Timing.clockTick0)) {
      ++q_qube_swingup_M->Timing.clockTickH0;
    }

    q_qube_swingup_M->Timing.t[0] = rtsiGetSolverStopTime
      (&q_qube_swingup_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      q_qube_swingup_M->Timing.clockTick1++;
      if (!q_qube_swingup_M->Timing.clockTick1) {
        q_qube_swingup_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void q_qube_swingup_derivatives(void)
{
  XDot_q_qube_swingup_T *_rtXdot;
  _rtXdot = ((XDot_q_qube_swingup_T *) q_qube_swingup_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = 0.0;
  _rtXdot->alpha_dot_CSTATE += q_qube_swingup_P.alpha_dot_A *
    q_qube_swingup_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += q_qube_swingup_B.Pendulumcountstorad;

  /* Derivatives for TransferFcn: '<S6>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = 0.0;
  _rtXdot->theta_dot_CSTATE += q_qube_swingup_P.theta_dot_A *
    q_qube_swingup_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += q_qube_swingup_B.Armcountstorad;

  /* Derivatives for TransferFcn: '<S6>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE_b = 0.0;
  _rtXdot->alpha_dot_CSTATE_b += q_qube_swingup_P.alpha_dot_A_o *
    q_qube_swingup_X.alpha_dot_CSTATE_b;
  _rtXdot->alpha_dot_CSTATE_b += q_qube_swingup_B.Bias;
}

/* Model initialize function */
void q_qube_swingup_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_qube_swingup_M, 0,
                sizeof(RT_MODEL_q_qube_swingup_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_qube_swingup_M->solverInfo,
                          &q_qube_swingup_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_qube_swingup_M->solverInfo, &rtmGetTPtr(q_qube_swingup_M));
    rtsiSetStepSizePtr(&q_qube_swingup_M->solverInfo,
                       &q_qube_swingup_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_qube_swingup_M->solverInfo,
                 &q_qube_swingup_M->ModelData.derivs);
    rtsiSetContStatesPtr(&q_qube_swingup_M->solverInfo, (real_T **)
                         &q_qube_swingup_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&q_qube_swingup_M->solverInfo,
      &q_qube_swingup_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&q_qube_swingup_M->solverInfo, (&rtmGetErrorStatus
      (q_qube_swingup_M)));
    rtsiSetRTModelPtr(&q_qube_swingup_M->solverInfo, q_qube_swingup_M);
  }

  rtsiSetSimTimeStep(&q_qube_swingup_M->solverInfo, MAJOR_TIME_STEP);
  q_qube_swingup_M->ModelData.intgData.f[0] = q_qube_swingup_M->ModelData.odeF[0];
  q_qube_swingup_M->ModelData.contStates = ((X_q_qube_swingup_T *)
    &q_qube_swingup_X);
  rtsiSetSolverData(&q_qube_swingup_M->solverInfo, (void *)
                    &q_qube_swingup_M->ModelData.intgData);
  rtsiSetSolverName(&q_qube_swingup_M->solverInfo,"ode1");
  rtmSetTPtr(q_qube_swingup_M, &q_qube_swingup_M->Timing.tArray[0]);
  rtmSetTFinal(q_qube_swingup_M, -1);
  q_qube_swingup_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  q_qube_swingup_M->Sizes.checksums[0] = (1127055806U);
  q_qube_swingup_M->Sizes.checksums[1] = (181951434U);
  q_qube_swingup_M->Sizes.checksums[2] = (2881173098U);
  q_qube_swingup_M->Sizes.checksums[3] = (3384755483U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    q_qube_swingup_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_qube_swingup_M->extModeInfo,
      &q_qube_swingup_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_qube_swingup_M->extModeInfo,
                        q_qube_swingup_M->Sizes.checksums);
    rteiSetTPtr(q_qube_swingup_M->extModeInfo, rtmGetTPtr(q_qube_swingup_M));
  }

  /* block I/O */
  (void) memset(((void *) &q_qube_swingup_B), 0,
                sizeof(B_q_qube_swingup_T));

  {
    q_qube_swingup_B.HILReadEncoderTimebase_o1 = 0.0;
    q_qube_swingup_B.HILReadEncoderTimebase_o2 = 0.0;
    q_qube_swingup_B.Pendulumcountstorad = 0.0;
    q_qube_swingup_B.MathFunction = 0.0;
    q_qube_swingup_B.Bias = 0.0;
    q_qube_swingup_B.alpha = 0.0;
    q_qube_swingup_B.SliderGain = 0.0;
    q_qube_swingup_B.cosalpha = 0.0;
    q_qube_swingup_B.Sum1 = 0.0;
    q_qube_swingup_B.PendTorqueNm = 0.0;
    q_qube_swingup_B.alpha_dot = 0.0;
    q_qube_swingup_B.alpha_dot2 = 0.0;
    q_qube_swingup_B.PendInertiakgm2 = 0.0;
    q_qube_swingup_B.Energy = 0.0;
    q_qube_swingup_B.SliderGain_j = 0.0;
    q_qube_swingup_B.mJtoJ = 0.0;
    q_qube_swingup_B.cosalpha_g = 0.0;
    q_qube_swingup_B.UnaryMinus = 0.0;
    q_qube_swingup_B.Armcountstorad = 0.0;
    q_qube_swingup_B.theta_dot = 0.0;
    q_qube_swingup_B.alpha_dot_b = 0.0;
    q_qube_swingup_B.EnableBalanceControlSwitch = 0.0;
    q_qube_swingup_B.ForveCCW = 0.0;
    q_qube_swingup_B.Gain = 0.0;
    q_qube_swingup_B.JtomJ = 0.0;
    q_qube_swingup_B.Gain_b = 0.0;
    q_qube_swingup_B.alpha_dotcosalpha = 0.0;
    q_qube_swingup_B.Sign = 0.0;
    q_qube_swingup_B.EEr = 0.0;
    q_qube_swingup_B.EErsigna_dotcosa = 0.0;
    q_qube_swingup_B.Product = 0.0;
    q_qube_swingup_B.Switch2 = 0.0;
    q_qube_swingup_B.AccelerationtoTorque = 0.0;
    q_qube_swingup_B.TorquetoVoltage = 0.0;
    q_qube_swingup_B.Switch = 0.0;
    q_qube_swingup_B.Sum[0] = 0.0;
    q_qube_swingup_B.Sum[1] = 0.0;
    q_qube_swingup_B.Sum[2] = 0.0;
    q_qube_swingup_B.Sum[3] = 0.0;
    q_qube_swingup_B.uKx = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&q_qube_swingup_X, 0,
                  sizeof(X_q_qube_swingup_T));
  }

  /* states (dwork) */
  (void) memset((void *)&q_qube_swingup_DW, 0,
                sizeof(DW_q_qube_swingup_T));
  q_qube_swingup_DW.HILInitialize_AOMinimums[0] = 0.0;
  q_qube_swingup_DW.HILInitialize_AOMinimums[1] = 0.0;
  q_qube_swingup_DW.HILInitialize_AOMaximums[0] = 0.0;
  q_qube_swingup_DW.HILInitialize_AOMaximums[1] = 0.0;
  q_qube_swingup_DW.HILInitialize_AOVoltages[0] = 0.0;
  q_qube_swingup_DW.HILInitialize_AOVoltages[1] = 0.0;
  q_qube_swingup_DW.HILInitialize_FilterFrequency[0] = 0.0;
  q_qube_swingup_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_qube_swingup_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube_swingup/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0",
                      &q_qube_swingup_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(q_qube_swingup_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_qube_swingup_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
      return;
    }

    if ((q_qube_swingup_P.HILInitialize_set_analog_output && !is_switching) ||
        (q_qube_swingup_P.HILInitialize_set_analog_outp_g && is_switching)) {
      q_qube_swingup_DW.HILInitialize_AOMinimums[0] =
        q_qube_swingup_P.HILInitialize_analog_output_min;
      q_qube_swingup_DW.HILInitialize_AOMinimums[1] =
        q_qube_swingup_P.HILInitialize_analog_output_min;
      q_qube_swingup_DW.HILInitialize_AOMaximums[0] =
        q_qube_swingup_P.HILInitialize_analog_output_max;
      q_qube_swingup_DW.HILInitialize_AOMaximums[1] =
        q_qube_swingup_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(q_qube_swingup_DW.HILInitialize_Card,
        q_qube_swingup_P.HILInitialize_analog_output_cha, 2U,
        &q_qube_swingup_DW.HILInitialize_AOMinimums[0],
        &q_qube_swingup_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube_swingup_P.HILInitialize_set_analog_outp_o && !is_switching) ||
        (q_qube_swingup_P.HILInitialize_set_analog_outp_m && is_switching)) {
      q_qube_swingup_DW.HILInitialize_AOVoltages[0] =
        q_qube_swingup_P.HILInitialize_initial_analog_ou;
      q_qube_swingup_DW.HILInitialize_AOVoltages[1] =
        q_qube_swingup_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(q_qube_swingup_DW.HILInitialize_Card,
        q_qube_swingup_P.HILInitialize_analog_output_cha, 2U,
        &q_qube_swingup_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
        return;
      }
    }

    if (q_qube_swingup_P.HILInitialize_set_analog_outp_p) {
      q_qube_swingup_DW.HILInitialize_AOVoltages[0] =
        q_qube_swingup_P.HILInitialize_watchdog_analog_o;
      q_qube_swingup_DW.HILInitialize_AOVoltages[1] =
        q_qube_swingup_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (q_qube_swingup_DW.HILInitialize_Card,
         q_qube_swingup_P.HILInitialize_analog_output_cha, 2U,
         &q_qube_swingup_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube_swingup_P.HILInitialize_set_encoder_param && !is_switching) ||
        (q_qube_swingup_P.HILInitialize_set_encoder_par_b && is_switching)) {
      q_qube_swingup_DW.HILInitialize_QuadratureModes[0] =
        q_qube_swingup_P.HILInitialize_quadrature;
      q_qube_swingup_DW.HILInitialize_QuadratureModes[1] =
        q_qube_swingup_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode
        (q_qube_swingup_DW.HILInitialize_Card,
         q_qube_swingup_P.HILInitialize_encoder_channels, 2U,
         (t_encoder_quadrature_mode *)
         &q_qube_swingup_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube_swingup_P.HILInitialize_set_encoder_count && !is_switching) ||
        (q_qube_swingup_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      q_qube_swingup_DW.HILInitialize_InitialEICounts[0] =
        q_qube_swingup_P.HILInitialize_initial_encoder_c;
      q_qube_swingup_DW.HILInitialize_InitialEICounts[1] =
        q_qube_swingup_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(q_qube_swingup_DW.HILInitialize_Card,
        q_qube_swingup_P.HILInitialize_encoder_channels, 2U,
        &q_qube_swingup_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_qube_swingup/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(q_qube_swingup_DW.HILInitialize_Card,
      q_qube_swingup_P.HILReadEncoderTimebase_samples_,
      q_qube_swingup_P.HILReadEncoderTimebase_channels, 2,
      &q_qube_swingup_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/alpha_dot' */
  q_qube_swingup_X.alpha_dot_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/theta_dot' */
  q_qube_swingup_X.theta_dot_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/alpha_dot' */
  q_qube_swingup_X.alpha_dot_CSTATE_b = 0.0;
}

/* Model terminate function */
void q_qube_swingup_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube_swingup/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(q_qube_swingup_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_qube_swingup_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_qube_swingup_P.HILInitialize_set_analog_outp_d && !is_switching) ||
        (q_qube_swingup_P.HILInitialize_set_analog_outp_e && is_switching)) {
      q_qube_swingup_DW.HILInitialize_AOVoltages[0] =
        q_qube_swingup_P.HILInitialize_final_analog_outp;
      q_qube_swingup_DW.HILInitialize_AOVoltages[1] =
        q_qube_swingup_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(q_qube_swingup_DW.HILInitialize_Card,
        q_qube_swingup_P.HILInitialize_analog_output_cha,
        num_final_analog_outputs, &q_qube_swingup_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube_swingup_M, _rt_error_message);
      }
    }

    hil_task_delete_all(q_qube_swingup_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_qube_swingup_DW.HILInitialize_Card);
    hil_close(q_qube_swingup_DW.HILInitialize_Card);
    q_qube_swingup_DW.HILInitialize_Card = NULL;
  }
}
