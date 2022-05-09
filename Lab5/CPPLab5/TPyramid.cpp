#include "TPyramid.h"

//перелічувальний тип для позначення основи піраміди
enum class figure
{
	triangle = 3,	//основа - рівносторонній трикутник
	square = 4		//основа - квадрат
};

//перевірка форми основи піраміди
string figureCheck(figure f)
{
	return f == figure::triangle ? "triangle" : "square";
}

//площа поверхні піраміди
float TPyramid::area()
{
	switch (basis)
	{
	case figure::triangle:
		return pow(side, 2) * sqrt(3) / 4 + 1.5 * side * sqrt(pow((side / (2 * sqrt(3))), 2) + pow(height, 2));
	case figure::square:
		return side * side + side * sqrt(pow((side / 2), 2) * 2 + pow(height, 2));
	}
}

//об'єм піраміди
float TPyramid::volume()
{
	switch (basis)
	{
	case figure::triangle:
		return pow(side, 2) * sqrt(3) / 4 * height / 3;
	case figure::square:
		return side * side * height / 3;
	}
}

//випадкове значення піраміди
void TPyramid::randomValue()
{
	basis = figure(rand() % 2 + 3);
	side = rand() % 10 + 1;
	height = rand() % 10 + 1;
}

//виведення інформації про піраміду
void TPyramid::output()
{
	cout << "\nPyramid: " << setw(2) << height << " h, " << setw(2) << side << " s, " << figureCheck(basis);
}