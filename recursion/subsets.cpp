#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(arr, output, index + 1, ans);
    // include
    int element = arr[index];
    output.push_back(element);
    solve(arr, output, index + 1, ans);
}

vector<vector<int>> subset(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr, output, index, ans);
    return ans;
}

int main()
{
    int n = 3;
    vector<int> arr = {3, 2, 1};
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
    cout << endl;
    return 0;
}