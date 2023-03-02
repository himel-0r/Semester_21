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
            head = newNode;
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
};

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

    void insert_front(int num)
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

    void insert_back(int num)
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

    void insert_middle(int num, int pos)
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

    void printList()
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

    void delete_front()
    {
        if (head == NULL)
            return;

        CNode *current = head;

        while (current->next != head)
            current = current->next;

        current->next = head->next;
        head = head->next;
    }

    void delete_back()
    {
        CNode *curr = head;

        while (curr->next->next != head)
            curr = curr->next;

        curr->next = head;
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

        CNode *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            if (current->next == NULL)
                return;

            current = current->next;
        }

        current->next = current->next->next;
    }
};

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

    DNode(int dat)
    {
        this->data = dat;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLinkedList
{
public:
    DNode *head;

    DLinkedList()
    {
        head = NULL;
    }

    void insert_front(int num)
    {
        DNode *newNode = new DNode(num);

        if (head == NULL)
        {
            head = newNode;
            head->next = NULL;
            head->prev = NULL;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insert_back(int num)
    {
        DNode *newNode = new DNode(num);

        if (head == NULL)
        {
            this->insert_front(num);
            return;
        }

        DNode *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    void insert_middle(int num, int pos)
    {
        DNode *newNode = new DNode(num);

        if (pos == 0)
        {
            insert_front(num);
            return;
        }

        DNode *current = head;

        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;

            if (current == NULL)
                return;
        }

        newNode->next = current->next;
        current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
    }

    void printList()
    {
        DNode *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;

            if (temp == head)
                break;
        }
        cout << endl;
    }

    void delete_front()
    {
        if (head == NULL)
            return;

        DNode *current = head;

        head = head->next;
        head->prev = NULL;
    }

    void delete_back()
    {
        DNode *curr = head;

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
            delete_front();
            return;
        }

        DNode *current = head;

        for (int i = 0; i < position - 1; i++)
        {
            if (current->next == NULL)
                return;

            current = current->next;
        }

        current->next->next->prev = current;
        current->next = current->next->next;
    }
};

int ft = 0;

void sorted(LinkedList a, LinkedList b, LinkedList c)
{
    Node *aa = a.head;
    Node *bb = b.head;

    while (aa != NULL && bb != NULL)
    {
        if (aa->data <= bb->data)
        {
            c.insert_back(aa->data);
            aa = aa->next;
        }
        else
        {
            c.insert_back(bb->data);
            bb = bb->next;
        }
    }

    while (aa != NULL)
    {
        c.insert_back(aa->data);
        aa = aa->next;
    }

    while (bb != NULL)
    {
        c.insert_back(bb->data);
        bb = bb->next;
    }
}

void merge_lists(LinkedList list[], int k, LinkedList &ans)
{

    // cout << "ind " << endl;
    while (k)
    {
        int mini = (list[0].head->data);
        int ind = 0;
        int nullcnt = 0;

        // cout << mini << endl;

        for (int i = 0; i < k; i++)
        {
            if (list[i].head == NULL)
            {
                nullcnt++;
                k--;
                continue;
            }

            // Node *curr = list[i].head;

            if (mini > (list[i].head->data))
            {
                mini = list[i].head->data;
                ind = i;
            }
        }

        // cout << ind << endl;

        if (ft == 0)
        {
            ans.insert_front(mini);
            ft++;

            cout << ans.head->data << endl;
        }
        else
            ans.insert_back(mini);

        list[ind].head = list[ind].head->next;
        if (list[ind].head == NULL)
        {
            nullcnt++;
            k--;
        }

        if (nullcnt == k)
            break;

        // cout << "b " << nullcnt << endl;
    }
}

void remove_duplicate(DLinkedList ls)
{
    int present_number = ls.head->data;
    bool is_dupl = false;

    DNode *current = ls.head->next;

    while (current->next != NULL)
    {

        if (current->data != present_number)
        {
            present_number = current->data;
            is_dupl = false;
        }
        else
        {
            is_dupl = true;

            DNode *now = current;

            while (current->data = present_number)
            {
                current = current->next;
            }

            now->prev->next = current;
            present_number = now->data;
        }
    }
}

int main()
{
    // freopen("out.txt", "w", stdout);

    // cout << "sgd" << endl;

    LinkedList a[3];
    LinkedList ans;

    a[0].insert_front(1);
    a[0].insert_back(4);
    a[0].insert_back(5);

    a[1].insert_front(1);
    a[1].insert_back(3);
    a[1].insert_back(4);

    a[2].insert_front(2);
    a[2].insert_back(6);

    a[2].printList();
    a[1].printList();
    a[0].printList();

    merge_lists(a, 3, ans);

    // ans.insert_front(100);

    ans.printList();
}
