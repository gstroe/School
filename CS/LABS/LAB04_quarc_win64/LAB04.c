/*
 * LAB04.c
 *
 * Code generation for model "LAB04".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Mar 01 18:27:14 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "LAB04.h"
#include "LAB04_private.h"
#include "LAB04_dt.h"

/* Block signals (auto storage) */
B_LAB04_T LAB04_B;

/* Block states (auto storage) */
DW_LAB04_T LAB04_DW;

/* Real-time model */
RT_MODEL_LAB04_T LAB04_M_;
RT_MODEL_LAB04_T *const LAB04_M = &LAB04_M_;

/* Model step function */
void LAB04_step(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T currentTime;

  /* Step: '<Root>/Step' */
  currentTime = LAB04_M->Timing.t[0];
  if (currentTime < LAB04_P.Step_Time) {
    LAB04_B.Step = LAB04_P.Step_Y0;
  } else {
    LAB04_B.Step = LAB04_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: LAB04/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(LAB04_DW.HILInitialize_Card,
      &LAB04_P.HILReadEncoder_channels, 1, &LAB04_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB04_M, _rt_error_message);
    } else {
      LAB04_B.HILReadEncoder = LAB04_DW.HILReadEncoder_Buffer;
    }
  }

  /* S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
  /* S-Function Block: LAB04/Inverse Modulus1 (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.002;
    real_T half_range = LAB04_P.InverseModulus1_Modulus / 2.0;
    real_T du, dy;
    if (LAB04_DW.InverseModulus1_FirstSample) {
      LAB04_DW.InverseModulus1_FirstSample = false;
      LAB04_DW.InverseModulus1_PreviousInput = LAB04_B.HILReadEncoder;
    }

    du = (real_T) LAB04_B.HILReadEncoder -
      LAB04_DW.InverseModulus1_PreviousInput;
    if (du > half_range) {
      LAB04_DW.InverseModulus1_Revolutions =
        LAB04_DW.InverseModulus1_Revolutions - 1;
      dy = du - LAB04_P.InverseModulus1_Modulus;
    } else if (du < -half_range) {
      LAB04_DW.InverseModulus1_Revolutions =
        LAB04_DW.InverseModulus1_Revolutions + 1;
      dy = du + LAB04_P.InverseModulus1_Modulus;
    } else {
      dy = du;
    }

    rtb_InverseModulus1 = LAB04_B.HILReadEncoder +
      LAB04_DW.InverseModulus1_Revolutions * LAB04_P.InverseModulus1_Modulus;
    LAB04_DW.InverseModulus1_PreviousInput = LAB04_B.HILReadEncoder;
  }

  /* Gain: '<Root>/To Rads' */
  LAB04_B.ToRads = LAB04_P.ToRads_Gain * rtb_InverseModulus1;

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  LAB04_B.Gain = (LAB04_B.Step - LAB04_B.ToRads) * LAB04_P.Gain_Gain;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: LAB04/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(LAB04_DW.HILInitialize_Card,
      &LAB04_P.HILWriteAnalog_channels, 1, &LAB04_B.Gain);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB04_M, _rt_error_message);
    }
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, LAB04_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(1, (((LAB04_M->Timing.clockTick1+LAB04_M->Timing.clockTickH1*
                          4294967296.0)) * 0.002));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(LAB04_M)!=-1) &&
        !((rtmGetTFinal(LAB04_M)-LAB04_M->Timing.t[0]) > LAB04_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(LAB04_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LAB04_M)) {
      rtmSetErrorStatus(LAB04_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LAB04_M->Timing.clockTick0)) {
    ++LAB04_M->Timing.clockTickH0;
  }

  LAB04_M->Timing.t[0] = LAB04_M->Timing.clockTick0 * LAB04_M->Timing.stepSize0
    + LAB04_M->Timing.clockTickH0 * LAB04_M->Timing.stepSize0 * 4294967296.0;

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
    LAB04_M->Timing.clockTick1++;
    if (!LAB04_M->Timing.clockTick1) {
      LAB04_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void LAB04_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LAB04_M, 0,
                sizeof(RT_MODEL_LAB04_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LAB04_M->solverInfo, &LAB04_M->Timing.simTimeStep);
    rtsiSetTPtr(&LAB04_M->solverInfo, &rtmGetTPtr(LAB04_M));
    rtsiSetStepSizePtr(&LAB04_M->solverInfo, &LAB04_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&LAB04_M->solverInfo, (&rtmGetErrorStatus(LAB04_M)));
    rtsiSetRTModelPtr(&LAB04_M->solverInfo, LAB04_M);
  }

  rtsiSetSimTimeStep(&LAB04_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&LAB04_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(LAB04_M, &LAB04_M->Timing.tArray[0]);
  rtmSetTFinal(LAB04_M, 2.5);
  LAB04_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB04_M->Sizes.checksums[0] = (2350197011U);
  LAB04_M->Sizes.checksums[1] = (1369671219U);
  LAB04_M->Sizes.checksums[2] = (1583766594U);
  LAB04_M->Sizes.checksums[3] = (3451840702U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LAB04_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB04_M->extModeInfo,
      &LAB04_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB04_M->extModeInfo, LAB04_M->Sizes.checksums);
    rteiSetTPtr(LAB04_M->extModeInfo, rtmGetTPtr(LAB04_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB04_B), 0,
                sizeof(B_LAB04_T));

  /* states (dwork) */
  (void) memset((void *)&LAB04_DW, 0,
                sizeof(DW_LAB04_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB04_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB04/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB04_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB04_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB04_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB04_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB04_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB04_M, _rt_error_message);
      return;
    }

    if ((LAB04_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB04_P.HILInitialize_set_analog_outp_j && is_switching)) {
      LAB04_DW.HILInitialize_AOMinimums[0] =
        LAB04_P.HILInitialize_analog_output_min;
      LAB04_DW.HILInitialize_AOMinimums[1] =
        LAB04_P.HILInitialize_analog_output_min;
      LAB04_DW.HILInitialize_AOMaximums[0] =
        LAB04_P.HILInitialize_analog_output_max;
      LAB04_DW.HILInitialize_AOMaximums[1] =
        LAB04_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB04_DW.HILInitialize_Card,
        LAB04_P.HILInitialize_analog_output_cha, 2U,
        &LAB04_DW.HILInitialize_AOMinimums[0],
        &LAB04_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB04_M, _rt_error_message);
        return;
      }
    }

    if ((LAB04_P.HILInitialize_set_analog_outp_i && !is_switching) ||
        (LAB04_P.HILInitialize_set_analog_outp_k && is_switching)) {
      LAB04_DW.HILInitialize_AOVoltages[0] =
        LAB04_P.HILInitialize_initial_analog_ou;
      LAB04_DW.HILInitialize_AOVoltages[1] =
        LAB04_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB04_DW.HILInitialize_Card,
        LAB04_P.HILInitialize_analog_output_cha, 2U,
        &LAB04_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB04_M, _rt_error_message);
        return;
      }
    }

    if (LAB04_P.HILInitialize_set_analog_outp_p) {
      LAB04_DW.HILInitialize_AOVoltages[0] =
        LAB04_P.HILInitialize_watchdog_analog_o;
      LAB04_DW.HILInitialize_AOVoltages[1] =
        LAB04_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB04_DW.HILInitialize_Card, LAB04_P.HILInitialize_analog_output_cha,
         2U, &LAB04_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB04_M, _rt_error_message);
        return;
      }
    }

    if ((LAB04_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB04_P.HILInitialize_set_encoder_par_d && is_switching)) {
      LAB04_DW.HILInitialize_QuadratureModes[0] =
        LAB04_P.HILInitialize_quadrature;
      LAB04_DW.HILInitialize_QuadratureModes[1] =
        LAB04_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB04_DW.HILInitialize_Card,
        LAB04_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB04_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB04_M, _rt_error_message);
        return;
      }
    }

    if ((LAB04_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB04_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      LAB04_DW.HILInitialize_InitialEICounts[0] =
        LAB04_P.HILInitialize_initial_encoder_c;
      LAB04_DW.HILInitialize_InitialEICounts[1] =
        LAB04_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB04_DW.HILInitialize_Card,
        LAB04_P.HILInitialize_encoder_channels, 2U,
        &LAB04_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB04_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
  /* S-Function Block: LAB04/Inverse Modulus1 (inverse_modulus_block) */
  {
    LAB04_DW.InverseModulus1_FirstSample = true;
    LAB04_DW.InverseModulus1_Revolutions = 0;
  }
}

/* Model terminate function */
void LAB04_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB04/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB04_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB04_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB04_P.HILInitialize_set_analog_out_kt && !is_switching) ||
        (LAB04_P.HILInitialize_set_analog_outp_o && is_switching)) {
      LAB04_DW.HILInitialize_AOVoltages[0] =
        LAB04_P.HILInitialize_final_analog_outp;
      LAB04_DW.HILInitialize_AOVoltages[1] =
        LAB04_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB04_DW.HILInitialize_Card,
        LAB04_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB04_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB04_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB04_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB04_DW.HILInitialize_Card);
    hil_close(LAB04_DW.HILInitialize_Card);
    LAB04_DW.HILInitialize_Card = NULL;
  }
}
