I Approach (Using HashMap and Counting Frequency)

class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();

        vector<int> mp(26,0);

        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }

        int oddF=INT_MIN;
        int evenF=INT_MAX;

        for(int i=0;i<26;i++)
        {
            if(mp[i]!=0)
            {
                if(mp[i]%2)

                    oddF=max(oddF,mp[i]);
                else
                    evenF=min(evenF,mp[i]);
            }
        }

        return oddF-evenF;
    }
};

Time Complexity=O(n).
Space Complexity=O(26)~O(1).

Where, 'n' is the length of the given string 's'.

