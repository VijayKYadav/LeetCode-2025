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

II Approach

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2==1)
            return false;

        int openC=0;
        int zeroC=0;

        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                zeroC++;
            }
            else
            {
                if(s[i]=='(')
                    openC++;
                else
                {
                    if(openC>0)
                        openC--;
                    else
                    {
                        if(zeroC>0)
                            zeroC--;
                        else
                            return false;
                    }
                }
            }
        }

        int balance=0;
        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='0')
            {
                balance--;
                zeroC--;
            }
            else
            {
                if(s[i]=='(')
                {
                    balance++;
                    openC--;
                }
                else
                {
                    balance--;
                }
            }

            if(balance>0)
                return false;
                
            if(zeroC==0 && openC==0)
                return true;
        }

        if(openC>0)
            return false;
        
        return true;

    }
};

Time Complexity: O(n)
Space Complexity: O(n) 
where, 'n' is the length of the given string 's'.

