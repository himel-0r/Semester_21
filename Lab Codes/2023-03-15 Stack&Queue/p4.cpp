#include "Queues.hpp"
using namespace std;

int main()
{
    freopen("in4.txt", "r", stdin);
    freopen("out4.txt", "w", stdout);

    int n;
    cin >> n;
    int x;
    QueueLL q;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.enqueue(x);
    }

    int k;
    cin >> k;

    int i = 0;
    int ans = 0;

    while (!q.isEmpty())
    {
        int p = q.front();
        q.dequeue();

        if (i == 0)
            ans += p;

        i++;
        i %= k;
    }

    cout << ans << endl;
}