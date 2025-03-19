I Approach (Using Sliding Window) (Brute-Force Method)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int i;
        for(i=0;i<n-k+1;i++)
        {
            if(nums[i]==0)
            {
                count++;
                for(int j=i;j<k+i;j++)
                {
                    nums[j]=1-nums[j];
                }
            }
        }

        for(;i<n;i++)
        {
            if(nums[i]==0)
                return -1;
        }

        return count;
    }
};

Time Complexity=O(n*k).
Space Complexity=O(1).

Where, 'n' is the size of in a given vector/array 'nums'.

This, solution will give TLE(Time Limit Exceeded).

II Approach (Using PrefixSum)(Optimal Method)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefixSum(n+1,0);
        
        int sum=0;
        int count=0;
        int i;

        for(i=0;i<n-k+1;i++)
        {
            sum+=prefixSum[i];
            if(nums[i]==0)
            {
                if(sum%2==0)
                {
                    count++;
                    prefixSum[i+1]++;
                    prefixSum[i+k]--;
                }
            }
            else
            {
                if(sum%2)
                {
                    count++;
                    prefixSum[i+1]++;
                    prefixSum[i+k]--;
                }
            }
        }

        for(;i<n;i++)
        {
            sum+=prefixSum[i];
            if(nums[i]==0)
            {
                if(sum%2==0)
                    return -1;
            }
            else
            {
                if(sum%2)
                    return -1;
            }
        }

        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of a given vector/array 'nums'.