#include <iostream>
using namespace std;

bool search(int arr[], int n, int key)
{
    cout << "size " << n << endl;
    // base case
    if (n == 0)
    {
        return false;
    }
    // recursive relation
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        bool ans = search(arr + 1, n - 1, key);
        return ans;
    }
}

int main()
{
    int n = 6;
    int key = 7;
    int arr[6] = {2, 4, 6, 7, 9, 0};
    int ans = search(arr, n, key);
    cout << ans << endl;
    return 0;
}