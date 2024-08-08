void subsets(int ind, vector<int> &output, vector<vector<int>> &ans, vector<int> nums)
{
    // base case
    ans.push_back(output);

    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        output.push_back(nums[i]);
        subsets(i + 1, output, ans, nums);
        output.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> output;
    subsets(0, output, ans, nums);
    return ans;
}