// memoization
int f(int i, vector<int> &heights, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int r = INT_MAX;
    int l = f(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    if (i > 1)
    {
        r = f(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
    }

    return dp[i] = min(l, r);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(heights.size() + 1, -1);
    return f(n - 1, heights, dp);
}

// tabulation
vector<int> dp(n, 0);
dp[0] = 0;

for (int i = 1; i < n; i++)
{
    int l = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    int r = INT_MAX;
    if (i > 1)
    {
        r = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    }
    dp[i] = min(l, r);
}
return dp[n - 1];

// space optimization
int prev2 = 0;
int prev = 0;

for (int i = 1; i < n; i++)
{
    int l = prev + abs(heights[i] - heights[i - 1]);
    int r = INT_MAX;
    if (i > 1)
    {
        r = prev2 + abs(heights[i] - heights[i - 2]);
    }
    int curr = min(l, r);

    prev2 = prev;
    prev = curr;
}
return prev;