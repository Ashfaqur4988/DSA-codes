void findCom(int ind, vector<int> arr, int target, vector<vector<int>> &ans, vector<int> &output)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(output);
        }
        return;
    }

    if (arr[ind] <= target)
    {
        output.push_back(arr[ind]);
        findCom(ind, arr, target - arr[ind], ans, output);
        output.pop_back();
    }
    findCom(ind + 1, arr, target, ans, output);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    findCom(0, candidates, target, ans, output);
    return ans;
}