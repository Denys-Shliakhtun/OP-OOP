from TFigure import TFigure
from math import pow
from math import pi
import random
class TCylinder(TFigure):
    def __init__(self, Radius, Height):
        self.radius = Radius    #радіус основи циліндра
        self.height = Height    #висота циліндра
    
    #конструктор за замовчуванням, випадкові значення
    def __init__(self):         
        self.randomValue()   
    
    #площа поверхні циліндра
    def area(self):
        return 2 * pi * self.radius * self.height

    #об'єм циліндра
    def volume(self):
        return pi * pow(self.radius, 2) * self.height

    #випадкове значення циліндра
    def randomValue(self):
        self.radius = random.randrange(1, 5)
        self.height = random.randrange(1, 10)

    #виведення інформації про циліндр
    def output(self):
        print("Cylinder: {} h, {} r".format(self.height, self.radius))