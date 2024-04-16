#include <iostream>
using namespace std;

bool isPresent(int arr1[][3], int k, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr1[i][j] == k)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int k;
    int arr1[3][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
    // int arr[3][4];
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arr1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "enter element to find " << endl;
    cin >> k;

    if (isPresent(arr1, k, 3, 3))
    {
        cout << "present " << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    return 0;
}