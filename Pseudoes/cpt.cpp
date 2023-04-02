#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define int ll
#define vi vector<ll>
#define vvi vector<vi>
#define all(vec) (vec).begin(), (vec).end()
#define endl '\n'
#define sp " "

void solveit()
{
    int n; cin >> n;
    int a[n];


    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int b = 0;

    for (int i=0; i<n; i++) {
        b ^= a[i];
    }

    cout << b << endl;
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