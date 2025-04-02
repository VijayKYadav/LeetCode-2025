I Approach (Brute-Force Method) (Using Recursion)

class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();

        unordered_set<string> st;
        
        solve(0,n,"",s,st);
        return st.size();
    }

    void solve(int ind, int n, string temp ,string &s, unordered_set<string> &st)
    {
        if(ind==n)
        {
            if(temp!="")
                st.insert(temp);
            return ;
        }

        solve(ind+1,n,temp+s[ind],s,st);
        solve(ind+1,n,temp,s,st);
    }
};

Time Complexity=O(2^n).
Space Complexity=O(2^n).

Where,'n' is the length of a given string 's'.

This, solution will give MLE(Memory Limit Exceeded).


II Approach (Using Recursion + Backtracking)

class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();

        unordered_set<string> st;
        string t="";
        solve(0,n,t,s,st);
        return st.size();
    }

    void solve(int ind, int n, string &temp ,string &s, unordered_set<string> &st)
    {
        if(ind==n)
        {
            if(temp!="")
                st.insert(temp);
            return ;
        }
        temp.push_back(s[ind]);
        solve(ind+1,n,temp,s,st);
        temp.pop_back(); // Backtracking
        solve(ind+1,n,temp,s,st);
    }
};

Time Complexity=O(2^n);
Space Complexity=(2^n);

Where,'n' is the length of a given string 's'.

This, solution will give TLE(Time Limit Exceeded).


III Approach (Using Dynamic Programming) (Optimal Method)

class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        int MOD=1e9+7;

        vector<int> dp(n+1);
        vector<int> last(26,-1);
        dp[0]=1;

        for(int i=0;i<n;i++)
        {
            int ind=s[i]-'a';

            dp[i+1]=(dp[i]*2)%MOD;
            
            if(last[ind]>=0)
                dp[i+1]-=dp[last[s[i]-'a']];
            
            dp[i+1]%=MOD;
            last[s[i]-'a']=i;
        }

        dp[n]--;
        if(dp[n]<0)
            dp[n]+=MOD;
            
        return dp[n];
    }
};

Time Complexity=O(n);
Space Complexity=(n);

Where,'n' is the length of a given string 's'.