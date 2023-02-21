#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define vector <int> vi

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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert_front(int);

    void insert_back(int);

    void insert_middle(int, int);

    void printList();

    void delete_front();

    void delete_back();

    void delete_middle(int);
};

void LinkedList::insert_front(int num)
{
    Node *newNode = new Node(num, head);

    head = newNode;
}

void LinkedList::insert_back(int num)
{
    Node *newNode = new Node(num);

    if (head == NULL)
    {
        this->insert_front(num);
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::insert_middle(int num, int pos)
{
    Node *newNode = new Node(num);

    Node *current = head;

    if (pos == 0)
    {
        insert_front(num);
        return;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;

        if (current == NULL)
            return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::delete_front()
{
    if (head == NULL)
        return;

    head = head->next;
}

void LinkedList::delete_back()
{
    Node *curr = head;

    while (curr->next->next != NULL)
        curr = curr->next;

    curr->next = NULL;
}

void LinkedList::delete_middle(int position)
{
    if (head == NULL)
        return;

    if (position == 0)
    {
        head = head->next;
        return;
    }

    Node *current = head;

    for (int i = 0; i < position - 1; i++)
    {
        if (current->next == NULL)
            return;

        current = current->next;
    }

    current->next = current->next->next;
}

void LinkedList::printList()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkedList a;

    a.insert_back(10);
    a.insert_front(85);
    a.insert_back(10);
    a.insert_middle(13, 2);
    a.insert_front(78);

    a.printList();

    a.delete_middle(1);
    a.delete_back();
    a.delete_front();
    
    a.printList();

    
}