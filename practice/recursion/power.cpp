#include <iostream>
using namespace std;
int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p == 1)
    {
        return n;
    }
    int ans = power(n, p / 2);
    if (p % 2 != 0)
    {
        // odd
        ans = n * ans * ans;
    }
    else
    {
        // even
        ans = ans * ans;
    }
    return ans;
}
int main()
{
    int n = 5;
    int p = 2;
    int ans = power(n, p);
    cout << ans << endl;
    return 0;
}