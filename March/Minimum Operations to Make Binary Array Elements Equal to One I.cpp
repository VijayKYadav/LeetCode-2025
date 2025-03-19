I Approach (Using Sliding Window) (Optimal Method)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=0;
        while(i<n-2)
        {
            if(nums[i]==0)
            {
                nums[i]=1-nums[i];
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];

                count++;
            }
            i++;
        }

        if(nums[i]==0 || nums[i+1]==0)
            return -1;
        
        return count;
    }
};

Time Complexity=O(n*3)~O(n).
Space Complexity=O(1).

Where, 'n' is the size of a given vector/array 'nums'.

