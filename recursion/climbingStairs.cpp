#include <iostream>
using namespace std;

int climbingWays(int stairs)
{
    // base case
    if (stairs < 0)
    {
        return 0;
    }

    if (stairs == 0)
    {
        return 1;
    }

    int ans = climbingWays(stairs - 1) + climbingWays(stairs - 2);
    return ans;
}
int main()
{
    int stairs = 4;
    int ways = climbingWays(stairs);
    cout << ways << endl;
    return 0;
}