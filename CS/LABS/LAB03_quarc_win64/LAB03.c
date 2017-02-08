/*
 * LAB03.c
 *
 * Code generation for model "LAB03".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Feb 08 18:50:57 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "LAB03.h"
#include "LAB03_private.h"
#include "LAB03_dt.h"

/* Block signals (auto storage) */
B_LAB03_T LAB03_B;

/* Continuous states */
X_LAB03_T LAB03_X;

/* Block states (auto storage) */
DW_LAB03_T LAB03_DW;

/* Real-time model */
RT_MODEL_LAB03_T LAB03_M_;
RT_MODEL_LAB03_T *const LAB03_M = &LAB03_M_;

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
  LAB03_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void LAB03_step(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T currentTime;
  if (rtmIsMajorTimeStep(LAB03_M)) {
    /* set solver stop time */
    if (!(LAB03_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&LAB03_M->solverInfo, ((LAB03_M->Timing.clockTickH0
        + 1) * LAB03_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&LAB03_M->solverInfo, ((LAB03_M->Timing.clockTick0 +
        1) * LAB03_M->Timing.stepSize0 + LAB03_M->Timing.clockTickH0 *
        LAB03_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(LAB03_M)) {
    LAB03_M->Timing.t[0] = rtsiGetT(&LAB03_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(LAB03_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: LAB03/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(LAB03_DW.HILInitialize_Card,
        &LAB03_P.HILReadEncoder_channels, 1, &LAB03_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
      } else {
        LAB03_B.HILReadEncoder = LAB03_DW.HILReadEncoder_Buffer;
      }
    }

    /* S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
    /* S-Function Block: LAB03/Inverse Modulus1 (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.002;
      real_T half_range = LAB03_P.InverseModulus1_Modulus / 2.0;
      real_T du, dy;
      if (LAB03_DW.InverseModulus1_FirstSample) {
        LAB03_DW.InverseModulus1_FirstSample = false;
        LAB03_DW.InverseModulus1_PreviousInput = LAB03_B.HILReadEncoder;
      }

      du = (real_T) LAB03_B.HILReadEncoder -
        LAB03_DW.InverseModulus1_PreviousInput;
      if (du > half_range) {
        LAB03_DW.InverseModulus1_Revolutions =
          LAB03_DW.InverseModulus1_Revolutions - 1;
        dy = du - LAB03_P.InverseModulus1_Modulus;
      } else if (du < -half_range) {
        LAB03_DW.InverseModulus1_Revolutions =
          LAB03_DW.InverseModulus1_Revolutions + 1;
        dy = du + LAB03_P.InverseModulus1_Modulus;
      } else {
        dy = du;
      }

      rtb_InverseModulus1 = LAB03_B.HILReadEncoder +
        LAB03_DW.InverseModulus1_Revolutions * LAB03_P.InverseModulus1_Modulus;
      LAB03_DW.InverseModulus1_PreviousInput = LAB03_B.HILReadEncoder;
    }

    /* Gain: '<Root>/To Rads' */
    LAB03_B.ToRads = LAB03_P.ToRads_Gain * rtb_InverseModulus1;
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  LAB03_B.TransferFcn1 = 0.0;
  LAB03_B.TransferFcn1 += LAB03_P.TransferFcn1_C * LAB03_X.TransferFcn1_CSTATE;
  LAB03_B.TransferFcn1 += LAB03_P.TransferFcn1_D * LAB03_B.ToRads;
  if (rtmIsMajorTimeStep(LAB03_M)) {
  }

  /* Step: '<Root>/Step' */
  currentTime = LAB03_M->Timing.t[0];
  if (currentTime < LAB03_P.Step_Time) {
    LAB03_B.Step = LAB03_P.Step_Y0;
  } else {
    LAB03_B.Step = LAB03_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
  if (rtmIsMajorTimeStep(LAB03_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: LAB03/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(LAB03_DW.HILInitialize_Card,
        &LAB03_P.HILWriteAnalog_channels, 1, &LAB03_B.Step);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
      }
    }
  }

  if (rtmIsMajorTimeStep(LAB03_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, LAB03_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(LAB03_M)) { /* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((LAB03_M->Timing.clockTick1+
                            LAB03_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(LAB03_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(LAB03_M)!=-1) &&
          !((rtmGetTFinal(LAB03_M)-(((LAB03_M->Timing.clockTick1+
               LAB03_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((LAB03_M->Timing.clockTick1+LAB03_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(LAB03_M, "Simulation finished");
      }

      if (rtmGetStopRequested(LAB03_M)) {
        rtmSetErrorStatus(LAB03_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&LAB03_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++LAB03_M->Timing.clockTick0)) {
      ++LAB03_M->Timing.clockTickH0;
    }

    LAB03_M->Timing.t[0] = rtsiGetSolverStopTime(&LAB03_M->solverInfo);

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
      LAB03_M->Timing.clockTick1++;
      if (!LAB03_M->Timing.clockTick1) {
        LAB03_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void LAB03_derivatives(void)
{
  XDot_LAB03_T *_rtXdot;
  _rtXdot = ((XDot_LAB03_T *) LAB03_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += LAB03_P.TransferFcn1_A *
    LAB03_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += LAB03_B.ToRads;
}

/* Model initialize function */
void LAB03_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LAB03_M, 0,
                sizeof(RT_MODEL_LAB03_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LAB03_M->solverInfo, &LAB03_M->Timing.simTimeStep);
    rtsiSetTPtr(&LAB03_M->solverInfo, &rtmGetTPtr(LAB03_M));
    rtsiSetStepSizePtr(&LAB03_M->solverInfo, &LAB03_M->Timing.stepSize0);
    rtsiSetdXPtr(&LAB03_M->solverInfo, &LAB03_M->ModelData.derivs);
    rtsiSetContStatesPtr(&LAB03_M->solverInfo, (real_T **)
                         &LAB03_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&LAB03_M->solverInfo, &LAB03_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&LAB03_M->solverInfo, (&rtmGetErrorStatus(LAB03_M)));
    rtsiSetRTModelPtr(&LAB03_M->solverInfo, LAB03_M);
  }

  rtsiSetSimTimeStep(&LAB03_M->solverInfo, MAJOR_TIME_STEP);
  LAB03_M->ModelData.intgData.f[0] = LAB03_M->ModelData.odeF[0];
  LAB03_M->ModelData.contStates = ((X_LAB03_T *) &LAB03_X);
  rtsiSetSolverData(&LAB03_M->solverInfo, (void *)&LAB03_M->ModelData.intgData);
  rtsiSetSolverName(&LAB03_M->solverInfo,"ode1");
  rtmSetTPtr(LAB03_M, &LAB03_M->Timing.tArray[0]);
  rtmSetTFinal(LAB03_M, -1);
  LAB03_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  LAB03_M->Sizes.checksums[0] = (911439470U);
  LAB03_M->Sizes.checksums[1] = (2423040542U);
  LAB03_M->Sizes.checksums[2] = (552203472U);
  LAB03_M->Sizes.checksums[3] = (347973715U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LAB03_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LAB03_M->extModeInfo,
      &LAB03_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LAB03_M->extModeInfo, LAB03_M->Sizes.checksums);
    rteiSetTPtr(LAB03_M->extModeInfo, rtmGetTPtr(LAB03_M));
  }

  /* block I/O */
  (void) memset(((void *) &LAB03_B), 0,
                sizeof(B_LAB03_T));

  /* states (continuous) */
  {
    (void) memset((void *)&LAB03_X, 0,
                  sizeof(X_LAB03_T));
  }

  /* states (dwork) */
  (void) memset((void *)&LAB03_DW, 0,
                sizeof(DW_LAB03_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LAB03_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB03/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &LAB03_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB03_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(LAB03_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB03_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(LAB03_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(LAB03_M, _rt_error_message);
      return;
    }

    if ((LAB03_P.HILInitialize_set_analog_output && !is_switching) ||
        (LAB03_P.HILInitialize_set_analog_outp_j && is_switching)) {
      LAB03_DW.HILInitialize_AOMinimums[0] =
        LAB03_P.HILInitialize_analog_output_min;
      LAB03_DW.HILInitialize_AOMinimums[1] =
        LAB03_P.HILInitialize_analog_output_min;
      LAB03_DW.HILInitialize_AOMaximums[0] =
        LAB03_P.HILInitialize_analog_output_max;
      LAB03_DW.HILInitialize_AOMaximums[1] =
        LAB03_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges(LAB03_DW.HILInitialize_Card,
        LAB03_P.HILInitialize_analog_output_cha, 2U,
        &LAB03_DW.HILInitialize_AOMinimums[0],
        &LAB03_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
        return;
      }
    }

    if ((LAB03_P.HILInitialize_set_analog_outp_i && !is_switching) ||
        (LAB03_P.HILInitialize_set_analog_outp_k && is_switching)) {
      LAB03_DW.HILInitialize_AOVoltages[0] =
        LAB03_P.HILInitialize_initial_analog_ou;
      LAB03_DW.HILInitialize_AOVoltages[1] =
        LAB03_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(LAB03_DW.HILInitialize_Card,
        LAB03_P.HILInitialize_analog_output_cha, 2U,
        &LAB03_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
        return;
      }
    }

    if (LAB03_P.HILInitialize_set_analog_outp_p) {
      LAB03_DW.HILInitialize_AOVoltages[0] =
        LAB03_P.HILInitialize_watchdog_analog_o;
      LAB03_DW.HILInitialize_AOVoltages[1] =
        LAB03_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (LAB03_DW.HILInitialize_Card, LAB03_P.HILInitialize_analog_output_cha,
         2U, &LAB03_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
        return;
      }
    }

    if ((LAB03_P.HILInitialize_set_encoder_param && !is_switching) ||
        (LAB03_P.HILInitialize_set_encoder_par_d && is_switching)) {
      LAB03_DW.HILInitialize_QuadratureModes[0] =
        LAB03_P.HILInitialize_quadrature;
      LAB03_DW.HILInitialize_QuadratureModes[1] =
        LAB03_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(LAB03_DW.HILInitialize_Card,
        LAB03_P.HILInitialize_encoder_channels, 2U, (t_encoder_quadrature_mode *)
        &LAB03_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
        return;
      }
    }

    if ((LAB03_P.HILInitialize_set_encoder_count && !is_switching) ||
        (LAB03_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      LAB03_DW.HILInitialize_InitialEICounts[0] =
        LAB03_P.HILInitialize_initial_encoder_c;
      LAB03_DW.HILInitialize_InitialEICounts[1] =
        LAB03_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(LAB03_DW.HILInitialize_Card,
        LAB03_P.HILInitialize_encoder_channels, 2U,
        &LAB03_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<Root>/Inverse Modulus1' */
  /* S-Function Block: LAB03/Inverse Modulus1 (inverse_modulus_block) */
  {
    LAB03_DW.InverseModulus1_FirstSample = true;
    LAB03_DW.InverseModulus1_Revolutions = 0;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  LAB03_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void LAB03_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: LAB03/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(LAB03_DW.HILInitialize_Card);
    hil_monitor_stop_all(LAB03_DW.HILInitialize_Card);
    is_switching = false;
    if ((LAB03_P.HILInitialize_set_analog_out_kt && !is_switching) ||
        (LAB03_P.HILInitialize_set_analog_outp_o && is_switching)) {
      LAB03_DW.HILInitialize_AOVoltages[0] =
        LAB03_P.HILInitialize_final_analog_outp;
      LAB03_DW.HILInitialize_AOVoltages[1] =
        LAB03_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(LAB03_DW.HILInitialize_Card,
        LAB03_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
        &LAB03_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(LAB03_M, _rt_error_message);
      }
    }

    hil_task_delete_all(LAB03_DW.HILInitialize_Card);
    hil_monitor_delete_all(LAB03_DW.HILInitialize_Card);
    hil_close(LAB03_DW.HILInitialize_Card);
    LAB03_DW.HILInitialize_Card = NULL;
  }
}
