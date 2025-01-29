I Approach (Using DFS)

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        vector<int> vi(n,false);
        vector<int> parent(n,-1);
        int start=-1;

        solve(0,adj,vi,parent,start);

        vector<int> cycle(n,0);
        int node = start;

        do {
            cycle[node] = 1;
            node = parent[node];
        } while (node != start);

        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (cycle[edges[i][0] - 1] && cycle[edges[i][1] - 1]) {
                ans=edges[i];
                break;
            }
        }
        return ans;
    }

    void solve(int node, vector<int> adj[], vector<int> &vi, vector<int> &p, int &start)
    {
        vi[node]=true;

        for(int i=0;i<adj[node].size();i++)
        {
            int v=adj[node][i];

            if(!vi[v])
            {
                p[v]=node;
                solve(v,adj,vi,p,start);
            }
            else if(v!=p[node] && start==-1)
            {
                start=v;
                p[v]=node;
            }
        }
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the number of edge's or node's in a given tree 'edges'.
