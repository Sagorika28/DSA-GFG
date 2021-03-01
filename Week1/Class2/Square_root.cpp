//to find the square root of a number as an integer -- amazon etc
//Method 1 -- O(sqrt(n))
// for (i = 0; i < size; i++) {
//     if(i*i == num)
//         return i;
//     if(i*i < num)
//         return i;
// }

//Method 2 -- O(log n) - using binary search
#include <iostream>
using namespace std;

int find_sqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int beg = 1, end = x, i, sqrt;
    while (beg <= end)
    {
        i = (beg + end) / 2;
        if (i * i == x)
            return i;
        else if (i * i < x)
        {
            beg = i + 1;
            sqrt = i;
        }
        else
            end = i - 1;
    }
    return sqrt;
}

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    cout << find_sqrt(x);
    return 0;
}