#include "module.h"

//визначення відстані між двома точками
float sideLength(TPoint a, TPoint b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

//введення масиву точок
void pointArrInput(TPoint* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter coordinates for point #" << i + 1;
		arr[i].input();
	}
}

//введення масиву відстаней
void lenArrInput(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter distance for point #" << i + 1 << " : ";
		cin >> arr[i];
	}
}

//введення значення для додавання до координат трикутника
float addInput()
{
	float add;
	cout << "\nEnter add value: ";
	cin >> add;
	return add;
}

//знаходження найбільшого периметру
int maxPerimeter(TTriangle& T1, TTriangle& T2, TTriangle& T3)
{
	float per, 
		per1 = T1.perimeter(), 
		per2 = T2.perimeter(), 
		per3 = T3.perimeter();
	int pos;
	cout << "\nPerimeter of triangle #" << T1.getNum() << ": " << per1;
	cout << "\nPerimeter of triangle #" << T2.getNum() << ": " << per2;
	cout << "\nPerimeter of triangle #" << T3.getNum() << ": " << per3;
	
	if (per1 >= per2)
	{
		per = per1;
		pos = T1.getNum();
	}
	else
	{
		per = per2;
		pos = T2.getNum();
	}

	if(per3>per)
	{
		per = per3;
		pos = T3.getNum();
	}

	cout << "\nTriangle #" << pos << " has max perimeter: " << per << endl;

	return pos;
}