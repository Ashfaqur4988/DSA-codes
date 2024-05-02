#include <iostream>
using namespace std;
void printDesc(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // processing
    cout << n << endl;

    // recursive relation
    printDesc(n - 1);
}

void printAsc(int n)
{
    if (n == 0)
    {
        return;
    }

    printAsc(n - 1);

    cout << n << endl;
}
int main()
{
    int n = 5;
    printDesc(n);
    cout << endl;
    printAsc(n);
    return 0;
}