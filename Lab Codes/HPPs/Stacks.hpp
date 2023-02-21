#ifndef STACKS_HPP
#define STACKS_HPP

#include "LinkedLists.hpp"

class Stack{
private:
    Node *head;
    int count;
    int limit;

public:
    Stack () {
        this->head = NULL;
        this->count = 0;
        this->limit = INT_MAX;
    }

    Stack (int sz) {
        this->head = NULL;
        this->count = 0;
        this->limit = sz;
    }

    int peek() {
        return this->head->data;
    }

    bool empty() {
        return (this->head == NULL);
    }

    bool full() {
        return (this->count == this->limit);
    }

    int size() {
        return this->count;
    }

    void clear() {
        this->head = NULL;
        this->count = 0;
    }

    int search (int num) {
        int ind = 0;

        Node * curr = this->head;

        while (curr->next != NULL) {
            if (curr->data == num)
                return (ind+1);

            ind++;
            curr = curr->next;
        }

        return -1;
    }

    void display () {
        Node *curr = this->head;

        while (curr != NULL) {
            cout << curr->data << " ";

            curr = curr->next;
        }
        cout << endl;
    }

    void push (int num) {
        Node* newNode = new Node(num);

        if (this->count >= this->limit) {
            cout << "Stack Overflow\n"; 
            return;
        }

        newNode->next = this->head;
        this->head = newNode;
        this->count = this->count + 1;
    }

    int pop () {
        if (this->head == NULL) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int top = this->head->data;

        this->head = this->head->next;
        this->count = this->count - 1;

        return top;
    }
};


#endif