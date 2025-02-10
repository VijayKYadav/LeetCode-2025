I Approach (Using Brute-Force/Navie Method)

class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        vector<bool> p(n,true);

        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                p[i]=false;
                int j=i-1;
                while(j>=0)
                {
                    if(s[j]>='a' && s[j]<='z' && p[j])
                    {
                        p[j]=false;
                        break;
                    }
                    j--;
                }
            }
        }

        string ans="";
        for(int i=0;i<n;i++)
        {
            if(p[i])
                ans+=s[i];
        }

        return ans;
    }
};

Time Complexity=O(n*n).
Space Complexity=O(n).

Where, 'n' is the length of the given string 's'.

