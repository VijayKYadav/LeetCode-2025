I Approach

class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();

        vector<int> mp(26,0);

        for(int i=0;i<n;i++)
            mp[s[i]-'a']++;
        
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(mp[i]<3)
                ans+=mp[i];
            else
            {
                if(mp[i]%2)
                    ans++;
                else
                    ans+=2;
            }
        }

        return ans;
    }
};

Time Complexity: O(n)
Space Complexity: O(26)~O(1) 
where, 'n' is the length of the given string 's'.