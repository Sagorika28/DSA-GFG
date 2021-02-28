//left rotate an array of n elements by d elements. Eg: arr = {1,6,2,3,4} , d = 2, result = {2,3,4,1,6}
//Method 1: use an extra array temp[d] to store the first d elements, shift the elements of main array by d to the left (i = 0 to n-d),
//          replace the last d elements of array by the temp[] elements --- Time: O(n), Space: O(d)
//Method 2: loop d times, each time shift the elements to the left by 1. --- Time: O(n*d), Space: O(1)

//Method 3: Time: O(n), Space: O(1) -- best //since arrays work on call by references, we don't return
#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end)
{
    int temp;
    for (int i = start, j = end; i <= j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void left_rotate(int arr[], int n, int d)
{
    if (d == 0)
        return;

    if (d > n)
        d %= n;

    // 1. Reverse the first 'd' elements of array
    reverse(arr, 0, d - 1);

    // 2. Reverse the remaining (n-d) elements of array
    reverse(arr, d, n - 1);

    // 3. Reverse the whole array
    reverse(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    int d, n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> d;
    left_rotate(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}