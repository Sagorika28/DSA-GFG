// Given an array consisting of cost of toys. Given an integer K depicting the amount of money available to purchase toys.
// Write a program to find the maximum number of toys one can buy with the amount K.  --- Greedy
// T=O(n logn) , S=O(1)

#include <iostream>
#include <algorithm>
using namespace std;

int max_items(int arr[], int n, int k)
{
    if (n == 0 or k == 0)
        return 0;

    sort(arr, arr + n);

    int i = 0, ans = 0, count = 0;
    while (i < n and k > arr[i])
    {
        ans++;
        k = k - arr[i];
        i++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << max_items(arr, n, k);
    return 0;
}