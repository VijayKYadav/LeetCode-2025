I Approach (Brute-Force Method)

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();

        int ans=0;
        long p=1;
        
        for(int i=0;i<n;i++)
        {
            int c=columnTitle[n-1-i]-'A'+1;
            ans+=p*c;
            p*=26;
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 'columnTitle'.
