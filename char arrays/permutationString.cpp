#include <iostream>
using namespace std;

bool checkEqual(int count1[26], int count2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkPermutation(string str1, string str2)
{
    // character count array
    int count1[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        int index = str1[i] - 'a';
        count1[index]++;
    }

    // traverse s2 string in window of size s1 length & compare
    int i = 0;
    int count2[26] = {0};
    int windowSize = str1.length();

    // running for first window
    while (i < windowSize && i < str2.length())
    {
        int index = str2[i] - 'a';
        count2[index]++;
        i++;
    }

    if (checkEqual(count1, count2))
    {
        return true;
    }

    // process window further
    while (i < str2.length())
    {
        char newChar = str2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = str2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;

        if (checkEqual(count1, count2))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string str2 = "eidbaooo";
    string str1 = "db";
    if (checkPermutation(str1, str2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}