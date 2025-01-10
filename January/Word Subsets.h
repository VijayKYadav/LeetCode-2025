I Approach

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int n=words1.size();
        int m=words2.size();
        
        vector<int> mp2(26,0);
        for(int i=0;i<m;i++)
        {
            int len1=words2[i].length();
            vector<int> mp(26,0);
            for(int j=0;j<len1;j++)
            {
                mp[words2[i][j]-'a']++;
            }

            for(int i=0;i<26;i++)
            {
                mp2[i]=max(mp2[i],mp[i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            vector<int> mp1(26,0);
            int len2=words1[i].length();

            for(int j=0;j<len2;j++)
            {
                mp1[words1[i][j]-'a']++;
            }

            int k;
            for(k=0;k<26;k++)
            {
                if(mp1[k]<mp2[k])
                    break;
            }

            if(k==26)
                ans.push_back(words1[i]);
        }

        return ans;
    }
};


Time Complexity: O(n+m)
Space Complexity: O(n+m) 
where, 'n' is the size of the given string of array word1 
and 'm' is the size of the given string of array word2.