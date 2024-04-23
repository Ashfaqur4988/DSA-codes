#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = row * col - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        int element = matrix[m / col][m % col];
        if (element == target)
        {
            return true;
        }
        if (element < target)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 20;
    bool res = binarySearch(matrix, target);
    cout << res << endl;
    return 0;
}