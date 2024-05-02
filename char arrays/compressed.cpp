#include <iostream>
using namespace std;

int compression(string s)
{
    int i = 0;
    int ansIndex = 0;
    int n = s.length();

    while (i < n)
    {
        int j = i + 1;
        while (j < n && s[i] == s[j])
        {
            j++;
        }
        // when traversal complete or new character encountered

        // store old char
        s[ansIndex++] = s[i];
        // storing the frequency of the char
        int count = j - i;

        if (count > 1)
        {
            // converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                s[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    string s = "aabbbcccd";
    int res = compression(s);
    cout << res << endl;
    return 0;
}