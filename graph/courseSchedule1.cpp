bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vector<int> adj[N];
    for (auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

    int indeg[N] = {0};
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    for (int i = 0; i < N; i++)
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

    if (ans.size() == N)
        return true;

    return false;
}