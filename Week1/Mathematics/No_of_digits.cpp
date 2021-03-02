//num of digits in a number = floor(log(n) base 10) + 1 ----- O(1)
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    cout << floor(log10(n) + 1);
    return 0;
}