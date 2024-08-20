void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // create the adjacency list with the weights
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
    }

    // find the topo sort
    //run -> O(N + M)
    int vis[N] = {0};
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(N);
    for (int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }

    // define the source node
    dist[0] = 0;

    //run -> O(N + M)
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // calculate the dist to each node from the source node
        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dist[node] + w < dist[v])
            {
                dist[v] = dist[node] + w;
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