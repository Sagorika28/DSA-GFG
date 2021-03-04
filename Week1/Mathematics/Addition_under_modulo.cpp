// Given two numbers a and b, find the sum of a and b. Since the sum can be very large, find the sum modulo 10^9+7 ---- T=O(1), S=O(1)

#include <iostream>
#include <cmath>
using namespace std;

long long sumUnderModulo(long long a, long long b)
{
    long long mod = pow(10, 9) + 7;
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a;
        long long b;
        cin >> a >> b;
        cout << sumUnderModulo(a, b) << endl;
    }
    return 0;
}