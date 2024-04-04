#include <iostream>
using namespace std;

char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(char str[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (!isalpha(str[s]) && !isdigit(str[s]))
        {
            s++;
        }
        if (!isalpha(str[e]) && !isdigit(str[e]))
        {
            e--;
        }
        if (toLowerCase(str[s]) != toLowerCase(str[e]))
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}

int getLen(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char str[10];
    cout << "enter string " << endl;
    cin >> str;

    int n = getLen(str);
    cout << "length " << n << endl;

    if (isPalindrome(str, n))
    {
        cout << "Yes " << endl;
    }
    else
    {
        cout << "No " << endl;
    }

    return 0;
}