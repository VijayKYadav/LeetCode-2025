I Approach (Using Queue and Unordered_Set of Integer Data_types)

class Solution {
private:
    queue<int> q;
    unordered_set<int> st;

public:
    Solution(int n, vector<int>& blacklist) {
        int len=blacklist.size();
        for(int i=0;i<len;i++)
        {
            st.insert(blacklist[i]);
        }
        n = min(100000, n);
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
                q.push(i);
        }
    }
    
    int pick() {
        int f=q.front();
        q.pop();
        q.push(f);
        return f;
    }
};

Time Complexity=O(1) for pick Operation .
Space Complexity=O(n).

Where, 'n' is the given Integer in range [0,n-1].