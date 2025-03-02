I Approach (Using Ordered_Map of 'Key' of Integer Data-type and 'Value' of Integer Data-type)

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }

        int m=operations.size();

        for(int i=0;i<m;i++)
        {
            int ind=mp[operations[i][0]];
            nums[ind]=operations[i][1];
            mp.erase(operations[i][0]);
            mp[operations[i][1]]=ind;
        }
        return nums;
    }
};

Time Complexity=O(n+m).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums' and
'm' is the size of the given 2D-vector 'operations'.