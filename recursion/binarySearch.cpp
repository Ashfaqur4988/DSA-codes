#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key)
{
    // base case

    if (s > e)
    {
        return false;
    }
    // processing
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (mid < key)
    {
        // recursive relation
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        // recursive relation
        return binarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int n = 6;
    int arr[6] = {2, 4, 6, 8, 9, 11};
    int key = 9;
    int ans = binarySearch(arr, 0, n - 1, 9);
    cout << ans << endl;
    return 0;
}