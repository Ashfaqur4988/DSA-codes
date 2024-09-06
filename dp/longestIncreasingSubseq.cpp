// memoization
int f(int ind, int prevInd, int n, vector<int> &nums, vector<vector<int>> dp)
{
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][prevInd + 1] != -1)
        return dp[ind][prevInd + 1];
    int nt = 0 + f(ind + 1, prevInd, n, nums, dp);
    int t = 0;
    if (prevInd == -1 || nums[ind] > nums[prevInd])
    {
        t = 1 + f(ind + 1, ind, n, nums, dp);
    }

    return dp[ind][prevInd + 1] = max(t, nt);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, n, nums, dp);
}

// tabulation
int longestSubsequence(int n, int a[])
{
    // your code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {

            int nt = 0 + dp[ind + 1][prev + 1];
            int t = 0;
            if (prev == -1 || a[ind] > a[prev])
            {
                t = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev + 1] = max(t, nt);
        }
    }
    return dp[0][0];
}

// binary search
int longestSubsequence(int n, int a[])
{
    // your code here
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
            ans.push_back(a[i]);
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}