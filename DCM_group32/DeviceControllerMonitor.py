import sys
import os
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QLineEdit, QPushButton, QStackedWidget, \
    QMainWindow, QDialog
from PyQt5.uic import loadUi
import PyQt5.QtCore as Qt
import User.user as User


class loginScreen(QMainWindow):

    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "MainWindow - LoginScreen.ui"), self)
        self.passwordField.setEchoMode(QLineEdit.Password)
        self.setFixedSize(1600, 800)

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
                    print("Sign Up Failed: The max amount of users has been hit.\n \
                                        Delete users before creating more.")
                    self.errorLabel.setText("Sign Up Failed: The max amount of users has been hit.\n \
                    Delete users before creating more.")
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
                SceneManager.setCurrentIndex(SceneManager.currentIndex() + 1)

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
        self.setFixedSize(1600, 800)
        self.saveAllButton.clicked.connect(self.saveToUser)
        self.logoutButton.clicked.connect(self.logOut)
        self.pacedComboBox.activated.connect(self.handlePacedModeChange)
        self.sensedComboBox.activated.connect(self.handlePacedModeChange)
        self.responseComboBox.activated.connect(self.handlePacedModeChange)
        self.hideFields()

    def hideFields(self):
        self.lowerRateLimitLabel.setHidden(True)
        self.lowerRateLimitField.setHidden(True)
        self.upperRateLimitLabel.setHidden(True)
        self.upperRateLimitField.setHidden(True)
        self.atrialAmplitudeLabel.setHidden(True)
        self.atrialAmplitudeField.setHidden(True)
        self.atrialPulseWidthLabel.setHidden(True)
        self.atrialPulseWidthField.setHidden(True)
        self.ventricularAmplitudeLabel.setHidden(True)
        self.ventricularAmplitudeField.setHidden(True)
        self.ventricularPulseWidthLabel.setHidden(True)
        self.ventricularPulseWidthField.setHidden(True)
        self.vrpLabel.setHidden(True)
        self.vrpField.setHidden(True)
        self.arpLabel.setHidden(True)
        self.arpField.setHidden(True)

    def setUser(self, user):
        self.user = user
        self.lowerRateLimitField.setText(str(self.user.getLowerRateLimit()))
        self.upperRateLimitField.setText(str(self.user.getUpperRateLimit()))
        self.atrialAmplitudeField.setText(str(self.user.getAtrialAmplitude()))
        self.atrialPulseWidthField.setText(str(self.user.getAtrialPulseWidth()))
        self.ventricularAmplitudeField.setText(str(self.user.getVentricularAmplitude()))
        self.ventricularPulseWidthField.setText(str(self.user.getVentricularPulseWidth()))
        self.vrpField.setText(str(self.user.getVRP()))
        self.arpField.setText(str(self.user.getARP()))
        self.handlePacedModeChange()

    def saveToUser(self):
        print(f"Saving attributes for {self.user.username}")
        self.errorLabel.setText("")
        try:
            self.user.setLowerRateLimit(self.lowerRateLimitField.text())
            self.user.setUpperRateLimit(self.upperRateLimitField.text())
            self.user.setAtrialAmplitude(self.atrialAmplitudeField.text())
            self.user.setAtrialPulseWidth(self.atrialPulseWidthField.text())
            self.user.setVentricularAmplitude(self.ventricularAmplitudeField.text())
            self.user.setVentricularPulseWidth(self.ventricularPulseWidthField.text())
            self.user.setVRP(self.vrpField.text())
            self.user.setARP(self.arpField.text())
            self.user.serialize()
        except Exception as e:
            print(f"Error Saving: {e}")
            self.errorLabel.setText(f"Error Saving: {e}")

    def logOut(self):
        self.user = None
        loginScreen.logUserOut()
        SceneManager.setCurrentIndex(SceneManager.currentIndex() - 1)

    def handlePacedModeChange(self):
        self.errorLabel.setText("")
        self.user.setBradycardiaOperatingMode(self.pacedComboBox.currentText()[0] + self.sensedComboBox.currentText()[0] \
                                              + self.responseComboBox.currentText()[0])
        if self.user.getBradycardiaOperatingMode() in ['AAI', 'AAT']:
            self.hideFields()
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)
            self.atrialAmplitudeLabel.setHidden(False)
            self.atrialAmplitudeField.setHidden(False)
            self.atrialPulseWidthLabel.setHidden(False)
            self.atrialPulseWidthField.setHidden(False)
            self.arpLabel.setHidden(False)
            self.arpField.setHidden(False)
        elif self.user.getBradycardiaOperatingMode() == 'AOO':
            self.hideFields()
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)
            self.atrialAmplitudeLabel.setHidden(False)
            self.atrialAmplitudeField.setHidden(False)
            self.atrialPulseWidthLabel.setHidden(False)
            self.atrialPulseWidthField.setHidden(False)
        elif self.user.getBradycardiaOperatingMode() in ['VVT', 'VVI', 'VDD']:
            self.hideFields()
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)
            self.ventricularAmplitudeLabel.setHidden(False)
            self.ventricularAmplitudeField.setHidden(False)
            self.ventricularPulseWidthLabel.setHidden(False)
            self.ventricularPulseWidthField.setHidden(False)
            self.vrpLabel.setHidden(False)
            self.vrpField.setHidden(False)
        elif self.user.getBradycardiaOperatingMode() == 'VOO':
            self.hideFields()
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)
            self.ventricularAmplitudeLabel.setHidden(False)
            self.ventricularAmplitudeField.setHidden(False)
            self.ventricularPulseWidthLabel.setHidden(False)
            self.ventricularPulseWidthField.setHidden(False)
        elif self.user.getBradycardiaOperatingMode() == 'DOO':
            self.hideFields()
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)
            self.atrialAmplitudeLabel.setHidden(False)
            self.atrialAmplitudeField.setHidden(False)
            self.atrialPulseWidthLabel.setHidden(False)
            self.atrialPulseWidthField.setHidden(False)
            self.ventricularAmplitudeLabel.setHidden(False)
            self.ventricularAmplitudeField.setHidden(False)
            self.ventricularPulseWidthLabel.setHidden(False)
            self.ventricularPulseWidthField.setHidden(False)
        elif self.user.getBradycardiaOperatingMode() in ['DDI', 'DDD']:
            self.hideFields()
            self.lowerRateLimitLabel.setHidden(False)
            self.lowerRateLimitField.setHidden(False)
            self.upperRateLimitLabel.setHidden(False)
            self.upperRateLimitField.setHidden(False)
            self.atrialAmplitudeLabel.setHidden(False)
            self.atrialAmplitudeField.setHidden(False)
            self.atrialPulseWidthLabel.setHidden(False)
            self.atrialPulseWidthField.setHidden(False)
            self.ventricularAmplitudeLabel.setHidden(False)
            self.ventricularAmplitudeField.setHidden(False)
            self.ventricularPulseWidthLabel.setHidden(False)
            self.ventricularPulseWidthField.setHidden(False)
            self.arpLabel.setHidden(False)
            self.arpField.setHidden(False)
            self.vrpLabel.setHidden(False)
            self.vrpField.setHidden(False)
        else:
            self.hideFields()
            print(f"{self.user.getBradycardiaOperatingMode()} is an invalid Bradycardia Operating Mode")
            self.errorLabel.setText(f"{self.user.getBradycardiaOperatingMode()} is an invalid Bradycardia Operating Mode")



app = QApplication([])
SceneManager = QStackedWidget()
SceneManager.setFixedSize(1600, 800)
DeviceControllerMonitor = DeviceControllerMonitor()
loginScreen = loginScreen()

SceneManager.addWidget(loginScreen)
SceneManager.addWidget(DeviceControllerMonitor)
SceneManager.show()
sys.exit(app.exec())
