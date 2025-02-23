I Approach (Using MaxHeap or Priority_Queue)

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long sum=0;
        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            sort(grid[i].begin(),grid[i].end(),greater<int>());
        }
        priority_queue<int> pq;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<limits[i];j++)
            {
                pq.push(grid[i][j]);
            }
        }

        while(k>0)
        {
            sum+=pq.top();
            pq.pop();
            k--;
        }

        return sum;
    }
};

Time Complexity=O(n*log(m)+n*m*log(m)+k*log(n*m).
Space Complexity=O(n*m).

Where, 'n' is the number of the row's and 
'm' is the number of column's in a given matrix 'grid' and 
'k' is the given Interger.