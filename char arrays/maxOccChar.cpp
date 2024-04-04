#include <iostream>
using namespace std;

char maxOccChar(string &str)
{
    int arr[26] = {0};
    int num = 0;
    // increasing the count with occurrence
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        // lowercase
        if (ch >= 'a' && ch <= 'z')
        {
            num = ch - 'a';
        }
        // uppercase
        else
        {
            num = ch - 'A';
        }
        arr[num]++;
    }

    // finding the max in the array
    int maxi = -1;
    int ans = 0; // to store the index
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxi)
        {
            ans = i;
            maxi = arr[i];
        }
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << "array " << arr[i] << endl;
    // }
    // cout << "maxi " << maxi << endl;
    // cout << "max index " << ans << endl;

    // convert the index to letter
    char result = 'a' + ans;

    return result;
}

int main()
{
    string str = "abcabda";

    char result = maxOccChar(str);
    cout << result << endl;
    return 0;
}