class data
{
public:
    int val, aPos, index;
    data(int v, int aP, int i)
    {
        val = v;
        aPos = aP;
        index = i;
    }
};

struct myCom
{
    bool operator()(data &d1, data &d2)
    {
        return d1.val > d2.val;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {

        priority_queue<data, vector<data>, myCom> pq;
        // pushing the first position of all the arrays
        for (int i = 0; i < K; i++)
        {
            data d(arr[i][0], i, 0);
            pq.push(d);
        }

        vector<int> ans;
        while (!pq.empty())
        {
            data curr = pq.top();
            pq.pop();
            ans.push_back(curr.val);
            int array = curr.aPos;
            int ind = curr.index;

            if (ind + 1 < arr[array].size())
            {
                data d(arr[array][ind + 1], array, ind + 1);
                pq.push(d);
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}
