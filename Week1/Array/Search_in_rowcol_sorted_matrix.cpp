// Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x.
// Find whether element x is present in the matrix or not.
// T = O(n*log(m))    S=O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool binary_search(vector<vector<int>> matrix, int n, int m, int x, int row)
    {
        int l = 0;
        int r = m - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (matrix[row][mid] == x)
                return true;
            if (matrix[row][mid] < x)
                l = mid + 1;
            if (matrix[row][mid] > x)
                r = mid - 1;
        }
        if (l > r)
            return false;
    }

    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        //find the row in which the element might exist
        for (int i = 0; i < n; i++)
        {
            //check if the element lies in that row
            if (x >= matrix[i][0] && x <= matrix[i][m - 1])
            {
                if (binary_search(matrix, n, m, x, i))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}