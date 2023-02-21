#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define vi vector<int>
const int n = 5000;
auto start_time = high_resolution_clock::now();

vi selection_sort(vi a, int exp)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;

        for (int j = i + 1; j < n; j++)
        {
            if ((a[j] / exp) % 10 < (a[mini] / exp) % 10)
                mini = j;
        }

        swap(a[i], a[mini]);
    }
    return a;
}

vi merge(vi left, vi right, int exp)
{
    {
        int i = 0, j = 0;

        vi merged;

        while (i < left.size() and j < right.size())
        {
            if ((left[i] / exp) % 10 <= (right[j] / exp) % 10)
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
}

vi mergesort(vi v, int exp)
{
    if (v.size() <= 1)
        return v;

    int mid = v.size() / 2;
    vi left, right;

    for (int i = 0; i < mid; i++)
        left.push_back(v[i]);

    for (int i = mid; i < v.size(); i++)
        right.push_back(v[i]);

    left = mergesort(left, exp);
    right = mergesort(right, exp);

    return merge(left, right, exp);
}

int hoare_partition(vi a, int l, int h, int exp)
{
    int piv = a[l];
    int i = l - 1;
    int j = h + 1;

    while (1)
    {
        i++;
        while ((a[i] / exp) % 10 < (piv / exp) % 10)
            i++;

        j--;
        while ((a[j] / exp) % 10 > (piv / exp) % 10)
            j--;

        if (i >= j)
            return j;

        swap(a[i], a[j]);
    }
}

vi quicksort(vi a, int l, int h, int exp)
{
    if (l < h)
    {
        int p = hoare_partition(a, l, h, exp);

        quicksort(a, l, p, exp);
        quicksort(a, p + 1, h, exp);
    }
    return a;
}

vi cnt_rad(vi a, int exp)
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

    return a;
}

void rad_sort(vi a)
{
    int m = a[0];

    for (int i = 1; i < a.size(); i++)
        if (a[i] > m)
            m = a[i];

    // start_time = high_resolution_clock::now();
    // for (int exp = 1; m / exp > 1; exp *= 10)
    // {
    //     a = cnt_rad(a, exp);
    // }
    auto stop_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_time - start_time);
    // cout << "Counting sort: " << duration.count() / 1000.0 << endl;

    start_time = high_resolution_clock::now();
    for (int exp = 1; m / exp > 1; exp *= 10)
    {
        a = selection_sort (a, exp);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    cout << "Selection sort: " << duration.count() / 1000.0 << endl;

    cout << "\n\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    start_time = high_resolution_clock::now();
    for (int exp = 1; m / exp > 1; exp *= 10)
    {
        a = mergesort (a, exp);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    cout << "Merge sort: " << duration.count() / 1000.0 << endl;

    start_time = high_resolution_clock::now();
    for (int exp = 1; m / exp > 1; exp *= 10)
    {
        a = quicksort (a, 0, n-1, exp);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    cout << "Quick sort: " << duration.count() / 1000.0 << endl;

    // cout << "\n\n";
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    // selection_sort(a);
    // cnt_rad (a, n, exp);
}

int main()
{
    start_time = high_resolution_clock::now();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vi v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    // sort (v.begin(), v.end());
    rad_sort(v);

    // auto stop_time = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop_time - start_time);

    // cout << duration.count() / 1000.0 << endl;
}