#include "Tree.h"
#include <iomanip>
#include <queue>

//конструктор з параметром
Node::Node(float value)
{
	data = value;
	left = nullptr;
	right = nullptr;
}

//вставлення нової вершини-нащадка
//pos == 1 -> left, pos == 2 -> right
Node* Node::insertNodePointer(Node* value, int pos)
{
	switch (pos)
	{
	case 1:
		left = value;
		return left;
	case 2:
		right = value;
		return right;
	}
	return nullptr;
}

//заповнення дерева заданими значеннями масиву
Node* Tree::createTree(float* arr, int from, int num)
{
	if (num == 0)
		return nullptr;
	Node* p = new Node(arr[from]);
	int numleft = num / 2;
	int numright = num - numleft - 1;
	p->insertNodePointer(createTree(arr, from + 1, numleft), 1);
	p->insertNodePointer(createTree(arr, from + 1 + numleft, numright), 2);
	return p;
}

//знаходження суми значень вершин дерева
float Tree::getAverageBFS()
{
	std::queue <Node*> plan; //черга для пошуку в ширину
	Node* temp = root;		 //проміжна змінна
	plan.push(temp);		 //додання кореню дерева в чергу
	float sum = 0;			 //сума значень
	float count = 0;		 //кількість вершин
	Node* temp2;			 //друга проміжна змінна
	while (plan.size()>0) //поки в черзі є елементи
	{
		//діставання елемента з черги
		temp = plan.front();
		plan.pop();

		//додавання лівого нащадка до черги
		temp2 = temp->getLeftPointer();
		if (temp2!=nullptr)		
			plan.push(temp2);		

		//додавання правого нащадка до черги
		temp2 = temp->getRightPointer();
		if (temp2 != nullptr)		
			plan.push(temp2);		

		//додавання значення temp до загальної суми
		if(temp!=nullptr)
			sum += temp->getData();
		
		count++;
	}
	return sum/count;
}

//генерація масиву дійсних чисел заданого розміру
float* arrGen(int num)
{
	float* arr = new float[num];
	for (int i = 0; i < num; i++)
		arr[i] = float(rand() % 100) / 10;
	return arr;
}

//виведення дерева
void treeOutput(const std::string& prefix, Node* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << "'--";

		std::cout << std::fixed << std::setprecision(1) << node->getData() << std::endl;

		treeOutput(prefix + (isLeft ? "|   " : "    "), node->getLeftPointer(), true);
		treeOutput(prefix + (isLeft ? "|   " : "    "), node->getRightPointer(), false);
	}
}

//введення кількості елементів дерева
int numInput()
{
	int num;
	std::cout << "Enter the number of nodes: ";
	std::cin >> num;
	return num;
}