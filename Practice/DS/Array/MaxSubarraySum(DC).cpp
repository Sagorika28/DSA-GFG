/* 
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum.
Use Divide & Conquer
For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7 (6, -2, -3, 1, 5). 
*/
// T=O(n log n) , S=O(log n)
#include <iostream>
#include <climits>
using namespace std;

int maxCrossArraySum(int arr[], int l, int r, int mid)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on right of mid.
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid+1; i <= r; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    int cross_sum = left_sum + right_sum;
    return max(max(left_sum, right_sum), cross_sum);
}

int maxSubArraySum(int arr[], int l, int r)
{
    if(l == r) // base case: Only one element
        return arr[l];

    int mid = (l + r) / 2;

    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray crosses the midpoint */
        
    int lmax = maxSubArraySum(arr, l, mid);
    int rmax = maxSubArraySum(arr, mid+1, r);
    int cmax = maxCrossArraySum(arr, l, r, mid);

    return max(max(lmax, rmax), cmax);
}

int main(int argc, char const *argv[])
{
    int arr[] = { 2, 3, 4, 5, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum contiguous sum is : " << max_sum;
    return 0;
}