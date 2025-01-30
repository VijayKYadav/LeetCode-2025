I Approach (Using DFS)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        int e=connections.size();

        for(int i=0;i<e;i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        
        return solve(0,-1,adj);
    }

    int solve(int node, int pre, vector<pair<int,int>> adj[])
    {
        int ans=0;
        for(int i=0;i<adj[node].size();i++)
        {
            int v=adj[node][i].first;
            int val=adj[node][i].second;
            
            if(pre!=v)
                ans+=val+solve(v,node,adj);
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the number of vertice's in a given graph 'connections'.

II Approach (Using BFS)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        int e=connections.size();

        for(int i=0;i<e;i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<int> vi(n);
        return solve(0,-1,adj,vi);
    }

    int solve(int node, int pre, vector<pair<int,int>> adj[], vector<int> &vi)
    {
        queue<int> q;
        q.push(node);
        vi[node]=true;
        int ans=0;
        
        while(!q.empty())
        {
            int n=q.front();
            q.pop();

            for(int i=0;i<adj[n].size();i++)
            {
                int v=adj[n][i].first;
                int val=adj[n][i].second;

                if(!vi[v])
                {
                    vi[v]=true;
                    ans+=val;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the number of vertice's in a given graph 'connections'.
