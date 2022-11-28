import sys
import os
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QLineEdit, QPushButton, QStackedWidget, \
    QMainWindow, QDialog, QGridLayout
from PyQt5.uic import loadUi
import PyQt5.QtCore as Qt
import User.user as User
import serial
import struct
import pyqtgraph as pg

WIDTH = 800
HEIGHT = 500
class loginScreen(QMainWindow):

    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "MainWindow - LoginScreen.ui"), self)
        self.passwordField.setEchoMode(QLineEdit.Password)
        self.setFixedSize(WIDTH, HEIGHT)

        def createUser():
            username = self.usernameField.text()
            try:
                if not username == "":
                    self.user = User.user(self.usernameField.text(), self.passwordField.text())
                else:
                    raise ValueError
            except Exception as e:
                if (username == ""):  # Username cannot be empty
                    print("Username cannot be empty")
                    self.errorLabel.setText("Username cannot be empty")
                elif (type(e) == ValueError):  # Too many users to create new one
                    print(str(e))
                    self.errorLabel.setText(str(e))
                elif (type(e) == KeyError):  # Wrong password
                    print("Login Failed: Wrong Password")
                    self.errorLabel.setText("Login Failed: Wrong Password")
                else:  # Unknown Error!
                    print(f"Unhandled Error: {e}")
                    self.errorLabel.setText(f"Unhandled Error: {e}")
                return False

            if self.user:
                # Created user succesfully
                # switch to logged in screen
                print(f"Logged in to {self.user.username}")
                DeviceControllerMonitor.setUser(self.user)
                SceneManager.setCurrentIndex(1)

        self.loginButton.clicked.connect(createUser)

    def logUserOut(self):
        print(f"Logged out of {self.user.username}")
        self.usernameField.setText("")
        self.passwordField.setText("")
        self.errorLabel.setText("")
        self.user = None


