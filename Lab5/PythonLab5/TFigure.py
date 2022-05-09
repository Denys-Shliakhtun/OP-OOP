class TFigure(object):
    def area():         #площа поверхні фігури
        pass
    def volume():       #об'єм фігури
        pass
    def randomValue():  #випадкове значення фігури
        pass
    def output():       #виведення інформації про фігуру
        pass

    #вибір між знаходженням площі і об'єму
    def funcChoice(self, word):
        if word == "volume":
            return self.volume()
        elif word == "area":
            return self.area()

