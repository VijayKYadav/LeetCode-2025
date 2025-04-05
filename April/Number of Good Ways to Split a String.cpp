I Approach (Using HashMap) (Optimal Method)

class Solution {
public:
    int numSplits(string s) {
        int n=s.length();
        vector<int> mp(26,0);
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(mp[s[i]-'a']==0)
                count++;
            
            mp[s[i]-'a']++;
        }

        int ans=0;
        unordered_set<char> st;

        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
            mp[s[i]-'a']--;

            if(mp[s[i]-'a']==0)
                count--;
            if(count==st.size())
                ans++;
        }
        return ans;
    }
};

Time Complexity=O(n*log(n)).
Space Complexity=O(26)~O(1).

Where,'n' is the size of a given vector/array 'nums'.