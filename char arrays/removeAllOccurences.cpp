#include <iostream>
using namespace std;

string removeOcc(string str, string sub)
{
    while (str.length() != 0 && str.find(sub) < str.length())
    {
        str.erase(str.find(sub), sub.length());
    }
    return str;
}

int main()
{
    string str = "daabcbaabcbc";
    string sub = "abc";
    cout << str << endl;
    string result = removeOcc(str, sub);
    cout << result << endl;
    return 0;
}