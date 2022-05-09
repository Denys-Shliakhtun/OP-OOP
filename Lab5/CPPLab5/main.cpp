/*
клас TFigure
* просторова геометрична фігура
* методи обчислення площі поверхні і об'єму
нащадки TPyramid та TCylinder
створити n пірамід та m циліндрів
знайти циліндр з найбільшим об'ємом
знайти піраміду з найменшою площею поверхні
*/
#include "module.h"

int main()
{
	srand(time(NULL));

	//введення кількості пірамід і циліндрів
	int n = sizeInput("pyramids");
	int m = sizeInput("cylinders");

	//генерація і виведення масиву об'єктів класу TPyramid
	TFigure** arrPyr = arrGen<TPyramid>(n);
	arrOutput(n, arrPyr);

	//генерація і виведення масиву об'єктів класу TCylinder
	TFigure** arrCyl = arrGen<TCylinder>(m);
	arrOutput(m, arrCyl);	
	
	//знаходження піраміди з найменшою площею поверхні
	cout << endl << "Pyramids' area:\n";
	arrMaxMin(n, arrPyr, "Min area of pyramids", "area", &boolMin);
	
	//знаходження піраміди з найбільшою площею поверхні
	cout << endl << "Cylinders' volume:\n";
	arrMaxMin(m, arrCyl, "Max volume of cylinders", "volume", &boolMax);

	//видалення масивів з динамічної пам'яті
	arrDelete(n, arrPyr);
	arrDelete(m, arrCyl);

	cout << endl;	
	system("pause");
}