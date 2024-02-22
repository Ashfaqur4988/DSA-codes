#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int arr3[], int n, int m)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && i < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < n)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

void print(int arr3[], int n, int m)
{
    for (int i = 0; i < n + m; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 4;
    int m = 5;
    int arr1[n] = {1, 3, 5, 7};
    int arr2[m] = {2, 4, 6, 8, 9};
    int arr3[n + m] = {0};

    merge(arr1, arr2, arr3, n, m);
    print(arr3, n, m);
    return 0;
}