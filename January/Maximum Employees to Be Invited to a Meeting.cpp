I Approach

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();

        int cycleL=0;
        vector<bool> vi(n,false);
        vector<int> dis(n,0);
        vector<int> cycle(n,0);
        vector<int> group(n,-1);

        for(int i=0;i<n;i++)
        {
            int start=i;
            vector<int> path(n,0);
            vector<int> d(n,0);

            int c=0;
            if(!vi[i])
            {
                c=solve(start,i,-1,0,favorite,vi,path,d,cycle,group);
                if(c==2)
                {    
                    dis[group[start]]=max(d[group[start]],dis[group[start]]);
                    return dis[group[start]];
                    c=c+dis[group[start]]+dis[favorite[i]];
                }

            }  
            cycleL=max(cycleL,c);
        }
        
        return cycleL;
    }

    int solve(int start, int &node,int p,int count,vector<int> &arr, vector<bool> &vi, vector<int> &path, vector<int> &d, vector<int> &cycle, vector<int> &group)
    {
        if(vi[node])
        {
            int c=path[p]-path[node]+1;

            if(cycle[node]==0)
                cycle[node]=c;

            if(cycle[node]==2)
            {
                if(start!=node)
                { 
                    d[start]=(path[node]-path[start])+d[node];
        
                    if(group[node]==-1)
                    {
                        group[start]=node;
                        group[node]=node;
                        group[p]=p;
                    }
                    else
                        group[start]=group[node];
                }
                else
                {
                    d[start]=0;
                    group[start]=node;
                    group[p]=p;

                }
               
            }
            return c; 
        }

        count++;
        vi[node]=true;
        path[node]=count;

        return cycle[node]=solve(start,arr[node],node,count,arr,vi,path,d,cycle,group);
    }
};

Time Complexity: O(n)
Space Complexity: O(n)
 
where, 'n' is the size of the given array 'favorite'.