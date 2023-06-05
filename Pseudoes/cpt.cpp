#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define int ll
#define pii pair<int, int>
#define vi vector<ll>
#define vvi vector<vi>
#define all(vec) (vec).begin(), (vec).end()
#define endl '\n'
#define sp " "

void print_path(vi prev, vi dist, int source, int destination)
{
    if (source == destination)
        cout << source << endl;
    else if (prev[destination] == -1)
        cout << "yisghbcvhabsdcghvisydgcb\n";
    else {
        print_path(prev, dist, source, prev[destination]);
        cout << destination << endl;
    }
}

void solveit()
{
    int n, m; cin >> n >> m;
    vvi adj(n+1);

    for (int i=0; i<m; i++)
    {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // int from = 8, to = 10;

    // queue<int> q;
    // q.push(from);

    // vi dist(n+1, INT_MAX);
    // vi vis(n+1, 0);

    // dist[from] = 0;

    // while (!q.empty())
    // {
    //     int u = q.front();
    //     q.pop();
    //     vis[u] = 1;
        
    //     for (int v : adj[u])
    //     {
    //         dist[v] = min (dist[v], dist[u] + 1);
    //         if (!vis[v]) q.push(v);
    //     }
    // }

    // cout << dist[to] << endl;



    // BFS and path printing using teacher's provided code

    enum color {
        WHITE, GRAY, BLACK
    };

    vector<color> col(n+1, WHITE);
    vi prev (n+1, -1);
    vi dist (n+1, INT_MAX);

    int source = 1;
    int destination = 6;

    dist[source] = 0;
    prev[source] = -1;
    col[source] = GRAY;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (col[v] == WHITE)
            {
                col[v] = GRAY;
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
        col[u] = BLACK;
    }

    cout << endl << endl;
    print_path(prev, dist, source, destination);

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen ("inp.txt", "r", stdin);
    // freopen ("out.txt", "w", stdout);

    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        // cout << "Case " << tt << ": ";
        solveit();
    }
}