/*
A k-diff pair is an integer pair (nums[i], nums[j]), 
where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k which implies (nums[i]=nums[j]+k) or (nums[i]=nums[j]-k)
*/

I Approach (Using HashMap)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        int ans=0;

        for(auto it:mp)
        {
            if(k==0)
            {
                if(it.second>1)
                    ans++;
            }
            else if(mp.find(it.first+k)!=mp.end()) // nums[i]=nums[j]+k
                ans++;
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.

II Approach (Using HashMap)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        int ans=0;

        for(auto it:mp)
        {
            if(k==0)
            {
                if(it.second>1)
                    ans++;
            }
            else if(mp.find(it.first-k)!=mp.end()) // nums[i]=nums[j]-k
                ans++;
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.

