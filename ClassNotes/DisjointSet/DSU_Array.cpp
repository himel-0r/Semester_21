#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void union_sets(int i, int j)
    {
        int rep_i = find(i);
        int rep_j = find(j);
        if (rep_i == rep_j)
        {
            return;
        }
        if (rank[rep_i] < rank[rep_j])
        {
            parent[rep_i] = rep_j;
        }
        else if (rank[rep_i] > rank[rep_j])
        {
            parent[rep_j] = rep_i;
        }
        else
        {
            parent[rep_j] = rep_i;
            rank[rep_i]++;
        }
    }
};

int main() {
    int n = 5;
    DSU dsu(n);

    for (int i = 0; i < n; i++) {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    dsu.union_sets(1, 2);
    
    for (int i = 0; i < n; i++) {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    dsu.union_sets(0, 3);
    
    for (int i = 0; i < n; i++) {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    dsu.union_sets(1, 4);
    
    for (int i = 0; i < n; i++) {
        cout << dsu.find(i) << " ";
    }
    cout << endl;

    return 0;
}





