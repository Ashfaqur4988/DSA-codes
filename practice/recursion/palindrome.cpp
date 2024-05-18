#include <iostream>
using namespace std;
bool palindrome(string str, int s, int e)
{
    if (s > e)
    {
        return true;
    }
    if (str[s] != str[e])
    {
        return false;
    }
    else
    {
        return palindrome(str, ++s, --e);
    }
}
int main()
{
    string str = "abba";
    bool ans = palindrome(str, 0, str.size() - 1);
    cout << ans << endl;
    return 0;
}