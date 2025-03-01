I Approach (Brute-Force Method)

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                int j=i;
                while(j+1<n && nums[j+1]!=0)
                {
                    swap(nums[j],nums[j+1]);
                    j++;
                }
            }
        }

        return nums;
    }
};

Time Complexity=O(n)+O(n*n)~O(n*n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.