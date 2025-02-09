I Approach (Using HashMap)

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        vector<int> dif(n);
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            dif[i]=i-nums[i];
            mp[dif[i]]++;
        }
        long long sum=0;
        long long total=n*(n-1)/2;

        for(auto it:mp)
        {
            if(it.second>1)
            {
                long long t = it.second;
                t=t*(t-1)/2;
                sum+=t;
            }
        }

        return total-sum;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.

