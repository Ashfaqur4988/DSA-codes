#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // adjacency matrix
    int n, m;
    cin >> n >> m;
    // graph (adjacency matrix)
    int adj[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // graph (adjacency matrix)

    // graph list store
    vector<int> vec[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    // graph list store

    // weighted graph list store
    vector<int> weighted[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // only one link
        weighted[u].push_back(v);
    }
    // weighted graph list store

    return 0;
}