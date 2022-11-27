/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_1.c
 *
 * Code generated for Simulink model 'Assignment_1'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Nov 27 14:36:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment_1.h"
#include "rtwtypes.h"
#include <math.h>
#include "Assignment_1_types.h"
#include "Assignment_1_private.h"
#include "Assignment_1_dt.h"

/* Named constants for Chart: '<S1>/Chart' */
#define Assignm_IN_CHARGING_DISCHARGING (1U)
#define Assignment_1_IN_AAI            (1U)
#define Assignment_1_IN_AOO            (2U)
#define Assignment_1_IN_CHARGING       (2U)
#define Assignment_1_IN_CHARGING_e     (1U)
#define Assignment_1_IN_DISCHARGING    (3U)
#define Assignment_1_IN_DISCHARGING_i  (2U)
#define Assignment_1_IN_PACE_ATR       (2U)
#define Assignment_1_IN_PACE_ATR_i     (4U)
#define Assignment_1_IN_PACE_ATR_if    (3U)
#define Assignment_1_IN_Start          (3U)
#define Assignment_1_IN_VOO            (4U)
#define Assignment_1_IN_VVI            (5U)
#define IN_Atrial_Refractory_Period_Pos (1U)
#define IN_Ventricular_Refractory_Perio (4U)

/* Block signals (default storage) */
B_Assignment_1_T Assignment_1_B;

/* Block states (default storage) */
DW_Assignment_1_T Assignment_1_DW;

/* Real-time model */
static RT_MODEL_Assignment_1_T Assignment_1_M_;
RT_MODEL_Assignment_1_T *const Assignment_1_M = &Assignment_1_M_;

/* Forward declaration for local functions */
static void Assignment_1_VVI(void);
static void Assignment_1_AAI(void);

