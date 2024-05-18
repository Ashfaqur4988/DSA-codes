#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(arr + 1, n - 1);
        return ans;
    }
}
int main()
{
    int n = 6;
    int arr[6] = {2, 4, 6, 9, 11, 13};
    int ans = isSorted(arr, n);
    cout << ans << endl;
    return 0;
}