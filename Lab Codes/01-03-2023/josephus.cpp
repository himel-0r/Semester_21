#include "circular_queue.hpp"

int main ()
{
    freopen ("jos_in.txt", "r", stdin);
    freopen ("jos_out.txt", "w", stdout);

    int num; cin >> num;
    int pulse; cin >> pulse;

    CirQ q (num+1);

    for (int i=1; i<=num; i++) {
        q.push(i);
    }

    int cnt = 0;

    while (!q.isEmpty()) {
        if (q.size() == 1) {
            cout << "The remaining one: " << q.front() << endl;
            break;
        }

        cnt++;

        int p = q.pop();

        if (cnt == pulse) {
            cnt = 0;
            continue;
        }

        q.push(p);
    }
}