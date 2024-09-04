// memoization
int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (tar % coins[0] == 0)
            return tar / coins[ind];
        else
            return 1e9;
    }

    if (dp[ind][tar] != -1)
        return dp[ind][tar];

    int nt = 0 + f(ind - 1, tar, coins, dp);
    int t = INT_MAX;
    if (coins[ind] <= tar)
        t = 1 + f(ind, tar - coins[ind], coins, dp);

    return dp[ind][tar] = min(t, nt);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, coins, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}

// tabulation
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int T = 0; T <= amount; T++)
    {
        if (T % coins[0] == 0)
            dp[0][T] = T / coins[0];
        else
            dp[0][T] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {
            int nt = 0 + dp[ind - 1][tar];
            int t = INT_MAX;
            if (coins[ind] <= tar)
            {
                t = 1 + dp[ind][tar - coins[ind]];
            }

            dp[ind][tar] = min(t, nt);
        }
    }

    int ans = dp[n - 1][amount];
    if (ans >= 1e9)
        return -1;
    return ans;
}