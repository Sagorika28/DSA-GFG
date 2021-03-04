/*
Given an integer N. Find the number of digits that appear in its factorial. T=O(N), S=O(1)
Constraints: 1 ≤ N ≤ 105

log(a*b) = log(a) + log(b)
therefore,
log( n! ) = log(1*2*3....... * n) we can write is as log(1) + log(2) + ........ +log(n)
Now, observe that the floor value of log base 10 increased by 1, of any number, gives the number of digits present in that number.
Hence, the output would be :
floor(log(n!)) + 1
Example: n = 5
log(5!) = log(1) + log(2) + ... log(5)
0.3 + 0.47 + 0.6 + 0.69 = 2 (floor value)
After adding 1 to the result,
floor(log(n!)) + 1 = 3 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int digitsInFactorial(int N)
    {
        double ans = 0;
        for (int i = 2; i <= N; i++)
        {
            ans += log10(i);
        }
        return (floor(ans) + 1);
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
        Solution ob;
        cout << ob.digitsInFactorial(N) << endl;
    }
    return 0;
}