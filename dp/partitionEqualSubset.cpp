// memoization
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (target == arr[0]);

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool np = f(ind - 1, target, arr, dp);
    bool p = false;

    if (arr[ind] <= target)
    {
        p = f(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = p | np;
}
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2)
    {
        return false;
    }

    int k = sum / 2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return f(n - 1, sum / 2, arr, dp);
}

// tabulation
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2)
    {
        return false;
    }

    int k = sum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nt = dp[ind - 1][target];
            bool t = false;

            if (arr[ind] <= target)
                t = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = t || nt;
        }
    }

    return dp[n - 1][k];
}
