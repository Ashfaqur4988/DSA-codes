#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> markedRow(row, 0);
    vector<int> markedCol(col, 0);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                markedRow[i] = -1;
                markedCol[j] = -1;
            }
        }
    }

    for (int k = 0; k < row; k++)
    {
        for (int l = 0; l < col; l++)
        {
            if (markedRow[k] == -1 || markedCol[l] == -1)
            {
                matrix[k][l] = 0;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> setZeroesOp(vector<vector<int>> matrix, int row, int col)
{
    int col0 = 1;
    // marking the columns and the rows
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                // marked the ith row
                matrix[i][0] = 0;
                // marked the jth col
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check if the cols or rows
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[j][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int row = matrix.size();
    int col = matrix[0].size();
    // setZeroes(matrix);
    vector<vector<int>> result = setZeroesOp(matrix, row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}