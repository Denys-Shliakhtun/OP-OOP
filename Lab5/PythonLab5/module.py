#генерація масиву об'єктів заданого класу
def arrGen(word, Class):
    arr = [Class() for i in range(int(input("Enter the number of "+word+": ")))]
    [arr[i].output() for i in range(len(arr))]
    print()
    return arr

#знаходження максимального або мінімального значення у масиві
def arrMaxMin(arr, func, method):
    arrValue = [arr[i].funcChoice(method) for i in range(len(arr))]
    [print("#{:<3} {:>6.2f}".format(i+1,arrValue[i])) for i in range(len(arrValue))]
    Value = func(arrValue)
    pos = arrValue.index(Value)
    return Value, pos+1