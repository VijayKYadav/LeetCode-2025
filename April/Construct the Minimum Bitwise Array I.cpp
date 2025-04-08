I Approach (Brute-Force Method)

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            int j;
            for(j=1;j<nums[i];j++)
            {
                if((j|j+1)==nums[i])
                {
                    ans.push_back(j);
                    break;
                }
            }

            if(j==nums[i])
                ans.push_back(-1);
        }
        return ans;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(1).

Where,'n' is the size of a given vector/array 'nums'.