//T(n) = O(n log n)   ---- O(n) for making heap and O(log n) for heapify
#include <iostream>
using namespace std;

void max_heapify(int arr[], int n, int i)
{
    int max = i; // assuming root node to be the largest
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    // If left child is larger than root
    if (l < n && arr[l] > arr[max])
        max = l;

    // If right child is larger than max so far
    if (r < n && arr[r] > arr[max])
        max = r;

    // If max is not root
    if (max != i)
    {
        swap(arr[i], arr[max]);

        // Recursively heapify the affected sub-tree
        max_heapify(arr, n, max);
    }
}

void heap_sort(int arr[], int n)
{
    // max_heapify the array
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        max_heapify(arr, i, 0);
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {8, 2, 5, 9, 12, 7, 1, 2};
    cout << "Array before sorting: ";
    print_array(arr, 8);
    heap_sort(arr, 8);
    cout << "\nArray after sorting: ";
    print_array(arr, 8);
    return 0;
}