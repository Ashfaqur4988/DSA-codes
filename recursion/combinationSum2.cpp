void combo(int ind, int target, vector<int> &output, vector<vector<int>> &ans, vector<int> arr)
{
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        // if repeated element
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        // if target in lesss than element
        if (arr[i] > target)
            break;

        output.push_back(arr[i]);
        combo(i + 1, target - arr[i], output, ans, arr);
        output.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> output;
    combo(0, target, output, ans, candidates);
    return ans;
}