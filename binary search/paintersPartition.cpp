#include <iostream>
using namespace std;

bool isPossible(int canvasSize[], int canvas, int painters, int mid)
{
    int canvasSizeCount = 0;
    int paintersCount = 1;
    for (int i = 0; i < canvas; i++)
    {
        if (canvasSizeCount + canvasSize[i] <= mid)
        {
            canvasSizeCount = canvasSizeCount + canvasSize[i];
        }
        else
        {
            paintersCount++;
            if (paintersCount > painters || canvasSize[i] > mid)
            {
                return false;
            }
            canvasSizeCount = canvasSize[i];
        }
    }
    return true;
}

int partition(int canvasSize[], int canvas, int painters)
{
    int start = 0;
    int sum = 0;
    for (int i = 0; i < canvas; i++)
    {
        sum = sum + canvasSize[i];
    }
    int end = sum;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (isPossible(canvasSize, canvas, painters, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int canvas = 4;
    int painters = 2;
    int canvasSize[canvas] = {5, 5, 5, 5};

    int ans = partition(canvasSize, canvas, painters);
    cout << ans << endl;

    return 0;
}