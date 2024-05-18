#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, int size, vector<vector<int>> maze, vector<vector<int>> visited)
{
    if ((x >= 0 && x < size) && (y >= 0 && y < size) && visited[x][y] == 0 && maze[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solveMaze(vector<vector<int>> maze, int size, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    if (x == size - 1 && y == size - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // down
    int newx = x + 1;
    int newy = y;

    if (isSafe(newx, newy, size, maze, visited))
    {
        path.push_back('D');
        solveMaze(maze, size, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;

    if (isSafe(newx, newy, size, maze, visited))
    {
        path.push_back('U');
        solveMaze(maze, size, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;

    if (isSafe(newx, newy, size, maze, visited))
    {
        path.push_back('L');
        solveMaze(maze, size, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;

    if (isSafe(newx, newy, size, maze, visited))
    {
        path.push_back('R');
        solveMaze(maze, size, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 1;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    vector<string> ans;
    if (maze[0][0] == 0)
    {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = maze;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";

    solveMaze(maze, maze.size(), ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = ratInMaze(maze);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}