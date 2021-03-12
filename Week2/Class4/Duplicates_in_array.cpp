// Check whether an array contains duplicates
// 1. Sort the array and then check if arr[i] == arr[i+1], return true   ---- T=O(n log n) , S=O(1)
// 2. Use 2 loops, For each index i, check if any index at j is matching.   ---- T=O(n*n) , S=O(1)
// 3. Use hashmap to increment the value for which the key repeats  ---- T=O(n) , S=O(n)

#include <iostream>
#include <map>
using namespace std;

bool has_duplicates(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] > 1)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 34, 6, 2, 8, 55, 21, 12, 63, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << has_duplicates(arr, n);
    return 0;
}