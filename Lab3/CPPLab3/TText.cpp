#include "TText.h"

//операція додавання рядка до тексту
void TText::stringAdd(string str)
{
	text.push_back(str);
}

//порядкове введення тексту
void TText::textInput()
{
	cout << "\nEnter text:\n";
	string str;
	char s;
	do
	{
		cin.ignore(32767, '\n');
		getline(cin, str);
		stringAdd(str);
		cout << "Press + to continue or any other symbol to stop: ";
		cin >> s;
	} while (s == '+');
}

//виведення тексту
void TText::textOutput()
{
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << '\n';
}

//визначення відсотка символів-цифр у тексті
float TText::symbolPerc()
{
	int textSize = 0;
	int symbolCount = 0;

	for (int i = 0; i < text.size(); i++)
	{
		textSize += text[i].length();
		for (int j = 0; j < text[i].length(); j++)
			if (isdigit(text[i][j]))			
				symbolCount++;		
	}
	return (float)symbolCount / textSize * 100;
}