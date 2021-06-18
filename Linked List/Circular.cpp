#include "Circular.h"
#include <iostream>
using namespace std;
CircularLinkedList::CircularLinkedList(int* A, int n)
{
	CNode* t, * tail;
	head = new CNode;
	head->data = A[0];
	head->next = head;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		t = new CNode;
		t->data = A[i];
		t->next = tail->next;
		tail->next = t;
		tail = t;
	}
}

void CircularLinkedList::Display()
{
	CNode* p = head;
	do
	{
		cout << p->data << "->";
		p = p->next;
	} while (p != head);
}

void CircularLinkedList::RDisplay(CNode *p)
{
	static int flag = 0;
	if (p != head || flag == 0)
	{
		flag = 1;
		cout << p->data << "->";
		RDisplay(p->next);
	}
	flag = 0;
}

CircularLinkedList:: ~CircularLinkedList()
{
	CNode* p = head;
	while (p->next != head)
	{
		p = p -> next;
	}
	while (p != head)
	{
		p->next = head->next;
		delete head;
		head = p->next;
	}
	if (p == head)
	{
		delete head;
		head = nullptr;
	}
}
