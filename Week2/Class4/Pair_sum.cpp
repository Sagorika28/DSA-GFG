// Write a program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x.
// 1. Use 2 loops   ----  T=O(n*n) , S=O(1)
// 2. Sort the array and use the 2 pointers approach from start and end to chcek if they are equal to sum or not    ----  T=O(n logn) , S=O(1)
// 3. Use hashing to find the 2nd element if it exits.    ----  T=O(n) , S=O(n)

#include <iostream>
#include <unordered_set>
using namespace std;

bool hasPair(int arr[], int n, int x)
{
    unordered_set<int> us;
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = x - arr[i];             // second value as sum - first val = second val
        if (us.find(temp) != us.end()) // if the second value is present in the set, return true
        {
            cout << "Pair with sum = " << x << " : (" << temp << ", "<< arr[i] << ")";
            return true;
        }
        else // if the second value is not present in the set, insert arr[i] (first value) into the set
            us.insert(arr[i]);
    }
    return false; // no pair with sum equal to x found
}

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (hasPair(arr, n, x))
        cout << "\nYes";
    else
        cout << "No";
    return 0;
}