I Approach (Using Single Source Sortest Path Algorithm) (Optimal Method)

class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        int m=roads.size();

        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;
        vector<long> dis(n,LONG_MAX);
        vector<long> count(n,0);
        dis[0]=0;
        count[0]=1;
        pq.push({0,0});

        while(!pq.empty())
        {
            long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(int i=0;i<adj[node].size();i++)
            {
                if(d+adj[node][i].second<dis[adj[node][i].first])
                {
                    dis[adj[node][i].first]=d+adj[node][i].second;
                    pq.push({dis[adj[node][i].first],adj[node][i].first});
                    count[adj[node][i].first]=count[node];
                }
                else if(d+adj[node][i].second==dis[adj[node][i].first])
                {
                    count[adj[node][i].first]=(count[adj[node][i].first]%MOD+count[node]%MOD)%MOD;
                }
            }
        }
        return count[n-1];
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where,'n' is the number of node's in a given undirected graph 'roads'.

