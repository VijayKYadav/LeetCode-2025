I Approach 

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
            return true;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2==1)
            {
                if(nums[i-1]%2==1)
                    return false;

                if(i+1<n && nums[i+1]%2==1)
                    return false;
            }
            else
            {
                if(nums[i-1]%2==0)
                    return false;

                if(i+1<n && nums[i+1]%2==0)
                    return false;
            }
        }

        return true;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the size of the given array 'nums'.