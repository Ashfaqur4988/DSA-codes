int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();
    int maxStrghtSum = INT_MIN;
    int tempMaxSum = 0;
    int arrSum = 0;
    int minStrghtSum = INT_MAX;
    int tempMinSum = 0;

    for (int i = 0; i < n; i++)
    {
        arrSum = arrSum + nums[i];

        tempMaxSum = tempMaxSum + nums[i];
        maxStrghtSum = max(maxStrghtSum, tempMaxSum);
        if (tempMaxSum < 0)
            tempMaxSum = 0;

        tempMinSum = tempMinSum + nums[i];
        minStrghtSum = min(minStrghtSum, tempMinSum);
        if (tempMinSum > 0)
            tempMinSum = 0;
    }

    if (arrSum == minStrghtSum)
        return maxStrghtSum;

    return max(maxStrghtSum, (arrSum - minStrghtSum));
}