I Approach (Using Sliding-Window) (Optimal Method)

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans=0;
        unordered_map<int,int> mp;
        int j=0;
        int i =0;
        int countP=0;

        while(j<n)
        {
            countP+=mp[nums[j]];
            mp[nums[j]]++;

            while(countP>=k)
            {
                ans+=n-j;
                countP-=(mp[nums[i]]-1);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the size of the given vector/arrray 'nums'.
