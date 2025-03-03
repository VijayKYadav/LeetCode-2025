I Approach (Using BFS)

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        vector<vector<bool>> vi(rows,vector<bool>(cols,false));

        BFS(rows,cols,rCenter,cCenter,ans,vi);

        return ans;
    }

    void BFS(int n, int m, int rC, int cC, vector<vector<int>> &ans, vector<vector<bool>> &vi)
    {
        queue<pair<int,int>> q;
        q.push({rC,cC});
        vi[rC][cC]=true;

        ans.push_back({rC,cC});

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            if(c+1<m && vi[r][c+1]==false)
            {
                ans.push_back({r,c+1});
                vi[r][c+1]=true;
                q.push({r,c+1});
            }

            if(c-1>=0 && vi[r][c-1]==false)
            {
                ans.push_back({r,c-1});
                vi[r][c-1]=true;
                q.push({r,c-1});
            }

            if(r+1<n && vi[r+1][c]==false)
            {
                ans.push_back({r+1,c});
                vi[r+1][c]=true;
                q.push({r+1,c});
            }

            if(r-1>=0 && vi[r-1][c]==false)
            {
                ans.push_back({r-1,c});
                vi[r-1][c]=true;
                q.push({r-1,c});
            }
        }
    }
};

Time Complexity=O(n*m).
Space Complexity=O(n*m).

Where, 'n' is the number of the row 'rows' and 
'm' is the number of column 'cols'.