#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int partition(vi a, int low, int high)
{
    int piv = a[low];
    int left = low;

    for (int i=low+1; i<high; i++) {
        if (a[i] < piv) {
            swap (a[i], a[left]);
            left++;
        }
    }
    swap (piv, a[left]);
    return left;
}