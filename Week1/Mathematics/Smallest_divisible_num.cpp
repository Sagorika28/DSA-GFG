// Given a number N, find an integer denoting the smallest number evenly divisible by each number from 1 to n. --- T=O(n), S=O(1)
#include <iostream>
using namespace std;

class Solution
{
public:
    long long gcd(long long a, long long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long getSmallestDivNum(long long n)
    {
        long long i, lcm = 1, size = n;
        for (i = 1; i <= size; i++)
        {
            lcm = ((i * lcm) / gcd(i, lcm));
        }
        return lcm;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.getSmallestDivNum(n) << endl;
    }
    return 0;
}