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
        if not username.isalnum():
            raise ValueError("Username can only contain letters or numbers.")
        if not password.isalnum():
            raise ValueError("Password can only contain letters or numbers.")
        self.createAttributes(username, password)
        self.subDirectory = subDirectory
        self.appUserDirectory += self.subDirectory
        userPath = os.path.join(self.appUserDirectory, f"{username}.json")
        if (not os.path.exists(userPath)):       
            if (self.instanceCount + 1 > 10):
                raise ValueError("Sign Up Failed: The max amount of users has been hit.\n \
                                        Delete users before creating more.") #too many users to create a new one, catch and handle in gui code
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
        self.ReactionTime = 25
        self.ResponseFactor = 10
        self.RecoveryTime = 8
        self.ActivityThreshold = "Med" # Need to be able to read at matlab uart if implements
        self.ATRmode = 1
        self.ATRtime = 3 
        self.ATRduration = 70

        self.outputLength = 0
        
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
            "AOO": 1,
            "VOO": 2,
            "AAI": 3,
            "VVI": 4,

        }
        Start = b'\x16'
        SYNC = b'\x22'
        Fn_set = b'\x55'
        toWrite = Start + Fn_set

        if type(parameter) == str and parameterName == "BradycardiaOperatingMode":
            toWrite += struct.pack("i", parameterDictionary[parameter[0:3]]) #struct.pack("i", parameterDictionary[parameterName])
            pacemaker = serial.Serial("COM3", 115200)
            print(f"parameterName = {parameterName}, {toWrite}, len = {len(struct.pack('i', parameterDictionary[parameter[0:3]]))}")
            self.outputLength += len(struct.pack('i', parameterDictionary['VOO']))
            pacemaker.write(toWrite)
            pacemaker.close()
        else:
            toWrite += struct.pack(typeDictionary[type(parameter)], parameter)
            print(f"parameterName = {parameterName}, {toWrite}, len = {len(struct.pack(typeDictionary[type(parameter)], parameter))}")
            self.outputLength += len(struct.pack(typeDictionary[type(parameter)], parameter))
            pacemaker = serial.Serial("COM3", 115200)
            pacemaker.write(toWrite)
            pacemaker.close()
        return True


    def writeParamtersToBoard(self):
        status = []
        outputParameters = [
            "BradycardiaOperatingMode",
            "LowerRateLimit",
            "UpperRateLimit",
            "AtrialAmplitude",
            "AtrialPulseWidth",
            "AtrialSensitivity",
            "VentricularAmplitude",
            "VentricularPulseWidth",
            "VentricularSensitivity",
            "VRP",
            "ARP",
            "MaxSensorRate",
            "FixedAVdelay",
            "DynamicAVdelay",
            "AVdelayOffset",
            "PVARP",
            "PVARPextension",
            "Hysteresis",
            "RateSmoothing",
            "ReactionTime",
            "ResponseFactor",
            "RecoveryTime",
            "ATRmode",
            "ATRtime",
            "ATRduration"
        ]

        #outputParameters = ["BradycardiaOperatingMode"]
        for name in outputParameters:
            written = self.setParameterOnBoard(name, self.__dict__[name])
            status.append((name, written))
        return status, self.outputLength

    def echoParametersFromBoard(self):
        status = []

        Start = b'\x16'
        SYNC = b'\x22'
        Fn_set = b'\x55'

        toWrite = Start + SYNC
        with serial.Serial('COM3',
                    baudrate=115200,
                    bytesize=serial.EIGHTBITS,
                    parity=serial.PARITY_NONE) as pacemaker:
          pacemaker.write(toWrite)
          for i in range(1):
              status.append(pacemaker.read(1))

        print(status)
        return True

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
       
        if (LowerRateLimit < 30 or LowerRateLimit > 50) or LowerRateLimit not in range(30,51,5):
            if LowerRateLimit < 50 or LowerRateLimit > 90:
                if (LowerRateLimit < 90 or LowerRateLimit > 175) or LowerRateLimit not in range(90,176,5):
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
        
        if (UpperRateLimit < 50 or UpperRateLimit > 175) or UpperRateLimit not in range(50,176,5):
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
        
        if (AtrialAmplitude < 0.5 or AtrialAmplitude > 3.2) or AtrialAmplitude not in range(0.5,3.3,0.1):
            if AtrialAmplitude not in range(3.5,7,0.5):
                if AtrialAmplitude != 0 and (AtrialAmplitude < 3.5 or AtrialAmplitude > 7):
                    raise ValueError("Atrial amplitude is not within the correct ranges")
    
        # off, 1.25, 2.5, 3.75, 5V for unregulated 
        elif AtrialAmplitude not in [0, 1.25, 2.5, 3.75, 5]:
            raise Exception ("Atrial amplitude is not an acceptable value")
        self.AtrialAmplitude = AtrialAmplitude

    def getAtrialPulseWidth(self):
        return self.AtrialPulseWidth

    def setAtrialPulseWidth(self, AtrialPulseWidth):
        # 0.05ms, 0.1-1.9ms
        try:
            AtrialPulseWidth = float(AtrialPulseWidth)
        except:
            raise TypeError("Atrial Pulse Width must be a float")
        
        if AtrialPulseWidth not in range(0.1,2.0,0.1):
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
            if (AtrialSensitivity < 1 or AtrialSensitivity > 10) or AtrialSensitivity not in range(1.0,10.5,0.5):
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
            if VentricularAmplitude not in range(3.5,7,0.5):
                if VentricularAmplitude != 0 and (VentricularAmplitude < 3.5 or VentricularAmplitude > 7):
                    raise ValueError("Ventricular amplitude is not within the correct ranges")
        
        # off, 1.25, 2.5, 3.75, 5V for unregulated
        elif VentricularAmplitude not in [0, 1.25, 2.5, 3.75, 5]:
            raise Exception ("Ventricular amplitude is not an acceptable value")
        self.VentricularAmplitude = VentricularAmplitude

    def getVentricularPulseWidth(self):
        return self.VentricularPulseWidth

    def setVentricularPulseWidth(self, VentricularPulseWidth):
        # 0.05ms, 0.1-1.9ms
        try:
            VentricularPulseWidth = float(VentricularPulseWidth)
        except:
            raise TypeError("Ventricular Pulse Width must be a float")

        if VentricularPulseWidth not in range(0.1,2.0,0.1):
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
            if(VentricularSensitivity < 1 or VentricularSensitivity > 10) or VentricularSensitivity not in range(1.0,10.5,0.5):
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
        
        if(VRP < 150 or VRP > 500) or VRP not in range(150,501,10):
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
        
        if ARP < 150 or ARP > 500 or ARP not in range(150,501,10):
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

        if (MaxSensorRate < 50 or MaxSensorRate > 175) or MaxSensorRate not in range(50,176,5):
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

        if (FixedAVdelay < 70 or FixedAVdelay > 300) or FixedAVdelay not in range(70,301,10):
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
        
        if (DynamicAVdelay < 30 or DynamicAVdelay > 100) or DynamicAVdelay not in range(30,101,10):
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
            if (AVdelayOffset < -100 or AVdelayOffset > -10) or AVdelayOffset not in range(-10,-101,-10):
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
        
        if (PVARP < 150 or PVARP > 500) or PVARP not in range(150,501,10):
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
            if (PVARPextension < 50 or PVARPextension > 400) or PVARPextension not in range(50,400,50):
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
            if (Hysteresis < 30 or Hysteresis > 50) or Hysteresis not in range(30,51,5):
                if Hysteresis < 50 or Hysteresis > 90:
                    if (Hysteresis < 90 or Hysteresis > 175) or Hysteresis not in range(90,176,5):
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
        return self.ReactionTime

    def setReactionTime(self, ReactionTime):
        # 10-50s                                   
        try:
            ReactionTime = int(ReactionTime)
        except:
            raise TypeError("Reaction time must be a integer")
        
        if (ReactionTime < 10 or ReactionTime > 50) or ReactionTime not in range(10,51,10):
            raise ValueError("Reaction time is not within the correct range")
        self.ReactionTime = ReactionTime

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
            if (ATRduration < 20 or ATRduration > 80) or ATRduration not in range(20,81,20):
                if (ATRduration < 100 or ATRduration > 2000) or ATRduration not in range(100,2001,100):
                    raise ValueError("ATR duration is not within the correct range")
        self.ATRduration = ATRduration
