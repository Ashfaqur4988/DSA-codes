#include <iostream>
using namespace std;
int sumOfArr(int arr[], int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    int remainingPart = sumOfArr(arr + 1, n - 1);
    int sum = arr[0] + remainingPart;

    return sum;
}
int main()
{
    int n = 5;
    int arr[5] = {2, 5, 7, 4, 1};
    int sum = sumOfArr(arr, n);
    cout << sum << endl;
    return 0;
}