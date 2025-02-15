I Approach (Using Recursion) (Optimal Method)

class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            int p=i*i;

            string mul=to_string(p);
            int len=mul.length();

            if(check(0,len,mul,0,i))
                ans=ans+p;

        }
        return ans;
    }                                      

    bool check(int ind,int len,string s,int sum, int k)
    {
        if(ind==len)
        {
            if(sum==k)
                return true;
            else
                return false;
        }

        for(int i=ind;i<len;i++)
        {
            string left=s.substr(ind,i-ind+1);
            int nsum=sum+stoi(left);

            if(check(i+1,len,s,nsum,k))
                return true;
        }

        return false;
    }
};

Time Complexity=O(n*2^log(n)).
Space Complexity=O(log(n)).

Where,  'n' is the number in the range [1,n].

II Approach (Using Dynamic Programming)

class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            int p=i*i;

            string mul=to_string(p);

            int len=mul.length();

            vector<vector<int>> dp(len,vector<int>(i+1,-1));

            if(check(0,len,mul,0,i,dp))
                ans=ans+i*i;
                
        }
        return ans;
    }                                      

    bool check(int ind,int len,string &s,int sum, int k, vector<vector<int>> &dp)
    {
        if(ind==len)
        {
            if(sum==k)
                return true;
            else
                return false;
        }

        if(sum>k)
            return false;
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];

        int found=false;

        for(int i=ind;i<len;i++)
        {
            string left=s.substr(ind,i-ind+1);
            int nsum=sum+stoi(left);

            found=found||check(i+1,len,s,nsum,k,dp);

            if(found)
                return true;
        }

        return dp[ind][sum]=found;
    }
};

Time Complexity=O(n*2^log(n)).
Space Complexity=O(n*log(n)).

Where,  'n' is the number in the range [1,n].