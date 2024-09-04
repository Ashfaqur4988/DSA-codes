// memoization
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];
    int t = 0;
    int nt = f(ind - 1, target, arr, dp);
    if (arr[ind] <= target)
        t = f(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (t + nt);
}

int perfectSum(vector<int> &arr, int n, int sum)
{
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n - 1, sum, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int totalSum = 0;
    for (int i = 0; i < arr.size(); i++)
        totalSum += arr[i];
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return 0;
    return perfectSum(arr, arr.size(), (totalSum - d) / 2);
}
int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    return countPartitions(n, target, arr);
}
