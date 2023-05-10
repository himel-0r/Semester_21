#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the structure of a Binomial Tree node
struct BinomialNode {
    int key;
    int degree;
    BinomialNode* parent;
    BinomialNode* child;
    BinomialNode* sibling;
};

// Helper function to create a new node with a given key
BinomialNode* newNode(int key) {
    BinomialNode* node = new BinomialNode();
    node->key = key;
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->sibling = nullptr;
    return node;
}

// Function to merge two binomial trees of the same degree
BinomialNode* merge_trees(BinomialNode* t1, BinomialNode* t2) {
    if (t1->key > t2->key) {
        swap(t1, t2);
    }
    t2->parent = t1;
    t2->sibling = t1->child;
    t1->child = t2;
    t1->degree++;
    return t1;
}

// Function to merge two Binomial Heaps
BinomialNode* merge_heaps(BinomialNode* h1, BinomialNode* h2) {
    BinomialNode* head = nullptr;
    BinomialNode* tail = nullptr;
    BinomialNode* t1 = h1;
    BinomialNode* t2 = h2;

    while (t1 != nullptr && t2 != nullptr) {
        if (t1->degree < t2->degree) {
            if (tail == nullptr) {
                head = t1;
            } else {
                tail->sibling = t1;
            }
            tail = t1;
            t1 = t1->sibling;
        } else {
            if (tail == nullptr) {
                head = t2;
            } else {
                tail->sibling = t2;
            }
            tail = t2;
            t2 = t2->sibling;
        }
    }

    while (t1 != nullptr) {
        tail->sibling = t1;
        tail = t1;
        t1 = t1->sibling;
    }

    while (t2 != nullptr) {
        tail->sibling = t2;
        tail = t2;
        t2 = t2->sibling;
    }

    BinomialNode* prev = nullptr;
    BinomialNode* curr = head;
    BinomialNode* next = head->sibling;

    while (next != nullptr) {
        if (curr->degree != next->degree ||
            (next->sibling != nullptr && next->sibling->degree == curr->degree)) {
            prev = curr;
            curr = next;
        } else {
            if (curr->key <= next->key) {
                curr->sibling = next->sibling;
                curr = merge_trees(curr, next);
            } else {
                if (prev == nullptr) {
                    head = next;
                } else {
                    prev->sibling = next;
                }
                curr = merge_trees(next, curr);
            }
        }
        next = curr->sibling;
    }

    return head;
}

// Function to insert a node into a Binomial Heap
BinomialNode* insert_node(BinomialNode* heap, int key) {
    BinomialNode* node = newNode(key);
    return merge_heaps(heap, node);
}

// Function to find the node with the minimum key in a Binomial Heap
