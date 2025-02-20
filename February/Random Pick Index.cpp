I Approach (Using Unordered_Map of 'Key' is of Integer Data_types and 'Value' is queue of Integer Data_types)

class Solution {
private:
    unordered_map<int,queue<int>> mp;
public:
    Solution(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push(i);
        }
    }
    
    int pick(int target) {
        int ind=mp[target].front();
        mp[target].pop();
        mp[target].push(ind);

        return ind;
    }
};

Time Complexity=O(1) for pick Operation .
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.