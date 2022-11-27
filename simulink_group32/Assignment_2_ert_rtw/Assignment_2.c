/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_2.c
 *
 * Code generated for Simulink model 'Assignment_2'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Nov 27 14:31:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment_2.h"
#include "rtwtypes.h"
#include "Assignment_2_types.h"
#include <string.h>
#include <stddef.h>
#include "send_params.h"
#include "send_params_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define Assignm_IN_CHARGING_DISCHARGING ((uint8_T)1U)
#define Assignment_2_IN_AAI            ((uint8_T)1U)
#define Assignment_2_IN_AOO            ((uint8_T)2U)
#define Assignment_2_IN_CHARGING       ((uint8_T)2U)
#define Assignment_2_IN_CHARGING_e     ((uint8_T)1U)
#define Assignment_2_IN_DISCHARGING    ((uint8_T)3U)
#define Assignment_2_IN_DISCHARGING_i  ((uint8_T)2U)
#define Assignment_2_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment_2_IN_PACE_ATR       ((uint8_T)2U)
#define Assignment_2_IN_PACE_ATR_i     ((uint8_T)4U)
#define Assignment_2_IN_PACE_ATR_if    ((uint8_T)3U)
#define Assignment_2_IN_Start          ((uint8_T)3U)
#define Assignment_2_IN_VOO            ((uint8_T)4U)
#define Assignment_2_IN_VVI            ((uint8_T)5U)
#define IN_Atrial_Refractory_Period_Pos ((uint8_T)1U)
#define IN_Ventricular_Refractory_Perio ((uint8_T)4U)

/* Named constants for Chart: '<S2>/COMIN' */
#define Assignment_2_IN_ECHO_PARAM     ((uint8_T)1U)
#define Assignment_2_IN_Initial        ((uint8_T)2U)
#define Assignment_2_IN_SET_PARAM      ((uint8_T)3U)
#define Assignment_2_IN_STANDBY        ((uint8_T)4U)

/* Block signals (default storage) */
B_Assignment_2_T Assignment_2_B;

/* Block states (default storage) */
DW_Assignment_2_T Assignment_2_DW;

/* Real-time model */
static RT_MODEL_Assignment_2_T Assignment_2_M_;
RT_MODEL_Assignment_2_T *const Assignment_2_M = &Assignment_2_M_;

/* Forward declaration for local functions */
static void Assignment_2_VVI(const boolean_T *DigitalRead1);
static void Assignmen_enter_atomic_CHARGING(void);
static void Assignment_2_AAI(const boolean_T *DigitalRead);
static void enter_atomic_CHARGING_DISCHARGI(void);
static void enter_atomic_CHARGING_DISCHAR_o(void);
static void Assignment_2_SystemCore_setup_g(freedomk64f_SCIRead_Assignmen_T *obj);

