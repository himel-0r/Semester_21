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
    int dequeue();
    int front();
    bool isEmpty();
    bool isFull();
    void display();
    void clear();
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

int QueueLL::dequeue()
{
    if (this->count <= 0)
    {
        cout << "Nothing to dequeue!!\n";
        return -1;
    }

    int val = this->start->data;

    if (this->count == 1)
    {
        this->start = NULL;
        this->end = NULL;

        this->count = this->count - 1;

        return -1;
    }

    this->start = this->start->next;
    this->count = this->count - 1;

    return val;
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

void QueueLL::clear()
{
    this->start = this->end = NULL;
    this->count = 0;
}

int main()
{
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);

    cout << "Implementation of queue using LinkedLists\n\n";

    QueueLL q(100);

    int x;
    cin >> x;
    q.enqueue(x);
    q.display();

    cin >> x;
    q.enqueue(x);
    q.display();

    cin >> x;
    q.enqueue(x);
    q.display();

    cout << "This is front: " << q.front() << endl;

    cout << "This value is popped: " << q.dequeue() << endl;
    cout << "Now calling display() function: " << endl;
    q.display();
}