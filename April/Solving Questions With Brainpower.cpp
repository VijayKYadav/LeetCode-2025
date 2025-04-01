I Approach (Using Recursion) (Brute-Force Method)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();

        return solve(0,n,questions);
    }

    long long solve(int ind, int n, vector<vector<int>> questions)
    {
        if(ind>=n)
            return 0;
        
        int take=questions[ind][0]+solve(ind+questions[ind][1]+1,n,questions);

        int notTake=solve(ind+1,n,questions);

        return max(take,notTake);
    }
};

Time Complexity=O(2^n).
Space Complexity=O(n).

Where,'n' is the number of a row's in a given 2D-array 'questions'.

This, solution will give TLE(Time Limit Exceeded).


II Approach (Using Dynamice Programming) (Top-Down)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return solve(0,n,questions,dp);
    }

    long long solve(int ind, int n, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if(ind>=n)
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];
        
        long long take=questions[ind][0]+solve(ind+questions[ind][1]+1,n,questions,dp);

        long long notTake=solve(ind+1,n,questions,dp);

        return dp[ind]=max(take,notTake);
    }
};

Time Complexity=O(n);
Space Complexity=O(n)+O(n)~O(n);

Where,'n' is the number of a row's in a given 2D-array 'questions'.

III Approach (Using Dynamice Programming) (Bottom-Up) (Optimal Method)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();

        vector<long long> dp(n,-1);

        int jumpInd=0;
        long long take=0, notTake=0;

        for(int i=n-1;i>=0;i--)
        {
            jumpInd=i+questions[i][1]+1;

            take=questions[i][0];

            if(jumpInd<n)
                take+=dp[jumpInd];
            
            notTake=0;
            if(i+1<n)
                notTake=dp[i+1];
            
            dp[i]=max(take,notTake);
        }
        return dp[0];
    }
};

Time Complexity=O(n);
Space Complexity=O(n);

Where,'n' is the number of a row's in a given 2D-array 'questions'.