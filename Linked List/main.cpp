// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"
#include "Circular.h"
#include "Doubly.h"
#include "CircularDoubly.h"

int main()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 5,6,7,8 };
	CircularDoubly c1(A,4);
	c1.Delete(3);
	c1.Display();
}
