I-Approach

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int count=0;
        int m=pref.length();

        for(int i=0;i<n;i++)
        {
            int len=words[i].length();
            if(m>len)
                continue;
            
            int j=0;

            for(;j<m;j++)
            {
                if(words[i][j]!=pref[j])
                    break;
            }
            if(j==m)
                count++;
        }

        return count;
    }
};

Time Complexity = O(n*m);
Space Complexity = O(1);
Where, n is the size of the given string array words and 
'm' is the length of the given prefix string.
