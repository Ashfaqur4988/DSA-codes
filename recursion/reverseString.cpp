#include <iostream>
using namespace std;
void reverse(string &str, int s, int e)
{
    // base case
    if (s > e)
    {
        return;
    }
    swap(str[s], str[e]);
    s++;
    e--;

    // recursive call
    reverse(str, s, e);
}
int main()
{
    string str = "abcde";
    reverse(str, 0, str.size() - 1);
    cout << str << endl;
    return 0;
}