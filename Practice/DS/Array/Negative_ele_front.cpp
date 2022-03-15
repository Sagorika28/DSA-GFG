/* 
An array contains both positive and negative numbers in random order. 
Rearrange the array elements so that all negative numbers appear before all positive numbers. 
*/
// T=O(n) , S=O(1)
#include <iostream>
using namespace std;

void rearrange(int *arr, int n)
{
    int neg_pos = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
            swap(arr[i], arr[neg_pos++]);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(int argc, char const *argv[])
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}