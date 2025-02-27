I Approach (Brute-Force Method)

class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.length();

        int count=0;
        int lC=0;
        int rC=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
                lC++;
            else
                rC++;
            
            if(lC==rC)
            {
                count++;
                lC=0;
                rC=0;
            }
        }

        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 's'.