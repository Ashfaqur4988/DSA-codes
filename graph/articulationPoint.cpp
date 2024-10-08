class Solution
{
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        int child = 0; // logic for strating point
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++; // logic for strating point
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        // logic for strating point
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<int> mark(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
    }
};