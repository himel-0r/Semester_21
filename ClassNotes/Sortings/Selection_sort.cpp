#include<bits/stdc++.h>
using namespace std;

int main()
{
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> a(n);

    for (auto &i : a) cin >> i;

    for (int i=0; i<n; i++) {
        int minind = i;
        for (int j=i+1; j<n; j++) {
            if (a[j] < a[minind])
                minind = j;
        }

        swap (a[i], a[minind]);
    }

    for (auto &i : a)
        cout << i << " ";
    cout << endl;
}