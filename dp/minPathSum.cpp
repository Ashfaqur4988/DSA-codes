// memoization
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int u = grid[i][j] + f(i - 1, j, grid, dp);
    int l = grid[i][j] + f(i, j - 1, grid, dp);

    return dp[i][j] = min(u, l);
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, grid, dp);
}

// tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int u = grid[i][j];
                if (i > 0)
                    u = u + dp[i - 1][j];
                else
                {
                    u = u + 1e9;
                }

                int l = grid[i][j];
                if (j > 0)
                    l = l + dp[i][j - 1];
                else
                {
                    l = l + 1e9;
                }

                dp[i][j] = min(u, l);
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int u = grid[i][j];
                if (i > 0)
                    u = u + prev[j];
                else
                {
                    u = u + 1e9;
                }

                int l = grid[i][j];
                if (j > 0)
                    l = l + curr[j - 1];
                else
                {
                    l = l + 1e9;
                }

                curr[j] = min(u, l);
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}