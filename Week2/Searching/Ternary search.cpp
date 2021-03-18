// Time Complexity: O(Log3 N)  -- array is divided into 3 parts, must be sorted
#include <iostream>
using namespace std;
int ternary_search(int arr[], int n, int x)
{
    int l = 0, r = n - 1, mid1, mid2;
    while (r >= l)
    {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;

        if (arr[mid1] == x)
            return mid1;

        if (arr[mid2] == x)
            return mid2;

        // The key lies in between l and mid1 
        if (x < arr[mid1])
            r = mid1 - 1;

        // The key lies in between mid2 and r 
        else if (x > arr[mid2])
            l = mid2 + 1;

        // The key lies in between mid1 and mid2 
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-6, 3, 7, 12, 45, 63, 98};
    int x = 45;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << ternary_search(arr, n, x);
    return 0;
}