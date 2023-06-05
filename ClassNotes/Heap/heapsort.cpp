#include<bits/stdc++.h>

using namespace std;

// Function to heapify a subtree rooted at given index
void heapify(vector<int> &arr, int n, int rootIndex)
{
    int largest = rootIndex;            // Initialize the largest as the root
    int leftChild = 2 * rootIndex + 1;  // Left child index
    int rightChild = 2 * rootIndex + 2; // Right child index

    // If left child is larger than root
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // If right child is larger than the largest so far
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If the largest is not the root
    if (largest != rootIndex)
    {
        swap(arr[rootIndex], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build a max heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
