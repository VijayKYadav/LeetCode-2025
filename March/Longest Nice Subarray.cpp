I Approach (Using Sliding-Window + Bit-Wise Operation)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int start = 0;
        int end = 0;
        int bitmask = 0;
        int ans = 0;

        while(end<n)
        {
            while((bitmask & nums[end])!=0)
            {
                bitmask^=nums[start++];
            }
           
            bitmask |= nums[end];
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of in a given vector/array 'nums'.