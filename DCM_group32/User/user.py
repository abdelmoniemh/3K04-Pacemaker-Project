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
    
    instanceCount = len(os.listdir(appUserDirectory))

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
        # add some restrictions on value based on pacemaker doc
        self.BradycardiaOperatingMode = BradycardiaOperatingMode

    def getLowerRateLimit(self):
        return self.LowerRateLimit

    def setLowerRateLimit(self, LowerRateLimit: int):
        # 30 - 175 ppm
        if not (type(LowerRateLimit) == int):
            raise TypeError("Lower Rate Limit must be an integer")
        self.LowerRateLimit = LowerRateLimit

    def getUpperRateLimit(self):
        return self.UpperRateLimit

    def setUpperRateLimit(self, UpperRateLimit: int):
        # 50 - 175 ppm
        if not (type(UpperRateLimit) == int):
            raise TypeError("Upper Rate Limit must be an integer")
        self.UpperRateLimit = UpperRateLimit

    def getAtrialAmplitude(self):
        return self.AtrialAmplitude

    def setAtrialAmplitude(self, AtrialAmplitude: float):
        # add some restrictions on value based on pacemaker doc
        if not (type(AtrialAmplitude) == float):
            raise TypeError("Atrial Amplitude must be an float")
        self.AtrialAmplitude = AtrialAmplitude

    def getAtrialPulseWidth(self):
        return self.AtrialPulseWidth

    def setAtrialPulseWidth(self, AtrialPulseWidth: float):
        # add some restrictions on value based on pacemaker doc
        if not (type(AtrialPulseWidth) == float):
            raise TypeError("Atrial Pulse Width must be an float")
        self.AtrialPulseWidth = AtrialPulseWidth

    def getVentricularAmplitude(self):
        return self.VentricularAmplitude

    def setVentricularAmplitude(self, VentricularAmplitude: float):
        # add some restrictions on value based on pacemaker doc
        if not (type(VentricularAmplitude) == float):
            raise TypeError("Ventricular Amplitude must be an float")
        self.VentricularAmplitude = VentricularAmplitude

    def getVentricularPulseWidth(self):
        return self.VentricularPulseWidth

    def setVentricularPulseWidth(self, VentricularPulseWidth: float):
        # add some restrictions on value based on pacemaker doc
        if not (type(VentricularPulseWidth) == float):
            raise TypeError("Ventricular Pulse Width must be an float")
        self.VentricularPulseWidth = VentricularPulseWidth

    def getVRP(self):
        return self.VRP

    def setVRP(self, VRP: int):
        # add some restrictions on value based on pacemaker doc
        if not (type(VRP) == int):
            raise TypeError("VRP must be an integer")
        self.VRP = VRP

    def getARP(self):
        return self.ARP

    def setARP(self, ARP: int):
        # add some restrictions on value based on pacemaker doc
        if not (type(ARP) == int):
            raise TypeError("ARP must be an integer")
        self.ARP = ARP

