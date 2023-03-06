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
    string s; cin >> s;

    map <char, int> mp;

    for (int i=0; i<n; i++) 
        mp[s[i]]++;

    cout << min ({mp['a'], mp['b'], mp['c'], mp['d'], mp['e']}) << sp;
    cout << max ({mp['a'], mp['b'], mp['c'], mp['d'], mp['e']}) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen ("inp.txt", "r", stdin);
    // freopen ("out.txt", "w", stdout);

    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        // cout << "Case " << tt << ": ";
        solveit();
    }
}