// To find the sum of digits till n using recursion.
// T(n) = O(n)
#include <iostream>
using namespace std;
int digits(int n)
{
    if (n == 1)
        return 1;
    return n + digits(n - 1);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << digits(n);
    return 0;
}
