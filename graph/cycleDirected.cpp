bool dfs(int node, int vis[], int pathVis[], vector<int> adj[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathVis, adj) == true)
                return true;
        }
        else if (vis[it] == 1 && pathVis[it] == 1)
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, pathVis, adj) == true)
            {
                return true;
            }
        }
    }
    return false;
}