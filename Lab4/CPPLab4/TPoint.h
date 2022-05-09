#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class TPoint
{
	float x, y, z; //координати точки
public:
	void set(int a, int b, int c); //задання значення координат точки
	const TPoint operator+=(const float add); //перевантаження оператора "+="
	void input();	//введення координат точки
	void output();	//виведення координат точки
	friend float sideLength(TPoint a, TPoint b); //визначення довжини між двома точками
	friend class TTriangle; //дружній клас трикутник
};