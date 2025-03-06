I Approach (Using HashMap)

cclass Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int sum=0;
        vector<int> mp(n*n,0);
        int dup;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=grid[i][j];
                mp[grid[i][j]-1]++;
                if(mp[grid[i][j]-1]==2)
                    dup=grid[i][j];
            }
        }
        vector<int> ans;
        ans.push_back(dup);
        int ele=n*n*(n*n+1)/2-(sum-dup);
        ans.push_back(ele);
        
        return ans;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n*n).

Where, 'n' is the number of row's or column's in a given 2D-vector/array 'grid'.