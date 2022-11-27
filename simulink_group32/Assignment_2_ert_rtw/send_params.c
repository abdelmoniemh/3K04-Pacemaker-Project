/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
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

#include "Assignment_2_types.h"
#include "send_params_private.h"
#include "Assignment_2.h"
#include "send_params.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Assignment_2_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj);
static void Assignment_2_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<S2>/Function-Call Subsystem' */
void send_params_Init(void)
{
  /* Start for MATLABSystem: '<S7>/Serial Transmit1' */
  Assignment_2_DW.obj_lb.isInitialized = 0;
  Assignment_2_DW.obj_lb.matlabCodegenIsDeleted = false;
  Assignment_2_SystemCore_setup(&Assignment_2_DW.obj_lb);
}

/* Output and update for Simulink Function: '<S2>/Function-Call Subsystem' */
void send_params(void)
{
  uint8_T status;

  /* SignalConversion generated from: '<S7>/Input' */
  Assignment_2_B.BD = Assignment_2_B.BD_f;

  /* SignalConversion generated from: '<S7>/Input1' */
  Assignment_2_B.LRL = Assignment_2_B.LRL_i;

  /* SignalConversion generated from: '<S7>/Input2' */
  Assignment_2_B.URL = Assignment_2_B.URL_g;

  /* SignalConversion generated from: '<S7>/Input3' */
  Assignment_2_B.ATR_AMP = Assignment_2_B.ATR_AMP_n;

  /* SignalConversion generated from: '<S7>/Input4' */
  Assignment_2_B.ATR_PW = Assignment_2_B.ATR_PW_i;

  /* SignalConversion generated from: '<S7>/Input5' */
  Assignment_2_B.ATR_Sens = Assignment_2_B.ATR_Sens_a;

  /* SignalConversion generated from: '<S7>/Input6' */
  Assignment_2_B.VENT_AMP = Assignment_2_B.VENT_AMP_k;

  /* SignalConversion generated from: '<S7>/Input7' */
  Assignment_2_B.VENT_PW = Assignment_2_B.VENT_PW_n;

  /* SignalConversion generated from: '<S7>/Input8' */
  Assignment_2_B.VENT_Sens = Assignment_2_B.VENT_Sens_l;

  /* SignalConversion generated from: '<S7>/Input9' */
  Assignment_2_B.VRP = Assignment_2_B.VRP_d;

  /* SignalConversion generated from: '<S7>/Input10' */
  Assignment_2_B.ARP = Assignment_2_B.ARP_e;

  /* SignalConversion generated from: '<S7>/Input11' */
  Assignment_2_B.MAX_SENS_RATE = Assignment_2_B.MAX_SENS_RATE_k;

  /* SignalConversion generated from: '<S7>/Input12' */
  Assignment_2_B.FixedAVdelay = Assignment_2_B.FixedAVdelay_m;

  /* SignalConversion generated from: '<S7>/Input13' */
  Assignment_2_B.DynamicAVdelay = Assignment_2_B.DynamicAVdelay_j;

  /* SignalConversion generated from: '<S7>/Input14' */
  Assignment_2_B.AVdelayOffset = Assignment_2_B.AVdelayOffset_m;

  /* SignalConversion generated from: '<S7>/Input15' */
  Assignment_2_B.PVARP = Assignment_2_B.PVARP_p;

  /* SignalConversion generated from: '<S7>/Input16' */
  Assignment_2_B.PVARPextenson = Assignment_2_B.PVARPextenson_k;

  /* SignalConversion generated from: '<S7>/Input17' */
  Assignment_2_B.HYS = Assignment_2_B.HYS_m;

  /* SignalConversion generated from: '<S7>/Input18' */
  Assignment_2_B.RATE_SMOOTH = Assignment_2_B.RATE_SMOOTH_k;

  /* SignalConversion generated from: '<S7>/Input19' */
  Assignment_2_B.REAC_TIME = Assignment_2_B.REAC_TIME_g;

  /* SignalConversion generated from: '<S7>/Input20' */
  Assignment_2_B.RESP_FAC = Assignment_2_B.RESP_FAC_g;

  /* SignalConversion generated from: '<S7>/Input21' */
  Assignment_2_B.RecoveryTime = Assignment_2_B.RecoveryTime_d;

  /* SignalConversion generated from: '<S7>/Input22' */
  Assignment_2_B.ATRmode = Assignment_2_B.ATRmode_m;

  /* SignalConversion generated from: '<S7>/Input23' */
  Assignment_2_B.ATRtime = Assignment_2_B.ATRtime_g;

  /* SignalConversion generated from: '<S7>/Input24' */
  Assignment_2_B.ATRduration = Assignment_2_B.ATRduration_l;

  /* SignalConversion generated from: '<S7>/Input25' */
  Assignment_2_B.TmpLatchAtInput25Outport1 = Assignment_2_B.DigitalRead2;

  /* SignalConversion generated from: '<S7>/Input26' */
  Assignment_2_B.TmpLatchAtInput26Outport1 = Assignment_2_B.DigitalRead3;

  /* S-Function (any2byte): '<S7>/Byte Pack' */

  /* Pack: <S7>/Byte Pack */
  (void) memcpy(&Assignment_2_B.BytePack[0], &Assignment_2_B.BD,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack1' */

  /* Pack: <S7>/Byte Pack1 */
  (void) memcpy(&Assignment_2_B.BytePack1[0], &Assignment_2_B.LRL,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack2' */

  /* Pack: <S7>/Byte Pack2 */
  (void) memcpy(&Assignment_2_B.BytePack2[0], &Assignment_2_B.URL,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack3' */

  /* Pack: <S7>/Byte Pack3 */
  (void) memcpy(&Assignment_2_B.BytePack3[0], &Assignment_2_B.ATR_AMP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack4' */

  /* Pack: <S7>/Byte Pack4 */
  (void) memcpy(&Assignment_2_B.BytePack4[0], &Assignment_2_B.ATR_PW,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack5' */

  /* Pack: <S7>/Byte Pack5 */
  (void) memcpy(&Assignment_2_B.BytePack5[0], &Assignment_2_B.ATR_Sens,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack6' */

  /* Pack: <S7>/Byte Pack6 */
  (void) memcpy(&Assignment_2_B.BytePack6[0], &Assignment_2_B.VENT_AMP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack7' */

  /* Pack: <S7>/Byte Pack7 */
  (void) memcpy(&Assignment_2_B.BytePack7[0], &Assignment_2_B.VENT_PW,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack8' */

  /* Pack: <S7>/Byte Pack8 */
  (void) memcpy(&Assignment_2_B.BytePack8[0], &Assignment_2_B.VENT_Sens,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack9' */

  /* Pack: <S7>/Byte Pack9 */
  (void) memcpy(&Assignment_2_B.BytePack9[0], &Assignment_2_B.VRP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack10' */

  /* Pack: <S7>/Byte Pack10 */
  (void) memcpy(&Assignment_2_B.BytePack10[0], &Assignment_2_B.ARP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack11' */

  /* Pack: <S7>/Byte Pack11 */
  (void) memcpy(&Assignment_2_B.BytePack11[0], &Assignment_2_B.MAX_SENS_RATE,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack12' */

  /* Pack: <S7>/Byte Pack12 */
  (void) memcpy(&Assignment_2_B.BytePack12[0], &Assignment_2_B.FixedAVdelay,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack13' */

  /* Pack: <S7>/Byte Pack13 */
  (void) memcpy(&Assignment_2_B.BytePack13[0], &Assignment_2_B.DynamicAVdelay,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack14' */

  /* Pack: <S7>/Byte Pack14 */
  (void) memcpy(&Assignment_2_B.BytePack14[0], &Assignment_2_B.AVdelayOffset,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack15' */

  /* Pack: <S7>/Byte Pack15 */
  (void) memcpy(&Assignment_2_B.BytePack15[0], &Assignment_2_B.PVARP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack16' */

  /* Pack: <S7>/Byte Pack16 */
  (void) memcpy(&Assignment_2_B.BytePack16[0], &Assignment_2_B.PVARPextenson,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack17' */

  /* Pack: <S7>/Byte Pack17 */
  (void) memcpy(&Assignment_2_B.BytePack17[0], &Assignment_2_B.HYS,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack18' */

  /* Pack: <S7>/Byte Pack18 */
  (void) memcpy(&Assignment_2_B.BytePack18[0], &Assignment_2_B.RATE_SMOOTH,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack19' */

  /* Pack: <S7>/Byte Pack19 */
  (void) memcpy(&Assignment_2_B.BytePack19[0], &Assignment_2_B.REAC_TIME,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack20' */

  /* Pack: <S7>/Byte Pack20 */
  (void) memcpy(&Assignment_2_B.BytePack20[0], &Assignment_2_B.RESP_FAC,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack21' */

  /* Pack: <S7>/Byte Pack21 */
  (void) memcpy(&Assignment_2_B.BytePack21[0], &Assignment_2_B.RecoveryTime,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack22' */

  /* Pack: <S7>/Byte Pack22 */
  (void) memcpy(&Assignment_2_B.BytePack22[0], &Assignment_2_B.ATRmode,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack23' */

  /* Pack: <S7>/Byte Pack23 */
  (void) memcpy(&Assignment_2_B.BytePack23[0], &Assignment_2_B.ATRtime,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack24' */

  /* Pack: <S7>/Byte Pack24 */
  (void) memcpy(&Assignment_2_B.BytePack24[0], &Assignment_2_B.ATRduration,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack25' */

  /* Pack: <S7>/Byte Pack25 */
  (void) memcpy(&Assignment_2_B.BytePack25,
                &Assignment_2_B.TmpLatchAtInput25Outport1,
                1);

  /* S-Function (any2byte): '<S7>/Byte Pack26' */

  /* Pack: <S7>/Byte Pack26 */
  (void) memcpy(&Assignment_2_B.BytePack26,
                &Assignment_2_B.TmpLatchAtInput26Outport1,
                1);

  /* SignalConversion generated from: '<S7>/Serial Transmit1' */
  Assignment_2_B.TmpSignalConversionAtSerial[0] = Assignment_2_B.BytePack[0];
  Assignment_2_B.TmpSignalConversionAtSerial[4] = Assignment_2_B.BytePack1[0];
  Assignment_2_B.TmpSignalConversionAtSerial[8] = Assignment_2_B.BytePack2[0];
  Assignment_2_B.TmpSignalConversionAtSerial[12] = Assignment_2_B.BytePack3[0];
  Assignment_2_B.TmpSignalConversionAtSerial[16] = Assignment_2_B.BytePack4[0];
  Assignment_2_B.TmpSignalConversionAtSerial[20] = Assignment_2_B.BytePack5[0];
  Assignment_2_B.TmpSignalConversionAtSerial[24] = Assignment_2_B.BytePack6[0];
  Assignment_2_B.TmpSignalConversionAtSerial[28] = Assignment_2_B.BytePack7[0];
  Assignment_2_B.TmpSignalConversionAtSerial[32] = Assignment_2_B.BytePack8[0];
  Assignment_2_B.TmpSignalConversionAtSerial[36] = Assignment_2_B.BytePack9[0];
  Assignment_2_B.TmpSignalConversionAtSerial[40] = Assignment_2_B.BytePack10[0];
  Assignment_2_B.TmpSignalConversionAtSerial[44] = Assignment_2_B.BytePack11[0];
  Assignment_2_B.TmpSignalConversionAtSerial[48] = Assignment_2_B.BytePack12[0];
  Assignment_2_B.TmpSignalConversionAtSerial[52] = Assignment_2_B.BytePack13[0];
  Assignment_2_B.TmpSignalConversionAtSerial[56] = Assignment_2_B.BytePack14[0];
  Assignment_2_B.TmpSignalConversionAtSerial[60] = Assignment_2_B.BytePack15[0];
  Assignment_2_B.TmpSignalConversionAtSerial[64] = Assignment_2_B.BytePack16[0];
  Assignment_2_B.TmpSignalConversionAtSerial[68] = Assignment_2_B.BytePack17[0];
  Assignment_2_B.TmpSignalConversionAtSerial[72] = Assignment_2_B.BytePack18[0];
  Assignment_2_B.TmpSignalConversionAtSerial[76] = Assignment_2_B.BytePack19[0];
  Assignment_2_B.TmpSignalConversionAtSerial[80] = Assignment_2_B.BytePack20[0];
  Assignment_2_B.TmpSignalConversionAtSerial[84] = Assignment_2_B.BytePack21[0];
  Assignment_2_B.TmpSignalConversionAtSerial[88] = Assignment_2_B.BytePack22[0];
  Assignment_2_B.TmpSignalConversionAtSerial[92] = Assignment_2_B.BytePack23[0];
  Assignment_2_B.TmpSignalConversionAtSerial[96] = Assignment_2_B.BytePack24[0];
  Assignment_2_B.TmpSignalConversionAtSerial[1] = Assignment_2_B.BytePack[1];
  Assignment_2_B.TmpSignalConversionAtSerial[5] = Assignment_2_B.BytePack1[1];
  Assignment_2_B.TmpSignalConversionAtSerial[9] = Assignment_2_B.BytePack2[1];
  Assignment_2_B.TmpSignalConversionAtSerial[13] = Assignment_2_B.BytePack3[1];
  Assignment_2_B.TmpSignalConversionAtSerial[17] = Assignment_2_B.BytePack4[1];
  Assignment_2_B.TmpSignalConversionAtSerial[21] = Assignment_2_B.BytePack5[1];
  Assignment_2_B.TmpSignalConversionAtSerial[25] = Assignment_2_B.BytePack6[1];
  Assignment_2_B.TmpSignalConversionAtSerial[29] = Assignment_2_B.BytePack7[1];
  Assignment_2_B.TmpSignalConversionAtSerial[33] = Assignment_2_B.BytePack8[1];
  Assignment_2_B.TmpSignalConversionAtSerial[37] = Assignment_2_B.BytePack9[1];
  Assignment_2_B.TmpSignalConversionAtSerial[41] = Assignment_2_B.BytePack10[1];
  Assignment_2_B.TmpSignalConversionAtSerial[45] = Assignment_2_B.BytePack11[1];
  Assignment_2_B.TmpSignalConversionAtSerial[49] = Assignment_2_B.BytePack12[1];
  Assignment_2_B.TmpSignalConversionAtSerial[53] = Assignment_2_B.BytePack13[1];
  Assignment_2_B.TmpSignalConversionAtSerial[57] = Assignment_2_B.BytePack14[1];
  Assignment_2_B.TmpSignalConversionAtSerial[61] = Assignment_2_B.BytePack15[1];
  Assignment_2_B.TmpSignalConversionAtSerial[65] = Assignment_2_B.BytePack16[1];
  Assignment_2_B.TmpSignalConversionAtSerial[69] = Assignment_2_B.BytePack17[1];
  Assignment_2_B.TmpSignalConversionAtSerial[73] = Assignment_2_B.BytePack18[1];
  Assignment_2_B.TmpSignalConversionAtSerial[77] = Assignment_2_B.BytePack19[1];
  Assignment_2_B.TmpSignalConversionAtSerial[81] = Assignment_2_B.BytePack20[1];
  Assignment_2_B.TmpSignalConversionAtSerial[85] = Assignment_2_B.BytePack21[1];
  Assignment_2_B.TmpSignalConversionAtSerial[89] = Assignment_2_B.BytePack22[1];
  Assignment_2_B.TmpSignalConversionAtSerial[93] = Assignment_2_B.BytePack23[1];
  Assignment_2_B.TmpSignalConversionAtSerial[97] = Assignment_2_B.BytePack24[1];
  Assignment_2_B.TmpSignalConversionAtSerial[2] = Assignment_2_B.BytePack[2];
  Assignment_2_B.TmpSignalConversionAtSerial[6] = Assignment_2_B.BytePack1[2];
  Assignment_2_B.TmpSignalConversionAtSerial[10] = Assignment_2_B.BytePack2[2];
  Assignment_2_B.TmpSignalConversionAtSerial[14] = Assignment_2_B.BytePack3[2];
  Assignment_2_B.TmpSignalConversionAtSerial[18] = Assignment_2_B.BytePack4[2];
  Assignment_2_B.TmpSignalConversionAtSerial[22] = Assignment_2_B.BytePack5[2];
  Assignment_2_B.TmpSignalConversionAtSerial[26] = Assignment_2_B.BytePack6[2];
  Assignment_2_B.TmpSignalConversionAtSerial[30] = Assignment_2_B.BytePack7[2];
  Assignment_2_B.TmpSignalConversionAtSerial[34] = Assignment_2_B.BytePack8[2];
  Assignment_2_B.TmpSignalConversionAtSerial[38] = Assignment_2_B.BytePack9[2];
  Assignment_2_B.TmpSignalConversionAtSerial[42] = Assignment_2_B.BytePack10[2];
  Assignment_2_B.TmpSignalConversionAtSerial[46] = Assignment_2_B.BytePack11[2];
  Assignment_2_B.TmpSignalConversionAtSerial[50] = Assignment_2_B.BytePack12[2];
  Assignment_2_B.TmpSignalConversionAtSerial[54] = Assignment_2_B.BytePack13[2];
  Assignment_2_B.TmpSignalConversionAtSerial[58] = Assignment_2_B.BytePack14[2];
  Assignment_2_B.TmpSignalConversionAtSerial[62] = Assignment_2_B.BytePack15[2];
  Assignment_2_B.TmpSignalConversionAtSerial[66] = Assignment_2_B.BytePack16[2];
  Assignment_2_B.TmpSignalConversionAtSerial[70] = Assignment_2_B.BytePack17[2];
  Assignment_2_B.TmpSignalConversionAtSerial[74] = Assignment_2_B.BytePack18[2];
  Assignment_2_B.TmpSignalConversionAtSerial[78] = Assignment_2_B.BytePack19[2];
  Assignment_2_B.TmpSignalConversionAtSerial[82] = Assignment_2_B.BytePack20[2];
  Assignment_2_B.TmpSignalConversionAtSerial[86] = Assignment_2_B.BytePack21[2];
  Assignment_2_B.TmpSignalConversionAtSerial[90] = Assignment_2_B.BytePack22[2];
  Assignment_2_B.TmpSignalConversionAtSerial[94] = Assignment_2_B.BytePack23[2];
  Assignment_2_B.TmpSignalConversionAtSerial[98] = Assignment_2_B.BytePack24[2];
  Assignment_2_B.TmpSignalConversionAtSerial[3] = Assignment_2_B.BytePack[3];
  Assignment_2_B.TmpSignalConversionAtSerial[7] = Assignment_2_B.BytePack1[3];
  Assignment_2_B.TmpSignalConversionAtSerial[11] = Assignment_2_B.BytePack2[3];
  Assignment_2_B.TmpSignalConversionAtSerial[15] = Assignment_2_B.BytePack3[3];
  Assignment_2_B.TmpSignalConversionAtSerial[19] = Assignment_2_B.BytePack4[3];
  Assignment_2_B.TmpSignalConversionAtSerial[23] = Assignment_2_B.BytePack5[3];
  Assignment_2_B.TmpSignalConversionAtSerial[27] = Assignment_2_B.BytePack6[3];
  Assignment_2_B.TmpSignalConversionAtSerial[31] = Assignment_2_B.BytePack7[3];
  Assignment_2_B.TmpSignalConversionAtSerial[35] = Assignment_2_B.BytePack8[3];
  Assignment_2_B.TmpSignalConversionAtSerial[39] = Assignment_2_B.BytePack9[3];
  Assignment_2_B.TmpSignalConversionAtSerial[43] = Assignment_2_B.BytePack10[3];
  Assignment_2_B.TmpSignalConversionAtSerial[47] = Assignment_2_B.BytePack11[3];
  Assignment_2_B.TmpSignalConversionAtSerial[51] = Assignment_2_B.BytePack12[3];
  Assignment_2_B.TmpSignalConversionAtSerial[55] = Assignment_2_B.BytePack13[3];
  Assignment_2_B.TmpSignalConversionAtSerial[59] = Assignment_2_B.BytePack14[3];
  Assignment_2_B.TmpSignalConversionAtSerial[63] = Assignment_2_B.BytePack15[3];
  Assignment_2_B.TmpSignalConversionAtSerial[67] = Assignment_2_B.BytePack16[3];
  Assignment_2_B.TmpSignalConversionAtSerial[71] = Assignment_2_B.BytePack17[3];
  Assignment_2_B.TmpSignalConversionAtSerial[75] = Assignment_2_B.BytePack18[3];
  Assignment_2_B.TmpSignalConversionAtSerial[79] = Assignment_2_B.BytePack19[3];
  Assignment_2_B.TmpSignalConversionAtSerial[83] = Assignment_2_B.BytePack20[3];
  Assignment_2_B.TmpSignalConversionAtSerial[87] = Assignment_2_B.BytePack21[3];
  Assignment_2_B.TmpSignalConversionAtSerial[91] = Assignment_2_B.BytePack22[3];
  Assignment_2_B.TmpSignalConversionAtSerial[95] = Assignment_2_B.BytePack23[3];
  Assignment_2_B.TmpSignalConversionAtSerial[99] = Assignment_2_B.BytePack24[3];
  Assignment_2_B.TmpSignalConversionAtSerial[100] = Assignment_2_B.BytePack25;
  Assignment_2_B.TmpSignalConversionAtSerial[101] = Assignment_2_B.BytePack26;

  /* MATLABSystem: '<S7>/Serial Transmit1' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Assignment_2_B.TxDataLocChar[0], (void *)
           &Assignment_2_B.TmpSignalConversionAtSerial[0], (uint32_T)((size_t)
            102 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(Assignment_2_DW.obj_lb.MW_SCIHANDLE,
      &Assignment_2_B.TxDataLocChar[0], 102U);
  }

  /* End of MATLABSystem: '<S7>/Serial Transmit1' */
}

/* Termination for Simulink Function: '<S2>/Function-Call Subsystem' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S7>/Serial Transmit1' */
  if (!Assignment_2_DW.obj_lb.matlabCodegenIsDeleted) {
    Assignment_2_DW.obj_lb.matlabCodegenIsDeleted = true;
    if ((Assignment_2_DW.obj_lb.isInitialized == 1) &&
        Assignment_2_DW.obj_lb.isSetupComplete) {
      MW_SCI_Close(Assignment_2_DW.obj_lb.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
