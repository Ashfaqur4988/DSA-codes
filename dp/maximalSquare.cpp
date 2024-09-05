// memoization
int f(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    int r = f(mat, i, j + 1, maxi, dp);
    int dia = f(mat, i + 1, j + 1, maxi, dp);
    int d = f(mat, i + 1, j, maxi, dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(r, min(dia, d));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;
    f(mat, 0, 0, maxi, dp);
    return maxi;
}

// tabulation
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxi = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int r = dp[i][j + 1];
            int dia = dp[i + 1][j + 1];
            int d = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(r, min(dia, d));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}

// space optimization
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // code here
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    int maxi = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int r = curr[j + 1];
            int dia = next[j + 1];
            int d = next[j];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(r, min(dia, d));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }

    return maxi;
}