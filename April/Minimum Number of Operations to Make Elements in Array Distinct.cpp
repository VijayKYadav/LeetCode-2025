I Approach (Using Unordered_Set) (Optimal Method)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.find(nums[i])!=st.end())
                return i/3+1;
            else
                st.insert(nums[i]);
        }

        return 0;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.