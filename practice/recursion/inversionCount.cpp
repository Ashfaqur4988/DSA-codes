#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> arr, int s, int e, int m)
{
    int count = 0;
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
            count = count + ((m - i) + 1);
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

    return count;
}
int mergeSort(vector<int> arr, int s, int e)
{
    int cnt = 0;
    int m = s + (e - s) / 2;
    if (s >= e)
    {
        return 0;
    }

    cnt = cnt + mergeSort(arr, s, m);
    cnt = cnt + mergeSort(arr, m + 1, e);
    cnt = cnt + merge(arr, s, e, m);
    return cnt;
}
int inversion(vector<int> arr, int n)
{
    int cnt = mergeSort(arr, 0, n - 1);
    return cnt;
}
int main()
{
    vector<int> arr = {6, 8, 4, 2, 1};
    int ans = inversion(arr, arr.size());
    cout << ans << endl;
    return 0;
}