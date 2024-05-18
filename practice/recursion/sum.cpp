#include <iostream>
using namespace std;
int getSum(int n)
{
    // base
    if (n == 0)
    {
        return 0;
    }

    int sum = n + getSum(n - 1);
    return sum;
}
int main()
{
    int n = 5;
    int ans = getSum(n);
    cout << ans << endl;
    return 0;
}