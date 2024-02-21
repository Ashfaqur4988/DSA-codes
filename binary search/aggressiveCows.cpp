#include <iostream>
#include <algorithm>
using namespace std;

bool possibleSoln(int positions[], int stalls, int mid, int cows)
{
    int cowCount = 1;
    int lastPosition = positions[0];

    for (int i = 0; i < stalls; i++)
    {
        if (positions[i] - lastPosition >= mid)
        {
            cowCount++;
            if (cowCount == cows)
            {
                return true;
            }
            lastPosition = positions[i];
        }
    }
    return false;
}

int cowPosition(int positions[], int stalls, int cows)
{
    int start = 0;
    int maxi = -1;
    for (int i = 0; i < stalls; i++)
    {
        maxi = max(maxi, positions[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (possibleSoln(positions, stalls, mid, cows))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int stalls = 5;
    int cows = 2;
    int positions[stalls] = {4, 2, 1, 3, 6};
    int n = sizeof(positions) / sizeof(positions[0]);
    sort(positions, positions + n);
    int ans = cowPosition(positions, stalls, cows);
    cout << ans << endl;

    return 0;
}