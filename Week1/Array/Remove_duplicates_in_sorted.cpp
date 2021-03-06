// Given a sorted array A of size N, delete all the duplicates elements from A.   T=O(n), S=O(1)

#include <iostream>
using namespace std;

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        int size = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[size])
            {
                a[++size] = a[i];
            }
        }
        return size + 1;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int n = ob.remove_duplicate(a, N);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}