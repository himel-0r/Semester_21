#ifndef DEQUEUE_HPP
#define DEQUEUE_HPP

#include <bits/stdc++.h>

using namespace std;

class DQNode
{
public:
    int data;
    DQNode *prev;
    DQNode *next;

    DQNode()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    DQNode(int n)
    {
        this->data = n;
        this->prev = NULL;
        this->next = NULL;
    }

    DQNode(int n, DQNode *prv, DQNode *nxt)
    {
        this->data = n;
        this->prev = prv;
        this->next = nxt;
    }
};

class Dequeue
{
private:
    DQNode *front_node;
    DQNode *back_node;
    int count;
    int limit;

public:
    Dequeue();
    Dequeue(int sz);
    void push_front(int n);
    void push_back(int n);
    void pop_front();
    void pop_back();
    int front();
    int back();
    bool empty();
    bool isFull();
    int size();
    void clear();
    void display();
};

Dequeue::Dequeue()
{
    this->front_node = NULL;
    this->back_node = NULL;
    this->count = 0;
    this->limit = INT_MAX;
    this->front_node->next = this->back_node;
    this->back_node->prev = this->front_node;
}

Dequeue::Dequeue(int sz)
{
    this->front_node = NULL;
    this->back_node = NULL;
    this->count = 0;
    this->limit = sz;
    this->front_node->next = this->back_node;
    this->back_node->prev = this->front_node;
}

void Dequeue::push_front(int n)
{
    (this->count)++;

    if (this->isFull()) {
        cout << "DEQUEUE OVERLOADED!!\n";
        return;
    }

    DQNode* newNode = new DQNode (n, NULL, this->front_node);

    this->front_node = newNode;
}

void Dequeue::push_back (int n)
{
    (this->count)++;

    if (this->isFull()) {
        cout << "DEQUEUE OVERLOADED!!\n";
        return;
    }

    DQNode* newNode = new DQNode (n, this->back_node, NULL);

    this->back_node = newNode;
}

void Dequeue::pop_front()
{
    if (this->empty())
    {
        cout << "NOTHING TO POP!!\n";
        return;
    }
    
    this->front_node = this->front_node->next;

    (this->count)--;
}

void Dequeue::pop_back()
{
    if (this->empty())
    {
        cout << "NOTHING TO POP!!\n";
        return;
    }

    this->back_node = this->back_node->prev;

    (this->count)--;
}

int Dequeue::front()
{
    return (this->front_node->data);
}

int Dequeue::back()
{
    return (this->back_node->data);
}

bool Dequeue::empty()
{
    return (this->count == 0);
}

bool Dequeue::isFull()
{
    return (this->count == this->limit);
}

int Dequeue::size()
{
    return (this->count);
}

void Dequeue::display()
{
    cout << "Displaying...   ";
    
    DQNode* curr = this->front_node;

    while (curr->next != NULL)
    {
        cout << curr->data << " ";
    }

    cout << "\n";
}

void Dequeue::clear()
{
    if (this->limit == INT_MAX) {
        Dequeue();
    }
    else {
        Dequeue(this->limit);
    }
}

#endif