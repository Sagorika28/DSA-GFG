// Kadane's is used to find the largest sum of subarray
// T=O(n), S=O(1)

#include <iostream>
using namespace std;

int max_subarray_sum(int arr[], int n)
{
    int cur_sum = 0, max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        // if current sum is still a positive value, add the new element to this sum train (since it's value either increases or remains same here)
        if (cur_sum >= 0)
            cur_sum += arr[i];

        // if the current sum train becomes negative, it's better to start a new current sum train so that the current value doesn't decrease its worth
        else
            cur_sum = arr[i];

        // if max sum < current sum, update it
        if (cur_sum > max_sum)
            max_sum = cur_sum;
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
    cout << max_subarray_sum(arr, n);
    return 0;
}