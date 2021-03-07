// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
// Time complexity - O(n*n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rainwater_trapped(vector<int> arr, int n)
{
    int total_water = 0;
    int left[n], right[n];

    // storing the left max at every index
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(arr[i], left[i - 1]);

    // storing the right max at every index
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(arr[i], right[i + 1]);

    for (int i = 1; i < n - 1; i++) //ignoring the 1st and last index as they cant store water - O(n)
        total_water += min(left[i], right[i]) - arr[i];

    return total_water;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << rainwater_trapped(arr, n);
    return 0;
}