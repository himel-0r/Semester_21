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

    Node(int num)
    {
        data = num;
        next = NULL;
    }
};

class Stack
{
private:
    Node *front;
    Node *back;
    int size_of_stack;  

public:
    Stack()
    {
        front = NULL;
        back = NULL;
        size_of_stack = 0;
    }

    void push(int num)
    {
        Node *newN = new Node(num);

        if (front == NULL)
        {
            front = newN;
            front->next = back;
            back->data = num;
            back = newN;
            size_of_stack++;
            return;
        }

        back->next = newN;
        back = newN;
        size_of_stack++;
    }

    int top()
    {
        return back->data;
    }

    void pop()
    {
        Node *curr = front;

        while (curr->next != back)
        {
            curr = curr->next;
        }

        curr->next = NULL;
        back = curr;
        size_of_stack--;
    }
};

int main()
{
    Stack s;
    s.push(10);
    // s.push(12);
    // s.push(45);

    cout << s.top() << endl;

    // s.push(30);

    // cout << s.top() << endl;

    // s.pop();
    // cout << s.top() << endl;
}