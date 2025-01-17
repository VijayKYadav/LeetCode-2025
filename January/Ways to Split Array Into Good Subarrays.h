I Approach 

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        long long split=1;
        int count=1;
        bool flag=false;
        int MOD=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                split=(split*count)%MOD;
                count=1;
                flag=true;
            }
            else
            {
                if(flag)
                    count++;
            }
        }

        if(flag==false)
            return 0;
        return split;
    }
};

Time Complexity: O(n)
Space Complexity: O(1) 
where, 'n' is the size of the given array 'nums'.