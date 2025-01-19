I Approach (Using BFS and Priority) 

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
		// Creating a Min-heap 
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<vector<bool>> vi(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][m-1],{i,m-1}});
            vi[i][0]=true;
            vi[i][m-1]=true;
        }

        for(int j=1;j<m-1;j++)
        {
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[n-1][j],{n-1,j}});
            vi[0][j]=true;
            vi[n-1][j]=true;
        }

        int water=0;

        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            int minHeight=node.first;
            int r=node.second.first;
            int c=node.second.second;

            if(c+1<m && !vi[r][c+1])
            {
                if(heightMap[r][c+1]<minHeight)
                    water=water+(minHeight-heightMap[r][c+1]);
                
                pq.push({max(heightMap[r][c+1],minHeight),{r,c+1}});
                vi[r][c+1]=true;
            }

            if(c-1>=0 && !vi[r][c-1])
            {
                if(heightMap[r][c-1]<minHeight)
                    water=water+(minHeight-heightMap[r][c-1]);
                
                pq.push({max(heightMap[r][c-1],minHeight),{r,c-1}});
                vi[r][c-1]=true;
            }

            if(r+1<n && !vi[r+1][c])
            {
                if(heightMap[r+1][c]<minHeight)
                    water=water+(minHeight-heightMap[r+1][c]);
                
                pq.push({max(heightMap[r+1][c],minHeight),{r+1,c}});
                vi[r+1][c]=true;
            }

            if(r-1>=0 && !vi[r-1][c])
            {
                if(heightMap[r-1][c]<minHeight)
                    water=water+(minHeight-heightMap[r-1][c]);
                
                pq.push({max(heightMap[r-1][c],minHeight),{r-1,c}});
                vi[r-1][c]=true;
            }
        }

        return water;
    }
};

Time Complexity: O(n*ml*og(n*m))
Space Complexity: O(n*m)
 
where, 'n' is the number of row's and 
'm' is the number of column's in the given 2-D array 'heightMap'.