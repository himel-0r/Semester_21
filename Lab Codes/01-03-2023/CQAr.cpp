#include <bits/stdc++.h>
using namespace std;

class CirQ
{
private:
    int ar[10000];
    int start;
    int end;
    int count;
    int limit;

public:
    CirQ(int n);
    void push(int n);
    int pop();
    int front();
    bool isEmpty();
    bool isFull();
    void display();
    void clear();
};

CirQ::CirQ(int sz)
{
    this->start = 0;
    this->end = 0;
    this->count = 0;
    this->limit = sz;
}

void CirQ::push (int n)
{
    if (this->count + 1 > this->limit) {
        cout << "Queue size overloaded\n";
        return;
    }

    this->ar[this->end] = n;
    (this->end)++;
    (this->end) %= (this->limit);
    (this->count)++;
}

int CirQ::pop()
{
    int val = this->ar[this->start];

    if (this->start == this->end) {
        cout << "Nothing to pop!!\n";
        return -1;
    }

    (this->start)++;
    (this->start) %= (this->limit);
    (this->count)--;

    return val;
}

int CirQ::front()
{
    return (this->ar[this->start]);
}

bool CirQ::isEmpty()
{
    return (this->count == 0);
}

bool CirQ::isFull()
{
    return (this->count == this->limit);
}

void CirQ::display()
{
    cout << "Display... ";

    for (int i=this->start, j=0; j<(this->count); i++, i%=this->limit, j++) {
        cout << this->ar[i] << " ";
    }
    cout << endl;
}

void CirQ::clear()
{
    this->start = this->end = this->count = 0;
    memset (ar, sizeof(ar)/sizeof(ar[0]), 0);
}


int main()
{
    freopen("inp1.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);

    cout << "Implementation of queue using circular Array\n\n";

    CirQ q (10);

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