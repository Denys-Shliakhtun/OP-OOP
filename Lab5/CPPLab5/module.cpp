#include "module.h"

//введення розміру масиву
int sizeInput(string str)
{
	int n;
	cout << "Enter the size of array for " << str << ": ";
	cin >> n;
	return n;
}

//виведення масиву об'єктів
void arrOutput(int size, TFigure** arr)
{
	for (int i = 0; i < size; i++)
		arr[i]->output();
	cout << endl;
}

//знаходження максимального або мінімального значення площі поверхні або об'єму у масиві об'єктів
void arrMaxMin(int size, TFigure** arr, string str, string method, bool(*func)(float, float))
{
	float value = (*arr)->funcChoice(method); //значення, яке шукається
	int pos = 1;	//позиція значення, яке шукається
	float temp;		//значення площі або об'єму поточного об'єкта
	for (int i = 0; i < size; i++)
	{
		temp = arr[i]->funcChoice(method);
		cout << "#" << setw(3) << left << i+1 << internal << ' ' << fixed << setw(10) << setprecision(2) << temp << endl;
		if (func(temp, value))	//func може приймати значення boolMax та boolMin
		{
			value = temp;
			pos = i;
		}
	}
	cout << str << ": " << setprecision(2) << value << " at position " << pos + 1 << endl;
}

//чи є перший параметр більший за другий
bool boolMax(float a, float b)
{
	return a > b ? true : false;
}

//чи є перший параметр менший за другий
bool boolMin(float a, float b)
{
	return a < b ? true : false;
}

//видадення масиву з динамічної пам'яті
void arrDelete(int size, TFigure** arr)
{
	for (int i = 0; i < size; i++)
	{
		 delete arr[i];
	}
	delete[size] arr;
}