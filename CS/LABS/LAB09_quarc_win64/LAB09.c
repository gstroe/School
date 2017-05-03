/*
 * LAB09.c
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
#include "LAB09.h"
#include "LAB09_private.h"
#include "LAB09_dt.h"

/* Block signals (auto storage) */
B_LAB09_T LAB09_B;

/* Continuous states */
X_LAB09_T LAB09_X;

/* Block states (auto storage) */
DW_LAB09_T LAB09_DW;

/* Real-time model */
RT_MODEL_LAB09_T LAB09_M_;
RT_MODEL_LAB09_T *const LAB09_M = &LAB09_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  LAB09_derivatives();
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
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
}

/* Model step function */
void LAB09_step(void)
{
  /* local block i/o variables */
  real_T rtb_ToRads1;
  real_T rtb_Bias;
  real_T tmp;
  if (rtmIsMajorTimeStep(LAB09_M)) {
    /* set solver stop time */
    if (!(LAB09_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LAB09_M->solverInfo, ((LAB09_M->Timing.clockTickH0
        + 1) * LAB09_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LAB09_M->solverInfo, ((LAB09_M->Timing.clockTick0 +
        1) * LAB09_M->Timing.stepSize0 + LAB09_M->Timing.clockTickH0 *
        LAB09_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LAB09_M)) {
    LAB09_M->Timing.t[0] = rtsiGetT(&LAB09_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(LAB09_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: LAB09/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(LAB09_DW.HILInitialize_Card,
        LAB09_P.HILReadEncoder_channels, 2, &LAB09_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
      } else {
        rtb_Bias = LAB09_DW.HILReadEncoder_Buffer[0];
        rtb_ToRads1 = LAB09_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S3>/To Rads' */
    rtb_Bias *= LAB09_P.ToRads_Gain;

    /* Math: '<S3>/Math Function' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    rtb_Bias = rt_modd_snf(rtb_Bias, LAB09_P.Constant1_Value);

    /* Bias: '<S3>/Bias' */
    rtb_Bias += LAB09_P.Bias_Bias;

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Abs: '<Root>/Abs'
     *  Constant: '<S1>/Constant'
     */
    LAB09_B.Compare = (fabs(rtb_Bias) <= LAB09_P.CompareToConstant_const);

    /* UnaryMinus: '<Root>/Unary Minus2' */
    LAB09_B.UnaryMinus2 = -rtb_Bias;

    /* Gain: '<Root>/Gain3' */
    LAB09_B.Gain3 = LAB09_P.Gain3_Gain * LAB09_B.UnaryMinus2;

    /* Gain: '<S3>/To Rads1' */
    rtb_ToRads1 *= LAB09_P.ToRads1_Gain;

    /* UnaryMinus: '<Root>/Unary Minus' */
    LAB09_B.UnaryMinus = -rtb_ToRads1;

    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<S2>/Gain1'
     *  Sum: '<Root>/Sum'
     */
    LAB09_B.Gain = (LAB09_P.Gain1_Gain_m * LAB09_P.Constant_Value - rtb_ToRads1)
      * LAB09_P.Gain_Gain;
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Sum: '<Root>/Add'
   *  TransferFcn: '<Root>/Transfer Fcn1'
   *  TransferFcn: '<Root>/Transfer Fcn2'
   */
  if (LAB09_B.Compare == 0) {
    tmp = LAB09_P.Constant1_Value_n;
  } else {
    tmp = (((LAB09_P.TransferFcn1_C * LAB09_X.TransferFcn1_CSTATE +
             LAB09_P.TransferFcn1_D * LAB09_B.UnaryMinus2) * LAB09_P.Gain2_Gain
            + LAB09_B.Gain3) + (LAB09_P.TransferFcn2_C *
            LAB09_X.TransferFcn2_CSTATE + LAB09_P.TransferFcn2_D *
            LAB09_B.UnaryMinus) * LAB09_P.Gain1_Gain) + LAB09_B.Gain;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Gain: '<Root>/Gain4' */
  LAB09_B.Gain4 = LAB09_P.Gain4_Gain * tmp;
  if (rtmIsMajorTimeStep(LAB09_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: LAB09/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(LAB09_DW.HILInitialize_Card,
        &LAB09_P.HILWriteAnalog_channels, 1, &LAB09_B.Gain4);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
      }
    }

    /* Gain: '<S4>/Gain' */
    LAB09_B.Gain_c = LAB09_P.Gain_Gain_k * rtb_Bias;

    /* Gain: '<S5>/Gain' */
    LAB09_B.Gain_p = LAB09_P.Gain_Gain_e * rtb_ToRads1;
  }

  if (rtmIsMajorTimeStep(LAB09_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, LAB09_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(LAB09_M)) { /* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((LAB09_M->Timing.clockTick1+
                            LAB09_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LAB09_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(LAB09_M)!=-1) &&
          !((rtmGetTFinal(LAB09_M)-(((LAB09_M->Timing.clockTick1+
               LAB09_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((LAB09_M->Timing.clockTick1+LAB09_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(LAB09_M, "Simulation finished");
      }

      if (rtmGetStopRequested(LAB09_M)) {
        rtmSetErrorStatus(LAB09_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&LAB09_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++LAB09_M->Timing.clockTick0)) {
      ++LAB09_M->Timing.clockTickH0;
    }

    LAB09_M->Timing.t[0] = rtsiGetSolverStopTime(&LAB09_M->solverInfo);

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
      LAB09_M->Timing.clockTick1++;
      if (!LAB09_M->Timing.clockTick1) {
        LAB09_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void LAB09_derivatives(void)
{
  XDot_LAB09_T *_rtXdot;
  _rtXdot = ((XDot_LAB09_T *) LAB09_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += LAB09_P.TransferFcn1_A *
    LAB09_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += LAB09_B.UnaryMinus2;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += LAB09_P.TransferFcn2_A *
    LAB09_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += LAB09_B.UnaryMinus;
}

/* Model initialize function */
void LAB09_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LAB09_M, 0,
                sizeof(RT_MODEL_LAB09_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LAB09_M->solverInfo, &LAB09_M->Timing.simTimeStep);
    rtsiSetTPtr(&LAB09_M->solverInfo, &rtmGetTPtr(LAB09_M));
    rtsiSetStepSizePtr(&LAB09_M->solverInfo, &LAB09_M->Timing.stepSize0);
    rtsiSetdXPtr(&LAB09_M->solverInfo, &LAB09_M->ModelData.derivs);
    rtsiSetContStatesPtr(&LAB09_M->solverInfo, (real_T **)
                         &LAB09_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&LAB09_M->solverInfo, &LAB09_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&LAB09_M->solverInfo, (&rtmGetErrorStatus(LAB09_M)));
    rtsiSetRTModelPtr(&LAB09_M->solverInfo, LAB09_M);
  }

  rtsiSetSimTimeStep(&LAB09_M->solverInfo, MAJOR_TIME_STEP);
  LAB09_M->ModelData.intgData.f[0] = LAB09_M->ModelData.odeF[0];
  LAB09_M->ModelData.contStates = ((X_LAB09_T *) &LAB09_X);
  rtsiSetSolverData(&LAB09_M->solverInfo, (void *)&LAB09_M->ModelData.intgData);
  rtsiSetSolverName(&LAB09_M->solverInfo,"ode1");
  rtmSetTPtr(LAB09_M, &LAB09_M->Timing.tArray[0]);
  rtmSetTFinal(LAB09_M, -1);
  LAB09_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB09_M->Sizes.checksums[0] = (678546035U);
  LAB09_M->Sizes.checksums[1] = (7005941U);
  LAB09_M->Sizes.checksums[2] = (3896878807U);
  LAB09_M->Sizes.checksums[3] = (1054104981U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    LAB09_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB09_M->extModeInfo,
      &LAB09_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB09_M->extModeInfo, LAB09_M->Sizes.checksums);
    rteiSetTPtr(LAB09_M->extModeInfo, rtmGetTPtr(LAB09_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB09_B), 0,
                sizeof(B_LAB09_T));

  /* states (continuous) */
  {
    (void) memset((void *)&LAB09_X, 0,
                  sizeof(X_LAB09_T));
  }

  /* states (dwork) */
  (void) memset((void *)&LAB09_DW, 0,
                sizeof(DW_LAB09_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB09_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB09/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB09_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB09_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB09_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB09_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB09_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB09_M, _rt_error_message);
      return;
    }

    if ((LAB09_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB09_P.HILInitialize_set_analog_outp_j && is_switching)) {
      LAB09_DW.HILInitialize_AOMinimums[0] =
        LAB09_P.HILInitialize_analog_output_min;
      LAB09_DW.HILInitialize_AOMinimums[1] =
        LAB09_P.HILInitialize_analog_output_min;
      LAB09_DW.HILInitialize_AOMaximums[0] =
        LAB09_P.HILInitialize_analog_output_max;
      LAB09_DW.HILInitialize_AOMaximums[1] =
        LAB09_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB09_DW.HILInitialize_Card,
        LAB09_P.HILInitialize_analog_output_cha, 2U,
        &LAB09_DW.HILInitialize_AOMinimums[0],
        &LAB09_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
        return;
      }
    }

    if ((LAB09_P.HILInitialize_set_analog_outp_i && !is_switching) ||
        (LAB09_P.HILInitialize_set_analog_outp_k && is_switching)) {
      LAB09_DW.HILInitialize_AOVoltages[0] =
        LAB09_P.HILInitialize_initial_analog_ou;
      LAB09_DW.HILInitialize_AOVoltages[1] =
        LAB09_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB09_DW.HILInitialize_Card,
        LAB09_P.HILInitialize_analog_output_cha, 2U,
        &LAB09_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
        return;
      }
    }

    if (LAB09_P.HILInitialize_set_analog_outp_p) {
      LAB09_DW.HILInitialize_AOVoltages[0] =
        LAB09_P.HILInitialize_watchdog_analog_o;
      LAB09_DW.HILInitialize_AOVoltages[1] =
        LAB09_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB09_DW.HILInitialize_Card, LAB09_P.HILInitialize_analog_output_cha,
         2U, &LAB09_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
        return;
      }
    }

    if ((LAB09_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB09_P.HILInitialize_set_encoder_par_d && is_switching)) {
      LAB09_DW.HILInitialize_QuadratureModes[0] =
        LAB09_P.HILInitialize_quadrature;
      LAB09_DW.HILInitialize_QuadratureModes[1] =
        LAB09_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB09_DW.HILInitialize_Card,
        LAB09_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB09_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
        return;
      }
    }

    if ((LAB09_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB09_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      LAB09_DW.HILInitialize_InitialEICounts[0] =
        LAB09_P.HILInitialize_initial_encoder_c;
      LAB09_DW.HILInitialize_InitialEICounts[1] =
        LAB09_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB09_DW.HILInitialize_Card,
        LAB09_P.HILInitialize_encoder_channels, 2U,
        &LAB09_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  LAB09_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  LAB09_X.TransferFcn2_CSTATE = 0.0;
}

/* Model terminate function */
void LAB09_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB09/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB09_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB09_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB09_P.HILInitialize_set_analog_out_kt && !is_switching) ||
        (LAB09_P.HILInitialize_set_analog_outp_o && is_switching)) {
      LAB09_DW.HILInitialize_AOVoltages[0] =
        LAB09_P.HILInitialize_final_analog_outp;
      LAB09_DW.HILInitialize_AOVoltages[1] =
        LAB09_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB09_DW.HILInitialize_Card,
        LAB09_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB09_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB09_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB09_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB09_DW.HILInitialize_Card);
    hil_close(LAB09_DW.HILInitialize_Card);
    LAB09_DW.HILInitialize_Card = NULL;
  }
}
