#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int N = 10005;

vector<vi> adj(N);
vi vis(N, 0);

void dfs(int node)
{
    if (vis[node])
        return;

    vis[node] = 1;
    cout << node << endl;

    for (int i = 0; i < adj[node].size(); i++)
    {
        dfs(adj[node][i]);
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    cout << node << endl;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int &i : adj[node])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

void show_graph()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    bfs(1);
}

int main()
{
    show_graph();
}