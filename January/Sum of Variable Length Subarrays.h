I Approach (Using Prefix Sum)

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++)
            prefixSum[i]=nums[i]+prefixSum[i-1];
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int start=max(0,i-nums[i]);
            sum+=prefixSum[i]-(start>0?prefixSum[start-1]:0);
        }

        return sum;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the size of the given array 'nums'.