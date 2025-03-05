I Approach (Brute-Force Method)

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();

        int minE=INT_MAX;
        int maxE=INT_MIN;

        for(int i=0;i<n;i++)
        {
            minE=min(minE,nums[i]);
            maxE=max(maxE,nums[i]);
        }

        return __gcd(minE,maxE);
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.