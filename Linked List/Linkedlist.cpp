#include "Linkedlist.h"
LinkedList::LinkedList(int A[], int n)
{
    Node* t ;
    first = new Node;
    first->data = A[0];
    first -> next = nullptr;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

LinkedList ::~LinkedList()
{
    Node* p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node* p = first;
    while (p != nullptr)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
}

void LinkedList:: RDisplay()
{
    RDisplay(first);
}

void LinkedList:: RDisplay(Node* p)
{
    if (p != NULL)
    {
        cout << p->data << " -> ";
        RDisplay(p->next);
    }
}

int LinkedList::Count()
{
    Node* p = first;
    int counter = 0;
    while (p != nullptr)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

int LinkedList::RCount(Node* p)
{
    if (p != NULL)
        return RCount(p->next) + 1;
    else
        return 0;
}

int LinkedList::Sum()
{
    Node* p = first;
    int s = 0;
    while (p)
    {
        s += p->data;
        p = p -> next;
    }
    return s;
}


int LinkedList::RSum(Node* p)
{
    if (!p)
        return 0;
    else
        return RSum(p->next) + p->data;
}

int LinkedList::Max()
{
    Node* p = first;
    int max = INT_MIN;
    while (p)
    {
        max = max > p->data ? max : p->data;
        p = p->next;
    }
    return max;
}

int LinkedList::RMax(Node* p)
{
    int max = INT_MIN;
    if (!p)
        return max;
    max = RMax(p->next);
    return max > p->data ? max : p->data;
}

int LinkedList::LSearch(int key)
{
    Node* q = nullptr;//previous node
    Node* p = first;
    while(p)
    {
        
        if (key == p->data)
        {
            if (!q)
                return p->data;
            q->next = p->next;
            p->next = first;
            first = p;
            return p->data;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return NULL;
}

int LinkedList::RSearch(int key)
{
    return RSearch(first,key);
}
int LinkedList::RSearch(Node* p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p->data;
    }
    return RSearch(p->next, key);    
}

void LinkedList::Insert(int position, int x)
{
    Node* p, *t;
    if (position < 0 || position > Count())
        return;
    if (position == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if (position > 0)
    {
        p = first;
        for (int i = 0; i < position - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

/*void LinkedList::InsertLast(int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;
    if (!first)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}*/

void LinkedList::SortedInsert(int x)
{
    Node* t, * q = NULL;
    Node* p = first;
    t = new Node;
    t->data = x;
    t->next = NULL;
    //first 指向 t
    if (first == NULL)
        first = t;
    else
    {
        while (p->data < x)
        {
            q = p;
            p = p->next;
        }
        // t 指向first
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int LinkedList::Delete(int position)
{
    Node* q=nullptr;
    Node* p = first;
    int x = -1;
    if (position < 1 || position > Count())
        return -1;
    if (position == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for (int i = 0; i < position - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int LinkedList::isSorted()
{
    Node* p = first;
    int x = INT_MIN;
    while (p)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void LinkedList::RemoveDuplicate()
{
    Node* p = first;
    Node* q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void LinkedList::ReverseE()
{
    Node* p = first;
    int length = Count();
    int* A = new int[length];
    int i = 0;
    while (p != NULL)
    {
        A[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;//i index 會多1
    while (p != NULL)
    {
        p->data = A[i--];
        p = p->next;
    }
}

void LinkedList::ReverseL()
{
    Node* r, * q = nullptr;
    Node* p = first;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;//q在最後一個
}

void LinkedList::RReverse()
{
    RReverse(NULL,first);
}

void LinkedList::RReverse(Node* q,Node* p)
{
    if (p != NULL)
    {
        RReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }        
}

void LinkedList::Concatenate(Node* second)
{
    Node* p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
}

int LinkedList:: isLoop()
{
    /* create loop for test
    Node* t1, * t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;*/
    Node* p, * q;
    p = q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    return 0;
}

void LinkedList::Merge(Node* second)
{
    Node* last;
    if (first->data < second->data)
    {
        third =  first;
        last = first;
        first = first->next;
        last->next = nullptr;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
        first = third;
    }
    else
    {
        last->next = second;
        first = third;
    }
}



Node* LinkedList::getFirstNode()
{
    return first;
}
