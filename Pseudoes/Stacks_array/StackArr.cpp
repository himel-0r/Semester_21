#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100000

class StackAr {
private:
    int arr[MAX_SIZE];
    int ind;
    int limit;

public:
    StackAr(int sz);
    StackAr();
    void push(int num);
    void pop();
    int top();
    bool empty();
    int size();
    bool isFull();
    void clear();
    bool search(int n);
    void display();
};

StackAr::StackAr() 
{
    this->limit = MAX_SIZE;
    this->ind = 0;
}

StackAr::StackAr(int sz)
{
    this->limit = sz;
    this->ind = 0;
}

void StackAr::push(int n)
{
    this->arr[this->ind] = n;
    (this->ind)++;
}

void StackAr::pop()
{
    if (!this->empty())
        (this->ind)--;
}

int StackAr::top()
{
    if (!this->empty())
        return (this->arr[this->ind - 1]);
}

int StackAr::size()
{
    return (this->ind);
}

bool StackAr::empty()
{
    return (this->ind == 0);
}

bool StackAr::isFull()
{
    return (this->ind == this->limit);
}

bool StackAr::search(int n)
{
    for (int i=0; i<this->ind; i++) 
        if (this->arr[i] == n)
            return true;

    return false;
}

void StackAr::clear()
{
    this->ind = 0;
}

void StackAr::display()
{
    cout << "Displaying...  ";
    for (int i=0; i<this->ind; i++)
        cout << this->arr[i] << " ";

    cout << endl;
}

int main ()
{
    StackAr st;

    st.display();
    cout << st.empty() << endl;
    cout << st.size() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    cout << st.size() << endl;

    st.pop();
    cout << st.top() << endl; 

    st.display();
}