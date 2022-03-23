#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

//клас абстракції тексту
class TText
{
	vector<string> text;	//вектор рядків
	void stringAdd(string); //операція додавання рядка до тексту
public:
	void textInput();		//порядкове введення тексту
	void textOutput();		//виведення тексту
	float symbolPerc();		//визначення відсотка символів-цифр у тексті
};