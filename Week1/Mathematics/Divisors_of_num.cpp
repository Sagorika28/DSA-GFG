// To find out divisors of a number in sqrt(n)
// diviors / factors occur in pairs. eg: for 100 - (1,100), (2,50), (4,25), (5,20), (10,10)
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, count = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                count++;
                cout << i << " ";
            }
            else
            {
                count += 2;
                cout << i << " " << (n / i) << " ";
            }
        }
    }
    cout << "\nNo. of divisors = " << count;
    return 0;
}