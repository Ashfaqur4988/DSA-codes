#include <iostream>
using namespace std;

string removeSpaces(string str)
{
    string temp = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }

    return temp;
}

void replaceSpaces(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '@40';
        }
    }
}

int main()
{

    string str = "Well begun is half done";
    string result = removeSpaces(str);
    replaceSpaces(str);
    cout << result << endl;
    cout << "replace = " << str << endl;
    return 0;
}