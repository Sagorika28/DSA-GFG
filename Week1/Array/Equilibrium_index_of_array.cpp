// Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
// Time Complexity : O(n)
// Auxiliary Space : O(1)

#include <iostream>
using namespace std;

int equi_index(int arr[], int n)
{
    int sum = 0, left_sum = 0;
    for (int i = 0; i < n; i++)
        sum =+ arr[i];

    for (int i = 0; i < n; i++)
    {
        sum -= arr[i]; // sum is now treated as the right_sum
        if (left_sum == sum)
            return i;
        left_sum += arr[i];
    }
    return -1; // if no equilibrium index is found
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << equi_index(arr, n);
    return 0;
}