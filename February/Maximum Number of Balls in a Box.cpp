I Approach (Naive Method)

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mp;

        int maxBallCount=0;

        for(int i=lowLimit;i<=highLimit;i++)
        {
            int digitSum=sumOfDigit(i);
            mp[digitSum]++;
            maxBallCount=max(maxBallCount,mp[digitSum]);
        }

        return maxBallCount;
    }

    int sumOfDigit(int n)
    {
        int sum=0;

        while(n>0)
        {
            sum+=n%10;
            n=n/10;
        }

        return sum;
    }
};

Time Complexity=O(d)
Space Complexity=O(1)

Where, 'd' equal to (highLimit-lowLimit+1).

