// Given an array arr[] of size N containing positive integers and an integer X,
// find the element in the array which is smaller than X and closest to it. If it doesn't exist, return -1.
// Expected Time Complexity: O(N), Expected Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// User function to complete
// arr[]: input array
// n: size of array
// k: find element smaller and closest to it.
int immediateSmaller(int arr[], int n, int x)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x && arr[i] > max)
            max = arr[i];
    }
    if (max == INT_MIN)
        max = -1;

    return max;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int x;
        cin >> x;

        cout << immediateSmaller(arr, n, x) << endl;
    }
    return 0;
}