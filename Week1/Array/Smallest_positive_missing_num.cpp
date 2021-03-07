// Given an array arr[] of size N, find the smallest positive number missing from the array.
// T=O(n), S=O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find missing integer in array
    // arr: input array
    // n: size of array
    int segregate_array(int arr[], int n)
    {
        int first_positive = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
            {
                swap(arr[i], arr[first_positive]);
                first_positive++;
            }
        }
        return first_positive;
    }

    int missing_part(int arr[], int n)
    {
        // traverse the remaining postive side of array
        int val = 0;

        for (int i = 0; i < n; i++)
        {
            // for each arr[i], go to the index of value of arr[i] and make that value negative.
            // if that index is not a part of the array, then simply move to the next iteration of loop

            val = abs(arr[i]) - 1;
            // cout<<val<<":"<<arr[val]<<" "
            if (val < n && arr[val] > 0)
            {
                arr[val] = -arr[val];
            }
            //cout<<val<<":"<<arr[val]<<" ";
        }
        
        // after whole array is traversed check which first element in array is positive and return its index
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                return i + 1;
        }
        // else if all are negative, return n+1
        return n + 1;
    }

    int findMissing(int arr[], int n)
    {
        // smallest number can either be 1-n or n+1 if all 1-n elements are present in the array

        // store the negative elements and 0 in the left side of the array
        int start = segregate_array(arr, n);
        // find missing part
        return missing_part(arr + start, n - start);
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
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.findMissing(arr, n) << endl;
    }
    return 0;
}