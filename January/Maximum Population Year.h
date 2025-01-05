I-Approach (Using PrefixSum)

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();

        vector<int> dp(101,0);

        for(int i=0;i<n;i++)
        {
            dp[logs[i][0]-1950]++;
            dp[logs[i][1]-1950]--;
        }

        int ans;
        int sum=dp[0];

        for(int i=1;i<101;i++)
        {
            dp[i]=dp[i]+dp[i-1];
            if(dp[i]>sum)
            {
                ans=i;
                sum=dp[i];
            }
        }

        return ans+1950;
    }
};

Time Complexity = O(n);
Space Complexity = O(1);
Where, n is th size of the given array logs.

