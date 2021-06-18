#pragma once
class CircularLinkedList;
class CNode
{
private:
	int data;
	CNode* next;
public:
	friend class CircularLinkedList;
};

class CircularLinkedList
{
private:
	CNode* head;
public:
	CircularLinkedList(int* A, int n);
	void Display();
	void RDisplay(CNode* p);
	CNode* getHead() { return head; }
	~CircularLinkedList();
	void Insert(int position, int x);
	int Length();
};
