#include <bits/stdc++.h>
long long int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int p = nums[i];
        if (i > 1)
            p += prev2;

        long long int np = 0 + prev;

        long long int curr = max(p, np);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    // temp array, remove the first in one, last in another
    vector<int> temp1, temp2;
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }
    long long int ans = max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    return ans;
}