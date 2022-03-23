#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "TText.h"
using namespace std;

//структура масиву об'єктів класу
struct TTextArr
{
	TText* arr; //динамічний масив об'єктів класу
	int size;	//розмір масиву
};

TTextArr textArrGen();			//створення масиву об'єктів класу
void textArrInput(TTextArr);	//введення текстів масиву
void textArrOutput(TTextArr);	//виведення масиву текстів
void symbolPercComp(TTextArr);	//визначення тексту з найменшим відсотком символів-цифр