// Consider an array of size N with all initial values as '0'. Perform given 'm' add (add value) operations from position 'a' to 'b'
// and evaluate highest element in array.
// T=O(n), S=O(1)

#include <iostream>
#include <cstring>
using namespace std;

int find_max_element(int arr[], int n)
{
    int max_element = arr[0];
    for (int i = 1; i < n; i++)
    {
        // calculating prefix sum array
        arr[i] += arr[i - 1];

        // calculating max element
        max_element = max(max_element, arr[i]);
    }
    return max_element;
}

int main(int argc, char const *argv[])
{
    int a, b, n, m, value;
    cin >> n >> m >> value;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    while (m--)
    {
        cin >> a >> b;
        arr[a - 1] += value;
        arr[b] -= value;
    }
    cout << find_max_element(arr, n);
    return 0;
}