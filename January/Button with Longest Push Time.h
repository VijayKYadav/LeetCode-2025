I-Approach

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n=events.size();
        int index=events[0][0];
        int time=events[0][1];

        for(int i=1;i<n;i++)
        {
            int d=events[i][1]-events[i-1][1];
            if(d>time)
            {
                time=d;
                index=events[i][0];
            }
            else if(d==time)
                index=min(index,events[i][0]);
        }

        return index;
    }
};

Time Complexity = O(n);
Space Complexity = O(1);

Where, 'n' is the size of given array 'events'.