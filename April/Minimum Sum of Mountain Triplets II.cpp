I Approach (Optimal Method)

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = nums[0];
        for(int i=1; i<n; i++)
            left[i] = min(left[i - 1], nums[i]);
        
        right[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            right[i] = min(right[i+1], nums[i]);
        
        int ans = INT_MAX;
        
        for(int i=1; i<n-1; i++)
        {
            if(nums[i] > left[i-1] && nums[i] > right[i+1])
            {
                ans = min(ans, nums[i] + left[i-1] + right[i+1]);
            }
                
        }

        if(ans==INT_MAX)
            return -1;
    
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.