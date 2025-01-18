I Approach (Using BFS and Dynamic Programming)

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> minC(n,vector<int>(m,INT_MAX));

        queue<pair<int,int>> q;
        q.push({0,0});
        minC[0][0]=0;


        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            int r=node.first;
            int c=node.second;

            int value=grid[r][c];

            if(c+1<m)
            {
                int ct=1;
                if(value==1)
                    ct=0;
                
                if(minC[r][c]+ct<minC[r][c+1])
                {
                    minC[r][c+1]=minC[r][c]+ct;
                    q.push({r,c+1});
                }
            }

            if(c-1>=0)
            {
                int ct=1;
                if(value==2)
                    ct=0;

                if(minC[r][c]+ct<minC[r][c-1])
                {
                    minC[r][c-1]=minC[r][c]+ct;
                    q.push({r,c-1});
                }
            }

            if(r+1<n)
            {
                int ct=1;
                if(value==3)
                    ct=0;

                if(minC[r][c]+ct<minC[r+1][c])
                {
                    minC[r+1][c]=minC[r][c]+ct;
                    q.push({r+1,c});
                }
            }

            if(r-1>=0)
            {
                int ct=1;
                if(value==4)
                    ct=0;

                if(minC[r][c]+ct<minC[r-1][c])
                {
                    minC[r-1][c]=minC[r][c]+ct;
                    q.push({r-1,c});
                }
            }

        }

        return minC[n-1][m-1];
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's int the given 2-D array 'grid'.