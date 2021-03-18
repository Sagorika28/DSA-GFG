// To find the count of digits in n using recursion.
// T=O(d)=O(log10 n) where d = no. of digits
#include <iostream>
using namespace std;
int count(int n)
{
    if (n < 10)
        return 1;
    return 1 + count(n / 10);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}
