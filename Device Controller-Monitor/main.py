import sys

from PyQt6.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QLineEdit, QPushButton, QStackedWidget
#import PyQt6.QtCore as Qt

import User.user as User

class loginScreen(QWidget):
    def __init__(self):
        super().__init__()
        self.WIDTH = 500
        self.HEIGHT = 500
        self.resize(self.WIDTH,self.HEIGHT)
        self.setWindowTitle("DeviceControllerManager")
        self.loggedIn = False
        self.welcomeScene()
    def welcomeScene(self):
        welcomeScreen = QLabel("<h1>Welcome Screen</h1>")
        #welcomeScreen.move(round(self.WIDTH/2)- 100, round(self.HEIGHT/2) - 100)

        usernameFeild = QLineEdit()
        passwordFeild = QLineEdit()

        self.layout = QVBoxLayout()
        self.layout.addWidget(welcomeScreen)
        self.layout.addWidget(usernameFeild)
        self.layout.addWidget(passwordFeild)
        button = QPushButton("Login/Signup")
        self.layout.addWidget(button)
        self.setLayout(self.layout)

        def createUser():
            try:
                self.user = User.user(usernameFeild.text(), passwordFeild.text())
            except:
                print("error Handle")

            if self.user:
                #Created user succesfully
                #switch to logged in screen
                print("created user")
                #super(DeviceControllerMonitor, self)
                DeviceControllerMonitor.setUser(self.user)
                SceneManager.setCurrentIndex(SceneManager.currentIndex() + 1)
            else:
                print("here")
                self.welcomeScene()


        button.clicked.connect(createUser)

class DeviceControllerMonitor(QWidget):

    def __init__(self):
        super().__init__()
        self.loggedIn = False
        self.layout = QVBoxLayout()
        print("Set Layout")
        self.setLayout(self.layout)
    def setUser(self, user):
        self.loggedIn = True
        self.user = user
        attributes = self.user.getAllAttributes()
        for attr, value in attributes:
            self.layout.addWidget(QLabel(f"<h1>{attr}: {value}</h1>"))
        self.setLayout(self.layout)


app = QApplication([])
SceneManager = QStackedWidget()
loginScreen = loginScreen()
DeviceControllerMonitor = DeviceControllerMonitor()

SceneManager.addWidget(loginScreen)
SceneManager.addWidget(DeviceControllerMonitor)
SceneManager.show()
sys.exit(app.exec())



