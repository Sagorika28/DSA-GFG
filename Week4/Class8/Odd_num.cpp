// To find whether given number is odd or not
#include <iostream>
using namespace std;

bool is_odd(int n)
{
    if(n&1)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << is_odd(n);
    return 0;
}