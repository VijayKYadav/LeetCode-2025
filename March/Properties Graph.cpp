I Approach (Using BFS)

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<vector<int>> edges;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(intersect(properties[i],properties[j])>=k)
                    edges.push_back({i,j});
            }
        }
        
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
        int components=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vi[i])
            {
                bfs(i,adj,vi);
                components++;
            }
        }
        
        return components;
        
        
    }
    
    void bfs(int v, vector<int> adj[], vector<bool> &vi)
    {
        queue<int> q;
        vi[v]=true;
        q.push(v);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                if(vi[adj[node][i]]==false)
                {
                    vi[adj[node][i]]=true;
                    q.push(adj[node][i]);
                }
            }
        }
    }
    
    int intersect(vector<int> &a, vector<int> &b)
    {
        int m=a.size();
        
        unordered_set<int> sta;
        unordered_set<int> stb;
        
        for(int i=0;i<m;i++)
        {
            sta.insert(a[i]);
            stb.insert(b[i]);
        }
        int count=0;
        
        for(int e: sta)
        {
            if(stb.find(e)!=stb.end())
                count++;
        }
        
        return count;
    }
};

Time Complexity=O(n*n*m*log(m)).
Space Complexity=O(n*n).

Where,'n' is the number of row's and 
'm' is the number colum's in a given 2D-Vector 'properties'.

This, solution will give TLE(Time Limit Exceeded).


II Approach (Using BFS) (Optimal Method)

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        int m=properties[0].size();
        
        vector<vector<int>> edges;
        
        for(int i=0;i<n-1;i++)
        {
            unordered_set<int> sta;
            vector<int> a=properties[i];
            
            for(int j=0;j<m;j++)
                sta.insert(a[j]);
            
            for(int j=i+1;j<n;j++)
            {
                if(intersect(sta,properties[j])>=k)
                    edges.push_back({i,j});
            }
        }
        
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
        int components=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vi[i])
            {
                bfs(i,adj,vi);
                components++;
            }
        }
        
        return components;  
    }
    
    void bfs(int v, vector<int> adj[], vector<bool> &vi)
    {
        queue<int> q;
        vi[v]=true;
        q.push(v);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                if(vi[adj[node][i]]==false)
                {
                    vi[adj[node][i]]=true;
                    q.push(adj[node][i]);
                }
            }
        }
    }
    
    int intersect(unordered_set<int> &sta, vector<int> &b)
    {
        int m=b.size();
        
        unordered_set<int> stb;
        
        for(int i=0;i<m;i++)
            stb.insert(b[i]);
        
        int count=0;
        
        for(int e: sta)
        {
            if(stb.find(e)!=stb.end())
                count++;
        }
        
        return count;
    }
};

Time Complexity=O(n*n*m*log(m)).
Space Complexity=O(n*n).

Where,'n' is the number of row's and 
'm' is the number colum's in a given 2D-Vector 'properties'.