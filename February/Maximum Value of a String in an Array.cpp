I Approach (Using Brute-Force Method)

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int n=strs.size();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(check(strs[i]))
            {
                int len=strs[i].length();
                ans=max(ans,len);
            }
            else
            {
                ans=max(ans,solve(strs[i]));
            }
        }

        return ans;
    }

    bool check(string &s)
    {
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
                return true;
        }

        return false;
    }

    int solve(string &s)
    {
        int n=s.length();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans=ans*10+(s[i]-'0');
        }

        return ans;
    }
};

Time Complexity=O(n*9)~O(n).
Space Complexity=O(1).

Where, 'n' is the size of the given vector/array of string data-types 'strs'.

