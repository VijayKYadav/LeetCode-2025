I Approach (Optimal Method)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();

        long long maxD=0;
        long long maxE=0;
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            ans=max(ans,maxD*nums[i]);
            maxD=max(maxD,maxE-nums[i]);
            maxE=max(maxE,(long long)nums[i]);
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where,'n' is the size of a given vector/array 'nums'.