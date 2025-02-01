I Approach (Using PrefixSum)

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefixSum(n,0);

        for(int i=1;i<n;i++)
        {
            int sum=1;

            if(nums[i]%2==1)
            {
                if(nums[i-1]%2==1)
                    sum=0;

                if(i+1<n && nums[i+1]%2==1)
                    sum=0;
                
                prefixSum[i]=sum+prefixSum[i-1];
            }
            else
            {
                if(nums[i-1]%2==0)
                    sum=0;

                if(i+1<n && nums[i+1]%2==0)
                    sum=0;
                
                prefixSum[i]=sum+prefixSum[i-1];
            }
        }

        int len=queries.size();
        vector<bool> ans(len,false);

        for(int i=0;i<len;i++)
        {
            if(queries[i][1]==queries[i][0])
                ans[i]=true;
            else
            {
                int dif1=queries[i][1]-queries[i][0];
                int dif2=prefixSum[queries[i][1]]-prefixSum[queries[i][0]];
                if(queries[i][1]+1<n && (nums[queries[i][1]]%2!=nums[queries[i][1]-1]%2 && nums[queries[i][1]]%2==nums[queries[i][1]+1]%2))
                    dif2++;

                if(dif1==dif2)
                    ans[i]=true;
            }
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the size of the given array 'nums'.