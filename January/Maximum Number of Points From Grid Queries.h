I Approach (Using BFS) 

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();

        int t=queries.size();
        vector<int> ans(t);
        for(int i=0;i<t;i++)
        {
            vector<vector<bool>> vi(n,vector<bool>(m,false));

            ans[i]=solve(grid,vi,queries[i]);
        }

        return ans;
    }

    int solve(vector<vector<int>> &grid, vector<vector<bool>> &vi, int q)
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        if(grid[0][0]>=q)
            return count;
        queue<pair<int,int>> pq;
        pq.push({0,0});
        vi[0][0]=true;
        count++;

        while(!pq.empty())
        {
            auto node=pq.front();
            pq.pop();
            int r=node.first;
            int c=node.second;

            if(c+1<m && !vi[r][c+1] && grid[r][c+1]<q)
            {
                count++;
                pq.push({r,c+1});
                vi[r][c+1]=true;
            }

            if(c-1>=0 && !vi[r][c-1] && grid[r][c-1]<q)
            {
                count++;
                pq.push({r,c-1});
                vi[r][c-1]=true;
            }

            if(r+1<n && !vi[r+1][c] && grid[r+1][c]<q)
            {
                count++;
                pq.push({r+1,c});
                vi[r+1][c]=true;
            }

            if(r-1>=0 && !vi[r-1][c] && grid[r-1][c]<q)
            {
                count++;
                pq.push({r-1,c});
                vi[r-1][c]=true;
            }
        }

        return count;
    }
};

Time Complexity: O(n*m*t)
Space Complexity: O(n*m)
 
where, 'n' and 'm' are the number of row's and 
column's in the given 2-D array 'grid'and 't' is the size of array 'queries'.

But, above approach give's TLE(Time Limit Exceeded).

II Approach (Most Optimal)/(Using BFS and Priority)

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        int t=queries.size();

        vector<pair<int,int>> q;

        for(int i=0;i<t;i++)
            q.push_back({queries[i],i});

        sort(q.begin(),q.end());

        vector<int> ans(t);
        vector<vector<bool>> vi(n,vector<bool>(m,false));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vi[0][0]=true;
        int count=0;

        for(int i=0;i<t;i++)
        {
            while(!pq.empty() && pq.top().first<q[i].first)
            {
                count++;
                auto node=pq.top();
                pq.pop();

                int r=node.second.first;
                int c=node.second.second;

                if(c+1<m && !vi[r][c+1])
                {
                    pq.push({grid[r][c+1],{r,c+1}});
                    vi[r][c+1]=true;
                }

                if(c-1>=0 && !vi[r][c-1])
                {
                    pq.push({grid[r][c-1],{r,c-1}});
                    vi[r][c-1]=true;
                }

                if(r+1<n && !vi[r+1][c])
                {
                    pq.push({grid[r+1][c],{r+1,c}});
                    vi[r+1][c]=true;
                }

                if(r-1>=0 && !vi[r-1][c])
                {
                    pq.push({grid[r-1][c],{r-1,c}});
                    vi[r-1][c]=true;
                }
            }

            ans[q[i].second]=count;
        }

        return ans;
    }
};

Time Complexity: O(n*m*log(n*m))
Space Complexity: O(n*m)
 
where, 'n' and 'm' are the number of row's and column's in the given 2-D array 'grid'.