// Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value,
//  second should be min value, third should be second max, fourth should be second min and so on.
// T=O(n), S=O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n)
    {
        int i, max_index = n - 1, min_index = 0, max = arr[n - 1] + 1;
        //remainder (old value) = dividend % divisor
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] += ((arr[max_index] % max) * max); //dividend = quotient*divisor+remainder
                max_index--;
            }
            else
            {
                arr[i] += ((arr[min_index] % max) * max);
                min_index++;
            }
        }
        for (i = 0; i < n; i++)
            arr[i] = arr[i] / max; //since quotient (new value) = dividend/divisor
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        //size of array
        int n;
        cin >> n;

        long long arr[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;

        //calling rearrange() function
        ob.rearrange(arr, n);

        //printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}