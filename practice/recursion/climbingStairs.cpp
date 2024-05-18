#include <iostream>
using namespace std;
int cs(int n)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    int ans = cs(n - 1) + cs(n - 2);
    return ans;
}
int main()
{
    int stairs = 3;
    int ans = cs(stairs);
    cout << ans << endl;
    return 0;
}