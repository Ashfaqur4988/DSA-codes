#include <iostream>
#include <vector>
using namespace std;
void solvePer(vector<int> num, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= num.size())
    {
        ans.push_back(num);
        return;
    }

    for (int i = index; i < num.size(); i++)
    {
        swap(num[index], num[i]);
        solvePer(num, ans, index + 1);

        // backtracking
        swap(num[index], num[i]);
    }
}
vector<vector<int>> permute(vector<int> &num)
{
    vector<vector<int>> ans;
    if (num.size() == 0)
    {
        return ans;
    }
    int index = 0;
    solvePer(num, ans, index);
    return ans;
}
int main()
{
    vector<int> num = {1, 2, 3};
    vector<vector<int>> ans = permute(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << "";
        }
        cout << "}";
    }
    cout << endl;
    return 0;
}