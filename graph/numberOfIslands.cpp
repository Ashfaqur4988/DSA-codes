void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int drow = -1; drow <= 1; drow++)
        {
            for (int dcol = -1; dcol <= 1; dcol++)
            {
                int nrow = drow + row;
                int ncol = dcol + col;

                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                cnt++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return cnt;
}