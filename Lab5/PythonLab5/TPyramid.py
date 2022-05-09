from TFigure import TFigure
from math import pow
from math import sqrt
import random
#правильна піраміда (в основі лежить правильний багатокутник)
class TPyramid(TFigure):
    def __init__(self, Basis, Side, Height):
        self.basis = Basis      #форма основи піраміди
        self.side = Side        #довжина сторони основи піраміди
        self.height = Height    #висота піраміди
    
    #конструктор за замовчуванням, випадкові значення
    def __init__(self):
        self.randomValue()

    #площа поверхні піраміди
    def area(self):
        if self.basis == "triangle":
            return pow(self.side, 2) * sqrt(3) / 4 + 1.5 * self.side * sqrt(pow((self.side / (2 * sqrt(3))), 2) + pow(self.height, 2))
        elif self.basis == "square":
            return self.side * self.side + 2 * self.side * sqrt(pow((self.side / 2), 2) + pow(self.height, 2))
    
    #об'єм піраміди
    def volume(self):
        if self.basis == "triangle":
            return pow(self.side, 2) * sqrt(3) / 4 * self.height / 3
        elif self.basis == "square":
            return self.side * self.side * self.height / 3
    
    #випадкове значення піраміди
    def randomValue(self):
        self.basis = random.choice(["triangle", "square"])
        self.side = random.randrange(1, 10)
        self.height = random.randrange(1, 10)
    
    #виведення інформації про піраміду
    def output(self):
        print("Pyramid: {} h, {} s, {}".format(self.height, self.side, self.basis))


