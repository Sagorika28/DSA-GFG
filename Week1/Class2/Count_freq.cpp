// C++ program to count occurrences of an element in a sorted array.---- O(log n)
// Iterator lower_bound (Iterator first, Iterator last, const val)
// Iterator upper_bound (Iterator first, Iterator last, const val)
// lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
// upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
#include <iostream>
#include <algorithm>
using namespace std;

/* if x is present in arr[] then returns the count of occurrences of x, otherwise returns 0. */
int count(int arr[], int x, int n)
{
    /* get the index of first occurrence of x */
    int *low = lower_bound(arr, arr + n, x);

    // If element is not present, return 0
    if (low == (arr + n) || *low != x)
        return 0;

    /* Else get the index of last occurrence of x. 
	Note that we are only looking in the 
	subarray after first occurrence */
    int *high = upper_bound(low, arr + n, x);

    /* return count */
    return high - low;
}

/* driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 3};
    int x = 3; // Element to be counted in arr[]
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = count(arr, x, n);
    cout << x << " occurs " << c << " times ";
    return 0;
}

// //alternate for upper_bound :-
// int last(int arr[], int low, int high, int x, int n)    --- low = i, high = n-1
// {
//     if (high >= low)
//     {
//         int mid = (low + high) / 2;
//         if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
//             return mid;
//         else if (x < arr[mid])
//             return last(arr, low, (mid - 1), x, n);
//         else
//             return last(arr, (mid + 1), high, x, n);
//     }
//     return -1;
// }

// //alternate for lower_bound :-
// int last(int arr[], int low, int high, int x, int n)   --- low = 0, high = n-1
// {
//     if (high >= low)
//     {
//         int mid = (low + high) / 2;
//         if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
//             return mid;
//         else if (x < arr[mid])
//             return last(arr, low, (mid - 1), x, n);
//         else
//             return last(arr, (mid + 1), high, x, n);
//     }
//     return -1;
// }
// in count function return (first-last+1)