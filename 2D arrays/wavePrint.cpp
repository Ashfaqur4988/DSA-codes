#include <iostream>
using namespace std;

void wavePrint(int arr[][3], int r, int c)
{

    for (int col = 0; col < c; col++)
    {
        if (col & 1)
        {
            // odd index -> bottom to top
            for (int row = r - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            // even index -> top to bottom
            for (int row = 0; row < r; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main()
{

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    wavePrint(arr, 3, 3);
    return 0;
}