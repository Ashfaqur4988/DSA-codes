bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (dfs(adjNode, node, vis, adj) == true)
            {
                return true;
            }
        }
        else if (adjNode != parent)
        {
            return true;
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
            {
                return true;
            }
        }
    }
    return false;
}