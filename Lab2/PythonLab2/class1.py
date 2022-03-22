#клас запису розкладу руху поїздів
class TTimeTable():
    def __init__(self,number,direction,hourDep,minuteDep,hourArr,minuteArr):
        self.number = number            #номер рейсу
        self.direction = direction      #напрямок руху
        self.hourDep = hourDep          #година відправлення
        self.minuteDep = minuteDep      #хвилина відправлення
        self.hourArr = hourArr          #година прибуття
        self.minuteArr = minuteArr      #хвилина прибуття


