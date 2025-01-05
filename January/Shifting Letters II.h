I-Approach 

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        int m=shifts.size();

        vector<int> dp(n,0);

        for(int i=0;i<m;i++)
        {
            for(int j=shifts[i][0];j<=shifts[i][1];j++)
            {
                if(shifts[i][2])
                    dp[j]=(dp[j]+1)%26;
                else
                    dp[j]=(dp[j]-1)%26;
            }
        }

        for(int i=0;i<n;i++)
        {
            int d=s[i]-'a';
            d=(d+dp[i]+26)%26;
            s[i]='a'+d;
        }

        return s;
    }
};

Time Complexity = O(n*m);
Space Complexity = O(n);

Where, 'n' is the length of the given string s and 'm' is the size of vector shifts.
This approach will given TLE(i.e Time Limit Exceeded)

II Approach (Using prefixSum)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        int m=shifts.size();

        vector<int> dp(n,0);

        for(int i=0;i<m;i++)
        {
            if(shifts[i][2])
            {
                dp[shifts[i][0]]=(dp[shifts[i][0]]+1)%26;
                if(shifts[i][1]+1<n)
                    dp[shifts[i][1]+1]=(dp[shifts[i][1]+1]-1)%26;
            }
            else
            {
                dp[shifts[i][0]]=(dp[shifts[i][0]]-1)%26;
                if(shifts[i][1]+1<n)
                    dp[shifts[i][1]+1]=(dp[shifts[i][1]+1]+1)%26;
            }

        }

        int sum=0;
        string res(n,' ');
        for(int i=0;i<n;i++)
        {
            sum=(sum+dp[i])%26;

            if(sum<0)
                sum+=26;
            
            res[i]='a'+(s[i]-'a'+sum)%26;
        }

        return res;
    }
};

Time Complexity = O(n+m);
Space Complexity = O(n);

Where, 'n' is the length of the given string s and 'm' is the size of vector shifts.

