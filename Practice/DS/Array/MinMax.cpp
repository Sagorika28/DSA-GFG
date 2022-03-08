// Find Maximum and minimum of an array using minimum number of comparisons
// T=O(n) , S=O(1)
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> getMinMax(int arr[], int n)
{
    int minm, maxm, i;

    // Length of array is even - initialize the first 2 elements as minimum and maximum
    if (!(n & 1))
    {
        minm = min(arr[0], arr[1]);
        maxm = max(arr[0], arr[1]);
        i = 2;
    }

    // Length of array is odd - initialize the first element as minimum and maximum
    else
    {
        minm = arr[0];
        maxm = arr[0];
        i = 1;
    }

    while (i < (n - 1))
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > maxm)
                maxm = arr[i];

            if (arr[i + 1] < minm)
                minm = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > maxm)
                maxm = arr[i + 1];

            if (arr[i] < minm)
                minm = arr[i];
        }
        i += 2;
    }

    pair<int, int> p;
    p = make_pair(minm, maxm);
    return p;
}

int main(int argc, char const *argv[])
{
    // no. of comparisons = 1.5n-2
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;
    pair<int, int> minmax = getMinMax(arr, arr_size);

    cout << "Minimum element is " << minmax.first << endl;
    cout << "Maximum element is " << minmax.second;

    return 0;
}