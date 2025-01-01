I-Approach (Two Pass)

class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int zCount=0;
        int oCount=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                oCount++;
        }
        int score=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
                zCount++;
            else
                oCount--;
            
            score=max(score,zCount+oCount);
        }

        return score;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)

II-Approach (One Pass)

class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int zCount=0;
        int oCount=0;
        
        int score=INT_MIN;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
                zCount++;
            else
                oCount++;
            
            score=max(score,zCount-oCount);
        }
        if(s[n-1]=='1')
            oCount++;

        return score+oCount;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
