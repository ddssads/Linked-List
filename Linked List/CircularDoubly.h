#pragma once
class CircularDoubly;
class CDNode 
{
private:
	int data;
	CDNode* prev;
	CDNode* next;
public:
	friend class CircularDoubly;
};
class CircularDoubly
{
private:
	CDNode* head;
public:
	CircularDoubly() { head = nullptr; }
	CircularDoubly(int A[], int n);
	void Display();
	int Length();
	int Delete(int position);
	void Insert(int position, int x);
};

