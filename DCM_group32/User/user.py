from ssl import VerifyFlags
from passlib.hash import sha256_crypt
import json
import os

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
        self.BradycardiaOperatingMode = "DDD"
        self.LowerRateLimit = 60
        self.UpperRateLimit = 120
        self.AtrialAmplitude = 3.5
        self.AtrialPulseWidth = 0.4
        self.VentricularAmplitude = 3.5
        self.VentricularPulseWidth = 0.4
        self.VRP = 320
        self.ARP = 250
        

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

        if  LowerRateLimit < 30 or LowerRateLimit > 175:
            raise Exception ("Lower Rate limit is not within the correct range")
        self.LowerRateLimit = LowerRateLimit

    def getUpperRateLimit(self):
        return self.UpperRateLimit

    def setUpperRateLimit(self, UpperRateLimit):
        # 50 - 175 ppm
        try:
            UpperRateLimit = int(UpperRateLimit)
        except:
            raise TypeError("Upper Rate Limit must be a integer")

        if  UpperRateLimit < 50 or UpperRateLimit > 175:
            raise Exception ("Upper rate limit is not within the correct range")
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
                raise Exception ("Atrial amplitude is not within the correct ranges")
        
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
        
        if  AtrialPulseWidth != 0.05 and (AtrialPulseWidth < 0.1 or AtrialPulseWidth > 1.9):
            raise Exception ("Atrial pulse width is not within the correct range")
        self.AtrialPulseWidth = AtrialPulseWidth

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
                raise Exception ("Ventricular amplitude is not within the correct ranges")
        
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

        if  VentricularPulseWidth != 0.05 and (VentricularPulseWidth < 0.1 or VentricularPulseWidth > 1.9):
            raise Exception ("Ventricular pulse width is not within the correct range")
        self.VentricularPulseWidth = VentricularPulseWidth

    def getVRP(self):
        return self.VRP

    def setVRP(self, VRP: int):
        # 150-500ms
        try:
            VRP = int(VRP)
        except:
            raise TypeError("VRP must be a integer")
        
        if  VRP < 150 or VRP > 500:
            raise Exception ("Ventricular refractory period is not within the correct range")
        self.VRP = VRP

    def getARP(self):
        return self.ARP

    def setARP(self, ARP: int):
        # 150-500ms
        try:
            ARP = int(ARP)
        except:
            raise TypeError("ARP must be a integer")
        
        if  ARP < 150 or ARP > 500:
            raise Exception ("Atrial refractory period is not within the correct range")
        self.ARP = ARP