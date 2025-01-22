I Approach (Using BFS)

cclass Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> distance(n,vector<int>(m,0));
        vector<vector<int>> vi(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vi[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;

            distance[r][c]=d;

            q.pop();

            if(c-1>=0 && vi[r][c-1]==0)
	        {
	           vi[r][c-1]=1;
	           q.push({{r,c-1},d+1});
	        }
	        
	        if(c+1<m && vi[r][c+1]==0)
	        {
	           vi[r][c+1]=1;
	           q.push({{r,c+1},d+1});
	        }
	        
	        if(r-1>=0 && vi[r-1][c]==0)
	        {
	           vi[r-1][c]=1;
	           q.push({{r-1,c},d+1});
	        }
	        
	        if(r+1<n && vi[r+1][c]==0)
	        {
	           vi[r+1][c]=1;
	           q.push({{r+1,c},d+1});
	        }
        }
        return distance;
    }
};


Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given 2D-array 'mat'.