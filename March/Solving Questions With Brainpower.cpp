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


II Approach (Using Dynamice Programming)

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
Space Complexity=O(n);

Where,'n' is the number of a row's in a given 2D-array 'questions'.