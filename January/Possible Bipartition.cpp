I Approach (Using BFS)

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int e=dislikes.size();
        vector<int> adj[n];

        for(int i=0;i<e;i++)
        {
            int u=dislikes[i][0]-1;
            int v=dislikes[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> col(n,-1);

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!solve(i,adj,col))
                    return false;
            }
        }

        return true;
    }

    bool solve(int n, vector<int> adj[], vector<int> &col)
    {
        queue<int> q;
        col[n]=0;
        q.push(n);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int i=0;i<adj[node].size();i++)
            {
                int v=adj[node][i];

                if(col[v]==-1)
                {
                    col[v]=1-col[node];
                    q.push(v);
                }
                else if(col[v]==col[node])
                    return false;
            }
        } 
        return true;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the number of vertice's in a given graph 'dislikes'.

II Approach (Using DFS)

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int e=dislikes.size();
        vector<int> adj[n];

        for(int i=0;i<e;i++)
        {
            int u=dislikes[i][0]-1;
            int v=dislikes[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> col(n,-1);

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!solve(i,0,adj,col))
                    return false;
            }
        }

        return true;
    }

    bool solve(int n, int c,vector<int> adj[], vector<int> &col)
    {
        col[n]=c;
        
        for(int i=0;i<adj[n].size();i++)
        {
            int v=adj[n][i];

            if(col[v]==-1)
            {
                if(!solve(v,1-c,adj,col))
                    return false;
            }
            else if(col[v]==c)
                return false;
        }

        return true;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the number of vertice's in a given graph 'dislikes'.