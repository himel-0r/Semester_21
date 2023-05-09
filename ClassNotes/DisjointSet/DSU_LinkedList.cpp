#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class DSU
{
private:
    vector<Node*> heads;

public:
    DSU(int n)
    {
        heads.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            heads[i] = new Node(i);
            heads[i]->next = nullptr;
        }
    }

    int find(int x)
    {
        if(heads[x] == nullptr)
            return x;
        
        Node* current = heads[x];

        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current->data;
    }

    void merge(int x, int y)
    {
        Node* xHead = heads[x];
        Node* yHead = heads[y];
        xHead->next = yHead;
        heads[y] = xHead;
        if(yHead->next == nullptr)
        {
            return;
        }
        Node* yNext = yHead->next;
        while(yNext->next!= nullptr)
        {
            yNext = yNext->next;
        }
        yNext->next = xHead;
        return;
    }
    
};