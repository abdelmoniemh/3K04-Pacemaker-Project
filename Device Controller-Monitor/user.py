from ssl import VerifyFlags
from passlib.hash import sha256_crypt
import json
import os

#if on linux or macos make sure "TMPDIR" env variable is set
os.environ["TMPDIR"] = "/home/tempdir" #for linux
class user():

    # get instanceCount from user directory/db
    appUserDirectory = os.environ["TMP"] +"\\3K04-GROUP32-tmp-directory\\users" if os.name=="Windows" \
            else os.environ["TMPDIR"] + "/3K04-GROUP32-tmp-directory/users"
    instanceCount = len(os.listdir(appUserDirectory))

    def __init__(self, username, password):
        self.createAttributes(self, username, password)
        if (not os.path.exists(os.path.join(self.appUserDirectory, f"{username}.json"))) and self.instanceCount > 10:            
            raise ValueError #too many users to create a new one, catch and handle in gui code
        else:
            self.deserialize(self, username, password)

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
        with open(os.path.join(self.appUserDirectory, f"{self.username}.json"), "r") as file:
            userAttributes = json.load(file)
            for attr, value in self.__dict__.items():
                attr = userAttributes[attr]
            if not sha256_crypt.verify(password, self.password):
                raise KeyError #wrong password
            
        

        pass

    # define a bunch of get/set methods to be used by gui

def testSerialize():
    testUser = user("testUser", "password")
    testUser.serialize()
testSerialize()