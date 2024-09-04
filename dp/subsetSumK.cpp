// recursion
bool f(int ind, int tar, vector<int> &arr)
{
    if (tar == 0)
        return true;
    if (ind == 0)
        return (arr[0] == tar);

    bool nt = f(ind - 1, tar, arr);
    bool t = false;
    if (tar >= arr[ind])
    {
        t = f(ind - 1, tar - arr[ind], arr);
    }

    return t | nt;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    return f(n - 1, k, arr);
}

// memoization
bool f(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    if (tar == 0)
        return true;
    if (ind == 0)
        return (arr[0] == tar);

    bool nt = f(ind - 1, tar, arr, dp);
    bool t = false;
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    if (tar >= arr[ind])
    {
        t = f(ind - 1, tar - arr[ind], arr, dp);
    }

    return dp[ind][tar] = t | nt;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nt = dp[ind - 1][target];
            bool t = false;

            if (arr[ind] <= target)
                t = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = t | nt;
        }
    }
    return dp[n - 1][k];
}

// space optimization
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nt = prev[target];
            bool t = false;

            if (arr[ind] <= target)
                t = prev[target - arr[ind]];

            curr[target] = t | nt;
        }
        prev = curr;
    }
    return prev[k];
}