#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int n, int s, int e, int m)
{
    vector<int> temp;
    int i = s;
    int j = m + 1;

    while (i <= m && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = s; k <= e; k++)
    {
        arr[k] = temp[k - s];
    }
}
void mergeSort(vector<int> &arr, int n, int s, int e)
{

    if (s >= e)
    {
        return;
    }
    int m = s + (e - s) / 2;
    // left part
    mergeSort(arr, n, s, m);
    // right part
    mergeSort(arr, n, m + 1, e);

    merge(arr, n, s, e, m);
}
int main()
{
    int n = 6;
    vector<int> arr = {4, 6, 8, 2, 7, 5};
    mergeSort(arr, n, 0, n - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}