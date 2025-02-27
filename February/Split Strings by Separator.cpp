I Approach (Brute-Force Method)

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        int n=words.size();

        vector<string> ans;

        for(int i=0;i<n;i++)
        {
            string s=words[i];
            int len=s.length();

            string temp="";
            for(int j=0;j<len;j++)
            {
                if(s[j]==separator)
                {
                    if(temp.length()>0)
                    {
                        ans.push_back(temp);
                        temp="";
                    }
                }
                else
                    temp+=s[j];
            }

            if(temp.length()>0)
                ans.push_back(temp);
        }

        return ans;
    }
};

Time Complexity=O(n*m).
Space Complexity=O(m).

Where, 'n' is the size of given vector/array 'words' and 
'm' is the length of the maximum length of string in a given vector/array 'words'.