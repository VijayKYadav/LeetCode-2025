I Approach (Using PrefixSum Concept with extra space)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<int> prefixSum(days+2,0);

        for(int i=0;i<n;i++)
        {
            prefixSum[meetings[i][0]]++;
            prefixSum[meetings[i][1]+1]--;
        }

        int sum=0;
        int count=0;

        for(int i=1;i<=days;i++)
        {
            sum+=prefixSum[i];
            if(sum==0)
                count++;
        }
        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(n).

Where,'n' is the given Interger 'days'.

This, solution will give MLE(Memory Limit Exceeded).


II Approach (Using Sorting) (Optimal Method)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());

        int count=0;
        int end=0;

        for(int i=0;i<n;i++)
        {
            int s=meetings[i][0];
            int e=meetings[i][1];

            if(s>end+1)
                count+=s-end-1;
            
            end=max(end,e);
        }

        count+=days-end;

        return count;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(n).

Where,'n' is the number of row's in a given 2D-Vector 'meetings'.