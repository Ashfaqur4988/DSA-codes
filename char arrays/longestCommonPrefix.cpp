string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string a = strs[0];
    string b = strs[n - 1];
    string ans = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
        else
        {
            ans.push_back(a[i]);
        }
    }
    return ans;
}