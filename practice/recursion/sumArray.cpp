#include <iostream>
using namespace std;
int getSum(int arr[], int n)
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

    int sum = 0;
    sum = arr[0] + getSum(arr + 1, n - 1);
    return sum;
}
int main()
{
    int n = 6;
    int arr[6] = {3, 4, 5, 6, 7, 8};
    int ans = getSum(arr, n);
    cout << ans << endl;
    return 0;
}