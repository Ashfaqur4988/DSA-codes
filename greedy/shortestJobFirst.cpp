long long solve(vector<int> &bt)
{
    // code here
    int n = bt.size();
    sort(bt.begin(), bt.end());

    int t = 0;
    int wt = 0;
    for (int i = 0; i < n; i++)
    {
        wt = wt + t;
        t = t + bt[i];
    }
    return wt / n;
}