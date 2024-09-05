int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    int start = -1;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i = 0; i < nums.size(); i++)
    {

        if (sum == 0)
        {
            start = i;
        }
        sum = sum + nums[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    // if(maxi < 0) return 0;
    return nums[ansStart] to nums[ansEnd];
}