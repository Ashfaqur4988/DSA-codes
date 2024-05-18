#include <iostream>
#include <vector>
using namespace std;
void solveSub(vector<char> str, vector<char> output, int i, vector<vector<char>> &ans)
{
    if (i >= str.size())
    {
        ans.push_back(output);
        return;
    }

    solveSub(str, output, i + 1, ans);

    char el = str[i];
    output.push_back(el);
    solveSub(str, output, i + 1, ans);
}
vector<vector<char>> subSeq(vector<char> &str)
{
    vector<vector<char>> ans;
    vector<char> output;
    int i = 0;
    solveSub(str, output, i, ans);
    return ans;
}
int main()
{
    vector<char> str = {'a', 'b', 'c'};
    vector<vector<char>> ans = subSeq(str);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "";
        }
        cout << "}";
    }
    cout << endl;
    return 0;
    return 0;
}