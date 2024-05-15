#include <iostream>
#include <vector>
using namespace std;

void solveSeq(vector<char> str, vector<char> output, int i, vector<vector<char>> &ans)
{
    // base case
    if (i >= str.size())
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solveSeq(str, output, i + 1, ans);
    // include
    char element = str[i];
    output.push_back(element);
    solveSeq(str, output, i + 1, ans);
}

vector<vector<char>> subsequence(vector<char> &str)
{
    vector<vector<char>> ans;
    vector<char> output;
    int i = 0;
    solveSeq(str, output, i, ans);
    return ans;
}
int main()
{
    vector<char> str = {'a', 'b', 'c'};
    vector<vector<char>> ans = subsequence(str);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "}";
    }
    cout << endl;
    return 0;
}