/* Function for Chart: '<S1>/Chart' */
static void Assignment_1_VVI(void)
{
  boolean_T guard1 = false;
  guard1 = false;
  switch (Assignment_1_DW.is_VVI) {
   case Assignment_1_IN_CHARGING_e:
    Assignment_1_B.FRONTEND_CTRL = true;
    Assignment_1_B.ATR_PACE_CTRL = false;
    Assignment_1_B.VENT_PACE_CTRL = false;
    Assignment_1_B.PACE_CHARGE_CTRL = true;
    Assignment_1_B.VENT_CMP_REF_PWM = 75.0;
    if (Assignment_1_B.DigitalRead1) {
      Assignment_1_DW.is_VVI = IN_Ventricular_Refractory_Perio;
      Assignment_1_DW.temporalCounter_i1 = 0U;
    } else if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
                 Assignment_1_B.LRL - Assignment_1_DW.delta) -
                Assignment_1_B.VENT_PW)) {
      Assignment_1_DW.is_VVI = Assignment_1_IN_PACE_ATR_if;
      Assignment_1_DW.temporalCounter_i1 = 0U;
      Assignment_1_B.PACE_CHARGE_CTRL = false;
      Assignment_1_B.PACE_GND_CTRL = true;
      Assignment_1_B.ATR_GND_CTRL = false;
      Assignment_1_B.Z_ATR_CTRL = false;
      Assignment_1_B.Z_VENT_CTRL = false;
      Assignment_1_B.VENT_GND_CTRL = false;
      Assignment_1_B.VENT_PACE_CTRL = true;
    }
    break;

   case Assignment_1_IN_DISCHARGING_i:
    Assignment_1_B.PACE_GND_CTRL = true;
    Assignment_1_B.VENT_PACE_CTRL = false;
    Assignment_1_B.Z_ATR_CTRL = false;
    Assignment_1_B.Z_VENT_CTRL = false;
    Assignment_1_B.ATR_PACE_CTRL = false;
    Assignment_1_B.ATR_GND_CTRL = false;
    Assignment_1_B.VENT_GND_CTRL = true;
    if ((Assignment_1_DW.sensing == 0.0) && (Assignment_1_DW.temporalCounter_i1 >=
         (uint32_T)ceil(Assignment_1_B.VRP))) {
      Assignment_1_DW.delta = Assignment_1_B.VRP;
      guard1 = true;
    } else if ((Assignment_1_DW.sensing == 1.0) &&
               (Assignment_1_DW.temporalCounter_i1 >= 1U)) {
      Assignment_1_DW.delta = 0.0;
      Assignment_1_DW.sensing = 0.0;
      guard1 = true;
    }
    break;

   case Assignment_1_IN_PACE_ATR_if:
    Assignment_1_B.PACE_CHARGE_CTRL = false;
    Assignment_1_B.PACE_GND_CTRL = true;
    Assignment_1_B.ATR_PACE_CTRL = false;
    Assignment_1_B.ATR_GND_CTRL = false;
    Assignment_1_B.Z_ATR_CTRL = false;
    Assignment_1_B.Z_VENT_CTRL = false;
    Assignment_1_B.VENT_GND_CTRL = false;
    Assignment_1_B.VENT_PACE_CTRL = true;
    if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
        (Assignment_1_B.VENT_PW)) {
      Assignment_1_DW.is_VVI = Assignment_1_IN_DISCHARGING_i;
      Assignment_1_DW.temporalCounter_i1 = 0U;
      Assignment_1_B.VENT_PACE_CTRL = false;
      Assignment_1_B.VENT_GND_CTRL = true;
    }
    break;

   default:
    /* case IN_Ventricular_Refractory_Period_Post_Sensing: */
    if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil(Assignment_1_B.VRP
         + 35.0)) {
      Assignment_1_DW.delta = Assignment_1_B.VRP;
      Assignment_1_DW.sensing = 1.0;
      Assignment_1_DW.is_VVI = Assignment_1_IN_CHARGING_e;
      Assignment_1_DW.temporalCounter_i1 = 0U;
      Assignment_1_B.FRONTEND_CTRL = true;
      Assignment_1_B.ATR_PACE_CTRL = false;
      Assignment_1_B.VENT_PACE_CTRL = false;
      Assignment_1_B.PACING_REF_PWM = 90.0;
      Assignment_1_B.PACE_CHARGE_CTRL = true;
      Assignment_1_B.VENT_CMP_REF_PWM = 75.0;
    }
    break;
  }

  if (guard1) {
    Assignment_1_DW.is_VVI = Assignment_1_IN_CHARGING_e;
    Assignment_1_DW.temporalCounter_i1 = 0U;
    Assignment_1_B.FRONTEND_CTRL = true;
    Assignment_1_B.PACING_REF_PWM = 90.0;
    Assignment_1_B.PACE_CHARGE_CTRL = true;
    Assignment_1_B.VENT_CMP_REF_PWM = 75.0;
  }
}

