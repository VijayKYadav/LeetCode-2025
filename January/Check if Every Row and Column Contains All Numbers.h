I Approach

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();

        unordered_set<int> row;
        unordered_set<int> col;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                row.insert(matrix[i][j]);
                col.insert(matrix[j][i]);
            }
            if(row.size()!=n || col.size()!=n)
                    return false;
                
            row.clear();
            col.clear();
        }

        return true;
    }
};

Time Complexity: O(n*n)
Space Complexity: O(n)
 
where, 'n' is the number of row's and 
column's in the given square matrix 'mat'.