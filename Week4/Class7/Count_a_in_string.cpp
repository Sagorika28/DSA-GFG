// To count the number of character 'a in given string using recursion.
// T(n) = O(n)
#include <iostream>
#include <cstring>
using namespace std;
int count(string str, int n)
{
    if (n == -1) // index = -1 means the whole string has been traversed
        return 0;

    if (str[n] == 'a')
        return 1 + count(str, n - 1);

    return count(str, n - 1);
}
int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    int n = str.size();
    cout << count(str, n - 1);
    return 0;
}