/* Function for Chart: '<S1>/Chart' */
static void Assignment_2_VVI(const boolean_T *DigitalRead1)
{
  int32_T tmp;
  boolean_T guard1 = false;
  if (Assignment_2_B.BD_f != 4) {
    Assignment_2_DW.is_VVI = Assignment_2_IN_NO_ACTIVE_CHILD;
    Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_Start;
  } else {
    guard1 = false;
    switch (Assignment_2_DW.is_VVI) {
     case Assignment_2_IN_CHARGING_e:
      Assignment_2_B.FRONTEND_CTRL = true;
      Assignment_2_B.ATR_PACE_CTRL = false;
      Assignment_2_B.VENT_PACE_CTRL = false;
      Assignment_2_B.PACE_CHARGE_CTRL = true;
      Assignment_2_B.VENT_CMP_REF_PWM = 75.0;
      Assignment_2_B.LED = true;
      Assignment_2_B.LED1 = false;
      if (*DigitalRead1) {
        Assignment_2_DW.is_VVI = IN_Ventricular_Refractory_Perio;
        Assignment_2_DW.temporalCounter_i1 = 0U;
      } else if (Assignment_2_DW.temporalCounter_i1 >= (60000.0F / (real32_T)
                  Assignment_2_B.LRL_i - Assignment_2_DW.delta) -
                 Assignment_2_B.VENT_PW_n) {
        Assignment_2_DW.is_VVI = Assignment_2_IN_PACE_ATR_if;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.PACE_CHARGE_CTRL = false;
        Assignment_2_B.PACE_GND_CTRL = true;
        Assignment_2_B.ATR_GND_CTRL = false;
        Assignment_2_B.Z_ATR_CTRL = false;
        Assignment_2_B.Z_VENT_CTRL = false;
        Assignment_2_B.VENT_GND_CTRL = false;
        Assignment_2_B.VENT_PACE_CTRL = true;
        Assignment_2_B.LED2 = false;
      }
      break;

     case Assignment_2_IN_DISCHARGING_i:
      Assignment_2_B.PACE_GND_CTRL = true;
      Assignment_2_B.VENT_PACE_CTRL = false;
      Assignment_2_B.Z_ATR_CTRL = false;
      Assignment_2_B.Z_VENT_CTRL = false;
      Assignment_2_B.ATR_PACE_CTRL = false;
      Assignment_2_B.ATR_GND_CTRL = false;
      Assignment_2_B.VENT_GND_CTRL = true;
      Assignment_2_B.LED = true;
      Assignment_2_B.LED1 = false;
      if ((Assignment_2_DW.sensing == 0.0) &&
          (Assignment_2_DW.temporalCounter_i1 >= (uint32_T)Assignment_2_B.VRP_d))
      {
        Assignment_2_DW.delta = (real32_T)Assignment_2_B.VRP_d;
        guard1 = true;
      } else if ((Assignment_2_DW.sensing == 1.0) &&
                 (Assignment_2_DW.temporalCounter_i1 >= 1U)) {
        Assignment_2_DW.delta = 0.0F;
        Assignment_2_DW.sensing = 0.0;
        guard1 = true;
      }
      break;

     case Assignment_2_IN_PACE_ATR_if:
      Assignment_2_B.PACE_CHARGE_CTRL = false;
      Assignment_2_B.PACE_GND_CTRL = true;
      Assignment_2_B.ATR_PACE_CTRL = false;
      Assignment_2_B.ATR_GND_CTRL = false;
      Assignment_2_B.Z_ATR_CTRL = false;
      Assignment_2_B.Z_VENT_CTRL = false;
      Assignment_2_B.VENT_GND_CTRL = false;
      Assignment_2_B.VENT_PACE_CTRL = true;
      Assignment_2_B.LED = true;
      Assignment_2_B.LED1 = false;
      if (Assignment_2_DW.temporalCounter_i1 >= Assignment_2_B.VENT_PW_n) {
        Assignment_2_DW.is_VVI = Assignment_2_IN_DISCHARGING_i;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.VENT_PACE_CTRL = false;
        Assignment_2_B.VENT_GND_CTRL = true;
        Assignment_2_B.LED2 = false;
      }
      break;

     default:
      /* case IN_Ventricular_Refractory_Period_Post_Sensing: */
      if (Assignment_2_B.VRP_d > 2147483612) {
        tmp = MAX_int32_T;
      } else {
        tmp = Assignment_2_B.VRP_d + 35;
      }

      if (Assignment_2_DW.temporalCounter_i1 >= (uint32_T)tmp) {
        Assignment_2_DW.delta = (real32_T)Assignment_2_B.VRP_d;
        Assignment_2_DW.sensing = 1.0;
        Assignment_2_DW.is_VVI = Assignment_2_IN_CHARGING_e;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.FRONTEND_CTRL = true;
        Assignment_2_B.ATR_PACE_CTRL = false;
        Assignment_2_B.VENT_PACE_CTRL = false;
        Assignment_2_B.PACING_REF_PWM = 90.0F;
        Assignment_2_B.PACE_CHARGE_CTRL = true;
        Assignment_2_B.VENT_CMP_REF_PWM = 75.0;
        Assignment_2_B.LED = true;
        Assignment_2_B.LED1 = false;
        Assignment_2_B.LED2 = false;
      }
      break;
    }

    if (guard1) {
      Assignment_2_DW.is_VVI = Assignment_2_IN_CHARGING_e;
      Assignment_2_DW.temporalCounter_i1 = 0U;
      Assignment_2_B.FRONTEND_CTRL = true;
      Assignment_2_B.PACING_REF_PWM = 90.0F;
      Assignment_2_B.PACE_CHARGE_CTRL = true;
      Assignment_2_B.VENT_CMP_REF_PWM = 75.0;
      Assignment_2_B.LED2 = false;
    }
  }
}

/* Function for Chart: '<S1>/Chart' */
static void Assignmen_enter_atomic_CHARGING(void)
{
  Assignment_2_B.FRONTEND_CTRL = true;
  Assignment_2_B.VENT_PACE_CTRL = false;
  Assignment_2_B.ATR_PACE_CTRL = false;
  Assignment_2_B.PACING_REF_PWM = 90.0F;
  Assignment_2_B.PACE_CHARGE_CTRL = true;
  Assignment_2_B.ATR_CMP_REF_PWM = 75.0;
  Assignment_2_B.LED = false;
  Assignment_2_B.LED1 = false;
  Assignment_2_B.LED2 = true;
}

