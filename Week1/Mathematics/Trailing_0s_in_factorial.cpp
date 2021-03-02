// Given an integer n, write a function that returns count of trailing zeroes in n!
// Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + ....

#include <iostream>
using namespace std;

int count_trailing_zeros(int n)
{
    int zeros = 0;
    for (int i = 5; (n / i) >= 1; i *= 5)
    {
        zeros += (n / i);
    }
    return zeros;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << "Trailing zeros in " << n << "! : " << count_trailing_zeros(n);
    return 0;
}