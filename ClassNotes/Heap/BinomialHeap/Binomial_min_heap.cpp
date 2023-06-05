#include <bits/stdc++.h>
using namespace std;

class BinomialHeapNode
{
public:
    int value;
    int degree;
    BinomialHeapNode *parent;
    BinomialHeapNode *child;
    BinomialHeapNode *sibling;

    BinomialHeapNode(int n)
    {
        this->value = 0;
        this->degree = 0;
        this->parent = NULL;
        this->child = NULL;
        this->sibling = NULL;
    }
};

class BinomialHeap
{
    BinomialHeapNode *root;
    int size;

    BinomialHeap()
    {
    }

    void merge(BinomialHeap *other)
    {
        if (this->root == NULL)
        {
            this->root = other->root;
            this->size = other->size;
            return;
        }
        if (other->root == NULL)
        {
            return;
        }

        if (this->root->degree > other->root->degree)
        {
            BinomialHeapNode *temp = other->root;
            other->root = this->root;
            this->root = temp;
        }
        if (this->root->child == NULL)
        {
            this->root->child = other->root;
        }
        else
        {
            BinomialHeapNode *temp = this->root->child;

            while (temp->sibling)
            {
                temp = temp->sibling;
            }

            temp->sibling = other->root;
        }

        this->root->degree += other->root->degree;
        this->consolidate();
    }

    void consolidate()
    {
        vector<int> degtable;
        BinomialHeapNode* node = this->root;
        BinomialHeapNode* parent = NULL;

        while (node)
        {
            int deg = node->degree;;
            // while 
        }
    }
};