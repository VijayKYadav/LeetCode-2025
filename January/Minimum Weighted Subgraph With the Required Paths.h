I Approach (Using Dijkstra's Algorithms or Single Source Shortest Path) 

class Solution {
    long MAXX=1e10;
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<pair<int,int>> adj[n],radj[n];
        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            int s=edges[i][0];
            int d=edges[i][1];
            int wt=edges[i][2];
            adj[s].push_back({d,wt});
            radj[d].push_back({s,wt});
        }

        vector<long> dis1(n,MAXX), dis2(n,MAXX), dis3(n,MAXX);

        solve(src1,dis1,adj);
        if(dis1[dest]==MAXX)
            return -1;
        solve(src2,dis2,adj);
        if(dis2[dest]==MAXX)
            return -1;
        solve(dest,dis3,radj);

        long ans=MAXX;

        for(int i=0;i<n;i++)
        {
            if(dis1[i]!=MAXX && dis1[i]!=MAXX && dis1[i]!=MAXX)
                ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
        }
        return ans;
    }

    void solve(int s, vector<long> &dis, vector<pair<int,int>> adj[])
    {
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;
        pq.push({0,s});
        dis[s]=0;

        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            long D=p.first;
            int node=p.second;

            if(dis[node]<D)
                continue;

            for(int i=0;i<adj[node].size();i++)
            {
                if(D+adj[node][i].second<dis[adj[node][i].first])
                {
                    dis[adj[node][i].first]=D+adj[node][i].second;
                    pq.push({dis[adj[node][i].first],adj[node][i].first});
                }
            }
        }
    }
};

Time Complexity: O(n*log(n))
Space Complexity: O(n)
 
where, 'n' is the number of vertice's in the given graph.