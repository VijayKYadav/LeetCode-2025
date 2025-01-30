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