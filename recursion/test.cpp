#include <iostream>
using namespace std;

void print(int &n, int m)
{
    if (n == m)
    {
        return;
    }
    n++;
    cout << "printing" << endl;
    print(n, m);
}
void printLinear(int n, int i)
{
    if (n < i)
    {
        return;
    }
    cout << n << endl;
    printLinear(n - 1, i);
}

void backTrack(int i, int n)
{
    if (i > n)
    {
        return;
    }
    backTrack(i + 1, n);
    cout << i << endl;
}

int main()
{
    int n = 1;
    int m = 5;
    // print(n, m);
    // printLinear(m, n);
    backTrack(1, 3);
    return 0;
}