#include "Queues.hpp"

int main()
{
    freopen ("in3.txt", "r", stdin);
    freopen ("out3.txt", "w", stdout);
    
    int n; cin >> n;
    int num;
    QueueLL q;
    for (int i=0; i<n; i++) {
        cin >> num;
        q.enqueue(num);
    }
    int k; cin >> k;

    QueueLL ansq = q;

    for (int i=0; i<n; i++) {
        QueueLL qq, intq;
        for (int j=0; j<n; j++) {
            qq.enqueue(q.front());
            q.enqueue(q.front());
            q.dequeue();
        }

        for (int j=0; j<i; j++) {
            qq.dequeue();
        }

        // qq.display();

        int sum = 0;

        while (sum < k && !qq.isEmpty()) {
            sum += qq.front();
            intq.enqueue(qq.front());
            qq.dequeue();
        }

        if (ansq.size() > intq.size() and sum >= k)
            ansq = intq;

        // ansq.display();
    }

    ansq.display();

}