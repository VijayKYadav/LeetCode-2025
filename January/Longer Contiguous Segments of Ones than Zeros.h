I Approach

class Solution {
public:
    bool checkZeroOnes(string s) {
        int n=s.length();

        int zeroC=0;
        int oneC=0;

        int count=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(s[i-1]=='1')
                    count++;
                else
                {
                    zeroC=max(zeroC,count);
                    count=1;
                }
            }
            else
            {
                if(s[i-1]=='0')
                    count++;
                else
                {
                    oneC=max(oneC,count);
                    count=1;
                }
            }
        }

        if(s[n-1]=='0')
            zeroC=max(count,zeroC);
        else
            oneC=max(count,oneC);

        if(oneC>zeroC)
            return true;
        return false;
    }
};


Time Complexity: O(n)
Space Complexity: O(1) 
where, 'n' is the length of the given string 's'.