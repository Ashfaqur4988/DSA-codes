#include <iostream>
using namespace std;

void rowWiseSum(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "sum row " << i + 1 << " is " << sum << endl;
    }
}

void colWiseSum(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << "sum col " << i + 1 << " is " << sum << endl;
    }
}

int main()
{
    int arr[3][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
    rowWiseSum(arr, 3, 3);
    colWiseSum(arr, 3, 3);
    return 0;
}