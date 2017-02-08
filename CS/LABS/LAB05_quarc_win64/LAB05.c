/*
 * LAB05.c
 *
 * Code generation for model "LAB05".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Feb 22 19:09:50 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "LAB05.h"
#include "LAB05_private.h"
#include "LAB05_dt.h"

/* Block signals (auto storage) */
B_LAB05_T LAB05_B;

/* Continuous states */
X_LAB05_T LAB05_X;

/* Block states (auto storage) */
DW_LAB05_T LAB05_DW;

/* Real-time model */
RT_MODEL_LAB05_T LAB05_M_;
RT_MODEL_LAB05_T *const LAB05_M = &LAB05_M_;

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
  LAB05_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void LAB05_step(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T temp;
  if (rtmIsMajorTimeStep(LAB05_M)) {
    /* set solver stop time */
    if (!(LAB05_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LAB05_M->solverInfo, ((LAB05_M->Timing.clockTickH0
        + 1) * LAB05_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LAB05_M->solverInfo, ((LAB05_M->Timing.clockTick0 +
        1) * LAB05_M->Timing.stepSize0 + LAB05_M->Timing.clockTickH0 *
        LAB05_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LAB05_M)) {
    LAB05_M->Timing.t[0] = rtsiGetT(&LAB05_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(LAB05_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: LAB05/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(LAB05_DW.HILReadEncoderTimebase_Task, 1,
        &LAB05_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
      } else {
        LAB05_B.HILReadEncoderTimebase = LAB05_DW.HILReadEncoderTimebase_Buffer;
      }
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = LAB05_P.SignalGenerator_Frequency * LAB05_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = LAB05_P.SignalGenerator_Amplitude;
  } else {
    temp = -LAB05_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  LAB05_B.Sum = LAB05_P.Gain_Gain * temp + LAB05_P.Constant_Value;
  if (rtmIsMajorTimeStep(LAB05_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: LAB05/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(LAB05_DW.HILInitialize_Card,
        &LAB05_P.HILWriteAnalog_channels, 1, &LAB05_B.Sum);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
      }
    }

    /* S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
    /* S-Function Block: LAB05/Inverse Modulus1 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = LAB05_P.InverseModulus1_Modulus / 2.0;
      real_T du, dy;
      if (LAB05_DW.InverseModulus1_FirstSample) {
        LAB05_DW.InverseModulus1_FirstSample = false;
        LAB05_DW.InverseModulus1_PreviousInput = LAB05_B.HILReadEncoderTimebase;
      }

      du = (real_T) LAB05_B.HILReadEncoderTimebase -
        LAB05_DW.InverseModulus1_PreviousInput;
      if (du > half_range) {
        LAB05_DW.InverseModulus1_Revolutions =
          LAB05_DW.InverseModulus1_Revolutions - 1;
        dy = du - LAB05_P.InverseModulus1_Modulus;
      } else if (du < -half_range) {
        LAB05_DW.InverseModulus1_Revolutions =
          LAB05_DW.InverseModulus1_Revolutions + 1;
        dy = du + LAB05_P.InverseModulus1_Modulus;
      } else {
        dy = du;
      }

      rtb_InverseModulus1 = LAB05_B.HILReadEncoderTimebase +
        LAB05_DW.InverseModulus1_Revolutions * LAB05_P.InverseModulus1_Modulus;
      LAB05_DW.InverseModulus1_PreviousInput = LAB05_B.HILReadEncoderTimebase;
    }

    /* Gain: '<Root>/To Rads' */
    LAB05_B.ToRads = LAB05_P.ToRads_Gain * rtb_InverseModulus1;
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  LAB05_B.TransferFcn1 = 0.0;
  LAB05_B.TransferFcn1 += LAB05_P.TransferFcn1_C * LAB05_X.TransferFcn1_CSTATE;
  LAB05_B.TransferFcn1 += LAB05_P.TransferFcn1_D * LAB05_B.ToRads;

  /* Integrator: '<S1>/Integrator' */
  LAB05_B.Integrator = LAB05_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(LAB05_M)) {
  }

  /* Gain: '<S1>/1//Jeq' incorporates:
   *  Gain: '<S1>/1//Ra'
   *  Gain: '<S1>/Km '
   *  Gain: '<S1>/Kt'
   *  Sum: '<S1>/Sum'
   */
  LAB05_B.Jeq = (LAB05_B.Sum - LAB05_P.Km_Gain * LAB05_B.Integrator) *
    LAB05_P.Ra_Gain * LAB05_P.Kt_Gain * LAB05_P.Jeq_Gain;
  if (rtmIsMajorTimeStep(LAB05_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, LAB05_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(LAB05_M)) { /* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((LAB05_M->Timing.clockTick1+
                            LAB05_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LAB05_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(LAB05_M)!=-1) &&
          !((rtmGetTFinal(LAB05_M)-(((LAB05_M->Timing.clockTick1+
               LAB05_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((LAB05_M->Timing.clockTick1+LAB05_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(LAB05_M, "Simulation finished");
      }

      if (rtmGetStopRequested(LAB05_M)) {
        rtmSetErrorStatus(LAB05_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&LAB05_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++LAB05_M->Timing.clockTick0)) {
      ++LAB05_M->Timing.clockTickH0;
    }

    LAB05_M->Timing.t[0] = rtsiGetSolverStopTime(&LAB05_M->solverInfo);

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
      LAB05_M->Timing.clockTick1++;
      if (!LAB05_M->Timing.clockTick1) {
        LAB05_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void LAB05_derivatives(void)
{
  XDot_LAB05_T *_rtXdot;
  _rtXdot = ((XDot_LAB05_T *) LAB05_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += LAB05_P.TransferFcn1_A *
    LAB05_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += LAB05_B.ToRads;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = LAB05_B.Jeq;
}

/* Model initialize function */
void LAB05_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LAB05_M, 0,
                sizeof(RT_MODEL_LAB05_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LAB05_M->solverInfo, &LAB05_M->Timing.simTimeStep);
    rtsiSetTPtr(&LAB05_M->solverInfo, &rtmGetTPtr(LAB05_M));
    rtsiSetStepSizePtr(&LAB05_M->solverInfo, &LAB05_M->Timing.stepSize0);
    rtsiSetdXPtr(&LAB05_M->solverInfo, &LAB05_M->ModelData.derivs);
    rtsiSetContStatesPtr(&LAB05_M->solverInfo, (real_T **)
                         &LAB05_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&LAB05_M->solverInfo, &LAB05_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&LAB05_M->solverInfo, (&rtmGetErrorStatus(LAB05_M)));
    rtsiSetRTModelPtr(&LAB05_M->solverInfo, LAB05_M);
  }

  rtsiSetSimTimeStep(&LAB05_M->solverInfo, MAJOR_TIME_STEP);
  LAB05_M->ModelData.intgData.f[0] = LAB05_M->ModelData.odeF[0];
  LAB05_M->ModelData.contStates = ((X_LAB05_T *) &LAB05_X);
  rtsiSetSolverData(&LAB05_M->solverInfo, (void *)&LAB05_M->ModelData.intgData);
  rtsiSetSolverName(&LAB05_M->solverInfo,"ode1");
  rtmSetTPtr(LAB05_M, &LAB05_M->Timing.tArray[0]);
  rtmSetTFinal(LAB05_M, 20.0);
  LAB05_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB05_M->Sizes.checksums[0] = (1023813838U);
  LAB05_M->Sizes.checksums[1] = (571467226U);
  LAB05_M->Sizes.checksums[2] = (3938036188U);
  LAB05_M->Sizes.checksums[3] = (3610362785U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LAB05_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB05_M->extModeInfo,
      &LAB05_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB05_M->extModeInfo, LAB05_M->Sizes.checksums);
    rteiSetTPtr(LAB05_M->extModeInfo, rtmGetTPtr(LAB05_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB05_B), 0,
                sizeof(B_LAB05_T));

  /* states (continuous) */
  {
    (void) memset((void *)&LAB05_X, 0,
                  sizeof(X_LAB05_T));
  }

  /* states (dwork) */
  (void) memset((void *)&LAB05_DW, 0,
                sizeof(DW_LAB05_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB05_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB05/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB05_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB05_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB05_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB05_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB05_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB05_M, _rt_error_message);
      return;
    }

    if ((LAB05_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB05_P.HILInitialize_set_analog_outp_a && is_switching)) {
      LAB05_DW.HILInitialize_AOMinimums[0] =
        LAB05_P.HILInitialize_analog_output_min;
      LAB05_DW.HILInitialize_AOMinimums[1] =
        LAB05_P.HILInitialize_analog_output_min;
      LAB05_DW.HILInitialize_AOMaximums[0] =
        LAB05_P.HILInitialize_analog_output_max;
      LAB05_DW.HILInitialize_AOMaximums[1] =
        LAB05_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB05_DW.HILInitialize_Card,
        LAB05_P.HILInitialize_analog_output_cha, 2U,
        &LAB05_DW.HILInitialize_AOMinimums[0],
        &LAB05_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
        return;
      }
    }

    if ((LAB05_P.HILInitialize_set_analog_outp_m && !is_switching) ||
        (LAB05_P.HILInitialize_set_analog_outp_d && is_switching)) {
      LAB05_DW.HILInitialize_AOVoltages[0] =
        LAB05_P.HILInitialize_initial_analog_ou;
      LAB05_DW.HILInitialize_AOVoltages[1] =
        LAB05_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB05_DW.HILInitialize_Card,
        LAB05_P.HILInitialize_analog_output_cha, 2U,
        &LAB05_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
        return;
      }
    }

    if (LAB05_P.HILInitialize_set_analog_outp_l) {
      LAB05_DW.HILInitialize_AOVoltages[0] =
        LAB05_P.HILInitialize_watchdog_analog_o;
      LAB05_DW.HILInitialize_AOVoltages[1] =
        LAB05_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB05_DW.HILInitialize_Card, LAB05_P.HILInitialize_analog_output_cha,
         2U, &LAB05_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
        return;
      }
    }

    if ((LAB05_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB05_P.HILInitialize_set_encoder_par_m && is_switching)) {
      LAB05_DW.HILInitialize_QuadratureModes[0] =
        LAB05_P.HILInitialize_quadrature;
      LAB05_DW.HILInitialize_QuadratureModes[1] =
        LAB05_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB05_DW.HILInitialize_Card,
        LAB05_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB05_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
        return;
      }
    }

    if ((LAB05_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB05_P.HILInitialize_set_encoder_cou_o && is_switching)) {
      LAB05_DW.HILInitialize_InitialEICounts[0] =
        LAB05_P.HILInitialize_initial_encoder_c;
      LAB05_DW.HILInitialize_InitialEICounts[1] =
        LAB05_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB05_DW.HILInitialize_Card,
        LAB05_P.HILInitialize_encoder_channels, 2U,
        &LAB05_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: LAB05/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(LAB05_DW.HILInitialize_Card,
      LAB05_P.HILReadEncoderTimebase_samples_,
      &LAB05_P.HILReadEncoderTimebase_channels, 1,
      &LAB05_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB05_M, _rt_error_message);
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
  /* S-Function Block: LAB05/Inverse Modulus1 (inverse_modulus_block) */
  {
    LAB05_DW.InverseModulus1_FirstSample = true;
    LAB05_DW.InverseModulus1_Revolutions = 0;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  LAB05_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  LAB05_X.Integrator_CSTATE = LAB05_P.Integrator_IC;
}

/* Model terminate function */
void LAB05_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB05/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB05_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB05_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB05_P.HILInitialize_set_analog_outp_p && !is_switching) ||
        (LAB05_P.HILInitialize_set_analog_out_m1 && is_switching)) {
      LAB05_DW.HILInitialize_AOVoltages[0] =
        LAB05_P.HILInitialize_final_analog_outp;
      LAB05_DW.HILInitialize_AOVoltages[1] =
        LAB05_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB05_DW.HILInitialize_Card,
        LAB05_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB05_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB05_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB05_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB05_DW.HILInitialize_Card);
    hil_close(LAB05_DW.HILInitialize_Card);
    LAB05_DW.HILInitialize_Card = NULL;
  }
}
