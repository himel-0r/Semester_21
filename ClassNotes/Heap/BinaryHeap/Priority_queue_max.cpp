#include<bits/stdc++.h>
#include "Heap.hpp"

using namespace std;

class priority_queue_max
{
    vector<int> a;
    int count;

    priority_queue_max()
    {
        this->count = 0;
    }

    void push(int x)
    {
        a.push_back(x);
        this->count += 1;

        heapify_max(this->a, this->count, 0);
    }

    int top()
    {
        return peek(this->a);
    }

    void pop()
    {
        extract_max(this->a);
    }
};