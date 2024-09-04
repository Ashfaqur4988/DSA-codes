// memoization
int mod = 1e9 + 7;
int f(int ind, int target, int arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];
    int t = 0;
    int nt = f(ind - 1, target, arr, dp) % mod;
    if (arr[ind] <= target)
        t = f(ind - 1, target - arr[ind], arr, dp) % mod;

    return dp[ind][target] = (t + nt) % mod;
}
int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n - 1, sum, arr, dp);
}

// tabulation
int mod = 1e9 + 7;
int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;
    if (arr[0] == 0)
        dp[0][0] = 2;

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= sum; tar++)
        {
            int t = 0;
            int nt = dp[ind - 1][tar];
            if (arr[ind] <= tar)
                t = dp[ind - 1][tar - arr[ind]];

            dp[ind][tar] = (t + nt) % mod;
        }
    }

    return dp[n - 1][sum];
}