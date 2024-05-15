#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e, int mid)
{
    vector<int> temp;
    int i = s;
    int j = mid + 1;
    while (i <= mid && j <= e)
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
    while (i <= mid)
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

void ms(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    ms(arr, s, mid);
    ms(arr, mid + 1, e);
    merge(arr, s, e, mid);
}

int main()
{
    vector<int> arr = {6, 4, 8, 2, 1};
    int s = 0;
    int e = arr.size() - 1;
    ms(arr, s, e);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}