class DeviceControllerMonitor(QDialog):
    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "EditProperties Screen.ui"), self)
        self.setFixedSize(WIDTH, HEIGHT)
        self.saveAllButton.clicked.connect(self.saveToUser)
        self.logoutButton.clicked.connect(self.logOut)
        self.resetButton.clicked.connect(self.resetFields)
        def moveToEgram():
            SceneManager.setCurrentIndex(2)
        self.egramButton.clicked.connect(moveToEgram)
        self.writeParametersButton.clicked.connect(self.writeParametersToBoard)
        self.echoParametersButton.clicked.connect(self.echoParametersFromBoard)
        self.pacedComboBox.activated.connect(self.handleModeChange)
        self.sensedComboBox.activated.connect(self.handleModeChange)
        self.responseComboBox.activated.connect(self.handleModeChange)
        self.rateModulationComboBox.activated.connect(self.handleModeChange)
        self.hideFields()
        self.tempBradycardiaMode = self.pacedComboBox.currentText()[0] + self.sensedComboBox.currentText()[0] \
                                   + self.responseComboBox.currentText()[0]

    def hideFields(self):
        self.lowerRateLimitLabel.setHidden(True)
        self.lowerRateLimitField.setHidden(True)
        self.upperRateLimitLabel.setHidden(True)
        self.upperRateLimitField.setHidden(True)
        self.atrialAmplitudeLabel.setHidden(True)
        self.atrialAmplitudeField.setHidden(True)
        self.atrialPulseWidthLabel.setHidden(True)
        self.atrialPulseWidthField.setHidden(True)
        self.atrialSensitivityLabel.setHidden(True)
        self.atrialSensitivityField.setHidden(True)
        self.ventricularAmplitudeLabel.setHidden(True)
        self.ventricularAmplitudeField.setHidden(True)
        self.ventricularPulseWidthLabel.setHidden(True)
        self.ventricularPulseWidthField.setHidden(True)
        self.ventricularSensitivityLabel.setHidden(True)
        self.ventricularSensitivityField.setHidden(True)
        self.vrpLabel.setHidden(True)
        self.vrpField.setHidden(True)
        self.arpLabel.setHidden(True)
        self.arpField.setHidden(True)
        self.MaxSensorRateLabel.setHidden(True)
        self.MaxSensorRateField.setHidden(True)
        self.FixedAVdelayLabel.setHidden(True) 
        self.FixedAVdelayField.setHidden(True)
        self.DynamicAVdelayLabel.setHidden(True) 
        self.DynamicAVdelayField.setHidden(True)
        self.AVdelayOffsetLabel.setHidden(True)
        self.AVdelayOffsetField.setHidden(True)
        self.pvarpLabel.setHidden(True)
        self.pvarpField.setHidden(True)
        self.pvarpExtensionLabel.setHidden(True)
        self.pvarpExtensionField.setHidden(True)
        self.hysteresisLabel.setHidden(True)
        self.hysteresisField.setHidden(True)
        self.RateSmoothingLabel.setHidden(True)
        self.RateSmoothingField.setHidden(True)
        self.ReactionTimeLabel.setHidden(True)
        self.ReactionTimeField.setHidden(True)
        self.ResponseFactorLabel.setHidden(True)
        self.ResponseFactorField.setHidden(True)
        self.RecoveryTimeLabel.setHidden(True)
        self.RecoveryTimeField.setHidden(True)
        self.ActivityThresholdLabel.setHidden(True)
        self.ActivityThresholdField.setHidden(True)
        self.atrModeLabel.setHidden(True)
        self.atrModeField.setHidden(True)
        self.atrTimeLabel.setHidden(True)
        self.atrTimeField.setHidden(True)
        self.atrDurationLabel.setHidden(True)
        self.atrDurationField.setHidden(True)


    def setUser(self, user):
        self.user = user
        self.label_9.setText(f"Current User: {self.user.username}  Pacemaker Serial Number: [] Communicating: []")
        self.resetFields()
    def resetFields(self):
        self.lowerRateLimitField.setText(str(self.user.getLowerRateLimit()))
        self.upperRateLimitField.setText(str(self.user.getUpperRateLimit()))
        self.atrialAmplitudeField.setText(str(self.user.getAtrialAmplitude()))
        self.atrialPulseWidthField.setText(str(self.user.getAtrialPulseWidth()))
        self.atrialSensitivityField.setText(str(self.user.getAtrialSensitivity()))
        self.ventricularAmplitudeField.setText(str(self.user.getVentricularAmplitude()))
        self.ventricularPulseWidthField.setText(str(self.user.getVentricularPulseWidth()))
        self.ventricularSensitivityField.setText(str(self.user.getVentricularSensitivity()))
        self.vrpField.setText(str(self.user.getVRP()))
        self.arpField.setText(str(self.user.getARP()))
        self.MaxSensorRateField.setText(str(self.user.getMaxSensorRate()))
        self.FixedAVdelayField.setText(str(self.user.getFixedAVdelay()))
        self.DynamicAVdelayField.setText(str(self.user.getDynamicAVdelay()))
        self.AVdelayOffsetField.setText(str(self.user.getAVdelayOffset()))
        self.pvarpField.setText(str(self.user.getPVARP()))
        self.pvarpExtensionField.setText(str(self.user.getPVARPextension()))
        self.hysteresisField.setText(str(self.user.getHysteresis()))
        self.RateSmoothingField.setText(str(self.user.getRateSmoothing()))
        self.ReactionTimeField.setText(str(self.user.getReactionTime()))
        self.ResponseFactorField.setText(str(self.user.getResponseFactor()))
        self.RecoveryTimeField.setText(str(self.user.getRecoveryTime()))
        self.ActivityThresholdField.setText(str(self.user.getActivityThreshold()))
        self.atrModeField.setText(str(self.user.getATRmode()))
        self.atrTimeField.setText(str(self.user.getATRtime()))
        self.atrDurationField.setText(str(self.user.getATRduration()))
        BychardiaSettingMap = {
            "V": "V - Ventricle",
            "O": "O - None",
            "A": "A - Atrium",
            "I": "I - Inhibited",
            "T": "T - Triggered",
            "D": "D - Dual",
            "R": "R - Rate Modulation"
        }
        self.pacedComboBox.setCurrentText(BychardiaSettingMap[self.user.getBradycardiaOperatingMode()[0]])
        self.sensedComboBox.setCurrentText(BychardiaSettingMap[self.user.getBradycardiaOperatingMode()[1]])
        responseBox = BychardiaSettingMap[self.user.getBradycardiaOperatingMode()[1]] if not \
        self.user.getBradycardiaOperatingMode()[1] == "D" \
            else "D - Tracked"
        self.responseComboBox.setCurrentText(responseBox)
        self.rateModulationComboBox.setCurrentText(self.user.getBradycardiaOperatingMode()[3])
        self.handleModeChange()

    def saveToUser(self):
        print(f"Saving attributes for {self.user.username}")
        self.errorLabel.setText("")
        try:
            self.user.setLowerRateLimit(self.lowerRateLimitField.text())
            self.user.setUpperRateLimit(self.upperRateLimitField.text())
            self.user.setAtrialAmplitude(self.atrialAmplitudeField.text())
            self.user.setAtrialPulseWidth(self.atrialPulseWidthField.text())
            self.user.setAtrialSensitivity(self.atrialSensitivityField.text())
            self.user.setVentricularAmplitude(self.ventricularAmplitudeField.text())
            self.user.setVentricularPulseWidth(self.ventricularPulseWidthField.text())
            self.user.setVentricularSensitivity(self.ventricularSensitivityField.text())
            self.user.setVRP(self.vrpField.text())
            self.user.setARP(self.arpField.text())
            self.user.setMaxSensorRate(self.MaxSensorRateField.text())
            self.user.setFixedAVdelay(self.FixedAVdelayField.text())
            self.user.setDynamicAVdelay(self.DynamicAVdelayField.text())
            self.user.setAVdelayOffset(self.AVdelayOffsetField.text())
            self.user.setPVARP(self.pvarpField.text())
            self.user.setPVARPextension(self.pvarpExtensionField.text())
            self.user.setHysteresis(self.hysteresisField.text())
            self.user.setRateSmoothing(self.RateSmoothingField.text())
            self.user.setReactionTime(self.ReactionTimeField.text())
            self.user.setResponseFactor(self.ResponseFactorField.text())
            self.user.setRecoveryTime(self.RecoveryTimeField.text())
            self.user.setActivityThreshold(self.ActivityThresholdField.text())
            self.user.setATRmode(self.atrModeField.text())
            self.user.setATRtime(self.atrTimeField.text())
            self.user.setATRduration(self.atrDurationField.text())
            self.user.setBradycardiaOperatingMode(self.tempBradycardiaMode)
            self.user.serialize()
        except Exception as e:
            print(f"Error Saving: {e}")
            self.errorLabel.setText(f"Error Saving: {e}")

    def writeParametersToBoard(self):
        try:
            self.user.writeParametersToBoard()
        except Exception as e:
            self.errorLabel.setText(str(e))
        
    def echoParametersFromBoard(self):
        try:
            self.user.echoParametersFromBoard()
            self.resetFields()
        except Exception as e:
            self.errorLabel.setText(str(e))

    def logOut(self):
        self.user = None
        loginScreen.logUserOut()
        SceneManager.setCurrentIndex(SceneManager.currentIndex() - 1)

    def handleModeChange(self):
        self.errorLabel.setText("")
        self.tempBradycardiaMode = self.pacedComboBox.currentText()[0] + self.sensedComboBox.currentText()[0] \
                   + self.responseComboBox.currentText()[0] + self.rateModulationComboBox.currentText()[0]

        def showRateLimits():
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)

        def showAtrialParameters():
            self.atrialAmplitudeLabel.setHidden(False)
            self.atrialAmplitudeField.setHidden(False)
            self.atrialPulseWidthLabel.setHidden(False)
            self.atrialPulseWidthField.setHidden(False)

        def showArtialSensitivity():
            self.atrialSensitivityLabel.setHidden(False) 
            self.atrialSensitivityField.setHidden(False) 

        def showVentricularParameters():
            self.ventricularAmplitudeLabel.setHidden(False)
            self.ventricularAmplitudeField.setHidden(False)
            self.ventricularPulseWidthLabel.setHidden(False)
            self.ventricularPulseWidthField.setHidden(False)

        def showVentricularSensitivity():
            self.ventricularSensitivityLabel.setHidden(False) 
            self.ventricularSensitivityField.setHidden(False)  

        def showArpParameters():
            self.arpLabel.setHidden(False)
            self.arpField.setHidden(False)

        def showVrpParameters():
            self.vrpLabel.setHidden(False)
            self.vrpField.setHidden(False)

        def showMaxSensorRate():
            self.MaxSensorRateLabel.setHidden(False)
            self.MaxSensorRateField.setHidden(False)

        def showFixedAVdelay():
            self.FixedAVdelayLabel.setHidden(False)
            self.FixedAVdelayField.setHidden(False)

        def showDynamicAVdelay():
            self.DynamicAVdelayLabel.setHidden(False)
            self.DynamicAVdelayField.setHidden(False)

        def showAVdelayOffset():
            self.AVdelayOffsetLabel.setHidden(False)
            self.AVdelayOffsetField.setHidden(False)

        def showPVARP():
            self.pvarpLabel.setHidden(False)
            self.pvarpField.setHidden(False)

        def showPVARPextension():
            self.pvarpExtensionLabel.setHidden(False)
            self.pvarpExtensionField.setHidden(False)

        def showHysteresis():
            self.hysteresisLabel.setHidden(False)
            self.hysteresisField.setHidden(False)

        def showRateSmoothing():
            self.RateSmoothingLabel.setHidden(False)
            self.RateSmoothingField.setHidden(False)

        def showRateAdaptiveParameters():
            self.ReactionTimeLabel.setHidden(False)
            self.ReactionTimeField.setHidden(False)
            self.ResponseFactorLabel.setHidden(False)
            self.ResponseFactorField.setHidden(False)
            self.RecoveryTimeLabel.setHidden(False)
            self.RecoveryTimeField.setHidden(False)
            self.ActivityThresholdLabel.setHidden(False)
            self.ActivityThresholdField.setHidden(False)

        def showATRparameters():
            self.atrModeLabel.setHidden(False)
            self.atrModeField.setHidden(False)
            self.atrTimeLabel.setHidden(False)
            self.atrTimeField.setHidden(False)
            self.atrDurationLabel.setHidden(False)
            self.atrDurationField.setHidden(False)

        if self.tempBradycardiaMode == 'AATO':
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showArpParameters()
            showArtialSensitivity()
            showPVARP()
        elif self.tempBradycardiaMode == 'VVTO':
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
            showVrpParameters()
            showVentricularSensitivity()
        elif self.tempBradycardiaMode == 'AOOO':
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
        elif self.tempBradycardiaMode == 'AAIO':
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showArpParameters()
            showArtialSensitivity()
            showPVARP()
            showHysteresis()
            showRateSmoothing()
        elif self.tempBradycardiaMode == 'VOOO':
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
        elif self.tempBradycardiaMode == 'VVIO':
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
            showVrpParameters()
            showVentricularSensitivity()
            showHysteresis()
            showRateSmoothing()
        elif self.tempBradycardiaMode == 'VDDO':
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
            showVrpParameters()
            showVentricularSensitivity()
            showFixedAVdelay()
            showDynamicAVdelay()
            showPVARPextension()
            showRateSmoothing()
            showATRparameters()
        elif self.tempBradycardiaMode == 'DOOO':
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showVentricularParameters()
            showFixedAVdelay()
        elif self.tempBradycardiaMode == 'DDIO':
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showVentricularParameters()
            showArpParameters()
            showVrpParameters()
            showArtialSensitivity()
            showVentricularSensitivity()
            showFixedAVdelay()
            showPVARP()
        elif self.tempBradycardiaMode == 'DDDO':
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showVentricularParameters()
            showArpParameters()
            showVrpParameters()
            showArtialSensitivity()
            showVentricularSensitivity()
            showFixedAVdelay()
            showDynamicAVdelay()
            showAVdelayOffset()
            showPVARP()
            showPVARPextension()
            showHysteresis()
            showRateSmoothing()
            showATRparameters()
        elif self.tempBradycardiaMode in ['AOOR']:
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showMaxSensorRate()
            showRateAdaptiveParameters()
        elif self.tempBradycardiaMode in ['AAIR']:
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showArpParameters()
            showArtialSensitivity()
            showMaxSensorRate()
            showPVARP()
            showHysteresis()
            showRateSmoothing()
            showRateAdaptiveParameters()
        elif self.tempBradycardiaMode in ['VOOR']:
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
            showMaxSensorRate()
            showRateAdaptiveParameters()
        elif self.tempBradycardiaMode in ['VVIR']:
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
            showVrpParameters()
            showVentricularSensitivity()
            showMaxSensorRate()
            showHysteresis()
            showRateSmoothing()
            showRateAdaptiveParameters()
        elif self.tempBradycardiaMode in ['VDDR']:
            self.hideFields()
            showRateLimits()
            showVentricularParameters()
            showVrpParameters()
            showVentricularSensitivity()
            showMaxSensorRate()
            showFixedAVdelay()
            showDynamicAVdelay()
            showPVARPextension()
            showRateSmoothing()
            showRateAdaptiveParameters()
            showATRparameters()
        elif self.tempBradycardiaMode in ['DOOR']:
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showVentricularParameters()
            showMaxSensorRate()
            showFixedAVdelay()
            showRateAdaptiveParameters()
        elif self.tempBradycardiaMode in ['DDIR']:
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showVentricularParameters()
            showArpParameters()
            showVrpParameters()
            showArtialSensitivity()
            showVentricularSensitivity()
            showMaxSensorRate()
            showFixedAVdelay()
            showPVARP()
            showRateAdaptiveParameters()
        elif self.tempBradycardiaMode in ['DDDR']:
            self.hideFields()
            showRateLimits()
            showAtrialParameters()
            showVentricularParameters()
            showArpParameters()
            showVrpParameters()
            showArtialSensitivity()
            showVentricularSensitivity()
            showMaxSensorRate()
            showFixedAVdelay()
            showDynamicAVdelay()
            showAVdelayOffset()
            showPVARP()
            showPVARPextension()
            showHysteresis()
            showRateSmoothing()
            showRateAdaptiveParameters()
            showATRparameters()
        else:
            self.hideFields()
            print(f"{self.tempBradycardiaMode} is an invalid Bradycardia Operating Mode")
            self.errorLabel.setText(f"{self.tempBradycardiaMode} is an invalid Bradycardia Operating Mode")


