// Given an array of names of candidates in an election. A candidate name in array represents a vote casted to the candidate.
// Print the name of candidates received Max vote. If there is tie, print lexicographically smaller name.
// T=O(n), S=O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void findWinner(vector<string> votes)
{
    map<string, int> mp;
    for (int i = 0; i < votes.size(); i++)
        mp[votes[i]]++;

    int max = 0;    // maximum count till now
    string key;     // candidate with max votes till now
    for (int i = 0; i < votes.size(); i++)
    {
        if (mp[votes[i]] > max)     // if current candidate's votes are more than previous max
        {
            max = mp[votes[i]];
            key = votes[i];
        }

        if (mp[votes[i]] == max && votes[i] < key)      // if current candidate's votes are equal to previous max (tie) but his name is lexicographically smaller than previous candidate
        {
            key = votes[i];                             // winner is the one with smaller lexicographical name
        }
    }
    cout << "Election won by " << key << " who got " << max << " votes.";
}

int main(int argc, char const *argv[])
{
    vector<string> votes = {"John", "Johnny", "Jackie",
                            "Johnny", "John", "Jackie",
                            "Jamie", "Jamie", "John",
                            "Johnny", "Jamie", "Johnny",
                            "John"};

    findWinner(votes);
    return 0;
}