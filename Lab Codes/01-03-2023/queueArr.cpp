#include<bits/stdc++.h>
using namespace std;

class QueueAr {
private:
    int ar[10000];
    int start;
    int end;
    int count;
    int limit;

public:
    QueueAr () 
    {
        this->start = 0;
        this->end = 0;
        this->count = 0;
        this->limit = INT_MAX;
        memset (ar, sizeof(ar)/sizeof(ar[0]), 0);
    }

    QueueAr (int sz) {
        this->start = 0;
        this->end = 0;
        this->count = 0;
        this->limit = sz;
        memset (ar, sizeof(ar)/sizeof(ar[0]), 0);
    }

    void push(int n);
    int pop();
    int front();
    bool isEmpty();
    bool isFull();
    void display();
    void clear();
};

void QueueAr::push(int n)
{
    if (this->count + 1 > this->limit) {
        cout << "Queue size overloaded\n";
        return;
    }

    this->ar[this->end] = n;
    (this->end)++;
    (this->count)++;
}

int QueueAr::pop()
{
    int val = this->ar[this->start];

    if (this->start == this->end) {
        cout << "Nothing to pop!!\n";
        return -1;
    }

    (this->start)++;
    (this->count)--;

    return val;
}

int QueueAr::front()
{
    return (this->ar[this->start]);
}

bool QueueAr::isEmpty()
{
    return (this->count == 0);
}

bool QueueAr::isFull()
{
    return (this->count == this->limit);
}

void QueueAr::display()
{
    cout << "Display... ";

    for (int i=this->start; i<this->end; i++)
        cout << this->ar[i] << " ";

    cout << endl;
}

void QueueAr::clear()
{
    this->start = this->end = this->count = 0;
    memset (ar, sizeof(ar)/sizeof(ar[0]), 0);
}

int main()
{
    freopen("inp1.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    cout << "Implementation of queue using Array\n\n";

    QueueAr q (100);

    cout << "Checking if this queue is empty: " << q.isEmpty() << endl;


    int x; cin >> x;
    q.push(x);
    q.display();

    cin >> x;
    q.push(x);
    q.display();

    cout << "Checking if this queue is empty: " << q.isEmpty() << endl;

    cin >> x;
    q.push(x);
    q.display();

    cout << "This is front: " << q.front() << endl;

    cout << "This value is popped: " << q.pop() << endl;
    cout << "Now calling display() function: " << endl;
    q.display();
    
}