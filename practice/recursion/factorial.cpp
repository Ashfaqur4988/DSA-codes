#include <iostream>
using namespace std;
int fact(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    int ans = n * fact(n - 1);
    return ans;
}
int main()
{
    int n = 4;
    int ans = fact(n);
    cout << ans << endl;
    return 0;
}