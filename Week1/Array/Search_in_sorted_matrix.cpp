// To find an element in a 2D matrix ---- T=O(log(mn))    S=O(1)
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
        int l = 0, r = n - 1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            //check if the element is the first element of the row
            if (matrix[mid][0] == x)
                return true;
            //check if the element is the last element of the row
            if (matrix[mid][m - 1] == x)
                return true;

            //check if the element lies in that row
            if (x > matrix[mid][0] && x < matrix[mid][m - 1])
            {
                if (binary_search(matrix, n, m, x, mid))
                    return true;
                return false;
            }

            if (x < matrix[mid][0])
                r = mid - 1;
            if (x > matrix[mid][0])
                l = mid + 1;
        }
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