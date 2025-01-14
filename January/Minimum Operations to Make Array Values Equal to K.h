I Approach

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int minV=INT_MAX;
        vector<int> mp(101,0);

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            minV=min(minV,nums[i]);
        }

        if(minV<k)
            return -1;
        
        int count=0;
        for(int i=100;i>0;i--)
        {
            if(i>k)
            {
                if(mp[i]>0)
                    count++;
            }
            else if(i==k)
                break;
        }

        return count;
    }
};

Time Complexity: O(n)
Space Complexity: O(101)~O(1) 
where, 'n' is the size of the given vector 'nums'.