/* Function for Chart: '<S1>/Chart' */
static void Assignment_1_AAI(void)
{
  boolean_T guard1 = false;
  guard1 = false;
  switch (Assignment_1_DW.is_AAI) {
   case IN_Atrial_Refractory_Period_Pos:
    if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil(Assignment_1_B.ARP
         + 35.0)) {
      Assignment_1_DW.delta = Assignment_1_B.ARP;
      Assignment_1_DW.sensing = 1.0;
      Assignment_1_DW.is_AAI = Assignment_1_IN_CHARGING;
      Assignment_1_DW.temporalCounter_i1 = 0U;
      Assignment_1_B.FRONTEND_CTRL = true;
      Assignment_1_B.VENT_PACE_CTRL = false;
      Assignment_1_B.ATR_PACE_CTRL = false;
      Assignment_1_B.PACING_REF_PWM = 90.0;
      Assignment_1_B.PACE_CHARGE_CTRL = true;
      Assignment_1_B.ATR_CMP_REF_PWM = 75.0;
    }
    break;

   case Assignment_1_IN_CHARGING:
    Assignment_1_B.FRONTEND_CTRL = true;
    Assignment_1_B.VENT_PACE_CTRL = false;
    Assignment_1_B.ATR_PACE_CTRL = false;
    Assignment_1_B.PACE_CHARGE_CTRL = true;
    Assignment_1_B.ATR_CMP_REF_PWM = 75.0;
    if (Assignment_1_B.DigitalRead) {
      Assignment_1_DW.is_AAI = IN_Atrial_Refractory_Period_Pos;
      Assignment_1_DW.temporalCounter_i1 = 0U;
    } else if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
                 Assignment_1_B.LRL - Assignment_1_DW.delta) -
                Assignment_1_B.ATR_PW)) {
      Assignment_1_DW.is_AAI = Assignment_1_IN_PACE_ATR_i;
      Assignment_1_DW.temporalCounter_i1 = 0U;
      Assignment_1_B.PACE_CHARGE_CTRL = false;
      Assignment_1_B.PACE_GND_CTRL = true;
      Assignment_1_B.VENT_GND_CTRL = false;
      Assignment_1_B.Z_VENT_CTRL = false;
      Assignment_1_B.Z_ATR_CTRL = false;
      Assignment_1_B.ATR_GND_CTRL = false;
      Assignment_1_B.ATR_PACE_CTRL = true;
    }
    break;

   case Assignment_1_IN_DISCHARGING:
    Assignment_1_B.PACE_GND_CTRL = true;
    Assignment_1_B.ATR_PACE_CTRL = false;
    Assignment_1_B.Z_VENT_CTRL = false;
    Assignment_1_B.Z_ATR_CTRL = false;
    Assignment_1_B.VENT_PACE_CTRL = false;
    Assignment_1_B.VENT_GND_CTRL = false;
    Assignment_1_B.ATR_GND_CTRL = true;
    if ((Assignment_1_DW.sensing == 0.0) && (Assignment_1_DW.temporalCounter_i1 >=
         (uint32_T)ceil(Assignment_1_B.ARP))) {
      Assignment_1_DW.delta = Assignment_1_B.ARP;
      guard1 = true;
    } else if ((Assignment_1_DW.sensing == 1.0) &&
               (Assignment_1_DW.temporalCounter_i1 >= 1U)) {
      Assignment_1_DW.delta = 0.0;
      Assignment_1_DW.sensing = 0.0;
      guard1 = true;
    }
    break;

   default:
    /* case IN_PACE_ATR: */
    Assignment_1_B.PACE_CHARGE_CTRL = false;
    Assignment_1_B.PACE_GND_CTRL = true;
    Assignment_1_B.VENT_PACE_CTRL = false;
    Assignment_1_B.VENT_GND_CTRL = false;
    Assignment_1_B.Z_VENT_CTRL = false;
    Assignment_1_B.Z_ATR_CTRL = false;
    Assignment_1_B.ATR_GND_CTRL = false;
    Assignment_1_B.ATR_PACE_CTRL = true;
    if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
        (Assignment_1_B.ATR_PW)) {
      Assignment_1_DW.is_AAI = Assignment_1_IN_DISCHARGING;
      Assignment_1_DW.temporalCounter_i1 = 0U;
      Assignment_1_B.ATR_PACE_CTRL = false;
      Assignment_1_B.ATR_GND_CTRL = true;
    }
    break;
  }

  if (guard1) {
    Assignment_1_DW.is_AAI = Assignment_1_IN_CHARGING;
    Assignment_1_DW.temporalCounter_i1 = 0U;
    Assignment_1_B.FRONTEND_CTRL = true;
    Assignment_1_B.PACING_REF_PWM = 90.0;
    Assignment_1_B.PACE_CHARGE_CTRL = true;
    Assignment_1_B.ATR_CMP_REF_PWM = 75.0;
  }
}

