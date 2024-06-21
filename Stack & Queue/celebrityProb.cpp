int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        s.push(i);
    }

    int f, sc;

    while (s.size() > 1)
    {
        f = s.top();
        s.pop();
        sc = s.top();
        s.pop();

        if (M[f][sc] && !M[sc][f])
        {
            s.push(sc);
        }
        else if (!M[f][sc] && M[sc][f])
        {
            s.push(f);
        }
    }

    if (s.empty())
    {
        return -1;
    }

    int num = s.top();

    int row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        row = row + M[num][i];
        col = col + M[i][num];
    }

    return row == 0 && col == n - 1 ? num : -1;
}