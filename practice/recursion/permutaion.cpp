#include <iostream>
#include <vector>
using namespace std;
void solvePer(string str, int i, vector<string> &ans)
{
    if (i >= str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int j = i; j < str.size(); j++)
    {
        swap(str[i], str[j]);
        solvePer(str, i + 1, ans);

        swap(str[i], str[j]);
    }
}
vector<string> per(string &str)
{
    vector<string> ans;
    if (str.size() == 0)
    {
        return ans;
    }

    int i = 0;
    solvePer(str, i, ans);
    return ans;
}
int main()
{
    string str = "abc";
    vector<string> ans = per(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}