I Approach (Using Prefix and Sufix Sum)

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        if(n==1)
            return 0;
        
        long long sufixSum=0;
        long long prefixSum=0;

        for(int i=n-1;i>=0;i--)
            sufixSum+=grid[0][i];

        long long sumR2=LLONG_MAX;

        for(int i=0;i<n;i++)
        {
            sufixSum-=grid[0][i];
            sumR2=min(sumR2,max(prefixSum,sufixSum));
            prefixSum+=grid[1][i];
        }
        return sumR2;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the number of column's in the given 2D-matrix 'grid'.