I Approach (Using PrefixSum)

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<long long>> sum(n,vector<long long>(m,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum[j][i]=grid[j][i]+(j>0?sum[j-1][i]:0);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                sum[i][j]=sum[i][j]+sum[i][j-1];
            }
        }

        int r=n-2;
        int c=m-2;

        long long maxSum=LONG_LONG_MIN;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                long long s=sum[i+2][j+2]-(j>0?sum[i+2][j-1]:0)-(i>0?sum[i-1][j+2]:0)+((i>0 && j>0)?sum[i-1][j-1]:0);
                long long d=grid[i+1][j]+grid[i+1][j+2];

                maxSum=max(maxSum,s-d);
            }
        }

        return maxSum;
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in a given matrix 'grid'.