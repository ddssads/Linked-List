#include "Circular.h"
CircularLinkedList::CircularLinkedList(int* A, int n)
{
	Node* t, * tail;
	head = new Node;
	head->data = A[0];
	head->next = head;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = tail->next;
		tail->next = t;
		tail = t;
	}
}