class DisplayEgram(QDialog):
    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "egramScreen.ui"), self)

        #Configure Timer to update graph
        self.timer = Qt.QTimer()
        self.timer.setInterval(50)
        self.timer.timeout.connect(self.getEgramData)
        self.count = 0

        #Configure Buttons
        self.startButton.clicked.connect(self.getOrStopData)
        self.backButton.clicked.connect(self.moveToDCM)
        self.clearButton.clicked.connect(self.clearData)

        self.start = False
        self.layout = QGridLayout()
        self.setFixedSize(WIDTH, HEIGHT)

        self.atriumX = []
        self.atriumY = []
        self.dataLineA = self.atriumView.plot(self.atriumX, self.atriumY)
        self.atriumView.setLabel("top", "Atrium Plot")

        self.ventricleX = []
        self.ventricleY = []
        self.dataLineV = self.ventricleView.plot(self.ventricleX, self.ventricleY)
        self.ventricleView.setLabel("top", "Ventricle Plot")



    def getOrStopData(self):
        if self.start:
            self.start = False
            self.timer.stop()
        else:
            self.start = True
            self.timer.start()

    def moveToDCM(self):
        self.start = False
        SceneManager.setCurrentIndex(1)

    def clearData(self):
        self.atriumX = []
        self.atriumY = []
        self.dataLineA = self.atriumView.clear()
        self.ventricleX = []
        self.ventricleY = []
        self.dataLineV = self.ventricleView.clear()
        self.count = 0

    def getEgramData(self):
        #print("here")

        Start = b'\x16'
        getData = b'\x77'
        toWrite = Start + getData
        for i in range(25):
            toWrite += struct.pack("i", 0)

        pacemaker = serial.Serial("COM4", 115200, timeout=2)
        pacemaker.write(toWrite)
        status = pacemaker.read(100)
        pacemaker.close()

        atrValue = struct.unpack("f", status[0:8])[0]
        venValue = struct.unpack("f", status[8:16])[0]

        self.atriumX.append(self.count)
        self.atriumY.append(atrValue)
        self.dataLineA = self.atriumView.plot(self.atriumX, self.atriumY)

        self.ventricleX.append(self.count)
        self.ventricleY.append(venValue)
        self.dataLineA = self.ventricleView.plot(self.ventricleX, self.ventricleY)

        self.count += 1

app = QApplication([])
SceneManager = QStackedWidget()
SceneManager.setFixedSize(WIDTH, HEIGHT)
DeviceControllerMonitor = DeviceControllerMonitor()
loginScreen = loginScreen()
graphEgram = DisplayEgram()

SceneManager.addWidget(loginScreen)
SceneManager.addWidget(DeviceControllerMonitor)
SceneManager.addWidget(graphEgram)
SceneManager.show()
sys.exit(app.exec())
