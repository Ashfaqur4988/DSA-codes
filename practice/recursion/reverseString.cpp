#include <iostream>
using namespace std;
void rev(string &str, int s, int e)
{
    if (s > e)
    {
        return;
    }

    swap(str[s], str[e]);

    rev(str, ++s, --e);
}
int main()
{
    string str = "abcde";
    rev(str, 0, str.size() - 1);
    cout << str << endl;
    return 0;
}