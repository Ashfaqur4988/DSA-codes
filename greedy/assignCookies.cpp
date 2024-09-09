int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();
    int m = s.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;
    int j = 0;
    while (j < m && i < n)
    {
        if (g[i] <= s[j])
        {
            i++;
        }
        j++;
    }
    return i;
}