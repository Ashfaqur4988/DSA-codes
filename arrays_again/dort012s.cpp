#include <iostream>
using namespace std;

void sortZeroOneTwo(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    for (int mid = 0; mid < n && mid <= high;)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
    cout << "after" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6;
    int arr[n] = {0, 1, 2, 0, 2, 1};
    cout << "before " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    sortZeroOneTwo(arr, n);
    return 0;
}