// with extra space
void permut(vector<int> &output, vector<vector<int>> &ans, int map[], vector<int> &nums)
{
    if (output.size() == nums.size())
    {
        ans.push_back(output);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!map[i])
        {
            output.push_back(nums[i]);
            map[i] = 1;
            permut(output, ans, map, nums);
            map[i] = 0;
            output.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> output;
    vector<vector<int>> ans;
    int map[nums.size()];
    for (int i = 0; i < nums.size(); i++)
    {
        map[i] = 0;
    }
    permut(output, ans, map, nums);
    return ans;
}