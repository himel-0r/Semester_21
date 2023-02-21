#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi merge (vi left, vi right) {
    vi ans;

    int i=0, j=0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            ans.push_back (left[i]);
            i++;
        }
        else {
            ans.push_back (right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        ans.push_back (left[i]);
        i++;
    }

    while (j < right.size()) {
        ans.push_back (right[j]);
        j++;
    }
    
    return ans;
}