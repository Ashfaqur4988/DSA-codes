vector<int> topo(int K, vector<int> adj[])
{
    int in[K] = {0};
    queue<int> q;
    vector<int> ansTopo;
    for (int i = 0; i < K; i++)
    {
        for (auto it : adj[i])
        {
            in[it]++;
        }
    }

    for (int i = 0; i < K; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ansTopo.push_back(node);
        for (auto it : adj[node])
        {
            in[it]--;

            if (in[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ansTopo;
}

string findOrder(string dict[], int N, int K)
{
    // adj list creation
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    // vector to store the order from the topo sort BFS (kahn's algorithm)
    vector<int> ansTopo = topo(K, adj);

    // string to store ans
    string ans = "";

    // pushing in the string
    for (auto it : ansTopo)
    {
        ans = ans + char(it + 'a');
    }

    return ans;
}