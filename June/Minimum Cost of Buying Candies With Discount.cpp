I Approach (Optimal Method) (Using Sorting)

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();

        int minCost=0;

        sort(cost.begin(),cost.end(),greater());

        for(int i=0;i<n;i++)
        {
            minCost+=cost[i++];
            if(i<n)
                minCost+=cost[i++];
        }

        return minCost;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(1).

Where,'n' is the size of given vector/array 'cost'.