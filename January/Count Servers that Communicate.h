I Approach

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        vector<pair<int,int>> cod;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    row[i]++;
                    col[j]++;

                    cod.push_back({i,j});
                }
            }
        }

        int len=cod.size();
        int count=0;

        for(int i=0;i<len;i++)
        {
            auto p=cod[i];
            int r=p.first;
            int c=p.second;

            if(row[r]>=2 || col[c]>=2)
                count++;
        }

        return count;
    }
};


Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given square matrix 'grid'.

II Approach (Optimal Approach)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    if(row[i]>=2 || col[j]>=2)
                        count++;
                }
            }
        }

        return count;
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n+m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given square matrix 'grid'.
