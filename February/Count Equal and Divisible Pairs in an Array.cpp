I Approach (Using Brute-Force/Naive Method)

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    if((i*j)%k==0)
                        count++;
                }
            }
        }

        return count;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.

