// To count the number of set bits in a number
#include <iostream>
using namespace std;

int count_set_bits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // Brian-kernighan's algo
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << count_set_bits(n);
    return 0;
}