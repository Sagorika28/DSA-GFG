// Choose a minimum number of weights to be able to measure all weights between 1-n kg.
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << ceil(log(n) / log(3));
}