// recursive approach
bool f(int ind, const string &s, const unordered_set<string> &st, vector<bool> &dp)
{
    if (ind == s.size())
        return true;

    for (int l = 1; l <= s.size() - ind; l++)
    {
        string t = s.substr(ind, l);

        if (st.find(t) != st.end() && f(ind + l, s, st, dp))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{

    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size(), -1);

    return f(0, s, st, dp);
}

// memoization
bool f(int ind, const string &s, const unordered_set<string> &st, vector<int> &dp)
{
    if (ind == s.size())
        return true;
    if (dp[ind] != -1)
        return dp[ind];
    for (int l = 1; l <= s.size() - ind; l++)
    {
        string t = s.substr(ind, l);

        if (st.find(t) != st.end() && f(ind + l, s, st, dp))
        {
            return dp[ind] = true;
        }
    }
    return dp[ind] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{

    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<int> dp(301, -1);

    return f(0, s, st, dp);
}

// tabulation
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<bool> dp(301, false);

    dp[n] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int l = 1; l <= n - i; l++)
        {
            string t = s.substr(i, l);
            if (st.find(t) != st.end() && dp[i + l])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}