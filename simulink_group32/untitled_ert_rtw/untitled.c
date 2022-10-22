/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Oct 21 16:49:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include <math.h>
#include "untitled_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define IN_Atrial_Refractory_Period_P_m ((uint8_T)2U)
#define IN_Atrial_Refractory_Period_Pos ((uint8_T)1U)
#define untitle_IN_CHARGING_DISCHARGING ((uint8_T)3U)
#define untitled_IN_PACE_ATR           ((uint8_T)4U)

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  boolean_T rtb_DigitalRead_0;

  /* MATLABSystem: '<S2>/Digital Read' */
  if (untitled_DW.obj.SampleTime != untitled_P.DigitalRead_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read(untitled_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  MATLABSystem: '<S2>/Digital Read'
   */
  if (untitled_DW.temporalCounter_i1 < MAX_uint32_T) {
    untitled_DW.temporalCounter_i1++;
  }

  if (untitled_DW.is_active_c3_untitled == 0U) {
    untitled_DW.is_active_c3_untitled = 1U;
    untitled_DW.delta = 0.0;
    untitled_DW.is_c3_untitled = untitle_IN_CHARGING_DISCHARGING;
    untitled_DW.temporalCounter_i1 = 0U;
    untitled_B.PACE_GND_CTRL = true;
    untitled_B.VENT_PACE_CTRL = false;
    untitled_B.Z_ATR_CTRL = false;
    untitled_B.Z_VENT_CTRL = false;
    untitled_B.ATR_PACE_CTRL = false;
    untitled_B.ATR_GND_CTRL = true;
    untitled_B.VENT_GND_CTRL = false;
    untitled_B.PACING_REF_PWM = 100.0 * untitled_P.Constant2_Value / 5.0;
    untitled_B.PACE_CHARGE_CTRL = true;
  } else {
    switch (untitled_DW.is_c3_untitled) {
     case IN_Atrial_Refractory_Period_Pos:
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_P.Constant1_Value)) {
        untitled_DW.delta = untitled_P.Constant1_Value;
        untitled_DW.is_c3_untitled = untitle_IN_CHARGING_DISCHARGING;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = true;
        untitled_B.VENT_PACE_CTRL = false;
        untitled_B.Z_ATR_CTRL = false;
        untitled_B.Z_VENT_CTRL = false;
        untitled_B.ATR_PACE_CTRL = false;
        untitled_B.ATR_GND_CTRL = true;
        untitled_B.VENT_GND_CTRL = false;
        untitled_B.PACING_REF_PWM = 100.0 * untitled_P.Constant2_Value / 5.0;
        untitled_B.PACE_CHARGE_CTRL = true;
      }
      break;

     case IN_Atrial_Refractory_Period_P_m:
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_P.Constant1_Value)) {
        untitled_DW.delta = untitled_P.Constant1_Value;
        untitled_DW.is_c3_untitled = untitle_IN_CHARGING_DISCHARGING;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_GND_CTRL = true;
        untitled_B.VENT_PACE_CTRL = false;
        untitled_B.Z_ATR_CTRL = false;
        untitled_B.Z_VENT_CTRL = false;
        untitled_B.ATR_PACE_CTRL = false;
        untitled_B.ATR_GND_CTRL = true;
        untitled_B.VENT_GND_CTRL = false;
        untitled_B.PACING_REF_PWM = 100.0 * untitled_P.Constant2_Value / 5.0;
        untitled_B.PACE_CHARGE_CTRL = true;
      }
      break;

     case untitle_IN_CHARGING_DISCHARGING:
      untitled_B.PACE_GND_CTRL = true;
      untitled_B.VENT_PACE_CTRL = false;
      untitled_B.Z_ATR_CTRL = false;
      untitled_B.Z_VENT_CTRL = false;
      untitled_B.ATR_PACE_CTRL = false;
      untitled_B.ATR_GND_CTRL = true;
      untitled_B.VENT_GND_CTRL = false;
      untitled_B.PACE_CHARGE_CTRL = true;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
            untitled_P.Constant_Value - untitled_DW.delta) -
           untitled_P.Constant3_Value)) {
        untitled_DW.is_c3_untitled = untitled_IN_PACE_ATR;
        untitled_DW.temporalCounter_i1 = 0U;
        untitled_B.PACE_CHARGE_CTRL = false;
        untitled_B.ATR_PACE_CTRL = true;
        untitled_B.ATR_GND_CTRL = false;
      } else if (rtb_DigitalRead_0) {
        untitled_DW.is_c3_untitled = IN_Atrial_Refractory_Period_P_m;
        untitled_DW.temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* case IN_PACE_ATR: */
      untitled_B.PACE_CHARGE_CTRL = false;
      untitled_B.PACE_GND_CTRL = true;
      untitled_B.ATR_PACE_CTRL = true;
      untitled_B.ATR_GND_CTRL = false;
      untitled_B.Z_ATR_CTRL = false;
      untitled_B.Z_VENT_CTRL = false;
      untitled_B.VENT_GND_CTRL = false;
      untitled_B.VENT_PACE_CTRL = false;
      if (untitled_DW.temporalCounter_i1 >= (uint32_T)ceil
          (untitled_P.Constant3_Value)) {
        untitled_DW.is_c3_untitled = IN_Atrial_Refractory_Period_Pos;
        untitled_DW.temporalCounter_i1 = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(untitled_DW.obj_e.MW_DIGITALIO_HANDLE,
                     untitled_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(untitled_DW.obj_n.MW_DIGITALIO_HANDLE,
                     untitled_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S2>/Digital Write2' */
  MW_digitalIO_write(untitled_DW.obj_j.MW_DIGITALIO_HANDLE,
                     untitled_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(untitled_DW.obj_lf.MW_DIGITALIO_HANDLE,
                     untitled_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(untitled_DW.obj_h0.MW_DIGITALIO_HANDLE,
                     untitled_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(untitled_DW.obj_b.MW_DIGITALIO_HANDLE,
                     untitled_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(untitled_DW.obj_o.MW_DIGITALIO_HANDLE,
                     untitled_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(untitled_DW.obj_h.MW_DIGITALIO_HANDLE,
                     untitled_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write9' */
  MW_digitalIO_write(untitled_DW.obj_l.MW_DIGITALIO_HANDLE,
                     untitled_B.PACING_REF_PWM != 0.0);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(untitled_DW.obj_g.MW_DIGITALIO_HANDLE, false);
}

/* Model initialize function */
void untitled_initialize(void)
{
  {
    freedomk64f_DigitalRead_untit_T *obj;
    freedomk64f_DigitalWrite_unti_T *obj_0;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    untitled_DW.obj.isInitialized = 0;
    untitled_DW.obj.SampleTime = -1.0;
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.SampleTime = untitled_P.DigitalRead_SampleTime;
    obj = &untitled_DW.obj;
    untitled_DW.obj.isSetupComplete = false;
    untitled_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    untitled_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    untitled_DW.obj_e.matlabCodegenIsDeleted = true;
    untitled_DW.obj_e.isInitialized = 0;
    untitled_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_e;
    untitled_DW.obj_e.isSetupComplete = false;
    untitled_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    untitled_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    untitled_DW.obj_n.matlabCodegenIsDeleted = true;
    untitled_DW.obj_n.isInitialized = 0;
    untitled_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_n;
    untitled_DW.obj_n.isSetupComplete = false;
    untitled_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    untitled_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write2' */
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
    untitled_DW.obj_j.isInitialized = 0;
    untitled_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_j;
    untitled_DW.obj_j.isSetupComplete = false;
    untitled_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    untitled_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    untitled_DW.obj_lf.matlabCodegenIsDeleted = true;
    untitled_DW.obj_lf.isInitialized = 0;
    untitled_DW.obj_lf.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_lf;
    untitled_DW.obj_lf.isSetupComplete = false;
    untitled_DW.obj_lf.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    untitled_DW.obj_lf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    untitled_DW.obj_h0.matlabCodegenIsDeleted = true;
    untitled_DW.obj_h0.isInitialized = 0;
    untitled_DW.obj_h0.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_h0;
    untitled_DW.obj_h0.isSetupComplete = false;
    untitled_DW.obj_h0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    untitled_DW.obj_h0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    untitled_DW.obj_b.isInitialized = 0;
    untitled_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_b;
    untitled_DW.obj_b.isSetupComplete = false;
    untitled_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    untitled_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    untitled_DW.obj_o.matlabCodegenIsDeleted = true;
    untitled_DW.obj_o.isInitialized = 0;
    untitled_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_o;
    untitled_DW.obj_o.isSetupComplete = false;
    untitled_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    untitled_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
    untitled_DW.obj_h.isInitialized = 0;
    untitled_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_h;
    untitled_DW.obj_h.isSetupComplete = false;
    untitled_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    untitled_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write9' */
    untitled_DW.obj_l.matlabCodegenIsDeleted = true;
    untitled_DW.obj_l.isInitialized = 0;
    untitled_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_l;
    untitled_DW.obj_l.isSetupComplete = false;
    untitled_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
    untitled_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    untitled_DW.obj_g.matlabCodegenIsDeleted = true;
    untitled_DW.obj_g.isInitialized = 0;
    untitled_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &untitled_DW.obj_g;
    untitled_DW.obj_g.isSetupComplete = false;
    untitled_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(6U, 1);
    untitled_DW.obj_g.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(untitled_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Read' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  if (!untitled_DW.obj_e.matlabCodegenIsDeleted) {
    untitled_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_e.isInitialized == 1) &&
        untitled_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!untitled_DW.obj_n.matlabCodegenIsDeleted) {
    untitled_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_n.isInitialized == 1) &&
        untitled_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write2' */
  if (!untitled_DW.obj_j.matlabCodegenIsDeleted) {
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_j.isInitialized == 1) &&
        untitled_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  if (!untitled_DW.obj_lf.matlabCodegenIsDeleted) {
    untitled_DW.obj_lf.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_lf.isInitialized == 1) &&
        untitled_DW.obj_lf.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_lf.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  if (!untitled_DW.obj_h0.matlabCodegenIsDeleted) {
    untitled_DW.obj_h0.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_h0.isInitialized == 1) &&
        untitled_DW.obj_h0.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_h0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  if (!untitled_DW.obj_b.matlabCodegenIsDeleted) {
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_b.isInitialized == 1) &&
        untitled_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  if (!untitled_DW.obj_o.matlabCodegenIsDeleted) {
    untitled_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_o.isInitialized == 1) &&
        untitled_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_h.isInitialized == 1) &&
        untitled_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write9' */
  if (!untitled_DW.obj_l.matlabCodegenIsDeleted) {
    untitled_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_l.isInitialized == 1) &&
        untitled_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write9' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  if (!untitled_DW.obj_g.matlabCodegenIsDeleted) {
    untitled_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_g.isInitialized == 1) &&
        untitled_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write8' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
