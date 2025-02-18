I Approach (Using Stack)

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();

        int count=0;
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            st.push(count);
            if(i==n || s[i]=='I')
            {
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
            count++;
        }
        return ans;
    }
};1

Time Complexity=O(n).
Space Complexity=O(n).

Where,  'n' is the length of the given string 's'.

II Approach (Optimal Method)

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();

        int countL=0,countH=n;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='I')
                ans.push_back(countL++);
            else
                ans.push_back(countH--);
        }
        ans.push_back(countL);
        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 's'.