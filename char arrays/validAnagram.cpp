bool isAnagram(string s, string t)
{
    unordered_map<char, int> st;
    for (char x : s)
    {
        st[x]++;
    }

    for (char x : t)
    {
        if (st.find(x) == st.end())
        {
            return false;
        }
        st[x]--;
    }

    for (auto &x : st)
    {
        if (x.second != 0)
        {
            return false;
        }
    }
    return true;
}