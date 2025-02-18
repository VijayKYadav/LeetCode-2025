I Approach (Optimal Method)

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();

        long long count=1;
        long long ans=0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                count++;
            }
            else
            {
                ans=ans+count*(count+1)/2;
                count=1;
            }
        }
        ans=ans+count*(count+1)/2;

        return ans;
    }
};1

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.