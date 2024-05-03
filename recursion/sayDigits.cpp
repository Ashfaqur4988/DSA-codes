#include <iostream>
using namespace std;
void sayDigits(int n, string alpha[])
{
    // base case
    if (n == 0)
    {
        return;
    }
    // processing
    int digit = n % 10;
    n = n / 10;

    // recursive relation
    sayDigits(n, alpha);
    cout << alpha[digit] << " ";
}
int main()
{
    string alpha[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n = 123;
    sayDigits(n, alpha);
    return 0;
}