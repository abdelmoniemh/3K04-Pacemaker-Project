from user import user
import os
import unittest

class testUserClass(unittest.TestCase):
    
    def testCreateNewUser(self):
        testCreateNewUser = user("username", "password", "/test")
        testCreateNewUser.setVentricularPulseWidth(123)
        testCreateNewUser.serialize()
        testCreateNewUserDeserialized = user("username", "password", "/test")
        testCreateDifferentUser = user("username-2", "pAsSwOrD")
        assert(testCreateNewUser.getVentricularPulseWidth() == testCreateNewUserDeserialized.getVentricularPulseWidth())
        assert(not (testCreateNewUser.getVentricularPulseWidth() == testCreateDifferentUser.getVentricularPulseWidth()))


if __name__ == '__main__':
    unittest.main()