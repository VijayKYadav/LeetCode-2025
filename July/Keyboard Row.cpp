I Approach (Optimal Method) (Using HashMap)

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard={"qwertyuiop","asdfghjkl","zxcvbnm"};

        vector<int> mp(26);
    
        for(int row=0;row<3;row++)
        {
            for(auto ch:keyboard[row])
                mp[ch-'a']=row;
        }

        vector<string> ans;
        for (auto word : words) 
        {
            bool flag = true;
            int idx = mp[tolower(word[0]) - 'a'];
            
            for (auto ch : word) 
            {
                if (mp[tolower(ch) - 'a'] != idx) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) 
                ans.push_back(word);
        }

        return ans;
    }
};

Time Complexity=O(n*m).
Space Complexity=O(1).

Where,'n' is the size of given vector/array 'words' and 
'm' is the maximum length of string in a given vector/array 'words'.