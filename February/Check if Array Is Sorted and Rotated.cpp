I Approach

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return true;

        int count=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
                count++;
        }

        if(nums[n-1]>nums[0])
            count++;

        if(count<=1)
            return true;
        return false;
    }
};

Time Complexity=O(n)
Space Complexity=O(1)

Where, 'n' is the size of the given array 'nums'.

