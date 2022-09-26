from passlib.hash import sha256_crypt
class user():

    # get instanceCount from user directory/db
    instanceCount = 0

    def __init__(self, username, password):
        
        userExists = self.deserialize(username)

        if ((instanceCount < 10) and not userExists):
            self.username = username
            self.password = sha256_crypt(password)
            instanceCount += 1
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

            self.serialize()

        else:
            print("Already have 10 users")
            # move to some functionality in the gui to delete users or do nothing

    def serialize(self):
        # store user data in txt files in directory/db
        pass
    
    def deserialize(self, username):
        # read user data to login if username exists
        # return bool if exists/doesnt
        pass

    # define a bunch of get/set methods to be used by gui