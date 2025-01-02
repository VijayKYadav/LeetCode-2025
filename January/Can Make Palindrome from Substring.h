I-Approach

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<bool> ans;
        for(int i=0;i<m;i++)
        {
            int st=queries[i][0];
            int len=queries[i][1]-queries[i][0]+1;
            int k=queries[i][2];

            ans.push_back(solve(s.substr(st,len),k));
        }
        return ans;
    }

    bool solve(string s, int k)
    {
        int n=s.length();
        vector<int> mp(26,0);

        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            count+=mp[i]%2;
        }
        
        if(count/2<=k)
            return true;
        else
            return false;
    }
};

Time Complexity = O(n*m)
Space Cmplexity = O(1)
Where, 'n' is the length of given string 's' ans 'm' is the no. of queries of size of queries vector

// This approach will give TTE(Time Limit Exceeded)

II-Approach

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        int m=queries.size();
        vector<bool> ans;

        vector<vector<int>> dp(n+1,vector<int>(26,00));

        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            dp[i][s[i-1]-'a']++;
        }

        int k,count;

        for(int i=0;i<m;i++)
        {
            count=0;
            for(int j=0;j<26;j++)
            {
                k=dp[queries[i][1]+1][j]-dp[queries[i][0]][j];
                count+=k%2;
            }

            ans.push_back(count/2<=queries[i][2]?true:false);
        }
        return ans;
    }
};

Time Complexity = O(26*n) = O(n)
Space Cmplexity = O(26*n) = O(n)
Where, 'n' is the length of given string 's'
