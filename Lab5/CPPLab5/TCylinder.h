#pragma once
#include "TFigure.h"

class TCylinder : public TFigure
{
	float radius, height; //радіус та висота
public:
	//конструктор за замовчуванням, який заповнює поля випадковими значеннями
	TCylinder() { randomValue(); }

	//конструктор зі списком ініціалізації
	TCylinder(float r, float h) : radius(r), height(h) {};
	
	//геттери
	float getRadius() { return radius; }
	float getHeight() { return height; }

	float area();		//площа поверхні циліндра
	float volume();		//об'єм циліндра
	void randomValue();	//випадкове значення циліндра
	void output();		//виведення інформації про циліндр
};