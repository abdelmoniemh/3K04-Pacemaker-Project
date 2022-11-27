/*
 * Test2_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test2".
 *
 * Model version              : 1.34
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sun Nov 27 14:39:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(freedomk64f_AnalogInput_Test2_T),
  sizeof(freedomk64f_DigitalRead_Test2_T),
  sizeof(freedomk64f_DigitalWrite_Test_T),
  sizeof(freedomk64f_PWMOutput_Test2_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "freedomk64f_AnalogInput_Test2_T",
  "freedomk64f_DigitalRead_Test2_T",
  "freedomk64f_DigitalWrite_Test_T",
  "freedomk64f_PWMOutput_Test2_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Test2_B.ARP), 0, 0, 12 },

  { (char_T *)(&Test2_B.DigitalRead1), 8, 0, 11 }
  ,

  { (char_T *)(&Test2_DW.obj), 15, 0, 1 },

  { (char_T *)(&Test2_DW.obj_o), 16, 0, 2 },

  { (char_T *)(&Test2_DW.obj_m), 17, 0, 9 },

  { (char_T *)(&Test2_DW.obj_my), 18, 0, 3 },

  { (char_T *)(&Test2_DW.delta), 0, 0, 2 },

  { (char_T *)(&Test2_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&Test2_DW.is_c3_Test2), 7, 0, 6 },

  { (char_T *)(&Test2_DW.is_active_c3_Test2), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Test2_P.AnalogInput_SampleTime), 0, 0, 11 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] Test2_dt.h */
