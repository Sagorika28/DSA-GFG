// Given a gold bar of length N with N equal markings, the task is to find the minimum number of cuts required to pay the
// salary in N days such that on any ith day the worker has i parts of the gold bar.
// https://www.geeksforgeeks.org/minimum-number-of-cuts-required-to-pay-salary-from-n-length-gold-bar/

// As we know any number can be represented with the help of the numbers in the form of powers of 2.
// So If we cut the length of Gold Bar into the nearest integer to log2 (N) then we can represent any number up to N.
// T=S=O(1)
#include <iostream>
#include <cmath>
using namespace std;

int cuts(int n)
{
    return log2(n);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << cuts(n);
    return 0;
}