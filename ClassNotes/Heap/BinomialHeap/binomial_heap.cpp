#include <bits/stdc++.h>
using namespace std;

class BinomialNode
{
public:
    int value;
    int degree;
    BinomialNode *parent;
    BinomialNode *child;
    BinomialNode *sibling;

    BinomialNode(int n)
    {
        this->value = n;
        this->degree = 0;
        this->parent = nullptr;
        this->child = nullptr;
        this->sibling = nullptr;
    }
};

BinomialNode* merge_tree(BinomialNode* heap1, BinomialNode* heap2)
{
    if (heap1->value > heap2->value)
        swap (heap1, heap2);

    heap2->parent = heap1;
    heap2->sibling = heap1->child;
    heap1->child = heap2;
    (heap1->degree)++;

    return heap1;
}

BinomialNode *merge_heaps(BinomialNode *heap1, BinomialNode *heap2)
{
    BinomialNode *head = nullptr;
    BinomialNode *tail = nullptr;

    BinomialNode *t1 = heap1;
    BinomialNode *t2 = heap2;

    while (t1 != nullptr and t2 != nullptr)
    {
        if (t1->degree < t2->degree)
        {
            if (tail == nullptr)
            {
                head = t1;
            }
            else
            {
                tail->sibling = t2;
            }

            tail = t1;
            t1 = t1->sibling;
        }
        else
        {
            if (tail == nullptr)
            {
                head = t2;
            }
            else 
            {
                tail->sibling = t2;
            }
            tail = t2;
            t2 = t2->sibling;
        }
    }

    while (t1 != nullptr)
    {
        tail->sibling = t1;
        tail = t1;
        t1 = t1->sibling;
    }

    while (t2 != nullptr)
    {
        tail->sibling = t2;
        tail = t2;
        t2 = t2->sibling;
    }

    BinomialNode* prev = nullptr;
    BinomialNode* current = head;
    BinomialNode* next = head->sibling;

    while (next != nullptr)
    {
        if (current->degree != next->degree or (next->sibling != nullptr && next->sibling->degree == current->degree))
        {
            prev = current;
            current = next;
        }
        else 
        {
            if (current->value <= next->value)
            {
                current->sibling = next->sibling;
                current = merge_tree(current, next);
            }
            else
            {
                if (prev == nullptr)
                {
                    head = next;
                }
                else
                {
                    prev->sibling = next;
                }
                current = merge_tree(next, current);
            }
        }
        next = current->sibling;
    }
    return head;
}

BinomialNode* insert_node(BinomialNode* heap, int x)
{
    BinomialNode* newNode = new BinomialNode(x);
    return merge_heaps(heap, newNode);
}

