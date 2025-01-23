I Approach

class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        sum.resize(n,vector<int>(m,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum[j][i]=matrix[j][i]+(j>0?sum[j-1][i]:0);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                sum[i][j]=sum[i][j]+sum[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
            return sum[row2][col2]-(col1>0?sum[row2][col1-1]:0)-(row1>0?sum[row1-1][col2]:0)+((row1>0 && col1)>0?sum[row1-1][col1-1]:0);
    }
};


Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given square matrix 'matrix'.