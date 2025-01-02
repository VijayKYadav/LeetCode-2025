I-Approach

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>> vi(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    vi[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<vector<int>> height(n,vector<int>(m,0));
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            int r=node.first.first;
            int c=node.first.second;
            int d=node.second;

            height[r][c]=d;

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

        return height;
    }
};

Time Complexity = O(n*m);
Space Complexity = O(n*m);

Where, 'n' is the no. of row and 'm' is the no. of colum in a given matrix isWater.