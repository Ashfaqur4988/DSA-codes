#include <iostream>
using namespace std;
void sayDigit(int n)
{
    string map[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // base case
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;
    cout << map[digit] << " ";

    sayDigit(n);
    cout << map[digit] << " ";
}
int main()
{
    int n = 234;
    sayDigit(n);
    return 0;
}