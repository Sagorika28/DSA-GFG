// To find the factorial of n using recursion.
// T(n) = O(n)
#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0 or n == 1)
        return 1;
    return n * factorial(n - 1);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}