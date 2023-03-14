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
    // this->front_node->next = this->back_node;
    // this->back_node->prev = this->front_node;
}

Dequeue::Dequeue(int sz)
{
    this->front_node = NULL; 
    this->back_node = NULL;
    this->count = 0;
    this->limit = sz;
}

void Dequeue::push_front(int n)
{
    DQNode* newnode = new DQNode (n, NULL, this->front_node);

    if (this->front_node) {
        this->front_node->prev = newnode;
    }
    this->front_node = newnode;

    if (!this->back_node) {
        this->back_node = this->front_node;
    }

    (this->count)++;

    if (this->isFull()) 
        cout << "DEQUE overloaded!!\n";
}

void Dequeue::push_back(int n)
{
    DQNode* newnode = new DQNode(n, this->back_node, NULL);

    if (this->back_node) {
        this->back_node->next = newnode;
    }
    this->back_node = newnode;
    if (!(this->front_node)) {
        this->front_node = this->back_node;
    }

    (this->count)++;

    if (this->isFull()) 
        cout << "DEQUE overloaded!!\n";
}

void Dequeue::pop_front()
{
    if (!(this->front_node)) {
        return;
    }

    (this->count)--;

    if (!(this->front_node->next)) {
        this->front_node = NULL;
        this->back_node = NULL;
        return;
    }

    this->front_node = this->front_node->next;
    this->front_node->prev = NULL;
}

void Dequeue::pop_back()
{
    if (!(this->front_node))
        return;

    (this->count)--;

    if (!(this->front_node->next)) {
        this->front_node = NULL;
        this->back_node = NULL;
        return;
    }

    this->back_node = this->back_node->prev;
    this->back_node->next = NULL;
}

int Dequeue::front()
{
    if (this->front_node)
        return this->front_node->data;
    return INT_MIN;
}

int Dequeue::back()
{
    if (this->back_node)
        return this->back_node->data;
    return INT_MIN;
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

    DQNode* current = this->front_node;

    while (current) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}

void Dequeue::clear()
{
    this->front_node = this->back_node = NULL;
    this->count = 0;
}

int main()
{
    freopen("dq_test.txt", "w", stdout);

    cout << "Start\n\n";

    Dequeue dq(10000);

    cout << dq.empty() << endl;

    dq.push_back(10);
    dq.display();
    cout << dq.size() << endl;
    // cout << dq.back() << endl;
    // cout << dq.front() << endl;
    dq.pop_back();
    dq.display();
    cout << dq.size() << endl;
    dq.push_front(20);
    dq.display();
    cout << dq.size() << endl;
    dq.push_front(30);
    dq.display();
    dq.pop_front();
    dq.display();
    cout << dq.size() << endl;
    dq.pop_front();
    dq.display();

    cout << dq.empty() << endl;
    cout << dq.size() << endl;
}