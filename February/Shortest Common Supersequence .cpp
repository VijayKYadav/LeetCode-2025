I Approach (Using 2D-Dynamic Programming)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        string sls="";
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int i=n,j=m;

        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                sls.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                {
                    sls.push_back(str2[j-1]);
                    j--;
                }
                else
                {
                    sls.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i>0)
        {
            sls.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0)
        {
            sls.push_back(str2[j-1]);
            j--;
        }
        
        reverse(sls.begin(),sls.end());
        
        return sls;
    }
};

Time Complexity=O(n*m).
Space Complexity=O(n*m).

Where, 'n' is the length of the given string 'str1' and
'm' is the length of the given string 'str2'.
