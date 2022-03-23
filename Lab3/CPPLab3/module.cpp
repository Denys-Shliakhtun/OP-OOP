#include "module.h"

//створення масиву об'єктів класу
TTextArr textArrGen()
{
	TTextArr text;
	do	//перевірка на коректність вводу
	{
		cout << "Enter the size of array: ";
		cin >> text.size;

	} while (text.size < 1);
	text.arr = new TText[text.size];
	return text;
}

//введення тектсу в масив
void textArrInput(TTextArr text)
{
	int choice;
	do
	{
		do
		{
			cout << "\nEnter the number of text you want to add strings to or enter 0 to stop: ";
			cin >> choice;
			choice--;
		} while (choice < -1 || choice >= text.size); //перевірка вводу
		if (choice != -1)	//якщо користувач вибрав текст
		{
			text.arr[choice].textInput();	//введення тексту, вибраного користувачем
		}
	} while (choice != -1);	//кінець вводу, якщо користувач не вибрав жоден текст
}

//виведення масиву текстів
void textArrOutput(TTextArr text)
{
	for (int i = 0; i < text.size; i++)
	{
		cout << "\nText #" << i + 1 << '\n';
		text.arr[i].textOutput();
	}
}

//визначення тексту з найменшим відсотком символів-цифр
void symbolPercComp(TTextArr text)
{
	float min = FLT_MAX;
	int minPos = 0;
	for (int i = 0; i < text.size; i++)
	{
		float perc = text.arr[i].symbolPerc(); //визначення відсотка символів-цифр у окремому тексті
		cout << "\nText #" << i + 1 << " symbol percentage: " << setw(6) << fixed << setprecision(2) << perc << '%';
		if (min > perc)	//порівняння відсотка символів-цифр у окремому тексті з поточним мінімальним
		{
			min = perc;
			minPos = i;	//збереження позиції тексту
		}
	}
	cout << "\n\nText #" << minPos + 1 << " has the lowest percentage: " << setw(6) << fixed << setprecision(2) << min << "%\n\n";
}