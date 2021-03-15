// Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another string that
// contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.
// 1. Sort the strings and compare them     --- T=(n logn) , S=O(1)
// 2. Hashing   --- T=O(n), S=O(n)
#include <iostream>
#define NO_OF_CHARS 256
using namespace std;
bool areAnagram(char str1[], char str2[])
{
    int count[NO_OF_CHARS] = {0};
    int i;

    // For each character in input strings, increment count in the corresponding hashmap
    for (i = 0; str1[i] && str2[i]; i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    // to make sure program doesn't fail with strings like 'aaca' and 'aca'
    if (str1[i] || str2[i])
        return false;

    // checking if both the strings matched i.e. if they have a non-zero value after traversing both the strings, we return false since no. of characters in both differ
    for (i = 0; i < NO_OF_CHARS; i++)
    {
        if (count[i])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char str1[] = "geeksforgeeks";
    char str2[] = "forgeeksgeeks";

    // Function Call
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each other";

    return 0;
}