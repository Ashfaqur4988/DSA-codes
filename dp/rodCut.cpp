// memoization
int f(int ind, int target, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return target * price[0];
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int nt = 0 + f(ind - 1, target, price, dp);
    int t = INT_MIN;
    int rodLen = ind + 1;
    if (rodLen <= target)
        t = price[ind] + f(ind, target - rodLen, price, dp);

    return dp[ind][target] = max(t, nt);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int s = price.size();
    vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
    return f(s - 1, n, price, dp);
}

// tabulation
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int s = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }

    for (int ind = 1; ind < s; ind++)
    {
        for (int tar = 0; tar <= n; tar++)
        {

            int nt = 0 + dp[ind - 1][tar];
            int t = INT_MIN;
            int rodLen = ind + 1;
            if (rodLen <= tar)
                t = price[ind] + dp[ind][tar - rodLen];

            dp[ind][tar] = max(t, nt);
        }
    }
    return dp[s - 1][n];
}
