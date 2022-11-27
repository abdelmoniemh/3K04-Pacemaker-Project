/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test2.c
 *
 * Code generated for Simulink model 'Test2'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Nov 27 14:39:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test2.h"
#include "rtwtypes.h"
#include <math.h>
#include "Test2_types.h"
#include "Test2_private.h"
#include "Test2_dt.h"

/* Named constants for Chart: '<S1>/Chart' */
#define IN_Atrial_Refractory_Period_Pos (1U)
#define IN_Ventricular_Refractory_Perio (4U)
#define Test2_IN_AAI                   (1U)
#define Test2_IN_AOO                   (2U)
#define Test2_IN_CHARGING              (2U)
#define Test2_IN_CHARGING_DISCHARGING  (1U)
#define Test2_IN_CHARGING_e            (1U)
#define Test2_IN_DISCHARGING           (3U)
#define Test2_IN_DISCHARGING_i         (2U)
#define Test2_IN_NO_ACTIVE_CHILD       ((uint8_T)0U)
#define Test2_IN_PACE_ATR              (2U)
#define Test2_IN_PACE_ATR_i            (4U)
#define Test2_IN_PACE_ATR_if           (3U)
#define Test2_IN_Start                 (3U)
#define Test2_IN_VOO                   (4U)
#define Test2_IN_VVI                   (5U)

/* Block signals (default storage) */
B_Test2_T Test2_B;

/* Block states (default storage) */
DW_Test2_T Test2_DW;

/* Real-time model */
static RT_MODEL_Test2_T Test2_M_;
RT_MODEL_Test2_T *const Test2_M = &Test2_M_;

/* Forward declaration for local functions */
static void Test2_VVI(void);
static void Test2_AAI(void);

/* Function for Chart: '<S1>/Chart' */
static void Test2_VVI(void)
{
  boolean_T guard1 = false;
  if (Test2_B.BD != 4.0) {
    Test2_DW.is_VVI = Test2_IN_NO_ACTIVE_CHILD;
    Test2_DW.is_c3_Test2 = Test2_IN_Start;
  } else {
    guard1 = false;
    switch (Test2_DW.is_VVI) {
     case Test2_IN_CHARGING_e:
      Test2_B.FRONTEND_CTRL = true;
      Test2_B.ATR_PACE_CTRL = false;
      Test2_B.VENT_PACE_CTRL = false;
      Test2_B.PACE_CHARGE_CTRL = true;
      Test2_B.VENT_CMP_REF_PWM = 75.0;
      if (Test2_B.DigitalRead1) {
        Test2_DW.is_VVI = IN_Ventricular_Refractory_Perio;
        Test2_DW.temporalCounter_i1 = 0U;
      } else if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
                   Test2_B.LRL - Test2_DW.delta) - Test2_B.VENT_PW)) {
        Test2_DW.is_VVI = Test2_IN_PACE_ATR_if;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.PACE_CHARGE_CTRL = false;
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.ATR_GND_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.VENT_PACE_CTRL = true;
      }
      break;

     case Test2_IN_DISCHARGING_i:
      Test2_B.PACE_GND_CTRL = true;
      Test2_B.VENT_PACE_CTRL = false;
      Test2_B.Z_ATR_CTRL = false;
      Test2_B.Z_VENT_CTRL = false;
      Test2_B.ATR_PACE_CTRL = false;
      Test2_B.ATR_GND_CTRL = false;
      Test2_B.VENT_GND_CTRL = true;
      if ((Test2_DW.sensing == 0.0) && (Test2_DW.temporalCounter_i1 >= (uint32_T)
           ceil(Test2_B.VRP))) {
        Test2_DW.delta = Test2_B.VRP;
        guard1 = true;
      } else if ((Test2_DW.sensing == 1.0) && (Test2_DW.temporalCounter_i1 >= 1U))
      {
        Test2_DW.delta = 0.0;
        Test2_DW.sensing = 0.0;
        guard1 = true;
      }
      break;

     case Test2_IN_PACE_ATR_if:
      Test2_B.PACE_CHARGE_CTRL = false;
      Test2_B.PACE_GND_CTRL = true;
      Test2_B.ATR_PACE_CTRL = false;
      Test2_B.ATR_GND_CTRL = false;
      Test2_B.Z_ATR_CTRL = false;
      Test2_B.Z_VENT_CTRL = false;
      Test2_B.VENT_GND_CTRL = false;
      Test2_B.VENT_PACE_CTRL = true;
      if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(Test2_B.VENT_PW)) {
        Test2_DW.is_VVI = Test2_IN_DISCHARGING_i;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.VENT_GND_CTRL = true;
      }
      break;

     default:
      /* case IN_Ventricular_Refractory_Period_Post_Sensing: */
      if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(Test2_B.VRP + 35.0)) {
        Test2_DW.delta = Test2_B.VRP;
        Test2_DW.sensing = 1.0;
        Test2_DW.is_VVI = Test2_IN_CHARGING_e;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.FRONTEND_CTRL = true;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.PACING_REF_PWM = 90.0;
        Test2_B.PACE_CHARGE_CTRL = true;
        Test2_B.VENT_CMP_REF_PWM = 75.0;
      }
      break;
    }

    if (guard1) {
      Test2_DW.is_VVI = Test2_IN_CHARGING_e;
      Test2_DW.temporalCounter_i1 = 0U;
      Test2_B.FRONTEND_CTRL = true;
      Test2_B.PACING_REF_PWM = 90.0;
      Test2_B.PACE_CHARGE_CTRL = true;
      Test2_B.VENT_CMP_REF_PWM = 75.0;
    }
  }
}

