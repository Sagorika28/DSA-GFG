/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/
// T=O(log n) , S=O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1, mid, index = -1;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                index = mid + 1;
                beg = mid + 1;
            }
            else
                end = mid - 1;
        }
        return (index == -1 ? 0 : index);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    cout << s.searchInsert(v, 2);
    return 0;
}