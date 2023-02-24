#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int dat, Node *nxt)
    {
        this->data = dat;
        this->next = nxt;
    }

    Node(int dat)
    {
        this->data = dat;
        this->next = NULL;
    }
};

class QueueLL
{
private:
    Node *start;
    Node *end;
    int count;
    int limit;

public:
    QueueLL();
    QueueLL(int sz);
    void enqueue(int num);
    void dequeue();
    int front();
    bool isEmpty();
    bool isFull();
};

QueueLL::QueueLL()
{
    this->start = NULL;
    this->end = NULL;
    this->count = 0;
    this->limit = INT_MAX;
}

QueueLL::QueueLL(int sz)
{
    this->start = NULL;
    this->end = NULL;
    this->count = 0;
    this->limit = sz;
}

void QueueLL::enqueue(int num)
{
    if (this->count + 1 > this->limit)
    {
        cout << "Queue size overloaded\n";
        return;
    }

    Node *newNode = new Node(num);
    if (this->count == 0)
    {
        this->start = newNode;
    }

    this->end = newNode;

    this->count = this->count + 1;
}

void QueueLL::dequeue()
{
    if (this->count <= 0)
    {
        cout << "Nothing to dequeue!!\n";
        return;
    }

    if (this->count == 1)
    {
        this->start = NULL;
        this->end = NULL;

        this->count = this->count - 1;

        return;
    }

    this->start = this->start->next;
    this->count = this->count - 1;
}

int QueueLL::front()
{
    return this->start->data;
}

bool QueueLL::isEmpty()
{
    return (this->count == 0);
}

bool QueueLL::isFull()
{
    return (this->count == this->limit);
}