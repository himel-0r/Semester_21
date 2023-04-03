#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "w", stdout);

    srand(unsigned(time(0)));

    for (int i = 0; i < 150; i++)
    {
        cout << rand() % 1000 << " ";

        if (i % 10 == 9)
            cout << endl;
    }

    return 0;
}