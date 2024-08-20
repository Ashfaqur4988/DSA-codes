vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // created adj list
    vector<int> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N, 1e9);
    queue<pair<int, int>> q;

    q.push({src, 0});
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int wt = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (wt + 1 < dist[it])
            {
                dist[it] = wt + 1;
                q.push({it, wt + 1});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }

    return dist;
}