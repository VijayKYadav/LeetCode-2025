I Approach (Using BFS)

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxF=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                    maxF=max(maxF,bfs(i,j,n,m,grid));
            }
        }

        return maxF;
    }

    int bfs(int row, int col, int n, int m, vector<vector<int>> &grid)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        int fish=grid[row][col];
        grid[row][col]=-1;

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            if(r>=0 && r<n && c-1>=0 && c-1<m && grid[r][c-1]>0)
	        {
	           fish+=grid[r][c-1];
               grid[r][c-1]=-1;
	           q.push({r,c-1});
	        }
	        
	        if(r>=0 && r<n && c+1>=0 && c+1<m&& grid[r][c+1]>0)
	        {
	           fish+=grid[r][c+1];
               grid[r][c+1]=-1;
	           q.push({r,c+1});
	        }
	        
	        if(r-1>=0 && r-1<n && c>=0 && c<m && grid[r-1][c]>0)
	        {
	           fish+=grid[r-1][c];
               grid[r-1][c]=-1;
	           q.push({r-1,c});
	        }
	        
	        if(r+1>=0 && r+1<n && c>=0 && c<m && grid[r+1][c]>0)
	        {
	           fish+=grid[r+1][c];
               grid[r+1][c]=-1;
	           q.push({r+1,c});
	        }
        }

        return fish;
    }
};

Time Complexity: O(n*m)
Space Complexity: O(1)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given matrix 'grid'.