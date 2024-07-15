#include <bits/stdc++.h>

void heapify(vector<int> &arr, int size, int i)
{
    int lar = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[lar] < arr[l])
    {
        lar = l;
    }
    if (r < size && arr[lar] < arr[r])
    {
        lar = r;
    }
    if (lar != i)
    {
        swap(arr[lar], arr[i]);
        heapify(arr, size, lar);
    }
    return;
}

vector<int> heapSort(vector<int> &arr, int n)
{
    // Write your code here.
    int size = n;

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    while (size > 1)
    {

        swap(arr[0], arr[size - 1]);
        size--;

        heapify(arr, size, 0);
    }
    return arr;
}