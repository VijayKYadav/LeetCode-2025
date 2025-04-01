I Approach (Using Recursion) (Brute-Force Method)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();

        if(stones[1]!=1)
            return false;

        int ind=1;
        int jump=1; 
        return solve(ind,n,jump,stones);  
    }

    bool solve(int ind, int n, int jump, vector<int> &stones)
    {
        if(ind==n-1)
            return true;
        
        bool frog=false;

        for(int i=ind+1;i<n;i++)
        {
			if(stones[ind]+jump+1<stones[i])
                break;
			
            for(int j=jump-1;j<=jump+1;j++)
            {
                if(stones[ind]+j==stones[i])
                    frog=frog || solve(i,n,j,stones);
            }
        }

        return frog;
    }
};

Time Complexity=O(3^n).
Space Complexity=O(n).

Where,'n' is the size of a given vector/array 'stones'.

This, solution will give TLE(Time Limit Exceeded).


II Approach (Using Dynamice Programming) (Top-Down) (Optimal Method)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();

        if(stones[1]!=1)
            return false;

        int ind=1;
        int jump=1; 
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(ind,n,jump,stones,dp);  
    }

    bool solve(int ind, int n, int jump, vector<int> &stones, vector<vector<int>> &dp)
    {
        if(ind==n-1)
            return true;
        
        if(dp[ind][jump]!=-1)
            return dp[ind][jump];

        bool frog=false;

        for(int i=ind+1;i<n;i++)
        {
            if(stones[ind]+jump+1<stones[i])
                break;

            for(int j=jump-1;j<=jump+1;j++)
            {
                if(stones[ind]+j==stones[i])
                    frog=frog || solve(i,n,j,stones,dp);
            }
        }

        return dp[ind][jump]=frog;
    }
};

Time Complexity=O(n);
Space Complexity=O(n)+O(n)~O(n);

Where,'n' is the size of a given vector/array 'stones'.