I Approach (Using PrefixSum) (Optimal Method)

class Solution {
  public:
    long long countEvenSum(vector<int>& arr) {
        int n=arr.size();
        
        long long prefixSum=0;
        long long oddC=0;
        long long evenC=1;
        
        long long count=0;
        
        for(int i=0;i<n;i++)
        {
            prefixSum+=arr[i];
            
            if(prefixSum%2)
            {
                count+=oddC;
                oddC++;
            }
            else
            {
                count+=evenC;
                evenC++;
            }
            
        }
        
        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of given vector/array 'arr';