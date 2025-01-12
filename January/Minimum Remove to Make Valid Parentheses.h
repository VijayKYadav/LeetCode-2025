I Approach

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> sO;
        stack<int> sC;

        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                sO.push(i);
            }
            else if(s[i]==')')
            {
                if(sO.empty())
                    sC.push(i);
                else
                    sO.pop();
            }
        }

        unordered_set<int> st;
        while(!sO.empty())
        {
            st.insert(sO.top());
            sO.pop();
        }
        
        while(!sC.empty())
        {
            st.insert(sC.top());
            sC.pop();
        }

        string ans="";
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
            {
                ans+=s[i];
            }
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(n) 
where, 'n' is the length of the given string 's'.
