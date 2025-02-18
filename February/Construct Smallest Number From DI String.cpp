I Approach (Using Recursion and Backing Tracking)

class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();

        vector<bool> mp(10,false);
        string ans="";
        string curr="";

        solve(0,pattern,n,mp,ans,curr);

        return ans;
    }

    void solve(int ind, string &pattern, int n,vector<bool> &mp, string &ans, string &curr)
    {
        if(curr.length()==n+1)
        {
            if(ans=="")
                ans=curr;
            else
            {
                if(ans>curr)
                    ans=curr;
            }
            return ;
        }

        if(pattern[ind]=='I')
        {
            if(ind==0)
            {
                curr.push_back('1');
                mp[1]=true;
                for(int t=2;t<10;t++)
                {
                    mp[t]=true;
                    curr.push_back(t+'0');
                    solve(ind+1,pattern,n,mp,ans,curr);
                    mp[t]=false;
                    curr.pop_back();
                }
            }
            else
            {
                for(int i=1;i<10;i++)
                {
                    if(mp[i]==false)
                    {
                        char last=curr.back();
                        if(last<(i+'0'))
                        {
                            mp[i]=true;
                            curr.push_back(i+'0');
                            solve(ind+1,pattern,n,mp,ans,curr);
                            mp[i]=false;
                            curr.pop_back();
                        }
                    }
                }
            }
        }
        else
        {
            if(ind==0)
            {
                for(int k=9;k>1;k--)
                {
                    curr.push_back(k+'0');
                    mp[k]=true;
                    for(int t=k-1;t>=1;t--)
                    {
                        mp[t]=true;
                        curr.push_back(t+'0');
                        solve(ind+1,pattern,n,mp,ans,curr);
                        mp[t]=false;
                        curr.pop_back();
                    }
                    mp[k]=false;
                    curr.pop_back();
                }
            }
            else
            {
                for(int i=9;i>=1;i--)
                {
                    if(mp[i]==false)
                    {
                        char last=curr.back();
                        if(last>(i+'0'))
                        {
                            mp[i]=true;
                            curr.push_back(i+'0');
                            solve(ind+1,pattern,n,mp,ans,curr);
                            mp[i]=false;
                            curr.pop_back();
                        }
                    }
                }
            }
        }
    }
};1

Time Complexity=O(9^n).
Space Complexity=O(n).

Where,  'n' is the length of the given string 'pattern'.


II Approach (Using Stack) (Optimal Method)

class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();

        string ans="";
        stack<char> st;
        int count=1;

        for(int i=0;i<n;i++)
        {
            st.push(count+'0');
            if(pattern[i]=='I')
            {    
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
            }
            count++;
        }
        st.push(count+'0');
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,  'n' is the length of the given string 'pattern'.
