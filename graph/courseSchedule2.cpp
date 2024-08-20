vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
    // code here
    vector<int> adj[n];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    int indeg[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (ans.size() == n)
        return ans;

    return {};