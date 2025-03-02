I Approach (Using BFS)

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        bool flag=true;
        int flip=2*n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if(flag)
                    {
                        BFS(i,j,n,grid);
                        flag=false;
                    }
                    else
                    {
                        int d=2*n;
                        vector<vector<bool>> vi(n,vector<bool>(n,false));
                        if((i-1>=0 && grid[i-1][j]==0) || (i+1<n && grid[i+1][j]==0) || (j-1>=0 && grid[i][j-1]==0) || (j+1<n && grid[i][j+1]==0))
                        {
                            d=solve(i,j,n,grid,vi);
                        }
                        
                        flip=min(flip,d);
                    }
                }
            }
        }
        return flip;
    }

    int solve(int row, int col, int n, vector<vector<int>> &grid, vector<vector<bool>> vi)
    {
        queue<pair<pair<int,int>,int>> q;
        q.push({{row,col},0});

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();

            int r=p.first.first;
            int c=p.first.second;
            int d=p.second;

            if(c+1<n)
            {
                if(grid[r][c+1]==0 )
                {
                    if(vi[r][c+1]==false)
                    {
                        q.push({{r,c+1},d+1});
                        vi[r][c+1]=true;
                    }
                }
                else if(grid[r][c+1]==-1)
                    return d;
            }

            if(c-1>=0)
            {
                if(grid[r][c-1]==0)
                {
                    if(vi[r][c-1]==false)
                    {
                        q.push({{r,c-1},d+1});
                        vi[r][c-1]=true;
                    }
                }
                else if(grid[r][c-1]==-1)
                    return d;
            }

            if(r+1<n)
            {
                if(grid[r+1][c]==0)
                {
                    if(vi[r+1][c]==false)
                    {
                        q.push({{r+1,c},d+1});
                        vi[r+1][c]=true;
                    }
                }
                else if(grid[r+1][c]==-1)
                    return d;
            }

            if(r-1>=0)
            {
                if(grid[r-1][c]==0)
                {
                    if(vi[r-1][c]==false)
                    {
                        q.push({{r-1,c},d+1});
                        vi[r-1][c]=true;
                    }
                }
                else if(grid[r-1][c]==-1)
                    return d;
            }
        }

        return 2*n;
    }

    void BFS(int row, int col, int n, vector<vector<int>> &grid)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col]=-1;

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            if(c+1<n && grid[r][c+1]==1)
            {
                grid[r][c+1]=-1;
                q.push({r,c+1});
            }

            if(c-1>=0 && grid[r][c-1]==1)
            {
                grid[r][c-1]=-1;
                q.push({r,c-1});
            }

            if(r+1<n && grid[r+1][c]==1)
            {
                grid[r+1][c]=-1;
                q.push({r+1,c});
            }

            if(r-1>=0 && grid[r-1][c]==1)
            {
                grid[r-1][c]=-1;
                q.push({r-1,c});
            }
        }
    }
};

Time Complexity=O(n*n)).
Space Complexity=O(n*n).

Where, 'n' is the number of the row's or column's in a given 
2D-binary array or binary matrix 'grid'.