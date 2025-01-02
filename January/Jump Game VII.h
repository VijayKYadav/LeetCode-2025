I-Approach

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1] == '1') 
            return false;
       
        int cnt = 0;
      
        for(int i = 0; i<n; i++)
        {
            if(s[i] == '1')
            {
                cnt++;
                if(cnt >= maxJump) 
                    return false;
            }
            else
            {
                cnt = 0;
            }
        }
        vector<int> dp(n,-1);
        return solve(0,n,s,minJump,maxJump,dp);
    }

    bool solve(int idx, int n, string &s, int minJ, int maxJ, vector<int> &dp){
        if(idx >=n || s[idx] == '1') 
            return false;

        if(idx == n - 1) 
            return true;

        if(dp[idx]!=-1) 
            return dp[idx];

        dp[idx] = false;

        for(int i = minJ; i<= maxJ; i++){
            if(solve(idx + i, n, s, minJ, maxJ, dp)) 
                return true;
        }
        return dp[idx];
    }
};

Time Complexity = O(n);
Space Complexity = O(n);

Where, 'n' is the length of given string 's'.