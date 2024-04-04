#include <iostream>
using namespace std;

// check if valid character or number
bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}

// convert to lower case
char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// check if palindrome
bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

int main()
{
    string str;
    cout << "enter string " << endl;
    cin >> str;

    string temp = "";

    // remove un necessary characters
    for (int j = 0; j < str.length(); j++)
    {
        if (valid(str[j]))
        {
            temp.push_back(str[j]);
        }
    }

    cout << "temp = " << temp << endl;

    // make lower case
    for (int j = 0; j < temp.length(); j++)
    {
        temp[j] = toLowerCase(temp[j]);
    }

    cout << "temp = " << temp << endl;

    if (isPalindrome(temp))
    {
        cout << "is Palindrome" << endl;
    }
    else
    {
        cout << "is not Palindrome" << endl;
    }
    return 0;
}