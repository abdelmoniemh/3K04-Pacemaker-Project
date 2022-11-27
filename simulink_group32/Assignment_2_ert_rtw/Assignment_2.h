/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment_2.h
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

#ifndef RTW_HEADER_Assignment_2_h_
#define RTW_HEADER_Assignment_2_h_
#ifndef Assignment_2_COMMON_INCLUDES_
#define Assignment_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#endif                                 /* Assignment_2_COMMON_INCLUDES_ */

#include "Assignment_2_types.h"
#include <stddef.h>
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T TxDataLocChar[102];
  uint8_T TmpSignalConversionAtSerial[102];
  uint8_T RxData[102];
  uint8_T RxDataLocChar[102];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  real_T ATR_CMP_REF_PWM;              /* '<S1>/Chart' */
  real_T VENT_CMP_REF_PWM;             /* '<S1>/Chart' */
  real32_T ATR_AMP;
  real32_T ATR_PW;
  real32_T ATR_Sens;
  real32_T VENT_AMP;
  real32_T VENT_PW;
  real32_T VENT_Sens;
  real32_T ATR_AMP_n;                  /* '<S2>/COMIN' */
  real32_T ATR_PW_i;                   /* '<S2>/COMIN' */
  real32_T ATR_Sens_a;                 /* '<S2>/COMIN' */
  real32_T VENT_AMP_k;                 /* '<S2>/COMIN' */
  real32_T VENT_PW_n;                  /* '<S2>/COMIN' */
  real32_T VENT_Sens_l;                /* '<S2>/COMIN' */
  real32_T PACING_REF_PWM;             /* '<S1>/Chart' */
  int32_T BD;
  int32_T LRL;
  int32_T URL;
  int32_T VRP;
  int32_T ARP;
  int32_T MAX_SENS_RATE;
  int32_T FixedAVdelay;
  int32_T DynamicAVdelay;
  int32_T AVdelayOffset;
  int32_T PVARP;
  int32_T PVARPextenson;
  int32_T HYS;
  int32_T RATE_SMOOTH;
  int32_T REAC_TIME;
  int32_T RESP_FAC;
  int32_T RecoveryTime;
  int32_T ATRmode;
  int32_T ATRtime;
  int32_T ATRduration;
  int32_T BD_f;                        /* '<S2>/COMIN' */
  int32_T LRL_i;                       /* '<S2>/COMIN' */
  int32_T URL_g;                       /* '<S2>/COMIN' */
  int32_T VRP_d;                       /* '<S2>/COMIN' */
  int32_T ARP_e;                       /* '<S2>/COMIN' */
  int32_T MAX_SENS_RATE_k;             /* '<S2>/COMIN' */
  int32_T FixedAVdelay_m;              /* '<S2>/COMIN' */
  int32_T DynamicAVdelay_j;            /* '<S2>/COMIN' */
  int32_T AVdelayOffset_m;             /* '<S2>/COMIN' */
  int32_T PVARP_p;                     /* '<S2>/COMIN' */
  int32_T PVARPextenson_k;             /* '<S2>/COMIN' */
  int32_T HYS_m;                       /* '<S2>/COMIN' */
  int32_T RATE_SMOOTH_k;               /* '<S2>/COMIN' */
  int32_T REAC_TIME_g;                 /* '<S2>/COMIN' */
  int32_T RESP_FAC_g;                  /* '<S2>/COMIN' */
  int32_T RecoveryTime_d;              /* '<S2>/COMIN' */
  int32_T ATRmode_m;                   /* '<S2>/COMIN' */
  int32_T ATRtime_g;                   /* '<S2>/COMIN' */
  int32_T ATRduration_l;               /* '<S2>/COMIN' */
  uint8_T BytePack[4];                 /* '<S7>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S7>/Byte Pack1' */
  uint8_T BytePack2[4];                /* '<S7>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S7>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S7>/Byte Pack4' */
  uint8_T BytePack5[4];                /* '<S7>/Byte Pack5' */
  uint8_T BytePack6[4];                /* '<S7>/Byte Pack6' */
  uint8_T BytePack7[4];                /* '<S7>/Byte Pack7' */
  uint8_T BytePack8[4];                /* '<S7>/Byte Pack8' */
  uint8_T BytePack9[4];                /* '<S7>/Byte Pack9' */
  uint8_T BytePack10[4];               /* '<S7>/Byte Pack10' */
  uint8_T BytePack11[4];               /* '<S7>/Byte Pack11' */
  uint8_T BytePack12[4];               /* '<S7>/Byte Pack12' */
  uint8_T BytePack13[4];               /* '<S7>/Byte Pack13' */
  uint8_T BytePack14[4];               /* '<S7>/Byte Pack14' */
  uint8_T BytePack15[4];               /* '<S7>/Byte Pack15' */
  uint8_T BytePack16[4];               /* '<S7>/Byte Pack16' */
  uint8_T BytePack17[4];               /* '<S7>/Byte Pack17' */
  uint8_T BytePack18[4];               /* '<S7>/Byte Pack18' */
  uint8_T BytePack19[4];               /* '<S7>/Byte Pack19' */
  uint8_T BytePack20[4];               /* '<S7>/Byte Pack20' */
  uint8_T BytePack21[4];               /* '<S7>/Byte Pack21' */
  uint8_T BytePack22[4];               /* '<S7>/Byte Pack22' */
  uint8_T BytePack23[4];               /* '<S7>/Byte Pack23' */
  uint8_T BytePack24[4];               /* '<S7>/Byte Pack24' */
  uint8_T BytePack25;                  /* '<S7>/Byte Pack25' */
  uint8_T BytePack26;                  /* '<S7>/Byte Pack26' */
  boolean_T TmpLatchAtInput25Outport1;
  boolean_T TmpLatchAtInput26Outport1;
  boolean_T DigitalRead3;              /* '<S5>/Digital Read3' */
  boolean_T DigitalRead2;              /* '<S5>/Digital Read2' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S1>/Chart' */
  boolean_T Z_ATR_CTRL;                /* '<S1>/Chart' */
  boolean_T Z_VENT_CTRL;               /* '<S1>/Chart' */
  boolean_T ATR_PACE_CTRL;             /* '<S1>/Chart' */
  boolean_T VENT_PACE_CTRL;            /* '<S1>/Chart' */
  boolean_T PACE_GND_CTRL;             /* '<S1>/Chart' */
  boolean_T ATR_GND_CTRL;              /* '<S1>/Chart' */
  boolean_T VENT_GND_CTRL;             /* '<S1>/Chart' */
  boolean_T FRONTEND_CTRL;             /* '<S1>/Chart' */
  boolean_T LED;                       /* '<S1>/Chart' */
  boolean_T LED1;                      /* '<S1>/Chart' */
  boolean_T LED2;                      /* '<S1>/Chart' */
} B_Assignment_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Assig_T obj; /* '<S5>/Digital Read3' */
  freedomk64f_DigitalRead_Assig_T obj_p;/* '<S5>/Digital Read2' */
  freedomk64f_DigitalRead_Assig_T obj_o;/* '<S5>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_g;/* '<S5>/Digital Read' */
  freedomk64f_SCIRead_Assignmen_T obj_l;/* '<S2>/Serial Receive' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<S5>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<S5>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S5>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_ki;/* '<S5>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_p4;/* '<S5>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_d;/* '<S5>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_h;/* '<S5>/Digital Write10' */
  freedomk64f_DigitalWrite_Assi_T obj_a;/* '<S5>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_pu;/* '<S5>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_i;/* '<S1>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_f;/* '<S1>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_pj;/* '<S1>/Digital Write' */
  freedomk64f_PWMOutput_Assignm_T obj_my;/* '<S5>/PWM Output2' */
  freedomk64f_PWMOutput_Assignm_T obj_hy;/* '<S5>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_mt;/* '<S5>/PWM Output' */
  freedomk64f_SCIWrite_Assignme_T obj_lb;/* '<S7>/Serial Transmit1' */
  real_T sensing;                      /* '<S1>/Chart' */
  real32_T delta;                      /* '<S1>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c1_Assignment_2;   /* '<S2>/COMIN' */
  uint8_T is_c1_Assignment_2;          /* '<S2>/COMIN' */
  uint8_T is_active_c3_Assignment_2;   /* '<S1>/Chart' */
  uint8_T is_c3_Assignment_2;          /* '<S1>/Chart' */
  uint8_T is_AOO;                      /* '<S1>/Chart' */
  uint8_T is_VOO;                      /* '<S1>/Chart' */
  uint8_T is_AAI;                      /* '<S1>/Chart' */
  uint8_T is_VVI;                      /* '<S1>/Chart' */
} DW_Assignment_2_T;

/* Parameters (default storage) */
struct P_Assignment_2_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read1'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read2'
                                        */
  real_T DigitalRead3_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read3'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S2>/Serial Receive'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment_2_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Assignment_2_T Assignment_2_P;

/* Block signals (default storage) */
extern B_Assignment_2_T Assignment_2_B;

/* Block states (default storage) */
extern DW_Assignment_2_T Assignment_2_DW;

/* Model entry point functions */
extern void Assignment_2_initialize(void);
extern void Assignment_2_step(void);
extern void Assignment_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment_2_T *const Assignment_2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'Assignment_2'
 * '<S1>'   : 'Assignment_2/Pacemaker (click here)'
 * '<S2>'   : 'Assignment_2/Serial Communication'
 * '<S3>'   : 'Assignment_2/Pacemaker (click here)/Chart'
 * '<S4>'   : 'Assignment_2/Pacemaker (click here)/Hardware Hiding'
 * '<S5>'   : 'Assignment_2/Pacemaker (click here)/Hardware Hiding/Subsystem'
 * '<S6>'   : 'Assignment_2/Serial Communication/COMIN'
 * '<S7>'   : 'Assignment_2/Serial Communication/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_Assignment_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
