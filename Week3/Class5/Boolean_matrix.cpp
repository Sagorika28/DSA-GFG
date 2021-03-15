// Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true)
// then make all the cells of ith row and jth column as 1.          ---   T=O(m*n), S=O(1)
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
void printMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(2) << mat[i][j];
        }
        cout << endl;
    }
}

class Solution
{
public:
    void booleanMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        //using the first colum and row as temporary arrays to mark
        bool row1 = false; // first row has 1 or not
        bool col1 = false; // first col has 1 or not
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // if any element in 1st row is 1, mark flag of row = true
                if (i == 0 && mat[i][j] == 1)
                    row1 = true;

                // if any element in 1st column is 1, mark flag of col = true
                if (j == 0 && mat[i][j] == 1)
                    col1 = true;

                // mark the corresponding element of 1st row and column as 1 if any element is true
                if (mat[i][j] == 1)
                {
                    mat[0][j] = 1;
                    mat[i][0] = 1;
                }
            }
        }

        //using the first colum and row (temp arrays) to mark the rows and columns with 1 at any position as 1 in the submatrix[m-1][n-1];
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (mat[0][j] == 1 || mat[i][0] == 1)
                    mat[i][j] = 1;
            }
        }

        // modify first row if there was any 1
        if (row1)
        {
            for (int j = 0; j < n; j++)
                mat[0][j] = 1;
        }

        // modify first column if there was any 1
        if (col1)
        {
            for (int i = 0; i < m; i++)
                mat[i][0] = 1;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row);
        for (int i = 0; i < row; i++)
        {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }

        cout << "Input Matrix :\n";
        printMatrix(matrix);

        Solution ob;
        ob.booleanMatrix(matrix);

        cout << "Matrix After Modification :\n";
        printMatrix(matrix);
    }
    return 0;
}