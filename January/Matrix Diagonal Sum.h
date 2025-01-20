I Approach

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();

        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i]+mat[n-1-i][i];
        }

        if(n%2)
            sum-=mat[n/2][n/2];
        
        return sum;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
 
where, 'n' is the number of row's and 
column's in the given square matrix 'mat'.