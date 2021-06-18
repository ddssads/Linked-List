// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"
#include "Circular.h"

int main()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 5,6,7,8 };
	CircularLinkedList C1(A, 4);
	C1.Insert(5, 10);
	C1.Display();
	C1.~CircularLinkedList();
}
