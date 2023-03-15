or (int i = j; i < n; i = j)
    {
        ans = 0;
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