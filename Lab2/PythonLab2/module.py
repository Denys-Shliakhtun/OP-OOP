import pickle
from class1 import TTimeTable

#вибір між створенням і доповненням файлу введених даних
def choice(fileName):
    while True:
        s = input("Enter 1 for new file or 2 to add to previous: ")
        if s == '1':    #відкриття бінарного файлу на запис
            return "wb"
        elif s == '2':  #відкриття бінарного файлу на дозапис в кінець файлу
            return "ab"
        print("Wrong imput. Try again.")

#введення окремого запису розкладу руху
def structInput():
    number = int(input("\nInput the number of train: "))
    direction = input("Input the direction of train: ")
    str = input("Input time of departure in format \"12:34\": ")
    #переведення формату "12:34" в два окремих числа
    hourDep = int(str[:str.find(':')])
    minuteDep = int(str[str.find(':')+1:])
    str = input("Input time of arrival in format \"12:34\": ")
    #переведення формату "12:34" в два окремих числа
    hourArr = int(str[:str.find(':')])
    minuteArr = int(str[str.find(':')+1:])
    return TTimeTable(number, direction, hourDep, minuteDep, hourArr, minuteArr)

#введення файлу
def fileInput(fileName, param):
    fileIn = open(fileName, param)
    flag = True
    while flag:
        #введення та запис окремого елемента розкладу в файл
        pickle.dump(structInput(), fileIn) 
        if input("Enter + to continue or any other symbol to stop: ") != '+':
            flag = False #закінчення введення, якщо введений символ не плюс
    fileIn.close()

#зчитування файлу
def fileRead(fileName):
    fileOut = open(fileName, 'rb')
    list = []
    flag = True
    while flag:
        try:
            #покласове перенесення даних з файлу до списку
            list.append(pickle.load(fileOut)) 
        except EOFError:
            #доки не наступить кінець файлу
            flag = False
    fileOut.close()
    return list

#виведення файлу
def fileOutput(fileName):
    print("\nFile {}:".format(fileName))
    i = 1
    for data in fileRead(fileName):
        print("#{:<5}{:<5}{:>30}   {:0>2}:{:0>2}  {:0>2}:{:0>2}".format(i, 
            data.number, data.direction, data.hourDep, data.minuteDep, 
            data.hourArr, data.minuteArr))
        i+=1

#створення файлу відповідно до задачі
def fileCreate(fileInName, fileOutName):
    fileOut = open(fileOutName, "wb") #відкриття файлу результату на запис
    for data in fileRead(fileInName): #зчитування файлу введених даних
        if timeCheck(data):               #якщо виконується умова відповідно до задачі
            pickle.dump(data, fileOut)        #запис у файл результатів
    fileOut.close()

#перевірка часу на відповідність умові задачі
def timeCheck(data):
    dep = data.hourDep + float(data.minuteDep) / 100
    arr = data.hourArr + float(data.minuteArr) / 100
    if dep < arr:   #якщо відправлення і прибуття відбуваються в межах одного дня
        flag = (dep <= 10 and arr <= 10) or (dep >= 18 and arr >= 18)
    else:           #якщо відправлення і прибуття відбуваються в різні дні
        flag = dep >= 18 and arr <= 10 
    return flag
