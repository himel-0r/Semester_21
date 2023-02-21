#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("input.txt", "w", stdout);

    srand (unsigned (time(0)));

    for (int i=0; i<5000; i++) {
        int b = rand()%10;

        if (b==0) {
            i--;
            continue;
        }

        cout << b * 10000 + rand()%10000 << " ";
    }
}