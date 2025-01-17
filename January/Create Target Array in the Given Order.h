I Approach 

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();

        vector<int> target(n);

        for(int i=0;i<n;i++)
        {
            if(index[i]==i)
                target[i]=nums[i];
            else
            {
                for(int j=i;j>index[i];j--)
                    target[j]=target[j-1];
                
                target[index[i]]=nums[i];
            }
        }

        return target;
    }
};

Time Complexity: O(n*n)
Space Complexity: O(1) 
where, 'n' is the size of the given array 'nums'.