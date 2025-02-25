I Approach (Using PrefixSum) (Optimal Method)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();

        int count=0;
        int prefixSum=0;
        int oddC=0;
        int evenC=1;
        int MOD=1e9+7;

        for(int i=0;i<n;i++)
        {
            prefixSum+=arr[i];

            if(prefixSum%2)
            {
                count+=evenC;
                oddC++;
            }
            else
            {
                count+=oddC;
                evenC++;
            }
            count=count%MOD;
        }

        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the size of given vector/array 'arr';