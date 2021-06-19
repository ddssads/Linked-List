#include "Doubly.h"
#include <iostream>
using namespace std;

Doubly::Doubly(int A[], int n)
{
	DNode* t, * last;
	first = new DNode;
	first->data = A[0];
	first->prev = nullptr;
	first->next = nullptr;
	last = first;
	for (int i = 1; i < n; i++)
	{
		t = new DNode;
		t->data = A[i];
		t->prev = last;
		t->next = nullptr;
		last->next = t;
		last = t;
	}
}

void Doubly::Display()
{
	DNode* p = first;
	while (p)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << endl;
}

int Doubly:: Length()
{
	int len = 0;
	DNode* p = first;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

void Doubly::Insert(int position, int x)
{
	DNode* p, * t;
	if (position < 0 || position > Length())
		return;
	if (position == 0)
	{
		t = new DNode;
		t->data = x;
		t->next = first;
		t->prev = nullptr;
		first->prev = t;
		first = t;
	}
	else
	{
		p = first;
		for (int i = 0; i < position - 1; i++)
			p = p->next;
		t = new DNode;
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next)
			p->next->prev = t;
		p->next = t;
	}	
}

int Doubly::Delete(int position)
{
	DNode* p = first;
	int x;
	if (position <0 || position > Length())
		return -1;
	if (position == 1)
	{
		first = first->next;
		if (first)
			first->prev = nullptr;
		x = p->data;
		delete p;
	}
	else
	{
		for (int i = 0; i < position - 1; i++)
			p = p->next; //move to target
		p->prev -> next = p->next;
		if (p->next)
			p->next -> prev = p->prev;
		x = p->data;
		delete p;
	}
	return x;
}

void Doubly::Reverse()
{
	DNode* p = first;
	DNode* temp = nullptr;
	while (p)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = temp;
		//p != null 沒這個條件的話 while會讓p=null p->next==null就會出問題 因為p不存在
		if (p!=nullptr &&p->next == nullptr)
			first = p;
	}
}