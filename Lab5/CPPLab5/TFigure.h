#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class TFigure
{
public:
	virtual float area() = 0;		//площа поверхні фігури
	virtual float volume() = 0;		//об'єм фігури
	virtual void randomValue() = 0;	//випадкове значення фігури
	virtual void output() = 0;		//виведення інформації про фігуру
	float funcChoice(string str)	//вибір між знаходженням площі і об'єму
	{ return str == "volume" ? volume() : 
		(str == "area" ? area() : 0); }
};