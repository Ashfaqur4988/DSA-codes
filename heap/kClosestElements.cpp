vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> pq;
    for (auto el : arr)
    {
        pq.push(make_pair(abs(x - el), el));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        ans.push_back(temp.second);
    }
    sort(ans.begin(), ans.end());
    return ans;
}