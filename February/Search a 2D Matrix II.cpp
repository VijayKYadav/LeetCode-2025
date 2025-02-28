I Approach (Using Binary Search) (Most Optimal Method)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=0;
        int j=n-1;

        while(i<m && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else
            {
                if(matrix[i][j]>target)
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }
};

Time Complexity=O(log(n+m)).
Space Complexity=O(1).

Where, 'n' is the number of the column's in a given 2D-array 'matrix' and
'm' is the number of the row's in a given 2D-array 'matrix'.