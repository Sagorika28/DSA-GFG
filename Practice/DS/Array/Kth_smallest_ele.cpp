/*
Given an array and a number k where k is smaller than the size of the array, we need to find the k’th smallest element in the given array.
It is given that all array elements are distinct.
*/
// T=O(log n) , S=O(n)
#include <iostream>
#include <set>
using namespace std;

int find(int *arr, int n, int k)
{
    // M1. sort(arr, arr+(r+1));
    //    return arr[k-1];

    // M2. set is implemented in STL using BST
    set<int> s(arr, arr + n);
    set<int>::iterator itr = s.begin();

    // point iterator to kth smallest element
    advance(itr, k - 1);
    return *itr;
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << find(arr, n, k);
    return 0;
}