#pragma once
class Doubly;
class DNode
{
private:
	DNode* prev;
	int data;
	DNode* next;
public:
	friend class Doubly;
};
class Doubly
{
private:
	DNode* first;
public:
	Doubly() { first = nullptr; }
	Doubly(int A[], int n);
	void Display();
	int Length();
	void Insert(int position, int x);
	int Delete(int position);
	void Reverse();
};



