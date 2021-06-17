#pragma once
class CircularLinkedList;
class Node
{
private:
	int data;
	Node* next;
public:
	friend class CircularLinkedList;
};

class CircularLinkedList
{
private:
	Node* head;
public:
	CircularLinkedList(int* A, int n);
	void Display();
	void recursiveDisplay(Node* p);
	Node* getHead() { return head; }
	~CircularLinkedList();
};
