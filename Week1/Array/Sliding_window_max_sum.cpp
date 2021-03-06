// Given an array of integers of size 'n'. Our aim is to calculate the maximum sum of 'k' consecutive elements in the array. T(n)=O(n), S=O(1)

#include <iostream>
using namespace std;

int find_max_sum(int arr[], int n, int k)
{
    int max_sum = 0, subarray_sum = 0;
    int first = arr[0];

    for (int i = 0; i < k; i++)
    {
        max_sum += arr[i];
    }

    subarray_sum = max_sum;

    for (int i = 1; i < n - k; i++)
    {
        subarray_sum += arr[i + k - 1] - first;
        first = arr[i];
        if (subarray_sum > max_sum)
        {
            max_sum = subarray_sum;
        }
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    if (k > n)
        cout << "Invalid";
    else
        cout << find_max_sum(arr, n, k);
    return 0;
}