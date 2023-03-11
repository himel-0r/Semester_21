#include<bits/stdc++.h>
using namespace std;

int main()
{
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> a(n);

    for (auto &i : a) cin >> i;

    for (int i=1; i<n; i++) {
        int j = i;

        while (j > 0 and a[j-1] > a[j]) {
            swap (a[j], a[j-1]);
            j--;
        }
    }

    for (auto &i : a)
        cout << i << " ";
    cout << endl;
}