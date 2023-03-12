#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi (int n, char from, char to, char aux)
{
    if (n==1) {
        cout << "Move disc 1 from " << from << " to " << to << endl;
        return; 
    }

    tower_of_hanoi (n-1, from, aux, to);
    cout << "Move disc " << n << " from " << from << " to " << to << endl;
    tower_of_hanoi (n-1, aux, to, from);
}

int main()
{
    // freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    tower_of_hanoi (1, 'A', 'C', 'B');
}