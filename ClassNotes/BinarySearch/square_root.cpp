#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    freopen("sqin.txt", "r", stdin);
    freopen("sqout.txt", "w", stdout);

    int n;
    cin >> n;

    int l = 1, r = n;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }

        if ((mid - 1) * (mid - 1) < n && (mid * mid) > n)
        {
            ans = mid - 1;
            break;
        }

        if (mid * mid > n)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << endl;
}