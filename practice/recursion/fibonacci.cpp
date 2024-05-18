#include <iostream>
#include <vector>
using namespace std;
int fibo(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int num = fibo(n - 1) + fibo(n - 2);
    return num;
}
int main()
{
    int n = 6;
    int ans = fibo(n);
    cout << ans << endl;
    return 0;
}