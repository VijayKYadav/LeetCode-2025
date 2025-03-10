I Approach (Using Brute-Force Method)

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.length();
        int count=0;

        for(int i=0;i<n;i++)
        {
            string t="";
            for(int j=i;j<n;j++)
            {
                if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
                {
                    t+=word[j];
                    if(t.length()>=5 && solve(t))
                        count++;
                }
                else
                    break;
            }
        }

        return count;
    }

    bool solve(string temp)
    {
        int n=temp.length();

        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[temp[i]]++;
        }

        if(mp.size()==5)
            return true;
        
        return false;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n).

Where, 'n' is the length of the given string 'word'.