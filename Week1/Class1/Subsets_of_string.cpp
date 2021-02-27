//print all the substrings of a string. eg: for str="pqr", substrings are "p","q","pqr","qr","r","pq" --- as total no. of substrings = n(n+1)/2
#include <iostream>
#include <cstring>
using namespace std;

void find_substring(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            string substring = "";
            for (int j = i; j < i + len; j++)
            {
                substring += str[j];
            }
            cout << substring << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    find_substring(str, str.length());
    return 0;
}