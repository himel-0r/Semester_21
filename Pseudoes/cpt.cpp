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

void solveit()
{
    int n; cin >> n;
    vi a(n+1);

    for (int i=1; i<=n; i++)
    {
        int x; cin >> x;
        a[x] = i;
    }

    if (a[n] < a[1] && a[n] < a[2])
    {
        cout << a[n] << sp << min(a[1], a[2]) << endl;
    }
    else if (a[n] > a[1] && a[n] > a[2])
    {
        cout << a[n] << sp << max(a[1], a[2]) << endl;
    }
    else 
    {
        cout << a[n] << sp << a[n] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen ("inp.txt", "r", stdin);
    // freopen ("out.txt", "w", stdout);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        // cout << "Case " << tt << ": ";
        solveit();
    }
}