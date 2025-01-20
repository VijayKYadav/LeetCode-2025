I Approach

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(i==j || j==n-1-i)
                 {
                    if(grid[i][j]==0)
                        return false;
                 }
                 else if(grid[i][j])
                    return false;
            }
        }

        return true;
    }
};

Time Complexity: O(n*n)
Space Complexity: O(1)
 
where, 'n' is the number of row's and 
column's in the given square matrix 'grid'.