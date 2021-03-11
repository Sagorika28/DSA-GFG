// Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.   T=O(m+n), S=O(1)

#include <iostream>
using namespace std;
#define R 4
#define C 4

// Function to find the index of first index of 1 in a boolean array arr[]
int first(bool arr[], int low, int high)
{
    if (high >= low)
    {
        // Get the middle index
        int mid = low + (high - low) / 2;

        // Check if the element at middle index is first 1
        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
            return mid;

        // If the element is 0, recur for right side
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);

        // If element is not first 1, recur for left side
        else
            return first(arr, low, (mid - 1));
    }
    return -1;
}

// Function that returns index of row with maximum number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    // Initialize max values
    int max_row_index = 0, row1, max = -1;
    int j = first(mat[0], 0, C - 1); // lower bound of 1 in first row
    if (j == -1)
        j = C - 1;

    // for the remaining rows
    for (int i = 1; i < R; i++)
    {
        // move left of j i.e. left of the above row to see if 1 is there or not
        while (j >= 0 && mat[i][j] == 1)
        {
            j--;
            max_row_index = i;
        }
    }
    return max_row_index;
}

int main()
{
    bool mat[R][C] = {{0, 0, 0, 1},
                      {0, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 0, 0}};

    cout << "Index of row with maximum 1's is " << rowWithMax1s(mat);
    return 0;
}