bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxInd = 0;
    for (int i = 0; i < n; i++)
    {

        if (maxInd < i)
        {
            return false;
        }

        maxInd = max(i + nums[i], maxInd);
    }
    return true;
}