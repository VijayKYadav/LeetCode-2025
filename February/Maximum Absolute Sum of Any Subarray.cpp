I Approach (Using Kadane's Algorithm) (Optimal Method)

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int sumM=0;
        int minS=0;

        for(int i=0;i<n;i++)
        {
            sumM+=nums[i];
            minS+=nums[i];

            maxSum=max(maxSum,sumM);
            minSum=min(minSum,minS);
			
            if(sumM<0)
                sumM=0;

            if(minS>0)
                minS=0;
        }

        return max(maxSum,abs(minSum));
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of given vector/array 'nums';