I Approach

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);
        unordered_map<int,pair<int,int>> mp;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[mat[i][j]]={i,j};
            }
        }

        int ans;

        for(int i=0;i<n*m;i++)
        {
            auto p=mp[arr[i]];
            int r=p.first;
            int c=p.second;

            row[r]++;
            col[c]++;

            if(row[r]==m || col[c]==n)
            {
                ans=i;
                break;
            }
        }

        return ans;
    }
};

Time Complexity: O(n*m)
Space Complexity: O(n*m)
 
where, 'n' and 'm' are the number of row's and column's in the given 2-D array 'mat'.
