I Approach (Optimal Method)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>k)
                st.insert(nums[i]);
            else if(nums[i]<k)
                return -1;
        }

        return st.size();
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.