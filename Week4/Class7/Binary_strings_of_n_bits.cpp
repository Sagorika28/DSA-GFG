// Given a positive integer number N. The task is to generate all the binary strings of N bits.
// These binary strings should be in ascending order.       (asked in Amazon)

#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void binary(int arr[], int n, int i)
{
    // base case
    if (i == n)
    {
        print(arr, n);
        return;
    }

    arr[i] = 0;
    binary(arr, n, i + 1); // for remaining permutations

    arr[i] = 1;
    binary(arr, n, i + 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    binary(arr, n, 0);
    return 0;
}