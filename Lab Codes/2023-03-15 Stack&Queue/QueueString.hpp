#ifndef QUEUES_HPP
#define QUEUES_HPP

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node()
    {
        data = "";
        next = NULL;
    }

    Node(string dat, Node *nxt)
    {
        this->data = dat;
        this->next = nxt;
    }

    Node(string dat)
    {
        this->data = dat;
        this->next = NULL;
    }
};

class QueueSTR
{
private:
    Node *start;
    Node *end;
    int count;
    int limit;

public:
    QueueSTR();
    QueueSTR(int sz);
    void enqueue(string num);
    void dequeue();
    string front();
    bool isEmpty();
    bool isFull();
    void display();
};

QueueSTR::QueueSTR()
{
    this->start = NULL;
    this->end = NULL;
    this->count = 0;
    this->limit = INT_MAX;
}

QueueSTR::QueueSTR(int sz)
{
    this->start = NULL;
    this->end = NULL;
    this->count = 0;
    this->limit = sz;
}

void QueueSTR::enqueue(string num)
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
        this->end = newNode;
    }

    this->end->next = newNode;

    this->end = newNode;

    this->count = this->count + 1;
}

void QueueSTR::dequeue()
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

string QueueSTR::front()
{
    return this->start->data;
}

bool QueueSTR::isEmpty()
{
    return (this->count == 0);
}

bool QueueSTR::isFull()
{
    return (this->count == this->limit);
}

void QueueSTR::display()
{
    Node *curr = this->start;

    // cout << "Display... ";

    if (curr == NULL)
    {
        cout << endl;
        return;
    }

    if (this->count == 1)
    {
        cout << this->start->data << endl;
        return;
    }

    while (curr != this->end->next)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

#endif