I Approach (Brute-Force Method)

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int c=columnTitle[n-1-i]-'A'+1;
            int p=pow(26,i);
            ans+=p*c;
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 'columnTitle'.