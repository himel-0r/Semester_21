#include "Queues.hpp"
using namespace std;

int main()
{
    freopen("in3.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);

    QueueLL q;

    int n;
    cin >> n;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        q.enqueue(num);
    }

    int sum;
    cin >> sum;

    QueueLL qq;

    int ans = 0;

    while (ans < sum)
    {
        ans += q.front();
        qq.enqueue(q.front());
        q.dequeue();
        j++;
    }

    while (!qq.isEmpty())
    {
        // cout << ans << " " << qq.front() << endl;
        if (ans - qq.front() >= sum)
        {
            ans -= qq.front();
            qq.dequeue();
        }
        else
            break;
    }

    qq.display();

    QueueLL q3;

    cout << j << endl;

    for (int i = j; i < n; i = j)
    {
        ans = 0;
        // cout << j << endl;
        while (ans < sum)
        {
            if (j > n)
                break;
            ans += q.front();
            q3.enqueue(q.front());
            q.dequeue();
            j++;
        }

        if (ans < sum)
            break;

        // cout << ans << " ";

        while (!qq.isEmpty())
        {
            // cout << ans << " " << qq.front() << endl;
            if (ans - q3.front() >= sum)
            {
                ans -= q3.front();
                q3.dequeue();
            }
            else
                break;
        }

        // cout << ans << endl;
        // cout << j << " " << q3.size() << endl;

        if (qq.size() > q3.size())
        {
            qq = q3;
        }
    }

    while (!qq.isEmpty())
    {
        cout << qq.front() << " ";
        qq.dequeue();
    }
    cout << endl;
}