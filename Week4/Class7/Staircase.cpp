// To find the no. of ways to reach the nth step of a staircase if we can take 1 or 2 steps at a time
#include <iostream>
using namespace std;

int find_steps(int n)
{
    if (n <= 2)
        return n;

    // return the number of steps required to reach the (n-1)th step + steps to raech (n-2)th step
    return find_steps(n - 1) + find_steps(n - 2);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << find_steps(n);
    return 0;
}