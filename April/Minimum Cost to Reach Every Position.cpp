I Approach (Brute-Force Method)

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();

        vector<int> ans;
        int maxC=101;

        for(int i=0;i<n;i++)
        {
            if(cost[i]<=maxC)
            {
                ans.push_back(cost[i]);
                maxC=cost[i];
            }
            else
                ans.push_back(maxC);
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where,'n' is the size of a given vector/array 'cost'.