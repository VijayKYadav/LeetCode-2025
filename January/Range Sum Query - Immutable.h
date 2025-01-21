I Approach (Using Prefix Sum)

class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];
        prefixSum.push_back(s);
        for(int i=1;i<n;i++)
        {
            s+=nums[i];
            prefixSum.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right]-(left>0?prefixSum[left-1]:0);
    }
};


Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the size of the given array 'nums'.