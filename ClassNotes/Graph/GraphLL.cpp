#include "LinkedLists.hpp"
#include "Queues.hpp"
using namespace std;

vector<LinkedList*> adj(10007);
vi visited(10007, 0);

void dfs(int node)
{
    if (visited[node]) return;

    visited[node] = 1;

    cout << node << endl;
    
    Node* u = adj[node]->head;

    while (u->next != nullptr) {
        dfs(u->next->data);

        u = u->next;
    }
}

void bfs(int node)
{
    QueueLL q;
    q.enqueue(node);

    visited[node] = 0;
    
    while (!q.isEmpty()) {
        int u = q.front();
        
        Node* u_ptr = adj[u]->head;

        cout << node << endl;
        
        while (u_ptr->next!= nullptr) {
            if (!visited[u_ptr->next->data]) {
                visited[u_ptr->next->data] = 1;
                q.enqueue(u_ptr->next->data);
            }
            
            u_ptr = u_ptr->next;
        }
    }


}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u]->insert_front(v);
        adj[v]->insert_front(u);
    }

    dfs(1);

    visited.resize(100007, 0);

    bfs(1);
}