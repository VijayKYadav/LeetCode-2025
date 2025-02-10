I Approach (Using Unordered_Set where key is integer and value is multiset of data-types integer)

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(n==1)
            return grid;
        
        unordered_map<int,multiset<int>> mp;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i-j].insert(grid[i][j]);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<j)
                {
                    auto it=mp[i-j].begin();
                    grid[i][j]=*it;
                    mp[i-j].erase(it);
                }
                else
                {
                    auto it=--mp[i-j].end();
                    grid[i][j]=*it;
                    mp[i-j].erase(it);
                }
            }
        }

        return grid;
    }
};

Time Complexity=O(n*n*log(n)).
Space Complexity=O(n*n).

Where, 'n' is the number of row's or column's in a given matrix 'grid'.

