I Approach (Brute-Force Method)

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();

        long long t=INT_MIN;

        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if((long long)(nums[i]-nums[j])*nums[k]>t)
                        t=(long long)(nums[i]-nums[j])*nums[k];
                }
            }
        }

        if(t<0)
            return 0;

        return t;
    }
};

Time Complexity=O(n*n*n).
Space Complexity=O(1).

Where,'n' is the size of a given vector/array 'nums'.