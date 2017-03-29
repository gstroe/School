/*
 * LAB07.c
 *
 * Code generation for model "LAB07".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Mar 15 19:01:58 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "LAB07.h"
#include "LAB07_private.h"
#include "LAB07_dt.h"

/* Block signals (auto storage) */
B_LAB07_T LAB07_B;

/* Continuous states */
X_LAB07_T LAB07_X;

/* Block states (auto storage) */
DW_LAB07_T LAB07_DW;

/* Real-time model */
RT_MODEL_LAB07_T LAB07_M_;
RT_MODEL_LAB07_T *const LAB07_M = &LAB07_M_;

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
  LAB07_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void LAB07_step(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T rtb_TransferFcn;
  if (rtmIsMajorTimeStep(LAB07_M)) {
    /* set solver stop time */
    if (!(LAB07_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LAB07_M->solverInfo, ((LAB07_M->Timing.clockTickH0
        + 1) * LAB07_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LAB07_M->solverInfo, ((LAB07_M->Timing.clockTick0 +
        1) * LAB07_M->Timing.stepSize0 + LAB07_M->Timing.clockTickH0 *
        LAB07_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LAB07_M)) {
    LAB07_M->Timing.t[0] = rtsiGetT(&LAB07_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(LAB07_M)) {
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_TransferFcn = LAB07_P.SignalGenerator_Frequency * LAB07_M->Timing.t[0];
  if (rtb_TransferFcn - floor(rtb_TransferFcn) >= 0.5) {
    rtb_TransferFcn = LAB07_P.SignalGenerator_Amplitude;
  } else {
    rtb_TransferFcn = -LAB07_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Gain1' */
  LAB07_B.Gain1 = LAB07_P.Gain1_Gain * rtb_TransferFcn;
  if (rtmIsMajorTimeStep(LAB07_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: LAB07/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(LAB07_DW.HILInitialize_Card,
        &LAB07_P.HILReadEncoder_channels, 1, &LAB07_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
      } else {
        LAB07_B.HILReadEncoder = LAB07_DW.HILReadEncoder_Buffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
    /* S-Function Block: LAB07/Inverse Modulus1 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = LAB07_P.InverseModulus1_Modulus / 2.0;
      real_T du, dy;
      if (LAB07_DW.InverseModulus1_FirstSample) {
        LAB07_DW.InverseModulus1_FirstSample = false;
        LAB07_DW.InverseModulus1_PreviousInput = LAB07_B.HILReadEncoder;
      }

      du = (real_T) LAB07_B.HILReadEncoder -
        LAB07_DW.InverseModulus1_PreviousInput;
      if (du > half_range) {
        LAB07_DW.InverseModulus1_Revolutions =
          LAB07_DW.InverseModulus1_Revolutions - 1;
        dy = du - LAB07_P.InverseModulus1_Modulus;
      } else if (du < -half_range) {
        LAB07_DW.InverseModulus1_Revolutions =
          LAB07_DW.InverseModulus1_Revolutions + 1;
        dy = du + LAB07_P.InverseModulus1_Modulus;
      } else {
        dy = du;
      }

      rtb_InverseModulus1 = LAB07_B.HILReadEncoder +
        LAB07_DW.InverseModulus1_Revolutions * LAB07_P.InverseModulus1_Modulus;
      LAB07_DW.InverseModulus1_PreviousInput = LAB07_B.HILReadEncoder;
    }

    /* Gain: '<Root>/To Rads' */
    LAB07_B.ToRads = LAB07_P.ToRads_Gain * rtb_InverseModulus1;
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S1>/Slider Gain'
   *  Gain: '<S2>/Slider Gain'
   *  Sum: '<Root>/Sum'
   *  TransferFcn: '<Root>/Transfer Fcn'
   */
  LAB07_B.Sum1 = (LAB07_B.Gain1 - LAB07_B.ToRads) * LAB07_P.Kp_gain -
    (LAB07_P.TransferFcn_C * LAB07_X.TransferFcn_CSTATE + LAB07_P.TransferFcn_D *
     LAB07_B.ToRads) * LAB07_P.Kd_gain;
  if (rtmIsMajorTimeStep(LAB07_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: LAB07/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(LAB07_DW.HILInitialize_Card,
        &LAB07_P.HILWriteAnalog_channels, 1, &LAB07_B.Sum1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
      }
    }
  }

  if (rtmIsMajorTimeStep(LAB07_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, LAB07_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(LAB07_M)) { /* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((LAB07_M->Timing.clockTick1+
                            LAB07_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LAB07_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(LAB07_M)!=-1) &&
          !((rtmGetTFinal(LAB07_M)-(((LAB07_M->Timing.clockTick1+
               LAB07_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((LAB07_M->Timing.clockTick1+LAB07_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(LAB07_M, "Simulation finished");
      }

      if (rtmGetStopRequested(LAB07_M)) {
        rtmSetErrorStatus(LAB07_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&LAB07_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++LAB07_M->Timing.clockTick0)) {
      ++LAB07_M->Timing.clockTickH0;
    }

    LAB07_M->Timing.t[0] = rtsiGetSolverStopTime(&LAB07_M->solverInfo);

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
      LAB07_M->Timing.clockTick1++;
      if (!LAB07_M->Timing.clockTick1) {
        LAB07_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void LAB07_derivatives(void)
{
  XDot_LAB07_T *_rtXdot;
  _rtXdot = ((XDot_LAB07_T *) LAB07_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += LAB07_P.TransferFcn_A *
    LAB07_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += LAB07_B.ToRads;
}

/* Model initialize function */
void LAB07_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LAB07_M, 0,
                sizeof(RT_MODEL_LAB07_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LAB07_M->solverInfo, &LAB07_M->Timing.simTimeStep);
    rtsiSetTPtr(&LAB07_M->solverInfo, &rtmGetTPtr(LAB07_M));
    rtsiSetStepSizePtr(&LAB07_M->solverInfo, &LAB07_M->Timing.stepSize0);
    rtsiSetdXPtr(&LAB07_M->solverInfo, &LAB07_M->ModelData.derivs);
    rtsiSetContStatesPtr(&LAB07_M->solverInfo, (real_T **)
                         &LAB07_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&LAB07_M->solverInfo, &LAB07_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&LAB07_M->solverInfo, (&rtmGetErrorStatus(LAB07_M)));
    rtsiSetRTModelPtr(&LAB07_M->solverInfo, LAB07_M);
  }

  rtsiSetSimTimeStep(&LAB07_M->solverInfo, MAJOR_TIME_STEP);
  LAB07_M->ModelData.intgData.f[0] = LAB07_M->ModelData.odeF[0];
  LAB07_M->ModelData.contStates = ((X_LAB07_T *) &LAB07_X);
  rtsiSetSolverData(&LAB07_M->solverInfo, (void *)&LAB07_M->ModelData.intgData);
  rtsiSetSolverName(&LAB07_M->solverInfo,"ode1");
  rtmSetTPtr(LAB07_M, &LAB07_M->Timing.tArray[0]);
  rtmSetTFinal(LAB07_M, 8.0);
  LAB07_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB07_M->Sizes.checksums[0] = (2101524737U);
  LAB07_M->Sizes.checksums[1] = (3363252869U);
  LAB07_M->Sizes.checksums[2] = (1761810848U);
  LAB07_M->Sizes.checksums[3] = (2824623708U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LAB07_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB07_M->extModeInfo,
      &LAB07_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB07_M->extModeInfo, LAB07_M->Sizes.checksums);
    rteiSetTPtr(LAB07_M->extModeInfo, rtmGetTPtr(LAB07_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB07_B), 0,
                sizeof(B_LAB07_T));

  /* states (continuous) */
  {
    (void) memset((void *)&LAB07_X, 0,
                  sizeof(X_LAB07_T));
  }

  /* states (dwork) */
  (void) memset((void *)&LAB07_DW, 0,
                sizeof(DW_LAB07_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB07_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB07/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB07_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB07_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB07_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB07_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB07_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB07_M, _rt_error_message);
      return;
    }

    if ((LAB07_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB07_P.HILInitialize_set_analog_outp_j && is_switching)) {
      LAB07_DW.HILInitialize_AOMinimums[0] =
        LAB07_P.HILInitialize_analog_output_min;
      LAB07_DW.HILInitialize_AOMinimums[1] =
        LAB07_P.HILInitialize_analog_output_min;
      LAB07_DW.HILInitialize_AOMaximums[0] =
        LAB07_P.HILInitialize_analog_output_max;
      LAB07_DW.HILInitialize_AOMaximums[1] =
        LAB07_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB07_DW.HILInitialize_Card,
        LAB07_P.HILInitialize_analog_output_cha, 2U,
        &LAB07_DW.HILInitialize_AOMinimums[0],
        &LAB07_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
        return;
      }
    }

    if ((LAB07_P.HILInitialize_set_analog_outp_i && !is_switching) ||
        (LAB07_P.HILInitialize_set_analog_outp_k && is_switching)) {
      LAB07_DW.HILInitialize_AOVoltages[0] =
        LAB07_P.HILInitialize_initial_analog_ou;
      LAB07_DW.HILInitialize_AOVoltages[1] =
        LAB07_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB07_DW.HILInitialize_Card,
        LAB07_P.HILInitialize_analog_output_cha, 2U,
        &LAB07_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
        return;
      }
    }

    if (LAB07_P.HILInitialize_set_analog_outp_p) {
      LAB07_DW.HILInitialize_AOVoltages[0] =
        LAB07_P.HILInitialize_watchdog_analog_o;
      LAB07_DW.HILInitialize_AOVoltages[1] =
        LAB07_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB07_DW.HILInitialize_Card, LAB07_P.HILInitialize_analog_output_cha,
         2U, &LAB07_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
        return;
      }
    }

    if ((LAB07_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB07_P.HILInitialize_set_encoder_par_d && is_switching)) {
      LAB07_DW.HILInitialize_QuadratureModes[0] =
        LAB07_P.HILInitialize_quadrature;
      LAB07_DW.HILInitialize_QuadratureModes[1] =
        LAB07_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB07_DW.HILInitialize_Card,
        LAB07_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB07_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
        return;
      }
    }

    if ((LAB07_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB07_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      LAB07_DW.HILInitialize_InitialEICounts[0] =
        LAB07_P.HILInitialize_initial_encoder_c;
      LAB07_DW.HILInitialize_InitialEICounts[1] =
        LAB07_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB07_DW.HILInitialize_Card,
        LAB07_P.HILInitialize_encoder_channels, 2U,
        &LAB07_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
  /* S-Function Block: LAB07/Inverse Modulus1 (inverse_modulus_block) */
  {
    LAB07_DW.InverseModulus1_FirstSample = true;
    LAB07_DW.InverseModulus1_Revolutions = 0;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  LAB07_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void LAB07_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB07/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB07_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB07_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB07_P.HILInitialize_set_analog_out_kt && !is_switching) ||
        (LAB07_P.HILInitialize_set_analog_outp_o && is_switching)) {
      LAB07_DW.HILInitialize_AOVoltages[0] =
        LAB07_P.HILInitialize_final_analog_outp;
      LAB07_DW.HILInitialize_AOVoltages[1] =
        LAB07_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB07_DW.HILInitialize_Card,
        LAB07_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB07_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB07_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB07_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB07_DW.HILInitialize_Card);
    hil_close(LAB07_DW.HILInitialize_Card);
    LAB07_DW.HILInitialize_Card = NULL;
  }
}
