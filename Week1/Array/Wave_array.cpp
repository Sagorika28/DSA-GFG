// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it.
// In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
// (considering the increasing lexicographical order).
// T=O(n), S=O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int *arr, int n)
    {
        int flag = 1;
        for (int i = 1; i < n; i++)
        {
            if (flag)
            {
                if (arr[i - 1] < arr[i])
                {
                    swap(arr[i - 1], arr[i]);
                }
                flag = 0;
            }
            else
            {
                if (arr[i - 1] > arr[i])
                {
                    swap(arr[i - 1], arr[i]);
                }
                flag = 1;
            }
        }
    }
};

/* Another shorter technique
class Solution{
    public:
       //Function to sort the array into a wave-like array.
        void convertToWave(int *arr, int n){
        //Iterating over the array.
        for(int i=0;i<n-1;i=i+2)
                //Swapping two neighbouring elements at a time. 
                swap(arr[i],arr[i+1]);               
    }
};
*/

int main()
{
    int t, n;
    cin >> t;   //Input testcases
    while (t--) //While testcases exist
    {
        cin >> n; //input size of array
        int a[n]; //declare array of size n
        for (int i = 0; i < n; i++)
            cin >> a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " "; //print array

        cout << endl;
    }
}