I Approach (Using Sliding-Window + HashMap) (Optimal Method)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        vector<int> mp(3,0);
        int i=0;
        int j=0;
        int count=0;
        int charCount=0;

        while(j<n)
        {
            mp[s[j]-'a']++;

            if(mp[s[j]-'a']==1)
                charCount++;

            while(charCount==3)
            {
                count+=n-j;
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)
                    charCount--;
                i++;
            }

            j++;
        }
        return count;
    }
};

Time Complexity=O(n).
Space Complexity=O(1).

Where, 'n' is the length of the given string 's'.