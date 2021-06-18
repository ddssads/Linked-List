// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"
#include "Circular.h"
#include "Doubly.h"

int main()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 5,6,7,8 };
	Doubly d1(A, 4);
	d1.Delete(1);
	d1.Display();
}
