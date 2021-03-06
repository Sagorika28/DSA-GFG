// Given a sorted array containing only 0s and 1s, find the transition point.  T=O(logn), S=O(1)
#include <iostream>
using namespace std;

int transitionPoint(int arr[], int n)
{
    int beg = 0, end = n - 1, mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == 1 && arr[mid - 1] == 0)
            return mid;
        else if (arr[mid] == 1 && arr[mid - 1] == 1)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if (beg > end)
        return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}