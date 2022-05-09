#include "TPoint.h"

//задання значення координат точки
void TPoint::set(int a, int b, int c) 
{
	x = a; y = b; z = c;
}

/*перевантаження оператора "+=" для
збільшення всіх координат на задану величину*/
const TPoint TPoint::operator+=(const float add)
{
	x += add; y += add; z += add; return *this;
}

//введення координат точки
void TPoint::input()
{
	cout << "\nEnter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter z: ";
	cin >> z;
}

//виведення координат точки
void TPoint::output()
{
	cout << setw(4) << x
		<< setw(4) << y
		<< setw(4) << z;
}