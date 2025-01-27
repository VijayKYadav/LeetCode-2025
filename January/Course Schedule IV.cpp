I Approach (Using DFS)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
		int e=prerequisites.size();
        vector<int> adj[numCourses];

        for(int i=0;i<e;i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[u].push_back(v);
        }

        int Q=queries.size();
        vector<bool> ans(Q);

        for(int i=0;i<Q;i++)
        {
            int src=queries[i][0];
            int des=queries[i][1];

            vector<bool> vi(numCourses);

            ans[i]=solve(adj,src,des,vi);
        }

        return ans;
    }

    bool solve(vector<int> adj[], int src, int des, vector<bool> &vi)
    {
        vi[src]=true;

        if(src==des)
            return true;
        
        for(int i=0;i<adj[src].size();i++)
        {
            if(!vi[adj[src][i]] && solve(adj,adj[src][i],des,vi))
                return true;
        }

        return false;
    }
};

Time Complexity: O(Q *(n+e))
Space Complexity: O(n+e)
    
where, 'n' is the number of vertice's 'e' is the number of edges in the given graph 'prerequisites' and 
'Q' is size of the given 2D-array 'queries'.
