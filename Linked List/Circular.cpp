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

void CircularLinkedList::Insert(int position, int x)
{
	CNode* t,*p;
	p = head;
	if (position < 0 || position > Length())
		return;
	//before head
	if (position == 0)
	{
		t = new CNode;
		t->data = x;
		if (head == NULL)
		{
			head = t;
			head->next = head;
		}
		else
		{
			while (p->next != head) p = p->next;
			p -> next = t;
			t -> next = head;
			head = t;//optional
		}
	}
	else
	{
		for (int i = 0; i < position - 1; i++) p = p->next;
		t = new CNode;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}

int CircularLinkedList::Length()
{
	int len = 0;
	CNode* p = head;
	do
	{
		len++;
		p = p->next;
	} while (p != head);
	return len;
}
