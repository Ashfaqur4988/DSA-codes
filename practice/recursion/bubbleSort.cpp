#include <iostream>
using namespace std;
void bubbleSort(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}
int main()
{
    int n = 5;
    int arr[5] = {2, 5, 7, 1, 3};
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}