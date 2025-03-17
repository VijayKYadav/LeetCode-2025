I Approach (Using HashMap or Unordered_Map)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        for(auto it:mp)
        {
            if(it.second%2)
                return false;
        }

        return true;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of in a given vector/array 'nums'.