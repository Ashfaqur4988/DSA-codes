int n = nums.size();
int j = 0;
int l = 0;
int r = 0;
while (r < n - 1)
{
    j++;
    int far = r + 1;
    for (int i = l; i <= r; i++)
    {
        if (i + nums[i] >= n - 1)
            return j;

        far = max(far, i + nums[i]);
    }
    l = r + 1;
    r = far;
}
return j;