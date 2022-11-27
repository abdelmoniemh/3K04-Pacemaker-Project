/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_1.h
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

#ifndef RTW_HEADER_Assignment_1_h_
#define RTW_HEADER_Assignment_1_h_
#ifndef Assignment_1_COMMON_INCLUDES_
#define Assignment_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_AnalogIn.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* Assignment_1_COMMON_INCLUDES_ */

#include "Assignment_1_types.h"
#include <stddef.h>
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ARP;                          /* '<Root>/ARP' */
  real_T ATR_AMPL;                     /* '<Root>/ATR_AMPL' */
  real_T ATR_PW;                       /* '<Root>/ATR_PW' */
  real_T BD;                           /* '<Root>/BD' */
  real_T VENT_AMPL;                    /* '<Root>/VENT_AMPL' */
  real_T LRL;                          /* '<Root>/LRL' */
  real_T VRP;                          /* '<Root>/VRP' */
  real_T VENT_PW;                      /* '<Root>/VENT_PW' */
  real_T PACING_REF_PWM;               /* '<S1>/Chart' */
  real_T ATR_CMP_REF_PWM;              /* '<S1>/Chart' */
  real_T VENT_CMP_REF_PWM;             /* '<S1>/Chart' */
  real_T AnalogInput;                  /* '<Root>/Analog Input' */
  boolean_T DigitalRead1;              /* '<S4>/Digital Read1' */
  boolean_T DigitalRead;               /* '<S4>/Digital Read' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S1>/Chart' */
  boolean_T Z_ATR_CTRL;                /* '<S1>/Chart' */
  boolean_T Z_VENT_CTRL;               /* '<S1>/Chart' */
  boolean_T ATR_PACE_CTRL;             /* '<S1>/Chart' */
  boolean_T VENT_PACE_CTRL;            /* '<S1>/Chart' */
  boolean_T PACE_GND_CTRL;             /* '<S1>/Chart' */
  boolean_T ATR_GND_CTRL;              /* '<S1>/Chart' */
  boolean_T VENT_GND_CTRL;             /* '<S1>/Chart' */
  boolean_T FRONTEND_CTRL;             /* '<S1>/Chart' */
} B_Assignment_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_AnalogInput_Assig_T obj; /* '<Root>/Analog Input' */
  freedomk64f_DigitalRead_Assig_T obj_o;/* '<S4>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_g;/* '<S4>/Digital Read' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<S4>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<S4>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S4>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_ki;/* '<S4>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<S4>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_d;/* '<S4>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_h;/* '<S4>/Digital Write10' */
  freedomk64f_DigitalWrite_Assi_T obj_a;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_pu;/* '<S4>/Digital Write' */
  freedomk64f_PWMOutput_Assignm_T obj_my;/* '<S4>/PWM Output2' */
  freedomk64f_PWMOutput_Assignm_T obj_hy;/* '<S4>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_mt;/* '<S4>/PWM Output' */
  real_T delta;                        /* '<S1>/Chart' */
  real_T sensing;                      /* '<S1>/Chart' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint32_T is_c3_Assignment_1;         /* '<S1>/Chart' */
  uint32_T is_AOO;                     /* '<S1>/Chart' */
  uint32_T is_VOO;                     /* '<S1>/Chart' */
  uint32_T is_AAI;                     /* '<S1>/Chart' */
  uint32_T is_VVI;                     /* '<S1>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c3_Assignment_1;   /* '<S1>/Chart' */
} DW_Assignment_1_T;

/* Parameters (default storage) */
struct P_Assignment_1_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S4>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S4>/Digital Read1'
                                        */
  real_T ARP_Value;                    /* Expression: 300
                                        * Referenced by: '<Root>/ARP'
                                        */
  real_T ATR_AMPL_Value;               /* Expression: 3.2
                                        * Referenced by: '<Root>/ATR_AMPL'
                                        */
  real_T ATR_PW_Value;                 /* Expression: 0.4
                                        * Referenced by: '<Root>/ATR_PW'
                                        */
  real_T BD_Value;                     /* Expression: 3
                                        * Referenced by: '<Root>/BD'
                                        */
  real_T VENT_AMPL_Value;              /* Expression: 3.2
                                        * Referenced by: '<Root>/VENT_AMPL'
                                        */
  real_T LRL_Value;                    /* Expression: 60
                                        * Referenced by: '<Root>/LRL'
                                        */
  real_T VRP_Value;                    /* Expression: 350
                                        * Referenced by: '<Root>/VRP'
                                        */
  real_T VENT_PW_Value;                /* Expression: 0.4
                                        * Referenced by: '<Root>/VENT_PW'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment_1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Assignment_1_T Assignment_1_P;

/* Block signals (default storage) */
extern B_Assignment_1_T Assignment_1_B;

/* Block states (default storage) */
extern DW_Assignment_1_T Assignment_1_DW;

/* Model entry point functions */
extern void Assignment_1_initialize(void);
extern void Assignment_1_step(void);
extern void Assignment_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment_1_T *const Assignment_1_M;

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
 * '<Root>' : 'Assignment_1'
 * '<S1>'   : 'Assignment_1/Pacemaker (click here)'
 * '<S2>'   : 'Assignment_1/Pacemaker (click here)/Chart'
 * '<S3>'   : 'Assignment_1/Pacemaker (click here)/Hardware Hiding'
 * '<S4>'   : 'Assignment_1/Pacemaker (click here)/Hardware Hiding/Subsystem'
 */
#endif                                 /* RTW_HEADER_Assignment_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
