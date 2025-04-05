I Approach (Using Recursion) (Brute-Force Method)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int xorT=0;
        int sum=0;
        solve(0,n,sum,xorT,nums);
        return xorT;
    }

    void solve(int ind,int n, int sum, int &xorT ,vector<int> &nums)
    {
        if(ind==n)
        {
            xorT+=sum;
            return ;
        }

        solve(ind+1,n,sum^nums[ind],xorT,nums);
        solve(ind+1,n,sum,xorT,nums);
    }
};

Time Complexity=O(2^n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'nums'.


II Approach (Using Bit-Manipulation) (Optimal Method)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int xorT=0;

        for(int ele:nums)
        {
            xorT|=ele;
        }

        return xorT<<(n-1);   
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where,'n' is the size of a given vector/array 'nums'.
