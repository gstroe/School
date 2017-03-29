/*
 * LAB08.c
 *
 * Code generation for model "LAB08".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Mar 22 18:18:53 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "LAB08.h"
#include "LAB08_private.h"
#include "LAB08_dt.h"

/* Block signals (auto storage) */
B_LAB08_T LAB08_B;

/* Block states (auto storage) */
DW_LAB08_T LAB08_DW;

/* Real-time model */
RT_MODEL_LAB08_T LAB08_M_;
RT_MODEL_LAB08_T *const LAB08_M = &LAB08_M_;

/* Model step function */
void LAB08_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: LAB08/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(LAB08_DW.HILInitialize_Card,
      &LAB08_P.HILReadEncoder_channels, 1, &LAB08_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB08_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder = LAB08_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/To Rads' */
  LAB08_B.ToRads = LAB08_P.ToRads_Gain * rtb_HILReadEncoder;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, LAB08_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(LAB08_M)!=-1) &&
        !((rtmGetTFinal(LAB08_M)-LAB08_M->Timing.taskTime0) >
          LAB08_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(LAB08_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LAB08_M)) {
      rtmSetErrorStatus(LAB08_M, "Simulation finished");
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
  if (!(++LAB08_M->Timing.clockTick0)) {
    ++LAB08_M->Timing.clockTickH0;
  }

  LAB08_M->Timing.taskTime0 = LAB08_M->Timing.clockTick0 *
    LAB08_M->Timing.stepSize0 + LAB08_M->Timing.clockTickH0 *
    LAB08_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void LAB08_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LAB08_M, 0,
                sizeof(RT_MODEL_LAB08_T));
  rtmSetTFinal(LAB08_M, -1);
  LAB08_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB08_M->Sizes.checksums[0] = (2912171012U);
  LAB08_M->Sizes.checksums[1] = (1681829692U);
  LAB08_M->Sizes.checksums[2] = (3616625476U);
  LAB08_M->Sizes.checksums[3] = (3846752002U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LAB08_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB08_M->extModeInfo,
      &LAB08_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB08_M->extModeInfo, LAB08_M->Sizes.checksums);
    rteiSetTPtr(LAB08_M->extModeInfo, rtmGetTPtr(LAB08_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB08_B), 0,
                sizeof(B_LAB08_T));

  /* states (dwork) */
  (void) memset((void *)&LAB08_DW, 0,
                sizeof(DW_LAB08_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB08_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB08/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB08_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB08_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB08_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB08_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB08_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB08_M, _rt_error_message);
      return;
    }

    if ((LAB08_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB08_P.HILInitialize_set_analog_outp_j && is_switching)) {
      LAB08_DW.HILInitialize_AOMinimums[0] =
        LAB08_P.HILInitialize_analog_output_min;
      LAB08_DW.HILInitialize_AOMinimums[1] =
        LAB08_P.HILInitialize_analog_output_min;
      LAB08_DW.HILInitialize_AOMaximums[0] =
        LAB08_P.HILInitialize_analog_output_max;
      LAB08_DW.HILInitialize_AOMaximums[1] =
        LAB08_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB08_DW.HILInitialize_Card,
        LAB08_P.HILInitialize_analog_output_cha, 2U,
        &LAB08_DW.HILInitialize_AOMinimums[0],
        &LAB08_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB08_M, _rt_error_message);
        return;
      }
    }

    if ((LAB08_P.HILInitialize_set_analog_outp_i && !is_switching) ||
        (LAB08_P.HILInitialize_set_analog_outp_k && is_switching)) {
      LAB08_DW.HILInitialize_AOVoltages[0] =
        LAB08_P.HILInitialize_initial_analog_ou;
      LAB08_DW.HILInitialize_AOVoltages[1] =
        LAB08_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB08_DW.HILInitialize_Card,
        LAB08_P.HILInitialize_analog_output_cha, 2U,
        &LAB08_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB08_M, _rt_error_message);
        return;
      }
    }

    if (LAB08_P.HILInitialize_set_analog_outp_p) {
      LAB08_DW.HILInitialize_AOVoltages[0] =
        LAB08_P.HILInitialize_watchdog_analog_o;
      LAB08_DW.HILInitialize_AOVoltages[1] =
        LAB08_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB08_DW.HILInitialize_Card, LAB08_P.HILInitialize_analog_output_cha,
         2U, &LAB08_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB08_M, _rt_error_message);
        return;
      }
    }

    if ((LAB08_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB08_P.HILInitialize_set_encoder_par_d && is_switching)) {
      LAB08_DW.HILInitialize_QuadratureModes[0] =
        LAB08_P.HILInitialize_quadrature;
      LAB08_DW.HILInitialize_QuadratureModes[1] =
        LAB08_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB08_DW.HILInitialize_Card,
        LAB08_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB08_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB08_M, _rt_error_message);
        return;
      }
    }

    if ((LAB08_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB08_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      LAB08_DW.HILInitialize_InitialEICounts[0] =
        LAB08_P.HILInitialize_initial_encoder_c;
      LAB08_DW.HILInitialize_InitialEICounts[1] =
        LAB08_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB08_DW.HILInitialize_Card,
        LAB08_P.HILInitialize_encoder_channels, 2U,
        &LAB08_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB08_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void LAB08_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB08/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB08_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB08_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB08_P.HILInitialize_set_analog_out_kt && !is_switching) ||
        (LAB08_P.HILInitialize_set_analog_outp_o && is_switching)) {
      LAB08_DW.HILInitialize_AOVoltages[0] =
        LAB08_P.HILInitialize_final_analog_outp;
      LAB08_DW.HILInitialize_AOVoltages[1] =
        LAB08_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB08_DW.HILInitialize_Card,
        LAB08_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB08_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB08_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB08_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB08_DW.HILInitialize_Card);
    hil_close(LAB08_DW.HILInitialize_Card);
    LAB08_DW.HILInitialize_Card = NULL;
  }
}
