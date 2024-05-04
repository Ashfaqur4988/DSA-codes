#include <iostream>
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
    int n = 5;
    int arr[5] = {2, 3, 5, 6, 8};
    bool ans = isSorted(arr, 5);
    if (ans)
    {
        cout << " sorted " << endl;
    }
    else
    {
        cout << " not sorted" << endl;
    }

    return 0;
}