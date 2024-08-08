void getAns(int i, vector<int> arr, int sum, vector<int> &ans)
{
    if (i >= arr.size())
    {
        ans.push_back(sum);
        return;
    }

    // pick
    sum = sum + arr[i];
    getAns(i + 1, arr, sum, ans);
    sum = sum - arr[i];

    // not pick
    getAns(i + 1, arr, sum, ans);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    // Write Your Code here
    int sum = 0;
    vector<int> ans;
    getAns(0, arr, sum, ans);
    return ans;
}