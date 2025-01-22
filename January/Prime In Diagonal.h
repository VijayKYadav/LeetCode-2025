I Approach

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();

        int prime=0;

        for(int i=0;i<n;i++)
        {
            if(solve(nums[i][i]))
            {
                if(nums[i][i]>prime)
                    prime=nums[i][i];
            }

            if(i!=n-1-i)
            {
                if(solve(nums[i][n-1-i]))
                {
                    if(nums[i][n-1-i]>prime)
                        prime=nums[i][n-1-i];
                }
            }

        }

        return prime;
    }

    bool solve(int n)
    {
        if(n==1)
            return false;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }

        return true;
    }
};


Time Complexity: O(n*sqrt(n))
Space Complexity: O(1)
 
where, 'n' is the number of row's in the given square matrix 'nums'.