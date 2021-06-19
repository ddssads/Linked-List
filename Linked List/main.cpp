// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"
#include "Circular.h"
#include "Doubly.h"
#include "CircularDoubly.h"

int main()
{
	int A[] = { 1,2,3,4,6,7 };
	int B[] = { 5,6,7,8 };
	LinkedList c1(A,6);
	cout<<c1.Mid();
}
