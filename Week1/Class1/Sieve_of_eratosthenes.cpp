//To find the prime numbers till n using sieve of eratosthenes --- O(n*log(log(n)))
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    bool prime[n + 1];

    memset(prime, true, sizeof(prime));  //marking all numbers till n as prime

    for (int j = 2; j * j <= n; j++)
    {
        if (prime[j]) 
        {
            for (int p = 2 * j; p <= n; p += j)  //marking multiples of prime nos. as false
            {
                if (p % j == 0)
                    prime[p] = false;
            }
        }
    }

    //printing all the prime numbers from prime[]
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            cout << i << "  ";
    }
    return 0;
}