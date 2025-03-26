I Approach (Using Unodered_Map) (Optimal Method)

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[grid[i][j]]++;
            }
        }

        int count=INT_MAX;
        int midVal;

        for(auto t:mp)
        {
            midVal=t.first;
            int countT=0;
            for(auto it:mp)
            {
                int key=it.first;
                int val=it.second;

                int d=abs(midVal-key);

                if(d%x)
                    return -1;

                countT+=(d/x)*val;
            }
            count=min(count,countT);
        }

        return count;
    }
};

Time Complexity=O(n*m*log(n*m)).
Space Complexity=O(n*m).

Where,'n' is the number of row's and 
'm' is the number of column's in a given 2D-vector 'grid'.