#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix)
{
    vector<vector<int>> temp = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < row; i++)
    {
        int s = 0;
        int e = col - 1;
        while (s <= e)
        {
            swap(temp[i][s], temp[i][e]);
            s++;
            e--;
        }
    }

    return temp;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result = rotateMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}