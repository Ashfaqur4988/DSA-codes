#include <iostream>
using namespace std;

void sortZeroes(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        while (arr[s] == 0 && s < e)
        {
            s++;
        }
        while (arr[e] == 1 && s < e)
        {
            e--;
        }
        if (s < e)
        {
            arr[s] = 0;
            arr[e] = 1;
            s++;
            e--;
        }
    }
    cout << "after " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6;
    int arr[n] = {0, 1, 1, 0, 0, 1};
    cout << "before " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    sortZeroes(arr, n);
    return 0;
}