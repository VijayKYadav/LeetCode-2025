I Approach (Brute-Force Method)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int count=0;
        vector<int> g;
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==pivot)
                count++;
            else if(nums[i]>pivot)
            {
                g.push_back(nums[i]);
            }
            else
            {
                nums[ind++]=nums[i];
            }
        }
        
        while(count>0)
        {
            nums[ind++]=pivot;
            count--;
        }

        int len=g.size();
        for(int k=0;k<len;k++)
        {
            nums[ind++]=g[k];
        }

        return nums;


    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where, 'n' is the size of the given vector/array 'nums'.

II Approach (Using Single-Pass) (Optimal Method)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n);
        int iL=0;
        int iH=n-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
                ans[iL++]=nums[i];

            if(nums[n-1-i]>pivot)
                ans[iH--]=nums[n-1-i];
        }
        
        while(iL<=iH)
            ans[iL++]=pivot;
            
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array 'nums'.