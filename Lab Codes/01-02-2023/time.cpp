
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int main ()
{
    auto start = high_resolution_clock::now();

    int sz;
    cout << "Enter the size of array::";
    cin >> sz;
    int randArray[sz];
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 1000000000; // Generate number between 0 to 99

    cout << "\nElements of the array::" << endl;

    sort (randArray, randArray+sz);

    // for (int i = 0; i < sz; i++)
    //     cout << " " << randArray[i] ;
        cout << endl;

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;
}