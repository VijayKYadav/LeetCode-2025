I Approach (Using HashMap + Dynamice Programming + Sorting) (Optimal Method)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

        vector<int> hash(n);
        vector<int> dp(n,0);
        
        int mlen=0;
        int LastIndex=-1;
        sort(nums.begin(),nums.end());
        
        for(int ind=0;ind<n;ind++)
        {
            hash[ind]=ind;
            int len=0;
            for(int prev=0;prev<ind;prev++)
            {
                if(nums[ind]%nums[prev]==0 && len<dp[prev])
                {
                    len=dp[prev];
                    hash[ind]=prev;
                }
            }
            dp[ind]=len+1;
            if(dp[ind]>mlen)
            {
                mlen=dp[ind];
                LastIndex=ind;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[LastIndex]);
        
        while(hash[LastIndex]!=LastIndex)
        {
            LastIndex=hash[LastIndex];
            temp.push_back(nums[LastIndex]);
        }
        
        return temp;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.