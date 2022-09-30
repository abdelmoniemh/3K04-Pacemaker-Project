from ssl import VerifyFlags
from passlib.hash import sha256_crypt
import json
import os

#if on linux or macos make sure "TMPDIR" env variable is set
os.environ["TMPDIR"] = "/home/tempdir" #for linux
class user():
    appUserDirectory = os.environ["TMP"] +"\\3K04-GROUP32-tmp-directory\\users" if os.name=="Windows" \
            else os.environ["TMPDIR"] + "/3K04-GROUP32-tmp-directory/users"
    # get instanceCount from user directory/db
    if not os.path.exists(appUserDirectory):
            os.makedirs(appUserDirectory)
    
    instanceCount = len(os.listdir(appUserDirectory))

    def __init__(self, username, password):
        self.createAttributes(username, password)
        userPath = os.path.join(self.appUserDirectory, f"{username}.json")
        if (not os.path.exists(userPath)):       
            if (self.instanceCount > 10):     
                raise ValueError #too many users to create a new one, catch and handle in gui code
            else:
                self.serialize()
        else:
            self.deserialize(username, password)

    def createAttributes(self, username, password):
        self.username = username
        self.password = sha256_crypt.hash(password)
        self.instanceCount += 1
        self.BradycardiaOperatingMode = "VOO"
        
        # initialize programmable parameters
        self.LowerRateLimit = 0
        self.UpperRateLimit = 0
        self.AtrialAmplitude = 0
        self.AtrialPulseWidth = 0
        self.VentricularAmplitude = 0
        self.VentricularPulseWidth = 0
        self.VRP = 0
        self.ARP = 0
        # more in PACEMAKER doc to be set up 

    def serialize(self):
        # store user data in txt files in directory/db

        toBeSerialized = dict()

        for attr, value in self.__dict__.items():
            #yield attr, value
            toBeSerialized[attr] = value

        jsonAsString = json.dumps(toBeSerialized)
        if not os.path.exists(self.appUserDirectory):
            os.makedirs(self.appUserDirectory)
        
        with open(os.path.join(self.appUserDirectory, f"{self.username}.json"), "w") as file:
            file.write(jsonAsString)

    def deserialize(self, username, password):
        print("Read from File")
        with open(os.path.join(self.appUserDirectory, f"{self.username}.json"), "r") as file:
            userAttributes = json.load(file)
            for attr, value in self.__dict__.items():
                self.__dict__[attr] = userAttributes[attr]
            print(password, self.password, sha256_crypt.verify(password, self.password))
            if not sha256_crypt.verify(password, self.password):
                raise KeyError #wrong password
            
    # define a bunch of get/set methods to be used by gui

    def getBradycardiaOperatingMode(self):
        return self.BradycardiaOperatingMode

    def setBradycardiaOperatingMode(self, BradycardiaOperatingMode):
        # add some restrictions on value based on pacemaker doc
        self.BradycardiaOperatingMode = BradycardiaOperatingMode

    def getLowerRateLimit(self):
        return self.LowerRateLimit

    def setLowerRateLimit(self, LowerRateLimit):
        # add some restrictions on value based on pacemaker doc
        self.LowerRateLimit = LowerRateLimit

    def getUpperRateLimit(self):
        return self.UpperRateLimit

    def setUpperRateLimit(self, UpperRateLimit):
        # add some restrictions on value based on pacemaker doc
        self.UpperRateLimit = UpperRateLimit

    def getAtrialAmplitude(self):
        return self.AtrialAmplitude

    def setAtrialAmplitude(self, AtrialAmplitude):
        # add some restrictions on value based on pacemaker doc
        self.AtrialAmplitude = AtrialAmplitude

    def getAtrialPulseWidth(self):
        return self.AtrialPulseWidth

    def setAtrialPulseWidth(self, AtrialPulseWidth):
        # add some restrictions on value based on pacemaker doc
        self.AtrialPulseWidth = AtrialPulseWidth

    def getVentricularAmplitude(self):
        return self.VentricularAmplitude

    def setVentricularAmplitude(self, VentricularAmplitude):
        # add some restrictions on value based on pacemaker doc
        self.VentricularAmplitude = VentricularAmplitude

    def getVentricularPulseWidth(self):
        return self.VentricularPulseWidth

    def setVentricularPulseWidth(self, VentricularPulseWidth):
        # add some restrictions on value based on pacemaker doc
        self.VentricularPulseWidth = VentricularPulseWidth

    def getVRP(self):
        return self.VRP

    def setVRP(self, VRP):
        # add some restrictions on value based on pacemaker doc
        self.VRP = VRP

    def getARP(self):
        return self.ARP

    def setARP(self, ARP):
        # add some restrictions on value based on pacemaker doc
        self.ARP = ARP








def testSerialize():
    testUser = user("testUser", "password")
    testUser.serialize()
    testUser2 = user("username", "password")
    testUser3 = user("username", "password3")
#testSerialize()