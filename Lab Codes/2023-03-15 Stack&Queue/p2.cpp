#include "QueueString.hpp"

void reverse(QueueSTR *q)
{
    string s = q->front();
    q->dequeue();

    if (!q->isEmpty())
        reverse(q);

    q->enqueue(s);
}

int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int n;
    cin >> n;

    string s;
    QueueSTR q;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        q.enqueue(s);
    }

    reverse(&q);

    q.display();
}