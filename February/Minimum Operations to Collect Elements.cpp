I Approach (Using Unordered_Set)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();

        int minOperation=0;
        unordered_set<int> st;

        for(int i=n-1;i>=0;i--)
        {
            minOperation++;
            if(nums[i]<=k)
                st.insert(nums[i]);
            
            if(st.size()==k)
                break;
        }

        return minOperation;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.