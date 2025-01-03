I-Approach

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixSum(n);
        prefixSum[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            prefixSum[i]+=prefixSum[i-1]+nums[i];
        }

        long long total=prefixSum[n-1];

        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(prefixSum[i]>=total-prefixSum[i])
                count++;
        }

        return count;
    }
};

Time Complexity = O(n);
Space Complexity = O(n);

Where, 'n' is the size of the given array nums.