#include <iostream>
using namespace std;

int getSum(int n)
{
    // base case
    if (n < 1)
    {
        return 0;
    }
    int sum = n + getSum(n - 1);

    return sum;
}
int main()
{
    int n = 7;
    int sum = getSum(n);
    cout << sum << endl;
    return 0;
}