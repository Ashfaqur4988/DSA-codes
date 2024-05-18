#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr, vector<vector<int>> &ans, vector<int> output, int i)
{
    if (i >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(arr, ans, output, i + 1);
    // include
    int element = arr[i];
    output.push_back(element);
    solve(arr, ans, output, i + 1);
}

vector<vector<int>> subset(vector<int> &arr)
{

    vector<vector<int>> ans;
    vector<int> output;
    if (arr.size() == 0)
    {
        return ans;
    }
    int i = 0;
    solve(arr, ans, output, i);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<vector<int>> ans = subset(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "";
        }
        cout << "}";
    }
    return 0;
}