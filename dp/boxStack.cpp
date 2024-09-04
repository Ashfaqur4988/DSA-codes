bool check(vector<int> base, vector<int> newBox)
{
    if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        return true;
    else
        return false;
}

int longestSubsequence(int n, vector<vector<int>> &a)
{
    // your code here
    vector<int> prevRow(n + 1, 0);
    vector<int> currRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {

            int nt = 0 + currRow[prev + 1];

            int t = 0;
            if (prev == -1 || check(a[curr], a[prev]))
            {
                t = a[curr][2] + currRow[curr + 1];
            }

            prevRow[prev + 1] = max(t, nt);
        }
        currRow = prevRow;
    }
    return currRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    sort(cuboids.begin(), cuboids.end());

    return longestSubsequence(cuboids.size(), cuboids);
}