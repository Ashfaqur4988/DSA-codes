int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq(stones.begin(), stones.end());

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        if (a != b)
        {
            pq.push(a - b);
        }
    }
    if (pq.empty())
        return 0;
    return pq.top();
}