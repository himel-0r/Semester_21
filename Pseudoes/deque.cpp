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
    this->front_node = this->back_node = NULL;
    this->back_node = this->front_node = NULL;
    this->count = 0;
    this->limit = INT_MAX;
    // this->front_node->next = this->back_node;
    // this->back_node->prev = this->front_node;
}

Dequeue::Dequeue(int sz)
{
    this->front_node = this->back_node = NULL;
    this->back_node = this->front_node = NULL;
    this->count = 0;
    this->limit = sz;
    // this->front_node->next = this->back_node;
    // this->back_node->prev = this->front_node;
}

void Dequeue::push_front(int n)
{
    if (this->empty())
    {
        DQNode *newNode = new DQNode(n, NULL, NULL);

        this->front_node = newNode;
        this->back_node = newNode;

        (this->count)++;
        return;
    }

    if (this->count == 1) {
        DQNode *newNode = new DQNode (n);

        this->back_node->prev = newNode;
        this->front_node = newNode;

        (this->count)++;
        return;
    }

    (this->count)++;

    if (this->isFull())
    {
        cout << "DEQUEUE OVERLOADED!!\n";
        return;
    }

    DQNode *newNode = new DQNode(n, NULL, this->front_node);

    this->front_node = newNode;
}

void Dequeue::push_back(int n)
{
    if (this->empty())
    {
        DQNode *newNode = new DQNode(n, NULL, NULL);

        this->front_node = newNode;
        this->back_node = newNode;

        (this->count)++;
        return;
    }

    if (this->count == 1) {
        DQNode *newNode = new DQNode (n);

        this->front_node->next = newNode;
        newNode->prev = this->front_node;
        this->back_node = newNode;

        (this->count)++;
        return;
    }

    (this->count)++;

    if (this->isFull())
    {
        cout << "DEQUEUE OVERLOADED!!\n";
        return;
    }

    DQNode *newNode = new DQNode(n);
    newNode->prev = this->back_node;
    this->back_node->next = newNode;
    newNode->next = NULL;
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

    if (this->count == 0) {
        cout << "NOTHING TO DISPLAY!!\n";
        return;
    }

    DQNode *curr = this->front_node;

    while (curr != this->back_node->next)
    {
        cout << curr->data << " ";

        // if (curr == this->back_node) {
        //     cout << this->back_node->data << " ";
        //     break;
        // }

        curr = curr->next;
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

    dq.push_front(10);
    dq.push_back(20);
    dq.display();
    dq.push_back(30);
    dq.display();

    dq.push_front(5);
    dq.display();

    dq.push_front(101);
    dq.push_front(200);

    dq.push_back(300);
    dq.push_back(400);
    dq.display();

    dq.clear();
    dq.display();

    dq.push_back(10);
    dq.push_back(20);
    dq.display();
    
    dq.clear();

    dq.push_front(20);
    dq.push_front(30);
    dq.display();
}