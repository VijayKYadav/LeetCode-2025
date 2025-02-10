I Approach (Using Unordered_Set where 'key' is 'integer' and 'value' is 'multiset' of data-types integer)

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        if(n==1 || m==1)
            return mat;
        
        unordered_map<int,multiset<int>> mp; // Map Value is Multiset.

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].insert(mat[i][j]);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                auto it=mp[i-j].begin();
                mat[i][j]=*it;
                mp[i-j].erase(it);
            }
        }

        return mat;
    }
};

Time Complexity=O(n*m*log(max(n,m))).
Space Complexity=O(n*m).

Where, 'n' is the number of row's and 'm' is number of column's in a given matrix 'mat'.


II Approach (Optimal Method) (Using Unordered_Set where 'key' is 'integer' and 'value' is 'priority_queue(Min_Heap)' of data-types integer)

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        if(n==1 || m==1)
            return mat;
        
        unordered_map<int,priority_queue<int, vector<int>, greater<int>>> mp; // Map Value is Priority_Queue(MinHeap).

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].push(mat[i][j]);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }

        return mat;
    }
};

Time Complexity=O(n*m*log(max(n,m))).
Space Complexity=O(n*m).
