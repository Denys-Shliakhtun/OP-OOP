#include "TCylinder.h"

//площа поверхні циліндра
float TCylinder::area()
{
	return 2 * (float)M_PI* radius* height;
}

//об'єм циліндра
float TCylinder::volume()
{
	return (float)M_PI * (float)pow(radius, 2) * height;
}

//випадкове значення циліндра
void TCylinder::randomValue()
{
	height = float(rand() % 10) + 1;
	radius = float(rand() % 5) + 1;
}

//виведення інформації про циліндр
void TCylinder::output()
{
	cout << "\nCylinder: " << setw(2) << height << " h, " << setw(2) << radius << " r";
}