I Approach

class Solution {
private:
    vector<int> q;
    int len;
public:
    Solution(vector<int>& w) {
        int n=w.size();

        for(int i=0;i<n;i++)
        {
            int val=min(1000,w[i]);
            for(int j=0;j<val;j++)
            {
                q.push_back(i);
            }
        }
        len=q.size();
    }
    
    int pickIndex() {
        return q[rand()%len];
    }
};

Time Complexity=O(1) for pickIndex Operation .
Space Complexity=O(n*v).

Where, 'n' is the size of the given vector 'w' and 
'v' is the maximum value in the given vector/array 'w'.