/* Function for Chart: '<S1>/Chart' */
static void Test2_AAI(void)
{
  boolean_T guard1 = false;
  if (Test2_B.BD != 3.0) {
    Test2_DW.is_AAI = Test2_IN_NO_ACTIVE_CHILD;
    Test2_DW.is_c3_Test2 = Test2_IN_Start;
  } else {
    guard1 = false;
    switch (Test2_DW.is_AAI) {
     case IN_Atrial_Refractory_Period_Pos:
      if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(Test2_B.ARP + 35.0)) {
        Test2_DW.delta = Test2_B.ARP;
        Test2_DW.sensing = 1.0;
        Test2_DW.is_AAI = Test2_IN_CHARGING;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.FRONTEND_CTRL = true;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.PACING_REF_PWM = 90.0;
        Test2_B.PACE_CHARGE_CTRL = true;
        Test2_B.ATR_CMP_REF_PWM = 75.0;
      }
      break;

     case Test2_IN_CHARGING:
      Test2_B.FRONTEND_CTRL = true;
      Test2_B.VENT_PACE_CTRL = false;
      Test2_B.ATR_PACE_CTRL = false;
      Test2_B.PACE_CHARGE_CTRL = true;
      Test2_B.ATR_CMP_REF_PWM = 75.0;
      if (Test2_B.DigitalRead) {
        Test2_DW.is_AAI = IN_Atrial_Refractory_Period_Pos;
        Test2_DW.temporalCounter_i1 = 0U;
      } else if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
                   Test2_B.LRL - Test2_DW.delta) - Test2_B.ATR_PW)) {
        Test2_DW.is_AAI = Test2_IN_PACE_ATR_i;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.PACE_CHARGE_CTRL = false;
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.ATR_GND_CTRL = false;
        Test2_B.ATR_PACE_CTRL = true;
      }
      break;

     case Test2_IN_DISCHARGING:
      Test2_B.PACE_GND_CTRL = true;
      Test2_B.ATR_PACE_CTRL = false;
      Test2_B.Z_VENT_CTRL = false;
      Test2_B.Z_ATR_CTRL = false;
      Test2_B.VENT_PACE_CTRL = false;
      Test2_B.VENT_GND_CTRL = false;
      Test2_B.ATR_GND_CTRL = true;
      if ((Test2_DW.sensing == 0.0) && (Test2_DW.temporalCounter_i1 >= (uint32_T)
           ceil(Test2_B.ARP))) {
        Test2_DW.delta = Test2_B.ARP;
        guard1 = true;
      } else if ((Test2_DW.sensing == 1.0) && (Test2_DW.temporalCounter_i1 >= 1U))
      {
        Test2_DW.delta = 0.0;
        Test2_DW.sensing = 0.0;
        guard1 = true;
      }
      break;

     default:
      /* case IN_PACE_ATR: */
      Test2_B.PACE_CHARGE_CTRL = false;
      Test2_B.PACE_GND_CTRL = true;
      Test2_B.VENT_PACE_CTRL = false;
      Test2_B.VENT_GND_CTRL = false;
      Test2_B.Z_VENT_CTRL = false;
      Test2_B.Z_ATR_CTRL = false;
      Test2_B.ATR_GND_CTRL = false;
      Test2_B.ATR_PACE_CTRL = true;
      if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(Test2_B.ATR_PW)) {
        Test2_DW.is_AAI = Test2_IN_DISCHARGING;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.ATR_GND_CTRL = true;
      }
      break;
    }

    if (guard1) {
      Test2_DW.is_AAI = Test2_IN_CHARGING;
      Test2_DW.temporalCounter_i1 = 0U;
      Test2_B.FRONTEND_CTRL = true;
      Test2_B.PACING_REF_PWM = 90.0;
      Test2_B.PACE_CHARGE_CTRL = true;
      Test2_B.ATR_CMP_REF_PWM = 75.0;
    }
  }
}

