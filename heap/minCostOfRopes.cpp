long long minCost(long long arr[], long long n)
{
    // Your code here
    long long cost = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);
    while (pq.size() != 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        cost = cost + (a + b);
        pq.push(a + b);
    }
    return cost;
}