#pragma once
#include <iostream>
#include <iomanip>
#include "TPoint.h"

class TTriangle
{
	TPoint p1, p2, p3;	//вершини трикутника
	const int num;		//порядковий номер трикутника
	static int count;	//загальна кількість створених об'єктів класу
public:
	TTriangle(TPoint a, TPoint b, TPoint c);//конструктор зі списком ініціалізації
	TTriangle(int a, int b, int c);			//конструктор з параметрами
	TTriangle(TTriangle&);					//конструктор копіювання
	TPoint getCertainVertex(int);	//геттер певної вершини трикутника
	void getAllVertices(TPoint&, TPoint&, TPoint&);	//геттер для всіх вершин трикутника
	int getNum() { return num; };	//геттер дря порядкового номера
	static int getCount() { return TTriangle::count; }; //геттер для кількості створених об'єктів
	float perimeter();	//обчислення периметру трикутника
	TTriangle operator++();					//перевантаження префіксного "++"
	TTriangle operator++(int notused);		//перевантаження постфіксного "++"
	const TTriangle operator+=(const float add);	//перевантаження "+="
	void output();	//виведення даних про трикутник
	~TTriangle();	//деструктор
};