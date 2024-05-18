#include <iostream>
using namespace std;
int ls(int arr[], int n, int key)
{
    // base
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] == key)
    {
        return arr[0];
    }
    else
    {
        int ans = ls(arr + 1, n - 1, key);
        return ans;
    }
}
int main()
{
    int n = 5;
    int arr[5] = {4, 6, 8, 2, 9};
    int key = 2;
    int ans = ls(arr, n, key);
    cout << ans << endl;
    return 0;
}