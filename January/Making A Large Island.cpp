I Approach (Using DSU)

class DisjointSet{
    public:
        vector<int> parent,size;
        
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }

        int findParent(int node)
        {
            if(parent[node]==node)
                return node;
            return parent[node] = findParent(parent[node]);
        }

        void Union(int u,int v)
        {
            int up_u=findParent(u);
            int up_v=findParent(v);

            if(up_u != up_v)
            {
                if(size[up_u]<size[up_v])
                {
                    parent[up_u]=up_v;
                    size[up_v]=size[up_v]+size[up_u];
                }
                else
                {
                    parent[up_v]=up_u;
                    size[up_u]=size[up_v]+size[up_u];
                }
            }
        }

};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                    if(grid[row][col])
                    {    
                        if(col-1>=0 && grid[row][col-1])
                        {
                            ds.Union(row*n+col,row*n+col-1);
                        }

                        if(col+1<n && grid[row][col+1])
                        {
                            ds.Union(row*n+col,row*n+col+1);
                        }

                        if(row-1>=0 && grid[row-1][col])
                        {
                            ds.Union(row*n+col,(row-1)*n+col);
                        }

                        if(row+1<n && grid[row+1][col])
                        {
                            ds.Union(row*n+col,(row+1)*n+col);
                        }

                    }
            }
        }

        int Max=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                set<int> component;
                if(!grid[row][col])
                {
                    if(col-1>=0 && grid[row][col-1])
                    {
                        component.insert(ds.findParent(row*n+col-1));
                    }

                    if(col+1<n && grid[row][col+1])
                    {
                        component.insert(ds.findParent(row*n+col+1));
                    }

                    if(row-1>=0 && grid[row-1][col])
                    {
                        component.insert(ds.findParent((row-1)*n+col));
                    }

                    if(row+1<n && grid[row+1][col])
                    {
                        component.insert(ds.findParent((row+1)*n+col));
                    }

                    int size=0;
                    for(auto it:component)
                    {
                        size=size+ds.size[it];
                    }
                    Max=max(Max,size+1);
                    
                }
            }
        }
        Max=max(Max,ds.size[0]);
        return Max;

    }
};

Time Complexity: O(n*n)
Space Complexity: O(n*n)
 
where, 'n' is the number of row's or 
'n' is the number of column's in a given matrix 'grid'.