I Approach (Using HashMap)

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int count=0;

        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
                count++;
            if(count>2)
                return false;

            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(mp1[i]!=mp2[i])
                return false;
        }

        return true;
    }
};

Time Complexity=O(n)
Space Complexity=O(1)

Where, 'n' is the length of the given string 's1'.

