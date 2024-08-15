bool isCyclic(int V, vector<int> adj[])
{
    // code here
    int indegree[V] = {0};
    queue<int> q;
    int cnt = 0;

    // fill the in degrees
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (cnt < V)
        return true;

    return false;
}