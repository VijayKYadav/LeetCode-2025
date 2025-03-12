I Approach (Using Sorting-Algorithm) (Optimal Method)

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        bool flag;

        for(int i=0;i<n;i++)
        {
            flag=true;

            if((i>0 && (nums[i-1]==nums[i] || nums[i-1]+1==nums[i])) || (i<n-1 && (nums[i+1]==nums[i] || nums[i+1]-1==nums[i])))
                flag=false;
            
            if(flag)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.