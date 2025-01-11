I Approach

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k)
            return false;
            
        vector<int> mp(26,0);

        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }

        int count=0;

        for(int i=0;i<26;i++)
        {
            if(mp[i]%2)
                count++;
        }

        if(count<=k)
            return true;
        
        return false;
    }
};


Time Complexity: O(n)
Space Complexity: O(26)~O(1) 
where, 'n' is the length of the given string 's'.