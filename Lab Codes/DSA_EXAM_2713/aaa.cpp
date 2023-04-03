#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        this->data = n;
    }
};

class Stack
{
public:
    Node *head;
    int count;
    int limit;

    Stack()
    {
        this->head = NULL;
        this->count = 0;
        this->limit = INT_MAX;
    }

    void push(int n)
    {
        Node *newnode = new Node(n);

        newnode->next = this->head;
        this->head = newnode;
        (this->count)++;
    }

    int pop()
    {
        if (this->empty())
        {
            return -1;
        }

        int num = this->head->data;

        this->head = this->head->next;
        (this->count)--;

        return num;
    }

    bool empty()
    {
        return (this->count == 0);
    }

    void display()
    {
        Node *curr = this->head;
        // int cnt = 0;

        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
            // cnt++;
        }
    }

    int top()
    {
        return (this->head->data);
    }
};

class Lili
{
public:
    Node *head;
    int count;

    Lili()
    {
        this->head = NULL;
        this->count = 0;
    }

    void insert(int num)
    {
        Node *newnode = new Node(num);

        newnode->next = this->head;
        this->head = newnode;
        (this->count)++;
    }

    int get_max()
    {
        int maxi = -1;
        Node *cur = this->head;

        while (cur)
        {
            maxi = max(cur->data, maxi);
            cur = cur->next;
        }

        return maxi;
    }

    int get_min()
    {
        int mini = INT_MAX;
        Node *cur = this->head;

        while (cur)
        {
            mini = min(cur->data, mini);
            cur = cur->next;
        }

        return mini;
    }

    int size()
    {
        return (this->count);
    }

    void display()
    {
        Node *curr = this->head;
        // int cnt = 0;

        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
            // cnt++;
        }
    }

    int num_at_pos(int pos)
    {
        int i = 0;
        Node *curr = this->head;

        while (curr)
        {
            if (i == pos)
            {
                return curr->data;
            }
            i++;

            curr = curr->next;
        }

        return -1;
    }
};

Lili insertion_sort(Lili ll)
{
    Node *curr = ll.head;

    while (curr)
    {
        int mini = curr->data;

        Node *node = curr->next;
        Node *minnode = curr;

        while (node)
        {
            if (mini > node->data)
            {
                minnode = node;
                mini = node->data;
            }
            node = node->next;

            if (node == NULL)
                break;
        }

        swap(curr->data, minnode->data);

        curr = curr->next;
    }

    return ll;
}

void bucket_sort(Lili &sLink)
{
    int n = 15;
    Lili ls[15]; // making 15 buckets

    int mx = sLink.get_max();
    int div = ceil(mx / (15 - 1));

    Node *curr = sLink.head;
    while (curr)
    {
        ls[(int)(curr->data / div)].insert(curr->data); // putting elements into buckets
        curr = curr->next;
    }

    for (int i = 0; i < 15; i++)
    {
        ls[i] = insertion_sort(ls[i]); // using insertion sort for sorting each buckets
    }

    curr = sLink.head;

    for (int i = 0; i < 15; i++) // merging all buckets
    {
        Node *node = ls[i].head;

        while (node)
        {
            curr->data = node->data;
            curr = curr->next;
            node = node->next;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // int a[151];
    int x;

    Lili sLink;
    Stack inputstack;

    while (scanf("%d", &x) != EOF)
    {
        sLink.insert(x);
        inputstack.push(x);
    } // Taking input from file to the stack and the sLink

    // inputstack.display();

    Stack tempstack;
    int currentelement;

    while (!inputstack.empty())
    {
        currentelement = inputstack.pop();

        if (tempstack.empty() || tempstack.top() <= currentelement)
        {
            tempstack.push(currentelement);
        }
        else
        {
            while (!tempstack.empty() && tempstack.top() > currentelement)
            {
                inputstack.push(tempstack.pop());
            }
            tempstack.push(currentelement);
        }
    } // steps 3, 4, 5 are here

    // tempstack.display();

    while (!tempstack.empty())
    {
        inputstack.push(tempstack.pop());
    } // step 7 done

    cout << "Displaying inputstack\n";
    inputstack.display(); // printing inputstack
    cout << endl;

    // step 9
    bucket_sort(sLink);
    cout << "\nDisplaying sLink\n";
    sLink.display();
    // step 9 ends

    // step 10 starts
    Node *llnode = sLink.head;
    Node *stnode = inputstack.head;

    int difference = 0;

    while (llnode != NULL && stnode != NULL)
    {
        if (llnode->data != stnode->data)
            difference++;

        llnode = llnode->next;
        stnode = stnode->next;
    }
    cout << endl;
    cout << "\nDifference is " << difference << endl;
    // step 10 ends

    // step 11 starts
    int avg = sLink.get_max() + sLink.get_min();
    avg >>= 1;

    int l = 0;
    int r = sLink.size() - 1;
    bool fl = false;
    cout << "\nFound Average? ";

    while (l < r) // binary seach starts
    {
        int mid = (l + r) / 2;
        int num = sLink.num_at_pos(mid);

        if (num == avg)
        {
            cout << "YES\n";
            fl = true;
            break; // if average is found, print "yes" and break
        }
        else if (num > avg)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (!fl)
    {
        cout << "NO\n";
    }

    return 0;
}