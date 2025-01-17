I Approach 

class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int minV=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int sumD=solve(nums[i]);
            minV=min(minV,sumD);
        }

        return minV;
    }

    int solve(int n)
    {
        int sum=0;

        while(n)
        {
            int r=n%10;
            sum+=r;
            n=n/10;
        }

        return sum;
    }
};

Time Complexity: O(n*log(m))
Space Complexity: O(1) 
where, 'n' is the size of the given array 'nums' and 
'm' is the largest integer in the given array 'nums'.