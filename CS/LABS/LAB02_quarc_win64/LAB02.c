/*
 * LAB02.c
 *
 * Code generation for model "LAB02".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Feb 08 18:30:36 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "LAB02.h"
#include "LAB02_private.h"
#include "LAB02_dt.h"

/* Block signals (auto storage) */
B_LAB02_T LAB02_B;

/* Continuous states */
X_LAB02_T LAB02_X;

/* Block states (auto storage) */
DW_LAB02_T LAB02_DW;

/* Real-time model */
RT_MODEL_LAB02_T LAB02_M_;
RT_MODEL_LAB02_T *const LAB02_M = &LAB02_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  LAB02_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void LAB02_step(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  if (rtmIsMajorTimeStep(LAB02_M)) {
    /* set solver stop time */
    if (!(LAB02_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LAB02_M->solverInfo, ((LAB02_M->Timing.clockTickH0
        + 1) * LAB02_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LAB02_M->solverInfo, ((LAB02_M->Timing.clockTick0 +
        1) * LAB02_M->Timing.stepSize0 + LAB02_M->Timing.clockTickH0 *
        LAB02_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LAB02_M)) {
    LAB02_M->Timing.t[0] = rtsiGetT(&LAB02_M->solverInfo);
  }

  {
    real_T temp;
    real_T *lastU;
    if (rtmIsMajorTimeStep(LAB02_M)) {
    }

    /* SignalGenerator: '<Root>/Signal Generator' */
    temp = LAB02_P.SignalGenerator_Frequency * LAB02_M->Timing.t[0];
    if (temp - floor(temp) >= 0.5) {
      temp = LAB02_P.SignalGenerator_Amplitude;
    } else {
      temp = -LAB02_P.SignalGenerator_Amplitude;
    }

    /* End of SignalGenerator: '<Root>/Signal Generator' */

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain'
     */
    LAB02_B.Sum = LAB02_P.Gain_Gain * temp + LAB02_P.Constant_Value;
    if (rtmIsMajorTimeStep(LAB02_M)) {
      /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

      /* S-Function Block: LAB02/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(LAB02_DW.HILInitialize_Card,
          &LAB02_P.HILWriteAnalog_channels, 1, &LAB02_B.Sum);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(LAB02_M, _rt_error_message);
        }
      }
    }

    /* TransferFcn: '<Root>/Transfer Fcn1' */
    LAB02_B.TransferFcn1 = 0.0;
    LAB02_B.TransferFcn1 += LAB02_P.TransferFcn1_C * LAB02_X.TransferFcn1_CSTATE;
    if (rtmIsMajorTimeStep(LAB02_M)) {
      /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

      /* S-Function Block: LAB02/HIL Read Encoder (hil_read_encoder_block) */
      {
        t_error result = hil_read_encoder(LAB02_DW.HILInitialize_Card,
          &LAB02_P.HILReadEncoder_channels, 1, &LAB02_DW.HILReadEncoder_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(LAB02_M, _rt_error_message);
        } else {
          LAB02_B.HILReadEncoder = LAB02_DW.HILReadEncoder_Buffer;
        }
      }

      /* S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
      /* S-Function Block: LAB02/Inverse Modulus1 (inverse_modulus_block) */
      {
        static const real_T sampling_period = 0.002;
        real_T half_range = LAB02_P.InverseModulus1_Modulus / 2.0;
        real_T du, dy;
        if (LAB02_DW.InverseModulus1_FirstSample) {
          LAB02_DW.InverseModulus1_FirstSample = false;
          LAB02_DW.InverseModulus1_PreviousInput = LAB02_B.HILReadEncoder;
        }

        du = (real_T) LAB02_B.HILReadEncoder -
          LAB02_DW.InverseModulus1_PreviousInput;
        if (du > half_range) {
          LAB02_DW.InverseModulus1_Revolutions =
            LAB02_DW.InverseModulus1_Revolutions - 1;
          dy = du - LAB02_P.InverseModulus1_Modulus;
        } else if (du < -half_range) {
          LAB02_DW.InverseModulus1_Revolutions =
            LAB02_DW.InverseModulus1_Revolutions + 1;
          dy = du + LAB02_P.InverseModulus1_Modulus;
        } else {
          dy = du;
        }

        rtb_InverseModulus1 = LAB02_B.HILReadEncoder +
          LAB02_DW.InverseModulus1_Revolutions * LAB02_P.InverseModulus1_Modulus;
        LAB02_DW.InverseModulus1_PreviousInput = LAB02_B.HILReadEncoder;
      }

      /* Gain: '<Root>/Gain1' */
      LAB02_B.Gain1 = LAB02_P.Gain1_Gain * rtb_InverseModulus1;
    }

    /* Derivative: '<Root>/Derivative' */
    if ((LAB02_DW.TimeStampA >= LAB02_M->Timing.t[0]) && (LAB02_DW.TimeStampB >=
         LAB02_M->Timing.t[0])) {
      LAB02_B.Derivative = 0.0;
    } else {
      temp = LAB02_DW.TimeStampA;
      lastU = &LAB02_DW.LastUAtTimeA;
      if (LAB02_DW.TimeStampA < LAB02_DW.TimeStampB) {
        if (LAB02_DW.TimeStampB < LAB02_M->Timing.t[0]) {
          temp = LAB02_DW.TimeStampB;
          lastU = &LAB02_DW.LastUAtTimeB;
        }
      } else {
        if (LAB02_DW.TimeStampA >= LAB02_M->Timing.t[0]) {
          temp = LAB02_DW.TimeStampB;
          lastU = &LAB02_DW.LastUAtTimeB;
        }
      }

      LAB02_B.Derivative = (LAB02_B.Gain1 - *lastU) / (LAB02_M->Timing.t[0] -
        temp);
    }

    /* End of Derivative: '<Root>/Derivative' */
  }

  if (rtmIsMajorTimeStep(LAB02_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (LAB02_DW.TimeStampA == (rtInf)) {
      LAB02_DW.TimeStampA = LAB02_M->Timing.t[0];
      lastU = &LAB02_DW.LastUAtTimeA;
    } else if (LAB02_DW.TimeStampB == (rtInf)) {
      LAB02_DW.TimeStampB = LAB02_M->Timing.t[0];
      lastU = &LAB02_DW.LastUAtTimeB;
    } else if (LAB02_DW.TimeStampA < LAB02_DW.TimeStampB) {
      LAB02_DW.TimeStampA = LAB02_M->Timing.t[0];
      lastU = &LAB02_DW.LastUAtTimeA;
    } else {
      LAB02_DW.TimeStampB = LAB02_M->Timing.t[0];
      lastU = &LAB02_DW.LastUAtTimeB;
    }

    *lastU = LAB02_B.Gain1;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, LAB02_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(LAB02_M)) { /* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((LAB02_M->Timing.clockTick1+
                            LAB02_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LAB02_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(LAB02_M)!=-1) &&
          !((rtmGetTFinal(LAB02_M)-(((LAB02_M->Timing.clockTick1+
               LAB02_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((LAB02_M->Timing.clockTick1+LAB02_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(LAB02_M, "Simulation finished");
      }

      if (rtmGetStopRequested(LAB02_M)) {
        rtmSetErrorStatus(LAB02_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&LAB02_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++LAB02_M->Timing.clockTick0)) {
      ++LAB02_M->Timing.clockTickH0;
    }

    LAB02_M->Timing.t[0] = rtsiGetSolverStopTime(&LAB02_M->solverInfo);

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
      LAB02_M->Timing.clockTick1++;
      if (!LAB02_M->Timing.clockTick1) {
        LAB02_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void LAB02_derivatives(void)
{
  XDot_LAB02_T *_rtXdot;
  _rtXdot = ((XDot_LAB02_T *) LAB02_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += LAB02_P.TransferFcn1_A *
    LAB02_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += LAB02_B.Derivative;
}

/* Model initialize function */
void LAB02_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LAB02_M, 0,
                sizeof(RT_MODEL_LAB02_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LAB02_M->solverInfo, &LAB02_M->Timing.simTimeStep);
    rtsiSetTPtr(&LAB02_M->solverInfo, &rtmGetTPtr(LAB02_M));
    rtsiSetStepSizePtr(&LAB02_M->solverInfo, &LAB02_M->Timing.stepSize0);
    rtsiSetdXPtr(&LAB02_M->solverInfo, &LAB02_M->ModelData.derivs);
    rtsiSetContStatesPtr(&LAB02_M->solverInfo, (real_T **)
                         &LAB02_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&LAB02_M->solverInfo, &LAB02_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&LAB02_M->solverInfo, (&rtmGetErrorStatus(LAB02_M)));
    rtsiSetRTModelPtr(&LAB02_M->solverInfo, LAB02_M);
  }

  rtsiSetSimTimeStep(&LAB02_M->solverInfo, MAJOR_TIME_STEP);
  LAB02_M->ModelData.intgData.f[0] = LAB02_M->ModelData.odeF[0];
  LAB02_M->ModelData.contStates = ((X_LAB02_T *) &LAB02_X);
  rtsiSetSolverData(&LAB02_M->solverInfo, (void *)&LAB02_M->ModelData.intgData);
  rtsiSetSolverName(&LAB02_M->solverInfo,"ode1");
  rtmSetTPtr(LAB02_M, &LAB02_M->Timing.tArray[0]);
  rtmSetTFinal(LAB02_M, -1);
  LAB02_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB02_M->Sizes.checksums[0] = (3117403250U);
  LAB02_M->Sizes.checksums[1] = (3390922992U);
  LAB02_M->Sizes.checksums[2] = (2631641274U);
  LAB02_M->Sizes.checksums[3] = (806518323U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LAB02_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB02_M->extModeInfo,
      &LAB02_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB02_M->extModeInfo, LAB02_M->Sizes.checksums);
    rteiSetTPtr(LAB02_M->extModeInfo, rtmGetTPtr(LAB02_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB02_B), 0,
                sizeof(B_LAB02_T));

  /* states (continuous) */
  {
    (void) memset((void *)&LAB02_X, 0,
                  sizeof(X_LAB02_T));
  }

  /* states (dwork) */
  (void) memset((void *)&LAB02_DW, 0,
                sizeof(DW_LAB02_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB02_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB02/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB02_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB02_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB02_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB02_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB02_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB02_M, _rt_error_message);
      return;
    }

    if ((LAB02_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB02_P.HILInitialize_set_analog_outp_j && is_switching)) {
      LAB02_DW.HILInitialize_AOMinimums[0] =
        LAB02_P.HILInitialize_analog_output_min;
      LAB02_DW.HILInitialize_AOMinimums[1] =
        LAB02_P.HILInitialize_analog_output_min;
      LAB02_DW.HILInitialize_AOMaximums[0] =
        LAB02_P.HILInitialize_analog_output_max;
      LAB02_DW.HILInitialize_AOMaximums[1] =
        LAB02_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB02_DW.HILInitialize_Card,
        LAB02_P.HILInitialize_analog_output_cha, 2U,
        &LAB02_DW.HILInitialize_AOMinimums[0],
        &LAB02_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB02_M, _rt_error_message);
        return;
      }
    }

    if ((LAB02_P.HILInitialize_set_analog_outp_n && !is_switching) ||
        (LAB02_P.HILInitialize_set_analog_outp_c && is_switching)) {
      LAB02_DW.HILInitialize_AOVoltages[0] =
        LAB02_P.HILInitialize_initial_analog_ou;
      LAB02_DW.HILInitialize_AOVoltages[1] =
        LAB02_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB02_DW.HILInitialize_Card,
        LAB02_P.HILInitialize_analog_output_cha, 2U,
        &LAB02_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB02_M, _rt_error_message);
        return;
      }
    }

    if (LAB02_P.HILInitialize_set_analog_out_cd) {
      LAB02_DW.HILInitialize_AOVoltages[0] =
        LAB02_P.HILInitialize_watchdog_analog_o;
      LAB02_DW.HILInitialize_AOVoltages[1] =
        LAB02_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB02_DW.HILInitialize_Card, LAB02_P.HILInitialize_analog_output_cha,
         2U, &LAB02_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB02_M, _rt_error_message);
        return;
      }
    }

    if ((LAB02_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB02_P.HILInitialize_set_encoder_par_n && is_switching)) {
      LAB02_DW.HILInitialize_QuadratureModes[0] =
        LAB02_P.HILInitialize_quadrature;
      LAB02_DW.HILInitialize_QuadratureModes[1] =
        LAB02_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB02_DW.HILInitialize_Card,
        LAB02_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB02_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB02_M, _rt_error_message);
        return;
      }
    }

    if ((LAB02_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB02_P.HILInitialize_set_encoder_cou_b && is_switching)) {
      LAB02_DW.HILInitialize_InitialEICounts[0] =
        LAB02_P.HILInitialize_initial_encoder_c;
      LAB02_DW.HILInitialize_InitialEICounts[1] =
        LAB02_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB02_DW.HILInitialize_Card,
        LAB02_P.HILInitialize_encoder_channels, 2U,
        &LAB02_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB02_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
  /* S-Function Block: LAB02/Inverse Modulus1 (inverse_modulus_block) */
  {
    LAB02_DW.InverseModulus1_FirstSample = true;
    LAB02_DW.InverseModulus1_Revolutions = 0;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  LAB02_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  LAB02_DW.TimeStampA = (rtInf);
  LAB02_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void LAB02_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB02/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB02_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB02_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB02_P.HILInitialize_set_analog_outp_f && !is_switching) ||
        (LAB02_P.HILInitialize_set_analog_outp_h && is_switching)) {
      LAB02_DW.HILInitialize_AOVoltages[0] =
        LAB02_P.HILInitialize_final_analog_outp;
      LAB02_DW.HILInitialize_AOVoltages[1] =
        LAB02_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB02_DW.HILInitialize_Card,
        LAB02_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB02_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB02_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB02_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB02_DW.HILInitialize_Card);
    hil_close(LAB02_DW.HILInitialize_Card);
    LAB02_DW.HILInitialize_Card = NULL;
  }
}
