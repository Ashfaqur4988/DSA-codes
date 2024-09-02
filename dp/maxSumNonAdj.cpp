// memoization
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + solve(ind - 2, nums, dp);
    int notPick = 0 + solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size(), -1);
    return solve(nums.size() - 1, nums, dp);
}

// tabulation

// space optimized
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    vector<int> dp(nums.size(), -1);
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int p = nums[i];
        if (i > 1)
            p = p + prev2;
        int np = 0 + prev;

        int curr = max(p, np);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
