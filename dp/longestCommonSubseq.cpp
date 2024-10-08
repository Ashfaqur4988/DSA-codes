// memoization
int f(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.size())
    {
        return 0;
    }
    if (j == b.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + f(a, b, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(f(a, b, i + 1, j, dp), f(a, b, i, j + 1, dp));
    }
    return dp[i][j] = ans;
}
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return f(text1, text2, 0, 0, dp);
}

// tabulation
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    // return f(text1, text2, 0, 0, dp);

    for (int i = text1.size() - 1; i >= 0; i--)
    {

        for (int j = text2.size() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

// space optimization
int longestCommonSubsequence(string text1, string text2)
{
    // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
    // return f(text1, text2, 0, 0, dp);
    vector<int> curr(text2.size() + 1, 0);
    vector<int> next(text2.size() + 1, 0);

    for (int i = text1.size() - 1; i >= 0; i--)
    {

        for (int j = text2.size() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}