#pragma once
#include <iostream>
#include <iomanip>
#include "TCylinder.h"
#include "TPyramid.h"

int sizeInput(string str);	//введення розміру масиву

void arrOutput(int size, TFigure** arr); //виведення масиву об'єктів

//знаходження максимального або мінімального значення у масиві
void arrMaxMin(int size, TFigure** arr, string str, string method, bool(*func)(float, float));

bool boolMax(float a, float b); //чи є перший параметр більший за другий

bool boolMin(float a, float b); //чи є перший параметр менший за другий

void arrDelete(int size, TFigure** arr); //видадення масиву з динамічної пам'яті

//шаблонна функція для генерації масиву об'єктів
template <class T>
TFigure** arrGen(int size)
{
	TFigure** arr = new TFigure * [size];
	for (int i = 0; i < size; i++)
		arr[i] = new T();
	return arr;
}