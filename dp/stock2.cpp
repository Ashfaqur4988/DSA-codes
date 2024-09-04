// memoization
int f(int ind, bool buy, vector<int> &prices, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (ind == n)
        return 0;

    int profit = 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, prices, dp),
                     0 + f(ind + 1, 1, prices, dp));
    }
    else
    {
        profit = max(prices[ind] + f(ind + 1, 1, prices, dp),
                     0 + f(ind + 1, 0, prices, dp));
    }
    return dp[ind][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return f(0, 1, prices, dp);
}

// tabulation
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    int profit = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// space optimization
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[ind] + prev[0], 0 + prev[1]);
            }
            else
            {
                profit = max(prices[ind] + prev[1], 0 + prev[0]);
            }
            curr[buy] = profit;
        }
        prev = curr;
    }
    return prev[1];
}