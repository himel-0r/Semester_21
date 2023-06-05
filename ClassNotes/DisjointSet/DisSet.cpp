#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int *rank, *parent;
    int n;

public:
    DisjointSet(int n)
    {
        rank = new int[n+1];
        parent = new int[n+1];
        this->n = n;
        makeset();
    }

    void makeset()
    {
        for (int i=0; i<=n; i++)
            parent[i] = i;
    }

    // Find function with path compression
    int find (int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unite (int x, int y)
    {
        int xpar = find(x);
        int ypar = find(y);

        if (xpar == ypar)
            return;
        
        if (rank[xpar] < rank[ypar])
            parent[xpar] = ypar;
        else if (rank[xpar] > rank[ypar])
            parent[ypar] = xpar;
        else
        {
            parent[ypar] = xpar;
            rank[xpar] += 1;
        }
    }
};

int main()
{
    DisjointSet dis(10);

    dis.unite(2, 9);
    // Ekhane aaro onek kichu likha jabe. 
    // :)
}
