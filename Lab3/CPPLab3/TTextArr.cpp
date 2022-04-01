#include "TTextArr.h"

//створення масиву об'єктів класу
void TTextArr::textArrGen()
{
	do	//перевірка на коректність вводу
	{
		cout << "Enter the size of array: ";
		cin >> size;
	} while (size < 1);
	arr = new TText[size];	
}

//введення тектсу в масив
void TTextArr::textArrInput()
{
	int choice;
	do
	{
		do
		{
			cout << "\nEnter the number of text you want to add strings to or enter 0 to stop: ";
			cin >> choice;
			choice--;
		} while (choice < -1 || choice >= size); //перевірка вводу
		if (choice != -1)	//якщо користувач вибрав текст
		{
			arr[choice].textInput();	//введення тексту, вибраного користувачем
		}
	} while (choice != -1);	//кінець вводу, якщо користувач не вибрав жоден текст
}

//виведення масиву текстів
void TTextArr::textArrOutput()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nText #" << i + 1 << '\n';
		arr[i].textOutput();
	}
}

//визначення тексту з найменшим відсотком символів-цифр
void TTextArr::symbolPercComp()
{
	float min = 100;
	int minPos = 0;
	for (int i = 0; i < size; i++)
	{
		float perc = arr[i].symbolPerc(); //визначення відсотка символів-цифр у окремому тексті
		cout << "\nText #" << i + 1 << " symbol percentage: " << setw(6) << fixed << setprecision(2) << perc << '%';
		if (min > perc)	//порівняння відсотка символів-цифр у окремому тексті з поточним мінімальним
		{
			min = perc;
			minPos = i;	//збереження позиції тексту
		}
	}
	cout << "\n\nText #" << minPos + 1 << " has the lowest percentage: " << setw(6) << fixed << setprecision(2) << min << "%\n\n";
}

//видалення масиву з пам'яті
void TTextArr::textArrDel()
{
	delete[size] arr;
	size = 0;
}