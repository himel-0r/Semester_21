#include <bits/stdc++.h>
#include<math.h>

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
    double a, b, angle;
    cin >> a >> b >> angle;

    if ((int) a == 0 && (int) b == 0)
    {
        cout << 0 << sp << 0 << endl;
        return;
    }

    if ((int) angle == 180)
    {
        cout << -a << sp << -b << endl;
        return;
    }

    double ang = angle * M_PI / 180.0;

    // cout << tan(M_PI/4.0) << endl;

    double an = ((int) a == 0 ? M_PI/2.0 : atan(b/a));
    an += ang;

    double m = tan(an);

    cout << m << endl;

    double r = sqrt(a*a + b*b);

    double xsq = r/(1+m*m);

    // cout << xsq << endl;

    xsq = sqrt(xsq);

    double ysq = m * xsq;

    cout << setprecision(20);

    cout << xsq << sp << ysq << endl;
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