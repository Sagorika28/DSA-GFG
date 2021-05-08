// Given an array of integers and a positive integer, determine the number of pairs where i<j and ar[i]+ar[j] is divisible by k
// Example: ar=[1,2,3,4,5,6], k=5
// 3 pairs meet the criteria: [1,4], [2,3], [4,6]
// T(n)=O(n), S(n)=O(n)
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

int find_dpairs(int ar[], int n, int k)
{
    // 1. find the frequencies of the remainders (after dividing by k) of the elements in the array and store it in a map
    unordered_map<int, int> remainders;
    int rem;
    for (int i = 0; i < n; i++)
    {
        rem = ar[i] % k;
        if (remainders.find(rem) != remainders.end()) // if remainder is already present in the map, increase its frequency
            remainders[rem] += 1;
        else //else add it in the map and make its frequency 1
            remainders[rem] = 1;
    }

    // 2. multiply the frequencies with the complement frequencies or do nC2 for remainder = 0 or k/2
    int pairs = 0;
    for (auto i : remainders)
    {
        int p = 0, rem = i.first, freq = i.second;
        int complement = k - rem;
        if (complement == k or (2 * complement == k)) // to check for even numbers (even no: k/2) or 0 remainder
            p = floor((freq * (freq - 1)) / 2);
        else if (remainders.find(complement) != remainders.end()) // checking whether complement exists in the set or not to be able to make a pair
        {
            p = freq * remainders[complement];
            remainders[rem] = 0; //making the frequency 0 as it's already been used up and we don't double count it
        }

        // add the no. of pairs
        pairs += p;
    }

    // 3. return the sum
    return pairs;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << find_dpairs(ar, n, k);
    return 0;
}