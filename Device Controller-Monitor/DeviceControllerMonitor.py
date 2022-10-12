import sys
import os
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QLineEdit, QPushButton, QStackedWidget, QMainWindow, QDialog
from PyQt5.uic import loadUi
import User.user as User

class loginScreen(QMainWindow):

    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "MainWindow - LoginScreen.ui"), self)
        self.setFixedSize(1500, 800)
        def createUser():
            try:
                self.user = User.user(self.usernameField.text(), self.passwordField.text())
            except:
                print("error Handle")

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

class DeviceControllerMonitor(QDialog):
    def __init__(self):
        super().__init__()
        loadUi(os.path.join("UI", "EditProperties Screen.ui"), self)
        self.setFixedSize(1500, 800)

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

app = QApplication([])
SceneManager = QStackedWidget()
DeviceControllerMonitor = DeviceControllerMonitor()
loginScreen = loginScreen()


SceneManager.addWidget(loginScreen)
SceneManager.addWidget(DeviceControllerMonitor)
SceneManager.show()
sys.exit(app.exec())
