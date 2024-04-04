#include <iostream>
#include <algorithm>
using namespace std;

void reversed(string &str, int s, int e)
{
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}

string reverseString(string str)
{
    str.push_back(' ');
    int j = 0;
    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            reversed(str, j, i - 1);
            j = i + 1;
        }
    }

    str.pop_back();

    reversed(str, 0, str.length() - 1);

    return str;
}

int main()
{
    string str = "my name is adam";

    cout << "before = " << str << endl;

    string rev = reverseString(str);

    cout << "after = " << rev << endl;
    return 0;
}