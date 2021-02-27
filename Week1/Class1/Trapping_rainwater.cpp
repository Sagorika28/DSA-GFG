// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_left_max(vector<int> arr, int n, int i)
{
    int max_left = 0;
    for (int j = 0; j <= i; j++) // j <= i , we equate to i so that negavtive numbers don't arise, if we do = i, water becomes 0 automatically if there's no trap space
    {
        max_left = max(max_left, arr[j]);
    }
    return max_left;
}

int find_right_max(vector<int> arr, int n, int i)
{
    int max_right = 0;
    for (int j = i; j < n; j++)
    {
        max_right = max(max_right, arr[j]);
    }
    return max_right;
}

int rainwater_trapped(vector<int> arr, int n)
{
    int total_water = 0;
    for (int i = 1; i < n - 1; i++) //ignoring the 1st and last index as they cant store water
    {
        int left_max = find_left_max(arr, n, i);
        int right_max = find_right_max(arr, n, i);
        total_water += min(left_max, right_max) - arr[i];
    }
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