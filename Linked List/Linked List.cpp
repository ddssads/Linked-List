// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"


int main()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 5,6,7,8 };
	LinkedList l1(A,4);
	LinkedList l2(B,4);
	l1.ReverseL();
	l1.Merge(l2.getFirstNode());
	l1.RDisplay();
}
