#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void heapify_max(vi &a);
void heapify_max(vi &a, int i);
void heapify_max(vi &a, int n, int i);
vi merge_heaps(vi a, vi b);
void insertMaxHeap(vi &a, int x);
void heap_sort(vi &a);
void delete_element(vi &a, int x);
int extract_max(vi &a);

void heapify_max(vi &a)
{
    for (int i = a.size() - 1; i >= 0; i--)
        heapify_max(a, i);
}

void heapify_max(vi &a, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left < a.size() and a[left] > a[largest])
        largest = left;

    if (right < a.size() and a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify_max(a, largest);
    }
}

void heapify_max(vi &a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left < n and a[left] > a[largest])
        largest = left;

    if (right < n and a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify_max(a, n, largest);
    }
}

vi merge_heaps(vi a, vi b)
{
    if (a.size() >= b.size())
    {
        for (auto &i : b)
            a.push_back(i);

        heapify_max(a);
        return a;
    }
    else
    {
        for (auto &i : a)
            b.push_back(i);

        heapify_max(b);
        return b;
    }
}

void insertMaxHeap(vi &a, int x)
{
    a.push_back(x);

    int index = a.size() - 1;
    int parent = (index - 1) / 2;

    while (index > 0 and a[index] > a[parent])
    {
        swap(a[index], a[parent]);

        index = parent;
        parent = (index - 1) / 2;
    }
}

void heap_sort(vi &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_max(a);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify_max(a, i, 0);
    }
}

void delete_element(vi &a, int x)
{
    int i = 0;
    while (a[i] != x && i < a.size())
        i++;

    // cout << i << endl;

    if (i == a.size())
        return;

    swap(a[i], a[a.size()-1]);

    a.pop_back();

    heapify_max(a, a.size()-1, 0);
}

int extract_max(vi &a)
{
    int n = a.size();

    if (!n) return -1;

    int ans = a[0];

    swap(a[0], a[n-1]);

    a.pop_back();

    heapify_max(a, n-1, 0);

    return ans;
}

int peek(vi &a)
{
    return a[0];
}

void display(vi &a)
{
    for (auto &i : a)
        cout << i << " ";

    cout << endl;
}

int main()
{
    vi a = {10, 23, 43, 12, 56, 9, 5};
    heap_sort(a);

    // heapify_max(a);

    display(a);

    delete_element(a, 12);

    display(a);
}