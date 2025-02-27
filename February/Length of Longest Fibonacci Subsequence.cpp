I Approach (Using Recursion) (Brute-Force Method)

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();

        return solve(0,n,arr,0,0);
    }

    int solve(int ind, int n, vector<int> &arr, int second, int first)
    {
        if(ind==n)
            return 0;

        if(first==0)
        {
            return max(1+solve(ind+1,n,arr,second,arr[ind]),solve(ind+1,n,arr,second,first));
        } 
        else if(second==0)
        {
            return max(1+solve(ind+1,n,arr,first,arr[ind]),solve(ind+1,n,arr,second,first));
        }
        else if(second+first==arr[ind])
            return 1+solve(ind+1,n,arr,first,arr[ind]);
        else
            return solve(ind+1,n,arr,second,first);
    }
};

Time Complexity=O(2^n).
Space Complexity=O(n).

Where, 'n' is the size of given vector/array 'arr';

This solution will give TLE(Time Limit Exceeded).

II Approach (Using Recursion + 3D-Dynamic Programming) (Better Method)

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int maxV=arr[n-1];
        int maxVS=arr[n-2];

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(maxVS+1,vector<int>(maxV+1,-1)));

        int ans=solve(0,n,arr,0,0,dp);
        if(ans>2)
            return ans;
        return 0;
    }

    int solve(int ind, int n, vector<int> &arr, int second, int first, vector<vector<vector<int>>> &dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind][second][first]!=-1)
            return dp[ind][second][first];

        if(first==0)
        {
            return dp[ind][second][first]=max(1+solve(ind+1,n,arr,second,arr[ind],dp),solve(ind+1,n,arr,second,first,dp));
        } 
        else if(second==0)
        {
            return dp[ind][second][first]=max(1+solve(ind+1,n,arr,first,arr[ind],dp),solve(ind+1,n,arr,second,first,dp));
        }
        else if(second+first==arr[ind])
            return dp[ind][second][first]=1+solve(ind+1,n,arr,first,arr[ind],dp);
        else
            return dp[ind][second][first]=solve(ind+1,n,arr,second,first,dp);
    }
};

Time Complexity=O(n*n*n).
Space Complexity=O(n*n*n).

Where, 'n' is the size of given vector/array 'arr';

This solution will give MLE(Memory Limit Exceeded).

II Approach (Using 2D-Dynamic Programming) (Optimal Method)

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int maxV=arr[n-1];
        int maxVS=arr[n-2];

        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxLen=0;

        for(int c=2;c<n;c++)
        {
            int s=0;
            int e=c-1;

            while(s<e)
            {
                int sumP=arr[s]+arr[e];

                if(sumP>arr[c])
                    e--;
                else if(sumP<arr[c])
                    s++;
                else
                {
                    dp[e][c]=dp[s][e]+1;
                    maxLen=max(maxLen,dp[e][c]);
                    e--;
                    s++;
                }
            }
        }

        if(!maxLen)
            return maxLen;
        return maxLen+2;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n*n).

Where, 'n' is the size of given vector/array 'arr';