/* Model step function */
void Test2_step(void)
{
  /* Constant: '<Root>/ARP' */
  Test2_B.ARP = Test2_P.ARP_Value;

  /* Constant: '<Root>/ATR_AMPL' */
  Test2_B.ATR_AMPL = Test2_P.ATR_AMPL_Value;

  /* Constant: '<Root>/ATR_PW' */
  Test2_B.ATR_PW = Test2_P.ATR_PW_Value;

  /* Constant: '<Root>/BD' */
  Test2_B.BD = Test2_P.BD_Value;

  /* Constant: '<Root>/VENT_AMPL' */
  Test2_B.VENT_AMPL = Test2_P.VENT_AMPL_Value;

  /* Constant: '<Root>/LRL' */
  Test2_B.LRL = Test2_P.LRL_Value;

  /* Constant: '<Root>/VRP' */
  Test2_B.VRP = Test2_P.VRP_Value;

  /* Constant: '<Root>/VENT_PW' */
  Test2_B.VENT_PW = Test2_P.VENT_PW_Value;

  /* MATLABSystem: '<S4>/Digital Read' */
  if (Test2_DW.obj_g.SampleTime != Test2_P.DigitalRead_SampleTime) {
    Test2_DW.obj_g.SampleTime = Test2_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<S4>/Digital Read' */
  Test2_B.DigitalRead = MW_digitalIO_read(Test2_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S4>/Digital Read1' */
  if (Test2_DW.obj_o.SampleTime != Test2_P.DigitalRead1_SampleTime) {
    Test2_DW.obj_o.SampleTime = Test2_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S4>/Digital Read1' */
  Test2_B.DigitalRead1 = MW_digitalIO_read(Test2_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* Chart: '<S1>/Chart' */
  if (Test2_DW.temporalCounter_i1 < MAX_uint32_T) {
    Test2_DW.temporalCounter_i1++;
  }

  if (Test2_DW.is_active_c3_Test2 == 0U) {
    Test2_DW.is_active_c3_Test2 = 1U;
    Test2_DW.is_c3_Test2 = Test2_IN_Start;
  } else {
    switch (Test2_DW.is_c3_Test2) {
     case Test2_IN_AAI:
      Test2_AAI();
      break;

     case Test2_IN_AOO:
      if (Test2_B.BD != 1.0) {
        Test2_DW.is_AOO = Test2_IN_NO_ACTIVE_CHILD;
        Test2_DW.is_c3_Test2 = Test2_IN_Start;
      } else if (Test2_DW.is_AOO == Test2_IN_CHARGING_DISCHARGING) {
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.ATR_GND_CTRL = true;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.PACE_CHARGE_CTRL = true;
        if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 / Test2_B.LRL
             - Test2_B.ATR_PW)) {
          Test2_DW.is_AOO = Test2_IN_PACE_ATR;
          Test2_DW.temporalCounter_i1 = 0U;
          Test2_B.PACE_CHARGE_CTRL = false;
          Test2_B.ATR_PACE_CTRL = true;
          Test2_B.ATR_GND_CTRL = false;
        }
      } else {
        /* case IN_PACE_ATR: */
        Test2_B.PACE_CHARGE_CTRL = false;
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.ATR_PACE_CTRL = true;
        Test2_B.ATR_GND_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.VENT_PACE_CTRL = false;
        if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(Test2_B.ATR_PW)) {
          Test2_DW.is_AOO = Test2_IN_CHARGING_DISCHARGING;
          Test2_DW.temporalCounter_i1 = 0U;
          Test2_B.ATR_PACE_CTRL = false;
          Test2_B.ATR_GND_CTRL = true;
          Test2_B.PACING_REF_PWM = 100.0 * Test2_B.ATR_AMPL / 5.0;
          Test2_B.PACE_CHARGE_CTRL = true;
        }
      }
      break;

     case Test2_IN_Start:
      if (Test2_B.BD == 1.0) {
        Test2_DW.is_c3_Test2 = Test2_IN_AOO;
        Test2_DW.is_AOO = Test2_IN_CHARGING_DISCHARGING;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.ATR_GND_CTRL = true;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.PACING_REF_PWM = 100.0 * Test2_B.ATR_AMPL / 5.0;
        Test2_B.PACE_CHARGE_CTRL = true;
      } else if (Test2_B.BD == 2.0) {
        Test2_DW.is_c3_Test2 = Test2_IN_VOO;
        Test2_DW.is_VOO = Test2_IN_CHARGING_DISCHARGING;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.ATR_GND_CTRL = true;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.PACING_REF_PWM = 100.0 * Test2_B.VENT_AMPL / 5.0;
        Test2_B.PACE_CHARGE_CTRL = true;
      } else if (Test2_B.BD == 3.0) {
        Test2_DW.is_c3_Test2 = Test2_IN_AAI;
        Test2_DW.delta = 0.0;
        Test2_DW.sensing = 0.0;
        Test2_DW.is_AAI = Test2_IN_CHARGING;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.FRONTEND_CTRL = true;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.PACING_REF_PWM = 90.0;
        Test2_B.PACE_CHARGE_CTRL = true;
        Test2_B.ATR_CMP_REF_PWM = 75.0;
      } else if (Test2_B.BD == 4.0) {
        Test2_DW.is_c3_Test2 = Test2_IN_VVI;
        Test2_DW.delta = 0.0;
        Test2_DW.sensing = 0.0;
        Test2_DW.is_VVI = Test2_IN_CHARGING_e;
        Test2_DW.temporalCounter_i1 = 0U;
        Test2_B.FRONTEND_CTRL = true;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.PACING_REF_PWM = 90.0;
        Test2_B.PACE_CHARGE_CTRL = true;
        Test2_B.VENT_CMP_REF_PWM = 75.0;
      }
      break;

     case Test2_IN_VOO:
      if (Test2_B.BD != 2.0) {
        Test2_DW.is_VOO = Test2_IN_NO_ACTIVE_CHILD;
        Test2_DW.is_c3_Test2 = Test2_IN_Start;
      } else if (Test2_DW.is_VOO == Test2_IN_CHARGING_DISCHARGING) {
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.VENT_PACE_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.ATR_GND_CTRL = true;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.PACE_CHARGE_CTRL = true;
        if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 / Test2_B.LRL
             - Test2_B.VENT_PW)) {
          Test2_DW.is_VOO = Test2_IN_PACE_ATR;
          Test2_DW.temporalCounter_i1 = 0U;
          Test2_B.PACE_CHARGE_CTRL = false;
          Test2_B.ATR_GND_CTRL = false;
          Test2_B.VENT_PACE_CTRL = true;
        }
      } else {
        /* case IN_PACE_ATR: */
        Test2_B.PACE_CHARGE_CTRL = false;
        Test2_B.PACE_GND_CTRL = true;
        Test2_B.ATR_PACE_CTRL = false;
        Test2_B.ATR_GND_CTRL = false;
        Test2_B.Z_ATR_CTRL = false;
        Test2_B.Z_VENT_CTRL = false;
        Test2_B.VENT_GND_CTRL = false;
        Test2_B.VENT_PACE_CTRL = true;
        if (Test2_DW.temporalCounter_i1 >= (uint32_T)ceil(Test2_B.VENT_PW)) {
          Test2_DW.is_VOO = Test2_IN_CHARGING_DISCHARGING;
          Test2_DW.temporalCounter_i1 = 0U;
          Test2_B.VENT_PACE_CTRL = false;
          Test2_B.ATR_GND_CTRL = true;
          Test2_B.PACING_REF_PWM = 100.0 * Test2_B.VENT_AMPL / 5.0;
          Test2_B.PACE_CHARGE_CTRL = true;
        }
      }
      break;

     default:
      /* case IN_VVI: */
      Test2_VVI();
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(Test2_DW.obj_pu.MW_DIGITALIO_HANDLE,
                     Test2_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(Test2_DW.obj_a.MW_DIGITALIO_HANDLE, Test2_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S4>/Digital Write2' */
  MW_digitalIO_write(Test2_DW.obj_d.MW_DIGITALIO_HANDLE, Test2_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(Test2_DW.obj_p.MW_DIGITALIO_HANDLE, Test2_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write4' */
  MW_digitalIO_write(Test2_DW.obj_ki.MW_DIGITALIO_HANDLE, Test2_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(Test2_DW.obj_e.MW_DIGITALIO_HANDLE, Test2_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(Test2_DW.obj_k.MW_DIGITALIO_HANDLE, Test2_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(Test2_DW.obj_m.MW_DIGITALIO_HANDLE, Test2_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(Test2_DW.obj_mt.MW_PWM_HANDLE, Test2_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/PWM Output1' */
  MW_PWM_SetDutyCycle(Test2_DW.obj_hy.MW_PWM_HANDLE, Test2_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write10' */
  MW_digitalIO_write(Test2_DW.obj_h.MW_DIGITALIO_HANDLE, Test2_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output2' */
  MW_PWM_SetDutyCycle(Test2_DW.obj_my.MW_PWM_HANDLE, Test2_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Test2_DW.obj.SampleTime != Test2_P.AnalogInput_SampleTime) {
    Test2_DW.obj.SampleTime = Test2_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Test2_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult(Test2_DW.obj.MW_ANALOGIN_HANDLE,
    &Test2_B.AnalogInput, 7);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Test2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Test2_M)!=-1) &&
        !((rtmGetTFinal(Test2_M)-Test2_M->Timing.taskTime0) >
          Test2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Test2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Test2_M)) {
      rtmSetErrorStatus(Test2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Test2_M->Timing.taskTime0 =
    ((time_T)(++Test2_M->Timing.clockTick0)) * Test2_M->Timing.stepSize0;
}

/* Model initialize function */
void Test2_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Test2_M, 1.0);
  Test2_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Test2_M->Sizes.checksums[0] = (588934625U);
  Test2_M->Sizes.checksums[1] = (208975063U);
  Test2_M->Sizes.checksums[2] = (518233739U);
  Test2_M->Sizes.checksums[3] = (97610551U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
    Test2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Test2_M->extModeInfo,
      &Test2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test2_M->extModeInfo, Test2_M->Sizes.checksums);
    rteiSetTPtr(Test2_M->extModeInfo, rtmGetTPtr(Test2_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Test2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    freedomk64f_AnalogInput_Test2_T *obj_2;
    freedomk64f_DigitalRead_Test2_T *obj;
    freedomk64f_DigitalWrite_Test_T *obj_0;
    freedomk64f_PWMOutput_Test2_T *obj_1;

    /* Start for Constant: '<Root>/ARP' */
    Test2_B.ARP = Test2_P.ARP_Value;

    /* Start for Constant: '<Root>/ATR_AMPL' */
    Test2_B.ATR_AMPL = Test2_P.ATR_AMPL_Value;

    /* Start for Constant: '<Root>/ATR_PW' */
    Test2_B.ATR_PW = Test2_P.ATR_PW_Value;

    /* Start for Constant: '<Root>/BD' */
    Test2_B.BD = Test2_P.BD_Value;

    /* Start for Constant: '<Root>/VENT_AMPL' */
    Test2_B.VENT_AMPL = Test2_P.VENT_AMPL_Value;

    /* Start for Constant: '<Root>/LRL' */
    Test2_B.LRL = Test2_P.LRL_Value;

    /* Start for Constant: '<Root>/VRP' */
    Test2_B.VRP = Test2_P.VRP_Value;

    /* Start for Constant: '<Root>/VENT_PW' */
    Test2_B.VENT_PW = Test2_P.VENT_PW_Value;

    /* Start for MATLABSystem: '<S4>/Digital Read' */
    Test2_DW.obj_g.matlabCodegenIsDeleted = true;
    Test2_DW.obj_g.isInitialized = 0;
    Test2_DW.obj_g.SampleTime = -1.0;
    Test2_DW.obj_g.matlabCodegenIsDeleted = false;
    Test2_DW.obj_g.SampleTime = Test2_P.DigitalRead_SampleTime;
    obj = &Test2_DW.obj_g;
    Test2_DW.obj_g.isSetupComplete = false;
    Test2_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Test2_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Read1' */
    Test2_DW.obj_o.matlabCodegenIsDeleted = true;
    Test2_DW.obj_o.isInitialized = 0;
    Test2_DW.obj_o.SampleTime = -1.0;
    Test2_DW.obj_o.matlabCodegenIsDeleted = false;
    Test2_DW.obj_o.SampleTime = Test2_P.DigitalRead1_SampleTime;
    obj = &Test2_DW.obj_o;
    Test2_DW.obj_o.isSetupComplete = false;
    Test2_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Test2_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Test2_DW.obj_pu.matlabCodegenIsDeleted = true;
    Test2_DW.obj_pu.isInitialized = 0;
    Test2_DW.obj_pu.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_pu;
    Test2_DW.obj_pu.isSetupComplete = false;
    Test2_DW.obj_pu.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Test2_DW.obj_pu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Test2_DW.obj_a.matlabCodegenIsDeleted = true;
    Test2_DW.obj_a.isInitialized = 0;
    Test2_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_a;
    Test2_DW.obj_a.isSetupComplete = false;
    Test2_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Test2_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write2' */
    Test2_DW.obj_d.matlabCodegenIsDeleted = true;
    Test2_DW.obj_d.isInitialized = 0;
    Test2_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_d;
    Test2_DW.obj_d.isSetupComplete = false;
    Test2_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Test2_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    Test2_DW.obj_p.matlabCodegenIsDeleted = true;
    Test2_DW.obj_p.isInitialized = 0;
    Test2_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_p;
    Test2_DW.obj_p.isSetupComplete = false;
    Test2_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Test2_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write4' */
    Test2_DW.obj_ki.matlabCodegenIsDeleted = true;
    Test2_DW.obj_ki.isInitialized = 0;
    Test2_DW.obj_ki.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_ki;
    Test2_DW.obj_ki.isSetupComplete = false;
    Test2_DW.obj_ki.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Test2_DW.obj_ki.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    Test2_DW.obj_e.matlabCodegenIsDeleted = true;
    Test2_DW.obj_e.isInitialized = 0;
    Test2_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_e;
    Test2_DW.obj_e.isSetupComplete = false;
    Test2_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Test2_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    Test2_DW.obj_k.matlabCodegenIsDeleted = true;
    Test2_DW.obj_k.isInitialized = 0;
    Test2_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_k;
    Test2_DW.obj_k.isSetupComplete = false;
    Test2_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Test2_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    Test2_DW.obj_m.matlabCodegenIsDeleted = true;
    Test2_DW.obj_m.isInitialized = 0;
    Test2_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_m;
    Test2_DW.obj_m.isSetupComplete = false;
    Test2_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Test2_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Test2_DW.obj_mt.matlabCodegenIsDeleted = true;
    Test2_DW.obj_mt.isInitialized = 0;
    Test2_DW.obj_mt.matlabCodegenIsDeleted = false;
    obj_1 = &Test2_DW.obj_mt;
    Test2_DW.obj_mt.isSetupComplete = false;
    Test2_DW.obj_mt.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Test2_DW.obj_mt.MW_PWM_HANDLE);
    Test2_DW.obj_mt.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    Test2_DW.obj_hy.matlabCodegenIsDeleted = true;
    Test2_DW.obj_hy.isInitialized = 0;
    Test2_DW.obj_hy.matlabCodegenIsDeleted = false;
    obj_1 = &Test2_DW.obj_hy;
    Test2_DW.obj_hy.isSetupComplete = false;
    Test2_DW.obj_hy.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Test2_DW.obj_hy.MW_PWM_HANDLE);
    Test2_DW.obj_hy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write10' */
    Test2_DW.obj_h.matlabCodegenIsDeleted = true;
    Test2_DW.obj_h.isInitialized = 0;
    Test2_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Test2_DW.obj_h;
    Test2_DW.obj_h.isSetupComplete = false;
    Test2_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Test2_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    Test2_DW.obj_my.matlabCodegenIsDeleted = true;
    Test2_DW.obj_my.isInitialized = 0;
    Test2_DW.obj_my.matlabCodegenIsDeleted = false;
    obj_1 = &Test2_DW.obj_my;
    Test2_DW.obj_my.isSetupComplete = false;
    Test2_DW.obj_my.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Test2_DW.obj_my.MW_PWM_HANDLE);
    Test2_DW.obj_my.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Test2_DW.obj.matlabCodegenIsDeleted = true;
    Test2_DW.obj.isInitialized = 0;
    Test2_DW.obj.SampleTime = -1.0;
    Test2_DW.obj.matlabCodegenIsDeleted = false;
    Test2_DW.obj.SampleTime = Test2_P.AnalogInput_SampleTime;
    obj_2 = &Test2_DW.obj;
    Test2_DW.obj.isSetupComplete = false;
    Test2_DW.obj.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Test2_DW.obj.MW_ANALOGIN_HANDLE, trigger_val,
      0U);
    Test2_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void Test2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Digital Read' */
  if (!Test2_DW.obj_g.matlabCodegenIsDeleted) {
    Test2_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_g.isInitialized == 1) && Test2_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Read' */

  /* Terminate for MATLABSystem: '<S4>/Digital Read1' */
  if (!Test2_DW.obj_o.matlabCodegenIsDeleted) {
    Test2_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_o.isInitialized == 1) && Test2_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Test2_DW.obj_pu.matlabCodegenIsDeleted) {
    Test2_DW.obj_pu.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_pu.isInitialized == 1) && Test2_DW.obj_pu.isSetupComplete)
    {
      MW_digitalIO_close(Test2_DW.obj_pu.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!Test2_DW.obj_a.matlabCodegenIsDeleted) {
    Test2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_a.isInitialized == 1) && Test2_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write2' */
  if (!Test2_DW.obj_d.matlabCodegenIsDeleted) {
    Test2_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_d.isInitialized == 1) && Test2_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  if (!Test2_DW.obj_p.matlabCodegenIsDeleted) {
    Test2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_p.isInitialized == 1) && Test2_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write4' */
  if (!Test2_DW.obj_ki.matlabCodegenIsDeleted) {
    Test2_DW.obj_ki.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_ki.isInitialized == 1) && Test2_DW.obj_ki.isSetupComplete)
    {
      MW_digitalIO_close(Test2_DW.obj_ki.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  if (!Test2_DW.obj_e.matlabCodegenIsDeleted) {
    Test2_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_e.isInitialized == 1) && Test2_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  if (!Test2_DW.obj_k.matlabCodegenIsDeleted) {
    Test2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_k.isInitialized == 1) && Test2_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  if (!Test2_DW.obj_m.matlabCodegenIsDeleted) {
    Test2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_m.isInitialized == 1) && Test2_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!Test2_DW.obj_mt.matlabCodegenIsDeleted) {
    Test2_DW.obj_mt.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_mt.isInitialized == 1) && Test2_DW.obj_mt.isSetupComplete)
    {
      MW_PWM_Stop(Test2_DW.obj_mt.MW_PWM_HANDLE);
      MW_PWM_Close(Test2_DW.obj_mt.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  if (!Test2_DW.obj_hy.matlabCodegenIsDeleted) {
    Test2_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_hy.isInitialized == 1) && Test2_DW.obj_hy.isSetupComplete)
    {
      MW_PWM_Stop(Test2_DW.obj_hy.MW_PWM_HANDLE);
      MW_PWM_Close(Test2_DW.obj_hy.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write10' */
  if (!Test2_DW.obj_h.matlabCodegenIsDeleted) {
    Test2_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_h.isInitialized == 1) && Test2_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Test2_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  if (!Test2_DW.obj_my.matlabCodegenIsDeleted) {
    Test2_DW.obj_my.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj_my.isInitialized == 1) && Test2_DW.obj_my.isSetupComplete)
    {
      MW_PWM_Stop(Test2_DW.obj_my.MW_PWM_HANDLE);
      MW_PWM_Close(Test2_DW.obj_my.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output2' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!Test2_DW.obj.matlabCodegenIsDeleted) {
    Test2_DW.obj.matlabCodegenIsDeleted = true;
    if ((Test2_DW.obj.isInitialized == 1) && Test2_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(Test2_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Test2_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
