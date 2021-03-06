// We are given an Array of n integers, We are given q queries having indices l and r.
// We have to find out sum between the given range of indices (l and r inclusive).
//Time Complexity : Max(O(n),O(q))  ,   Auxiliary Space : O(n)

#include <iostream>
using namespace std;

int range_sum(int arr[], int n, int l, int r)
{
    int sum = 0, prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) // O(n)
        prefix[i] = arr[i] + prefix[i - 1];

    // finding range sum
    if (l == 0)
        sum = prefix[r];
    else
        sum = prefix[r] - prefix[l - 1];

    return sum;
}

int main(int argc, char const *argv[])
{
    int n, q, l, r;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << range_sum(arr, n, l, r) << endl;
    }
    return 0;
}