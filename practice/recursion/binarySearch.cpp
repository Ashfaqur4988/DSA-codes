#include <iostream>
using namespace std;
bool bs(int arr[], int s, int e, int key)
{
    int m = s + (e - s) / 2;
    if (s > e)
    {
        return false;
    }
    if (key == arr[m])
    {
        return true;
    }

    if (m < key)
    {
        bool ans = bs(arr, m + 1, e, key);
        return ans;
    }
    else
    {
        bool ans = bs(arr, s, m - 1, key);
        return ans;
    }
}
int main()
{
    int n = 5;
    int arr[5] = {2, 4, 6, 7, 9};
    int key = 2;
    bool ans = bs(arr, 0, n - 1, key);
    cout << ans << endl;
    return 0;
}