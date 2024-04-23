#include <iostream>
#include <vector>
using namespace std;

void spiralPrint(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // index initialization
    int top = 0;
    int left = 0;
    int right = col - 1;
    int bottom = row - 1;

    while (top <= bottom && left <= right)
    {
        // print from top to right
        for (int i = left; i <= right; i++)
        {
            cout << matrix[top][i] << " ";
        }
        top++;
        // print right to bottom
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][right] << " ";
        }
        right--;
        // print bottom to left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        // print left to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    spiralPrint(matrix);
    return 0;
}