import sys
import os
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QLineEdit, QPushButton, QStackedWidget, QMainWindow, QDialog
from PyQt5.uic import loadUi
import PyQt5.QtCore as Qt
import User.user as User

class loginScreen(QMainWindow):

    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "MainWindow - LoginScreen.ui"), self)
        self.setFixedSize(1500, 800)
        def createUser():
            username = self.usernameField.text()
            try:
                if not username == "":
                    self.user = User.user(self.usernameField.text(), self.passwordField.text())
                else:
                    raise ValueError
            except Exception as e:
                if (username == ""): # Username cannot be empty
                    self.errorLabel.setText("Username cannot be empty")
                elif (type(e) == ValueError): # Too many users to create new one
                    self.errorLabel.setText("The max amount of users has been hit.\n \
                    Delete users before creating more.")
                elif (type(e) == KeyError): # Wrong password
                    self.errorLabel.setText("Wrong Password")
                else: # Unknown Error!
                    self.errorLabel.setText(f"Unhandled Error: {e}")
                return False


            if self.user:
                #Created user succesfully
                #switch to logged in screen
                print("created user")
                DeviceControllerMonitor.setUser(self.user)
                SceneManager.setCurrentIndex(SceneManager.currentIndex() + 1)
            else:
                print("here")
                self.welcomeScene()

        self.loginButton.clicked.connect(createUser)

    def logUserOut(self):
        self.user = None

class DeviceControllerMonitor(QDialog):
    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "EditProperties Screen.ui"), self)
        self.setFixedSize(1500, 800)
        self.saveAllButton.clicked.connect(self.saveToUser)
        self.logoutButton.clicked.connect(self.logOut)
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

    def saveToUser(self):
        self.user.setLowerRateLimit(self.lowerRateLimitField.text())
        self.user.setUpperRateLimit(self.upperRateLimitField.text())
        self.user.setAtrialAmplitude(self.atrialAmplitudeField.text())
        self.user.setAtrialPulseWidth(self.atrialPulseWidthField.text())
        self.user.setVentricularAmplitude(self.ventricularAmplitudeField.text())
        self.user.setVentricularPulseWidth(self.ventricularPulseWidthField.text())
        self.user.setVRP(self.vrpField.text())
        self.user.setARP(self.arpField.text())
        self.user.serialize()

    def logOut(self):
        self.user = None
        loginScreen.logUserOut()
        SceneManager.setCurrentIndex(SceneManager.currentIndex() - 1)


app = QApplication([])
SceneManager = QStackedWidget()
SceneManager.setFixedSize(1500,800)
DeviceControllerMonitor = DeviceControllerMonitor()
loginScreen = loginScreen()


SceneManager.addWidget(loginScreen)
SceneManager.addWidget(DeviceControllerMonitor)
SceneManager.show()
sys.exit(app.exec())
