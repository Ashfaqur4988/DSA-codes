#include <iostream>
using namespace std;
int steps(int src, int dest)
{
    // base case
    if (src == dest)
    {
        return 0;
    }
    src++;

    int ans = steps(src, dest);

    return ans;
}
int main()
{
    int src = 0;
    int dest = 10;
    int ans = steps(src, dest);
    cout << ans << endl;
    return 0;
}