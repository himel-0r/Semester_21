#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define vector <int> vi

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode()
    {
        data = 0;
        next = this;
        prev = this;
    }

    DNode(int dat,DNode* prv, DNode* nxt)
    {
        this->data = dat;
        this->prev = prv;
        this->next = nxt;
    }

    DNode (int dat) {
        this->data = dat;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLinkedList
{
private:
    DNode *head;

public:
    DLinkedList()
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

void DLinkedList::insert_front (int num)
{
    DNode *newNode = new DNode(num);

    if (head == NULL) {
        head = newNode;
        head->next = NULL;
        head->prev = NULL;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DLinkedList::insert_back (int num) 
{
    DNode *newNode = new DNode (num);

    DNode *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void DLinkedList::insert_middle (int num, int pos) 
{
    DNode *newNode = new DNode (num);

    if (pos == 0) {
        insert_front (num);
        return;
    }

    DNode *current = head;

    for (int i = 0; i<pos-1; i++) {
        current = current->next;

        if (current == NULL)
            return;
    }

    newNode->next = current->next;
    current->next->prev = newNode;
    newNode->prev = current;
    current->next = newNode;
}

void DLinkedList::delete_front ()
{
    if (head == NULL)
        return;

    DNode *current = head;

    head = head->next;
    head->prev = NULL;
}

void DLinkedList::delete_back () 
{
    DNode *curr = head;

    while (curr->next->next != NULL) 
        curr = curr->next;

    curr->next = NULL;
}

void DLinkedList::delete_middle (int position)
{
    if (head == NULL)
        return;

    if (position == 0) {
        delete_front();
        return;
    }

    DNode *current = head;

    for (int i=0; i<position-1; i++) {
        if (current->next == NULL)
            return;

        current = current->next;
    }

    current->next->next->prev = current;
    current->next = current->next->next;
    
}

void DLinkedList::printList ()
{
    DNode* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head)
            break;
    }
    cout << endl;
}

int main()
{
    DLinkedList l;

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