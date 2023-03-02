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

class LinkedList
{
public:
    Node *head;


    LinkedList()
    {
        head = NULL;
    }

    void insert_front(int num)
    {
        Node *newNode = new Node(num, head);

        head = newNode;
    }

    void insert_back(int num)
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

    void insert_middle(int num, int pos)
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

    void printList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void delete_front()
    {
        if (head == NULL)
            return;

        head = head->next;
    }

    void delete_back()
    {
        Node *curr = head;

        while (curr->next->next != NULL)
            curr = curr->next;

        curr->next = NULL;
    }

    void delete_middle(int position)
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

    void append_sorted(int num)
    {
        Node *newNode = new Node(num);

        Node *current = head;

        if (head == NULL)
        {
            head = newNode;
            head->next = NULL;
            return;
        }

        if (num <= (head->data))
        {
            this->insert_front(num);
            return;
        }

        while ((current->data) < num && (current->next) != NULL)
        {
            current = current->next;

            if (current->data >= num)
            {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }

            if (current->next == NULL)
            {
                current->next = newNode;
                return;
            }
        }

        newNode->next = current->next;
        current->next = newNode;
    }
};

void remove_duplicate (LinkedList ls)
{
    int present_number=ls.head->data;
    bool is_dupl = false;

    Node* current = ls.head->next;

    while (current->next != NULL) {
        //current = current->next;

        if (current->data != present_number) {
            present_number = current->data;
            is_dupl = false;
        }
        else {
            is_dupl = true;

            
        }
    }
}

int main()
{
    LinkedList list;

    int k, x, n;
    cin >> k; // number of lists

    for (int kk = 0; kk < k; kk++)
    {
        cin >> n; // number of elements in this list
        cout << "abd  " << n << endl;

        for (int i = 0; i < n; i++)
        {
            cin >> x;

            list.append_sorted(x);
        }
    }
    list.printList();
}