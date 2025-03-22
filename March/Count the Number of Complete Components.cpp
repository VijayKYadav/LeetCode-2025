I Approach (Using BFS)

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        int e=edges.size();

        for(int i=0;i<e;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vi(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vi[i])
            {
                vector<int> node;
                bfs(i,vi,adj,node);
                
                if(check(node,adj))
                    count++;
            }
        }

        return count;
    }

    void bfs(int ind, vector<bool> &vi, vector<int> adj[], vector<int> &node)
    {
        queue<int> q;
        vi[ind]=true;
        q.push(ind);
        node.push_back(ind);

        while(!q.empty())
        {
            int n=q.front();
            q.pop();

            for(int i=0;i<adj[n].size();i++)
            {
                if(!vi[adj[n][i]])
                {
                    vi[adj[n][i]]=true;
                    q.push(adj[n][i]);
                    node.push_back(adj[n][i]);
                }
            }
        }
    }

    bool check(vector<int> &node, vector<int> adj[])
    {
        int n=node.size();

        for(int i=0;i<n;i++)
        {
            if(adj[node[i]].size()!=n-1)
                return false;
        }

        return true;
    }
};

Time Complexity=O(n+m).
Space Complexity=O(n+m).

Where,'n' is the number of node's in a given undirected graph 'edges' and
'm' is the number of edge's in a given undirected graph 'edges'.

