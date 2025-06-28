I Approach (Optimal Method) (Using Sorting)

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> sol;

        for(int i=0;i<n;i++)
        {
            sol.push_back({nums[i],i});
        }

        sort(sol.begin(),sol.end(),greater<pair<int,int>>());

        vector<int> ind;
        for(int i=0;i<k;i++)
        {
            ind.push_back(sol[i].second);
        }

        sort(ind.begin(),ind.end());
        vector<int> ans;

        for(int i=0;i<k;i++)
        {
            ans.push_back(nums[ind[i]]);
        }

        return ans;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where,'n' is the size of given vector/array 'nums'.