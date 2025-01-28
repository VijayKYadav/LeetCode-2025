I Approach

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();

        bool flag=true;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                if(flag)
                {
                    if(i==1)
                        flag=false;
                    else if(i+1==n)
                        flag=false;
                    else    if(nums[i]>nums[i-2] || nums[i+1]>nums[i-1])
                        flag=false;
                    else
                        return false;
                }
                else
                    return false;
            }
        }

        return true;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the size of the given array 'nums'.