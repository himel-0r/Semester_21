#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define vector <int> vi

class CNode
{
public:
    int data;
    CNode *next;

    CNode()
    {
        data = 0;
        next = this;
    }

    CNode(int dat, CNode *nxt)
    {
        this->data = dat;
        this->next = nxt;
    }

    CNode(int dat)
    {
        this->data = dat;
        this->next = NULL;
    }
};

class CLinkedList
{
private:
    CNode *head;

public:
    CLinkedList()
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

void CLinkedList::insert_front(int num)
{
    CNode *newNode = new CNode(num, head);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    CNode *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
    head = newNode;
}

void CLinkedList::insert_back(int num)
{
    CNode *newNode = new CNode(num);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    CNode *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
}

void CLinkedList::insert_middle(int num, int pos)
{
    CNode *newNode = new CNode(num);

    if (pos == 0)
    {
        insert_front(num);
        return;
    }

    CNode *current = head;

    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;

        if (current == head)
            return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void CLinkedList::delete_front()
{
    if (head == NULL)
        return;

    CNode *current = head;

    while (current->next != head)
        current = current->next;

    current->next = head->next;
    head = head->next;
}

void CLinkedList::delete_back()
{
    CNode *curr = head;

    while (curr->next->next != head)
        curr = curr->next;

    curr->next = head;
}

void CLinkedList::delete_middle(int position)
{
    if (head == NULL)
        return;

    if (position == 0)
    {
        head = head->next;
        return;
    }

    CNode *current = head;

    for (int i = 0; i < position - 1; i++)
    {
        if (current->next == NULL)
            return;

        current = current->next;
    }

    current->next = current->next->next;
}

void CLinkedList::printList()
{
    CNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head)
            break;
    }
    cout << endl;
}

int main()
{
    CLinkedList l;

    l.insert_front(1);
    l.insert_back(3);
    l.insert_front(7);
    l.insert_front(10);
    l.insert_middle(5, 1);
    l.insert_back(11);

    l.printList();

    l.delete_back();
    l.printList();

    l.delete_front();
    l.printList();

    l.delete_middle(2);
    l.printList();
}
