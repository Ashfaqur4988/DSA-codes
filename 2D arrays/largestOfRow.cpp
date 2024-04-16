#include <iostream>
using namespace std;

void largestRowSum(int arr[][3], int r, int c)
{
    int largest = 0;
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "sum row " << i + 1 << " is " << sum << endl;
        if (sum > largest)
        {
            largest = sum;
                }
    }
    cout << "largest -> " << largest;
}

int main()
{
    int arr[3][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
    largestRowSum(arr, 3, 3);
    return 0;
}