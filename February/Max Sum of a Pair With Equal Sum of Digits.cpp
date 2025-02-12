I Approach (Using Sorting Method)

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int maxS=-1;
        vector<pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            mp.push_back({digitSum(nums[i]),nums[i]});
        }

        sort(mp.begin(),mp.end());
        
        for(int i=1;i<n;i++)
        {
            if(mp[i].first==mp[i-1].first)
            {
                maxS=max(maxS,mp[i].second+mp[i-1].second);
            }
        }

        return maxS;
    }

    int digitSum(int n)
    {
        int sum=0;

        while(n>0)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.