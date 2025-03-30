I Approach (Using Unordered_map) (Optimal Method)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();

        unordered_map<char,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }

        int start=0;
        int end=0;
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            end=max(end,mp[s[i]]);
            if(end==i)
            {
                ans.push_back(end-start+1);
                start=end=i+1;
            }   
        }

        return ans;
    }
};

Time Complexity=O(n).
Space Complexity=O(k).

Where,'n' is the length of a given string 's' and 
'k' is the number of unique character in a given string 's'.