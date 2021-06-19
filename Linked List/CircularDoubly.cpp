#include "CircularDoubly.h"
#include <iostream>
using namespace std;

CircularDoubly::CircularDoubly(int A[], int n)
{
	CDNode* t, * tail;
	head = new CDNode;
	head->data = A[0];
	head->next = head;
	head->prev = head;
	tail = head;
	for (int i = 1; i < n; i++)
	{
		t = new CDNode;
		t->data = A[i];
		t->next = tail->next;
		t -> prev = tail;
		head->prev = t;
		tail->next = t;
		tail = t;
	}
}

void CircularDoubly:: Display()
{
	CDNode* p = head;
	do
	{
		cout << p->data << "->";
		p = p->next;
	} while (p != head);
}

void CircularDoubly::Insert(int position, int x)
{
	CDNode* t, * p;
	if (position<0 || position > Length())
		return;
	//before head
	if (position == 0)
	{	
		t = new CDNode;
		t->data = x;
		if (head == nullptr)
		{
			head = t;
			t->next = head;
			t->prev = head;
			return;
		}
		t->next = head;
		t->prev = head->prev;
		head->prev->next = t;
		head->prev = t;
		head = t;
	}
	else
	{
		p = head;
		for (int i = 0; i < position - 1; i++)
		{
			p = p->next;//move to target
		}
		t = new CDNode;
		t->data = x;
		t->next = p->next;
		t->prev = p;
		p->next->prev = t;
		p->next = t;
	}
}

int CircularDoubly::Length()
{
	if (head == nullptr)
		return 0;
	CDNode* p=head;
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != head);
	return len;
}

int CircularDoubly:: Delete(int position)
{
	CDNode* p;
	int x;
	p = head;
	if (position <0 || position > Length())
		return -1;
	if (position == 1)
	{
		x = head->data;
		while (p->next != head)
			p = p->next;
		if (p == head)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			p->next = head->next;
			head->next->prev = p;
			delete head;
			head = p->next;
		}
	}
	else
	{
		for (int i = 0; i < position-1; i++)
		{
			p = p->next;
		}
		x = p->data;
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
	}
	return x;
}