I Approach (Using Dynamice Programming) (Optimal Method)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
        }
        if(sum%2!=0)
            return false;
        else
            return SumOfSubset(nums,sum/2,n);
    }
    bool SumOfSubset(vector<int> &arr ,int SUM ,int N)
    { 
        vector<vector<bool>> DP(N+1 ,vector<bool>(SUM+1));
        for(int i=0;i<N+1;i++)
            DP[i][0]=true;
        for(int j=1;j<SUM+1;j++)
        {
            DP[0][j]=false;
        }
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<SUM+1;j++)
            {
                if(arr[i-1]<=j)
                    DP[i][j]= DP[i-1][j-arr[i-1]] || DP[i-1][j];
                else
                    DP[i][j]=DP[i-1][j];
            }
        }
        return DP[N][SUM];
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.