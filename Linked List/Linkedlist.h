#pragma once
#include <iostream>
using namespace std;
class LinkedList;
class Node
{
private:
    int data;
    Node* next;
public:
    friend class LinkedList;
};

class LinkedList
{
private:
    Node* first;
    Node* last;
    Node* third;
public:
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        third = nullptr;
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void RDisplay();//Recursive
    void RDisplay(Node* p);
    Node* getFirstNode();
    int Count();
    int RCount(Node* p);//Recursive
    int Sum();
    int RSum(Node* p);//Recursive
    int Max();
    int RMax(Node* p);//Recursive
    int LSearch(int key); //linear search
    int RSearch(int key);
    int RSearch(Node* p, int key);
    void Insert(int position, int x);
    void InsertLast(int x);
    void SortedInsert(int x);
    int Delete(int position);
    int isSorted();
    void RemoveDuplicate();
    void ReverseE();//Elements
    void ReverseL();//Links
    void RReverse();//Recursive
    void RReverse(Node* q,Node *p);
    void Concatenate(Node* second);
    void Merge(Node *second);
    int Mid();
    int isLoop();
};

