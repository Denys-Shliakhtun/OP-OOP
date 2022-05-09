#pragma once
#include "TFigure.h"

enum class figure;	//перелічувальний тип для позначення основи піраміди
string figureCheck(figure f);	//перевірка форми основи піраміди

//правильна піраміда (в основі лежить правильний багатокутник)
class TPyramid : public TFigure 
{
	figure basis;			//форма основи піраміди
	float side, height;		//довжина сторони основи та висота
public:
	//конструктор за замовчуванням, який заповнює поля випадковими значеннями
	TPyramid() { randomValue(); } 

	//конструктор зі списком ініціалізації
	TPyramid(figure f, float s, float h) : basis(f), side(s), height(h) {};
	
	//геттери
	figure getBasis() { return basis; }
	float getSide() { return side; }
	float getHeight() { return height; }

	float area();		//площа поверхні піраміди
	float volume();		//об'єм піраміди
	void randomValue();	//випадкове значення піраміди
	void output();		//виведення інформації про піраміду
};