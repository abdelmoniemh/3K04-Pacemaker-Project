from ssl import VerifyFlags
from passlib.hash import sha256_crypt
import json
import os
import serial
import struct

#if on linux or macos make sure "TMPDIR" env variable is set
#os.environ["TMPDIR"] = "/home/tempdir" #for linux
class user():
    appUserDirectory = os.environ["TMP"] +"\\3K04-GROUP32-tmp-directory\\users" if os.name=="nt" \
            else os.environ["TMPDIR"] + "/3K04-GROUP32-tmp-directory/users"
    print(appUserDirectory)
    # get instanceCount from user directory/db
    if not os.path.exists(appUserDirectory):
            os.makedirs(appUserDirectory)
    
    instanceCount = len([file for file in os.listdir(appUserDirectory) if file.endswith(".json")])

    def __init__(self, username, password, subDirectory=""):
        self.createAttributes(username, password)
        self.subDirectory = subDirectory
        self.appUserDirectory += self.subDirectory
        userPath = os.path.join(self.appUserDirectory, f"{username}.json")
        if (not os.path.exists(userPath)):       
            if (self.instanceCount + 1 > 10):
                raise ValueError #too many users to create a new one, catch and handle in gui code
            else:
                self.instanceCount += 1
                self.serialize()
        else:
            self.deserialize(username, password)

    def createAttributes(self, username, password):
        self.username = username
        self.password = sha256_crypt.hash(password)
        
        # initialize programmable parameters
        # TODO: add rest of programmable parameters and their getters/setters
        self.BradycardiaOperatingMode = "DDDO"
        self.LowerRateLimit = 60
        self.UpperRateLimit = 120
        self.AtrialAmplitude = 3.5
        self.AtrialPulseWidth = 0.4
        self.AtrialSensitivity = 0.5
        self.VentricularAmplitude = 3.5
        self.VentricularPulseWidth = 0.4
        self.VentricularSensitivity = 0.5
        self.VRP = 320
        self.ARP = 250
        self.MaxSensorRate = 100
        self.FixedAVdelay = 150
        self.DynamicAVdelay = 60
        self.AVdelayOffset = -55
        self.PVARP = 300
        self.PVARPextension = 200
        self.Hysteresis = 60
        self.RateSmoothing = 12
        self.ReationTime = 25
        self.ResponseFactor = 10
        self.RecoveryTime = 8
        self.ActivityThreshold = "Med"
        self.ATRmode = 1
        self.ATRtime = 3 
        self.ATRduration = 70
        
    def serialize(self):
        # store user data in txt files in directory/db
        toBeSerialized = dict()
        for attr, value in self.__dict__.items():
            toBeSerialized[attr] = value

        jsonAsString = json.dumps(toBeSerialized)
        if not os.path.exists(self.appUserDirectory):
            os.makedirs(self.appUserDirectory)
        
        with open(os.path.join(self.appUserDirectory, f"{self.username}.json"), "w") as file:
            file.write(jsonAsString)

    def deserialize(self, username, password):
        with open(os.path.join(self.appUserDirectory, f"{self.username}.json"), "r") as file:
            userAttributes = json.load(file)
            for attr, value in self.__dict__.items():
                self.__dict__[attr] = userAttributes[attr]
            if not sha256_crypt.verify(password, self.password):
                raise KeyError #wrong password, catch and retry on gui side
        self.instanceCount = len([file for file in os.listdir(self.appUserDirectory) if file.endswith(".json")])

    def setParameterOnBoard(self, parameterName, parameter):
        typeDictionary = {
            float : "f",
            int : "i"
        }
        parameterDictionary = {
            "BradycardiaOperatingMode": b'x\00000',
            "LowerRateLimit": b'x\00001',
            "UpperRateLimit": b'x\00010',
            "AtrialAmplitude": b'x\00011',
            "AtrialPulseWidth":b'x\00100',
            "AtrialSensitivity":b'x\00101',
            "VentricularAmplitude":b'x\00110',
            "VentricularPulseWidth":b'x\00111',
            "VentricularSensitivity":b'x\01000',
            "VRP":b'x\01001',
            "ARP":b'x\01010',
            "MaxSensorRate":b'x\01011',
            "FixedAVdelay":b'x\01100',
            "DynamicAVdelay":b'x\01101',
            "AVdelayOffset":b'x\01110',
            "PVARP":b'x\01111',
            "PVARPextension":b'x\10000',
            "Hysteresis":b'x\10001',
            "RateSmoothing":b'x\10010',
            "ReationTime":b'x\10011',
            "ResponseFactor":b'x\10100',
        }
        toWrite = b'x\16' + b'x\22' + b'x\55'
        #toWrite = bytes()
        if parameterName not in parameterDictionary.keys():
            return False
        if type(parameter) == str and parameterName == "BradycardiaOperatingMode":
            toWrite += parameterDictionary[parameterName]
            for char in parameter:
                toWrite += struct.pack("c", bytes(char.encode()))
            print(f"parameterName = {parameterName}, {toWrite}")
        else:
            toWrite += parameterDictionary[parameterName] + struct.pack(typeDictionary[type(parameter)], parameter)
            print(f"parameterName = {parameterName}, {toWrite}")
        with serial.Serial('COM3',
                     baudrate=115200,
                     bytesize=serial.EIGHTBITS,
                     parity=serial.PARITY_NONE) as pacemaker:
           pacemaker.write(toWrite)
        return True


    def writeParamtersToBoard(self):
        status = []
        for name, value in self.__dict__.items():
            written = self.setParameterOnBoard(name, value)
            status.append((name, written))
        return status

    def getAllAttributes(self):
        return self.__dict__.items()
            
    # define a bunch of get/set methods to be used by gui

    def getBradycardiaOperatingMode(self):
        return self.BradycardiaOperatingMode

    def setBradycardiaOperatingMode(self, BradycardiaOperatingMode):
        self.BradycardiaOperatingMode = BradycardiaOperatingMode

    def getLowerRateLimit(self):
        return self.LowerRateLimit

    def setLowerRateLimit(self, LowerRateLimit):
        # 30 - 175 ppm
        try:
            LowerRateLimit = int(LowerRateLimit)
        except:
            raise TypeError("Lower Rate Limit must be a integer")
       
        if LowerRateLimit < 30 or LowerRateLimit > 175:
            raise ValueError("Lower Rate limit is not within the correct range")
        self.LowerRateLimit = LowerRateLimit

    def getUpperRateLimit(self):
        return self.UpperRateLimit

    def setUpperRateLimit(self, UpperRateLimit):
        # 50 - 175 ppm
        try:
            UpperRateLimit = int(UpperRateLimit)
        except:
            raise TypeError("Upper Rate Limit must be a integer")
        
        if UpperRateLimit < 50 or UpperRateLimit > 175:
            raise ValueError("Upper rate limit is not within the correct range")
        self.UpperRateLimit = UpperRateLimit

    def getAtrialAmplitude(self):
        return self.AtrialAmplitude

    def setAtrialAmplitude(self, AtrialAmplitude):
        # off, 0.5-3.2V, 3.5-7V
        try:
            AtrialAmplitude = float(AtrialAmplitude)
        except:
            raise TypeError("Atrial Amplitude must be a float")
        
        if AtrialAmplitude < 0.5 or AtrialAmplitude > 3.2:
            if AtrialAmplitude != 0 and (AtrialAmplitude < 3.5 or AtrialAmplitude > 7):
                raise ValueError("Atrial amplitude is not within the correct ranges")
        
        # off, 1.25, 2.5, 3.75, 5V for unregulated 
        #elif AtrialAmplitude not in [0, 1.25, 2.5, 3.75, 5]:
        #    raise Exception ("Atrial amplitude is not an acceptable value")
        self.AtrialAmplitude = AtrialAmplitude

    def getAtrialPulseWidth(self):
        return self.AtrialPulseWidth

    def setAtrialPulseWidth(self, AtrialPulseWidth):
        # 0.05ms, 0.1-1.9ms
        try:
            AtrialPulseWidth = float(AtrialPulseWidth)
        except:
            raise TypeError("Atrial Pulse Width must be a float")
        
        if AtrialPulseWidth != 0.05 and (AtrialPulseWidth < 0.1 or AtrialPulseWidth > 1.9):
            raise ValueError("Atrial pulse width is not within the correct range")
        self.AtrialPulseWidth = AtrialPulseWidth

    def getAtrialSensitivity(self):
        return self.AtrialSensitivity

    def setAtrialSensitivity(self, AtrialSensitivity):
        # 0.25, 0.5, 0.75, 1-10mV
        try:
            AtrialSensitivity = float(AtrialSensitivity)
        except:
            raise TypeError("Atrial sensitivity must be a float")
     
        if AtrialSensitivity!= 0.25 and AtrialSensitivity!= 0.5 and AtrialSensitivity!= 0.75:
            if(AtrialSensitivity < 1 or AtrialSensitivity > 10):
                raise ValueError("Atrial sensitivity is not within the correct range")
        self.AtrialSensitivity = AtrialSensitivity

    def getVentricularAmplitude(self):
        return self.VentricularAmplitude

    def setVentricularAmplitude(self, VentricularAmplitude):
        # off, 0.5-3.2V, 3.5-7V
        try:
            VentricularAmplitude = float(VentricularAmplitude)
        except:
            raise TypeError("Ventricular Amplitude must be a float")

        if VentricularAmplitude < 0.5 or VentricularAmplitude > 3.2:
            if VentricularAmplitude != 0 and (VentricularAmplitude < 3.5 or VentricularAmplitude > 7):
                raise ValueError("Ventricular amplitude is not within the correct ranges")
        
        # off, 1.25, 2.5, 3.75, 5V for unregulated
        #elif VentricularAmplitude not in [0, 1.25, 2.5, 3.75, 5]:
        #    raise Exception ("Ventricular amplitude is not an acceptable value")
        self.VentricularAmplitude = VentricularAmplitude

    def getVentricularPulseWidth(self):
        return self.VentricularPulseWidth

    def setVentricularPulseWidth(self, VentricularPulseWidth):
        # 0.05ms, 0.1-1.9ms
        try:
            VentricularPulseWidth = float(VentricularPulseWidth)
        except:
            raise TypeError("Ventricular Pulse Width must be a float")

        if VentricularPulseWidth != 0.05 and (VentricularPulseWidth < 0.1 or VentricularPulseWidth > 1.9):
            raise ValueError("Ventricular pulse width is not within the correct range")
        self.VentricularPulseWidth = VentricularPulseWidth

    def getVentricularSensitivity(self):
        return self.VentricularSensitivity
    
    def setVentricularSensitivity(self, VentricularSensitivity):
        # 0.25, 0.5, 0.75, 1-10mV
        try:
            VentricularSensitivity = float(VentricularSensitivity)
        except:
            raise TypeError("Ventricular sensitivity must be a float")
     
        if VentricularSensitivity!= 0.25 and VentricularSensitivity!= 0.5 and VentricularSensitivity!= 0.75:
            if(VentricularSensitivity < 1 or VentricularSensitivity > 10):
                raise ValueError("Ventricular sensitivity is not within the correct range")
        self.VentricularSensitivity = VentricularSensitivity

    def getVRP(self):
        return self.VRP

    def setVRP(self, VRP: int):
        # 150-500ms
        try:
            VRP = int(VRP)
        except:
            raise TypeError("VRP must be a integer")
        
        if VRP < 150 or VRP > 500:
            raise ValueError("Ventricular refractory period is not within the correct range")
        self.VRP = VRP

    def getARP(self):
        return self.ARP

    def setARP(self, ARP: int):
        # 150-500ms
        try:
            ARP = int(ARP)
        except:
            raise TypeError("ARP must be a integer")
        
        if ARP < 150 or ARP > 500:
            raise ValueError("Atrial refractory period is not within the correct range")
        self.ARP = ARP

    def getMaxSensorRate(self):
        return self.MaxSensorRate
    
    def setMaxSensorRate(self, MaxSensorRate):
        # 50-175ppm
        try:
            MaxSensorRate = int(MaxSensorRate)
        except:
            raise TypeError("Max sensor rate must be a integer")

        if MaxSensorRate < 50 or MaxSensorRate > 175:
            raise ValueError("Max sensor rate is not within the correct range")
        self.MaxSensorRate = MaxSensorRate

    def getFixedAVdelay(self):
        return self.FixedAVdelay

    def setFixedAVdelay(self, FixedAVdelay):
        # 70-300ms
        try:
            FixedAVdelay = int(FixedAVdelay)
        except:
            raise TypeError("Fixed AV delay must be a integer")

        if FixedAVdelay < 70 or FixedAVdelay > 300:
            raise ValueError("Fixed AV delay is not within the correct range")
        self.FixedAVdelay = FixedAVdelay

    def getDynamicAVdelay(self):
        return self.DynamicAVdelay

    def setDynamicAVdelay(self, DynamicAVdelay):
        # 30-100ms                                   #on and off??
        try:
            DynamicAVdelay = int(DynamicAVdelay)
        except:
            raise TypeError("Dynamic AV delay must be a integer")
        
        if DynamicAVdelay < 30 or DynamicAVdelay > 100:
            raise ValueError("Dynamic AV delay is not within the correct range")
        self.DynamicAVdelay = DynamicAVdelay

    def getAVdelayOffset(self):
        return self.AVdelayOffset

    def setAVdelayOffset(self, AVdelayOffset):
        # off(0) and -10 to -100ms                                   
        try:
            AVdelayOffset = int(AVdelayOffset)
        except:
            raise TypeError("AV delay offset must be a integer")
        
        if AVdelayOffset != 0:
            if AVdelayOffset < -100 or AVdelayOffset > -10:
                raise ValueError("AV delay offset is not within the correct range")
        self.AVdelayOffset = AVdelayOffset

    def getPVARP(self):
        return self.PVARP

    def setPVARP(self, PVARP):
        # 150-500ms                                   
        try:
            PVARP = int(PVARP)
        except:
            raise TypeError("PVARP must be a integer")
        
        if PVARP < 150 or PVARP > 500:
            raise ValueError("PVARP is not within the correct range")
        self.PVARP = PVARP

    def getPVARPextension(self):
        return self.PVARPextension
    
    def setPVARPextension(self, PVARPextension):
        # off(0) and 50-400ms                                   
        try:
            PVARPextension = int(PVARPextension)
        except:
            raise TypeError("PVARP extension must be a integer")
        
        if PVARPextension != 0:
            if PVARPextension < 50 or PVARPextension > 400:
                raise ValueError("PVARPextension is not within the correct range")
        self.PVARPextension = PVARPextension

    def getHysteresis(self):
        return self.Hysteresis

    def setHysteresis(self, Hysteresis):
        # off and 30-175 ppm
        try:
            Hysteresis = int(Hysteresis)
        except:
            raise TypeError("Hysteresis must be a integer")
        
        if Hysteresis != 0:
            if Hysteresis < 30 or Hysteresis > 175:
                raise ValueError("Hysteresis is not within the correct range")
        self.Hysteresis = Hysteresis

    def getRateSmoothing(self):
        return self.RateSmoothing

    def setRateSmoothing(self, RateSmoothing):
        # off(0), 0.25, 3, 6, 9, 12, 15, 18, 21
        try:
            RateSmoothing = float(RateSmoothing)
        except:
            raise TypeError("Rate smoothing must be a float")
     
        if RateSmoothing!= 0 and RateSmoothing!= 0.25 and RateSmoothing!= 3 and RateSmoothing!= 6 and RateSmoothing!= 9 and RateSmoothing!= 12 and RateSmoothing!= 15 and RateSmoothing!= 18 and RateSmoothing!= 21:
            raise ValueError("Rate smoothing is not within the correct range")
        self.RateSmoothing = RateSmoothing

    def getReactionTime(self):
        return self.ReationTime

    def setReationTime(self, ReationTime):
        # 10-50s                                   
        try:
            ReationTime = int(ReationTime)
        except:
            raise TypeError("Reation time must be a integer")
        
        if ReationTime < 10 or ReationTime > 50:
            raise ValueError("Reation time is not within the correct range")
        self.ReationTime = ReationTime

    def getResponseFactor(self):
        return self.ResponseFactor

    def setResponseFactor(self, ResponseFactor):
        # 1-16                                 
        try:
            ResponseFactor = int(ResponseFactor)
        except:
            raise TypeError("Response factor must be a integer")
        
        if ResponseFactor < 1 or ResponseFactor > 16:
            raise ValueError("Response factor is not within the correct range")
        self.ResponseFactor = ResponseFactor

    def getRecoveryTime(self):
        return self.RecoveryTime

    def setRecoveryTime(self, RecoveryTime):
        # 2-16 min                                
        try:
            RecoveryTime = int(RecoveryTime)
        except:
            raise TypeError("Recovery time must be a integer")
        
        if RecoveryTime < 2 or RecoveryTime > 16:
            raise ValueError("Recovery time is not within the correct range")
        self.RecoveryTime = RecoveryTime

    def getActivityThreshold(self):
         return self.ActivityThreshold

    def setActivityThreshold(self, ActivityThreshold: str):
        # V-Low, Low, Med-Low, Med, Med-High, High, V-High
        try:
            ActivityThreshold = str(ActivityThreshold)
        except:
            raise TypeError("Activity threshold must be a string")
     
        if ActivityThreshold != "V-Low" and ActivityThreshold != "Low" and ActivityThreshold != "Med-Low" and ActivityThreshold != "Med" and ActivityThreshold != "Med-High" and ActivityThreshold != "High" and ActivityThreshold != "V-High":
            raise ValueError("Activity threshold does not match a given mode")
        self.ActivityThreshold = ActivityThreshold

    def getATRmode(self):
        return self.ATRmode

    def setATRmode(self, ATRmode):
        # on or off (1 or 0)
        try:
            ATRmode = int(ATRmode)
        except:
            raise TypeError("ATR Fallback Mode must be a integer")
        
        if ATRmode != 1 and ATRmode != 0:
            raise ValueError("ATR Fallback Mode is not working")
        self.ATRmode = ATRmode
   
    def getATRtime(self):
        return self.ATRtime

    def setATRtime(self, ATRtime):
        # 1-5 min                                
        try:
            ATRtime = int(ATRtime)
        except:
            raise TypeError("ATR time must be a integer")
        
        if ATRtime < 1 or ATRtime > 5:
            raise ValueError("ATR time is not within the correct range")
        self.ATRtime = ATRtime

    def getATRduration(self):
        return self.ATRduration

    def setATRduration(self, ATRduration):
        # 10 and 20-80 and 100-2000
        try:
            ATRduration = int(ATRduration)
        except:
            raise TypeError("ATR duration must be a integer")
        
        if ATRduration != 10:
            if ATRduration < 20 or ATRduration > 80:
                if ATRduration < 100 or ATRduration > 2000:
                    raise ValueError("ATR duration is not within the correct range")
        self.ATRduration = ATRduration
