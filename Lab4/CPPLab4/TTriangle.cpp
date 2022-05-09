#include "TTriangle.h"

//статична змінна кількості створених об'єктів класу
int TTriangle::count; 

//конструктор зі списком ініціалізації
TTriangle::TTriangle(TPoint a, TPoint b, TPoint c)
	: p1(a), p2(b), p3(c), num(++count) {} 

//конструктор з параметрами за замовчуванням шляхом відкладення відрізків на осях координат
TTriangle::TTriangle(int a = 1, int b = 1, int c = 1) : num(++count) 	
{
	p1.set(a, 0, 0);
	p2.set(0, b, 0);
	p3.set(0, 0, c);
}

//конструктор копіювання
TTriangle::TTriangle(TTriangle& T) : num(++count) 
{
	T.getAllVertices(p1, p2, p3);
}

//геттер певної вершини трикутника
TPoint TTriangle::getCertainVertex(int n = 1) 
{
	switch (n)
	{
	case 1:
		return p1;
	case 2:
		return p2;
	case 3:
		return p3;
	default:
		cout << "\nWrong input detected. Value of first verticle is returned.";
		return p1;
	}
}

//геттер для всіх вершин трикутника
void TTriangle::getAllVertices(TPoint& a, TPoint& b, TPoint& c)	
{
	a = p1;	b = p2;	c = p3;
}

//обчислення периметру трикутника
float TTriangle::perimeter()
{
	return sideLength(p1, p2) + sideLength(p2, p3) + sideLength(p1, p3);
}

//перевантаження префіксного "++" для збільшення х-координат
TTriangle TTriangle::operator++()
{
	p1.x++; p2.x++;	p3.x++;
	return *this;
}

//перевантаження постфіксного "++" для збільшення у-координат
TTriangle TTriangle::operator++(int notused)
{
	p1.y++;	p2.y++;	p3.y++;
	return *this;
}

//перевантаження "+=" для збільшення всіх координат на задану величину
const TTriangle TTriangle::operator+=(const float add)
{
	p1 += add; p2 += add; p3 += add;
	return *this;
}

//виведення даних про трикутник
void TTriangle::output()
{
	cout << "\nTriangle #" << num <<
		"\nP1:"; p1.output();
	cout << "\nP2:"; p2.output();
	cout << "\nP3:"; p3.output();
	cout << "\nGeneral number of triangles: " << count << endl;
}

//деструктор
TTriangle::~TTriangle()
{
	count--;
}