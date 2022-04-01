#pragma once
#include <iostream>
#include <iomanip>
#include "TText.h"
using namespace std;

//клас масиву об'єктів класу абстракції тексту
class TTextArr
{
	TText* arr; //динамічний масив об'єктів класу
	int size;	//розмір масиву
public:
	void textArrGen();		//створення масиву об'єктів класу
	void textArrInput();	//введення текстів масиву
	void textArrOutput();	//виведення масиву текстів
	void symbolPercComp();	//визначення тексту з найменшим відсотком символів-цифр
	void textArrDel();		//видалення масиву з пам'яті
};