#pragma once
#include <iostream>
#include <iomanip>
#include "TTriangle.h"

float sideLength(TPoint a, TPoint b); //визначення відстані між двома точками
void pointArrInput(TPoint* arr, int n); //введення масиву точок
void lenArrInput(int* arr, int n); //введення масиву відстаней
float addInput(); //введення значення для додавання до координат трикутника
int maxPerimeter(TTriangle&, TTriangle&, TTriangle&); //найбільший периметр