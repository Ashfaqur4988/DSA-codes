#include <iostream>
using namespace std;

void move(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    int arr[n] = {0, 1, 0, 3, 12};
    move(arr, n);
    return 0;
}