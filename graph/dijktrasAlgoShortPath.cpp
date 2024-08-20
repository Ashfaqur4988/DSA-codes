vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (wt + w < dist[v])
            {
                dist[v] = wt + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}