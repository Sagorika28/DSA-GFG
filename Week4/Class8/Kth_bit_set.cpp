// Given a number n, check if k-th bit of n is set or not.  --- O(1)
// To count the number of set bits in a number
// Method 2: If we right shift n by k-1, we get last bit as 1 if k-th bit is set else 0.
#include <iostream>
using namespace std;

bool k_set_bit(int n, int k)
{
    // creating the mask which is a number that has only it's kth bit set
    int mask = (1 << (k - 1)); // 1*pow(2,k)
    if ((n & mask) == 0)
        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    if (k_set_bit(n, k))
        cout << "SET";
    else
        cout << "NOT SET";
    return 0;
}