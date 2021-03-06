// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverse(vector<long long> &arr, int l, int r)
    {
        int temp;
        for (int i = l, j = r; i <= j; i++, j--)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        int i, l, r;
        for (i = 0; i < n; i += k)
        {
            l = i;
            r = min(i + k - 1, n - 1);
            reverse(arr, l, r);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}