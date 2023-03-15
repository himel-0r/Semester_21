#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
private:
    int a[10000];
    int head;
    int tail;
    int size;
    int limit;

public:
    MyCircularDeque(int sz)
    {
        this->head = 0;
        this->tail = 0;
        this->size = 0;
        this->limit = sz;
    }

    void addFront(int num)
    {
        a[this->head] = num;
        if (this->head == this->tail)
        {
            this->tail = (this->tail + 1) % this->limit;
        }
        this->head = (this->head - 1 + this->limit) % this->limit;

        (this->size)++;
    }

    void addRear(int num)
    {
        a[this->tail] = num;
        if (this->head == this->tail)
        {
            this->head = (this->head - 1 + this->limit) % this->limit;
        }
        this->tail = (this->tail + 1) % this->limit;

        (this->size)++;
    }

    int removeFront()
    {
        // int k = a[this->head];
        this->head = (this->head + 1) % this->limit;
        (this->size)--;
        int k = a[this->head];
        return k;
    }

    int removeRear()
    {
        this->tail = (this->tail - 1 + this->limit) % this->limit;
        (this->size)--;
        int k = a[this->tail];
        return k;
    }

    bool isEmpty()
    {
        return (this->size == 0);
    }

    void print()
    {
        for (int i = (this->head + 1) % this->limit;; i++, i %= this->limit)
        {
            cout << a[i] << " ";

            if (i == (this->tail - 1 + this->limit) % this->limit)
                break;
        }
        cout << endl;
    }
};

int main()
{
    // freopen("in1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);

    MyCircularDeque dq(5);

    dq.addFront(10);
    dq.addRear(20);
    dq.addRear(30);
    dq.print();
    cout << dq.removeFront() << endl;
    cout << dq.removeFront() << endl;

    cout << dq.isEmpty() << endl;
    cout << dq.removeFront() << endl;
    cout << dq.isEmpty() << endl;
}