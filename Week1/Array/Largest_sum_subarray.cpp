// We are given an array of positive and negative integers. We have to find the subarray(continuous elements) having maximum sum.
// Time Complexity : O(n)
// Auxiliary Space : O(1)
#include <iostream>
#include <climits>
using namespace std;

int largest_subarray_sum(int arr[], int n)
{
    int max_sum = INT_MIN, temp_max = 0;
    for (int i = 0; i < n; i++)
    {
        temp_max += arr[i];
        if (temp_max > max_sum)
            max_sum = temp_max;

        if (temp_max < 0)
            temp_max = 0;
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << largest_subarray_sum(arr, n);
    return 0;
}