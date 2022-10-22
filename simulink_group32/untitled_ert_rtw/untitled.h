/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
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

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/Chart' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/Chart' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/Chart' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/Chart' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/Chart' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/Chart' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/Chart' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/Chart' */
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_untit_T obj; /* '<S2>/Digital Read' */
  freedomk64f_DigitalWrite_unti_T obj_l;/* '<S2>/Digital Write9' */
  freedomk64f_DigitalWrite_unti_T obj_g;/* '<S2>/Digital Write8' */
  freedomk64f_DigitalWrite_unti_T obj_h;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_unti_T obj_o;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_unti_T obj_b;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_unti_T obj_h0;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_unti_T obj_lf;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_unti_T obj_j;/* '<S2>/Digital Write2' */
  freedomk64f_DigitalWrite_unti_T obj_n;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_unti_T obj_e;/* '<S2>/Digital Write' */
  real_T delta;                        /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_untitled;       /* '<Root>/Chart' */
  uint8_T is_c3_untitled;              /* '<Root>/Chart' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 3.5
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: .4
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: .4
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Chart'
 * '<S2>'   : 'untitled/Subsystem'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
