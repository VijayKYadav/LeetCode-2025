I-Approach

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int m=queries.size();

        vector<int> prefixSum(n+1,0);

        for(int i=0;i<n;i++)
        {
            string s=words[i];
            int l=s.length();

            if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u') && (s[l-1]=='a' || s[l-1]=='e' || s[l-1]=='i' || s[l-1]=='o' || s[l-1]=='u'))
                prefixSum[i+1]++;

            prefixSum[i+1]+=prefixSum[i];
        }

        vector<int> ans(m);

        for(int i=0;i<m;i++)
        {
            ans[i]=prefixSum[queries[i][1]+1]-prefixSum[queries[i][0]];
        }

        return ans;
    }
};

Time Complexity = O(n+m);
Space Complexity = O(n);

Where, 'n' is the size of string array words and 'm' is the size of queries array or no. of queries.