/* Function for Chart: '<S1>/Chart' */
static void Assignment_2_AAI(const boolean_T *DigitalRead)
{
  int32_T tmp;
  boolean_T guard1 = false;
  if (Assignment_2_B.BD_f != 3) {
    Assignment_2_DW.is_AAI = Assignment_2_IN_NO_ACTIVE_CHILD;
    Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_Start;
  } else {
    guard1 = false;
    switch (Assignment_2_DW.is_AAI) {
     case IN_Atrial_Refractory_Period_Pos:
      if (Assignment_2_B.ARP_e > 2147483612) {
        tmp = MAX_int32_T;
      } else {
        tmp = Assignment_2_B.ARP_e + 35;
      }

      if (Assignment_2_DW.temporalCounter_i1 >= (uint32_T)tmp) {
        Assignment_2_DW.delta = (real32_T)Assignment_2_B.ARP_e;
        Assignment_2_DW.sensing = 1.0;
        Assignment_2_DW.is_AAI = Assignment_2_IN_CHARGING;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignmen_enter_atomic_CHARGING();
      } else {
        Assignment_2_B.LED2 = true;
      }
      break;

     case Assignment_2_IN_CHARGING:
      Assignment_2_B.FRONTEND_CTRL = true;
      Assignment_2_B.VENT_PACE_CTRL = false;
      Assignment_2_B.ATR_PACE_CTRL = false;
      Assignment_2_B.PACE_CHARGE_CTRL = true;
      Assignment_2_B.ATR_CMP_REF_PWM = 75.0;
      Assignment_2_B.LED = false;
      Assignment_2_B.LED1 = false;
      if (*DigitalRead) {
        Assignment_2_DW.is_AAI = IN_Atrial_Refractory_Period_Pos;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.LED2 = true;
      } else if (Assignment_2_DW.temporalCounter_i1 >= (60000.0F / (real32_T)
                  Assignment_2_B.LRL_i - Assignment_2_DW.delta) -
                 Assignment_2_B.ATR_PW_i) {
        Assignment_2_DW.is_AAI = Assignment_2_IN_PACE_ATR_i;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.PACE_CHARGE_CTRL = false;
        Assignment_2_B.PACE_GND_CTRL = true;
        Assignment_2_B.VENT_GND_CTRL = false;
        Assignment_2_B.Z_VENT_CTRL = false;
        Assignment_2_B.Z_ATR_CTRL = false;
        Assignment_2_B.ATR_GND_CTRL = false;
        Assignment_2_B.ATR_PACE_CTRL = true;
        Assignment_2_B.LED2 = true;
      }
      break;

     case Assignment_2_IN_DISCHARGING:
      Assignment_2_B.PACE_GND_CTRL = true;
      Assignment_2_B.ATR_PACE_CTRL = false;
      Assignment_2_B.Z_VENT_CTRL = false;
      Assignment_2_B.Z_ATR_CTRL = false;
      Assignment_2_B.VENT_PACE_CTRL = false;
      Assignment_2_B.VENT_GND_CTRL = false;
      Assignment_2_B.ATR_GND_CTRL = true;
      Assignment_2_B.LED = false;
      Assignment_2_B.LED1 = false;
      if ((Assignment_2_DW.sensing == 0.0) &&
          (Assignment_2_DW.temporalCounter_i1 >= (uint32_T)Assignment_2_B.ARP_e))
      {
        Assignment_2_DW.delta = (real32_T)Assignment_2_B.ARP_e;
        guard1 = true;
      } else if ((Assignment_2_DW.sensing == 1.0) &&
                 (Assignment_2_DW.temporalCounter_i1 >= 1U)) {
        Assignment_2_DW.delta = 0.0F;
        Assignment_2_DW.sensing = 0.0;
        guard1 = true;
      }
      break;

     default:
      /* case IN_PACE_ATR: */
      Assignment_2_B.PACE_CHARGE_CTRL = false;
      Assignment_2_B.PACE_GND_CTRL = true;
      Assignment_2_B.VENT_PACE_CTRL = false;
      Assignment_2_B.VENT_GND_CTRL = false;
      Assignment_2_B.Z_VENT_CTRL = false;
      Assignment_2_B.Z_ATR_CTRL = false;
      Assignment_2_B.ATR_GND_CTRL = false;
      Assignment_2_B.ATR_PACE_CTRL = true;
      Assignment_2_B.LED = false;
      Assignment_2_B.LED1 = false;
      if (Assignment_2_DW.temporalCounter_i1 >= Assignment_2_B.ATR_PW_i) {
        Assignment_2_DW.is_AAI = Assignment_2_IN_DISCHARGING;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.ATR_PACE_CTRL = false;
        Assignment_2_B.ATR_GND_CTRL = true;
        Assignment_2_B.LED2 = true;
      }
      break;
    }

    if (guard1) {
      Assignment_2_DW.is_AAI = Assignment_2_IN_CHARGING;
      Assignment_2_DW.temporalCounter_i1 = 0U;
      Assignmen_enter_atomic_CHARGING();
    }
  }
}

/* Function for Chart: '<S1>/Chart' */
static void enter_atomic_CHARGING_DISCHARGI(void)
{
  Assignment_2_B.PACE_GND_CTRL = true;
  Assignment_2_B.VENT_PACE_CTRL = false;
  Assignment_2_B.Z_ATR_CTRL = false;
  Assignment_2_B.Z_VENT_CTRL = false;
  Assignment_2_B.ATR_PACE_CTRL = false;
  Assignment_2_B.ATR_GND_CTRL = true;
  Assignment_2_B.VENT_GND_CTRL = false;
  Assignment_2_B.PACING_REF_PWM = 100.0F * Assignment_2_B.ATR_AMP_n / 5.0F;
  Assignment_2_B.PACE_CHARGE_CTRL = true;
  Assignment_2_B.LED = true;
  Assignment_2_B.LED1 = false;
  Assignment_2_B.LED2 = false;
}

/* Function for Chart: '<S1>/Chart' */
static void enter_atomic_CHARGING_DISCHAR_o(void)
{
  Assignment_2_B.PACE_GND_CTRL = true;
  Assignment_2_B.VENT_PACE_CTRL = false;
  Assignment_2_B.Z_ATR_CTRL = false;
  Assignment_2_B.Z_VENT_CTRL = false;
  Assignment_2_B.ATR_PACE_CTRL = false;
  Assignment_2_B.ATR_GND_CTRL = true;
  Assignment_2_B.VENT_GND_CTRL = false;
  Assignment_2_B.PACING_REF_PWM = 100.0F * Assignment_2_B.VENT_AMP_k / 5.0F;
  Assignment_2_B.PACE_CHARGE_CTRL = true;
  Assignment_2_B.LED = false;
  Assignment_2_B.LED1 = true;
  Assignment_2_B.LED2 = false;
}

