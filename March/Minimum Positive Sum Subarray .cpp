I Approach (Using Sliding-Window) (Optimal Method)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;

        for(int t=l;t<=r;t++)
        {
            int sum=solve(nums,t);
            if(sum>0)
                ans=min(ans,sum);
            
        }

        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }

    int solve(vector<int> &nums, int k)
    {
        int n=nums.size();

        int sumL=0;
        int sumG=INT_MAX;

        int i=0;
        int j=0;

        while(j<n)
        {
            sumL+=nums[j];

            if(j-i+1==k)
            {
                if(sumL>0)
                    sumG=min(sumG,sumL);
                sumL-=nums[i];
                i++;
            }
            j++;
        }

        return sumG;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(1).

Where, 'n' is the size of the given array 'nums'.