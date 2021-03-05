// Given a positive integer value N. The task is to find how many numbers less than or equal to N have
// number of divisors exactly equal to 3.  T = O(n/2 * n/4)  ,  S = O(1)
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int exactly3Divisors(int n)
    {
        //numbers with exactly 3 divisors are the squares of prime numbers
        // ed: 4, 9, 25, 49, ....
        int count = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (isPrime(i))
                count++;
        }
        return count;
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
        cout << ob.exactly3Divisors(N) << endl;
    }
    return 0;
}