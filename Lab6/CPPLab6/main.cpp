/*
Побудувати дерево, елементами якого є дійсні числа. 
Обчислити середнє арифметичне усіх його елементів.
*/

#include "Tree.h"

int main()
{
	srand(time(NULL));

	//створення дерева конструктором на замовчуванням
	Tree* tree = new Tree();

	//виведення дерева
	treeOutput("", tree->getRoot(), false);

	//виведення середнього значення вершин дерева
	std::cout << "Average: " << tree->getAverageBFS() << std::endl;

	system("pause");
}