/* Model step function */
void Assignment_1_step(void)
{
  /* Constant: '<Root>/ARP' */
  Assignment_1_B.ARP = Assignment_1_P.ARP_Value;

  /* Constant: '<Root>/ATR_AMPL' */
  Assignment_1_B.ATR_AMPL = Assignment_1_P.ATR_AMPL_Value;

  /* Constant: '<Root>/ATR_PW' */
  Assignment_1_B.ATR_PW = Assignment_1_P.ATR_PW_Value;

  /* Constant: '<Root>/BD' */
  Assignment_1_B.BD = Assignment_1_P.BD_Value;

  /* Constant: '<Root>/VENT_AMPL' */
  Assignment_1_B.VENT_AMPL = Assignment_1_P.VENT_AMPL_Value;

  /* Constant: '<Root>/LRL' */
  Assignment_1_B.LRL = Assignment_1_P.LRL_Value;

  /* Constant: '<Root>/VRP' */
  Assignment_1_B.VRP = Assignment_1_P.VRP_Value;

  /* Constant: '<Root>/VENT_PW' */
  Assignment_1_B.VENT_PW = Assignment_1_P.VENT_PW_Value;

  /* MATLABSystem: '<S4>/Digital Read' */
  if (Assignment_1_DW.obj_g.SampleTime != Assignment_1_P.DigitalRead_SampleTime)
  {
    Assignment_1_DW.obj_g.SampleTime = Assignment_1_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<S4>/Digital Read' */
  Assignment_1_B.DigitalRead = MW_digitalIO_read
    (Assignment_1_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S4>/Digital Read1' */
  if (Assignment_1_DW.obj_o.SampleTime != Assignment_1_P.DigitalRead1_SampleTime)
  {
    Assignment_1_DW.obj_o.SampleTime = Assignment_1_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S4>/Digital Read1' */
  Assignment_1_B.DigitalRead1 = MW_digitalIO_read
    (Assignment_1_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* Chart: '<S1>/Chart' */
  if (Assignment_1_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment_1_DW.temporalCounter_i1++;
  }

  if (Assignment_1_DW.is_active_c3_Assignment_1 == 0U) {
    Assignment_1_DW.is_active_c3_Assignment_1 = 1U;
    Assignment_1_DW.is_c3_Assignment_1 = Assignment_1_IN_Start;
  } else {
    switch (Assignment_1_DW.is_c3_Assignment_1) {
     case Assignment_1_IN_AAI:
      Assignment_1_AAI();
      break;

     case Assignment_1_IN_AOO:
      if (Assignment_1_DW.is_AOO == Assignm_IN_CHARGING_DISCHARGING) {
        Assignment_1_B.PACE_GND_CTRL = true;
        Assignment_1_B.VENT_PACE_CTRL = false;
        Assignment_1_B.Z_ATR_CTRL = false;
        Assignment_1_B.Z_VENT_CTRL = false;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.ATR_GND_CTRL = true;
        Assignment_1_B.VENT_GND_CTRL = false;
        Assignment_1_B.PACE_CHARGE_CTRL = true;
        if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
             Assignment_1_B.LRL - Assignment_1_B.ATR_PW)) {
          Assignment_1_DW.is_AOO = Assignment_1_IN_PACE_ATR;
          Assignment_1_DW.temporalCounter_i1 = 0U;
          Assignment_1_B.PACE_CHARGE_CTRL = false;
          Assignment_1_B.ATR_PACE_CTRL = true;
          Assignment_1_B.ATR_GND_CTRL = false;
        }
      } else {
        /* case IN_PACE_ATR: */
        Assignment_1_B.PACE_CHARGE_CTRL = false;
        Assignment_1_B.PACE_GND_CTRL = true;
        Assignment_1_B.ATR_PACE_CTRL = true;
        Assignment_1_B.ATR_GND_CTRL = false;
        Assignment_1_B.Z_ATR_CTRL = false;
        Assignment_1_B.Z_VENT_CTRL = false;
        Assignment_1_B.VENT_GND_CTRL = false;
        Assignment_1_B.VENT_PACE_CTRL = false;
        if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (Assignment_1_B.ATR_PW)) {
          Assignment_1_DW.is_AOO = Assignm_IN_CHARGING_DISCHARGING;
          Assignment_1_DW.temporalCounter_i1 = 0U;
          Assignment_1_B.ATR_PACE_CTRL = false;
          Assignment_1_B.ATR_GND_CTRL = true;
          Assignment_1_B.PACING_REF_PWM = 100.0 * Assignment_1_B.ATR_AMPL / 5.0;
          Assignment_1_B.PACE_CHARGE_CTRL = true;
        }
      }
      break;

     case Assignment_1_IN_Start:
      if (Assignment_1_B.BD == 1.0) {
        Assignment_1_DW.is_c3_Assignment_1 = Assignment_1_IN_AOO;
        Assignment_1_DW.is_AOO = Assignm_IN_CHARGING_DISCHARGING;
        Assignment_1_DW.temporalCounter_i1 = 0U;
        Assignment_1_B.PACE_GND_CTRL = true;
        Assignment_1_B.VENT_PACE_CTRL = false;
        Assignment_1_B.Z_ATR_CTRL = false;
        Assignment_1_B.Z_VENT_CTRL = false;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.ATR_GND_CTRL = true;
        Assignment_1_B.VENT_GND_CTRL = false;
        Assignment_1_B.PACING_REF_PWM = 100.0 * Assignment_1_B.ATR_AMPL / 5.0;
        Assignment_1_B.PACE_CHARGE_CTRL = true;
      } else if (Assignment_1_B.BD == 2.0) {
        Assignment_1_DW.is_c3_Assignment_1 = Assignment_1_IN_VOO;
        Assignment_1_DW.is_VOO = Assignm_IN_CHARGING_DISCHARGING;
        Assignment_1_DW.temporalCounter_i1 = 0U;
        Assignment_1_B.PACE_GND_CTRL = true;
        Assignment_1_B.VENT_PACE_CTRL = false;
        Assignment_1_B.Z_ATR_CTRL = false;
        Assignment_1_B.Z_VENT_CTRL = false;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.ATR_GND_CTRL = true;
        Assignment_1_B.VENT_GND_CTRL = false;
        Assignment_1_B.PACING_REF_PWM = 100.0 * Assignment_1_B.VENT_AMPL / 5.0;
        Assignment_1_B.PACE_CHARGE_CTRL = true;
      } else if (Assignment_1_B.BD == 3.0) {
        Assignment_1_DW.is_c3_Assignment_1 = Assignment_1_IN_AAI;
        Assignment_1_DW.delta = 0.0;
        Assignment_1_DW.sensing = 0.0;
        Assignment_1_DW.is_AAI = Assignment_1_IN_CHARGING;
        Assignment_1_DW.temporalCounter_i1 = 0U;
        Assignment_1_B.FRONTEND_CTRL = true;
        Assignment_1_B.VENT_PACE_CTRL = false;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.PACING_REF_PWM = 90.0;
        Assignment_1_B.PACE_CHARGE_CTRL = true;
        Assignment_1_B.ATR_CMP_REF_PWM = 75.0;
      } else if (Assignment_1_B.BD == 4.0) {
        Assignment_1_DW.is_c3_Assignment_1 = Assignment_1_IN_VVI;
        Assignment_1_DW.delta = 0.0;
        Assignment_1_DW.sensing = 0.0;
        Assignment_1_DW.is_VVI = Assignment_1_IN_CHARGING_e;
        Assignment_1_DW.temporalCounter_i1 = 0U;
        Assignment_1_B.FRONTEND_CTRL = true;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.VENT_PACE_CTRL = false;
        Assignment_1_B.PACING_REF_PWM = 90.0;
        Assignment_1_B.PACE_CHARGE_CTRL = true;
        Assignment_1_B.VENT_CMP_REF_PWM = 75.0;
      }
      break;

     case Assignment_1_IN_VOO:
      if (Assignment_1_DW.is_VOO == Assignm_IN_CHARGING_DISCHARGING) {
        Assignment_1_B.PACE_GND_CTRL = true;
        Assignment_1_B.VENT_PACE_CTRL = false;
        Assignment_1_B.Z_ATR_CTRL = false;
        Assignment_1_B.Z_VENT_CTRL = false;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.ATR_GND_CTRL = true;
        Assignment_1_B.VENT_GND_CTRL = false;
        Assignment_1_B.PACE_CHARGE_CTRL = true;
        if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
             Assignment_1_B.LRL - Assignment_1_B.VENT_PW)) {
          Assignment_1_DW.is_VOO = Assignment_1_IN_PACE_ATR;
          Assignment_1_DW.temporalCounter_i1 = 0U;
          Assignment_1_B.PACE_CHARGE_CTRL = false;
          Assignment_1_B.ATR_GND_CTRL = false;
          Assignment_1_B.VENT_PACE_CTRL = true;
        }
      } else {
        /* case IN_PACE_ATR: */
        Assignment_1_B.PACE_CHARGE_CTRL = false;
        Assignment_1_B.PACE_GND_CTRL = true;
        Assignment_1_B.ATR_PACE_CTRL = false;
        Assignment_1_B.ATR_GND_CTRL = false;
        Assignment_1_B.Z_ATR_CTRL = false;
        Assignment_1_B.Z_VENT_CTRL = false;
        Assignment_1_B.VENT_GND_CTRL = false;
        Assignment_1_B.VENT_PACE_CTRL = true;
        if (Assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (Assignment_1_B.VENT_PW)) {
          Assignment_1_DW.is_VOO = Assignm_IN_CHARGING_DISCHARGING;
          Assignment_1_DW.temporalCounter_i1 = 0U;
          Assignment_1_B.VENT_PACE_CTRL = false;
          Assignment_1_B.ATR_GND_CTRL = true;
          Assignment_1_B.PACING_REF_PWM = 100.0 * Assignment_1_B.VENT_AMPL / 5.0;
          Assignment_1_B.PACE_CHARGE_CTRL = true;
        }
      }
      break;

     default:
      /* case IN_VVI: */
      Assignment_1_VVI();
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(Assignment_1_DW.obj_pu.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(Assignment_1_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S4>/Digital Write2' */
  MW_digitalIO_write(Assignment_1_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(Assignment_1_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write4' */
  MW_digitalIO_write(Assignment_1_DW.obj_ki.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(Assignment_1_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(Assignment_1_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(Assignment_1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment_1_DW.obj_mt.MW_PWM_HANDLE,
                      Assignment_1_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/PWM Output1' */
  MW_PWM_SetDutyCycle(Assignment_1_DW.obj_hy.MW_PWM_HANDLE,
                      Assignment_1_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write10' */
  MW_digitalIO_write(Assignment_1_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment_1_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output2' */
  MW_PWM_SetDutyCycle(Assignment_1_DW.obj_my.MW_PWM_HANDLE,
                      Assignment_1_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Assignment_1_DW.obj.SampleTime != Assignment_1_P.AnalogInput_SampleTime) {
    Assignment_1_DW.obj.SampleTime = Assignment_1_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment_1_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult(Assignment_1_DW.obj.MW_ANALOGIN_HANDLE,
    &Assignment_1_B.AnalogInput, 7);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Assignment_1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Assignment_1_M)!=-1) &&
        !((rtmGetTFinal(Assignment_1_M)-Assignment_1_M->Timing.taskTime0) >
          Assignment_1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Assignment_1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Assignment_1_M)) {
      rtmSetErrorStatus(Assignment_1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Assignment_1_M->Timing.taskTime0 =
    ((time_T)(++Assignment_1_M->Timing.clockTick0)) *
    Assignment_1_M->Timing.stepSize0;
}

/* Model initialize function */
void Assignment_1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Assignment_1_M, 1.0);
  Assignment_1_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Assignment_1_M->Sizes.checksums[0] = (2437088035U);
  Assignment_1_M->Sizes.checksums[1] = (1173911168U);
  Assignment_1_M->Sizes.checksums[2] = (3243318787U);
  Assignment_1_M->Sizes.checksums[3] = (738862358U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
    Assignment_1_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Assignment_1_M->extModeInfo,
      &Assignment_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Assignment_1_M->extModeInfo,
                        Assignment_1_M->Sizes.checksums);
    rteiSetTPtr(Assignment_1_M->extModeInfo, rtmGetTPtr(Assignment_1_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Assignment_1_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    freedomk64f_AnalogInput_Assig_T *obj_2;
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* Start for Constant: '<Root>/ARP' */
    Assignment_1_B.ARP = Assignment_1_P.ARP_Value;

    /* Start for Constant: '<Root>/ATR_AMPL' */
    Assignment_1_B.ATR_AMPL = Assignment_1_P.ATR_AMPL_Value;

    /* Start for Constant: '<Root>/ATR_PW' */
    Assignment_1_B.ATR_PW = Assignment_1_P.ATR_PW_Value;

    /* Start for Constant: '<Root>/BD' */
    Assignment_1_B.BD = Assignment_1_P.BD_Value;

    /* Start for Constant: '<Root>/VENT_AMPL' */
    Assignment_1_B.VENT_AMPL = Assignment_1_P.VENT_AMPL_Value;

    /* Start for Constant: '<Root>/LRL' */
    Assignment_1_B.LRL = Assignment_1_P.LRL_Value;

    /* Start for Constant: '<Root>/VRP' */
    Assignment_1_B.VRP = Assignment_1_P.VRP_Value;

    /* Start for Constant: '<Root>/VENT_PW' */
    Assignment_1_B.VENT_PW = Assignment_1_P.VENT_PW_Value;

    /* Start for MATLABSystem: '<S4>/Digital Read' */
    Assignment_1_DW.obj_g.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_g.isInitialized = 0;
    Assignment_1_DW.obj_g.SampleTime = -1.0;
    Assignment_1_DW.obj_g.matlabCodegenIsDeleted = false;
    Assignment_1_DW.obj_g.SampleTime = Assignment_1_P.DigitalRead_SampleTime;
    obj = &Assignment_1_DW.obj_g;
    Assignment_1_DW.obj_g.isSetupComplete = false;
    Assignment_1_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment_1_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Read1' */
    Assignment_1_DW.obj_o.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_o.isInitialized = 0;
    Assignment_1_DW.obj_o.SampleTime = -1.0;
    Assignment_1_DW.obj_o.matlabCodegenIsDeleted = false;
    Assignment_1_DW.obj_o.SampleTime = Assignment_1_P.DigitalRead1_SampleTime;
    obj = &Assignment_1_DW.obj_o;
    Assignment_1_DW.obj_o.isSetupComplete = false;
    Assignment_1_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment_1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Assignment_1_DW.obj_pu.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_pu.isInitialized = 0;
    Assignment_1_DW.obj_pu.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_pu;
    Assignment_1_DW.obj_pu.isSetupComplete = false;
    Assignment_1_DW.obj_pu.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment_1_DW.obj_pu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Assignment_1_DW.obj_a.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_a.isInitialized = 0;
    Assignment_1_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_a;
    Assignment_1_DW.obj_a.isSetupComplete = false;
    Assignment_1_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment_1_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write2' */
    Assignment_1_DW.obj_d.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_d.isInitialized = 0;
    Assignment_1_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_d;
    Assignment_1_DW.obj_d.isSetupComplete = false;
    Assignment_1_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment_1_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    Assignment_1_DW.obj_p.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_p.isInitialized = 0;
    Assignment_1_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_p;
    Assignment_1_DW.obj_p.isSetupComplete = false;
    Assignment_1_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment_1_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write4' */
    Assignment_1_DW.obj_ki.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_ki.isInitialized = 0;
    Assignment_1_DW.obj_ki.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_ki;
    Assignment_1_DW.obj_ki.isSetupComplete = false;
    Assignment_1_DW.obj_ki.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment_1_DW.obj_ki.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    Assignment_1_DW.obj_e.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_e.isInitialized = 0;
    Assignment_1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_e;
    Assignment_1_DW.obj_e.isSetupComplete = false;
    Assignment_1_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment_1_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    Assignment_1_DW.obj_k.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_k.isInitialized = 0;
    Assignment_1_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_k;
    Assignment_1_DW.obj_k.isSetupComplete = false;
    Assignment_1_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment_1_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    Assignment_1_DW.obj_m.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_m.isInitialized = 0;
    Assignment_1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_m;
    Assignment_1_DW.obj_m.isSetupComplete = false;
    Assignment_1_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment_1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Assignment_1_DW.obj_mt.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_mt.isInitialized = 0;
    Assignment_1_DW.obj_mt.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_DW.obj_mt;
    Assignment_1_DW.obj_mt.isSetupComplete = false;
    Assignment_1_DW.obj_mt.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_DW.obj_mt.MW_PWM_HANDLE);
    Assignment_1_DW.obj_mt.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    Assignment_1_DW.obj_hy.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_hy.isInitialized = 0;
    Assignment_1_DW.obj_hy.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_DW.obj_hy;
    Assignment_1_DW.obj_hy.isSetupComplete = false;
    Assignment_1_DW.obj_hy.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_DW.obj_hy.MW_PWM_HANDLE);
    Assignment_1_DW.obj_hy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write10' */
    Assignment_1_DW.obj_h.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_h.isInitialized = 0;
    Assignment_1_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_1_DW.obj_h;
    Assignment_1_DW.obj_h.isSetupComplete = false;
    Assignment_1_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment_1_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    Assignment_1_DW.obj_my.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj_my.isInitialized = 0;
    Assignment_1_DW.obj_my.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_1_DW.obj_my;
    Assignment_1_DW.obj_my.isSetupComplete = false;
    Assignment_1_DW.obj_my.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_1_DW.obj_my.MW_PWM_HANDLE);
    Assignment_1_DW.obj_my.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Assignment_1_DW.obj.matlabCodegenIsDeleted = true;
    Assignment_1_DW.obj.isInitialized = 0;
    Assignment_1_DW.obj.SampleTime = -1.0;
    Assignment_1_DW.obj.matlabCodegenIsDeleted = false;
    Assignment_1_DW.obj.SampleTime = Assignment_1_P.AnalogInput_SampleTime;
    obj_2 = &Assignment_1_DW.obj;
    Assignment_1_DW.obj.isSetupComplete = false;
    Assignment_1_DW.obj.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment_1_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment_1_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment_1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Digital Read' */
  if (!Assignment_1_DW.obj_g.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_g.isInitialized == 1) &&
        Assignment_1_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Read' */

  /* Terminate for MATLABSystem: '<S4>/Digital Read1' */
  if (!Assignment_1_DW.obj_o.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_o.isInitialized == 1) &&
        Assignment_1_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Assignment_1_DW.obj_pu.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_pu.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_pu.isInitialized == 1) &&
        Assignment_1_DW.obj_pu.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_pu.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!Assignment_1_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_a.isInitialized == 1) &&
        Assignment_1_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write2' */
  if (!Assignment_1_DW.obj_d.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_d.isInitialized == 1) &&
        Assignment_1_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  if (!Assignment_1_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_p.isInitialized == 1) &&
        Assignment_1_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write4' */
  if (!Assignment_1_DW.obj_ki.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_ki.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_ki.isInitialized == 1) &&
        Assignment_1_DW.obj_ki.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_ki.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  if (!Assignment_1_DW.obj_e.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_e.isInitialized == 1) &&
        Assignment_1_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  if (!Assignment_1_DW.obj_k.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_k.isInitialized == 1) &&
        Assignment_1_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  if (!Assignment_1_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_m.isInitialized == 1) &&
        Assignment_1_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!Assignment_1_DW.obj_mt.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_mt.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_mt.isInitialized == 1) &&
        Assignment_1_DW.obj_mt.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_DW.obj_mt.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_DW.obj_mt.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  if (!Assignment_1_DW.obj_hy.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_hy.isInitialized == 1) &&
        Assignment_1_DW.obj_hy.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_DW.obj_hy.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_DW.obj_hy.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write10' */
  if (!Assignment_1_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_h.isInitialized == 1) &&
        Assignment_1_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Assignment_1_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  if (!Assignment_1_DW.obj_my.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj_my.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj_my.isInitialized == 1) &&
        Assignment_1_DW.obj_my.isSetupComplete) {
      MW_PWM_Stop(Assignment_1_DW.obj_my.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_1_DW.obj_my.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output2' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!Assignment_1_DW.obj.matlabCodegenIsDeleted) {
    Assignment_1_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment_1_DW.obj.isInitialized == 1) &&
        Assignment_1_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(Assignment_1_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Assignment_1_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
