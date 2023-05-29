#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    set<string> a;

    for (int i=0; i<n-1; i++)
        a.insert("" + s[i] + s[i+1]);

    for (string p:a)
        cout << p << " ";
    cout << endl;
}