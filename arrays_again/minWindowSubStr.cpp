string minWindow(string s, string t)
{
    if (t.empty() > s.empty())
        return "";

    int n = s.size();
    int m = t.size();
    int i = 0;
    int j = 0;
    int winSize = INT_MAX;
    int sInd = 0;
    int reqCnt = m;
    unordered_map<char, int> mp;
    for (char c : t)
    {
        mp[c]++;
    }

    while (j < n)
    {
        char ch = s[j];

        if (mp[ch] > 0)
        {
            reqCnt--;
        }

        mp[ch]--;

        while (reqCnt == 0)
        {
            // start shrinking the window
            int currWindSize = j - i + 1;

            if (winSize > currWindSize)
            {
                winSize = currWindSize;
                sInd = i;
            }
            mp[s[i]]++;

            if (mp[s[i]] > 0)
            {
                reqCnt++;
            }
            i++;
        }

        j++;
    }

    return winSize == INT_MAX ? "" : s.substr(sInd, winSize);
}