static void Assignment_2_SystemCore_setup_g(freedomk64f_SCIRead_Assignmen_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Assignment_2_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Assignment_2_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Assignment_2_B.SCIModuleLoc, false, 10U,
    Assignment_2_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Assignment_2_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        Assignment_2_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void Assignment_2_step(void)
{
  uint8_T status;
  boolean_T DigitalRead;
  boolean_T DigitalRead1;

  /* MATLABSystem: '<S2>/Serial Receive' */
  if (Assignment_2_DW.obj_l.SampleTime !=
      Assignment_2_P.SerialReceive_SampleTime) {
    Assignment_2_DW.obj_l.SampleTime = Assignment_2_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Assignment_2_DW.obj_l.MW_SCIHANDLE,
    &Assignment_2_B.RxDataLocChar[0], 102U);
  memcpy((void *)&Assignment_2_B.RxData[0], (void *)
         &Assignment_2_B.RxDataLocChar[0], (uint32_T)((size_t)102 * sizeof
          (uint8_T)));

  /* MATLABSystem: '<S5>/Digital Read2' */
  if (Assignment_2_DW.obj_p.SampleTime != Assignment_2_P.DigitalRead2_SampleTime)
  {
    Assignment_2_DW.obj_p.SampleTime = Assignment_2_P.DigitalRead2_SampleTime;
  }

  Assignment_2_B.DigitalRead2 = MW_digitalIO_read
    (Assignment_2_DW.obj_p.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S5>/Digital Read2' */

  /* MATLABSystem: '<S5>/Digital Read3' */
  if (Assignment_2_DW.obj.SampleTime != Assignment_2_P.DigitalRead3_SampleTime)
  {
    Assignment_2_DW.obj.SampleTime = Assignment_2_P.DigitalRead3_SampleTime;
  }

  Assignment_2_B.DigitalRead3 = MW_digitalIO_read
    (Assignment_2_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S5>/Digital Read3' */

  /* Chart: '<S2>/COMIN' incorporates:
   *  MATLABSystem: '<S2>/Serial Receive'
   */
  if (Assignment_2_DW.is_active_c1_Assignment_2 == 0U) {
    Assignment_2_DW.is_active_c1_Assignment_2 = 1U;
    Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_Initial;
  } else {
    switch (Assignment_2_DW.is_c1_Assignment_2) {
     case Assignment_2_IN_ECHO_PARAM:
      Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_STANDBY;
      break;

     case Assignment_2_IN_Initial:
      Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_STANDBY;
      break;

     case Assignment_2_IN_SET_PARAM:
      Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (Assignment_2_B.RxData[0] == 22) {
          switch (Assignment_2_B.RxData[1]) {
           case 85:
            Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_SET_PARAM;
            memcpy((void *)&Assignment_2_B.BD_f, (void *)&Assignment_2_B.RxData
                   [2], (uint32_T)((size_t)1 * sizeof(int32_T)));
            memcpy((void *)&Assignment_2_B.LRL_i, (void *)
                   &Assignment_2_B.RxData[6], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.URL_g, (void *)
                   &Assignment_2_B.RxData[10], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.ATR_AMP_n, (void *)
                   &Assignment_2_B.RxData[14], (uint32_T)((size_t)1 * sizeof
                    (real32_T)));
            memcpy((void *)&Assignment_2_B.ATR_PW_i, (void *)
                   &Assignment_2_B.RxData[18], (uint32_T)((size_t)1 * sizeof
                    (real32_T)));
            memcpy((void *)&Assignment_2_B.ATR_Sens_a, (void *)
                   &Assignment_2_B.RxData[22], (uint32_T)((size_t)1 * sizeof
                    (real32_T)));
            memcpy((void *)&Assignment_2_B.VENT_AMP_k, (void *)
                   &Assignment_2_B.RxData[26], (uint32_T)((size_t)1 * sizeof
                    (real32_T)));
            memcpy((void *)&Assignment_2_B.VENT_PW_n, (void *)
                   &Assignment_2_B.RxData[30], (uint32_T)((size_t)1 * sizeof
                    (real32_T)));
            memcpy((void *)&Assignment_2_B.VENT_Sens_l, (void *)
                   &Assignment_2_B.RxData[34], (uint32_T)((size_t)1 * sizeof
                    (real32_T)));
            memcpy((void *)&Assignment_2_B.VRP_d, (void *)
                   &Assignment_2_B.RxData[38], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.ARP_e, (void *)
                   &Assignment_2_B.RxData[42], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.MAX_SENS_RATE_k, (void *)
                   &Assignment_2_B.RxData[46], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.FixedAVdelay_m, (void *)
                   &Assignment_2_B.RxData[50], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.DynamicAVdelay_j, (void *)
                   &Assignment_2_B.RxData[54], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.AVdelayOffset_m, (void *)
                   &Assignment_2_B.RxData[58], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.PVARP_p, (void *)
                   &Assignment_2_B.RxData[62], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.PVARPextenson_k, (void *)
                   &Assignment_2_B.RxData[66], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.HYS_m, (void *)
                   &Assignment_2_B.RxData[70], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.RATE_SMOOTH_k, (void *)
                   &Assignment_2_B.RxData[74], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.REAC_TIME_g, (void *)
                   &Assignment_2_B.RxData[78], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.RESP_FAC_g, (void *)
                   &Assignment_2_B.RxData[82], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.RecoveryTime_d, (void *)
                   &Assignment_2_B.RxData[86], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.ATRmode_m, (void *)
                   &Assignment_2_B.RxData[90], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.ATRtime_g, (void *)
                   &Assignment_2_B.RxData[94], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            memcpy((void *)&Assignment_2_B.ATRduration_l, (void *)
                   &Assignment_2_B.RxData[98], (uint32_T)((size_t)1 * sizeof
                    (int32_T)));
            break;

           case 34:
            Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_ECHO_PARAM;
            send_params();
            break;

           default:
            Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_STANDBY;
            break;
          }
        } else {
          Assignment_2_DW.is_c1_Assignment_2 = Assignment_2_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S2>/COMIN' */

  /* MATLABSystem: '<S5>/Digital Read' */
  if (Assignment_2_DW.obj_g.SampleTime != Assignment_2_P.DigitalRead_SampleTime)
  {
    Assignment_2_DW.obj_g.SampleTime = Assignment_2_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<S5>/Digital Read' */
  DigitalRead = MW_digitalIO_read(Assignment_2_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S5>/Digital Read1' */
  if (Assignment_2_DW.obj_o.SampleTime != Assignment_2_P.DigitalRead1_SampleTime)
  {
    Assignment_2_DW.obj_o.SampleTime = Assignment_2_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S5>/Digital Read1' */
  DigitalRead1 = MW_digitalIO_read(Assignment_2_DW.obj_o.MW_DIGITALIO_HANDLE);

  /* Chart: '<S1>/Chart' */
  if (Assignment_2_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment_2_DW.temporalCounter_i1++;
  }

  if (Assignment_2_DW.is_active_c3_Assignment_2 == 0U) {
    Assignment_2_DW.is_active_c3_Assignment_2 = 1U;
    Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_Start;
  } else {
    switch (Assignment_2_DW.is_c3_Assignment_2) {
     case Assignment_2_IN_AAI:
      Assignment_2_AAI(&DigitalRead);
      break;

     case Assignment_2_IN_AOO:
      if (Assignment_2_B.BD_f != 1) {
        Assignment_2_DW.is_AOO = Assignment_2_IN_NO_ACTIVE_CHILD;
        Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_Start;
      } else if (Assignment_2_DW.is_AOO == Assignm_IN_CHARGING_DISCHARGING) {
        Assignment_2_B.PACE_GND_CTRL = true;
        Assignment_2_B.VENT_PACE_CTRL = false;
        Assignment_2_B.Z_ATR_CTRL = false;
        Assignment_2_B.Z_VENT_CTRL = false;
        Assignment_2_B.ATR_PACE_CTRL = false;
        Assignment_2_B.ATR_GND_CTRL = true;
        Assignment_2_B.VENT_GND_CTRL = false;
        Assignment_2_B.PACE_CHARGE_CTRL = true;
        Assignment_2_B.LED = true;
        Assignment_2_B.LED1 = false;
        if (Assignment_2_DW.temporalCounter_i1 >= 60000.0F / (real32_T)
            Assignment_2_B.LRL_i - Assignment_2_B.ATR_PW_i) {
          Assignment_2_DW.is_AOO = Assignment_2_IN_PACE_ATR;
          Assignment_2_DW.temporalCounter_i1 = 0U;
          Assignment_2_B.PACE_CHARGE_CTRL = false;
          Assignment_2_B.ATR_PACE_CTRL = true;
          Assignment_2_B.ATR_GND_CTRL = false;
          Assignment_2_B.LED2 = false;
        }
      } else {
        /* case IN_PACE_ATR: */
        Assignment_2_B.PACE_CHARGE_CTRL = false;
        Assignment_2_B.PACE_GND_CTRL = true;
        Assignment_2_B.ATR_PACE_CTRL = true;
        Assignment_2_B.ATR_GND_CTRL = false;
        Assignment_2_B.Z_ATR_CTRL = false;
        Assignment_2_B.Z_VENT_CTRL = false;
        Assignment_2_B.VENT_GND_CTRL = false;
        Assignment_2_B.VENT_PACE_CTRL = false;
        Assignment_2_B.LED = true;
        Assignment_2_B.LED1 = false;
        if (Assignment_2_DW.temporalCounter_i1 >= Assignment_2_B.ATR_PW_i) {
          Assignment_2_DW.is_AOO = Assignm_IN_CHARGING_DISCHARGING;
          Assignment_2_DW.temporalCounter_i1 = 0U;
          enter_atomic_CHARGING_DISCHARGI();
        }
      }
      break;

     case Assignment_2_IN_Start:
      switch (Assignment_2_B.BD_f) {
       case 1:
        Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_AOO;
        Assignment_2_DW.is_AOO = Assignm_IN_CHARGING_DISCHARGING;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_DISCHARGI();
        break;

       case 2:
        Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_VOO;
        Assignment_2_DW.is_VOO = Assignm_IN_CHARGING_DISCHARGING;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_DISCHAR_o();
        break;

       case 3:
        Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_AAI;
        Assignment_2_DW.delta = 0.0F;
        Assignment_2_DW.sensing = 0.0;
        Assignment_2_DW.is_AAI = Assignment_2_IN_CHARGING;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignmen_enter_atomic_CHARGING();
        break;

       case 4:
        Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_VVI;
        Assignment_2_DW.delta = 0.0F;
        Assignment_2_DW.sensing = 0.0;
        Assignment_2_DW.is_VVI = Assignment_2_IN_CHARGING_e;
        Assignment_2_DW.temporalCounter_i1 = 0U;
        Assignment_2_B.FRONTEND_CTRL = true;
        Assignment_2_B.ATR_PACE_CTRL = false;
        Assignment_2_B.VENT_PACE_CTRL = false;
        Assignment_2_B.PACING_REF_PWM = 90.0F;
        Assignment_2_B.PACE_CHARGE_CTRL = true;
        Assignment_2_B.VENT_CMP_REF_PWM = 75.0;
        Assignment_2_B.LED = true;
        Assignment_2_B.LED1 = false;
        Assignment_2_B.LED2 = false;
        break;
      }
      break;

     case Assignment_2_IN_VOO:
      if (Assignment_2_B.BD_f != 2) {
        Assignment_2_DW.is_VOO = Assignment_2_IN_NO_ACTIVE_CHILD;
        Assignment_2_DW.is_c3_Assignment_2 = Assignment_2_IN_Start;
      } else if (Assignment_2_DW.is_VOO == Assignm_IN_CHARGING_DISCHARGING) {
        Assignment_2_B.PACE_GND_CTRL = true;
        Assignment_2_B.VENT_PACE_CTRL = false;
        Assignment_2_B.Z_ATR_CTRL = false;
        Assignment_2_B.Z_VENT_CTRL = false;
        Assignment_2_B.ATR_PACE_CTRL = false;
        Assignment_2_B.ATR_GND_CTRL = true;
        Assignment_2_B.VENT_GND_CTRL = false;
        Assignment_2_B.PACE_CHARGE_CTRL = true;
        Assignment_2_B.LED = false;
        Assignment_2_B.LED1 = true;
        if (Assignment_2_DW.temporalCounter_i1 >= 60000.0F / (real32_T)
            Assignment_2_B.LRL_i - Assignment_2_B.VENT_PW_n) {
          Assignment_2_DW.is_VOO = Assignment_2_IN_PACE_ATR;
          Assignment_2_DW.temporalCounter_i1 = 0U;
          Assignment_2_B.PACE_CHARGE_CTRL = false;
          Assignment_2_B.ATR_GND_CTRL = false;
          Assignment_2_B.VENT_PACE_CTRL = true;
          Assignment_2_B.LED2 = false;
        }
      } else {
        /* case IN_PACE_ATR: */
        Assignment_2_B.PACE_CHARGE_CTRL = false;
        Assignment_2_B.PACE_GND_CTRL = true;
        Assignment_2_B.ATR_PACE_CTRL = false;
        Assignment_2_B.ATR_GND_CTRL = false;
        Assignment_2_B.Z_ATR_CTRL = false;
        Assignment_2_B.Z_VENT_CTRL = false;
        Assignment_2_B.VENT_GND_CTRL = false;
        Assignment_2_B.VENT_PACE_CTRL = true;
        Assignment_2_B.LED = false;
        Assignment_2_B.LED1 = true;
        if (Assignment_2_DW.temporalCounter_i1 >= Assignment_2_B.VENT_PW_n) {
          Assignment_2_DW.is_VOO = Assignm_IN_CHARGING_DISCHARGING;
          Assignment_2_DW.temporalCounter_i1 = 0U;
          enter_atomic_CHARGING_DISCHAR_o();
        }
      }
      break;

     default:
      /* case IN_VVI: */
      Assignment_2_VVI(&DigitalRead1);
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* MATLABSystem: '<S1>/Digital Write' */
  MW_digitalIO_write(Assignment_2_DW.obj_pj.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.LED);

  /* MATLABSystem: '<S1>/Digital Write1' */
  MW_digitalIO_write(Assignment_2_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.LED1);

  /* MATLABSystem: '<S1>/Digital Write2' */
  MW_digitalIO_write(Assignment_2_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.LED2);

  /* MATLABSystem: '<S5>/Digital Write' */
  MW_digitalIO_write(Assignment_2_DW.obj_pu.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S5>/Digital Write1' */
  MW_digitalIO_write(Assignment_2_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S5>/Digital Write2' */
  MW_digitalIO_write(Assignment_2_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S5>/Digital Write3' */
  MW_digitalIO_write(Assignment_2_DW.obj_p4.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S5>/Digital Write4' */
  MW_digitalIO_write(Assignment_2_DW.obj_ki.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S5>/Digital Write5' */
  MW_digitalIO_write(Assignment_2_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S5>/Digital Write6' */
  MW_digitalIO_write(Assignment_2_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S5>/Digital Write7' */
  MW_digitalIO_write(Assignment_2_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S5>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment_2_DW.obj_mt.MW_PWM_HANDLE, (real_T)
                      Assignment_2_B.PACING_REF_PWM);

  /* MATLABSystem: '<S5>/PWM Output1' */
  MW_PWM_SetDutyCycle(Assignment_2_DW.obj_hy.MW_PWM_HANDLE,
                      Assignment_2_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/Digital Write10' */
  MW_digitalIO_write(Assignment_2_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment_2_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S5>/PWM Output2' */
  MW_PWM_SetDutyCycle(Assignment_2_DW.obj_my.MW_PWM_HANDLE,
                      Assignment_2_B.VENT_CMP_REF_PWM);
}

/* Model initialize function */
void Assignment_2_initialize(void)
{
  {
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/Function-Call Subsystem' incorporates:
     *  SubSystem: '<S2>/Function-Call Subsystem'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/Function-Call Subsystem' */

    /* Start for MATLABSystem: '<S2>/Serial Receive' */
    Assignment_2_DW.obj_l.isInitialized = 0;
    Assignment_2_DW.obj_l.matlabCodegenIsDeleted = false;
    Assignment_2_DW.obj_l.SampleTime = Assignment_2_P.SerialReceive_SampleTime;
    Assignment_2_SystemCore_setup_g(&Assignment_2_DW.obj_l);

    /* Start for MATLABSystem: '<S5>/Digital Read2' */
    Assignment_2_DW.obj_p.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_p.isInitialized = 0;
    Assignment_2_DW.obj_p.SampleTime = -1.0;
    Assignment_2_DW.obj_p.matlabCodegenIsDeleted = false;
    Assignment_2_DW.obj_p.SampleTime = Assignment_2_P.DigitalRead2_SampleTime;
    obj = &Assignment_2_DW.obj_p;
    Assignment_2_DW.obj_p.isSetupComplete = false;
    Assignment_2_DW.obj_p.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(16U, 0);
    Assignment_2_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read3' */
    Assignment_2_DW.obj.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj.isInitialized = 0;
    Assignment_2_DW.obj.SampleTime = -1.0;
    Assignment_2_DW.obj.matlabCodegenIsDeleted = false;
    Assignment_2_DW.obj.SampleTime = Assignment_2_P.DigitalRead3_SampleTime;
    obj = &Assignment_2_DW.obj;
    Assignment_2_DW.obj.isSetupComplete = false;
    Assignment_2_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(17U, 0);
    Assignment_2_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read' */
    Assignment_2_DW.obj_g.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_g.isInitialized = 0;
    Assignment_2_DW.obj_g.SampleTime = -1.0;
    Assignment_2_DW.obj_g.matlabCodegenIsDeleted = false;
    Assignment_2_DW.obj_g.SampleTime = Assignment_2_P.DigitalRead_SampleTime;
    obj = &Assignment_2_DW.obj_g;
    Assignment_2_DW.obj_g.isSetupComplete = false;
    Assignment_2_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment_2_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read1' */
    Assignment_2_DW.obj_o.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_o.isInitialized = 0;
    Assignment_2_DW.obj_o.SampleTime = -1.0;
    Assignment_2_DW.obj_o.matlabCodegenIsDeleted = false;
    Assignment_2_DW.obj_o.SampleTime = Assignment_2_P.DigitalRead1_SampleTime;
    obj = &Assignment_2_DW.obj_o;
    Assignment_2_DW.obj_o.isSetupComplete = false;
    Assignment_2_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment_2_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    Assignment_2_DW.obj_pj.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_pj.isInitialized = 0;
    Assignment_2_DW.obj_pj.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_pj;
    Assignment_2_DW.obj_pj.isSetupComplete = false;
    Assignment_2_DW.obj_pj.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment_2_DW.obj_pj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    Assignment_2_DW.obj_f.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_f.isInitialized = 0;
    Assignment_2_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_f;
    Assignment_2_DW.obj_f.isSetupComplete = false;
    Assignment_2_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Assignment_2_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write2' */
    Assignment_2_DW.obj_i.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_i.isInitialized = 0;
    Assignment_2_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_i;
    Assignment_2_DW.obj_i.isSetupComplete = false;
    Assignment_2_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment_2_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write' */
    Assignment_2_DW.obj_pu.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_pu.isInitialized = 0;
    Assignment_2_DW.obj_pu.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_pu;
    Assignment_2_DW.obj_pu.isSetupComplete = false;
    Assignment_2_DW.obj_pu.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment_2_DW.obj_pu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    Assignment_2_DW.obj_a.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_a.isInitialized = 0;
    Assignment_2_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_a;
    Assignment_2_DW.obj_a.isSetupComplete = false;
    Assignment_2_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment_2_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write2' */
    Assignment_2_DW.obj_d.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_d.isInitialized = 0;
    Assignment_2_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_d;
    Assignment_2_DW.obj_d.isSetupComplete = false;
    Assignment_2_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment_2_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write3' */
    Assignment_2_DW.obj_p4.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_p4.isInitialized = 0;
    Assignment_2_DW.obj_p4.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_p4;
    Assignment_2_DW.obj_p4.isSetupComplete = false;
    Assignment_2_DW.obj_p4.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment_2_DW.obj_p4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write4' */
    Assignment_2_DW.obj_ki.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_ki.isInitialized = 0;
    Assignment_2_DW.obj_ki.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_ki;
    Assignment_2_DW.obj_ki.isSetupComplete = false;
    Assignment_2_DW.obj_ki.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment_2_DW.obj_ki.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write5' */
    Assignment_2_DW.obj_e.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_e.isInitialized = 0;
    Assignment_2_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_e;
    Assignment_2_DW.obj_e.isSetupComplete = false;
    Assignment_2_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment_2_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write6' */
    Assignment_2_DW.obj_k.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_k.isInitialized = 0;
    Assignment_2_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_k;
    Assignment_2_DW.obj_k.isSetupComplete = false;
    Assignment_2_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment_2_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write7' */
    Assignment_2_DW.obj_m.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_m.isInitialized = 0;
    Assignment_2_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_m;
    Assignment_2_DW.obj_m.isSetupComplete = false;
    Assignment_2_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment_2_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output' */
    Assignment_2_DW.obj_mt.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_mt.isInitialized = 0;
    Assignment_2_DW.obj_mt.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_2_DW.obj_mt;
    Assignment_2_DW.obj_mt.isSetupComplete = false;
    Assignment_2_DW.obj_mt.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_2_DW.obj_mt.MW_PWM_HANDLE);
    Assignment_2_DW.obj_mt.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output1' */
    Assignment_2_DW.obj_hy.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_hy.isInitialized = 0;
    Assignment_2_DW.obj_hy.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_2_DW.obj_hy;
    Assignment_2_DW.obj_hy.isSetupComplete = false;
    Assignment_2_DW.obj_hy.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_2_DW.obj_hy.MW_PWM_HANDLE);
    Assignment_2_DW.obj_hy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write10' */
    Assignment_2_DW.obj_h.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_h.isInitialized = 0;
    Assignment_2_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment_2_DW.obj_h;
    Assignment_2_DW.obj_h.isSetupComplete = false;
    Assignment_2_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment_2_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM Output2' */
    Assignment_2_DW.obj_my.matlabCodegenIsDeleted = true;
    Assignment_2_DW.obj_my.isInitialized = 0;
    Assignment_2_DW.obj_my.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment_2_DW.obj_my;
    Assignment_2_DW.obj_my.isSetupComplete = false;
    Assignment_2_DW.obj_my.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment_2_DW.obj_my.MW_PWM_HANDLE);
    Assignment_2_DW.obj_my.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment_2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Receive' */
  if (!Assignment_2_DW.obj_l.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_l.isInitialized == 1) &&
        Assignment_2_DW.obj_l.isSetupComplete) {
      MW_SCI_Close(Assignment_2_DW.obj_l.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read2' */
  if (!Assignment_2_DW.obj_p.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_p.isInitialized == 1) &&
        Assignment_2_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read2' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read3' */
  if (!Assignment_2_DW.obj.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj.isInitialized == 1) &&
        Assignment_2_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read3' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read' */
  if (!Assignment_2_DW.obj_g.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_g.isInitialized == 1) &&
        Assignment_2_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read1' */
  if (!Assignment_2_DW.obj_o.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_o.isInitialized == 1) &&
        Assignment_2_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!Assignment_2_DW.obj_pj.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_pj.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_pj.isInitialized == 1) &&
        Assignment_2_DW.obj_pj.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_pj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  if (!Assignment_2_DW.obj_f.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_f.isInitialized == 1) &&
        Assignment_2_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write2' */
  if (!Assignment_2_DW.obj_i.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_i.isInitialized == 1) &&
        Assignment_2_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  if (!Assignment_2_DW.obj_pu.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_pu.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_pu.isInitialized == 1) &&
        Assignment_2_DW.obj_pu.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_pu.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write1' */
  if (!Assignment_2_DW.obj_a.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_a.isInitialized == 1) &&
        Assignment_2_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write2' */
  if (!Assignment_2_DW.obj_d.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_d.isInitialized == 1) &&
        Assignment_2_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write3' */
  if (!Assignment_2_DW.obj_p4.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_p4.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_p4.isInitialized == 1) &&
        Assignment_2_DW.obj_p4.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_p4.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write4' */
  if (!Assignment_2_DW.obj_ki.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_ki.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_ki.isInitialized == 1) &&
        Assignment_2_DW.obj_ki.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_ki.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write5' */
  if (!Assignment_2_DW.obj_e.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_e.isInitialized == 1) &&
        Assignment_2_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write6' */
  if (!Assignment_2_DW.obj_k.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_k.isInitialized == 1) &&
        Assignment_2_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write7' */
  if (!Assignment_2_DW.obj_m.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_m.isInitialized == 1) &&
        Assignment_2_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output' */
  if (!Assignment_2_DW.obj_mt.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_mt.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_mt.isInitialized == 1) &&
        Assignment_2_DW.obj_mt.isSetupComplete) {
      MW_PWM_Stop(Assignment_2_DW.obj_mt.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_2_DW.obj_mt.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output1' */
  if (!Assignment_2_DW.obj_hy.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_hy.isInitialized == 1) &&
        Assignment_2_DW.obj_hy.isSetupComplete) {
      MW_PWM_Stop(Assignment_2_DW.obj_hy.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_2_DW.obj_hy.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write10' */
  if (!Assignment_2_DW.obj_h.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_h.isInitialized == 1) &&
        Assignment_2_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Assignment_2_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S5>/PWM Output2' */
  if (!Assignment_2_DW.obj_my.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_my.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_my.isInitialized == 1) &&
        Assignment_2_DW.obj_my.isSetupComplete) {
      MW_PWM_Stop(Assignment_2_DW.obj_my.MW_PWM_HANDLE);
      MW_PWM_Close(Assignment_2_DW.obj_my.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
