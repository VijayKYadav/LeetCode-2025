I Approach (Using DFS+BFS+Bipartite)

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int e=edges.size();
        vector<int> adj[n];

        for(int i=0;i<e;i++)
        {
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!solve(i,adj,col))
                    return -1;
            }
        }

        vector<int> dis(n,0);
        for(int i=0;i<n;i++)
        {
            dis[i]=depth(i,n,adj);
        }

        int group=0;
        vector<bool> vi(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vi[i])
            {
                group+=maxDepth(i,dis,adj,vi);
            }
        }

        return group;
    }

    int maxDepth(int node, vector<int> &dis, vector<int> adj[], vector<bool> &vi)
    {
        vi[node]=true;
        int depth=dis[node];

        for(int i=0;i<adj[node].size();i++)
        {
            int v=adj[node][i];

            if(!vi[v])
            {
                depth=max(depth,maxDepth(v,dis,adj,vi));
            }
        }

        return depth;

    }

    int depth(int node, int n, vector<int> adj[])
    {
        queue<int> q;
        vector<bool> vi(n,false);
        
        q.push(node);
        vi[node]=true;

        int distance=0;

        while(!q.empty())
        {
            int len=q.size();

            for(int i=0;i<len;i++)
            {
                int u=q.front();
                q.pop();

                for(int i=0;i<adj[u].size();i++)
                {
                    int v=adj[u][i];
                    if(!vi[v])
                    {
                        vi[v]=true;
                        q.push(v);
                    }
                }
            }
            distance++;
        }

        return distance;
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

Time Complexity: O(n*(n+e))
Space Complexity: O(n)
 
where, 'n' is the number of vertice's and 
'm' is the number of edge's in a given graph 'edges'.
