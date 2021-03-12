// Given two given arrays of equal length, the task is to find if given arrays are equal or not.
// Two arrays are said to be equal if both of them contain the same set of elements, arrangements (or permutation) of elements may be different though.
// Note: If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.
// 1. Sort the arrays and check if arr1[i] == arr2[i], return true.        ---- T=O(n log n), S=O(1)
// 2. Use hashing       ----  T=O(n), S=O(n)

#include <iostream>
#include <unordered_map>
using namespace std;
bool areEqual(int arr1[], int arr2[], int n, int m)
{
    if (n != m)
        return false;

    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        um[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        // If there is an element in arr2[], but not in arr1[]
        if (um.find(arr2[i]) == um.end())
            return false;

        // If an element of arr2[] appears more times than it appears in arr1[]
        if (um[arr2[i]] == 0)
            return false;

        um[arr2[i]]--;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int arr1[] = {3, 5, 2, 5, 2};
    int arr2[] = {2, 3, 5, 5, 2};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);

    if (areEqual(arr1, arr2, n, m))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}