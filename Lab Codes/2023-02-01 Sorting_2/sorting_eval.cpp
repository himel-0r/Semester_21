#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>

// Merge sort started
vi merge(vi left, vi right)
{
    int i = 0, j = 0;

    vi merged;

    while (i < left.size() and j < right.size())
    {
        if (left[i] <= right[j])
        {
            merged.push_back(left[i]);
            i++;
        }
        else
        {
            merged.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        merged.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}

vi mergesort(vi v)
{
    if (v.size() <= 1)
        return v;

    int mid = v.size() / 2;
    vi left, right;

    for (int i = 0; i < mid; i++)
        left.push_back(v[i]);

    for (int i = mid; i < v.size(); i++)
        right.push_back(v[i]);

    left = mergesort(left);
    right = mergesort(right);

    return merge(left, right);
}
// Merge sort ended

// Quick sort started
int hoare_partition(vi a, int l, int h)
{
    int piv = a[l];
    int i = l - 1;
    int j = h + 1;

    while (1)
    {
        i++;
        while (a[i] < piv)
            i++;

        j--;
        while (a[j] > piv)
            j--;

        if (i >= j)
            return j;

        swap(a[i], a[j]);
    }
}

void quicksort(vi a, int l, int h)
{
    if (l < h)
    {
        int p = hoare_partition(a, l, h);

        quicksort(a, l, p);
        quicksort(a, p + 1, h);
    }
    return;
}
// Quick sort ended

// Counting sort started
vi countsort(vi a, int n)
{
    int mx = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];

    vi cnt(mx + 1, 0);
    vi ans(n);

    for (int i = 0; i < n; i++)
        cnt[a[i]]++;

    for (int &i : cnt)
        cout << i << " ";
    cout << endl;

    for (int i = 1; i <= mx; i++)
        cnt[i] += cnt[i - 1];

    for (int &i : cnt)
        cout << i << " ";
    cout << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << endl;
        ans[cnt[a[i]] - 1] = a[i];
        cnt[a[i]]--;
    }
    return ans;
} // Counting sort ended

// Counting sort for Radix sort
void cnt_rad(vi a, int n, int exp)
{
    vi ans(n);
    int i, cnt[10] = {0};

    for (int i = 0; i < n; i++)
        cnt[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        ans[cnt[(a[i] / exp) % 10] - 1] = a[i];
        cnt[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = ans[i];

    return;
}

void rad_sort(vi a, int n)
{
    int m = a[0];

    for (int i = 1; i < a.size(); i++)
        if (a[i] > m)
            m = a[i];

    for (int exp = 1; m / exp > 1; exp *= 10)
        cnt_rad(a, n, exp);
} // Radix sort ended

int main()
{
    int n;
    cin >> n;

    vi v(n);

    for (int &i : v)
        cin >> i;

    // v = mergesort (v);
    // v = countsort(v, n);
    // rad_sort (v, n);

    for (int &i : v)
        cout << i << " ";
    cout << endl;
}