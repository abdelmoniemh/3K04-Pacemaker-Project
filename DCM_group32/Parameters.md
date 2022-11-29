BradycardiaOperatingMode is represented as a string so it is easily sliceable and can therefore be seperated
LowerRateLimit is represented as a integer
UpperRateLimit is represented as a integer
AtrialAmplitude is represented float
AtrialPulseWidth is represented float
AtrialSensitivity is represented float
VentricularAmplitude is represented float
VentricularPulseWidth is represented float
VentricularSensitivity is represented float
VRP is represented as a integer
ARP is represented as a integer
MaxSensorRate is represented as a integer
FixedAVdelay is represented as a integer
DynamicAVdelay is represented as a integer
AVdelayOffset is represented as a integer
PVARP is represented as a integer
PVARPextension is represented as a integer
Hysteresis is represented as a integer
RateSmoothing is represented as a integer
ReactionTime is represented as a integer
ResponseFactor is represented as a integer
RecoveryTime is represented as a integer
ActivityThreshold is represented as a integer
ATRmode is represented as a integer
ATRtime is represented as a integer
ATRduration is represented as a integer

We can guarantee that these parameters are the same on the gui and the pacemaker, since we can echo the parameters on the board and set the dcm to display them
at which point any descrepencies can be identified by the user.
