#include <bits/stdc++.h>
using namespace std;

class treenode
{
public:
    int data;
    string name;
    int serial_no;

    treenode(int dat, string nm, int sl);
    treenode();
};

treenode::treenode(int dat, string nm, int sl)
{
    this->name = nm;
    this->data = dat;
    this->serial_no = sl;
}

treenode::treenode()
{
    this->name = "";
    this->data = -1;
    this->serial_no = 0;
}

class bst
{
public:
    treenode ar[100000];
    int level[100000];
    int root;

    bst()
    {
        memset(ar, sizeof(ar) / sizeof(ar[0]), INT_MIN);
        memset(level, sizeof(level) / sizeof(level[0]), INT_MIN);
        root = 1;
    }

    int parent(int n)
    {
        return (n / 2);
    }

    int left(int n)
    {
        return (2 * n);
    }

    int right(int n)
    {
        return (2 * n + 1);
    }

    void insert(int num)
    {
        if (ar[root].data == INT_MIN)
        {
            ar[root].data = num;
        }
        else
        {
            this->insert(num, root);
        }
    }

    void insert(int num, int ind)
    {
        if (num <= ar[ind].data)
        {
            if (ar[left(ind)].data != INT_MIN)
            {
                this->insert(num, left(ind));
            }
            else
            {
                ar[left(ind)].data = num;
            }
        }
        else
        {
            if (ar[right(ind)].data != INT_MIN)
            {
                this->insert(num, right(ind));
            }
            else
            {
                ar[right(ind)].data = num;
            }
        }
    }

    bool search(int num)
    {
        return this->search(num, root);
    }

    bool search(int num, int ind)
    {
        
    }
};