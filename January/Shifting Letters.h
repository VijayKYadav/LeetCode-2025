I-Approach (Using SuffixSum)

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        vector<int> suffixSum(n,0);
        suffixSum[n-1]=shifts[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffixSum[i]=(suffixSum[i+1]+shifts[i]%26)%26;
        }

        for(int i=0;i<n;i++)
        {
            int d=s[i]-'a';
            d=(d+suffixSum[i])%26;
            s[i]='a'+d;
        }
        return s;
    }
};

Time Complexity = O(n);
Space Complexity = O(n);

Where, 'n' is the length of the given string s.
