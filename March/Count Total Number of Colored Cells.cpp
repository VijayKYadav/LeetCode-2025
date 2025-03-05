I Approach (Using BFS)

class Solution {
public:
    long long coloredCells(int n) {
        vector<vector<bool>> vi(2*n-1,vector<bool>(2*n-1,false));

        return BFS(n-1,n-1,vi);
    }

    long long BFS(int row, int col, vector<vector<bool>> &vi)
    {
        queue<pair<pair<int,int>,int>> q;
        int minute=row+1;
        int n=minute*2-1;

        q.push({{row,col},1});
        vi[row][col]=true;
        long long count=1;

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();

            int r=p.first.first;
            int c=p.first.second;

            int d=p.second;

            if(d<minute && c+1<n && vi[r][c+1]==false)
            {
                vi[r][c+1]=true;
                q.push({{r,c+1},d+1});
                count++;
            }

            if(d<minute && c-1>=0 && vi[r][c-1]==false)
            {
                vi[r][c-1]=true;
                q.push({{r,c-1},d+1});
                count++;
            }

            if(d<minute && r+1<n && vi[r+1][c]==false)
            {
                vi[r+1][c]=true;
                q.push({{r+1,c},d+1});
                count++;
            }

            if(d<minute && r-1<n && vi[r-1][c]==false)
            {
                vi[r-1][c]=true;
                q.push({{r-1,c},d+1});
                count++;
            }

        }

        return count;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n*n).

Where, 'n' is the given Integer 'minute'.

This solution will give MLE(Memory Limit Exceeded).

II Approach (Optimal Method)

class Solution {
public:
    long long coloredCells(int n) {
        long long count=0;
        int t=2*n-1;
        count=count+t;
        t=t-2;

        while(t>0)
        {
            count=count+2*t;
            t=t-2;
        }

        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the given Integer 'minute'.