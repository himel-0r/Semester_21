#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(0);

    vi dist(n + 1, INT_MAX);
    vi vis(n + 1, 0);

    dist[0] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;

        for (int v : adj[u])
        {
            dist[v] = min(dist[v], dist[u] + 1);
            if (!vis[v])
                q.push(v);
        }
    }

    cout << dist[5] << endl;
}