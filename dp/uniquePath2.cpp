// memoization
int mod = (int)(1e9 + 7);

int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    if (i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int u = f(i - 1, j, mat, dp);
    int l = f(i, j - 1, mat, dp);

    return dp[i][j] = (u + l) % mod;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, mat, dp);
}

// tabulation
int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (mat[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int u = 0;
                int l = 0;

                if (i > 0)
                    u = dp[i - 1][j];
                if (j > 0)
                    l = dp[i][j - 1];

                dp[i][j] = (u + l) % mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// space optimization
int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {

        vector<int> curr(m, 0);

        for (int j = 0; j < m; j++)
        {

            if (mat[i][j] == -1)
                curr[j] = 0;
            else if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int u = 0;
                int l = 0;

                if (i > 0)
                    u = prev[j];
                if (j > 0)
                    l = curr[j - 1];

                curr[j] = (u + l) % mod;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}