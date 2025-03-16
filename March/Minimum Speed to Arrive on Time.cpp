I Approach (Using Binary Search)

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(hour<=n-1)
            return -1;
        
        int minS=1;
        int maxS=1e7;

        while(minS<maxS)
        {
            int midS=minS+(maxS-minS)/2;

            if(check(dist,hour,midS))
                maxS=midS;
            else
                minS=midS+1;
        }
        return maxS;
    }

    bool check(vector<int> &dist, double hour, double speed)
    {
        int n=dist.size();

        double time=0;

        for(int i=0;i<n-1;i++)
            time+=ceil(dist[i]/speed);

        time+=dist[n-1]/speed;

        return time<=hour;
    }
};

Time Complexity=O(n*log(1e7).
Space Complexity=O(1).

Where, 'n' is the size of in a given vector/array 'dist'.