I Approach (Using Single Pass)

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int LMS=1;

        int countI=1;
        int countD=1;

        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                countD++;
                LMS=max(LMS,countI);
                countI=1;
            }
            else if(nums[i-1]<nums[i])
            {
                countI++;
                LMS=max(LMS,countD);
                countD=1;
            }
            else
            {
                LMS=max(LMS,countI);
                LMS=max(LMS,countD);
                countI=1;
                countD=1;
            }

        }

        LMS=max(LMS,countI);
        LMS=max(LMS,countD);

        return LMS;
    }
};

Time Complexity=O(n)
Space Complexity=O(1)

Where, 'n' is the size of the given array 'nums'.

