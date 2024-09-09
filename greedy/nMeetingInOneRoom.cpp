class Solution
{
public:
    struct meeting
    {
        int start;
        int end;
        int pos;
    };
    bool static comp(struct meeting m1, struct meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[])
    {
        // Your code here

        struct meeting meet[n];

        for (int i = 0; i < n; i++)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        sort(meet, meet + n, comp);

        vector<int> ans;
        int freeTime = meet[0].end;
        ans.push_back(meet[0].pos);

        for (int i = 0; i < n; i++)
        {
            if (meet[i].start > freeTime)
            {
                freeTime = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }

        return ans.size();
    }
};