#pragma once
#include <iostream>

struct Node
{
	float data;		//дані вершини
	Node* left;		//посилання на лівого нащадка
	Node* right;	//посилання на правого нащадка
public:	
	//конструктор з параметром
	Node(float value);
	
	//геттери
	float getData() { return data; };
	Node* getLeftPointer() { return left; };	
	Node* getRightPointer() { return right; };

	//вставлення нової вершини-нащадка
	//pos == 1 -> left, pos == 2 -> right
	Node* insertNodePointer(Node* value, int pos);
};

//введення кількості елементів дерева
int numInput();

//генерація масиву дійсних чисел заданого розміру
float* arrGen(int num);

//виведення дерева
void treeOutput(const std::string& prefix, Node* node, bool isLeft);

class Tree
{
	Node* root; //корінь дерева
	
	//заповнення дерева заданими значеннями масиву
	Node* createTree(float* arr, int from, int num);
public:
	//конструктор за замовчуванням
	Tree() : Tree(numInput()) {};
	
	//конструктор з параметром, заповнення дерева випадковими значеннями
	Tree(int num) : Tree(arrGen(num), num) {};
	
	//конструктор з двома параметрами заповнення дерева
	Tree(float* arr, int num) { root = createTree(arr, 0, num); };
	
	//геттер
	Node* getRoot() { return root; };

	//знаходження середнього значення вершин дерева
	float getAverageBFS();
};