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
    void display();
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
        this->end = newNode;
    }

    this->end->next = newNode;

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

void QueueLL::display()
{
    Node *curr = this->start;

    cout << "Display... ";

    if (curr == NULL)
    {
        cout << endl;
        return;
    }

    if (this->count == 1) {
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

int main()
{
    QueueLL q(5);

    cout << "isempty " << q.isEmpty() << endl;

    q.display();
    q.dequeue();

    q.enqueue(5);
    q.display();

    q.enqueue(10);
    q.enqueue(20);
    q.display();

    cout << "isfull " << q.isFull() << endl;
    cout << "isempty " << q.isEmpty() << endl;

    cout << q.front() << endl;

    q.dequeue();
    q.display();
    cout << "isfull " << q.isFull() << endl;
    cout << "isempty " << q.isEmpty() << endl;
    q.dequeue();
    q.display();
    cout << "isfull " << q.isFull() << endl;
    cout << "isempty " << q.isEmpty() << endl;
    q.dequeue();
    
    q.display();
}