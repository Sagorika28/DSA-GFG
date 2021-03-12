// Given an array arr[] of size N, find the first repeating element.
// The element should occurs more than once and the index of its first occurrence should be the smallest.
// T=O(n), S=O(n)

#include <bits/stdc++.h>
using namespace std;

int firstRepeated(int *, int);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cout << firstRepeated(arr, n) << "\n";
    }

    return 0;
}

int firstRepeated(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int j = 0; j < n; j++)
    {
        if (mp[arr[j]] > 1)
            return j + 1;
    }
    return -1;
}