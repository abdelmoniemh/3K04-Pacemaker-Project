import sys

from PyQt6.QtWidgets import QApplication, QLabel, QWidget, QVBoxLayout, QLineEdit, QPushButton
#import PyQt6.QtCore as Qt

import User.user as User

class DeviceControllerMonitor(QWidget):
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
                super(loggedInScreen(self.user)).__init__()

            else:
                pass


        button.clicked.connect(createUser)

class loggedInScreen(QWidget):

    def __init__(self, user):
        super().__init__()
        self.user = user
        self.loggedIn = True
        self.layout = QVBoxLayout()
        attributes = self.user.getAllAttributes()
        for attr, value in attributes:
            self.layout.addWidget(QLabel(f"<h1>{attr}: {value}</h1>"))
        self.setLayout(self.layout)
        print("Set Layout")
        self.show()


app = QApplication([])
window = DeviceControllerMonitor()
window.show()
sys.exit(app.exec())




"""
window = QWidget()
window.setWindowTitle("Device Controller Manager")
window.setGeometry(400, 400, 280, 80)


usernameFeild = QLineEdit()



layout = QVBoxLayout()
usernameFeild.setFixedWidth(150)
layout.addWidget(usernameFeild)

button = QPushButton("Submit")
def outputUser():
    print(usernameFeild.text())

button.clicked.connect(outputUser)

layout.addWidget(button)

window.show()
window.setLayout(layout)
# 5. Run your application's event loop
sys.exit(app.exec())
"""