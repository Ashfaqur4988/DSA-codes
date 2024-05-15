#include <iostream>
using namespace std;

bool palindrome(string str, int i, int j)
{
    // base case
    if (i > j)
    {
        return true;
    }

    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        // recursive relation
        return palindrome(str, i + 1, j - 1);
    }
}

int main()
{
    string str = "abba";
    bool check = palindrome(str, 0, str.size() - 1);
    cout << check << endl;
    return 0;
}