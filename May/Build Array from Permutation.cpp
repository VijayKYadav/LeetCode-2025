I Approach (Optimal Method) (Using Unordered_Map)

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[i]=nums[i];
        
        vector<int> ans(n);

        for(int i=0;i<n;i++)
            ans[i]=nums[mp[i]];

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of the given vector/arrray 'nums'.
